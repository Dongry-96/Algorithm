#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    vector<string> ResultList;
    int Count1 = 0; int Count2 = 0;

    int Idx = 0;
	int TargetIdx = 0;
    while (Idx != s.size())
    {
        char Target = s[TargetIdx];

        if (Count1 == Count2 && Count1 != 0)
        {
            ResultList.push_back(s.substr(TargetIdx, Count1 + Count2));
            Count1 = 0;
            Count2 = 0;
            TargetIdx = Idx;
			continue;
        }

        if (Target == s[Idx])
        {
            Count1++;
        }
        else
        {
            Count2++;
        }

        Idx++;
        if (Idx == s.size())
        {
            ResultList.push_back(s.substr(TargetIdx, Count1 + Count2));
        }
    }

    return ResultList.size();
}