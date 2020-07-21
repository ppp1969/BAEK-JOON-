/*
문제 1929 정답률 27%

(에라토스테네스의 체를 활용할 것)

M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1 ≤ M ≤ N ≤ 1,000,000) M이상 N이하의 소수가 하나 이상 있는 입력만 주어진다.

출력
한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.

에라토스테네스의 체 ex) 120까지의 소수를 구한다면,
120의 제곱근과 비교해서 정수 부분에 해당하는 수의 배수들만 지워도 소수판별에 문제가 없다. 

*/

#include<stdio.h>
#include<stdbool.h>
#include<math.h>

int count;
bool prime_N[1000001]={1,1,0}; //기본값은 false, true면 기본숫자 false면 소수.

void prime_decision(int last);

int main(void){
	int first, last;
	scanf("%d %d", &first,&last);

	prime_decision(last);

	for(int i=first; i<=last;i++){
		if(prime_N[i]==false){
			printf("%d\n", i);
		}
	}
	return 0;
}

void prime_decision(int last){
	for(int i=2; pow(i,2)<=last; i++){
		if(prime_N[i]==false){
			for(int j=i; j<=last; j+=i){
				if(j!=i){
					prime_N[j] = true;
				}
			}
		}
		
	}
}
