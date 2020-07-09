#include<stdio.h>
#define arr_max 201
//공백 문자 입력받을 때에는 scanf 안먹힘.
//gets함수로 대체
int main(void){
	char arr[arr_max];
	int i=0;	//(i+1)-Croatia 하면 나옴.
	int Croatia = 0;
	gets(arr);
	while(arr[i]!=0){	//'=','-','j'로 특별한 크로아티아 문자들을 인식하고. 조건에 따라 판별.
		if(arr[i]=='='){
			if(i>=2&&(arr[i-1]=='z'&&arr[i-2]=='d')){
				Croatia=Croatia+2;
			}
			else{
				Croatia++;
			}
		}
		if(arr[i]=='-'){
			Croatia++;
		}
		if(arr[i]=='j'){
			if(i>=1&&(arr[i-1]=='l'||arr[i-1]=='n')){
				Croatia++;
			}
		}
		i++;
	}
	printf("%d",i-Croatia);
}

