/*
문제 10870 67%
피보나치 수는 0과 1로 시작한다. 0번째 피보나치 수는 0이고, 1번째 피보나치 수는 1이다. 그 다음 2번째 부터는 바로 앞 두 피보나치 수의 합이 된다.

이를 식으로 써보면 Fn = Fn-1 + Fn-2 (n>=2)가 된다.

n=17일때 까지 피보나치 수를 써보면 다음과 같다.

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597

n이 주어졌을 때, n번째 피보나치 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 n이 주어진다. n은 20보다 작거나 같은 자연수 또는 0이다.

출력
첫째 줄에 n번째 피보나치 수를 출력한다.
*/
#include<stdio.h>

int Fibo(int num);

int num_arr[22]={[0]=0,[1]=1};

int main(void){
	int num;
	scanf("%d",&num);

	Fibo(num);

	printf("%d",num_arr[num]);

	return 0;
}

/*int Fibo(int num){	//이런 식으로 로직을 짜면 n이 올라가면 올라갈 수록 함수호출 횟수가 기하급수적으로 많아짐.조심해야함.
	if(num==1||num==2){
		return 1;
	}
	return Fibo(num-1)+Fibo(num-2);
}*/

int Fibo(int num){
	if(num<2){return 0;}
	else	{Fibo(num-1);}

	num_arr[num] = num_arr[num - 1] + num_arr[num - 2];
	
	return 0;

}

