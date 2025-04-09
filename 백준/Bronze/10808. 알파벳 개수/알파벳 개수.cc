#include <vector>
#include <string>
#include <iostream>

using namespace std;

void solution(const string& input)
{
	vector<int> result(26, 0);

	for (char ch : input)
	{
		result[ch - 'a']++;
	}

	for (int cnt : result)
	{
		cout << cnt << " ";
	}
}

int main()
{
	string input;
	cin >> input;
   
	solution(input);

	return 0;
}