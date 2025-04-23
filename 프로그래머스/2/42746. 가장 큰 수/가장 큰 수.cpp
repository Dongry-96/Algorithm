#include <string>
#include <vector>
#include <queue>

using namespace std;

struct compare
{
    bool operator()(const string& a, const string& b)
    {
        return a + b < b + a;
    }
};

string solution(vector<int> numbers)
{
    priority_queue<string, vector<string>, compare> pq;

    for (int number : numbers)
    {
        pq.push(to_string(number));
    }

    string result;
    while (!pq.empty())
    {
        result += pq.top(); pq.pop();
    }

    if (result[0] == '0') result = "0";

    return result;
}