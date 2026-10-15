#include <bits/stdc++.h>

class Singleton {
  Singleton() {
      std::cout <<"Constructor called";
  }

  ~Singleton() {
      std::cout <<"Destructor called";
  }
  
  public:
    static Singleton* getInstance() {
        static Singleton instance;
        return &instance;
    }

    Singleton(const Singleton&) = delete;
    Singleton(const Singleton&&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton& operator=(const Singleton&&) = delete;
    
    void show() {
        std::cout<< "Show has been called";
    }

    void read() {
        std::cout<< "Read has been called";
    }
    
};

int main()
{
    Singleton::getInstance()->show();
    Singleton::getInstance()->read();

    return 0;
}


//using callonce
#include <bits/stdc++.h>


class vehicle{
    vehicle(){
        std::cout<< "ctor called" <<std::endl;
    }
    
    inline static std::once_flag initflag;
    inline static std::unique_ptr<vehicle> instance;
    
    public:
        
        vehicle(const vehicle& obj) = delete;
        vehicle& operator = (const vehicle& obj) = delete;
        vehicle(vehicle&& obj) = delete;
        vehicle& operator = (vehicle&& obj) = delete;
        
        static vehicle* getInstance(){
            std::call_once(initflag,[](){
                instance.reset(new vehicle());
            });
            
            return instance.get();
        }
        

};

        // std::once_flag vehicle::initflag;
        // std::unique_ptr<vehicle> vehicle::instance = nullptr;

int main() {
    vehicle::getInstance();
    vehicle::getInstance();
    return 0;
}