/*

���� ����� 30%

�ð����⵵�� O�� �ʰ��ϸ� �ȵȴ�.

������ �����ϴ� ť�� ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.

����� �� ���� �����̴�.

push X: ���� X�� ť�� �ִ� �����̴�.
pop: ť���� ���� �տ� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ť�� ����ִ� ������ ������ ����Ѵ�.
empty: ť�� ��������� 1, �ƴϸ� 0�� ����Ѵ�.
front: ť�� ���� �տ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
back: ť�� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.

�Է�
ù° �ٿ� �־����� ����� �� N (1 �� N �� 2,000,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ����� �ϳ��� �־�����. �־����� ������ 1���� ũ�ų� ����, 100,000���� �۰ų� ����. ������ �������� ���� ����� �־����� ���� ����.

���
����ؾ��ϴ� ����� �־��� ������, �� �ٿ� �ϳ��� ����Ѵ�.

*/

#include<stdio.h>
#include<string.h>  //���ڿ� �񱳸� ���� ���

int queue[2000000];
int first,last;

void push(int data);
void pop(void);
void size(void);
void empty(void);
void front(void);
void back(void);

int main(void){
	int num,data;
	char command[15];
	scanf("%d ",&num);	//scanf�� �������� ���Ͱ� ���ۿ� ���� �׷��� %d �ڿ� ����� ������ command ������ -1ȸ �����.
						//get�迭 �Լ��� ���ۿ��� �������� ������.!!

	for(int i=0; i<num; i++){
		gets(command);	//������ �����Ƿ� scanf���� gets�Լ��� ������.
		if(strstr(command,"push")){
			sscanf(command,"push %d",&data);	//command���� ���ڰ� ������.
			push(data);
		}
		else if(strstr(command,"pop")){
			pop();
		}
		else if(strstr(command, "size")){
			size();
		}
		else if(strstr(command, "empty")){
			empty();
		}
		else if(strstr(command, "front")){
			front();
		}
		else if(strstr(command, "back")){
			back();
		}
	}

	return 0;
}

void push(int data){
	queue[last] = data;
	last++;
}
void pop(void){
	if(first==last)
		printf("%d\n",-1);
	else
		printf("%d\n",queue[first++]);

}
void size(void){
	printf("%d\n",last-first);
}
void empty(void){
	if(first==last)
		printf("%d\n",1);
	else
		printf("%d\n",0);

}
void front(void){
	if(first==last)
		printf("%d\n",-1);
	else
		printf("%d\n",queue[first]);
}
void back(void){
		if(first==last)
		printf("%d\n",-1);
	else
		printf("%d\n",queue[last-1]);
}
