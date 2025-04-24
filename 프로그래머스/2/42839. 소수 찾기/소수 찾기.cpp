#include <string>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

bool isprimenum(const string& str)
{
    int num = stoi(str);

    if (num < 2) return false;

    for (int i = 2; i <= sqrt(num); ++i)
    {
        if (num % i == 0) return false;
    }

    return true;
}

void DFS(const string& numbers, string str, unordered_set<int>& prime_num, vector<bool>& used)
{
    if (!str.empty())
    {
        if (isprimenum(str)) prime_num.insert(stoi(str));
    }

    for (int i = 0; i < numbers.length(); ++i)
    {
        if (used[i]) continue;

        used[i] = true;
        DFS(numbers, str + numbers[i], prime_num, used);
        used[i] = false;
    }
}

int solution(string numbers)
{
    unordered_set<int> prime_num;
    vector<bool> used(numbers.length(), false);

    DFS(numbers, "", prime_num, used);

    return prime_num.size();
}