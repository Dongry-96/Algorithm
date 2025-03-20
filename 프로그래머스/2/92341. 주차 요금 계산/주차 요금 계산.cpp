#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <sstream>
#include <iostream>

using namespace std;

int calculate_fees(const vector<int>& fees, int time)
{
    // 기본 요금
    int fee = fees[1];

    if(time > fees[0])
    {
        // 누적 시간에 따른 추가 요금
        time -= fees[0];
        (time % fees[2] == 0) ? fee += (time / fees[2]) * fees[3] : fee += (time / fees[2] + 1) * fees[3];
    }

    return fee;
}

void calculate_time(const vector<string>& records, unordered_map<string, pair<int, string>>& records_map, map<string, int>& accum_time)
{
    // 1. sstream 사용해서 records 파싱
    // 2. 각 차량번호를 key 값, 입/출차 시간과 IN/OUT을 value로 unordered_map<string, pair<int, string>에 저장
    // 3. 차량 번호마다 누적 주차 시간 계산해 map<string, int>에 저장
 
    // 차량 별 누적 시간 계산
    for (const string& record : records)
    {
        string time, car_number, io;

        stringstream ss(record);
        ss >> time >> car_number >> io;

        int hours, minutes;
        char colon;

        stringstream timestream(time);
        timestream >> hours >> colon >> minutes;
        int total_minutes = hours * 60 + minutes;

        
        if (records_map.find(car_number) == records_map.end())
        {
            records_map.insert({ car_number, { total_minutes, io } });
        }
        else
        {
            int prev_time = records_map[car_number].first;

            accum_time[car_number] += total_minutes - prev_time;
            records_map.erase(car_number);
        }
    }

    // 출차 기록 없는 차량, 누적 시간 추가
    if (records_map.size() > 0)
    {
        int max_minutes = 23 * 60 + 59;
        for (const auto& record : records_map)
        {
            accum_time[record.first] += (max_minutes - records_map[record.first].first);
        }
    }
}

vector<int> solution(vector<int> fees, vector<string> records)
{
    // 주차 누적 시간 정리
    unordered_map<string, pair<int, string>> records_map;
    map<string, int> accum_time;
    calculate_time(records, records_map, accum_time);
        
    //누적 시간에 따른 요금 정리
    vector<int> result;
    for (const auto& time : accum_time)
    {
        result.push_back(calculate_fees(fees, time.second));
    }

    return result;
}