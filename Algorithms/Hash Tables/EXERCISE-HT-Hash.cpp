#include <iostream>

using namespace std;


class Node {
    public:
        string key;
        int value;
        Node* next;

        Node(string key, int value) {
            this->key = key;
            this->value = value;
            next = nullptr;
        }
};

class HashTable {
    private:
        static const int SIZE = 7;
        Node* dataMap[SIZE];
        
    public:
int hash(string key) {
    int hash = 0; // Initialize hash value to 0

    // Iterate over each character in the string
    for (int i = 0; i < key.length(); i++) {
        // Retrieve the ASCII value of the character at position i
        int asciiValue = int(key[i]);

        // Update the hash value:
        // - Multiply ASCII value by 23 to spread out the values more uniformly
        // - Add the result to the current hash value
        // - Take modulo SIZE to ensure the hash value fits within the bounds of the hash table
        hash = (hash + asciiValue * 23) % SIZE;
    }

    // Return the computed hash value
    return hash;
}
    	// HASH FUNCTION MUST BE PUBLIC FOR CODE IN MAIN TO WORK
    	
        // WRITE HASH MEMBER FUCTION HERE //
        //                                //
        //                                //
        //                                //
        //                                //
        //                                //
        ////////////////////////////////////  

    public:
        // ---------------------------------------------------
        //  Destructor code is similar to keys() function
        //  Watch that video to help understand how this works
        // ---------------------------------------------------
        ~HashTable() {
            for(int i = 0; i < SIZE; i++) {
                Node* head = dataMap[i];
                Node* temp = head;
                while (head) {
                    head = head->next;
                    delete temp;
                    temp = head;
                }
            }
        }
        
        void printTable() {
            for(int i = 0; i < SIZE; i++) {
                cout << i << ":" << endl;
                if(dataMap[i]) {
                    Node* temp = dataMap[i];
                    while (temp) {
                        cout << "   {" << temp->key << ", " << temp->value << "}" << endl;
                        temp = temp->next;
                    }
                }
            }
        }
    
};


int main() {

    HashTable* myHashTable = new HashTable();

    // HASH FUNCTION MUST BE SET TO PUBLIC FOR THESE LINES TO WORK:
    cout << "nails: " << myHashTable->hash("nails");
    cout << "\nbolts: " << myHashTable->hash("bolts");
    cout << "\nlumber: " << myHashTable->hash("lumber");
    cout << "\ntile: " << myHashTable->hash("tile");
    cout << "\nscrews: " << myHashTable->hash("screws");



    /*
        EXPECTED OUTPUT:
        ----------------
        nails: 6
        bolts: 4
        lumber: 6
        tile: 6
        screws: 3

    */  

}

