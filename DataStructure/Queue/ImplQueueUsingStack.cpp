#include<bits/stdc++.h>


class Queue{
    std::stack<int> s1;
    std::stack<int> s2;

    public:
        void push(int data){
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }

            s1.push(data);

            while(!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
        }

        int pop() {
            int ans = s1.top();
            s1.pop();
            return ans;
        }

        int peek() {
            return s1.top();
        }

        int empty() {
            return s1.empty();
        }
 };

 int main() {
    Queue q1;

    q1.push(10);
    q1.push(20);
    q1.push(30);
    q1.push(40);

    while(!q1.empty()) {
        std::cout<< q1.peek() << " ";
        q1.pop();
    }
    return 0;
 }