/*10872 - 49%
����
0���� ũ�ų� ���� ���� N�� �־�����. �̶�, N!�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� N(0 �� N �� 12)�� �־�����.

���
ù° �ٿ� N!�� ����Ѵ�.
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
