/*
����
������� �������� ���� ��� ����. N�� 3�� �ŵ�����(3, 9, 27, ...)�̶�� �� ��, ũ�� N�� ������ N��N ���簢�� ����̴�.

ũ�� 3�� ������ ����� ������ �ְ�, ����� ������ ��� ĭ�� ���� �ϳ��� �ִ� �����̴�.

***
* *
***
N�� 3���� Ŭ ���, ũ�� N�� ������ �������� ä���� ����� (N/3)��(N/3) ���簢���� ũ�� N/3�� �������� �ѷ��� �����̴�. ���� ��� ũ�� 27�� ������ ���� ��� 1�� ����.

�Է�
ù° �ٿ� N�� �־�����. N�� 3�� �ŵ������̴�. �� � ���� k�� ���� N=3k�̸�, �̶� 1 �� k < 8�̴�.


���ٹ� : N�� 3�� �ŵ������̹Ƿ� 3�϶��� ����� ��������� ȣ��� �� �ۿ� ����. ������ ������ ������� �������� Ǯ�⸦ ���������Ƿ� �迭�� ���� �����ϰ� ���� ���
*/

#include<stdio.h>

void star(int square_size,int Column,int Row);
void print_star(int num);

char arr[6562][6562];	//k�� 8�϶� �ִ�������� �迭����

int main(void){
	int num;
	scanf("%d",&num);

	for(int i=0;i<num;i++){		//�ʱ�ȭ �����ָ� ���ؿ� ������ �� ������. �����Ϸ����� �Ƚᵵ �����.
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
	
	star(size,Column,Row);	//ũ�⸦ ���� �ٿ����� �ݺ������� ����.
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
