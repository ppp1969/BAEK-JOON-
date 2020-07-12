/*
����
������ �����ϴ� ������ ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.

����� �� �ټ� �����̴�.

push X: ���� X�� ���ÿ� �ִ� �����̴�.
pop: ���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ���ÿ� ����ִ� ������ ������ ����Ѵ�.
empty: ������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.
top: ������ ���� ���� �ִ� ������ ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
�Է�
ù° �ٿ� �־����� ����� �� N (1 �� N �� 10,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ����� �ϳ��� �־�����. �־����� ������ 1���� ũ�ų� ����, 100,000���� �۰ų� ����. ������ �������� ���� ����� �־����� ���� ����.

���
����ؾ��ϴ� ����� �־��� ������, �� �ٿ� �ϳ��� ����Ѵ�.
*/
#include<stdio.h>
#include <string.h>

int stack[10000]={0,};
int count=0;

void push(push_num){
	stack[count]=push_num;
	count++;
}

void size(void){
	printf("%d\n",count);
}

void empty(void){
	if(count==0) printf("%d\n", 1);
	else printf("%d\n", 0);
}

void top(void){
	if(count==0) printf("-1\n");
	else printf("%d\n", stack[count-1]);
}

void pop(void){
	if(count==0) printf("-1\n");
    else{
        printf("%d\n", stack[count-1]);
		stack[count]=0;
        count--;
    }
}

int main(void){
	int command_num;
	scanf("%d ",&command_num);			//scanf�� �������� ���Ͱ� ���ۿ� ���� �׷��� %d �ڿ� ����� ������ command ������ -1ȸ �����.
										//get�迭 �Լ��� ���ۿ��� �������� ������.!!
	
	int push_num;

	char command[15]; //��ɾ��� �ִ���� : push 100000\n -> �ִ�ġ�� ����ؼ� �˳��ϰ� 15�� ����. 
	for(int i=0;i<command_num;i++){
		gets(command);		//push ��ɾ ������ �ֱ⿡ scanf�Լ���� x.
		if(strstr(command,"push")){            //strstr�� command�� �迭�� Ȯ��. push�� sscanf�� ���ڿ� �ڸ���.
            sscanf(command,"push %d",&push_num);
            push(push_num);
        } 
		else if(strstr(command,"size")){
            size();
        } 
		else if(strstr(command,"empty")){
            empty();
        } 
		else if(strstr(command,"top")){
            top();
        } 
		else if(strstr(command,"pop")) {
            pop();
        } 
	}

	return 0;
}
