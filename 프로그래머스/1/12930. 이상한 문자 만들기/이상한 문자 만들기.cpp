#include <string>
#include <vector>

using namespace std;

string ChangeString(string Target)
{
    for(int i = 0; i < Target.length(); i++)
    {
        if(i % 2 == 0)
        {
            if(Target[i] >= 'a' && Target[i] <= 'z')
            {
                char ch = Target[i] - 32;
                Target.erase(i, 1);
                Target.insert(i, 1, ch);
            }
        }
        else
        {
            if(Target[i] >= 'A' && Target[i] <= 'Z')
            {
                char ch = Target[i] + 32;
                Target.erase(i, 1);
                Target.insert(i, 1, ch);
            }
        }
    }
    return Target;
}

string solution(string s) 
{
    int t = 0;
    string Answer = "";
    s += " ";
    
    while(s.find(" ", t) != -1)
    {
        string Target = s.substr(t, s.find(" ", t) - t);
        Answer += ChangeString(Target) + " ";
        t = s.find(" ", t) + 1;
    }
    
    Answer.erase(Answer.length() - 1);
    
    return Answer;
}