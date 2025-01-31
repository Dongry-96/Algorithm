#include <string>
#include <vector>

using namespace std;

int solution(int n) 
{
    int a = 0; int b = 1; 
    int sum;
    for(int i = 2; i <= n; ++i)
    {
        sum = (a + b) % 1234567;
        a = b;
        b = sum;
    }
    
    return sum;
}