#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) 
{
    int n = numbers.size();
    vector<int> answer(n, -1);
    stack<int> st;

    // 뒤에서부터 순회
    for (int i = n - 1; i >= 0; --i)
    {
        // stack에 현재 탐색하는 원소보다 큰 값만 남기고 전부 삭제
        while (!st.empty() && numbers[i] >= st.top())
        {
            st.pop();
        }

        // 탐색하는 현재 원소보다 뒤 원소가 더 크다면 answer에 stack의 값 추가
        if (!st.empty())
        {
            answer[i] = st.top();
        }

        // 뒤에서부터 모든 원소는 stack에 저장
        st.push(numbers[i]);
    }

    return answer;
}