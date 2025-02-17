#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    int answer = 1;
    unordered_map<string, int> clothes_cnt;

    for (int i = 0; i < clothes.size(); ++i)
    {
        clothes_cnt[clothes[i][1]]++;
    }

    for (const auto& clothes : clothes_cnt)
    {
        answer *= clothes.second + 1;
    }

    return answer - 1;
}