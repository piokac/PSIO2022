#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void rectangle(int n, int m)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            if ((i == 0 || i == n - 1) || (j == 0 || j == m - 1))
                cout << "*";
            else
                cout << " ";
        cout << endl;
    }
}
int main()
{
    //    rectangle(4, 5);

    //petla 1
    vector<double> tab = {4, 3, 5, 1, 7};
    int rozmiar = tab.size();
    bool is_changed;
    do {
        is_changed = false;
        rozmiar--;
        for (int i = 0; i < rozmiar; i++) {
            if (tab[i] > tab[i + 1]) {
                double tmp = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = tmp;
                is_changed = true;
            }
        }
    } while (is_changed);

    for (auto &el : tab)
        cout << el << endl;

    return 0;
}
