#include<stdio.h>
#define arr_max 1000001
//���� ���� �Է¹��� ������ scanf �ȸ���.
//gets�Լ��� ��ü
int main(void){
	char arr[arr_max];
	int i=1;
	int space = 0;
	gets(arr);
	while(arr[i]!=0){
		if(arr[i]==' '){
			if(arr[i+1]!='\0'){		//����������� �������� + ������ �������� ������ ��� ����ó��
				space++;
			}
		}
		i++;
	}
	if(arr[0]=='\0'||(arr[0]==' ')&&(arr[1]=='\0')){printf("%d",space);} //" "�Է�, ""�Է� �� ����ó��
	else			{printf("%d",space+1);}
}

