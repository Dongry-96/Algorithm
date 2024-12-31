#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string ConvertStirng(const unordered_map<string, string> NumList, const string& s)
{
    string Result;
    string Temp;

    for (char c : s)
    {
        if (isalpha(c))
        {
            Temp += c;
            auto it = NumList.find(Temp);
            if (it != NumList.end())
            {
                Result += (*it).second;
                Temp.clear();
            }
        }
        else
        {
            Result += c;
        }
    }
    return Result;
}

int solution(string s)
{
    unordered_map<string, string> NumList =
    {
        {"zero","0"}, {"one","1"}, {"two","2"}, {"three","3"}, {"four","4"},
        {"five","5"}, {"six","6"}, {"seven","7"}, {"eight","8"}, {"nine","9"}
    };

    string Result = ConvertStirng(NumList, s);

    return stoi(Result);
}