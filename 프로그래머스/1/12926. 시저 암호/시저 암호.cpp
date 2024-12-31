#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) 
{
    for(int i = 0; i < s.length(); ++i)
    {
        char NowChar = s[i];
        
        // 공백일 경우
        if(NowChar == ' ') continue;
        // 대문자일 경우
        if(isupper(NowChar))
        {
            s[i] = 'A' + (NowChar - 'A' + n) % 26;
        }
        // 소문자일 경우
        if(islower(NowChar))
        {
            s[i] = 'a' + (NowChar - 'a' + n) % 26;
        }
    }
    
    return s;
}