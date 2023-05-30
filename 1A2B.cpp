#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
int main (){
	srand(time(NULL));
	int r;
	int a, b, c, d;
	int arr[4]={};
	
	for(int i=0;i<4;i++){
		r = rand()%(10)+1;
		arr[i]=r;
//		cout << arr[i];
	}
//	cout <<"\n";
	int cnt = 0;
	while(1){
		int A=0,B=0;
		char n;	
		int limit =0;
		int input[4]={};
		int num;
		cout <<"輸入四個數字：\n";
		while(cin.get(n)){
			if(limit >= 4){
				break;
			}
			num = n-48;
			input[limit]=num;
			limit++;
		}
		if(input[0]==arr[0]){
				A++;
		}else if(input[0]== arr[1]||input[0]== arr[2]||input[0]== arr[3]){
			B++;
		}
		if(input[1]==arr[1]){
			A++;
		}else if(input[1]== arr[0]||input[1]== arr[2]||input[1]== arr[3]){
			B++;
		}
		if(input[2]==arr[2]){
			A++;
		}else if(input[2]== arr[0]||input[2]== arr[1]||input[2]== arr[3]){
			B++;
		}
		if(input[3]==arr[3]){
			A++;
		}else if(input[3]== arr[0] ||input[3]== arr[1] ||input[3]== arr[2]){
			B++;
		}
		if(input[0]==arr[0]&&input[1]==arr[1]&&input[2]==arr[2]&&input[3]==arr[3]){
			cout << "correct ! !\n";
			break;
		}
		cout << A <<"A"<<B<<"B\n"; 
	}
	
	return 0;
} 
