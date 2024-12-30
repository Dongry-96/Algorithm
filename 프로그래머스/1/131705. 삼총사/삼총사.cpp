#include <string>
#include <vector>

using namespace std;

int GetCombinationCnt(vector<int> Number, int Sum, int Count, int Idx)
{
    int Result = 0;
    
    if(Count == 3)
    {
        return Sum == 0;
    }
    
    for(int i = Idx; i < Number.size(); ++i)
    {
        Result += GetCombinationCnt(Number, Sum + Number[i], Count + 1, i + 1);
    }
    
    return Result;
}

int solution(vector<int> Number) {
    return GetCombinationCnt(Number, 0, 0, 0);
}