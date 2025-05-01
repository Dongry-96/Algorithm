#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) 
{
    int left = 0, right = 0;
    int sum = sequence[0];
    int minLen = sequence.size() + 1;
    vector<int> answer;

    while (right < sequence.size()) 
    {
        if (sum < k) 
        {
            right++;
            if (right < sequence.size()) sum += sequence[right];
        }
        else if (sum > k) 
        {
            sum -= sequence[left];
            left++;
        }
        else 
        {
            if (right - left + 1 < minLen) 
            {
                minLen = right - left + 1;
                answer = {left, right};
            }
            sum -= sequence[left];
            left++;
        }
    }

    return answer;
}