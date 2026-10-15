// Linked List creation with tail pointer


#include<bits/stdc++.h>

struct Node{
    int data;
    Node *next;
    Node(int value): data(value), next(nullptr){}
};


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

    void printLinkedList() {

        Node *temp = head;

        while(temp) {
            std::cout<<temp->data << "->";
            temp = temp->next;
        }
        std::cout<<"nullptr" <<std::endl;
    }
    
    bool Ispalindrome(){

        Node* temp = head;

        std::vector<int> vec;
        while(temp->next){
            vec.push_back(temp->data);
            temp = temp->next;
        }

        int l = 0 ; int r = vec.size() -1;
        for(auto itr:vec){
            std::cout << "value:" << itr <<std::endl; 
        }

        while(l < r){
            if(vec[l] != vec[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    void RemoveDuplicateSorted(Node *temp){

        while(temp->next) {
            if(temp->data == temp->next->data){
                temp->next = temp->next->next;
            } else {
                temp = temp->next;
            }
        }
    }

int main() {
    pushFront(10);
    pushBack(10);
    pushBack(20);
    pushBack(20);
    pushBack(50);



    RemoveDuplicateSorted(head);

    printLinkedList();

    std::cout<< "Is this palindrome: " << Ispalindrome() <<std::endl;
}