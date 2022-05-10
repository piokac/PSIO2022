#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
bool below_zero(const float &el)
{
    return el < 0;
}
class Threshold
{
    float th_;

public:
    Threshold(float th) : th_(th) {}
    bool operator()(const float &el) { return el < th_; }
};

int main()
{
    vector<float> temp = {10, 15, 20, 10, 5, 0, -3, -2, 10};
    cout << "liczba dni z temp -3 stopnie: " << count(temp.begin(), temp.end(), -3) << endl;
    cout << "liczba dni z temp <0 stopnie: " << count_if(temp.begin(), temp.end(), below_zero)
         << endl;

    float th = 5;

    cout << "LAMBDA: liczba dni z temp <0 stopnie: "
         << count_if(temp.begin(), temp.end(), [th](const float &el) { return el < th; }) << endl;

    Threshold thr(10);
    thr(4);
    cout << "FUNCTOR: liczba dni z temp <th stopnie: " << count_if(temp.begin(), temp.end(), thr)
         << endl;
    return 0;
}
