#include<bits/stdc++.h> 


class CirclerQueue {
    public:
        int *arr;
        int frnt;
        int rear;
        int Currentsize;
        int Capasity;

    public:
        CirclerQueue(int size) {
            frnt = 0;
            rear = -1;
            Currentsize = 0;
            Capasity = size;
            arr = new int[Capasity];
        }

        void push(int value) {
            if(Currentsize == Capasity) {
                std::cout<< "CQ is Full";
                return;
            }
            rear = (rear + 1) % Capasity;
            arr[rear] = value;
            Currentsize++;
        }

        void pop() {
            if(empty()) {
                std::cout<< "CQ is Empty";
                return;
            }

            frnt = (frnt + 1) % Capasity;
            Currentsize--;
        }

        int front() {
            if(empty()) {
                std::cout<< "CQ is Empty";
                return -1;
            }
            return arr[frnt];
        }

        int empty() {
            return Currentsize == 0;
        }
};

int main() {
    CirclerQueue Cq(4);
    Cq.push(20);
    Cq.push(10);

    Cq.push(30);
    Cq.push(40);

    while(!Cq.empty()) {
        std::cout<<Cq.front();
        Cq.pop();
    }
    return 0;
}