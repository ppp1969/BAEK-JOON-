#include<stdio.h>
#define arr_max 1000001
//공백 문자 입력받을 때에는 scanf 안먹힘.
//gets함수로 대체
int main(void){
	char arr[arr_max];
	int i=1;
	int space = 0;
	gets(arr);
	while(arr[i]!=0){
		if(arr[i]==' '){
			if(arr[i+1]!='\0'){		//공백기준으로 개수세기 + 공백이 마지막에 나오는 경우 예외처리
				space++;
			}
		}
		i++;
	}
	if(arr[0]=='\0'||(arr[0]==' ')&&(arr[1]=='\0')){printf("%d",space);} //" "입력, ""입력 등 예외처리
	else			{printf("%d",space+1);}
}

