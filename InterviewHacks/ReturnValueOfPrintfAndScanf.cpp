/**
 * What does printf and scanf will return?
 * printf returns the number of character printed 
 * Scanf returns the number of elements readed
 * 
 */

#include <iostream>
#include <stdio.h>

using namespace std;


int main() {

    char buf[100];

    int printOut = printf("%s", "Hello");
    int scanOut = scanf("%s", buf);

    std::cout<< printOut <<std::endl;
    std::cout<< scanOut;

    return 0;

}