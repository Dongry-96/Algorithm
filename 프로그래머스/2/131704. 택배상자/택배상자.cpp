#include <string>
#include <vector>
#include <stack>

using namespace std;

void check_temp(const vector<int>& order, stack<int>& temp_container, int& idx, int& box_cnt)
{
    while (!temp_container.empty() && order[idx] == temp_container.top())
    {
        temp_container.pop();
        idx++;
        box_cnt++;
    }
}

int solution(vector<int> order)
{
    stack<int> temp_container;
    int idx = 0;
    int box_cnt = 0;

    for (int i = 1; i <= order.size(); ++i)
    {
        // i가 order와 같다면
        if (i == order[idx])
        {
            idx++;
            box_cnt++;
            // 보조 컨테이너에서 order 처리
            check_temp(order, temp_container, idx, box_cnt);
        }
        // i가 order와 다르다면
        else
        {
            // 보조 컨테이너에 i 저장
            temp_container.push(i);
            // 보조 컨테이너에서 order 처리
            check_temp(order, temp_container, idx, box_cnt);
        }
    }

    return box_cnt;
}