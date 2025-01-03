#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    
    for(int i = 1; i < food.size(); ++i)
    {
        answer.insert(answer.size() >> 1, food[i] - (food[i] & 1), '0' + i);
    }
    answer.insert(answer.size() >> 1, 1, '0');
    
    return answer;
}