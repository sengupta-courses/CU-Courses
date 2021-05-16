/****************************************************************/
/*                Producer Consumer Driver File                 */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

/****************************************************************/
/*                Producer Consumer Driver File                 */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "ProducerConsumer.hpp"
#include <iostream>
#include <string> 

// you may include more libraries as needed

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */

ProducerConsumer::ProducerConsumer(){
	queueFront = 0; 
	queueEnd = 0;
}

bool ProducerConsumer::isEmpty(){
	if(counter == 0){
		return true; 
	}
	else{
		return false; 
	}
}

bool ProducerConsumer::isFull(){
	if(counter == SIZE){
		return true; 
	}
	else{
		return false; 
	}
}

void ProducerConsumer::enqueue(string item){
	if(isFull()){
	    cout << "Queue full, cannot add new item" << endl; 
	}
	else{
	    queue[queueEnd] = item; 
	    queueEnd++; 
	    queueEnd = queueEnd % SIZE; 
	    counter++;
	}
}

void ProducerConsumer::dequeue(){
    if(isEmpty()){
        cout << "Queue empty, cannot dequeue an item" << endl;
    }
    else{
        queueFront++; 
        queueFront = queueFront % SIZE; 
        counter--; 
    }
}

string ProducerConsumer::peek(){
    string temp = " "; 
	if(isEmpty()){
	    cout << "Queue empty, cannot peek" << endl; 
	    temp = " ";
	    return temp; 
	}
	
	else{
	    temp = queue[queueFront]; 
	    return temp; 
	}
}

int ProducerConsumer::queueSize(){
    return counter; 
}



void menu()
{
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
    cout << "1. Producer (Produce items into the queue)" << endl;
	cout << "2. Consumer (Consume items from the queue)" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}
// Use getline for reading
int main(int argc, char const *argv[]) {
	ProducerConsumer que;
	string line = " ";  
	int total = 0; 

	
	while(line != "3"){
	    menu(); 
	    getline(cin, line); 
    	if(line == "1"){
    	    cout << "Enter the number of items to be produced: " << endl; 
    	    string numProduce = " "; 
    	    getline(cin, numProduce); 
    	    string newNum = " "; 
    	    int i = 0; 
    	    
    	    for(i = 0; i < stoi(numProduce); i++){
    	        cout << "Item" << i + 1 << ":" << endl; 
    	        getline(cin, newNum); 
    	        que.enqueue(newNum); 
    	    }
    	    total = total + stoi(numProduce); 
    	}
    	
    	else if(line == "2"){
    	    cout << "Enter the number of items to be consumed: " << endl; 
    	    string numConsume; 
    	    getline(cin, numConsume); 
    	    int j = 0; 
    	    
    	    for(j = 0; j < stoi(numConsume); j++){
    	        if(total == 0){
    	            cout << "No more items to consume from queue" << endl; 
    	            break;
    	        }
    	        
    	        cout << "Consumed: " << que.peek() << endl; 
    	        que.dequeue(); 
    	        total--; 
    	    }
    	    
    	}
    	else if(line == "3"){
    	        cout << "Number of items in the queue:" << total << endl; 
    	}
    }
}
