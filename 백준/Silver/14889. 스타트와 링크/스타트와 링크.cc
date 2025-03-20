#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Init(const int& n, vector<vector<int>>& SIJ)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int t;
            cin >> t;
            SIJ[i].push_back(t);
        }
    }
}

void CalculatePower(const vector<vector<int>>& SIJ, const vector<int>& Team, vector<int>& Partner, int Idx, int Cnt, int& Sum)
{
    if (Cnt == 2)
    {
        Sum += SIJ[Partner[0]][Partner[1]];
        Sum += SIJ[Partner[1]][Partner[0]];
        return;
    }

    for (int i = Idx; i < Team.size(); ++i)
    {
        Partner.push_back(Team[i]);

        CalculatePower(SIJ, Team, Partner, i + 1, Cnt + 1, Sum);

        Partner.pop_back();
    }
}

int GetPowerGap(const vector<vector<int>>& SIJ, const vector<int>& A_Team, const vector<int>& B_Team)
{
    vector<int> Partner;
    int A_Power = 0;
    int B_Power = 0;
    CalculatePower(SIJ, A_Team, Partner, 0, 0, A_Power);
    CalculatePower(SIJ, B_Team, Partner, 0, 0, B_Power);

    return abs(A_Power - B_Power);
}

void Backtrack(const int& n, const vector<vector<int>>& SIJ,
    vector<int>& A_Team, vector<bool>& Used, int& Min, int Idx, int Cnt)
{
    if (Cnt == n / 2)
    {
        // B_Team 추가
        vector<int> B_Team;
        for (int i = 0; i < n; ++i)
        {
            if (!Used[i]) B_Team.push_back(i);
        }

        // 능력치 차이 계산
        int PowerGap = GetPowerGap(SIJ, A_Team, B_Team);

        // 능력치 차이 최소값 갱신
        Min = min(Min, PowerGap);

        return;
    }

    //idx부터 탐색하여 중복 제거
    for (int i = Idx; i < n; ++i)
    {
        if (Used[i]) continue;
        Used[i] = true;
        A_Team.push_back(i);

        Backtrack(n, SIJ, A_Team, Used, Min, i + 1, Cnt + 1);

        Used[i] = false;
        A_Team.pop_back();
    }
}

void Solution(const int& n, const vector<vector<int>>& SIJ)
{
    vector<int> A_Team;
    vector<int> B_Team;
    vector<bool> used(n, false);
    int Min = 21e8;

    Backtrack(n, SIJ, A_Team, used, Min, 0, 0);

    cout << Min;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> SIJ(n);
    Init(n, SIJ);

    Solution(n, SIJ);

    return 0;
}