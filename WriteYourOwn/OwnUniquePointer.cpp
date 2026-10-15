

#include<bits/stdc++.h>

template<typename T>
class UniquePointer {

    public:
        T *ptr;

    public:
        UniquePointer(T *p = nullptr): ptr(p){}

        ~UniquePointer(){
            delete ptr;
        }

        UniquePointer(const UniquePointer&) = delete;

        UniquePointer& operator=(const UniquePointer&) = delete;

        UniquePointer(UniquePointer &&other){
            ptr = other.ptr;
            other.ptr = nullptr;
        }

        UniquePointer& operator=(UniquePointer &&other){
            if(this != &other){
                delete ptr;
                ptr = other.ptr;
                other.ptr = nullptr;
            }
            return *this;
        }

        T* operator->(){
            return ptr;
        }

        T& operator*(){
            return *ptr;
        }

        operator bool() const {
            return ptr != nullptr;
        }
};

class Demo{
    public:
    Demo() {
        std::cout<< "Demo ctor called" <<std::endl;
    }

    ~Demo(){
        std::cout<< "Demo dctor called" <<std::endl;
    }

    void hello(){
        std::cout<< "Hello from Demo class!" <<std::endl;
    }
};

int main() {

    UniquePointer<Demo> up1 = new Demo();
    UniquePointer<Demo> up2 = std::move(up1);

    if(!up1){
        std::cout<< "up1 is empty" <<std::endl;
    }

    up2->hello();
    (*up2).hello();

    UniquePointer<Demo> up3 = new Demo();
    UniquePointer<Demo> up4 = new Demo();

    up4 = std::move(up3);

    if(!up3){
        std::cout<< "up3 is empty" <<std::endl;
    }

    return 0;
}