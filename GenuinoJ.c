// #includes
#include <stdio.h>
#include <conio.h>
#include <string.h>
/* Quiz Game v2
Author: Jose Mari Victorio G. Genuino
Date Started: 7 February 2023
Date Finished: 5 April 2023
Purpose: QUIZ GAME - [CCPROG2] Machine Project 
*/

#define SIZE 2

// prototypes
int showMaster();
int showManageDataMenu();
int showManageDataSubMenu();
int showQuizGameMenu();
int showQuizGameSubMenu();


// typedefs
typedef char String20[20];
typedef char String30[30];
typedef char Sentence[150];

/* struct record
	- 
*/
struct record {
	String20 topic;
	int questionNumber;
	Sentence question;
	String30 choice1;
	String30 choice2;
	String30 choice3;
	String30 answer;
};

/* struct score
*/
struct score {
	int rowNum;
	String20 playerName;
	int score;
};

// implement player name array and/or struct 
// implement linear or binary search 
// check hands on 2 and hands on 1 exams

/* getString20 is a void function that allows the user to to input String20
	@param *ptr - points to address of passed String20 variable instance
*/ 
void
getString20(String20 s)
{
	char ch;
	int i = 0;
	String20 string2;
	
	do
	{
		scanf("%c", &ch);
		
		if(ch != '\n')
		{
			s[i] = ch;
			i++;
			s[i] = '\0';
		}
	}while (i < 21 && ch != '\n');
	
//	strcpy(*ptr2, string2);
} 

/* getString30 is a void function that allows the user to to input String30
	@param *ptr - points to address of passed String30 variable instance
*/
void
getString30(String30 s)
{
	char ch;
	int i = 0;
	String30 string3;
	
	do
	{
		scanf("%c", &ch);
		
		if(ch != '\n')
		{
			s[i] = ch;
			i++;
			s[i] = '\0';
		}
	}while (i < 31 && ch != '\n');
	
//	strcpy(*ptr3, string3);
}

/* getSentence is a void function that allows the user to to input a Sentence
	@param *ptr - points to address of passed Sentence variable instance
*/
void
getSentence(Sentence s)
{
	char ch;
	int i = 0;
	Sentence a;
	
	do
	{
		scanf("%c", &ch);
		
		if(ch != '\n')
		{
			s[i] = ch;
			i++;
			s[i] = '\0';
		}
	}while (i < 151 && ch != '\n');
	
//	strcpy(*ptr4, a);
}

/* binarySearch is a void function that allows the user to to input a Sentence
	@param *ptr - points to address of passed Sentence variable instance
*/
int
binarySearch(Sentence *param1, String30 *param2, struct record *A, int s)
{
    // Encode your solution.
    int low=0, high=s-1, mid, cmp;
    int found=0;
    
    while(found==0&&low<=high){
    	mid=low+(high-low)/2;
    	cmp = strcmp(A[mid].question, param1);
    	if(!cmp)
    		cmp = strcmp(A[mid].answer, param2);
    	
    // positive cmp means current is greater
    	if(!cmp){
    		found=1;
		} else if (cmp>0){
			high=mid-1;
		} else {
			low=mid+1;
		}
	}
	
	if(found)
		return mid;
	else
		return -1;
}

