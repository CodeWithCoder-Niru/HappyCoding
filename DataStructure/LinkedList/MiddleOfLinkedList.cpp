/*find the Middle Node in a Linked List*/


#include<bits/stdc++.h>

struct Node{
    int data;
    Node *next;
    Node(int value): data(value), next(nullptr){
    }
};

class LinkedList {
    public:
        Node *head = nullptr;

        void pushFront(int value) {
            Node *newNode = new Node(value);

            if(head == nullptr) {
                head = newNode;
            }else {
                newNode->next = head;
                head = newNode;
            }

        }

        void pushback(int value) {
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

        void middleNode() {

            // Node *temp = head;
            // int cnt=1;

            // while(temp->next){
            //     temp = temp->next;
            //     cnt++;
            // }
            // std::cout<<cnt;

            // Node *fast = head;
            // for(int i=0 ; i< cnt/2; i++) {
            //     fast = fast->next;
            // }

            // std::cout<< fast->data;

            Node *slow = head;
            Node *fast = head;

            while(fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
            }

            std::cout<< slow->data;



        }

        void printll() {

            Node *temp=head;
            while(temp) {
                std::cout<<temp->data << "->";
                temp = temp->next;
            }
            std::cout<<"nullptr" <<std::endl;
        }
};

int main() {

    LinkedList L1;
    LinkedList L2;

    L1.pushFront(10);
    L1.pushback(20);
    L1.pushback(30);
    L1.pushback(40);
    L1.pushback(50);
    L1.pushback(60);

    L2.pushFront(70);
    L2.pushback(80);
    L2.pushback(90);
    L2.pushback(100);
    L2.pushback(120);
    L2.pushback(130);

    L2.printll();

    L1.middleNode();


}