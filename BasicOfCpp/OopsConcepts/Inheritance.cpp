/*
When a base class is privately inherited by the derived class,
public members of the base class becomes the private members of the derived class and therefore,
the public members of the base class can only be accessed by the member functions of the derived class.
They are inaccessible to the objects of the derived class.
o On the other hand, when the base class is publicly inherited by the derived class,
public members of the base class also become the public members of the derived class.
Therefore, the public members of the base class are accessible by the objects of the derived class as well as by the member functions of the derived class.
*/
#include <iostream>
#include <string.h>
using namespace std;

class person
{
    int id;
    char name[100];

    public:
    void set_p(int, char[]);
    void print_p();
};

void person::set_p(int id, char name[])
{
    this->id = id;
    strcpy(this->name, name);
}

void person::print_p()
{
    cout<<id <<endl<<name;
}

class student : private person{
    int fee;
    char course[10];

    public:
    void set_s(int, char[]);
    void print_s();
};

void student::set_s(int fee, char n[10])
{
    set_p(fee,n);
    this->fee = fee;
    strcpy(this->course, n);
}

void student::print_s()
{
    print_p();
    cout<<fee<<endl<<course;
}

int main()
{
    student s1;
    s1.set_s(100, "B.tech");
    s1.print_s();
    return 0;
}

/*
// C++ Implementation to show that a derived class
// doesn’t inherit access to private data members.
// However, it does inherit a full parent object.
class A {
public:
    int x;

protected:
    int y;

private:
    int z;
};

class B : public A {
    // x is public
    // y is protected
    // z is not accessible from B
};

class C : protected A {
    // x is protected
    // y is protected
    // z is not accessible from C
};

class D : private A // 'private' is default for classes
{
    // x is private
    // y is private
    // z is not accessible from D
};
*/

/* hybrid Inheritance*/
/* ---> This program will produce the ambiguities so that use virtual keyword for inherited classes
#include<iostream>
using namespace std;
class Person {
   // Data members of person 
public:
    Person(int x)  { cout << "Person::Person(int ) called" << endl;   }
};
 
class Faculty : public Person {
   // data members of Faculty
public:
    Faculty(int x):Person(x)   {
       cout<<"Faculty::Faculty(int ) called"<< endl;
    }
};
 
class Student : public Person {
   // data members of Student
public:
    Student(int x):Person(x) {
        cout<<"Student::Student(int ) called"<< endl;
    }
};
 
class TA : public Faculty, public Student  {
public:
    TA(int x):Student(x), Faculty(x)   {
        cout<<"TA::TA(int ) called"<< endl;
    }
};
 
int main()  {
    TA ta1(30);
}
*/

/*
// C++ program for Hierarchical Inheritance 
#include<iostream> 
using namespace std; 
  
class A   //superclass A 
{ 
  public: 
  void show_A() { 
    cout<<"class A"<<endl; 
  } 
}; 
class B : public A   //subclass B 
{ 
  public: 
  void show_B() { 
    cout<<"class B"<<endl; 
  } 
}; 
  
class C : public A   //subclass C 
{ 
  public: 
  void show_C() { 
    cout<<"class C"<<endl; 
  } 
}; 
  
int main() { 
  B b;  // b is object of class B 
  cout<<"calling from B: "<<endl; 
  b.show_B(); 
  b.show_A(); 
    
  C c;  // c is object of class C 
  cout<<"calling from C: "<<endl; 
  c.show_C(); 
  c.show_A(); 
  return 0; 
} 
*/

/*
// C++ program to implement
// Multilevel Inheritance
#include <bits/stdc++.h>
using namespace std;
 
// single base class
class A {
public:
    int a;
    void get_A_data()
    {
        cout << "Enter value of a: ";
        cin >> a;
    }
};
 
// derived class from base class
class B : public A {
public:
    int b;
    void get_B_data()
    {
        cout << "Enter value of b: ";
        cin >> b;
    }
};
 
// derived from class derive1
class C : public B {
private:
    int c;
 
public:
    void get_C_data()
    {
        cout << "Enter value of c: ";
        cin >> c;
    }
 
    // function to print sum
    void sum()
    {
        int ans = a + b + c;
        cout << "sum: " << ans;
    }
};
int main()
{
    // object of sub class
    C obj;
 
    obj.get_A_data();
    obj.get_B_data();
    obj.get_C_data();
    obj.sum();
    return 0;
}
*/