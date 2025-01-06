#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = 0; i < score.size(); ++i)
    {
        // pq의 사이즈가 k 이상
        if(pq.size() >= k)
        {
            // 현재 score가 pq의 최소 값보다 클 때만 명예의 전당에 값 저장
            if(score[i] > pq.top())
            {
                pq.pop();
                pq.push(score[i]);    
            }
        }
        // pq의 사이즈가 k 미만
        else
        {
            pq.push(score[i]);
        }
        
        // 명예의 전당 최하위 점수 저장
        answer.push_back(pq.top());
    }
    
    return answer;
}