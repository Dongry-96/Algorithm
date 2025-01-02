#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    unordered_map<char, int> used;
    
    for(int i = 0; i < s.length(); ++i)
    {
        // 문자가 처음 등장 했다면
        if(used.find(s[i]) == used.end())
        {
            // 해당 문자 key에 현재 인덱스를 value로
            used[s[i]] = i;
            // 배열에 -1 추가
            answer.push_back(-1);
        }
        // 앞에 문자가 나왔었다면
        else
        {
            // 해당 문자의 value값(인덱스)에서 현재 인덱스를 뺀 값을 배열에 추가
            answer.push_back(i - used.find(s[i])->second);
            // 현재 인덱스로 value값 갱신
            used[s[i]] = i;
        }
    }
    return answer;
}