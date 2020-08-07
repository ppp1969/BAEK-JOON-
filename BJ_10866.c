/*
문제	덱구현 55% - 배열로 하면 비효율적이고 시간초과되기에 linked list로 구현
				++추가 단순연결리스트로 구현해도 시간이 초과됨 -> pop_back과정에서 시간복잡도가 O(n)만큼 걸림.
				++이중연결리스트로 구현해야함.

참고영상 주소 : https://www.youtube.com/watch?v=SnUo22WcV54

정수를 저장하는 덱(Deque)를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 여덟 가지이다.

push_front X: 정수 X를 덱의 앞에 넣는다.
push_back X: 정수 X를 덱의 뒤에 넣는다.
pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 덱에 들어있는 정수의 개수를 출력한다.
empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
입력
첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.

출력
출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.
*/

#include<stdio.h>
#include<string.h>  //문자열 비교를 위해 사용
#include<stdlib.h>	//노드사용.
typedef struct _node {	//단순 연결 리스트로 구현
	int data;
	struct _node * next;
	struct _node * prev;
}Node;

typedef struct _deque {
	Node * head;
	Node * tail;
	int count;
}Deque;

void deque_init(Deque* pdeq);
void push_first(Deque * pdeq, int data);
void push_back(Deque * pdeq, int data);
int pop_first(Deque * pdeq);
int pop_back(Deque *pdeq);
int size(Deque * pdeq);
int empty(Deque * pdeq);
int front(Deque * pdeq);
int back(Deque * pdeq);

int main(void){
	int num,in_data;
	Deque dq;
	deque_init(&dq);
	char command[20];
	scanf("%d ",&num);	//scanf의 마지막에 엔터가 버퍼에 남음 그래서 %d 뒤에 띄우지 않으면 command 개수가 -1회 실행됨.
						//get계열 함수도 버퍼에서 가져오기 때문임.!!

	for(int i=0; i<num; i++){
		gets(command);	//공백이 있으므로 scanf보다 gets함수가 적절함.
		if(strstr(command,"push_front")){
			sscanf(command,"push_front %d",&in_data);	//command에서 숫자값 빼오기.
			push_first(&dq, in_data);
		}
		else if(strstr(command,"push_back")){
			sscanf(command,"push_back %d",&in_data);
			push_back(&dq, in_data);
		}
		else if(strstr(command,"pop_front")){
			printf("%d\n",pop_first(&dq));
		}
		else if(strstr(command,"pop_back")){
			printf("%d\n",pop_back(&dq));
		}
		else if(strstr(command, "size")){
			printf("%d\n",dq.count);
		}
		else if(strstr(command, "empty")){
			printf("%d\n",empty(&dq));
		}
		else if(strstr(command, "front")){
			printf("%d\n",front(&dq));
		}
		else if(strstr(command, "back")){
			printf("%d\n",back(&dq));
		}
	}

	return 0;
}
void deque_init(Deque* pdeq){
	pdeq->head = NULL;
	pdeq->tail = NULL;
	pdeq->count = 0;
}

void push_first(Deque * pdeq, int data){
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	pdeq->count++;

	if(pdeq->head == NULL){
		pdeq->head = newNode;
		pdeq->tail = newNode;
	}
	else{
		newNode->next=pdeq->head;
		pdeq->head->prev=newNode;
		pdeq->head=newNode;
	}
}
void push_back(Deque * pdeq, int data){
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	pdeq->count++;

	newNode->prev = pdeq->tail;
	if(pdeq->head == NULL){
		pdeq->head = newNode;
		pdeq->tail = newNode;
	}
	else{
		pdeq->tail->next=newNode;
		newNode->prev=pdeq->tail;
		pdeq->tail=newNode;
	}
}

int pop_first(Deque * pdeq){
	if (empty(pdeq))
		return -1;

	int rdata = pdeq->head->data;

	if(pdeq->count==1){
		pdeq->head = NULL;
		pdeq->tail = NULL;
	}
	else{
		(pdeq->head->next)->prev=NULL;
		pdeq->head=pdeq->head->next;
	}
	
	pdeq->count--;

	return rdata;
}
int pop_back(Deque *pdeq){
	if (empty(pdeq))
		return -1;
	
	int rdata = pdeq->tail->data;
	if(pdeq->count==1){		//1개 들어있을 때, 오류남.
		pdeq->head = NULL;
		pdeq->tail = NULL;
	}
	else{
		(pdeq->tail->prev)->next=NULL;
		pdeq->tail=pdeq->tail->prev;
	}
	pdeq->count--;

	return rdata;
}
int empty(Deque * pdeq){
	if (pdeq->head == NULL)
		return 1;
	else
		return 0;
}
int front(Deque * pdeq){
	if (empty(pdeq))
		return -1;
	else
		return pdeq->head->data;
}
int back(Deque * pdeq){
	if (empty(pdeq))
		return -1;
	else
		return pdeq->tail->data;
}
