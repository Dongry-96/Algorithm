#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> pattern = { 1,2,3,1 };

    int i = 0;
    while (i <= ingredient.size() - 4 && ingredient.size() >= 4)
    {
        if (i + 4 <= ingredient.size() && equal(ingredient.begin() + i, ingredient.begin() + (i + 4), pattern.begin()))
        {
            answer++;
            ingredient.erase(ingredient.begin() + i, ingredient.begin() + (i + 4));
            if (i >= 3)
            {
                i -= 3;
            }
            else
            {
                i = 0;
            }
        }
        else
        {
            i++;
        }
    }

    return answer;
}