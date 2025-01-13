#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

string solution(string X, string Y) 
{
    string answer = "";
    char target;
    
    sort(X.begin(), X.end(), greater<>());
    
    unordered_map<char, int> X_cnt;
    unordered_map<char, int> Y_cnt;
    
    for(char ch : X)
    {
        X_cnt[ch]++;
    }
    for(char ch : Y)
    {
        Y_cnt[ch]++;
    }
    
    for(int i = 0; i < X.length();)
    {
        target = X[i];
        
        int min_cnt = min(X_cnt[target], Y_cnt[target]);
        answer.append(min_cnt, target);
        
        i += X_cnt[target];
    }
    
    if(answer.empty()) return "-1";
    if(answer[0] =='0') return "0";
    
    return answer;
}