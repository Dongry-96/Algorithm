#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location)
{
	deque<pair<int, int>> dq;
	priority_queue<int> max_heap;
	for (int i = 0; i < priorities.size(); i++)
	{
		dq.push_back({ i, priorities[i] });
		max_heap.push(priorities[i]);
	}
	
	int answer = 0;
	while (!dq.empty())
	{
		auto temp = dq.front();
		dq.pop_front();

		if (temp.second < max_heap.top())
		{
			dq.push_back(temp);
		}
		else
		{
			answer++;
			max_heap.pop();
			
			if (temp.first == location)
			{
				return answer;
			}
		}
	}
	
	return -1;
}