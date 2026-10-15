

#include <bits/stdc++.h>

struct Node {
    int data;
    Node *next;
    Node(int val):data(val), next(nullptr){}
};

Node* ReverseLinkedList(Node *head) {

    if(head == nullptr || head->next == nullptr)
        return head;

    Node* newNode = ReverseLinkedList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newNode;
}

int main() {

    Node *l1 = new Node(10);
    l1->next = new Node(20);
    l1->next->next = new Node(30);
    l1->next->next->next = new Node(40);
    l1->next->next->next->next = new Node(50);

    Node *collect = ReverseLinkedList(l1);

    while(collect){
        std::cout<< collect->data << "->";
        collect = collect->next;
    }

}