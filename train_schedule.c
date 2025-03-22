#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct train{

    char *train_name;
    int arriv_time;
    int time_format;

};

void print(struct train *rail,int num){
    for(int j=0; j < num; j++){
		if(rail[j].arriv_time > 24){
           	printf("You enterd wrong Arrive time:\nPlease Try Again Leter\n");
			exit(1);
		}else{
			printf("Train name:%s \t Arrive Time:%d.00\n",rail[j].train_name,rail[j].arriv_time);
		}
	free(rail[j].train_name);
    }
}

int main(int argc,char* argv[]){
	
	int num =argc-1;
    
	if(num==0){
		printf("Please Enter Command Line Argument\n");
		exit(1);
	}
	
	struct train *rail;
	rail=(struct train*)malloc(num * sizeof(struct train));

    for(int i=0; i < num; i++){
		
		int len;
		len = strlen(argv[i+1]);
		
		rail[i].train_name=(char *)malloc(len* sizeof(char));
		
		if(rail[i].train_name == NULL){
			printf("Memory not Allocated\nPlease Try Again Leter\n");
			exit(1);			
		}
			strcpy(rail[i].train_name,argv[i+1]);
			
			if(strcmp(rail[i].train_name,argv[i+1])){

				printf("Train Name Not Assessed\n");
				printf("Please Try Again Leter\n");
				exit(1);			
			}
			
			printf("Enter Train time 0 - 12:");
			scanf("%d",&rail[i].arriv_time);

			if(rail[i].arriv_time > 12){
           		printf("You enterd wrong Arrive time:\nPlease Try Again Leter\n");
				exit(1);
			}

			printf("Enter 1 for AM \nEnter 2 for PM : ");
			scanf("%d",&rail[i].time_format);

			if(rail[i].time_format == 1){
				
				continue;
			}
			else if(rail[i].time_format == 2){
           		rail[i].arriv_time = 12+rail[i].arriv_time;
        	}
     		else{
           		printf("You Enterd wrong time Format:\nPlease Try Again Leter\n");
	    		exit(1);
			}
    }
	print(rail,num);
	return 0;
}
