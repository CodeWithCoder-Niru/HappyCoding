#include<iostream>
using namespace std;
float area;
void AreaOfTriangle(float b, float h)
{
    area = (b*h)/2;
    cout<<"Area of triangle "<<area<<endl;
}

void AreaOfSquare(float s,float s1)
{
    area = s*s1;
    cout<<"Area of Square "<<area<<endl;
}

void AreaofCircle(float r, float r1)
{
    area = (22/7)*r*r1;
    cout<<"Area of Circle "<<area<<endl;
}

int main()
{
    float b,h;
    cin>>b;
    cin>>h;
    for(int i =0;i<3;i++)
    {
        void (*function_ptr[i])(float, float) = {AreaOfTriangle, AreaOfSquare, AreaofCircle};
    }
}