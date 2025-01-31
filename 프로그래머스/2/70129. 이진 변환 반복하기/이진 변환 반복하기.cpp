#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> solution(string s)
{
    int zero_cnt = 0;
    int loop_cnt = 0;
    string temp;
    while (s != "1")
    {
        int z_cnt = count(s.begin(), s.end(), '0');
        zero_cnt += z_cnt;

        temp = string(s.size() - z_cnt, '1');
        int temp_size = temp.size();
        
        stack<int> st;
        while (temp_size !=0)
        {
            st.push(temp_size % 2);
            temp_size /= 2;
        }
        
        temp.clear();
        int st_size = st.size();
        for (int i = 0; i < st_size; ++i)
        {
            temp += to_string(st.top());
            st.pop();
        }
        
        s = temp;
        loop_cnt++;
    }

    vector<int> answer({ loop_cnt, zero_cnt });
    return answer;
}