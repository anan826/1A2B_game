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
    for (int i = 0; i < 4; i++)
    {
        r = rand() % (10);
        arr[i] = r;
        cout << arr[i];
    }
    cout << "\n";
    int maxCount = 0;
    while (1)
    {
        int cnt = 0;
        int A = 0, B = 0;
        // Key in Detect
        char n;
        int num;
        int limit = 0; // Word's Maximum length
        int input[4] = {};
        int quit[4] = {};
        cout << "Enter 4 numbers: ";
        if (maxCount == 10)
        {
            cout << "\n";
            cout << "Enter 'Ctrl + C' to give up. . .\n";
        }
        while (cin.get(n))
        {
            if (n == '\n')
            {
                // If the input is a newline character, check if the input numbers are correct
                if (limit != 4)
                {
                    //Invalid input numbers, output error message and ask for re-entering
                    cout << "----------------\n";
                    cout << "|Invalid input |\n";
                    cout << "----------------\n";
                    cout << "Enter exactly 4 numbers¡G";
    
                    // Clear the invalid characters in the input buffer
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
                    // Reset the limit and continue the loop
                    limit = 0;
                    continue;
                }
                break;
            }
    
            if (limit >= 4)
            {
                 // Input numbers exceed 4, output error message and ask for re-entering
                cout << "----------------\n";
                cout << "|Invalid input |\n";
                cout << "----------------\n";
                cout << "Enter exactly 4 numbers¡G";
    
                // Clear the invalid characters in the input buffer
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
                // Reset the limit and continue the loop
                limit = 0;
                continue;
            }
    
            if (n >= '0' && n <= '9')
            {
                // If the input is a valid digit character, convert it to a number and store it in the corresponding array
                quit[limit] = n;
                num = n - '0';
                input[limit] = num;
                limit++;
            }
            else
            {
                // If the input is not a digit character, output error message and ask for re-entering
                cout << "----------------\n";
                cout << "|Invalid input |\n";
                cout << "----------------\n";
                cout << "Enter exactly 4 numbers¡G";
    
                // Clear the invalid characters in the input buffer
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
                // Reset the limit and continue the loop
                limit = 0;
                continue;
            }
        }
    
        maxCount++;
        if (maxCount >= 10)
        {
            if (quit[0] == 'q' && quit[1] == 'u' && quit[2] == 'i' && quit[3] == 't')
            {
                cout << "You lose! The answer is: ";
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
            cout << "Correct!\n";
            cout << "The answer is: ";
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

