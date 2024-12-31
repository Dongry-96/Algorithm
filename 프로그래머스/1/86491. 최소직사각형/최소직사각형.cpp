#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
   
    int Max_W = 0;
    int Max_H = 0;
    
    for(int i = 0; i < sizes.size(); ++i)
    {
        // 명함의 길이가 긴 쪽을 0번 인덱스로 정렬
        if(sizes[i][0] < sizes[i][1])
        {
            swap(sizes[i][0], sizes[i][1]);
        }
        // 최대 w 값 갱신
        if(sizes[i][0] > Max_W)
        {
            Max_W = sizes[i][0];
        }
        // 최대 h 값 갱신
        if(sizes[i][1] > Max_H)
        {
            Max_H = sizes[i][1];
        }
    }
    
    return Max_W * Max_H;
}