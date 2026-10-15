#include<bits/stdc++.h>


class Stack {
    std::queue<int> q1;
    std::queue<int> q2;


    public:
        void push(int data){

            while(!q1.empty()) {
                q2.push(q1.front());
                q1.pop();
            }

            q1.push(data);

            while(!q2.empty()) {
                q1.push(q2.front());
                q2.pop();
            }

            //using single queue
            // q1.push(data);
            // int size = q1.size();
            // for(auto i=0; i<size-1; i++){
            //     q1.push(q1.front());
            //     q1.pop();
            // }
        }

        int pop(){
            int ans = q1.front();
            q1.pop();
            return ans;
        }

        int top() {
            return q1.front();
        }

        int empty() {
            return q1.empty();
        }
};

int main(){
    Stack S1;
    S1.push(10);
    S1.push(20);
    S1.push(30);
    S1.push(40);

    while(!S1.empty()) {
        std::cout<< S1.top();
        S1.pop();
    }

    return 0;
}