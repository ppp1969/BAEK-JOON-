#include<stdio.h>
#define arr_max 201
//���� ���� �Է¹��� ������ scanf �ȸ���.
//gets�Լ��� ��ü
int main(void){
	char arr[arr_max];
	int i=0;	//(i+1)-Croatia �ϸ� ����.
	int Croatia = 0;
	gets(arr);
	while(arr[i]!=0){	//'=','-','j'�� Ư���� ũ�ξ�Ƽ�� ���ڵ��� �ν��ϰ�. ���ǿ� ���� �Ǻ�.
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

