
#include <bits/stdc++.h>

template<typename T>
class SharedPtr {

    public:
        T* data;
        int *refCount;

    public:
        SharedPtr(T* pt = nullptr): data(pt), refCount(new int(1)){}

        ~SharedPtr(){
            release();
        }

        SharedPtr(const SharedPtr &other){
            data = new T(*other.data);
            refCount = other.refCount;
            ++(*refCount);
        }

        SharedPtr& operator = (const SharedPtr &other){
            if(this != &other){
                release(); // old ref count for ptr
                delete data;
                data = new T(*other.data);
                refCount = other.refCount;
                ++(*refCount);
            }
            return *this;
        }

        SharedPtr(SharedPtr &&other){
            data = other.data;
            refCount = other.refCount;
            other.data = nullptr;
            other.refCount = nullptr;
        }

        SharedPtr& operator=(SharedPtr &&other){
            if(this != &other){
                release();
                delete data;
                data = other.data;
                refCount = other.refCount;
                other.data = nullptr;
                other.refCount = nullptr;
            }
            return *this;
        }

        int use_cout(){
            return (refCount) ? *refCount : 0;
        }

        void release(){
            if(refCount){
                --(*refCount);
                if(*refCount == 0){
                    delete data;
                    delete refCount;
                }
            }
        }

        T* operator->(){
            return data;
        }
        T& operator*(){
            return *data;
        }

        operator bool() const{
            return data != nullptr;
        }
};

class Demo {
    public:
        Demo(){
            std::cout<< "Demo ctor called" <<std::endl;
        }
        ~Demo(){
            std::cout<< "Demo dtor called" <<std::endl;
        }

        void hello() {
            std::cout<< "Hi, Hello" <<std::endl;
        }
};

int main(){

    SharedPtr<Demo> Sp1 = new Demo();
    SharedPtr<Demo> Sp2 = Sp1;

    SharedPtr<Demo> Sp3 = Sp1;
    Sp3 = Sp1;
    std::cout<< Sp3.use_cout() <<std::endl;

    SharedPtr<Demo> Sp4 = std::move(Sp3);
    std::cout<< Sp4.use_cout() <<std::endl;

    return 0;
}
