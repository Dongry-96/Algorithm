#include <string>
#include <vector>
#include <unordered_set>
#include <cmath>
#include <algorithm>

using namespace std;

bool isprimenum(const string& str)
{
    int num = stoi(str);

    for (int i = 2; i <= sqrt(num); ++i)
    {
        if (num % i == 0) return false;
    }

    return true;
}

int solution(string numbers)
{
    unordered_set<int> prime_num;
    sort(numbers.begin(), numbers.end());

    do
    {
        for (int len = 1; len <= numbers.length(); ++len)
        {
            string str = numbers.substr(0, len);

            if (stoi(str) < 2) continue;

            if (prime_num.find(stoi(str)) == prime_num.end())
            {
                if (isprimenum(str)) prime_num.insert(stoi(str));
            }
        }
    } while (next_permutation(numbers.begin(), numbers.end()));

    return prime_num.size();
}