#include <iostream>

using namespace std;

int main()
{
    float f = 0.001 - 10000 - 0.001 + 10000;
    cout.precision(16);
    cout << f;
    return 0;
}
