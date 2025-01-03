#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "0";
    int count;
    
    for(int i = food.size() - 1; i > 0; --i)
    {
        count = food[i] / 2;
        while(count)
        {
            answer = to_string(i) + answer + to_string(i);
            --count;
        }
    }
    return answer;
}