#include <stdio.h>
#include <iostream>
#include <map>
#include <string>

using namespace std;
int main()
{
    map<string, string> dictionary;
    dictionary.insert(pair<string, string>("Apple", "fruit"));
    dictionary.insert(pair<string, string>("Zanana", "vegetable"));
    dictionary.insert(pair<string, string>("Banana", "fruit"));

    dictionary["Banana"] = "veg";

    for (auto pair : dictionary)
    {
        cout << pair.first << "-" << pair.second << endl;
    }
}