
#include <bits/stdc++.h>

struct Node {
    int data;
    Node *next;
    Node(int value):data(value), next(nullptr){}
};


class Queue {

    public:

    Node *head = nullptr;
    Node *tail = nullptr;

    void push(int value) {
        Node *newNode = new Node(value);

        if(head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop() {

        if(head == nullptr) {
            //queue is empty
            return ;
        }

        Node *temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
    }

    int front() {
        if(head == nullptr) {
            //queue is empty
            return 0;
        }

        return head->data;
    }

    int empty() {

        return head == nullptr;
    }

};

int main() {
    Queue q1;
    q1.push(10);
    q1.push(20);
    q1.push(30);
    q1.push(40);

    while(!q1.empty()) {
        std::cout<< q1.front() << " ";
        q1.pop();
    }
    return 0;

}