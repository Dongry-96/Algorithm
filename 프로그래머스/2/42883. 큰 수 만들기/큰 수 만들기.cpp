#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) 
{
    string answer = number;
    auto it = answer.begin();

    while (k > 0)
    {
        if (it + 1 == answer.end() || *it < *(it + 1))
        {
            answer.erase(it);
            it = answer.begin();

            k--;
            continue;
        }

        it++;
    }

    return answer;
}