#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string answer = "";

    for (int i = 1; i < food.size(); ++i)
    {
        string temp = to_string(i);
        for (int j = 0; j < food[i] / 2; ++j)
        {
            answer += temp;
        }
    }

    string temp = answer;
    sort(temp.begin(), temp.end(), greater<>());

    answer += '0' + temp;

    return answer;
}