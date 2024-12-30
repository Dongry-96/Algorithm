#include <string>
#include <vector>

using namespace std;

int GetCount(string t, string p)
{
    int Count = 0;
    int T_Length = t.length();
    int P_Length = p.length();
    
    for(int i = 0; i <= T_Length - P_Length; ++i)
    {
        string Target = t.substr(i, P_Length);
        if(Target <= p) 
        {
            Count++;
        }
    }
    return Count;
}

int solution(string t, string p) 
{
    return GetCount(t, p);
}