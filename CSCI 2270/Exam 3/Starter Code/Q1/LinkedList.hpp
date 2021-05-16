#include <string>

struct Node
{
    int key;
    Node* next;
};

class LinkedList 
{   
    private:
        Node* head;
    
    public:
        LinkedList();
        ~LinkedList();

        void append(int key);   // Creates and inserts a new node at the **END** of list
        std::string print();    // Returns the same output as string for testcase verification
        void moveEvens();
};