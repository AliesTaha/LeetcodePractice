#include <iostream>
#include <stdio.h>
#include <list>
using namespace std;

class ytChannel
{
public:
    string name;
    string titles;
    list<string> pbVids;

    ytChannel(string name, string titles)
    {
        this->name = name;
        this->titles = titles;
        this->pbVids = pbVids;
    }

    void getInfo()
    {
        cout << name << endl;
        cout << titles << endl;
        for (string name : pbVids)
        {
            cout << name << ", ";
        }
    }
};

int main()
{
    ytChannel Ali("Ali", "Lol");
    Ali.pbVids.push_back("I am the one");
    Ali.pbVids.push_back("'I am the two'");
    Ali.pbVids.push_back("'I am the three'");

    Ali.getInfo();
    return 0;
}