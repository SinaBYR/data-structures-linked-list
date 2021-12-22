#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
};

class LinkedList {
    private:
        Node *head;
        Node *current;
        Node *temp;
    public:
        LinkedList(){
            head = NULL;
            current = NULL;
            temp = NULL;
        };

        // ~LinkedList(){
        //     Node *cutptr = head;
        //     Node *temp;
        //     while (cutptr != NULL){
        //         temp = cutptr;
        //         cutptr = cutptr->next;
        //         delete temp;
        //     }
        // };

        void addNode(int data) {
            Node *n = new Node();
            n->data = data;
            n->next = NULL;

            if(head) {
                head = n;
                return;
            }

            current = head;
            while(current->next != NULL) {
                current = current->next;
            }
            current->next = n;
        };

        void deleteNode(int data) {
            Node *deletePtr = NULL;
            current = head;
            temp = head;

            while(current != NULL && current->data != data) {
                temp = current;
                current = current->next;
            };

            if(current == NULL) {
                cout << data << " was not found in the list" << endl;
                delete deletePtr;
                return;
            };

            deletePtr = current;
            current = current->next;
            temp->next = current;
        }
};

int main(){
    return 0;
};


// if(head != NULL) {
//     current = head;
//     while(current->next != NULL) {
//         current = current->next;
//     }
//     current->next = n;
// } else {
//     head = n;
// }