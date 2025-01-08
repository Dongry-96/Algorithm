#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int Check_PrimeNum(int sum)
{
    for (int i = 2; i <= sqrt(sum); ++i)
    {
        if (sum % i == 0) return 0;
    }
    return 1;
}

void Count_PrimeNum(const vector<int>& nums, int start, int& result, int sum, int count)
{
    if (count == 3)
    {
        result += Check_PrimeNum(sum);
        return;
    }

    for (int i = start; i < nums.size(); ++i)
    {
        Count_PrimeNum(nums, i + 1, result, sum + nums[i], count + 1);  
    }
}

int solution(vector<int> nums) {

    int result = 0;
    int start = 0;

    Count_PrimeNum(nums, start, result, 0, 0);


    return result;
}