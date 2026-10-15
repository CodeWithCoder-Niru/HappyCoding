/**https://leetcode.com/problems/print-foobar-alternately/ */

#include<bits/stdc++.h>
using namespace std;

std::condition_variable cv;
std::mutex mx;

bool footurn = true;


void foo(int n) {
    for(int i=0; i<n; i++){
        std::unique_lock<std::mutex> lk(mx);
        cv.wait(lk, [&](){
            return footurn;
        });
        std::cout<<"foo";
        footurn = false;
        cv.notify_one();
    }
}

void bar(int n) {
    for(int i=0; i<n; i++){
        std::unique_lock<std::mutex> lk(mx);
        cv.wait(lk, [&](){
            return !footurn;
        });
        std::cout<<"bar";
        footurn = true;
        cv.notify_one();
    }
}

int main() {

    std::vector<std::thread> vec;
    vec.emplace_back(foo, 3);
    vec.emplace_back(bar, 3);

    for(auto &itr:vec)
        itr.join();

    return 0;
}