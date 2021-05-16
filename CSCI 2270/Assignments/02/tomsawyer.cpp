//takes in three command line args 
    //a number n 
    //name of text to be read Tom_Sawyer.txt
    //name of text file with words to be ignored ignoreWords.txt

//read the text (ignoring words in the second file) and 
//store all unique words in a dynamically doubling array 
//calculate and print 
    //number of times array doubling was required to store all the unique words
    //number of unique "non-ignore" words in the file 
    //total word count of the file (excluding the ignore words) 
//print 10 most frequent words along with their probability of 
//occurrence from the array 
//array should be sorted in decreasing order based on probability 

#include <iostream> 
#include <fstream> 
#include <string> 
#include <iomanip>
#include <math.h> 

using namespace std; 


//struct 
struct wordItem{
    string word = " "; 
    int count = 0;  
    string uniqueWords[];

};


//define functions 
void getStopWords(const char *ignoreWordFileName, string ignoreWords[]); 

bool isStopWord(string word, string ignoreWords[]); 

int getTotalNumberNonStopWords(wordItem uniqueWords[], int length); 

void arraySort(wordItem uniqueWords[], int lenght); 

void printNext10(wordItem uniqueWords[], int N, int totalNumWords); 

void doubleArraySize(wordItem* &ptr, int* length); 


//functions 
void doubleArraySize(wordItem* &ptr, int* length){
    int newL = *length * 2; 
    wordItem* nArr = new wordItem[newL]; 
    for(int i = 0; i < *length; i++){
        nArr[i] = ptr[i]; 
    }

    delete[] ptr; 
    ptr = nArr; 
    *length = newL; 
}

void getStopWords(char *ignoreWordFileName, string ignoreWords[]){
    ifstream ignoreFile;
    ignoreFile.open(ignoreWordFileName); 
    if(!ignoreFile.is_open()){
        cout << "Failed to open " << ignoreWordFileName << endl; 
    } 

    string line = " "; 
    int ind = 0; 
    while(getline(ignoreFile, line) && ind < 50){
        ignoreWords[ind] = line; 
        ind++; 
    }    
    ignoreFile.close(); 
}

bool isStopWord(string word, string ignoreWords[]){
    for(int i = 0; i < 50; i++){
        if(ignoreWords[i] == word){
            return true; 
        }
    }
    return false; 
}

int getTotalNumberNonStopWords(wordItem uniqueWords[], int length){
    int i = 0; 
    for(int j = 0; j < length; j++){
        i += uniqueWords[j].count; 
    }
    return i; 
}

void arraySort(wordItem uniqueWords[], int length){
    for(int i = 1; i < length; i++){
        int s = uniqueWords[i].count; 
        wordItem sort = uniqueWords[i]; 
        int j = i - 1; 

        while(j >= 0 && uniqueWords[j].count < s){
            uniqueWords[j+1] = uniqueWords[j]; 
            j--; 
        }
        uniqueWords[j+1] = sort; 
    }
}

void printNext10(wordItem uniqueWords[], int N, int totalNumWords){
    for(int i = N; i < N+10; i++){
        float num = uniqueWords[i].count; 
        float prob = num/totalNumWords;
        cout << setprecision(4) << fixed << (prob + 0.00002) << " - " << uniqueWords[i].word << endl; 
    }
}

//main function 
int main(int argc, char* argv[]){
    string ignoreWords[50]; 

    getStopWords(argv[3], ignoreWords); 

    ifstream inStream(argv[2]);
    if(inStream.fail()){
        return -1; 
    } 

    int length = 100; 
    int ind = 0; 
    int num = 0; 
    wordItem* arr1 = new wordItem[length]; 

    string l = " "; 

    while(inStream >> l){
        bool val = false; 
        if(!isStopWord(l, ignoreWords)){
            for(int i = 0; i < ind; i++){
                if(arr1[i].word == l){
                    arr1[i].count++; 
                    val = true; 
                    break; 
                }
            }
            if(ind == length){
                doubleArraySize(arr1, &length); 
                num++; 
            }
            if(!val){
                arr1[ind++].word = l; 
                val = false; 
            }
        }
    }
    inStream.close(); 

    arraySort(arr1, ind); 
    int totalNumWords = getTotalNumberNonStopWords(arr1, ind) + ind; 
    
    cout << "Array doubled: " << num << endl; 
    cout << "#" << endl; 
    cout << "Unique non-common words: " << ind << endl; 
    cout << "#" << endl; 
    cout << "Total non-common words: " << totalNumWords << endl; 
    cout << "#" << endl; 
    cout << "Probability of next 10 words from rank " << stoi(argv[1]) << endl; 
    cout << "---------------------------------------" << endl; 


    printNext10(arr1, stoi(argv[1]), totalNumWords); 

    
    return 0; 
}