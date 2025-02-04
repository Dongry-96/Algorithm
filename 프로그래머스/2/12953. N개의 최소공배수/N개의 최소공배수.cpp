#include <vector>

using namespace std;

int GCD(int a, int b)
{
    while(b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int solution(vector<int> arr) 
{
    int a = arr[0];
    
    for(int i = 1; i < arr.size(); ++i)
    {
        int b = arr[i];
        int divisor = GCD(a,b);
        a = a * b / divisor;    
    }
    
    return a;
}