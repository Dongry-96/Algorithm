#include <string>
#include <vector>

using namespace std;

int DFS(vector<int>& numbers, int& target, int idx, int sum)
{
    if (idx == numbers.size())
    {
        return (target == sum) ? 1 : 0;
    }

    return DFS(numbers, target, idx + 1, sum + numbers[idx]) +
        DFS(numbers, target, idx + 1, sum - numbers[idx]);
}

int solution(vector<int> numbers, int target)
{
    return DFS(numbers, target, 0, 0);;
}