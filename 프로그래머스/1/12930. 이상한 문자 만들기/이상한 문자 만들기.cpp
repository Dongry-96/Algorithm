#include <string>
#include <vector>

using namespace std;

string solution(string s) 
{
    string Answer = "";
    int t = 1;
    
    for(int i = 0; i < s.length(); i++, t++)
    {
        if(s[i] ==' ')
        {
            Answer += " ";
            t = 0;
        }
        else
        {
            //비트 And 연산자를 활용해서 홀수번째인지, 짝수번째인지 확인
            //toupper함수와 tolower함수를 사용해서 대소문자 변환
            t & 1 ? Answer += toupper(s[i]) : Answer += tolower(s[i]);
        }
    }
    
    return Answer;
}