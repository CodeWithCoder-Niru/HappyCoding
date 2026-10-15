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
        Node *tail = nullptr;

        Node* mergeNodesRecursive(Node *first, Node *second) {
            if(first == nullptr)
                return second;

            if(second == nullptr)
                return first;

            if(first->data < second->data) {
                first->next = mergeNodesRecursive(first->next, second);
                return first;
            }

            second->next = mergeNodesRecursive(first, second->next);
            return second;
        }

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
                tail = newNode;
                return;
            }

            tail->next = newNode;
            tail = newNode;

            // Node *temp = head;

            // while(temp->next){
            //     temp = temp->next;
            // }

            // temp->next = newNode;
            // newNode->next = nullptr; 
        }

        LinkedList* mergeSortedLinkedList(LinkedList *L1, LinkedList *L2) {
            LinkedList *result = new LinkedList();
            std::vector<int> values;

            Node *temp1 = (L1 != nullptr) ? L1->head : nullptr;
            Node *temp2 = (L2 != nullptr) ? L2->head : nullptr;

            while(temp1) {
                values.push_back(temp1->data);
                temp1 = temp1->next;
            }

            while(temp2) {
                values.push_back(temp2->data);
                temp2 = temp2->next;
            }

            std::sort(values.begin(), values.end());

            for(int value : values) {
                result->pushback(value);
            }

            return result;
        }

        LinkedList* mergeUnSortedLinkedList(LinkedList *L1, LinkedList *L2) {
            if(L1 == nullptr)
                return L2;

            if(L2 == nullptr)
                return L1;

            L1->tail->next = L2->head;
            L1->tail = L2->tail;

            return L1;

        }

        LinkedList* mergeListRecursive(LinkedList *L1, LinkedList *L2) {
            LinkedList *result = new LinkedList();

            Node *first = (L1 != nullptr) ? L1->head : nullptr;
            Node *second = (L2 != nullptr) ? L2->head : nullptr;

            result->head = mergeNodesRecursive(first, second);

            Node *temp = result->head;
            while(temp && temp->next) {
                temp = temp->next;
            }
            result->tail = temp;

            return result;
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
    LinkedList result;

    L1.pushback(20);
    L1.pushback(30);
    L1.pushback(40);
    L1.pushback(50);
    L1.pushback(60);

    L2.pushback(80);
    L2.pushback(90);
    L2.pushback(10);
    L2.pushback(120);
    L2.pushback(13);

    // LinkedList *mergeUnsorted = L1.mergeUnSortedLinkedList(&L1, &L2);
    // mergeUnsorted->printll();

    // LinkedList *mergeSorted = L1.mergeSortedLinkedList(&L1, &L2);
    // mergeSorted->printll();

    LinkedList *mergeRecursive = L1.mergeListRecursive(&L1, &L2);
    mergeRecursive->printll();
    
    return 0;

}