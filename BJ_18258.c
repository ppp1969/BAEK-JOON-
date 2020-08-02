/*

문제 정답률 30%

시간복잡도가 O를 초과하면 안된다.

정수를 저장하는 큐를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 여섯 가지이다.

push X: 정수 X를 큐에 넣는 연산이다.
pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 큐에 들어있는 정수의 개수를 출력한다.
empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.

입력
첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 2,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.

출력
출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.

*/

#include<stdio.h>
#include<string.h>  //문자열 비교를 위해 사용

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
	scanf("%d ",&num);	//scanf의 마지막에 엔터가 버퍼에 남음 그래서 %d 뒤에 띄우지 않으면 command 개수가 -1회 실행됨.
						//get계열 함수도 버퍼에서 가져오기 때문임.!!

	for(int i=0; i<num; i++){
		gets(command);	//공백이 있으므로 scanf보다 gets함수가 적절함.
		if(strstr(command,"push")){
			sscanf(command,"push %d",&data);	//command에서 숫자값 빼오기.
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
