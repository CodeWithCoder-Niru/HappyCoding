
#include <bits/stdc++.h>

struct Node {
    int data;
    Node *next;
    Node(int value):data(value), next(nullptr){}
};


class Stack {

    public:

    Node *head = nullptr;
    Node *tail = nullptr;

    void push(int value) {
        Node *newNode = new Node(value);

        if(head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
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

    int top() {
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
    Stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);

    while(!q1.empty()) {
        std::cout<< q1.top() << " ";
        q1.pop();
    }
    return 0;

}