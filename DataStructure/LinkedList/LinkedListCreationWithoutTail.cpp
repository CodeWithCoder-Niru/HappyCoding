/*LINKED LIST
// This is sequencial data structure and used store data
// It is special data structure, data elemets are linked to one another

//OPERATIONS:
//Insertion, Deletion, Traversing

//ADVANTAGE:
//Linked List is dynamic data structure , it can grow and shrink at runtime
//It is used to efficiently utilise the memory
//Insertion and deletion is very easy at any position

//DRAWBACKS:
//More memory required if list is too big
//Accessing element is time consuming

//TYPES OF LL:
//Single , Doably, Circular, Doubly Circular */

#include<bits/stdc++.h>

struct Node{
    int data;
    Node *next;
    Node(int value): data(value), next(nullptr){}

};

class LinkedList {
    public:
        Node *head = nullptr;
    
    void push_Front(int value){
        Node *newNode = new Node(value);

        if(nullptr == head) {
            head = newNode;
            return;
        } else {
            newNode->next = head;
            head = newNode;
        }

    }

    void push_Back(int value) {
        Node *newNode = new Node(value);

        if(head == nullptr) {
            head = newNode;
            return;
        }

        Node *temp = head;
        while(temp->next) {
            temp = temp->next;
        }

        temp->next = newNode;

    }

    void pop_Front(){

        if(head == nullptr) {
            std::cout<<"LL is empty";
            return;
        }

        Node *temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;

        //If you want remove all Nodes from LL run it in while loop
        // while(head) {
        //     head = head->next;
        //     temp->next = nullptr;
        //     delete temp;
        // }
    }

    void pop_Back() {
        if(head == nullptr) {
            std::cout<< "LL is empty";
            return;
        }

        Node *prev = nullptr;
        Node *curr = head;
        while(curr->next) {
            prev = curr;
            curr = curr->next;
        }
        delete curr;
        prev->next = nullptr;

        //one more method is that using next->next pointer to delete it

        // while(curr->next->next) {
        //     curr = curr->next;
        // }
        // delete curr->next;
        // curr->next = nullptr;
    }

    void insertNode(int value , int pos) {
        if(pos < 0)
            std::cout<<"Invalid Position";
        
        if(pos == 0)
            push_Front(value);
        
        Node *newNode = new Node(value);
        Node *temp = head;
        for(int i =0 ;i<pos -1; i++) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    int searchKey(int key) {
        int index =0 ;
        Node *temp = head;
        while(temp) {
            if(temp->data == key){
                return index;
            }
            temp = temp->next;
            index++;
        }

        return -1;


    }

    void printLinkedList() {

        Node *temp = head;
        while(temp) {
            std::cout<< temp->data << "->";
            temp = temp->next;
        }
        std::cout<<"nullptr" <<std::endl;
    }
};





int main() {
    LinkedList ll;

    ll.push_Front(10);
    ll.push_Back(20);
    ll.push_Back(30);
    ll.push_Back(40);
    ll.pop_Front();
    ll.pop_Back();

    ll.insertNode(40 , 2);


    // ll.popFront();

    ll.printLinkedList();

    std::cout<< ll.searchKey(30);
    return 0;
}
