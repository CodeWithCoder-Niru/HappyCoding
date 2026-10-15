#include<iostream>
using namespace std;

class This
{
    private:
        int a;
    public:
        This(int value) : a(value) {}

        void setvalue(int value)
        {
            this->a = value;
        }

        void print () const{
            cout<<"a : " <<this->a <<endl; // this is const *This
        }

        This &increment()
        {
            this->a +=1; 
            return *this; //returning the object itself
        }
};

int main()
{
    This t1(10);
    t1.print(); //10

    t1.setvalue(20);
    t1.print(); //20

    t1.increment().increment().increment(); //Chaining calls
    t1.print(); //23

    return 0;
}