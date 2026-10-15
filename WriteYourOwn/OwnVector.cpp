

#include<bits/stdc++.h>


template<typename T>
class MyVector{

    public:
        T* data;
        size_t size;
        size_t capacity;

    public:
        MyVector():data(nullptr), size(0), capacity(0){

        }

        ~MyVector(){
            delete[] data;
        }

        void resize(size_t newCapacity){
            T* newData = new T[newCapacity];

            for(size_t i=0; i<size ;i++){
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity  = newCapacity;
        }

        void push_back(const T* value){

            if(size == capacity){
                size_t newCapacity = (capacity == 0) ? 1 : capacity *2;
                resize(newCapacity);
            }
            data[size++] = value;
        }

        void pop_back(){
            if(size > 0)
                --size;
        }

        size_t size(){
            return size;
        }

        size_t capacity(){
            return capacity;
        }

        bool isEmpty(){
            return size == 0;
        }

        T& operator[](size_t index){
            if(index >= size){
                 throw std::out_of_range("Index out of range");
            }
            return data[index];
        }
};

int main() {
    MyVector<int> vec;

    std::cout << "Pushing values: ";
    for (int i = 1; i <= 5; ++i) {
        vec.push_back(i);
        std::cout << i << " ";
    }

    std::cout << "\nSize: " << vec.size();
    std::cout << "\nCapacity: " << vec.capacity();

    std::cout << "\nElements: ";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";

    vec.pop_back();
    std::cout << "\nAfter pop_back(), size: " << vec.size();
    std::cout << "\nAfter pop_back(), capacity: " << vec.capacity();
    std::cout << std::endl;
    return 0;
}

