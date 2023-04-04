#include <stdio.h>

struct record{
	int question_number;
	char question[50];
};


int test(struct quizRecord **B, int s) {
	int current = s-1;
	if(((B+current)->question_number) > 0) // for adding 1 record, check if time has value
	{
		printf("Enter question: ");
		getString(&(B+s)->question));
	}
}

int test(struct quizRecord *A, int s) {
	struct record quizRecord[10];
	struct quizRecord **B=&A;
	test2(B, int s);
}

int main(){
	struct record quizRecord[10];
	
	test(quizRecord, 10);
	
	
}
