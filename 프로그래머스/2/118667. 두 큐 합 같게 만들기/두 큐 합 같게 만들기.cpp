#include <vector>
#include <numeric>  
#include <queue>

using namespace std;
typedef long long ll;

int solution(vector<int> queue1, vector<int> queue2) 
{
    deque<int> q1(queue1.begin(), queue1.end());
    deque<int> q2(queue2.begin(), queue2.end());

    ll q1_sum = accumulate(q1.begin(), q1.end(), 0);
    ll q2_sum = accumulate(q2.begin(), q2.end(), 0);

    ll total_sum = q1_sum + q2_sum;
    ll target_sum = total_sum / 2;
    if (total_sum % 2 != 0) return -1;

    int cnt = 0;
    int max_ops = (q1.size() + q2.size()) * 2;
    while (cnt <= max_ops)
    {
        if (q1_sum == target_sum) return cnt;

        if (q1_sum > target_sum)
        {
            ll value = q1.front(); q1.pop_front();
            q2.push_back(value);

            q1_sum -= value;
            q2_sum += value;
        }
        else
        {
            ll value = q2.front(); q2.pop_front();
            q1.push_back(value);

            q1_sum += value;
            q2_sum -= value;
        }

        cnt++;
    }

    return -1;
}