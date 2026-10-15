/**
 * Observer Design Pattern
 * The Observer Design Pattern is a software design pattern in which an object, called the subject,
 * maintains a list of its dependents, called observers, and notifies them of any state changes,
 * usually by calling one of their methods. It is mainly used to implement distributed event-handling systems.
 */

#include <bits/stdc++.h>

class Subscriber{
    public:
        virtual void notify(const std::string& message) = 0; // Pure virtual function

        virtual ~Subscriber() = default; // Virtual destructor

};

class MyChannel{
    public:
        std::vector<Subscriber*> subscribers;
    
    public:
        void subscribe(Subscriber *sub) {
            subscribers.push_back(sub);
        }

        void uploadVideo(std::string const &title) {
            std::cout<< "Channel uploaded: " <<title <<std::endl;
            for(auto itr : subscribers) {
                itr->notify(title);
            }
        }
};

class User : public Subscriber {
    public:
        std::string userName;
    public:
        User(const std::string &name) :userName(name){}
    
        void notify(std::string const &videoTitle)override {
            std::cout<< userName << " Got Notified: new Video - " << userName <<" "<< videoTitle <<std::endl;
        }
};

int main() {
    MyChannel ch1;
    User us1("Niranjan");
    User us2("Sahitya");

    ch1.subscribe(&us1);
    ch1.subscribe(&us2);

    ch1.uploadVideo("Masti mai Hai");
}