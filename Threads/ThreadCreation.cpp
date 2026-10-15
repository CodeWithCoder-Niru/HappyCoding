//Creation of threads n 5 ways

#include<bits/stdc++.h>
#include<thread>

/*1. Using Function Pointer*/
std::mutex mMute;

/*
void fun(int x) {
    while(x) {
        std::lock_guard<std::mutex> lock{mMute};
        x--;
        std::cout<<"x is:"<<x<<std::endl;
    }
}

int main() {
    int x = 5;
    std::thread t1(fun, x);
    std::thread t2(fun, 6);
    std::thread t3(fun, 6);
    t1.join();
    t2.join();
    t3.join();
    return 0;
}*/

//2. Using Lambda Function
/*auto fun = [](int x) {
    while(x) {
        std::lock_guard<std::mutex> lock{mMute};
        x--;
        std::cout<<"x is:"<<x<<std::endl;
    }
};
int main() {
    int x = 5;
    std::thread t1(fun, x);
    std::thread t2(fun, 6);
    std::thread t3([](int x) {
        while(x) {
            std::lock_guard<std::mutex> lock{mMute};
            x--;
            std::cout<<"x is:"<<x<<std::endl;
        }
    }, 10);
    t1.join();
    t2.join();
    t3.join();
    return 0;
}*/

//3. Using Funtor
/*
class functor {
    public:
        void operator ()(int x) {
            while(x) {
                std::lock_guard<std::mutex> lock{mMute};
                x--;
                std::cout<<"x is:"<<x<<std::endl;
            }
        }
};

int main() {
    int x = 5;
    std::thread t1((functor()), x);
    std::thread t2((functor()), 6);
    std::thread t3([](int x) {
        while(x) {
            std::lock_guard<std::mutex> lock{mMute};
            x--;
            std::cout<<"x is:"<<x<<std::endl;
        }
    }, 10);
    t1.join();
    t2.join();
    t3.join();
    return 0;
}*/

//4. Using Non Static data member function
/*
class NonStaticFun {
    public:
        void fun (int x){
            while(x) {
                std::lock_guard<std::mutex> lock{mMute};
                x--;
                std::cout<<"x is:"<<x<<std::endl;
            }
        }
};
int main() {
    int x = 5;
    NonStaticFun obj;
    std::thread t1(&NonStaticFun::fun, std::ref(obj), x);
    std::thread t2(&NonStaticFun::fun, std::ref(obj), x);
    std::thread t3([](int x) {
        while(x) {
            std::lock_guard<std::mutex> lock{mMute};
            x--;
            std::cout<<"x is:"<<x<<std::endl;
        }
    }, 10);
    t1.join();
    t2.join();
    t3.join();
    return 0;
}*/

//5 Using Static Member Function
//No need to create obj for calling the static function
class StaticFun {
    public:
        static void fun (int x){
            while(x) {
                std::lock_guard<std::mutex> lock{mMute};
                x--;
                std::cout<<"x is:"<<x<<std::endl;
            }
        }
};

int main() {
    int x = 5;
    std::thread t1(&StaticFun::fun, x);
    std::thread t2(&StaticFun::fun, x);
    std::thread t3([](int x) {
        while(x) {
            std::lock_guard<std::mutex> lock{mMute};
            x--;
            std::cout<<"x is:"<<x<<std::endl;
        }
    }, 10);
    t1.join();
    t2.join();
    t3.join();
    return 0;
}