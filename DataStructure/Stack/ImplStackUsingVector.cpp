#include<bits/stdc++.h>

    int array[3] = {};
    int n = sizeof(array)/sizeof(int);

// int i =0;
class Stack{
    // std::vector<int> v;
    public:

    void push(int value) {
        static int i =0;
        array[i] = value;
        i++;

        //v.push_back(value);
    }

    void pop() {
        array[n--];

        //v.pop_back();

    }

    int top() {
        return array[n-1];

        //return v[v.size() -1];
    }

    bool empty() {
        return n == 0;

        //return v.empty();
    }

    void printaray() {
        std::cout<< n << " " <<std::endl;
        for(int i=0;i<n;i++){
            std::cout<< array[i] << " ";
        }
    }

};

int main(){
    Stack S;
    S.push(10);
    S.push(20);
    S.push(30);

    // S.printaray();

    while(!S.empty()) {
        std::cout << S.top() << " ";
        S.pop();
    }


    return 0;
}