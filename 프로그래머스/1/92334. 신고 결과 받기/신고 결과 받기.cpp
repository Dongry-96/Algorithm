#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    unordered_map<string, int> reported_cnt;
    unordered_multimap<string, string> report_mmap;
    unordered_set<string> report_set;

    // 신고내역 중복 방지
    for (const string& history : report)
    {
        report_set.insert(history);
    }

    // set을 순회하며 신고자와 피신고자 정리, 피신고자 누적 횟수 증가
    for (const string& report : report_set)
    {
        stringstream ss(report);
        string reporter, reported_id;
        ss >> reporter >> reported_id;

        // 피신고자를 신고한 사람 리스트 추가
        report_mmap.insert({ reported_id, reporter });
        // 피신고자 누적 횟수 증가
        reported_cnt[reported_id]++;
    }
    
    unordered_map<string, int> result;
    // 누적 신고 횟수가 k 이상이면 신고했던 id에 cnt 증가
    for (const auto& pair : reported_cnt)
    {
        if (pair.second >= k)
        {
            const auto& range = report_mmap.equal_range(pair.first);
            for (auto it = range.first; it != range.second; ++it)
            {
                result[it->second]++;
            }
        }

    }

    vector<int> answer;
    for (string id : id_list)
    {
        answer.push_back(result[id]);
    }
    return answer;
}