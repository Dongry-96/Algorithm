#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(const long long& tar)
{
    if (tar < 2) return false;
    if (tar == 2 || tar == 3) return true;
    if (tar % 2 == 0 || tar % 3 == 0) return false;

    for (int i = 5; i <= sqrt(tar); i += 6)
    {
        if (tar % i == 0 || tar % (i + 2) == 0) return false;
    }
    return true;
}

int solution(int n, int k)
{
    string converted;
    while (n > 0)
    {
        converted = to_string(n % k) + converted;
        n /= k;
    }

    string temp;
    int answer = 0;

    for (char ch : converted)
    {
        if (ch == '0')
        {
            if (!temp.empty() && isPrime(stoll(temp))) answer++;
            temp.clear();
        }
        else
        {
            temp.push_back(ch);
        }
    }

    if (!temp.empty() && isPrime(stoll(temp))) answer++;

    return answer;
}