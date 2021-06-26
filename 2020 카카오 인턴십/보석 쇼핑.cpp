#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>

#define MAX_VALUE 100001

using namespace std;

// �ð��ʰ� ����(ȿ����)
// 
//bool CheckAllUse(vector<string> gems, unordered_map<string, int> mapTemp)
//{
//	for (int i = 0; i < gems.size(); i++)
//	{
//		if (mapTemp[gems[i]] == 0)
//		{
//			return false;
//		}
//	}
//
//	return true;
//}
//
//vector<int> solution(vector<string> gems)
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	vector<int> answer;
//
//	unordered_map<string, int> mapGems;
//
//	for (int i = 0; i < gems.size(); i++)
//	{
//		mapGems.insert(make_pair(gems[i],0));
//	}
//
//	int start = -1;
//	int end = gems.size();
//	vector<pair<int, int>> vecTemp;
//
//	while (1)
//	{
//		start++;
//
//		if ((gems.size()-start) < mapGems.size())
//		{
//			break;
//		}
//
//		unordered_map<string, int> mapTemp = mapGems;
//
//		for (int i = start; i < gems.size(); i++)
//		{
//			mapTemp[gems[i]]++;
//
//			if (CheckAllUse(gems, mapTemp))
//			{
//				end = i;
//				vecTemp.push_back({ start + 1, end + 1 });
//				break;
//			}
//		}
//	}		
//
//	int minValue = MAX_VALUE;
//
//	for (int i = 0; i < vecTemp.size(); i++)
//	{
//		minValue = min(minValue, vecTemp[i].second - vecTemp[i].first);
//	}
//
//	for (int i = 0; i < vecTemp.size(); i++)
//	{
//		if (minValue == vecTemp[i].second - vecTemp[i].first)
//		{
//			answer.push_back(vecTemp[i].first);
//			answer.push_back(vecTemp[i].second);
//			break;
//		}
//	}
//
//	return answer;
//}

// �������� ���
vector<int> solution(vector<string> gems)
{
	vector<int> answer(2);

	unordered_map<string, int> hashGems;
	set<string> setNum(gems.begin(), gems.end());

	int min;
	int start = 0;
	int end = 0;

	for (int i = 0; i < gems.size(); i++)
	{
		hashGems[gems[i]]++;

		if (hashGems.size() == setNum.size())
		{
			break;
		}

		// ������ ��� �����ϴ� �������� end �̵�
		end++;
	}

	min = end - start;	// ������ ���� ª�� ������ ���ؾ� �ϹǷ�
	answer[0] = start + 1;
	answer[1] = end + 1;

	while (1)
	{
		// startŰ�� ������ start�� ������Ŵ
		string strKey = gems[start];
		hashGems[strKey]--;
		start++;

		// startŰ ���� ���� 0�� �ǹ����� ������� �ʾҴٴ°ŹǷ� end ����
		if (hashGems[strKey] == 0)
		{
			end++;

			for (; end < gems.size(); end++)
			{				
				hashGems[gems[end]]++;						

				// ������ Ű�� ������ end���� ���´ٸ� 
				if (strKey == gems[end])
				{
					break;
				}
			}
			
			// end�� ������ �����Ƿ� ����
			if (end == gems.size())
			{
				break;
			}
		}

		if (min > end - start)
		{
			answer[0] = start + 1;
			answer[1] = end + 1;
			min = end - start;
		}
	}

	return answer;
}

int main()
{
	vector<int> vecAnswer = solution({ "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" });	// 3, 7
	//vector<int> vecAnswer = solution({ "AA", "AB", "AC", "AA", "AC" });	// 1, 3
	//vector<int> vecAnswer = solution({ "XYZ", "XYZ", "XYZ" });	// 1, 1
	//vector<int> vecAnswer = solution({ "ZZZ", "YYY", "NNNN", "YYY", "BBB" });	// 1, 5

	for (int i = 0; i < vecAnswer.size(); i++)
	{
		cout << vecAnswer[i] << " ";
	}

	return 0;
}