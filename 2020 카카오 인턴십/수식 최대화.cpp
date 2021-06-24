#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long Calculate(long long num1, long long num2, char op)
{
	if (op == '+')
	{
		return num1 + num2;
	}

	else if (op == '-')
	{
		return num1 - num2;
	}

	else if (op == '*')
	{
		return num1 * num2;
	}
}

long long solution(string expression)
{
	long long answer = 0;

	vector<long long> vecNum;
	vector<char> vecOperater;
	string sTemp = "";

	for (int i = 0; i < expression.size(); i++)
	{
		// ���ڸ�
		if (expression[i] >= '0' && expression[i] <= '9')
		{
			sTemp += expression[i];
		}

		// �����ڸ�
		else
		{
			vecOperater.push_back(expression[i]);
			vecNum.push_back(stoll(sTemp));
			sTemp = "";
		}
	}

	// ������ �����ڰ� �ƴ� ���ڷ� �������Ƿ� ������ ���� �־���
	vecNum.push_back(stoll(sTemp));		
	
	string op = "+-*";
	sort(op.begin(), op.end());
	
	// next_permutation�� ����� ���� �� ���� ������ ���� �ֽ��ϴ�. 
	// 
	//1. ������������ ���ĵ� ���� ���� �����̳ʷθ� ��밡���մϴ�.
	//2. default�� operator < �� ����� ������ �����մϴ�.�� ������������ ������ �����մϴ�.
	//3. �ߺ��� �ִ� ���ҵ��� �ߺ��� �����ϰ� ������ ������ݴϴ�.

	do 
	{
		vector<long long> vecTempNum = vecNum;
		vector<char> vecTempOperater = vecOperater;

		for (int i = 0; i < op.size(); i++)
		{
			for (int j = 0; j < vecTempOperater.size(); j++)
			{
				// ������ �켱�������� ���
				if (vecTempOperater[j] == op[i])
				{
					// �ش� �����ڷ� ����� ����� 
					vecTempNum[j] = Calculate(vecTempNum[j], vecTempNum[j + 1], op[i]);

					// ���������Ƿ� ������ �� ���ڴ� ������
					vecTempNum.erase(vecTempNum.begin() + j + 1);

					// ������ ������ ������
					vecTempOperater.erase(vecTempOperater.begin() + j);

					// ������ ����� ���ں��� �ٽ� ����
					j--;
				}
			}
		}

		answer = max(answer, abs(vecTempNum[0]));

	} while (next_permutation(op.begin(), op.end()));

	return answer;
}

int main()
{
	cout << solution("100-200*300-500+20") << '\n';	// 60420
	cout << solution("50*6-3*2") << '\n';			// 300

	return 0;
}