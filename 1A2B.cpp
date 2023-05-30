#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <limits>
using namespace std;
int main()
{
	srand(time(NULL));
	int r;
	int arr[4] = {};
	// Generating Random Number.
	for (int i = 0; i <= 3; i++)
	{
		r = rand() % (10) + 1;
		arr[i] = r;
		cout << arr[i];
	}
	cout << "\n";
	int maxCount = 0;
	while (1)
	{
		int cnt = 0;
		int A = 0, B = 0;
		//	Key in Detect
		char n;
		int num;
		int limit = 0; //	Word's Maximum length
		int input[4] = {};
		int quit[4] = {};
		cout << "Enter 4 number¡G";
		if (maxCount == 10)
		{
			cout << "\n";
			cout << "Enter 'Ctrl + C' to give up. . .\n";
		}
		//		char x[4]={};
		while (cin.get(n))
		{
			if (n == '\n')
			{
				if (limit != 4)
				{
					cout << "----------------\n";
					cout << "|Invalid input |\n";
					cout << "----------------\n";
					cout << "Enter exactly 4 numbers¡G";
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					limit = 0;
					continue;
				}
				break;
			}

			if (limit >= 4)
			{
				cout << "----------------\n";
				cout << "|Invalid input |\n";
				cout << "----------------\n";
				cout << "Enter exactly 4 numbers¡G";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				limit = 0;
				continue;
			}

			if (n >= '0' && n <= '9')
			{
				quit[limit] = n;
				num = n - '0';
				input[limit] = num;
				limit++;
			}
			else
			{
				cout << "----------------\n";
				cout << "|Invalid input |\n";
				cout << "----------------\n";
				cout << "Enter exactly 4 numbers¡G";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				limit = 0;
				continue;
			}
		}
		maxCount++;
		if (maxCount >= 10)
		{
			if (quit[0] == 'q' && quit[1] == 'u' && quit[2] == 'i' && quit[3] == 't')
			{
				cout << "You lose !"
						"the answer is¡G";
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
		int finalcheck = 0;
		for (int i = 0; i < 4; i++)
		{
			if (input[i] == arr[i])
			{
				finalcheck++;
			}
		}
		if (finalcheck == 4)
		{
			cout << "Correct ! !\n";
			cout << "The answer is¡G";
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
