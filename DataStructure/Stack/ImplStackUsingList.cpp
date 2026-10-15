#include<bits/stdc++.h>


class Stack{
    std::list<int> ll;
    public:

    void push(int value) {
        ll.push_front(value);
    }

    void pop() {
        ll.pop_front();
    }

    int top() {
        return ll.front();
    }

    bool empty() {
        return ll.size() == 0;

        //v.empty();
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