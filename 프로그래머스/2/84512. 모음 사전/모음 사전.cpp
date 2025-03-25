#include <string>
#include <vector>

using namespace std;

void dfs(const string& alpha, const string& word, string temp, int& answer, bool& isfind)
{
    if (temp == word)
    {
        isfind = true;
        return;
    }

    if (temp.size() == 5) return;

    for (int i = 0; i < alpha.size(); ++i)
    {
        temp += alpha[i];
        answer += 1;

        dfs(alpha, word, temp, answer, isfind);

        if (isfind) return;
        temp.pop_back();
    }
}

int solution(string word)
{
    string alpha = "AEIOU";
    string temp;
    int answer = 0;
    bool isfind = false;

    dfs(alpha, word, temp, answer, isfind);

    return answer;
}