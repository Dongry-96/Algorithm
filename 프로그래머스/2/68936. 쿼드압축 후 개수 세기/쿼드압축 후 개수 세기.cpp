#include <string>
#include <vector>

using namespace std;

pair<int, int> compress(const vector<vector<int>>& arr, int x, int y, int size)
{
    int base = arr[x][y];
    bool allsame = true;

    for (int i = x; i < x + size; ++i)
    {
        for (int j = y; j < y + size; ++j)
        {
            if (arr[i][j] != base)
            {
                allsame = false;
                break;
            }
        }
        if (!allsame) break;
    }

    if (allsame)
    {
        return (base == 0) ? make_pair(1, 0) : make_pair(0, 1);
    }

    int half = size / 2;
    pair<int, int> result1 = compress(arr, x, y, half);
    pair<int, int> result2 = compress(arr, x, y + half, half);
    pair<int, int> result3 = compress(arr, x + half, y, half);
    pair<int, int> result4 = compress(arr, x + half, y + half, half);

    return {
        result1.first + result2.first + result3.first + result4.first,
        result1.second + result2.second + result3.second + result4.second
    };
}

vector<int> solution(vector<vector<int>> arr) 
{
    int size = arr.size();
    pair<int, int> result = compress(arr, 0, 0, size);

    vector<int> answer = { result.first, result.second };
    return answer;
}