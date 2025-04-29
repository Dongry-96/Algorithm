#include <string>
#include <vector>

using namespace std;

vector<int> trans_result(const vector<vector<int>>& board)
{
    vector<int> result;
    size_t size = board.size();
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            if (board[y][x] != 0) result.push_back(board[y][x]);
        }
    }

    return result;
}

vector<int> solution(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));

    int dir_y[3] = { 1, 0, -1 };
    int dir_x[3] = { 0, 1, -1 };
    int num = 1, dir = 0, y = 0, x = 0;
    int total_num = n * (n + 1) / 2;


    while (num <= total_num)
    {
        board[y][x] = num++;

        int dy = y + dir_y[dir];
        int dx = x + dir_x[dir];

        if (dy < 0 || dy >= n || dx < 0 || dx >= n || board[dy][dx] != 0)
        {
            dir = (dir + 1) % 3;
        }

        y += dir_y[dir];
        x += dir_x[dir];
    }

    return trans_result(board);
}