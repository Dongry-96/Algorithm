#include <string>
#include <vector>
#include <set>
using namespace std;

int TotalDaysCnt(const int& Month, const int& Date)
{
    vector<int> DateList = { 31,29,31,30,31,30,31,31,30,31,30,31 };
    int DateCount = 0;
    
    for (int i = 0; i < Month - 1; i++)
    {
        DateCount += DateList[i];
    }
    DateCount += Date - 1;
    
    return DateCount;
}
string solution(int a, int b) 
{
    vector<string> Week = { "FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU" };
    
    int TotalDays = TotalDaysCnt(a, b);

    string answer = Week[TotalDays % 7];
    
    return answer;
}