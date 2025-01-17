#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index)
{
    for (int i = 0; i < s.length(); ++i)
    {
        char target = s[i];
        int cnt = 0;
        int end_flag = index;
        while (end_flag)
        {
            cnt++;
            target = 'a' + (s[i] - 'a' + cnt) % 26;
            if (skip.find(target) == -1) end_flag--;
        }
        s[i] = 'a' + (s[i] - 'a' + cnt) % 26;

    }
    return s;
}