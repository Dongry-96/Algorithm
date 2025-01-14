#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) 
{
    int answer = n - lost.size();
    set<int> lostList(lost.begin(), lost.end());
    set<int> reserveList(reserve.begin(), reserve.end());

    for(int i : reserveList)
    {
        if(lostList.find(i) != lostList.end())
        {
            lostList.erase(i);
            reserveList.erase(i);
            answer++;
        }
    }
    
    for(int i : reserveList)
    {
        if(lostList.find(i - 1) != lostList.end())
        {
            answer++;
            lostList.erase(i - 1);
        }
        else if(lostList.find(i + 1) != lostList.end())
        {
            answer++;
            lostList.erase(i + 1);
        }
    }
    
    return answer;
}