/* getInput allows the user to input a record for the Quiz Game
	@param *A - points to the first index address of the array of records passed to the function
	@param s - is the size of the array of records passed
*/ 
void
getInput(struct record *A, int s)
{
	int j, current = s-1, found=0;
	char c;
	Sentence questionTemp;
	String30 answerTemp;
	
	
	do{
		scanf("%c", &c);
		printf("Enter question:");
		getSentence(questionTemp);
		printf("\nEnter answer:");
		getString30(answerTemp);
		
		found = binarySearch(questionTemp, answerTemp, A, s);
		printf("\nFound = %d", found);
		if(found!=-1){
			printf("The entered Question and Answer has already been listed in the records.\n");
			printf("%-10s %-10d %-30s %-10s %-10s %-10s %-10s\n", 
			(A+found)->topic, (A+found)->questionNumber, (A+found)->question, 
			(A+found)->choice1, (A+found)->choice2, (A+found)->choice3, (A+found)->answer);
		} else {
			printf("The entered Question and Answer does not exist in the records.\n");
			
			// enter last three fields
			// question number should already be assigned
			if(((A+current)->questionNumber) > 0) // for adding 1 record, check if questionNumber has value
			{
				printf("%d", (A+current)->questionNumber);
				printf("\nEnter topic: ");
				getString20(&((A+s)->topic));
				printf("Enter question number: ");
				scanf("%d", &((A+s)->questionNumber));
				scanf("%c", &c);// for new line in between int and characters
	//			printf("Enter question: ");
	//			getSentence(&((A+i)->question));
				strcpy((A+s)->question, questionTemp);
				printf("Enter choice1: ");
				getString30(&((A+s)->choice1));
				printf("Enter choice2: ");
				getString30(&((A+s)->choice2));
				printf("Enter choice3: ");
				getString30(&((A+s)->choice3));
	//			printf("Enter answer: ");
	//			getString30(&((A+i)->answer));
				strcpy((A+s)->answer, answerTemp);
			}
			else
			{
				for(j=0; j < s/*change value to s after testing*/; j++)
				{
					printf("ITEM # %d", j+1);
					printf("\nEnter topic: ");
					getString20(&((A+j)->topic));
					printf("topic = %s", (A+j)->topic);
					printf("Enter question number: ");
					scanf("%d", &((A+j)->questionNumber));
					scanf("%c", &c);// for new line in between int and characters
		//			printf("Enter question: ");
		//			getSentence(&((A+i)->question));
					strcpy((A+j)->question, questionTemp);
					printf("Enter choice1: ");
					getString30(&((A+j)->choice1));
					printf("Enter choice2: ");
					getString30(&((A+j)->choice2));
					printf("Enter choice3: ");
					getString30(&((A+j)->choice3));
		//			printf("Enter answer: ");
		//			getString30(&((A+i)->answer));
					strcpy((A+j)->answer, answerTemp);
					}
				}	
			}
		}while(found!=-1);
} // fix logic

/* displayStruct allows the user to display the records for the Quiz Game
	@param *A - points to the first index address of the array of records passed to the function
	@param s - is the size of the array of records passed
*/ 
void
displayStruct(struct record A[], int s)
{
	int i;
	printf("\n%-10s %-10s %-20s %-10s %-10s %-10s %-10s\n", "Topic", "Number", "Question", "Choice 1", "Choice 2", "Choice 3", "Answer");
	
		for(i=0; i < s; i++)
		{
			printf("%-10s %-10d %-30s %-10s %-10s %-10s %-10s\n", (A+i)->topic, (A+i)->questionNumber, (A+i)->question, (A+i)->choice1, (A+i)->choice2, (A+i)->choice3, (A+i)->answer);
		}
}

/* addStruct allows the user to input additional records for the Quiz Game
	@param *A - points to the first index address of the array of records passed to the function
	@param s - is the size of the array of records passed
*/ 
int
addStruct(struct record *A, int s)
{
	getInput(A, s);
	return s + 1;
} 

/* editStruct allows the user to edit a record for the Quiz Game
	@param *A - points to the first index address of the array of records passed to the function
	@param s - is the size of the array of records passed
*/ 
void
editStruct(struct record *A, int s)
{
	int i = 0;
	int t = 1;
	char c;
	
	do{
		printf("EDIT %-10s %-5.2d %-20s %-20s %-20s %-20s %-20s (Y/N)?", (A+i)->topic, (A+i)->questionNumber, (A+i)->question, (A+i)->choice1, (A+i)->choice2, (A+i)->choice3, (A+i)->answer);
		scanf(" %c", &c);
		if(c == 121 || c == 89) // y or Y
		{
			printf("\nEnter topic: ");
			scanf("%s", &((A+i)->topic));
			scanf("%c", &c);// for new line in between int and characters
			printf("Enter question number: ");
			scanf("%d", &((A+i)->questionNumber));
			scanf("%c", &c);// for new line in between int and characters
			printf("Enter question: ");
			getSentence(&((A+i)->question));
			printf("Enter choice1: ");
			getString30(&((A+i)->choice1));
			printf("Enter choice2: ");
			getString30(&((A+i)->choice2));
			printf("Enter choice3: ");
			getString30(&((A+i)->choice3));
			printf("Enter answer: ");
			getString30(&((A+i)->answer));
			t = 0;
		}
		else
		{
			i++;
			t = 1;
		}
	}while(i < s && t);
} // fix logic

