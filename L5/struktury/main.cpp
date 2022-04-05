#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main()
{
    //    list<float> tab;
    //    for (int i = 0; i < 100; i++) {
    //        tab.emplace_back(10);
    //        cout << tab.size() << " - " << tab.capacity() << endl;
    //    }
    list<int> tab;

    for (int i = 0; i < 10; i++) {
        tab.emplace_back(i);
    }
    for (auto &el : tab)
        cout << el << endl;
    return 0;
}
