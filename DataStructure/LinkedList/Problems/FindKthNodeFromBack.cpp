/**
 * @brief We will see how to find k'th number from back in singly linked list with one traversal.
 * The idea is we will maintain two pointers and one pointer will move to k'th number and 
 * then we will move both the pointer at the same time, and by the time first pointer is reaching 
 * to the last node second pointer would be at desired node.
 */

#include<bits/stdc++.h>

struct Node{
    int data;
    Node *next;
    Node(int value): data(value), next(nullptr){}
};

class LinkedList {
    public:
        Node *head = nullptr;

        void push_back(int value){
            Node *newNode = new Node(value);

            if(head == nullptr) {
                head = newNode;
                return;
            }

            Node *temp = head;
            while(temp->next){
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->next = nullptr;
        }

        void FindKthNodeFromLast(int k){
            Node *slow = head;
            Node *fast = head;

            int pos = 0;

            while(fast->next) {
                if(pos == k)
                    break;
                ++pos;
                fast = fast->next;
            }

            while(fast){
                slow = slow->next;
                fast = fast->next;
            }
            std::cout<< slow->data <<std::endl;
        }

        void printll(){
            Node *temp = head;
            while(temp){
                std::cout<< temp->data << "->";
                temp = temp->next;
            }
            std::cout<< "nullptr" <<std::endl;
        }
};

int main(){

    LinkedList ll;
    ll.push_back(10);
    ll.push_back(20);
    ll.push_back(30);
    ll.push_back(40);
    ll.push_back(50);

    ll.printll();

    ll.FindKthNodeFromLast(1);
}