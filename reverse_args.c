#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* revrse(char *st,int len){

	char *ptr=NULL;

	ptr = (char*)malloc(len * sizeof(char));
	
	if(ptr==NULL){
		printf("Memory Not Assigned");
		exit(1);
	}

	for(int i=0; st[i] != '\0'; i++){
		ptr[i]=st[len-1];
		len--;
	}
	printf("%s",ptr);
//	return ptr;
}
int main(int argc, char *argv[]){

	int len=0;
	char *str=NULL;
	if(argc == 1){
		printf("Command line Argument is  Missing\n");
		exit(1);
	}
	for(int i=0; i < argc; i++){	
		len =strlen(argv[i+1]);

		str=(char*)malloc(len * sizeof(char));
		if(str==NULL){
			printf("String Memoey not Allocated\n");
			exit(1);
		}
		str =revrse(argv[i+1],len);
		printf("Revrse String %d Is:%s\n\n",i+1,str);
		free(str);	
	}
	return 0;
}
