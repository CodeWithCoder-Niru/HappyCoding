/**
 * Factory Design Pattern
 * The Factory Design Pattern is a creational design pattern that provides an interface for creating objects in a superclass,
 * but allows subclasses to alter the type of objects that will be created. 
 * It promotes loose coupling by eliminating the need to bind application-specific classes into the code.
 * The Factory Design Pattern is often used when the exact type of object to be created is not known until runtime.
 */


#include <bits/stdc++.h>

class Vehicle {
    public:
        virtual void drive() = 0; // Pure virtual function

    virtual ~Vehicle() = default; // Virtual destructor

};

class Bike :public Vehicle {
    public:
        void drive() override{
            std::cout << "Driving a bike" << std::endl;
        }
};

class Car : public Vehicle {
    public:
        void drive() override{
            std::cout << "Driving a car" << std::endl;
        }
};

class Plane : public Vehicle {
    public:
        void drive() override{
            std::cout << "Flying a plane" << std::endl;
        }
};

class VehicleFactory {
    public:
        static Vehicle* createVehicle(const std::string& type) {
            if (type == "Bike") {
                return new Bike();
            } else if (type == "Car") {
                return new Car();
            } else if (type == "Plane") {
                return new Plane();
            } else {
                return nullptr;
            }
        }
};

int main() {
    VehicleFactory factory;
    auto ptr = factory.createVehicle("Bike");
    if (ptr) {
        ptr->drive();
        delete ptr; // Clean up memory
    } else {
        std::cout << "Invalid vehicle type" << std::endl;
    }
}