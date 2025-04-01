#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping)
{
    int answer = 0;
    unordered_set<int> left;
    unordered_map<int, int> right;
    for (int i = 0; i < topping.size(); ++i)
    {
        right[topping[i]]++;
    }

    for (int i = 0; i < topping.size(); ++i)
    {
        right[topping[i]]--;
        left.insert(topping[i]);

        if (right[topping[i]] <= 0) right.erase(topping[i]);
        if (left.size() == right.size()) answer++;
    }

    return answer;
}