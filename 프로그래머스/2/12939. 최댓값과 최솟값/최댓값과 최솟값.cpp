#include <string>
#include <set>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string s)
{
    stringstream ss(s);
    int blank_cnt = count(s.begin(), s.end(), ' ');
    set<int> list;

    for (int i = 0; i <= blank_cnt; ++i)
    {
        string str;
        ss >> str;
        list.insert(stoi(str));
    }

    string answer = to_string(*(list.begin())) + " " + to_string(*(--list.end()));
    return answer;
}