#include <string>
#include <vector>
#include <cmath>

using namespace std;

int GetDivisorCnt(const int& num)
{
    int cnt = 0;
    for(int i = 1; i <= sqrt(num); ++i)
    {
        if(i * i == num) cnt += 1;
        else if(num % i == 0) cnt += 2;
    }
    return cnt;
}
int solution(int number, int limit, int power) 
{
    int result = 0;
    for(int i = 1; i <= number; ++i)
    {
        int temp = GetDivisorCnt(i);
        if(temp > limit) temp = power;
        
        result += temp;
    }

    return result;
}