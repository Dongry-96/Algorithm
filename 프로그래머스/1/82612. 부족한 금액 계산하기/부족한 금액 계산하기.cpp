using namespace std;

long long GetPrice(int Price, int Count)
{
    long long TotalPrice = 0;
    
    for(int i = 1; i <= Count; ++i)
    {
        TotalPrice += i * Price;
    }
    return TotalPrice;
}

long long solution(int Price, int Money, int Count)
{
    long long Answer = -1;

    // 이용금액 price 계산
    long long TotalPrice = GetPrice(Price, Count);
    
    // price에서 money를 제외한 금액이 0인지 확인
    long long Amount = Money - TotalPrice;
    
    // 남은 돈이 없으면 모자른 금액 반환, 남은 돈이 있으면 0을 반환
    return (Amount < 0) ? Amount * -1 : 0;
}