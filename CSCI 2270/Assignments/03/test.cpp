/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represet communication paths between nations             */
/****************************************************************/

#include "CountryNetwork.hpp"

using namespace std;

/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CountryNetwork::CountryNetwork()
{
    // set head pointer to NULL 
    head = NULL; 
}

/*
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
void CountryNetwork::insertCountry(Country* previous, string countryName)
{
    // TODO
    //find new country with name countryName 
    Country *newC = new Country(); 
    newC -> name  = countryName;

    //if previous is NULL, then add the new country to the 
        //beginning of the list 
    if(previous == NULL){
        newC -> next = head; 
        head = newC;
        //print name of the contry added 
        cout << "adding: " << countryName << " (HEAD)" << endl;  
    }
    else{
        newC -> next = previous -> next; 
        previous -> next = newC; 
        //print name of the country added
        cout << "adding: " << countryName << " (prev: " << previous -> name << ")" << endl; 
    }

}

/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup()
{
    // TODO
    //add United States, Canada, Brazil, India, China, and Australia 
        //to network with insertCountry 
    CountryNetwork(); 
    insertCountry(NULL, "United States"); 
    insertCountry(searchNetwork("United States"), "Canada"); 
    insertCountry(searchNetwork("Canada"), "Brazil"); 
    insertCountry(searchNetwork("Brazil"), "India"); 
    insertCountry(searchNetwork("India"), "China");
    insertCountry(searchNetwork("China"), "Australia"); 
}

/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 */
Country* CountryNetwork::searchNetwork(string countryName)
{
    // TODO
    //return a pointer to the node with the name countryName 
    //if countryName cannot be found, return NULL 
    Country *node = head; 

    while((node != NULL) && (node -> name.compare(countryName) != 0)){
        node = node -> next; 
    }
    if(node != NULL){
        return node; 
    }
    else{
        return NULL; 
    }
}

/*
 * Purpose: Transmit a message across the network to the
 *   receiver. Msg should be stored in each country it arrives
 *   at, and should increment that country's count.
 * @param receiver name of the country to receive the message
 * @param message the message to send to the receiver
 * @return none
 */
void CountryNetwork::transmitMsg(string receiver, string msg)
{
    Country *node = head; 
    // TODO
    //isEmpty, print "Empty List" and exit 
    if(node == NULL){
        cout << "Empty list" << endl; 
        return; 
    }
    //if node is not present, print "Country not Found"
    if(searchNetwork(receiver) == NULL){
        cout << "Country not found" << endl;
        return; 
    }
    //transverse from head to node with name receiver 
    //set each node's message to msg and increment node's numberMessages 
    else{
        while((node != NULL) && (node != searchNetwork(receiver) -> next)){
            node -> message = msg;
            node -> numberMessages += 1;
            cout << node -> name << " [# messages received: " << node -> numberMessages << "] received: " << node -> message << endl;
            node = node -> next; 
        }
    }
    
}

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath() {
    // TODO
    //print names of each node in the list 
    //if empty, print "nothing in path"

    cout << "== CURRENT PATH ==" << endl;
    Country *node = head; 
    
    if(head == NULL){
        cout << "nothing in path" << endl;
        cout << "===" << endl; 
        return; 
    }

    while(node != NULL){
        cout << node -> name << " -> "; 
        node= node -> next; 
    }
    cout << "NULL" << endl;
    cout << "===" << endl; 
}

/****************************************************************/
/*                   Assignment 3 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "CountryNetwork.hpp"
#include <iostream>
#include <fstream>
#include <string> 

void displayMenu();  // declaration for main's helper-function

int main(int argc, char* argv[])
{   
    CountryNetwork CountryNet;
    int userChoice; 
    string countryReceive; 
    string msgSend; 
    string newCName;
    string previous; 

    bool val = false; 

    while(userChoice != 5){
        displayMenu(); 
        cin>>userChoice; 

        switch(userChoice){
            case 1: 
                //Option 1: Build Network 
                //calls loadDefaultSetup
                CountryNet.loadDefaultSetup(); 
                //calls printPath 
                CountryNet.printPath(); 
            break; 

            case 2: 
                //Option 2: Print Network Path 
                //calls printPath 
                CountryNet.printPath(); 
            break; 

            case 3: 
                //Option 3: Transmit Message 
                cout << "Enter name of the country to receive the message: " << endl; 
                cin.ignore(); 
                getline(cin, countryReceive); 
                
                cout << "Enter the message to send: " << endl; 
                getline(cin, msgSend); 
                cout << endl; 
                CountryNet.transmitMsg(countryReceive, msgSend); 
            break; 

            case 4: 
                //Option 4: Add Country 
                //prompt user for name of new country, newCountry
                cin.ignore(); 
                cout << "Enter a new country name: " << endl; 
                getline(cin, newCName); 
                //prompt user for country already in netowrk, previous 
                cout << "Enter the previous country name (or First): " << endl; 
                
                while(val == false){
                    getline(cin, previous); 
                    if(previous == "First"){
                        CountryNet.insertCountry(NULL, newCName); 
                        val = true; 
                    }
                    //insert newCountry after previous 
                    else if(previous != "First"){
                        if(CountryNet.searchNetwork(previous) != NULL){
                            CountryNet.insertCountry(CountryNet.searchNetwork(previous), newCName); 
                            val = true; 
                        }
                
                        else{
                            cout << "INVALID(previous country name)...Please enter a VALID previous country name!" << endl; 
                        }
                    }
                }
                CountryNet.printPath(); 
                val = false; 
            break; 

            case 5: 
                cout << "Quitting..." << endl; 
                cout << "Goodbye!" << endl; 
            break; 

            default: 
                cout << "Invalid Input" << endl; 
            break; 
        }
    }
    return 0; 
}


/*
 * Purpose; displays a menu with options
 */
void displayMenu()
{
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
    cout << " 2. Print Network Path " << endl;
    cout << " 3. Transmit Message " << endl;
    cout << " 4. Add Country " << endl;
    cout << " 5. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}


