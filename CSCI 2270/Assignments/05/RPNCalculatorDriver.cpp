/****************************************************************/
/*                  RPN Calculator Driver File                  */
/****************************************************************/
/*      TODO: Implement driver as described in the writeup      */
/****************************************************************/

#include "RPNCalculator.hpp"
#include <iostream>
#include <string> 
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: Determine whether some user input string is a
 *          valid floating point number
 * @param none
 * @return true if the string s is a number
 */


RPNCalculator::RPNCalculator(){
  stackHead = NULL; 
}

RPNCalculator::~RPNCalculator(){
  while(!isEmpty()){
    pop(); 
  }
}

bool RPNCalculator::isEmpty(){
  if(stackHead == NULL){
    return true; 
  }
  else{
    return false; 
  }
}

void RPNCalculator::push(float number){
  //push value of stackHead into the next position  
  Operand *val = new Operand(); 
  val -> number = number; 
  val -> next = stackHead; 
  //redefine stackHead 
  stackHead = val; 
}

void RPNCalculator::pop(){
  if(!isEmpty()){
    Operand *val = new Operand(); 
    val = stackHead; 
    stackHead = stackHead -> next; 
    delete val; 
  }
  else{
    cout << "Stack empty, cannot pop an item."  << endl; 
  }
}

Operand* RPNCalculator::peek(){
  if(!isEmpty()){
    return stackHead; 
  }
  else{
    cout << "Stack empty, cannot peek." << endl;
    return NULL;  
  }
}

bool RPNCalculator::compute(string symbol){
  float val1; 
  float val2; 
  float compVal; 

  if(symbol == "+"){
    if(isEmpty()){
      cout << "err: not enough operands" << endl; 
      return false; 
    }

    val1 = stackHead -> number; 
    pop(); 
    if(isEmpty()){
      cout << "err: not enough operands" << endl; 
      push(val1); 
      return false; 
    }

    val2 = stackHead -> number; 
    pop(); 
    compVal = val1 + val2; 
    push(compVal); 
    return true; 
  }

  else if(symbol == "*"){
    if(isEmpty()){
      cout << "err: not enough operands" << endl; 
      return false; 
    }
    val1 = stackHead -> number; 
    pop(); 
    if(isEmpty()){
      cout << "err: not enough operands" << endl; 
      push(val1); 
      return false; 
    }

    val2 = stackHead -> number; 
    pop(); 
    compVal = val1*val2; 
    push(compVal); 
    return true; 
  }

  else if(symbol == "="){
    return true; 
  }

  else{
    cout << "err: invalid operation" << endl; 
    return false; 
  }
}

bool isNumber(string s)
{
    if(s.size() == 1 && s == "-") return false;
    else if(s.size() > 1 && s[0] == '-') s = s.substr(1);

    bool point = false;
    for(int i = 0; i < s.size(); i++)
    {
      if(!isdigit(s[i]) && s[i] != '.') return false;
      if(s[i]=='.' and !point) point = true;
      else if(s[i]=='.' and point) return false;
    }

    return true;
}

int main()
{
  // TODO - Declare a stack to hold the operands
  RPNCalculator calc; 
  // int operand = 0; 
  // int operator = 0; 
  string input;

  cout << "Enter the operators and operands ('+', '*') in a postfix format" << endl;

  while(true)
  {
        cout << "#> ";
        getline(cin, input);
        /* TODO
           1. Read input (operators and operands) until you encounter a "="
           2. Use the isNumber function to check if the input is an operand
           3. push all operands to the stack
           4. If input is not an operand, call the compute function to evaluate
              the partial expression
        */
        
    
        if(input == "="){
           break; 
       }
       
        if(isNumber(input)){
            //operands++; 
           calc.push(stof(input)); 
       }
       
       else{
           //operators++; 
           calc.compute(input); 
       }
  }
    
      /* TODO - If the stack is empty then print "No operands: Nothing to evaluate" */
      if(calc.isEmpty()){
        cout << "No operands: Nothing to evaluate" << endl; 
        return 0; 
      }
      /* TODO - Validate the expression
          1. If valid then print the result
          2. Else, print "Invalid expression"*/
      float end = calc.peek() -> number; 
      calc.pop(); 
      if(!calc.isEmpty()){
          cout << "Invalid expression" << endl; 
          return 0;
      }
      
      else{
          cout << end << endl; 
          return 0; 
      }
}
