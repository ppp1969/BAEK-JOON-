/*10872 - 49%
문제
0보다 크거나 같은 정수 N이 주어진다. 이때, N!을 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 정수 N(0 ≤ N ≤ 12)가 주어진다.

출력
첫째 줄에 N!을 출력한다.
*/
#include<stdio.h>

int Factorial(int number);

int result = 1;

int main(void){
	int num;
	scanf("%d",&num);
	Factorial(num);
	printf("%d",result);

	return 0;
}

int Factorial(int number){
	if(number<=1){	
		return 0;		
	}
	else{
		result *= number;
		Factorial(number-1);
	}
	return 0;
}
