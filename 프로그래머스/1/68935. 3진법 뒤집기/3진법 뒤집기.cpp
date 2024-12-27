#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    
    vector<int> R_Trit;
    
    // vector에 리버스된 3진법 저장
    while(n != 0)
    {
        R_Trit.push_back(n % 3);
        n /= 3;
    }
    
    int k = 1;
    int answer = 0;
    while(!R_Trit.empty())
    {
        answer += k * R_Trit.back();
        R_Trit.pop_back();
        k *= 3;
    }
    
    return answer;
}