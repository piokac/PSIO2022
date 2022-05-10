#include <fstream>
#include <iostream>
#include <string>
using namespace std;
struct sNode
{
    string word;
    int counter;
    sNode *L;
    sNode *R;
};

void print(sNode *node)
{
    if (node->L != nullptr)
        print(node->L);
    cout << node->word << " - " << node->counter << endl;
    if (node->R != nullptr)
        print(node->R);
}
void add_node(sNode *&node, const string &word)
{
    if (node == nullptr) {
        node = new sNode;
        node->counter = 1;
        node->word = word;
        node->L = nullptr;
        node->R = nullptr;
    } else {
        if (node->word > word) {
            add_node(node->L, word);
        } else {
            if (node->word == word) {
                node->counter++;
            } else
                add_node(node->R, word);
        }
    }
}

int main()
{
    sNode *root = nullptr;
    fstream file("/home/piotr/license.txt", ios::in);
    while (!file.eof()) {
        string word;
        file >> word;
        //        cout << word;

        add_node(root, word);
    }

    print(root);

    return 0;
}
