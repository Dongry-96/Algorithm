#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    multiset<int> topList;
    
    for(int i = 0; i < score.size(); ++i)
    {
        // k를 초과하지 않을 때
        if(i < k)
        {
            topList.insert(score[i]);
        }
        // k를 초과할 때
        else 
        {
            // 현재 스코어가 topList의 최소 값보다 크다면
            if(score[i] > *topList.begin())
            {
                topList.erase(topList.begin());
                topList.insert(score[i]);
            }
        }
        
        //현재 topList의 최소 값을 answer에 저장
        answer.push_back(*topList.begin());
    }
    
    return answer;
}