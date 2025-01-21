#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> survey, vector<int> choices)
{
    string answer = "";
    unordered_map<char, int> score;
    vector<string> char_type = { "RT", "CF","JM","AN" };

    for (int i = 0; i < survey.size(); ++i)
    {
        if (choices[i] < 4) score[survey[i][0]] += (4 - choices[i]);
        if (choices[i] > 4) score[survey[i][1]] += (choices[i] - 4);
    }

    for (string type : char_type)
    {
        if (score[type[0]] > score[type[1]]) answer += type[0];
        else if (score[type[0]] < score[type[1]]) answer += type[1];
        else answer += type[0];
    }

    return answer;
}