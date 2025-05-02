#include <iostream>
using namespace std;
int main()
{
AAAA:
    goto CCCC;
BBBB:
    goto AAAA;
CCCC:
    goto DDDD;
DDDD:
    goto BBBB;
    return 0;
}