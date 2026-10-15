/** Function pointer is a pointer that points to a function instead of a data variable. 
 * It allows us to call a function indirectly through the pointer, which can be useful in certain situations, 
 * such as when we want to pass a function as an argument to another function or when we want to implement callback functions.  
 */


#include<bits/stdc++.h>
using namespace std;
    
// Define a function that matches the signature of the function pointer
int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}


int main() {
    // Define a function pointer that points to a function taking two integers and returning an integer
    int (*funcPtr)(int, int);
    std::function<int(int,int)> funcptr2 = sub;



    // Assign the address of the add function to the function pointer
    funcPtr = &add;

    // Call the function through the function pointer
    int result = funcPtr(5, 3);
    cout << "Result: " << result << endl; // Output: Result: 8
    std::cout << "Result: " << funcptr2(5, 3) << std::endl; // Output: Result: 2

    //Array of function pointers
    int (*fptr[2])(int, int) = {add, sub};
    std::array<std::function<int(int,int)>, 2> fptr2 = {add, sub};

    std::cout << "Result: " << fptr[0](5, 3) << std::endl; // Output: Result: 8
    std::cout << "Result: " << fptr[1](5, 3) << std::endl; // Output: Result: 2
    std::cout << "Result: " << fptr2[0](5, 3) << std::endl; // Output: Result: 8
    std::cout << "Result: " << fptr2[1](5, 3) << std::endl; // Output: Result: 2


    return 0;
}