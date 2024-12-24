#include <string>
#include <vector>
#include <cctype>

using namespace std;

bool ConditionCheck(string s)
{
    int sLen = s.size();
        
    // 숫자로만 구성인지 체크
    for(int i = 0; i < sLen; ++i)
    {
        if(!(isdigit(s[i]))) return false;
    }
           
    // 글자수 체크
    return (sLen == 4 || sLen == 6) ? true : false;
}

bool solution(string s) {
    
    bool answer = ConditionCheck(s);
    
    return answer;
}