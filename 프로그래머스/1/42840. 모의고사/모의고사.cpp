#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int correct_answer(const vector<int>& answers, const vector<int>& p)
{
    int count = 0;
    int p_size = p.size();
    int t = 0;

    for (int i = 0; i < answers.size(); ++i)
    {
        if (answers[i] == p[t]) ++count;

        ++t;
        if (t == p_size) t = 0;
    }

    return count;
}

vector<int> solution(vector<int> answers)
{
    vector<int> p1 = { 1,2,3,4,5 };
    vector<int> p2 = { 2,1,2,3,2,4,2,5 };
    vector<int> p3 = { 3,3,1,1,2,2,4,4,5,5 };
    vector<int> result;
    vector<int> answer;
     
    result.push_back(correct_answer(answers, p1));
    result.push_back(correct_answer(answers, p2));
    result.push_back(correct_answer(answers, p3));

    auto max_it = max_element(result.begin(), result.end());

    for (int i = 0; i < 3; i++)
    {
        if (result[i] == (*max_it))
        {
            answer.push_back(i + 1);
        }
    }

    return answer;
}