#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void check_apple(unordered_map<int, int>& List, int k, const vector<int>& score)
{
    for (int i = 1; i <= k; ++i)
    {
        int k_cnt = count(score.begin(), score.end(), i);

        List[i] = k_cnt;
    }
}

int solution(int k, int m, vector<int> score)
{
    unordered_map<int, int> apple_cnt;
    int result = 0;

    // score 점수별로 사과가 몇 개 있는지 정리
    check_apple(apple_cnt, k, score);

    // k점수부터 1점수까지 m개씩 포장해서 점수 계산
    for (int i = k; i >= 1; --i)
    {
        // 만약 개수가 m보다 작다면 밑에 점수 개수에 저장
        if (apple_cnt[i] < m)
        {
            apple_cnt[i - 1] += apple_cnt[i];
            continue;
        }

        // m으로 나눈 몫 * 점수를 result에 더해 저장
        result += (apple_cnt[i] / m) * i * m;

        // 나머지를 밑에 점수 개수에 저장
        apple_cnt[i - 1] += apple_cnt[i] % m;
    }


    return result;
}