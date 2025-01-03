#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    
    while(n >= a)
    {
        int maxChange = a * (n / a);
        int changedBottle = b * (n / a);
        
        answer += changedBottle;
        n -= maxChange - changedBottle;
    }
    
    return answer;
}