/*
����	������ 55% - �迭�� �ϸ� ��ȿ�����̰� �ð��ʰ��Ǳ⿡ linked list�� ����
				++�߰� �ܼ����Ḯ��Ʈ�� �����ص� �ð��� �ʰ��� -> pop_back�������� �ð����⵵�� O��ŭ �ɸ�.
				++���߿��Ḯ��Ʈ�� �����ؾ���.

������ �ּ� : https://www.youtube.com/watch?v=SnUo22WcV54

������ �����ϴ� ��(Deque)�� ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.

����� �� ���� �����̴�.

push_front X: ���� X�� ���� �տ� �ִ´�.
push_back X: ���� X�� ���� �ڿ� �ִ´�.
pop_front: ���� ���� �տ� �ִ� ���� ����, �� ���� ����Ѵ�. ����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
pop_back: ���� ���� �ڿ� �ִ� ���� ����, �� ���� ����Ѵ�. ����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ���� ����ִ� ������ ������ ����Ѵ�.
empty: ���� ��������� 1��, �ƴϸ� 0�� ����Ѵ�.
front: ���� ���� �տ� �ִ� ������ ����Ѵ�. ���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
back: ���� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
�Է�
ù° �ٿ� �־����� ����� �� N (1 �� N �� 10,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ����� �ϳ��� �־�����. �־����� ������ 1���� ũ�ų� ����, 100,000���� �۰ų� ����. ������ �������� ���� ����� �־����� ���� ����.

���
����ؾ��ϴ� ����� �־��� ������, �� �ٿ� �ϳ��� ����Ѵ�.
*/

#include<stdio.h>
#include<string.h>  //���ڿ� �񱳸� ���� ���
#include<stdlib.h>	//�����.
typedef struct _node {	//�ܼ� ���� ����Ʈ�� ����
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
	scanf("%d ",&num);	//scanf�� �������� ���Ͱ� ���ۿ� ���� �׷��� %d �ڿ� ����� ������ command ������ -1ȸ �����.
						//get�迭 �Լ��� ���ۿ��� �������� ������.!!

	for(int i=0; i<num; i++){
		gets(command);	//������ �����Ƿ� scanf���� gets�Լ��� ������.
		if(strstr(command,"push_front")){
			sscanf(command,"push_front %d",&in_data);	//command���� ���ڰ� ������.
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
	newNode->next = pdeq->head;
	if(pdeq->head == NULL){
		pdeq->tail = newNode;
	}
	else{
		pdeq->head->prev = newNode;
	}
	pdeq->head = newNode;
	newNode->prev=NULL;
}
void push_back(Deque * pdeq, int data){
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	pdeq->count++;

	newNode->prev = pdeq->tail;
	if(pdeq->head == NULL){
		pdeq->head = newNode;
	}
	else{
		pdeq->tail->next = newNode;
	}
	newNode->next=NULL;
	pdeq->tail = newNode;
}

int pop_first(Deque * pdeq){
	if (empty(pdeq))
		return -1;

	Node * rnode = pdeq->head;
	int rdata = rnode->data;

	pdeq->head = pdeq->head->next;
	if (pdeq->head == NULL) 
		pdeq->tail = NULL;
	else 
		pdeq->head->prev = NULL;
	
	free(rnode);
	return rdata;
}
int pop_back(Deque *pdeq){
	if (empty(pdeq))
		return -1;
	Node * rnode = pdeq->tail;
	int rdata = rnode->data;

	pdeq->tail = pdeq->tail->prev;
	if (pdeq->tail == NULL) 
		pdeq->head = NULL;
	
	else 
		pdeq->tail->next = NULL;
	free(rnode);
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
