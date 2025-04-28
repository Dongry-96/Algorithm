#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> scores) 
{
    pair<int, int> wanho = { scores[0][0], scores[0][1] };
    int wanho_sum = wanho.first + wanho.second;

    sort(scores.begin(), scores.end(), [](const vector<int>& a, const vector<int>& b)
        {
            if (a[0] != b[0]) return a[0] > b[0];
            else return a[1] < b[1];
        });

    vector<pair<int, int>> valid;
    int max_peer = 0;

    for (const auto& score : scores)
    {
        int work = score[0], peer = score[1];
        if (peer < max_peer)
        {
            if (wanho.first == work && wanho.second == peer) return -1;

        }
        else
        {
            max_peer = max(max_peer, peer);
            valid.push_back({ work, peer });
        }
    }

    multiset<int, greater<int>> rate;
    for (const auto& v : valid)
    {
        rate.insert(v.first + v.second);
    }

    auto it = rate.find(wanho_sum);

    return distance(rate.begin(), it) + 1;
}