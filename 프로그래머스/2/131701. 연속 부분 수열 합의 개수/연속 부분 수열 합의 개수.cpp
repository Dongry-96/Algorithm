#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) 
{
    unordered_set<int> us;
    int size = elements.size();

    for (int start = 0; start < size; ++start)
    {
        int sum = 0;
        for (int current = start; current < start + size; ++current)
        {
            // 모듈러 연산을 통해 vector size 범위 초과하지 않도록 함.
            // current가 vector size 값이 되면 0번 인덱스가 된다.
            sum += elements[current % size];
            us.insert(sum);
        }
    }

    int answer = us.size();
    return answer;
}