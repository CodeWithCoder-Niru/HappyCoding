
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

    
    void insertAtHead(int value) {
        Node *newNode = new Node(value);

        if(head == nullptr) {
            head=tail = newNode;
            tail->next = head;
        } else {
            newNode->next = head;
            head = newNode;
            tail->next = newNode;
        }

    }

    void insertAtTail(int value) {
        Node *newNode = new Node(value);
        if(head == nullptr) {
            head=tail = newNode;
            tail->next = head;
        } else {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }

    }

    void printLL() {

        std::cout<< head->data << "->";

        Node *temp = head->next;

        while(temp != head) {
            std::cout<< temp->data << "->";
            temp=temp->next;
        }

        std::cout<<temp->data <<std::endl;
    }

    void deleteNodeAtHead() {

        if(head == nullptr) {
            std::cout <<"LL is empty";
        } else if(head == tail) {
            delete head;
            head=tail=nullptr;
        } else {
            Node *temp=head;

            head = head->next;
            tail->next = head;
            temp->next = nullptr;
            delete temp;
        }
    }

    void deleteNodeAtTail() {
        if(head == nullptr) {
            std::cout <<"LL is empty";
        } else if(head == tail) {
            delete head;
            head=tail=nullptr;
        } else {
            Node *temp=tail;

            Node *prev = head;
            while(prev->next != tail) {
                prev = prev->next;
            }

            tail = prev;
            tail->next = head;
            temp->next = nullptr;
            delete temp;
        }

    }
};

int main() {
    LinkedList ll;
    ll.insertAtHead(10);
    ll.insertAtTail(20);
    ll.insertAtTail(30);
    ll.printLL();
    ll.deleteNodeAtHead();
    ll.printLL();
    ll.deleteNodeAtTail();
    ll.printLL();
}