// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

void addNumbers(std::promise<int> promise, std::vector<int> num){
    int sum = 0;
    for(auto itr:num){
        sum +=itr;
    }
    std::this_thread::sleep_for(std::chrono::seconds(4));
    promise.set_value(sum);
    
}

int main() {
    
    std::promise<int> prom;
    std::future<int> fut = prom.get_future();
    std::vector<int> nums {1,2,3,4,5,6};
    std::thread t1(addNumbers, std::move(prom), nums);
    std::cout<<"waiting for result"<<std::endl;
    std::cout<<"result:" <<fut.get();

    
    t1.join();

    return 0;
}