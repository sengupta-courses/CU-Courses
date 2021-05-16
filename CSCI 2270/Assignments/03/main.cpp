
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
    int userChoice = 0; 
    // Object representing our network of cities.
    // (Linked list representation is in CountryNetwork)
    CountryNetwork CountryNet;

    string input = " "; 
    int opt = 0; 
    displayMenu(); 
    cin >> input; 
    opt = stoi(input); 
    // TODO
    userChoice = opt; 

    if(userChoice < 1 || userChoice > 5){
        cout << "Invalid Input. Please choose again. " << endl; 
    }
    else{
        switch(userChoice){
            case 1: 
            {
                //Option 1: Build Network 
                //calls loadDefaultSetup
                CountryNet.loadDefaultSetup(); 
                //calls printPath 
                CountryNet.printPath(); 
                break; 
            }

            case 2: 
            {
                //Option 2: Print Network Path 
                //calls printPath 
                CountryNet.printPath(); 
                break; 
            }

            case 3: 
            {
                //Option 3: Transmit Message 
                string countryReceive = " "; 
                cout << "Enter name of the country to receive the message: " << endl; 
                getline(cin, countryReceive); 
                cout << endl; 

                string msgSend = " "; 
                cout << "Enter the message to send " << countryReceive << endl; 
                getline(cin, msgSend);
                cout << endl; 

                cout << endl; 
                CountryNet.transmitMsg(countryReceive, msgSend); 
                cout << endl;  
                break; 
            }

            case 4: 
            {
                //Option 4: Add Country 
                //prompt user for name of new country, newCountry 
                string countryNew = " "; 
                cout << "Enter a new country name: " << endl; 
                getline(cin, countryNew); 
                countryNew[0] = toupper(countryNew[0]); 
                cout << endl; 
                //prompt user for country already in netowrk, previous 
                string prevCountry = " "; 
                cout << "Enter the previous country name (or First): " << endl; 
                getline(cin, prevCountry); 
                cout << endl; 

                //insert newCountry after previous 
                Country *prev = CountryNet.searchNetwork(prevCountry); 
                if(prev == NULL){
                    cout << "INVALID " << prevCountry << "Please enter a VALID previous country name!" << endl; 
                }
                else{
                    CountryNet.insertCountry(prev, countryNew); 
                }
                cout << endl; 
                CountryNet.printPath(); 
                break; 
            } 
            case 5: 
            {
                //Option 5: Quit
                cout << "Quitting..." << endl; 
                cout << "Goodbye!" << endl;
                return 0; 
            }
        }
    }
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
