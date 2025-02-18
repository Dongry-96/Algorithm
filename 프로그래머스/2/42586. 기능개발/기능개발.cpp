#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    // progresses 요소 마다 몇 일이 걸리는지 저장
    queue<int> q;
    for (int i = 0; i < progresses.size(); ++i)
    {
        int tar = 100 - progresses[i];
        if (tar % speeds[i] != 0) q.push(tar / speeds[i] + 1);
        else q.push(tar / speeds[i]);
    }
    
    // 앞의 기능 기준으로 뒤의 배포 일이 작으면 cnt 증가
    // 뒤의 배포일이 크면 현재 cnt를 answer에 저장
    vector<int> answer;
    int cnt = 1;
    int cur = q.front();
    q.pop();
    while (!q.empty())
    {
        int next = q.front();
        if (cur >= next)
        {
            cnt++;
            q.pop();
        }
        else
        {
            answer.push_back(cnt);
            cur = next;
			cnt = 1;    
            q.pop();
        }
    }
	if (q.empty()) answer.push_back(cnt);

    return answer;
}