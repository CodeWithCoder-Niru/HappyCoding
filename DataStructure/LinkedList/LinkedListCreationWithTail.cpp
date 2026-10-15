// Linked List creation with tail pointer


#include<bits/stdc++.h>

struct Node{
    int data;
    Node *next;
    Node(int value): data(value), next(nullptr){}
};


class LinkedList {

    public:
        Node *head = nullptr;
        Node *tail = nullptr;

    
    void pushFront(int value) {
        Node *newNode = new Node(value);

        if(head == nullptr){
            head = tail = newNode;
            return;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void pushBack(int value) {
        Node *newNode = new Node(value);

        if(head == nullptr)
            head=tail=newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void popFront() {

        if(head == nullptr) {
            std::cout<<"LL is empty";
            return;
        }

        Node *temp = head;
        head = head->next;
        temp->next =  nullptr;
        delete temp;
    }

    void pop_Back() {
        if(head == nullptr) {
            std::cout<<"LL is empty";
            return;
        }

        Node *temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }

        temp->next = nullptr;
        delete tail;
        tail = temp;
    }

    void printLinkedList() {

        Node *temp = head;

        while(temp) {
            std::cout<<temp->data << "->";
            temp = temp->next;
        }
        std::cout<<"nullptr" <<std::endl;
    }

    void insertNewNode(int value, int pos) {

        if(pos < 0) 
            std::cout<< "Invalid Postion";
        
        if(pos == 0)
            pushFront(value);

        Node *newNode = new Node(value);

        Node *temp = head;
        for(int i=0; i<pos-1;i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void reverseLinkedList(LinkedList *ll){
        Node *prev = nullptr;
        Node *curr = head;
        Node *nxt = nullptr;

        while(curr) {
            nxt = curr->next;
            curr->next = prev;
            prev=curr;
            curr=nxt;
        }

        Node *temp = prev;
        while(temp) {
            std::cout<< temp->data;
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList ll;

    ll.pushFront(10);
    ll.pushBack(20);
    ll.pushBack(30);
    ll.pushBack(40);
    ll.pushBack(50);

    ll.printLinkedList();

    ll.popFront();

    ll.printLinkedList();

    ll.popBack();

    ll.printLinkedList();

    ll.insertNewNode(50, 3);

    ll.printLinkedList();

    ll.reverseLinkedList(&ll);
}