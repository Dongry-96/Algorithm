#include <string>
#include <vector>

using namespace std;

int GCD(int n, int m)
{
    while(m != 0)
    {
        int temp = m;
        m = n % m;
        n = temp;
    }
    return n;
}

int LCM(int n, int m, int gcd)
{
    return (n * m) / gcd;
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    int gcd = GCD(n, m);
    int lcm = LCM(n, m, gcd);
    
    answer.push_back(gcd);
    answer.push_back(lcm);
    
    return answer;
}