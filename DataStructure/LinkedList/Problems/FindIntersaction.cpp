/**find if two linked list have intersection point.*/

#include<bits/stdc++.h>

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

Node* getIntersectionNode(Node* head1, Node* head2) {
    if (!head1 || !head2)
        return nullptr;

    Node* p1 = head1;
    Node* p2 = head2;

    while (p1 != p2) {
        p1 = (p1 == nullptr) ? head2 : p1->next;
        p2 = (p2 == nullptr) ? head1 : p2->next;
    }

    return p1; // intersection node or nullptr
}

int main() {
    // Common part
    Node* common = new Node(7);
    common->next = new Node(8);
    common->next->next = new Node(9);

    // List 1: 1 -> 2 -> 3 -> 7 -> 8 -> 9
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(10);
    head1->next->next->next = common;

    // List 2: 4 -> 5 -> 7 -> 8 -> 9
    Node* head2 = new Node(4);
    head2->next = new Node(5);
    head2->next->next = common;

    Node* intersection = getIntersectionNode(head1, head2);

    if (intersection)
        cout << "Intersection point: " << intersection->data << endl;
    else
        cout << "No intersection found" << endl;

    return 0;
}
