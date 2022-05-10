#include <fstream>
#include <iostream>
#include <regex.h>
#include <sstream>
#include <string>

//#include <iterator>
//
//

using namespace std;

int main()
{
    fstream file("/home/piotr/Downloads/kursy.html", ios::in);

    stringstream str;
    str << file.rdbuf();
    string text = str.str();
    regex_t pattern(R"(<td class="right">(\d+)\s(\w{3})\D+(\d+,\d+))");
    //    cout << text;
    //    system("read sth");
    return 0;
}
