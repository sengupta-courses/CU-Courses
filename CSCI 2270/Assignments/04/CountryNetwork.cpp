/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represent communication paths between nations             */
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
/* finished. do not touch. */
    head = NULL;
}


/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CountryNetwork::isEmpty()
{
/* finished. do not touch. */
    return (head == NULL);
}


/*
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
void CountryNetwork::insertCountry(Country* previous, string countryName) {
    
    // if we are passed an empty list, just create a new head node, and return
    if (head == NULL)
    {
        cout << "adding: " << countryName << " (HEAD)" << endl;
        head = new Country;
        head->name = countryName;
        head->numberMessages = 0;
        head->next = NULL;
    }
    // if it's not empty, we need to search for previous and append our node there.
    else if(previous == NULL )
    {
        //case where it's a new head Country
        cout << "adding: " << countryName << " (HEAD)" << endl;
        Country *c = new Country;
        c->name = countryName;
        c->numberMessages = 0;
        c->next = head;
        head = c;
    }else{
        cout << "adding: " << countryName << " (prev: " << previous->name << ")" << endl;
        Country *newCountry = new Country;
        newCountry->name = countryName;
        newCountry->numberMessages = 0;
        newCountry->next = previous->next;
        previous->next = newCountry;
    }
}


/*
 * Purpose: delete the country in the network with the specified name.
 * @param countryName name of the country to delete in the network
 * @return none
 */
void CountryNetwork::deleteCountry(string countryName) {
    //TODO: Complete this function
    Country *node = head; 
    Country *deleted; 
    if (node ->name.compare(countryName) == 0){
        head = head -> next; 
        //cout << "deleting: " << node -> name << endl;
        return; 
    }

    while(node -> next != NULL && node -> next -> name.compare(countryName) != 0){
        node = node -> next; 
    }
    
    
    if(node -> next != NULL){
        //cout << "deleting: " << node -> name << endl; 
        deleted = node -> next; 
        node -> next = deleted -> next; 
        delete deleted; 
        return; 
    }
    else{
        cout << "Country does not exist." << endl; 
    }
}
/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup()
{
    int num_countries = 6;
    string countries[] = {"United States", "Canada", "Brazil", "India", "China", "Australia"};
    // deleteEntireNetwork();
    Country* prev = NULL;
    for(int i = 0; i < num_countries; i++)
    {
        insertCountry(prev, countries[i]);
        prev = searchNetwork(countries[i]);
    }
}


/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 * @see insertCountry, deletecountry
 */
Country* CountryNetwork::searchNetwork(string countryName)
{
// Search until the head is NULL, or we find the country
    Country* ptr = head;
    while (ptr != NULL && ptr->name != countryName)
    {
        ptr = ptr->next;
    }
    // Return the node, or NULL
    return ptr;
}

/*
* Purpose: Creates a loop from last node to the country specified.
* @param countryName name of the country to loop back
* returns pointer to last node before loop creation (to break the loop)
*/
Country* CountryNetwork::createLoop(string countryName)
{
    //TODO: Complete this function
    Country* node = head; 
    Country* add = NULL; 

    while(node -> next != NULL){
        if(node -> name == countryName){
            add = node; 
        } 
        else if(node -> next -> name == countryname){
            add = node -> next; 
        }
    }

    add = node -> next; 
    return node; 
}


/*
 * Purpose: deletes all countries in the network starting at the head country.
 * @param none
 * @return none
 */
void CountryNetwork::deleteEntireNetwork()
{
    //TODO: Complete this function
    Country *node = head; 
    Country *deleted; 

    while(node != NULL){
        deleted = node; 
        cout << "deleting: " << node -> name << endl; 
        node = node -> next; 
        delete deleted; 
    }
    cout << "Deleted network" << endl;
    head = NULL; 
}

void CountryNetwork::deleteEntireNetwork() { 
    Country *start = head;

    while(start != NULL) {
        Country *del = start;
        start = start->next;
        cout << "deleting: " << del->name << endl;
        delete del;
    }

    cout << "Deleted Network!" << endl;
    head = NULL;
}

/*
*Purpose: to detect loop in the linkedlist
* @param
* returns true if loop is detected. Otherwise return false.
*/
bool CountryNetwork::detectLoop() {
    //TODO: Complete this function
    Country *node1 = head;
    Country *node2 = head; 
    bool val = true; 
    if(head == NULL){
        //no loop 
        val = false; 
        return val; 
    }
    //while there is a loop 
    while(val == true){
        node1 = node1 -> next; 

        if(node2 -> next != NULL){
            node2 = node2 -> next -> next; 
        }
        else{
            //no loop 
            val = false; 
            return val; 
        }
        
        if(node1 == NULL || node2 == NULL){
            //no loop 
            val = false; 
            return val; 
        }
        
        if(node1 == node2){
            //there is a loop 
            val = true; 
            return val; 
        }
    }
    return val; 
}



  
/*
* Purpose: Take the chunk of nodes from start index to end index
*          Move that chunk at the end of the List
*@param: start index
*@param: end index
* return none
*/
void CountryNetwork:: readjustNetwork(int start_index, int end_index)
{
    int count = 0; 
    Country *first = head; 
    Country *var = NULL; 
    Country *last = head; 
    Country *size = head; 
    //TODO: Complete this function'

    while (size != NULL)  
    {  
        count++;  
        size = size->next;  
    } 

    //if the linked list in empty 
    if(head == NULL){
        cout << "Linked List is Empty" << endl; 
    }

    //if endIndex is greater than the index of the last element 
        //or smaller than 0 
    else if(end_index < 0 || start_index > end_index) {
        cout << "Invalid indices" << endl; 
        return; 
    }
    else if(end_index > count) {
        cout << "Invalid end index" << endl;
        return; 
    }
    //if startIndex is bigger than the number of nodes in the list 
        //or small than 0 
    else if(start_index < 0 || start_index > count){
        cout << "Invalid start index" << endl; 
        return; 
    }
    else{
        for(int i = 0; i < start_index; i++){
            var = first; 
            first = first -> next; 
        }

        for(int j = 0; j < end_index; j++){
            last = last -> next; 
        }

        if(start_index == 0){
            head = last -> next; 
            var = head; 
            while(var -> next != NULL){
                var = var -> next; 
            }

            var -> next = first; 
            last -> next = NULL; 
        }
        else if(last -> next != NULL){
            var -> next = last -> next; 
            while(var -> next != NULL){
                var = var -> next; 
            }
            
            var -> next = first; 
            last -> next = NULL; 
        }
    } 
}
/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath() {
    cout << "== CURRENT PATH ==" << endl;
    // If the head is NULL
    Country* ptr = head;
    if (ptr == NULL)
        cout << "nothing in path" << endl;

    // Otherwise print each node, and then a NULL
    else
    {
        while (ptr->next != NULL)
        {
            cout << ptr->name << " -> ";
            ptr = ptr->next;
        }
        cout << ptr->name << " -> ";
        cout << "NULL" << endl;
    }
    cout << "===" << endl;
}
