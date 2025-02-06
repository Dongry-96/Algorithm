#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = 0;

    for (int i = 0; i < s.length(); ++i)
    {
        // s를 회전해서 temp에 저장
        string temp = s.substr(i) + s.substr(0, i);
        // 올바른 괄호 검증하기 위해 stack 선언
        stack<int> st;

        for(char c : temp)
        {
            // 현재 문자 c가 괄호의 시작이거나 스택이 비어있을 경우 푸쉬
            if (c == '[' || c == '{' || c == '(' || st.empty())
            {
                st.push(c);
            }
            else
            {
                // 앞서 스택에 저장된 괄호가 닫는 괄호라면 올바른 괄호가 아니므로 break
                if (st.top() == ']' || st.top() == '}' || st.top() == ')') break;

                // 짝이 맞는 괄호일 경우
                // 닫는 괄호 - 여는 괄호 일때 아스키코드 값 기준으로 2 이하의 수가 나옴
                // 이것으로 올바른 괄호인지 검증
                if ((c - '0') - (st.top() - '0') <= 2) st.pop();

                // 괄호 안에 괄호가 존재할 수 있음으로 일단 푸쉬
                else st.push(c);
            }
        }

        // stack이 비어있다면 모두 올바른 괄호임으로 answer 증가
        if (st.empty()) answer++;
    }

    return answer;
}

int main()
{
    string s = "}]()[{";

    int answer = solution(s);

    return 0;
}