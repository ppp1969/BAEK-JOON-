
/* ���� 2108�� ����

	���� ó���ϴ� ���� ����п��� ����� �߿��� ���̴�. ����п��� N���� ���� ��ǥ�ϴ� �⺻ ��谪���� ������ ���� �͵��� �ִ�. ��, N�� Ȧ����� ��������.

	������ : N���� ������ ���� N���� ���� ��
	�߾Ӱ� : N���� ������ �����ϴ� ������ �������� ��� �� �߾ӿ� ��ġ�ϴ� ��
	�ֺ� : N���� ���� �� ���� ���� ��Ÿ���� ��
	���� : N���� ���� �� �ִ񰪰� �ּڰ��� ����

	N���� ���� �־����� ��, �� ���� �⺻ ��谪�� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

	�Է�
		ù° �ٿ� ���� ���� N(1 �� N �� 500,000)�� �־�����. �� ���� N���� �ٿ��� �������� �־�����. �ԷµǴ� ������ ������ 4,000�� ���� �ʴ´�.

	���
		ù° �ٿ��� �������� ����Ѵ�. �Ҽ��� ���� ù° �ڸ����� �ݿø��� ���� ����Ѵ�.

		��° �ٿ��� �߾Ӱ��� ����Ѵ�.

		��° �ٿ��� �ֺ��� ����Ѵ�. ���� �� ���� ������ �ֺ� �� �� ��°�� ���� ���� ����Ѵ�.

		��° �ٿ��� ������ ����Ѵ�.

*/
#include<stdio.h>
#include <stdlib.h>			//����Ʈ �Լ� ����ϱ� ���� �������

int compare(const void *a, const void *b)    // �������� �� �Լ� ����(����Ʈ ����)
{
    int num1 = *(int *)a;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������
    int num2 = *(int *)b;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������

    if (num1 < num2)    // a�� b���� ���� ����
        return -1;      // -1 ��ȯ
    
    if (num1 > num2)    // a�� b���� Ŭ ����
        return 1;       // 1 ��ȯ
    
    return 0;    // a�� b�� ���� ���� 0 ��ȯ
}

int main(void){
	int sequence_range;
	scanf("%d",&sequence_range);
	int sequence[sequence_range];		//�������� �迭 ����
	int sorted_number[sequence_range];	//���ĵ� ���� ���� �迭 ����

	int sum=0;					//�����հ��� ���� ����
	double arithmetic_mean;
	int max,min,range;			//�ִ�,�ּҰ�(����)���� ���� ����
	int median;					//�߾Ӱ����� ���� ����
	int mode=0, mode_max=0,maxmax=0,num=0;	//�ֺ󰪰��� ���� ����
	int count[8001]={0,};	

	for(int i=0;i<sequence_range;i++){
		scanf("%d",&sequence[i]);
		sum=sum+sequence[i];		//�Է¹����鼭 �մ���
		count[sequence[i]+4000]++;		//sequence[]�迭�� ���� count[]�迭�� �ε����� ��. //count[]�迭�� ���� ī��Ʈ. ī��Ʈ�� ����.
	}
	arithmetic_mean = (double)sum/sequence_range;	//������ ��� �� ���
	printf("%.0lf\n",round(arithmetic_mean));

	for(int i = 0 ; i < 8001 ; i++){
		if(maxmax<count[i]){
			maxmax = count[i];//count �迭�� �ٰŷ� �ֺ� ���� ã�� 
		}
	}
	for(int i = 0 ;i  < 8001 ;i++){
		if(count[i] == maxmax){//�ֺ� ������ �������� �� ��츦 ����. 2��° ���� ã�� ����.  
			num++;
			mode = i;//1�� �ֺ� ���� �� 
		}
		if(num == 2){//2�� �ֺ� ���� �� 
			mode = i;
			break;
		}
	}

	qsort(sequence, sizeof(sequence) / sizeof(int), sizeof(int), compare);//����(�ִ�-�ּҰ�)�� �߾Ӱ��� �˱����� ����.
	
	max = sequence[sequence_range-1];		//���� �� �ּ�, �ִ밪, ������ ����.
	min = sequence[0];
	range = max - min;

	printf("%d\n",sequence[sequence_range/2]); 
	
	
	printf("%d\n",mode-4000);	//�ֺ� ���

	printf("%d",range);		//���� ���
}
