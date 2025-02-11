#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    answer.reserve(right - left + 1);  // 메모리 미리 할당

    // left에서 right까지 필요한 값만 바로 계산
    for (long long i = left; i <= right; ++i) {
        int row = i / n;
        int col = i % n;
        answer.push_back(max(row, col) + 1);
    }

    return answer;
}