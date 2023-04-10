#include <stdio.h>
#include <stdlib.h>


struct record {
	char topic[20];
	int questionNumber;
	char question[150];
	char choice1[30];
	char choice2[30];
	char choice3[30];
	char answer[30];
};

void importData(struct record *A, int s){
	char filename[30];
	int i=0, flag=1;
	// file pointer declaration
	FILE *fp;
	
	while(flag){
		fprintf(stdout, "Input filename : ");
		fscanf(stdin, "%s", filename);
		if((fp=fopen(filename, "r"))==NULL){
			fprintf(stderr, "ERROR: %s does not exist.\n", filename);
			fprintf(stdout, "Please try inputting a different filename.");
		} else {
			do{
				if((fscanf(fp, "%s\n%d\n%s\n%s\n%s\n%s\n%s",  &((A+i)->topic), &((A+i)->questionNumber), &((A+i)->question),
					&((A+i)->choice1), &((A+i)->choice2), &((A+i)->choice3), &((A+i)->answer))==7)){
					fprintf(stdout, "\nA[%d] = %s\n%d\n%s\n%s\n%s\n%s\n%s", (A+i)->topic, (A+i)->questionNumber, (A+i)->question,
					(A+i)->choice1, (A+i)->choice2, (A+i)->choice3, (A+i)->answer);
				}
				i++;
			}while(i<s);
			flag=0;
		}
	}
	fclose(fp);
}

int main(){
	struct record A[2];
	char filename[30];
	int flag=1;
	int count=0;
	
	FILE *fp;
	
	importData(A,2);
	
	fclose(fp);
	return 0;
}

