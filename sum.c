#include<stdio.h>
#include<stdlib.h>

struct node{
	int a;
	int b;
	int (*fptr)(int ,int);
};

int sum(int a,int b){
	return a+b;
}

int main(){
	struct node n1;
	int result;

	printf("Enter Two Number's:");
	scanf("%d %d",&n1.a,&n1.b);
	
	n1.fptr=sum;
	result =n1.fptr(n1.a,n1.b);
	printf("%d",result);

	return 0;
}	
