struct Node
{
    int key;
    Node* left;
    Node* right;
};

class BST
{
    private:
        Node* root;

    public:
        BST();
        ~BST();
        void print_depths(int val);
        void insert(int val);
        Node* search(int val);
        void print();
        void inorder();
};

// Helper signatures
void recursive_destroy(Node* n);
Node* recursive_insert(Node* n, int val);
Node* recursive_search(Node* n, int val);
void recursive_inorder(Node* n);
void print2DUtil(Node *n, int space = 0, int COUNT = 10);