#include <iostream>
#include "Header.h"
using namespace std;
int main()
{
    cout << (int)'a' << endl;
    cout << (int)'A' << endl;
    cout << (char)('Z' + ('a' - 'A')) << endl;
    return 0;
}
