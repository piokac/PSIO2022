#include <iostream>

using namespace std;

int main()
{
    char napis[] = "a";
    char znak = 'a';
    int waga = 75, wzrost = 180, a, b, c, d;

    float bmi = waga / ((float) wzrost / 100 * static_cast<float>(wzrost) / 100);
    cout << bmi;
    return 0;
}
