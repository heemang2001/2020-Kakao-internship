#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int FindLenth(int arrNum[4][3],int TargetNum, int StartNum)
{
	int lenth = 0;

	int StartNumi;
	int StartNumj;
	int TargetNumi;
	int TargetNumj;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (StartNum == arrNum[i][j])
			{
				StartNumi = i;
				StartNumj = j;
				break;
			}
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (TargetNum == arrNum[i][j])
			{
				if (i == StartNumi && StartNum != TargetNum)
				{
					return 1;
				}

				else
				{
					if (StartNumj != 1)
					{
						return abs(i - StartNumi) + 1;
					}
					
					else
					{
						return abs(i - StartNumi);
					}
				}
			}
		}
	}
}

string solution(vector<int> numbers, string hand)
{
	string answer = "";
	int Left = -1;
	int Right = -2;
	int arrNum[4][3]
		= { {1, 2, 3},
			{4, 5, 6},
			{7, 8, 9},
			{-1,0,-2} };

	for (int i = 0; i < numbers.size(); i++)
	{
		// ¿ŞÂÊ
		if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
		{
			Left = numbers[i];
			answer += 'L';
		}

		// ¿À¸¥ÂÊ
		else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
		{
			Right = numbers[i];
			answer += 'R';
		}

		// 2 5 8 0
		else
		{			
			int LeftLenth = FindLenth(arrNum, numbers[i], Left);
			int RightLenth = FindLenth(arrNum, numbers[i], Right);

			if (LeftLenth == RightLenth)
			{
				if (hand == "right")
				{
					Right = numbers[i];
					answer += 'R';
				}

				else
				{
					Left = numbers[i];
					answer += 'L';
				}
			}

			else if (LeftLenth < RightLenth)
			{
				Left = numbers[i];
				answer += 'L';
			}

			else
			{
				Right = numbers[i];
				answer += 'R';
			}
		}
	}

	return answer;
}

int main()
{
	string strAnswer = solution({ 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 }, "right"); 
	cout << strAnswer << '\n';

	strAnswer = solution({ 7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2 }, "left");
	cout << strAnswer << '\n';

	strAnswer = solution({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 }, "right");
	cout << strAnswer << '\n';

	return 0;
}