#include <stdio.h>
#include "cs1300bmp.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Filter.h"

using namespace std;

#include "rdtsc.h"

inline int Filter::get(int r, int c){
    return data[ r * dim + c]; 
}

inline int Filter::getDivisor(){
    return divisor; 
}

inline int Filter::getSize(){
    return dim; 
}

//
// Forward declare the functions
//
Filter * readFilter(string filename);
double applyFilter(Filter *filter, cs1300bmp *input, cs1300bmp *output);

int
main(int argc, char **argv)
{

  if ( argc < 2) {
    fprintf(stderr,"Usage: %s filter inputfile1 inputfile2 .... \n", argv[0]);
  }

  //
  // Convert to C++ strings to simplify manipulation
  //
  string filtername = argv[1];

  //
  // remove any ".filter" in the filtername
  //
  string filterOutputName = filtername;
  string::size_type loc = filterOutputName.find(".filter");
  if (loc != string::npos) {
    //
    // Remove the ".filter" name, which should occur on all the provided filters
    //
    filterOutputName = filtername.substr(0, loc);
  }

  Filter *filter = readFilter(filtername);

  double sum = 0.0;
  int samples = 0;

  for (int inNum = 2; inNum < argc; inNum++) {
    string inputFilename = argv[inNum];
    string outputFilename = "filtered-" + filterOutputName + "-" + inputFilename;
    struct cs1300bmp *input = new struct cs1300bmp;
    struct cs1300bmp *output = new struct cs1300bmp;
    int ok = cs1300bmp_readfile( (char *) inputFilename.c_str(), input);

    if ( ok ) {
      double sample = applyFilter(filter, input, output);
      sum += sample;
      samples++;
      cs1300bmp_writefile((char *) outputFilename.c_str(), output);
    }
    delete input;
    delete output;
  }
  fprintf(stdout, "Average cycles per sample is %f\n", sum / samples);

}

struct Filter *
readFilter(string filename)
{
  ifstream input(filename.c_str());

  if ( ! input.bad() ) {
    int size = 0;
    input >> size;
    Filter *filter = new Filter(size);
    int div;
    input >> div;
    filter -> setDivisor(div);
    for (int i=0; i < size; i++) {
      for (int j=0; j < size; j++) {
	int value;
	input >> value;
	filter -> set(i,j,value);
      }
    }
    return filter;
  } else {
    cerr << "Bad input in readFilter:" << filename << endl;
    exit(-1);
  }
}

double
applyFilter(struct Filter *filter, cs1300bmp *input, cs1300bmp *output)
{

  long long cycStart, cycStop;

  cycStart = rdtscll();

  int width = output->width = input->width;
  int height = output->height = input->height;


  for(int row = 1; row <= height; row++){
    for(int col = 1; col <= width; col++){

      int outputR = 0;
      int outputG = 0;
      int outputB = 0;
        int fSize = filter -> getSize(); 
        int divisor = filter -> getDivisor(); 

      for (int i = 0; i < fSize; i++) { 
        for (int j = 0; j < fSize; j++) {
          outputR += input -> color[row + i - 1][col + j - 1][COLOR_RED] * filter -> get(i, j);
          outputG += input -> color[row + i - 1][col + j - 1][COLOR_GREEN] * filter -> get(i, j);
          outputB += input -> color[row + i - 1][col + j - 1][COLOR_BLUE] * filter -> get(i, j);
        }
      }

      outputR /= divisor; 
      outputG /= divisor; 
      outputB /= divisor;

      if (outputR < 0){outputR = 0;}
      if (outputR > 255){outputR = 255;}
      if (outputG < 0){outputG = 0;}
      if (outputG > 255){outputG = 255;}
      if (outputB < 0){outputB = 0;}
      if (outputB > 255){outputB = 255;}

      output -> color[row][col][COLOR_RED] = outputR;
      output -> color[row][col][COLOR_GREEN] = outputG;
      output -> color[row][col][COLOR_BLUE] = outputB;
      
    }
  }

  cycStop = rdtscll();
  double diff = cycStop - cycStart;
  double diffPerPixel = diff / (output -> width * output -> height);
  fprintf(stderr, "Took %f cycles to process, or %f cycles per pixel\n",
	  diff, diff / (output -> width * output -> height));
  return diffPerPixel;
}