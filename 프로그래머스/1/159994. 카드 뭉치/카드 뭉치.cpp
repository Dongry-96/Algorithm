#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) 
{
    int one_idx = 0;
    int two_idx = 0;

    for(int i = 0; i < goal.size(); ++i)
    {
        if(goal[i] == cards1[one_idx])
        {
            one_idx++;
        }
        else if(goal[i] == cards2[two_idx])
        {
            two_idx++;
        }
        else
        {
            return "No";
        }
    }
    
    return "Yes";
}