#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i = 0; i < commands.size(); ++i)
    {
        int StartIdx = commands[i][0] - 1;
        int Count = commands[i][1] - commands[i][0] + 1;
        int ResultIdx = commands[i][2] - 1;
        
        vector<int> Temp(array.begin() + StartIdx, array.begin() + StartIdx + Count);
        sort(Temp.begin(), Temp.end());
        
        answer.push_back(Temp[ResultIdx]);
    }
    
    return answer;
}