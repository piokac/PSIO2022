#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main()
{
    map<string, int> bst;
    fstream file("/home/piotr/license.txt", ios::in);
    while (!file.eof()) {
        string word;
        file >> word;
        bst[word]++;
    }

    for (auto &el : bst) {
        cout << el.first << " - " << el.second << endl;
    }

    vector<pair<string, int>> words;
    //    words.reserve(bst.size());

    copy(bst.begin(), bst.end(), back_inserter(words));
    sort(words.begin(), words.end(), [](const pair<string, int> &el1, const pair<string, int> &el2) {
        return el1.second < el2.second;
    });

    for (auto &el : words) {
        cout << el.first << " - " << el.second << endl;
    }
    return 0;
}
