#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling)
{
    int answer = 0;
    vector<string> words = { "aya", "ye", "woo", "ma" };
    string temp;

    for (string str : babbling)
    {
        temp.clear();
        for (int i = 0; i < 4; i++)
        {
            if (str.empty())
            {
                answer++;
                temp.clear();
                break;
            }

            if (words[i] == temp) continue;

            int find_idx = str.find(words[i]);
            if (find_idx == 0)
            {
                temp = str.substr(find_idx, words[i].length());
                str.erase(find_idx, words[i].length());
                i = -1;
            }
        }
    }
    return answer;
}