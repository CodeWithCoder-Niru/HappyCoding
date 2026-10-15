/**https://leetcode.com/problems/print-in-order/ */

#include <bits/stdc++.h>
using namespace std;

std::condition_variable cv;
std::mutex mx;

int firstDone = 0;
int secondDone = 0;

void first() {
    std::unique_lock<std::mutex> lk(mx);
    cv.wait(lk, [&](){
        return (firstDone == 0);
    });
    firstDone = 1;
    std::cout<< "first";
    cv.notify_one();
}
void second() {
    std::unique_lock<std::mutex> lk(mx);
    cv.wait(lk, [&](){
        return ((firstDone == 1) && (secondDone == 0));
    });
    secondDone =1;
    std::cout<< "second";
    cv.notify_one();
}
void third() {
    std::unique_lock<std::mutex> lk(mx);
    cv.wait(lk, [&](){
        return ((firstDone == 1) && (secondDone == 1));
    });
    std::cout<< "third";
}

int main() {

    std::vector<std::thread> vec;
    vec.emplace_back(third);
    vec.emplace_back(first);
    vec.emplace_back(second);

    for(auto &itr:vec)
        itr.join();

    return 0;

}