#include <string>
#include <vector>

using namespace std;

bool ConditionCheck(string s)
{
    int sLen = s.size();
    // 글자수 체크
    if(!(sLen == 4 || sLen == 6)) return false;
    
    // 숫자로만 구성인지 체크
    for(int i = 0; i < sLen; ++i)
    {
        if(!('0' <= s[i] && s[i] <= '9')) return false;
    }
    
    return true;
}

bool solution(string s) {
    
    bool answer = ConditionCheck(s);
    
    return answer;
}