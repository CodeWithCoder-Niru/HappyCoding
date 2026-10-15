// 

#include <bits/stdc++.h>

class base{
    public:
        base(){
            std::cout<< "base ctor" <<std::endl;
        }
        
        void show1(){
            std::cout<< "base Show" <<std::endl;
        }
        
        virtual ~base(){
            std::cout<< "base dtor" <<std::endl;
        }
};

class derived : protected base{
    public:
        derived(){
            std::cout<< "derived ctor" <<std::endl;
        }
        
        void show(){
            std::cout<< "derived Show" <<std::endl;
        }
        
        ~derived(){
            std::cout<< "derived dtor" <<std::endl;
        }
};

 
int main() {
    derived *b1  =new derived();
    // b1->show();
    (*b1).show();
    return 0;
}