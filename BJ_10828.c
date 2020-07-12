/*
문제
정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 다섯 가지이다.

push X: 정수 X를 스택에 넣는 연산이다.
pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 스택에 들어있는 정수의 개수를 출력한다.
empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
입력
첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.

출력
출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.
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
	scanf("%d ",&command_num);			//scanf의 마지막에 엔터가 버퍼에 남음 그래서 %d 뒤에 띄우지 않으면 command 개수가 -1회 실행됨.
										//get계열 함수도 버퍼에서 가져오기 때문임.!!
	
	int push_num;

	char command[15]; //명령어의 최대길이 : push 100000\n -> 최대치를 고려해서 넉넉하게 15로 잡음. 
	for(int i=0;i<command_num;i++){
		gets(command);		//push 명령어에 공백이 있기에 scanf함수사용 x.
		if(strstr(command,"push")){            //strstr로 command의 계열을 확인. push면 sscanf로 문자열 자르기.
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
