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
		// 숫자면
		if (expression[i] >= '0' && expression[i] <= '9')
		{
			sTemp += expression[i];
		}

		// 연산자면
		else
		{
			vecOperater.push_back(expression[i]);
			vecNum.push_back(stoll(sTemp));
			sTemp = "";
		}
	}

	// 수식이 연산자가 아닌 숫자로 끝났으므로 마지막 숫자 넣어줌
	vecNum.push_back(stoll(sTemp));		
	
	string op = "+-*";
	sort(op.begin(), op.end());
	
	// next_permutation을 사용할 때는 몇 가지 주의할 점이 있습니다. 
	// 
	//1. 오름차순으로 정렬된 값을 가진 컨테이너로만 사용가능합니다.
	//2. default로 operator < 를 사용해 순열을 생성합니다.즉 오름차순으로 순열을 생성합니다.
	//3. 중복이 있는 원소들은 중복을 제외하고 순열을 만들어줍니다.

	do 
	{
		vector<long long> vecTempNum = vecNum;
		vector<char> vecTempOperater = vecOperater;

		for (int i = 0; i < op.size(); i++)
		{
			for (int j = 0; j < vecTempOperater.size(); j++)
			{
				// 연산자 우선순위따라 계산
				if (vecTempOperater[j] == op[i])
				{
					// 해당 연산자로 계산후 결과값 
					vecTempNum[j] = Calculate(vecTempNum[j], vecTempNum[j + 1], op[i]);

					// 연산했으므로 연산자 뒤 숫자는 지워줌
					vecTempNum.erase(vecTempNum.begin() + j + 1);

					// 연산한 연산자 지워줌
					vecTempOperater.erase(vecTempOperater.begin() + j);

					// 연산한 결과인 숫자부터 다시 시작
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