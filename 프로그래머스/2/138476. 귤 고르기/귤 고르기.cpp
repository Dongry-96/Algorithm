#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine)
{
    unordered_map<int, int> size_cnt;

    for (int size : tangerine)
    {
        size_cnt[size]++;
    }

    vector<pair<int, int>> sorted_cnt(size_cnt.begin(), size_cnt.end());
    sort(sorted_cnt.begin(), sorted_cnt.end(), [](const auto& a, const auto& b)
        {
            return a.second > b.second;
        });


    int answer = 0;
    for (const auto& cnt : sorted_cnt)
    {
        k -= cnt.second;
        answer++;

        if (k <= 0)
        {
            break;
        }
    }

    return answer;
}