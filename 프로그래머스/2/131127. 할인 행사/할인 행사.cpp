#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) 
{
    // want와 number를 map으로 합쳐서 정리 buylist
    unordered_map<string, int> buylist;
    for (int i = 0; i < want.size(); ++i)
    {
        buylist[want[i]] = number[i];
    }


    // discount목록 map에 첫 째날 부터 10일치 넣기 discountlist
    unordered_map<string, int> discountlist;
    for (int i = 0; i < 10; ++i)
    {
        discountlist[discount[i]]++;
    }

    // buylist를 순회하며 discountlist의 값보다 큰 값이 하나라도 나오면 구매불가, 모두 작거나 같으면 구매가능 -> anwer 증가
    int answer = 0;
    for (int i = 0; i <= discount.size() - 10; ++i)
    {
        bool canbuy = true;

        for (const auto& item : buylist)
        {
            if (item.second > discountlist[item.first])
            {
                canbuy = false;
                break;
            }
        }

        if (canbuy) answer++;

        if (i + 10 < discount.size())
        {
            discountlist[discount[i]]--;
            discountlist[discount[i + 10]]++;
        }
    }

    return answer;
}