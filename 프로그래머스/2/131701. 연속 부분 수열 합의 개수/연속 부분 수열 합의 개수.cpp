#include <string>
#include <vector>
#include <unordered_set>
#include <deque>
#include <numeric> // accumulate

using namespace std;

int solution(vector<int> elements)
{
    // 합산 결과를 키로 저장. 중복 x
    unordered_set<int> us;

    // 원형 순열로 모든 요소가 합산의 시작점이 될 수 있다.
    // 양쪽 끝에서의 삽입/삭제가 빠른 deque 컨테이너 사용.
    deque<int> dq(elements.begin(), elements.end());
    
    // 더할 숫자 개수
    int cnt = 1;
    while (cnt != elements.size())
    {
        // elements의 크기만큼 반복
        // 원형 순열이기에 덧셈 시작 위치를 모든 요소에 적용
        for (int i = 0; i < elements.size(); ++i)
        {
            // dq의 시작부터 cnt 개수만큼 더한 값을 set에 저장
            us.insert(accumulate(dq.begin(), dq.begin() + cnt, 0));

            // 원형 순열이기 때문에 dq.front 시작점 갱신
            int temp = dq.front();
            dq.pop_front();
            dq.push_back(temp);
        }
        // 더할 갯수 증가
        cnt++;
    }
    
    // 모든 요소를 더할 때는 시작점이 중요하지 않기에 한 번만 저장
    us.insert(accumulate(dq.begin(), dq.begin() + cnt, 0));
    
    // set의 크기가 곧 합산의 경우의 수
    int answer = us.size();
    return answer;
}