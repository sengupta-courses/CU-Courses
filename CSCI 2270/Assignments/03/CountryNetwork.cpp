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
        return node; 
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
void CountryNetwork::transmitMsg(string receiver, string message)
{
    // TODO
    //isEmpty, print "Empty List" and exit 
    if(head == NULL){
        cout << "Empty List" << endl; 
        return; 
    }
    //if node is not present, print "Country not Found"
    if(searchNetwork(receiver) == NULL){
        cout << "Country not Found" << endl; 
    }
    //transverse from head to node with name receiver 
    //set each node's message to msg and increment node's numberMessages 
    Country *node = head; 
    while((node != NULL) && (node != searchNetwork(receiver) -> next)){
        node -> message = message;
        node -> numberMessages += 1;
        cout << node -> name << " [# messages received: " << node -> numberMessages << "] received: " << node -> message << endl;
        node = node -> next; 
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
    if(head == NULL){
        cout << "nothing in path" << endl; 
    }

    cout << "==CURRENT PATH==" << endl;
    Country *node = head; 

    while(node != NULL){
        cout << node -> name << "->"; 
        node = node -> next; 
    }
    cout << "NULL" << endl << "===" << endl; 
}
