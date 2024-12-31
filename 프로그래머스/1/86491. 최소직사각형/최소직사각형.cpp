#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
   
    int W = 0;
    int H = 0;
    
    for(int i = 0; i < sizes.size(); ++i)
    {
        W = max(W, max(sizes[i][0], sizes[i][1]));
        H = max(H, min(sizes[i][0], sizes[i][1]));
    }
    
    return W * H;
}