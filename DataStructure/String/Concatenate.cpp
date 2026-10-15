// C++ Program for string
// concatenation using append
#include <iostream>
using namespace std;
 
// Driver code
int main()
{
    string init("this is init");
    string add(" added now");
 
    // Appending the string.
    init.append(add);
 
    cout << init << endl;
    return 0;
}

/*
// concatenation using '+' operator
#include <iostream>
using namespace std;
 
// Driver code
int main()
{
    string init("this is init");
    string add(" added now");
 
    // Appending the string.
    init = init + add;
 
    cout << init << endl;
    return 0;
}
*/

/*
// concatenation using strcat
#include <iostream>
#include <string.h>
using namespace std;
 
// Driver code
int main()
{
    char init[] = "this is init";
    char add[] = " added now";
 
    // Concatenating the string.
    strcat(init, add);
 
    cout << init << endl;
 
    return 0;
}
*/

/*
// concatenation using for loop
#include <iostream>
using namespace std;
 
// Driver code
int main()
{
    string init("this is init");
    string add(" added now");
 
    string output;
 
    // Adding element inside output
    // from  init
    for (int i = 0; init[i] != '\0'; i++) 
    {
        output += init[i];
    }
 
    // Adding element inside output
    // fromt add
    for (int i = 0; add[i] != '\0'; i++) 
    {
        output += add[i];
    }
 
    cout << output << endl;
    return 0;
}
*/