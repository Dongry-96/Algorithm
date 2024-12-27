#include <string>
#include <vector>
#include <cmath>

using namespace std;

string Trit(int n)
{
    string Result  = "";
    while(n != 0)
    {
        Result += to_string(n % 3);
        n /= 3;
    }
    return Result;
}

int solution(int n) {
    
    string R_Trit = Trit(n);
    int answer = 0;
    
    int i = R_Trit.length() - 1;
    for(int j = i; j >= 0; --j)
    {
        answer += (R_Trit[i - j] - '0') * pow(3, j);
    }
    
    return answer;
}