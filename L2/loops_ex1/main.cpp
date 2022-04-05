#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

bool is_prime(int value)
{
    for (int i = 2; i < sqrt(value) + 1; i++) {
        if (value % i == 0) {
            //            cout << "liczba ma dzielnik " << i << endl;
            return false;
        }
    }
    return true;
}
float maximum(const vector<float> &array)
{
    float max = array[0];

    //    for (int i = 0; i < array.size(); i++) {
    //        if (array[i] > max)
    //            max = array[i];
    //    }

    for (auto &el : array) {
        if (el > max)
            max = el;
    }
    return max;
}

float mean(const vector<float> &array)
{
    float acc = 0;

    for (auto &el : array) {
        acc += el;
    }
    return acc / array.size();
}
float pi(float prec = 0.00001)
{
    float acc = 0;
    //    for (int i = 1; i < 10000; i++) {
    //        acc += 4 * pow(-1, i - 1) / (2 * i - 1);
    //    }
    float delta;
    int i = 1;
    do {
        delta = 4 * pow(-1, i - 1) / (2 * i - 1);
        acc += delta;
        i++;
    } while (fabs(delta) > prec);
    return acc;
}

int factorial_itr(int n)
{
    int acc = 1;
    for (int i = 1; i <= n; i++) {
        acc *= i;
    }
    return acc;
}
int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}
int main()
{
    //    int value;
    //    cin >> value;
    //    if (is_prime(value)) {
    //        cout << "liczba jest pierwsz" << endl;
    //    } else {
    //        cout << "liczba nie jest pierwsza";
    //    }

    //    vector<float> array(10);
    //    for (auto &el : array)
    //        el = rand() % 100;

    //    cout << "wartosc maksymalna: " << maximum(array);
    //    cout.precision(9);
    //    cout << pi();
    cout << factorial_itr(1000000);

    return 0;
}
