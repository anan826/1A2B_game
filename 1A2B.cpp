#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
int main()
{
	srand(time(NULL));
	int r;
	int arr[4] = {};
	for (int i = 0; i <= 3; i++)
	{
		r = rand() % (10) + 1;
		arr[i] = r;
		//		cout << arr[i];
	}
	//	cout <<"\n";
	int cnt = 0;
	int maxCount = 0;
	while (1)
	{
		int A = 0, B = 0;
		char n;
		int limit = 0;
		int input[4] = {};
		int quit[4] = {};
		int num;
		cout << "Enter 4 number：";
		if (maxCount == 10)
		{
			cout << "\n";
			cout << "Enter 'quit' for give up. . .\n";
		}
		while (cin.get(n))
		{

			if (limit >= 4)
			{
				break;
			}
			if (limit < 4)
			{
				cout << "請重新輸入";
				int input[4] = {};
				continue;
			}
			quit[limit] = n;
			num = n - 48;
			input[limit] = num;
			limit++;
		}
		maxCount++;
		if (maxCount >= 10)
		{
			if (quit[0] == 'q' && quit[1] == 'u' && quit[2] == 'i' && quit[3] == 't')
			{
				cout << "You lose !"
						"the answer is：";
				for (int i = 0; i < 4; i++)
				{
					cout << arr[i];
				}
				cout << ".";
				break;
			}
		}

		int check[4] = {0, 0, 0, 0};
		for (int i = 0; i < 4; i++)
		{
			if (input[i] == arr[i])
			{
				A++;
				check[i] = 1;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			if (check[i] == 0)
			{
				for (int j = 0; j < 4; j++)
				{
					if (input[i] == arr[j] && check[j] == 0)
					{
						B++;
						check[j] = 1;
						break;
					}
				}
			}
		}
		if (input[0] == arr[0] && input[1] == arr[1] && input[2] == arr[2] && input[3] == arr[3])
		{
			cout << "Correct ! !\n";
			cout << "The answer is：";
			for (int i = 0; i < 4; i++)
			{
				cout << arr[i];
			}
			cout << ".";
			break;
		}

		cout << A << "A" << B << "B\n";
	}

	return 0;
}