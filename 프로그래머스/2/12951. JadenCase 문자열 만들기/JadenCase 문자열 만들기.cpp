#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) 
{
    string answer = "";
    bool capitalize = true;

    for (char ch : s)
    {
        if (ch == ' ')
        {
            answer += ' ';
            capitalize = true;
        }
        else
        {
            if (capitalize)
            {
                if (!isalpha(ch))
                {
                    answer += ch;
                    capitalize = false;
                }
                else
                {
                    answer += toupper(ch);
                    capitalize = false;
                }
            }
            else
            {
                answer += tolower(ch);
            }
        }
    }
    
    return answer;
}