#include <iostream>

using namespace std;

int main()
{
    //    uint64_t n = 30;
    //    uint64_t factorial = 1;
    //    for (uint64_t i = 1; i < n; i++) {
    //        uint64_t factorial_prev = factorial;
    //        factorial *= i;
    //        cout << i << " - " << factorial << " - " << factorial / factorial_prev << endl;
    //    }

    double acc = 0;
    double dt = 0.001;
    for (uint64_t i = 0; i < 1000000; i++) {
        acc += dt;
    }

    cout.precision(16);
    cout << acc;
    return 0;
}
