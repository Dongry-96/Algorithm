#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


int solution(int k, int m, vector<int> score)
{
    int result = 0;
    // score 내림차순으로 정렬
    sort(score.begin(), score.end(), greater<>());

    // i는 m씩 증가
    for(int i = 0; i + m <= score.size(); i += m)
    {
        // 내림차순 정렬했기 때문에 m번째 요소가 박스에 들어갈 최소 점수
        int min_score = score[i + m - 1];

        // 최소 점수 * 개수를 저장
        result += min_score * m;
    }


    return result;
}