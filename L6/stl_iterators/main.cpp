#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main()
{
    list<int> v = {1, 2, 3, 4, 4, 4, 5, 6};
    generate(v.begin(), v.end(), f);

    //    //    vector<float>::iterator itr = v.begin();

    //    //    for (vector<float>::iterator itr = v.begin(); itr != v.end(); itr++) {
    //    //        *itr = rand() % 100;
    //    //    }
    //    for (auto &el : v) {
    //        el = rand();
    //    }

    //    for (auto itr = v.begin(); itr != v.end();) {
    //        //        cout << *itr << endl;
    //        if (*itr == 4) {
    //            itr = v.erase(itr);
    //            //            itr++;
    //        } else
    //            itr++;
    //        //        cout << *itr;
    //    }
    //    for (auto &el : v) {
    //        cout << el;
    //    }

    vector<pair<float, float>> pv = {{1, 2}, {3, 4}};

    //    pv.push_back(pair<float, float>(1, 2));
    pv.emplace_back(1, 2);

    return 0;
}
