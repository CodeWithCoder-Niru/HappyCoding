// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

class ImplQueue {
    public:
        std::vector<int> vec;
    public:
        void push(int data) {
            vec.push_back(data);
        }
        
        void pop() {
            vec.erase(vec.begin());
        }
        
        int front() {
            return vec.front();
        }
        
        bool empty() {
            return vec.empty();
        }
};

int main() {
    // Write C++ code here
    ImplQueue S;
    S.push(10);
    S.push(20);
    S.push(30);
    S.push(40);
    
    while(!S.empty()) {
        std::cout<< S.front() <<" ";
        S.pop();
    }

    return 0;
}