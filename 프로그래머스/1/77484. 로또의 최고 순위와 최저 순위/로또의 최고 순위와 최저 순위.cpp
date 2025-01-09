#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

void GetCnt(const vector<int>& lottos, const unordered_set<int>& win_set, int& zero_cnt, int& match_cnt)
{
    for (int num : lottos)
    {
        if (num == 0)
        {
            zero_cnt++;
        }
        else if (win_set.count(num))
        {
            match_cnt++;
        }
    }
}

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
    int zero_cnt = 0;
    int match_cnt = 0;

    unordered_set<int> win_set(win_nums.begin(), win_nums.end());

    GetCnt(lottos, win_set, zero_cnt, match_cnt);

    int top_rate = 7 - (match_cnt + zero_cnt);
    int lowest_rate = 7 - match_cnt;
    if (top_rate > 6) top_rate = 6;
    if (lowest_rate > 6) lowest_rate = 6;

    vector<int> result = { top_rate, lowest_rate };

    return result;
}