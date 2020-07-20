/*
문제 1316 52%
그룹 단어란 단어에 존재하는 모든 문자에 대해서, 각 문자가 연속해서 나타나는 경우만을 말한다. 예를 들면, ccazzzzbb는 c, a, z, b가 모두 연속해서 나타나고, kin도 k, i, n이 연속해서 나타나기 때문에 그룹 단어이지만, aabbbccb는 b가 떨어져서 나타나기 때문에 그룹 단어가 아니다.

단어 N개를 입력으로 받아 그룹 단어의 개수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 단어의 개수 N이 들어온다. N은 100보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에 단어가 들어온다. 단어는 알파벳 소문자로만 되어있고 중복되지 않으며, 길이는 최대 100이다.

출력
첫째 줄에 그룹 단어의 개수를 출력한다.
*/

#include<stdio.h>
#include<string.h> //memset함수로 배열을 사용하다 중단에 초기화.
#include<stdbool.h> //알파벳 배열로 참, 거짓판별 - 전에 나왔으면 true

void checker(char arr[], int size);

int count;

int main(void){
	int num;

	scanf("%d",&num);
	char arr[100];
	for(int i = 0 ; i < num ; i++){
		memset(arr,0,sizeof(char)*100);	//초기화.
		scanf("%s",arr);
		
		checker(arr,100);
	}
	printf("%d",count);
	
	return 0;
}

void checker(char arr[], int size){
	bool alphabet[26]={0,};	//전에 나온 적이 있다면 true로 값을 바꿔 저장하는 배열.
							//true인 상태에서 한번더 나온다면 check++; - 그룹단어가 아님.마지막에 check값이 0이이면 count ++;
	int check = 0;		
	int index = 0;
	for(int i = 1; i < (size - 1); i++){
		if(arr[i-1]!=arr[i]){
			if(alphabet[arr[i-1]-97] == true){	//아스키코드 값이 a~z : 97~122인 것을 활용하여 판별.
				check++;
			}
			alphabet[arr[i-1]-97]=true;
		}
	}
	if(check == 0){
		count++;
	}
}
