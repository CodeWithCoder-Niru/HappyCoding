//Question: Find the addition of all odd and even numbers within the number 10 using threads

#include<bits/stdc++.h>
#include<thread>
using namespace std;

mutex mx;
condition_variable cv;
bool isEvenTurn = true;

void SumofEven(int &num, int &evenSum) {
    while(num<10) {
        std::unique_lock<mutex> lock{mx};
        cv.wait(lock, [&] { return isEvenTurn; });
        if((num & 1) == 0) {
            evenSum+=num;
        }
        num++;
        isEvenTurn = false;
        cv.notify_all();
    }
}

void SumofOdd(int &num, int &oddSum) {
    while(num<10) {
        std::unique_lock<mutex> lock{mx};
        cv.wait(lock, [&] { return !isEvenTurn; });
        if((num %2) != 0) {
            oddSum+=num;
        }
        num++;
        isEvenTurn = true;
        cv.notify_all();
    }
}
int main() {
    int num = 0;
    int oddSum = 0;
    int evenSum = 0;
    thread t1(SumofEven, std::ref(num), std::ref(evenSum));
    thread t2(SumofOdd, std::ref(num), std::ref(oddSum));
    t1.join();
    t2.join();
    cout<<"Sum of the Even Numbers:"<<evenSum<<std::endl;
    cout<<"Sum of the Odd Numbers:"<<oddSum<<std::endl;
    return 0;
}