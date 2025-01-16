#include <string>
#include <vector>
#include <climits>

using namespace std;

int GetFindTarget(const vector<string>& keymap, const char& ch)
{
    int min_idx = INT_MAX;
    int target_idx;

    for (int i = 0; i < keymap.size(); ++i)
    {
        int find_idx = keymap[i].find(ch);
        if (find_idx != -1 && find_idx < min_idx)
        {
            min_idx = find_idx;
            target_idx = i;
        }
    }

	return min_idx == INT_MAX ? -1 : target_idx;
}

vector<int> solution(vector<string> keymap, vector<string> targets)
{
    vector<int> result;
    int cnt = 0;

    for (string target : targets)
    {
        // keymap을 순회하며 find함수로 Target의 요소를 찾아, 최소 인덱스 값을 구함
        // Target요소가 keymap[MinIdx]의 몇 번 인덱스에 있는지 탐색
        // Cnt 값 증가
        for (char ch : target)
        {
            int min_idx = GetFindTarget(keymap, ch);
            if (min_idx == -1)
            {
				result.push_back(-1);
                cnt = 0;
                break;
            }

            int target_idx = keymap[min_idx].find(ch);
            cnt += target_idx + 1;
        }

        if (cnt > 0) result.push_back(cnt);
		cnt = 0;
    }

    return result;
}