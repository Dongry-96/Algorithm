#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void AddAll(set<int>& SetNum, const vector<int>& numbers, vector<int>& used, int sum, int count)
{
    if (count == 2)
    {
        SetNum.insert(sum);
        return;
    }
    
    for (int i = 0; i < numbers.size(); ++i)
    {
        if (used[i] == 1) continue;

        used[i] = 1;
        sum += numbers[i];

        AddAll(SetNum, numbers, used, sum, count + 1);

        used[i] = 0;
        sum -= numbers[i];
    }
}

vector<int> solution(vector<int> numbers) 
{
    // 중복된 값을 쳐내고 정렬하기 위해 set 사용
    set<int> SetNum;
    // 인덱스 중복 방지 하기 위해 used 배열 사용
    vector<int> used(numbers.size(), 0);

    // 재귀호출을 통해 모든 경우의 합 계산
    AddAll(SetNum, numbers, used, 0, 0);

    //vector만 리턴 가능해서, 값 set의 값을 vector로 복사
    vector<int> answer(SetNum.begin(), SetNum.end());

    return answer;
}