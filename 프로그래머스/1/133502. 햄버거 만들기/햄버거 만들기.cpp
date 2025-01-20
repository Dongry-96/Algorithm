#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> ingredient) 
{
    int answer = 0;
    stack<int> check_list;
    check_list.push(-1);

    for (int i : ingredient)
    {
        if (check_list.top() == 1 && i == 2) check_list.top() = 12;
        else if (check_list.top() == 12 && i == 3) check_list.top() = 123;
        else if (check_list.top() == 123 && i == 1) answer++, check_list.pop();
        else check_list.push(i);
    }

    return answer;
}