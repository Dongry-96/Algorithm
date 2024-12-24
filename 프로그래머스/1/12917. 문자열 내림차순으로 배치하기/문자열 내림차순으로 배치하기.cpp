#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int Partition(string& str, int Left, int Right)
{
    char Pivot = str[Right];
    int i = Left - 1;

    for (int j = Left; j <= Right; ++j)
    {
        if (str[j] > Pivot)
        {
            i++;
            swap(str[i], str[j]);
        }
    }
    swap(str[i + 1], str[Right]);

    return i + 1;
}

void QuickSort(string& str, int Left, int Right)
{
    if (Left < Right)
    {
        int Pivot = Partition(str, Left, Right);
        QuickSort(str, Left, Pivot - 1);
        QuickSort(str, Pivot + 1, Right);
    }
}

string solution(string s) {
    
    QuickSort(s, 0, s.size() - 1);
    
    return s;
}