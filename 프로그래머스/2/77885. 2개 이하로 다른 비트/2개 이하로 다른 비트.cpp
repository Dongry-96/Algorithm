#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers)
{
    vector<long long> answer;

    for (long long num : numbers)
    {
        if (num % 2 == 0)
        {
            answer.push_back(num + 1);
        }

        else
        {
            long long temp = num;
            long long bit = 1;

            while ((temp & bit) != 0)
            {
                bit <<= 1;
            }

            long long result = num + bit - (bit >> 1);
            answer.push_back(result);
        }
    }

    return answer;
}