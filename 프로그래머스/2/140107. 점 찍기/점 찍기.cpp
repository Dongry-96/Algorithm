#include <string>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

long long solution(int k, int d) 
{
    ll answer = 0;
    ll d2 = 1ll * d * d;

    for (ll x = 0; x <= d; x += k)
    {
        ll maxY = sqrt(d2 - x * x);
        answer += maxY / k + 1;
    }

    return answer;
}