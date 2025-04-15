#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct trieNode
{
	unordered_map<char, trieNode*> children;
	bool isEnd = false;
};

bool solution(trieNode* root, const string& num)
{
	trieNode* node = root;

	for (char ch : num)
	{
		if (node->isEnd) return false;

		if (!node->children.count(ch))
		{
			node->children[ch] = new trieNode();
		}

		node = node->children[ch];
	}

	if (!node->children.empty()) return false;

	node->isEnd = true;
	return true;
}

int main()
{
	int t;
	cin >> t;

	vector<string> results;

	for (int i = 0; i < t; ++i)
	{
		int n;
		cin >> n;

		trieNode* root = new trieNode;
		bool consistent = true;

		vector<string> phone_num(n);
		for (int j = 0; j < n; ++j)
		{
			cin >> phone_num[j];
		}

		sort(phone_num.begin(), phone_num.end());

		for (const string& num : phone_num)
		{
			if (!solution(root, num))
			{
				consistent = false;
				break;
			}
		}
		
		results.push_back(consistent ? "YES" : "NO");
	}

	for (const string& result : results)
	{
		cout << result << endl;
	}
}