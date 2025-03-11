#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons)
{
    // 브루트 포스 기법, 순열을 사용해서 모든 경우를 카운팅해보기
    
    sort(dungeons.begin(), dungeons.end());

    int max_cnt = -1;
    int origin_k = k;

    do
    {
        int cnt = 0;
        int k = origin_k;

        for (const auto& row : dungeons)
        {
            if (k < row[0]) continue;

            k -= row[1];
            cnt++;
        }

        if (cnt > max_cnt) max_cnt = cnt;
    } while (next_permutation(dungeons.begin(), dungeons.end()));

    return max_cnt;
}