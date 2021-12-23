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
        // linked list constructor
        LinkedList(){
            head = NULL;
            current = NULL;
            temp = NULL;
        };

        // destroy linked list entirely
        ~LinkedList(){
            current = head;
            while (current != NULL){
                Node *next = current->next;
                delete current;
                current = next;
            }
            head = NULL;
            cout << "Linked list destroyed successfully." << endl;
        };

        // add node to the end of the list
        void addNode(int data) {
            Node *n = new Node;
            n->data = data;
            n->next = NULL;

            if(head == NULL) {
                head = n;
                return;
            };

            current = head;
            while(current->next != NULL) {
                current = current->next;
            };
            current->next = n;
        };

        // delete a node from list
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

            if(current == head) {
                head = head->next;
                temp = NULL;
            } else {
                deletePtr = current;
                current = current->next;
                temp->next = current;
            }

            delete deletePtr;
            cout << data << " was deleted successfully." << endl;
        };

        bool isEmpty() {
            return head == NULL;
        };

        void display() {
            if(isEmpty()) {
                cout << "List is empty." << endl;
                return;
            }

            current = head;
            cout << "List items are: " << endl;
            while(current != NULL) {
                cout << current->data << endl;
                current = current->next;
            };
        };
};

int main(){
    LinkedList myList;

    myList.addNode(10);
    myList.addNode(20);
    myList.addNode(30);

    myList.deleteNode(10);

    myList.display();

    return 0;
};