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
        
        // 대소문자 경우에 따라 알파벳 순환 이동(circular shifting)
        int Case = (NowChar >= 'a') ? 'a' : 'A'; 
        s[i] = Case + (NowChar - Case + n) % 26;
    }
    
    return s;
}