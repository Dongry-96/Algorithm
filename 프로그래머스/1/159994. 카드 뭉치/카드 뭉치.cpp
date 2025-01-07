#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) 
{
    int one_idx = 0;
    int two_idx = 0;
    int flag = 0;

    int one_maxIdx = cards1.size() - 1;
    int two_maxIdx = cards2.size() - 1;
    for(int i = 0; i < goal.size(); ++i)
    {
        flag = 0;
        
        if(goal[i] == cards1[one_idx])
        {
            if(one_maxIdx > one_idx) one_idx++;
            flag = 1;
        }
        else if(goal[i] == cards2[two_idx])
        {
            if(two_maxIdx > two_idx) two_idx++;
            flag = 1;
        }
        
        if(flag == 0)
        {
            return "No";
        }
    }
    
    return "Yes";
}