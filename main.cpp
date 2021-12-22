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
};

int main(){
    return 0;
};