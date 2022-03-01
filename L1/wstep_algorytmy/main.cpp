#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //sprawdzanie zakresu
    char znak;
    cout << "Podaj małą literę";
    cin >> znak;
    if (znak >= 'a' && znak <= 'z')
        cout << "znak jest ok";

    // użycie pętli do while
    int a;
    do {
        cout << "Podaj liczbe z zakresu (-10,10)";
        cin >> a;
    } while (!(a > -10 && a < 10));
    cout << "liczba jest ok";
    vector<int> tab(10);
    //użycie pętli for
    for (int i = 0; i < tab.size(); i++) {
        tab[i] = rand();
    }

    //alternatywny zapis za pomoca pętli while
    int i = 0;
    while (i < tab.size()) {
        tab[i] = rand();
        i++;
    }
    //alternatywny zapis za pomocą range based for loop

    for (auto &el : tab) {
        el = rand();
    }

    //użycie pętli while - nie potrzebny jest licznik
    fstream file("/home/piotr/license.txt", ios::in);
    vector<string> words;
    while (!file.eof()) {
        string word;
        file >> word;
        words.emplace_back(word);
        cout << word << endl;
    }

    return 0;
}
