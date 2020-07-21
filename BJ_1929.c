/*
���� 1929 ����� 27%

(�����佺�׳׽��� ü�� Ȱ���� ��)

M�̻� N������ �Ҽ��� ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �ڿ��� M�� N�� �� ĭ�� ���̿� �ΰ� �־�����. (1 �� M �� N �� 1,000,000) M�̻� N������ �Ҽ��� �ϳ� �̻� �ִ� �Է¸� �־�����.

���
�� �ٿ� �ϳ���, �����ϴ� ������� �Ҽ��� ����Ѵ�.

�����佺�׳׽��� ü ex) 120������ �Ҽ��� ���Ѵٸ�,
120�� �����ٰ� ���ؼ� ���� �κп� �ش��ϴ� ���� ����鸸 ������ �Ҽ��Ǻ��� ������ ����. 

*/

#include<stdio.h>
#include<stdbool.h>
#include<math.h>

int count;
bool prime_N[1000001]={1,1,0}; //�⺻���� false, true�� �⺻���� false�� �Ҽ�.

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
