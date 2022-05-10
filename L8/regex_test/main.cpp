#include <iostream>
#include <regex>
#include <sstream>
#include <string>

#include <fstream>
#include <iostream>
#include <map>
#include <regex.h>
#include <sstream>
#include <string>
#include <unordered_map>
using namespace std;
struct ex_rate
{
    string currency;
    int units;
    float rate;
};

int main()
{
    fstream file("/home/piotr/Downloads/kursy.html", ios::in);
    vector<ex_rate> rates;
    unordered_map<string, float> rates_map;
    stringstream str;
    str << file.rdbuf();
    string text = str.str();
    regex pattern(R"(<td class="right">(\d+)\s(\w{3})\D+(\d+,\d+))");
    auto text_begin = sregex_iterator(text.begin(), text.end(), pattern);

    //    cout << distance(text_begin, sregex_iterator());
    for (auto itr = text_begin; itr != sregex_iterator(); itr++) {
        smatch el = *itr;
        cout << "groups #" << el.size() << endl;
        //        for (auto item : el) {
        //            cout << item << endl;
        //        }
        string rate = el[3];
        rate[1] = '.';
        ex_rate r = {el[2], stoi(el[1]), stof(rate)};

        rates_map[el[2]] = stof(rate) / stoi(el[1]);
        rates.emplace_back(r);
    }
    for (auto el : rates_map) {
        //        cout << el.currency << " - " << el.rate / el.units << endl;
        cout << el.first << "-" << el.second << endl;
    }

    cout << "kurs dolara:" << rates_map["USD"] << endl;
    return 0;
}
