#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings)
{
    unordered_map<string, int> rating_str;
    unordered_map<int, string> rating_int;
    for (int i = 0; i < players.size(); ++i)
    {
        rating_str[players[i]] = i;
        rating_int[i] = players[i];
    }

    for (const string& call : callings)
    {
        int current_rank = rating_str[call];
        string prev_player = rating_int[current_rank - 1];

        rating_str[call] = current_rank - 1;
        rating_int[current_rank - 1] = call;

        rating_str[prev_player] = current_rank;
        rating_int[current_rank] = prev_player;
    }

    vector<string> answer;
    for (int i = 0; i < players.size(); ++i)
    {
        answer.push_back(rating_int[i]);
    }

    return answer;
}