/* deleteStruct allows the user to delete a record for the Quiz Game
	@param *A - points to the first index address of the array of records passed to the function
	@param s - is the size of the array of records passed
*/ 
int
deleteStruct(struct record *A, int s)
{
	int i = 0;
	int t = 1;
	int d; // deleted index
	char c;
	
	do{
		printf("DELETE %-10s %-5.2d %-20s %-20s %-20s %-20s %-20s (Y/N)? ", (A+i)->topic, (A+i)->questionNumber, (A+i)->question, (A+i)->choice1, (A+i)->choice2, (A+i)->choice3, (A+i)->answer);
		scanf(" %c", &c);
		if(c == 121 || c == 89) // y or Y
		{
			// move succeeding records to the deleted position
			for(d = i; d < s; d++)
			{
				strcpy(((A+d)->topic), (A+(d+1))->topic);
				(A+d)->questionNumber = (A+(d+1))->questionNumber;
				strcpy(((A+d)->question), (A+(d+1))->question);
				strcpy(((A+d)->choice1), (A+(d+1))->choice1);
				strcpy(((A+d)->choice2), (A+(d+1))->choice2);
				strcpy(((A+d)->choice3), (A+(d+1))->choice3);
				strcpy(((A+d)->answer), (A+(d+1))->answer);
			}
			t = 0;
			s--; // decrement size
		}
		else
		{
			i++;
			t = 1;
		}
	}while(i < s && t);
	
	return s;
} // fix logic

void
importData(struct record *A, int s)
{
	char filename[30];
	FILE *fp;
	int i;
	
	printf("Input filename: ");
	scanf("%s", filename);

	if((fp=fopen(filename, "r")) == NULL) {
		printf("ERROR: %s does not exist.\n", filename);
		exit(1);
	}
	else
		printf("%s was opened successfully.\n", filename);

	fclose(fp);
	return 0;
}

void
exportData(struct record *A, int s)
{
	char filename[30];
	FILE*fp;
	int i;
	
	printf("Input filename: ");
	scanf("%s", filename);
	fp=fopen(filename, "w");
	for(i=0;i<s;i++){
		fprintf(fp,"%s\n%d\n%s\n%s\n%s\n%s\n%s", A[i].topic, A[i].questionNumber, 
		A[i].question, A[i].choice1, A[i].choice2, A[i].choice3, A[i].answer);	
	}
	
	fclose(fp);
}
// intial run for user
// system clear code |  system("cls");
// get input code | getch();

/* showMaster allows the program to display the three foundational features of the Quiz Game
	@feature - "Manage Data"
	@feature - "Play"
	@feature - "Exit"
*/ 
int 
showMaster(char password[], struct record *A, int s){
	
	int choice = 0;
	int i;
	// MASTER MAIN MENU
	printf("\n		\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3\n\n");
	printf("		\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB\n\n");
	printf("		\xDB\xDB\xDB\xDB\xB2 1| Manage Data     	  \xB2\xDB\xDB\xDB\xDB\n\n");
	printf("		\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB\n\n");
	printf("		\xDB\xDB\xDB\xDB\xB2 2| Play                     \xB2\xDB\xDB\xDB\xDB\n\n");
	printf("		\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB\n\n");
	printf("		\xDB\xDB\xDB\xDB\xB2 3| Exit                     \xB2\xDB\xDB\xDB\xDB\n\n");
	printf("		\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB\n\n");
	printf("		\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3\n");
	printf("password = %s", password);	
	printf("\nPlease enter your choice : ");
	scanf("%d", &choice);
	
	return choice;
}

/* getPassword allows the user to input a password in order to access the Records
	@param *password - points to the address of String20 password
*/ 
int
getPassword(char *password){
	
	// password is set to ""
	
	char temp[20];
	int i=0;
	char c;
	char ch2, ch3;
	// password feature
		printf("%d", strlen(password));
			if(strlen(password)==0)
			{
				printf("There is no existing ADMIN password, please enter one: ");
//				while((ch2=_getch())!=13) {
//					password[i]=ch2;
//					i++;
//					printf("*");
//				}
//				password[i]='\0';
				for(i=0;i<8;i++) {					
			 		ch2=getch();
		 			password[i] = ch2;
			 		ch2 = '*';
			 		printf("%c", ch2);
			 	}
				 password[i]='\0';
				 return 1;
				 	
			} else {
				printf("Please enter the existing ADMIN password: %s", password);
				scanf("%s", temp);
				if((strcmp(password, temp))==0) { // correct password
					printf("correct password");
					printf("\ntype any key and press enter to continue");
					scanf(" %c", &ch3); 
					return 1;
				} else { // wrong password
					printf("incorrect password");
					printf("\ntype any key and press enter to continue");
					scanf(" %c", &ch3);
					return 0;
				}
			}
		// password feature
}

