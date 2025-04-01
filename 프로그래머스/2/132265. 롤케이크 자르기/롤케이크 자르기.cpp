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
    for (int t : topping)
    {
        right[t]++;
    }

    for (int t : topping)
    {
        right[t]--;
        left.insert(t);

        if (right[t] <= 0) right.erase(t);
        if (left.size() == right.size()) answer++;
    }

    return answer;
}