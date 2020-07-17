/*
문제
재귀적인 패턴으로 별을 찍어 보자. N이 3의 거듭제곱(3, 9, 27, ...)이라고 할 때, 크기 N의 패턴은 N×N 정사각형 모양이다.

크기 3의 패턴은 가운데에 공백이 있고, 가운데를 제외한 모든 칸에 별이 하나씩 있는 패턴이다.

***
* *
***
N이 3보다 클 경우, 크기 N의 패턴은 공백으로 채워진 가운데의 (N/3)×(N/3) 정사각형을 크기 N/3의 패턴으로 둘러싼 형태이다. 예를 들어 크기 27의 패턴은 예제 출력 1과 같다.

입력
첫째 줄에 N이 주어진다. N은 3의 거듭제곱이다. 즉 어떤 정수 k에 대해 N=3k이며, 이때 1 ≤ k < 8이다.


접근법 : N이 3의 거듭제곱이므로 3일때의 모양이 재귀적으로 호출될 수 밖에 없다. 문제의 내용이 재귀적인 패턴으로 풀기를 제시했으므로 배열에 값을 대입하고 이후 출력
*/

#include<stdio.h>

void star(int square_size,int Column,int Row);
void print_star(int num);

char arr[6562][6562];	//k가 8일때 최대사이즈의 배열선언

int main(void){
	int num;
	scanf("%d",&num);

	for(int i=0;i<num;i++){		//초기화 안해주면 백준에 제출할 때 오류뜸. 컴파일러에선 안써도 실행됨.
		for(int j =0;j<num;j++){
			arr[i][j] = ' ';
		}
	}


	star(num,0,0);
	print_star(num);

	return 0;
}


void star(int size,int Column,int Row){
	int i,j;
	if(size==3)
	{
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				arr[Column+i][Row+j]='*';
			}
		}
		arr[Column+1][Row+1]=' ';
	}
	else{
		for(i=0;i<size/3;i++){
			for(j=0;j<size/3;j++){
				arr[size/3+i][size/3+j]=' ';
			}
		}
			size/=3;
	
	star(size,Column,Row);	//크기를 점차 줄여가며 반복적으로 실행.
	star(size,Column,Row+size);
	star(size,Column,Row+2*size);
	star(size,Column+2*size,Row);
	star(size,Column+2*size,Row+size);
	star(size,Column+2*size,Row+2*size);
	star(size,Column+size,Row);
	star(size,Column+size,Row+2*size);
	}


}
void print_star(int num){
	for(int i=0;i<num;i++){
		for(int j=0; j<num;j++){
			printf("%c",arr[i][j]);
		}
		printf("\n");
	}
}
