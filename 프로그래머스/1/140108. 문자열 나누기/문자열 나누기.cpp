#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s)
{
    vector<string> result;

    while (!s.empty())
    {
        auto it = s.begin();
        char pivot = *it;
        pair<int, int> cnt({ 0,0 });

        while (it != s.end())
        {
            if (*it == pivot)
            {
                cnt.first++;
            }
            else
            {
                cnt.second++;
            }
            it++;

            if (cnt.first == cnt.second)
            {
                string temp(s.begin(), it);
                result.push_back(temp);
                s.erase(0, temp.size());
                break;
            }
        }

        if (cnt.first != cnt.second)
        {
            result.push_back(s);
            break;
        }
    }

    return result.size();
}