/*Detect the Cycle in Linked List*/
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
            // newNode->next = head; 
        }

        void createCyclicLL() {
            Node *temp = head;

            int cnt = 1;
            int pos = 3;
            Node *cyclicNode = nullptr;

            while(temp->next) {
                if(cnt == pos) {
                    cyclicNode = temp;
                    
                }
                temp = temp->next;
                cnt++;
            }

            temp->next = cyclicNode;

        }

        void detectCycle(LinkedList *ll) {
            Node *slow = head;
            Node *fast = head;
            bool isCycle = false;

            while(fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;

                if(slow == fast) {
                    std::cout<< "Cycle exist in the LinkedList";
                    isCycle = true;
                    return;
                }
            }
            if(isCycle == false) {
                std::cout<< "No Cycle exist in the LinkedList";
            }

        }

        void strtNodeofCycle(LinkedList *ll) {
            Node *slow = head;
            Node *fast = head;
            bool isCycleExit = false;

            while(fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;

                if(slow == fast) {
                    std::cout<< "Cycle exist in the LinkedList" <<std::endl;
                    isCycleExit = true;
                    break;
                }
            }

            if(isCycleExit) {
                slow = head;
                while(slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                std::cout<< "starting node of LL: "<<slow->data <<std::endl;
            }
        }

        void RemoveCycleFromLL(LinkedList *ll) {
            Node *slow = head;
            Node *fast = head;
            bool isCycleExit = false;

            while(fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;

                if(slow == fast) {
                    std::cout<< "Cycle exist in the LinkedList" <<std::endl;
                    isCycleExit = true;
                    break;
                }
            }

            if(isCycleExit) {
                slow = head;
                Node *prev = nullptr;
                while(slow != fast) {
                    slow = slow->next;
                    prev = fast;
                    fast = fast->next;
                }

                prev->next = nullptr;
                std::cout<< "removed the cycle in LL" <<std::endl;
            }
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

    LinkedList ll;
    ll.pushFront(10);
    ll.pushback(20);
    ll.pushback(30);
    ll.pushback(40);
    ll.pushback(50);
    ll.pushback(60);

    ll.printll();

    ll.createCyclicLL();
    ll.detectCycle(&ll);
    ll.strtNodeofCycle(&ll);
    //ll.printll();
    ll.RemoveCycleFromLL(&ll);
    ll.printll();
    ll.detectCycle(&ll);


    // ll.middleNode();


}