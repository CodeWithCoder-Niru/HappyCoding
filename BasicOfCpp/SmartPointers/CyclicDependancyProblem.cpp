#include <bits/stdc++.h>
 
 
class SmartPointer2;
 
class SmartPointer1 {
    public:
        int data;
        std::weak_ptr<SmartPointer2> sptr1;
        SmartPointer1() {
            std::cout << "default ctor called SmartPointer1" <<std::endl;
            data = 20;
        }
        void Show() {
            std::cout << "SmartPointer1 Show has been called" << data<<std::endl;
        }
        ~SmartPointer1() {
            std::cout << "SmartPointer1 dctor called" <<std::endl;
        }
};
 
class SmartPointer2 {
    public:
        int data;
        std::shared_ptr<SmartPointer1> sptr2;
        SmartPointer2() {
            std::cout << "default ctor called SmartPointer2" <<std::endl;
            data = 20;
        }
        void Show() {
            std::cout << "SmartPointer2 Show has been called" << data<<std::endl;
        }
        ~SmartPointer2() {
            std::cout << "SmartPointer2 dctor called" <<std::endl;
        }
};
 
int main()
{
    // SmartPointer Sp;
    std::shared_ptr<SmartPointer1> Sp1 = std::make_shared<SmartPointer1>();
    std::shared_ptr<SmartPointer2> Sp2 = std::make_shared<SmartPointer2>();
 
    Sp1 -> sptr1 = Sp2;
    Sp2 -> sptr2 = Sp1;
 
    std::cout<< "reference count:" <<Sp1.use_count() <<std::endl;
    std::cout<< "reference count:" <<Sp2.use_count() <<std::endl;;
    return 0;
}