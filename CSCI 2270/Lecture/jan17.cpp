#include <iostream>
#include <fstream>
#include <sstream>
#include <string> 

using namespace std; 

struct Address {
    //unique ID: 1614011140000
    long id; 
    //Name: Ashuthosh Trivedi 
    string name; 
    //Phone number: (720) 707-9663
    string phone; 
    //ashutosh.trivedi@gmail.com
    string email; 
    //4141 Spruce Street
    string street; 
    //Philadelphia
    string city; 
    //PA
    string state; 
    //19104
    int zip; 
    //39.948610
    float lat; 
    //-75.177830
    float lon; 

    Address() {}; 
    Address(long _id, string _name, string _phone, string _email, string _street, string _city, string _state, int _zip, float _lat, float _lon){
        
        //assign input variable values to fixed variables 
        id = _id;
        name = _name; 
        phone = _phone; 
        email = _email; 
        street = _street; 
        city = _city; 
        state = _state; 
        zip = _zip; 
        lat = _lat; 
        lon = _lon; 
    }

    void fill(string _id, string _name, string _phone, string _email, string _street, string _city, string _state, string _zip, string _lat, string _lon){
        id = stol(_id); 
        name = _name; 
        phone = _phone; 
        email = _email; 
        street = _street; 
        city = _city;
        state = _state; 
        zip = stoi(_zip); 
        lat = stoi(_lat); 
        lon = stof(_lon); 
    }

    void prettyPrint() {
        cout << name << endl; 
        cout << "Unique Identity Number: \n " << id << endl; 
        cout << "Phone Number: \n +1" << phone << endl; 
        cout << "E-mail: \n " << email << endl; 
        cout << "Address: " << endl; 
        cout << " " << street << ", " << city << ", " << state << "-" << zip << endl; 
        cout << "Location: \n (" << lat << ", " << lon << ") " << endl; 
        cout << "_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/" << endl; 
    }
}; 

int main(int argc, char *argv[]) {
    if (argc != 2) cerr << "Error: incorrect number of arguments \n"; 
    else {
        ifstream fin(argv[1]); 
        if (fin.is_open()){
            //address database (array of structs)
            Address addressDB[100]; 
            int size = 0; 
            string line; 
            while (getline(fin, line)) {
                stringstream sin(line); 
                string id, name, phone, email, street, zip, city, state, lat, lon; 
                getline(sin, id, ','); 
                getline(sin, name, ','); 
                getline(sin, phone, ',');
                getline(sin, email, ',');
                getline(sin, street, ',');
                getline(sin, city, ',');
                getline(sin, state, ',');
                getline(sin, zip, ',');
                getline(sin, lat, ',');
                getline(sin, lon, ',');

                addressDB[size].fill(id, name, phone, email, street, city, state, zip, lat, lon); 
                size++; 
            }
            
            for (int i = 0; i <size; i++) addressDB[i].prettyPrint(); 
        }

        else cerr << "File addresses.txt not found!"; 
        fin.close(); 
        return 0; 
    }
}
