/*
���� 1316 52%
�׷� �ܾ�� �ܾ �����ϴ� ��� ���ڿ� ���ؼ�, �� ���ڰ� �����ؼ� ��Ÿ���� ��츸�� ���Ѵ�. ���� ���, ccazzzzbb�� c, a, z, b�� ��� �����ؼ� ��Ÿ����, kin�� k, i, n�� �����ؼ� ��Ÿ���� ������ �׷� �ܾ�������, aabbbccb�� b�� �������� ��Ÿ���� ������ �׷� �ܾ �ƴϴ�.

�ܾ� N���� �Է����� �޾� �׷� �ܾ��� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �ܾ��� ���� N�� ���´�. N�� 100���� �۰ų� ���� �ڿ����̴�. ��° �ٺ��� N���� �ٿ� �ܾ ���´�. �ܾ�� ���ĺ� �ҹ��ڷθ� �Ǿ��ְ� �ߺ����� ������, ���̴� �ִ� 100�̴�.

���
ù° �ٿ� �׷� �ܾ��� ������ ����Ѵ�.
*/

#include<stdio.h>
#include<string.h> //memset�Լ��� �迭�� ����ϴ� �ߴܿ� �ʱ�ȭ.
#include<stdbool.h> //���ĺ� �迭�� ��, �����Ǻ� - ���� �������� true

void checker(char arr[], int size);

int count;

int main(void){
	int num;

	scanf("%d",&num);
	char arr[100];
	for(int i = 0 ; i < num ; i++){
		memset(arr,0,sizeof(char)*100);	//�ʱ�ȭ.
		scanf("%s",arr);
		
		checker(arr,100);
	}
	printf("%d",count);
}

void checker(char arr[], int size){
	bool alphabet[26]={0,};	//���� ���� ���� �ִٸ� true�� ���� �ٲ� �����ϴ� �迭.
							//true�� ���¿��� �ѹ��� ���´ٸ� check++; - �׷�ܾ �ƴ�.�������� check���� 0���̸� count ++;
	int check = 0;		
	int index = 0;
	for(int i = 1; i < (size - 1); i++){
		if(arr[i-1]!=arr[i]){
			if(alphabet[arr[i-1]-97] == true){	//�ƽ�Ű�ڵ� ���� a~z : 97~122�� ���� Ȱ���Ͽ� �Ǻ�.
				check++;
			}
			alphabet[arr[i-1]-97]=true;
		}
	}
	if(check == 0){
		count++;
	}
}
