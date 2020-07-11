
/* 백준 2108번 문제

	수를 처리하는 것은 통계학에서 상당히 중요한 일이다. 통계학에서 N개의 수를 대표하는 기본 통계값에는 다음과 같은 것들이 있다. 단, N은 홀수라고 가정하자.

	산술평균 : N개의 수들의 합을 N으로 나눈 값
	중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
	최빈값 : N개의 수들 중 가장 많이 나타나는 값
	범위 : N개의 수들 중 최댓값과 최솟값의 차이

	N개의 수가 주어졌을 때, 네 가지 기본 통계값을 구하는 프로그램을 작성하시오.

	입력
		첫째 줄에 수의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 그 다음 N개의 줄에는 정수들이 주어진다. 입력되는 정수의 절댓값은 4,000을 넘지 않는다.

	출력
		첫째 줄에는 산술평균을 출력한다. 소수점 이하 첫째 자리에서 반올림한 값을 출력한다.

		둘째 줄에는 중앙값을 출력한다.

		셋째 줄에는 최빈값을 출력한다. 여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.

		넷째 줄에는 범위를 출력한다.

*/
#include<stdio.h>
#include <stdlib.h>			//퀵소트 함수 사용하기 위한 헤더파일

int compare(const void *a, const void *b)    // 오름차순 비교 함수 구현(퀵소트 조건)
{
    int num1 = *(int *)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
    int num2 = *(int *)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

    if (num1 < num2)    // a가 b보다 작을 때는
        return -1;      // -1 반환
    
    if (num1 > num2)    // a가 b보다 클 때는
        return 1;       // 1 반환
    
    return 0;    // a와 b가 같을 때는 0 반환
}

int main(void){
	int sequence_range;
	scanf("%d",&sequence_range);
	int sequence[sequence_range];		//가변적인 배열 선언
	int sorted_number[sequence_range];	//정렬된 값을 넣을 배열 선언

	int sum=0;					//산술평균관련 변수 선언
	double arithmetic_mean;
	int max,min,range;			//최대,최소값(범위)관련 변수 선언
	int median;					//중앙값관련 변수 선언
	int mode=0, mode_max=0,maxmax=0,num=0;	//최빈값관련 변수 선언
	int count[8001]={0,};	

	for(int i=0;i<sequence_range;i++){
		scanf("%d",&sequence[i]);
		sum=sum+sequence[i];		//입력받으면서 합누적
		count[sequence[i]+4000]++;		//sequence[]배열의 값을 count[]배열의 인덱스로 봄. //count[]배열의 값이 카운트. 카운트를 증가.
	}
	arithmetic_mean = (double)sum/sequence_range;	//산술평균 계산 후 출력
	printf("%.0lf\n",round(arithmetic_mean));

	for(int i = 0 ; i < 8001 ; i++){
		if(maxmax<count[i]){
			maxmax = count[i];//count 배열을 근거로 최빈 값을 찾음 
		}
	}
	for(int i = 0 ;i  < 8001 ;i++){
		if(count[i] == maxmax){//최빈 값들이 여러가지 일 경우를 생각. 2번째 것을 찾기 시작.  
			num++;
			mode = i;//1차 최빈 값의 값 
		}
		if(num == 2){//2차 최빈 값의 값 
			mode = i;
			break;
		}
	}

	qsort(sequence, sizeof(sequence) / sizeof(int), sizeof(int), compare);//범위(최대-최소값)과 중앙값을 알기위해 정렬.
	
	max = sequence[sequence_range-1];		//정렬 후 최소, 최대값, 범위를 지정.
	min = sequence[0];
	range = max - min;

	printf("%d\n",sequence[sequence_range/2]); 
	
	
	printf("%d\n",mode-4000);	//최빈값 출력

	printf("%d",range);		//범위 출력
}
