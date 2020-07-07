#include<stdio.h>
#define arr_max 1000000

int alphabet[26];

int stack(char A){
	if(A>=97)
		alphabet[A-97]++;
	else
		alphabet[A-65]++;
	return 0;
}

int main(void){
	char arr[arr_max];
	int i=0,j,temp=0;
	int most=0;

	scanf("%s",arr);

	while(arr[i]){
		stack(arr[i]);
		i++;
	}
	
	for(j=1;j<26;j++){
		if(alphabet[j]>alphabet[most]){
			most=j;
		}
	}

	for(j=0;j<26;j++){
		if(alphabet[j]==alphabet[most]){
			temp++;
		}
	}
	if(temp!=1)
		printf("?");
	
	else
		printf("%c",most+65);

}