/* showManageDataMenu provides the skeleton for the "Manage Data" menu
	@param *A - points to the first index address of the array of records passed to the function
	@param s - is the size of the array of records passed
	@param *password - points to the address of String20 password
*/ 
int 
showManageDataMenu(struct record *A, int s, int valid){
	int choice,temp,cmp,i;
	char ch;
	printf("\nvalid = %d", valid);
	do
	{ 	
		choice = showManageDataSubMenu();
		switch(choice)
		{
			case 1:
			{
				// add record feature
				s=addStruct(A, s);
				break;
			}
			case 2:
			{
				// display records feature
				displayStruct(A, s);
				break;
			}
			case 3:
			{
				// edit record feature
				editStruct(A, s);
				break;
			}
			case 4:
			{
				// delete a record feature
				deleteStruct(A, s);
				break;
			}
			case 5:
			{
				// import data feature
				// read and/or write text file
				break;
			}
			case 6:
			{
				// export data feature
				// read and/or write text file
				break;
			}
			case 7:
			{
				// go back to main menu feature
				break;
			}
		}
	}while(choice>7);
	
	return choice;
}

/* showManageDataSubMenu provides the interface for the user to either add, display, edit, delete, import, export, records
	@param *A - points to the first index address of the array of records passed to the function
	@param s - is the size of the array of records passed
*/ 
int 
showManageDataSubMenu(){
	int selected;
	
	do
	{
//		system("cls");
		printf("\n		\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MANAGE DATA \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2 1| Add a Record    	  \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2 2| View Records             \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2 3| Edit a Record            \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2 4| Delete a Record          \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2 5| Import Data              \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2 6| Export Data              \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2 7| Go back to MAIN MENU     \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3\n");;
		printf("\nPlease enter your choice : ");
		scanf("%d", &selected);
	}while((selected<1)||(selected>7));
	
	return selected;
}

/* play allows the user to answer random questions under a certain topic choice
	@param *A - points to the first index address of the array of records passed to the function
	@param s - is the size of the array of records passed
*/ 
void
play(struct record *A, int s, struct score *B, int t){
	FILE *fp;
	String30 playerCurrent;
	int i, accScore;
	char ch;

	// load "score.txt" file
	fp=fopen("score.txt", "wb+");

	// ask for player name
		printf("Enter your player name : ");
		scanf("%c", &ch);
		getString30(&playerCurrent);
		
//		if player_current not/is in players?
		
		
	// choose from topics
		
	// display random question (under topic)
	
	// answer question
		// if correct
			// add score
		// else wrong
			// "sorry" message	
			// ask for another topic
	
	// display end game option
		// if chosen
			// message
			// accumulated score
			// go back to menu
		// else go back to answer question
	fclose(fp);
}
// view scores function

// exit quiz game menu function?

/* showQuizGameMenu allows the user to answer random questions under a certain topic choice
	@param *A - points to the first index address of the array of records passed to the function
	@param s - is the size of the array of records passed
*/
int 
showQuizGameMenu(struct record *A, int s, struct score *B, int t){
	int choice,temp;
	do
	{
		// read "score.txt" file
		choice = showQuizGameSubMenu();
		switch(choice)
		{
			case 1:
			{
				// play feature
				play(A,s,B,t);
				break;
			}
			case 2:
			{
				// view scores feature
				// viewScores();
				break;
			}
			case 3:
			{
				// exit feature
				break;
			}
		}
	}while(choice>4);
	
	return choice;
}

int
showQuizGameSubMenu(){
	int selected;
	
	do{
		system("cls");
		printf("\n		\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2 1| Play            	  \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2 2| View Scores              \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2 3| Exit                     \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3\n");
		printf("\nPlease enter your choice : ");
		scanf("%d", &selected);
	}while((selected<1)||(selected>4));
	
	return selected;
}

int 
main() {
	 
	char password[40];
	strcpy(password, "\0");

	struct record quizRecord[SIZE]; // struct for the amount of Quiz Questions
	struct score quizScores[SIZE]; // struct for the amount of playes and their scores
	int choice, valid;
	int flag = 1, temp = 0;
	
	while(flag){
		choice = showMaster(password, quizRecord, 2);
		switch(choice)
		{
			case 1: 
			{
				do{
					valid = getPassword(password);
				}while(valid!=1);
				
				showManageDataMenu(quizRecord, 2, valid);	
			
				break;
			}
			case 2: 
			{
				showQuizGameMenu(quizRecord, SIZE, quizScores, 2);
				break;
			}
			case 3:
			{
				system("cls");
				printf("THANKS FOR PLAYING!");
				flag = 0;
				break;
			}
			default:
			{
				printf("> Invalid Input\n");
				printf("Please enter any key to proceed with another choice : ");
				scanf(" %c", &temp);
//				system("cls");
				break;
			}
		}
	}
	return 0;
}


// View Scores

// Exit

/* EXIT SEGMENT */


