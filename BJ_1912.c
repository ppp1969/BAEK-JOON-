#include<stdio.h>
/*
문제
n개의 정수로 이루어진 임의의 수열이 주어진다. 우리는 이 중 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다. 단, 수는 한 개 이상 선택해야 한다.

예를 들어서 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 이라는 수열이 주어졌다고 하자. 여기서 정답은 12+21인 33이 정답이 된다.

입력
첫째 줄에 정수 n(1 ≤ n ≤ 100,000)이 주어지고 둘째 줄에는 n개의 정수로 이루어진 수열이 주어진다. 수는 -1,000보다 크거나 같고, 1,000보다 작거나 같은 정수이다.

출력
첫째 줄에 답을 출력한다.

문제풀이 접근방식 : 잘못된 접근 : (-값을 찾고 -값 사이의 값을 모두 더하고 그 값을 누적비교해서 최대값 찾기.)
				temp 변수에 값을 계속 누적해서 넣음. temp가 음수 되면 초기화 ㅋㅋ;
*/

int main(void){
	int num;
	scanf("%d ",&num);		//최대 10만
	int inputarr[num];
	int temp = 0;
	int max=-1001; //부분합의 최소값은 -1000 임을 이용해서 최대값 변수 정의

	/* 2시간 헤멘 잘못된 접근법 : 음수값을 무조건 안 더하는 것이 아니라 음수값을 포함해도 더 큰 합이 존재할 가능성을 고려해야함.;;;
	for(int i=0;i<num;i++){
		scanf("%d",&inputarr[i]);
		if(inputarr[i]<0){	//음수라면 = 음수판정 on
			if(temp!=0){	//음수값만 존재할 때도 생각해서 temp값이 빈 경우 예외처리.
				if(temp>max){ max = temp; }
			}
			if(inputarr[i]>max){ max = inputarr[i]; }
			temp = 0;
		}
		else if(i==num-1) {
			temp += inputarr[i];
			if(temp>max){ max = temp; }
			temp = 0;
		}
		else {
			temp += inputarr[i];
		}*/


	for(int i=0;i<num;i++){
		scanf("%d",&inputarr[i]);
		temp = temp + inputarr[i];
		if(temp>max){ max = temp; }
		if(temp<0){
			//모두 음수 값일때 예외처리.
			if(max<inputarr[i]){ max = inputarr[i]; }
			temp = 0;
		}
	}

	printf("%d\n", max);    

	return 0;
}
