#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iostream>

using namespace std;

// 날짜를 총 일수로 변환 메서드
int DateToDays(const string& date) 
{
    int year, month, day;
    char dot1, dot2;
    stringstream ss(date);

    ss >> year >> dot1 >> month >> dot2 >> day;

    return year * 12 * 28 + month * 28 + day;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies)
{
    unordered_map<string, int> term_map;
    
    // 약관 일수로 변경
    for (const string& term : terms)
    {
        stringstream ss(term);
        string type; int month;
        ss >> type >> month;

        term_map[type] = month * 28;
    }

    // 오늘 날짜 총 일수로 저장
    int today_days = DateToDays(today);
    vector<int> answer;

    // 개인정보 파기 여부 계산
    for (int i = 0; i < privacies.size(); ++i)
    {
        int privacy_days = DateToDays(privacies[i]);

        string date, type;
        stringstream ss(privacies[i]);
        ss >> date >> type;

        privacy_days += term_map[type];
        
        if (today_days >= privacy_days) answer.push_back(i + 1);
    }

    return answer;
}