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
getString20(String20 *ptr)
{
	char ch;
	int i = 0;
	String20 Sentence;
	
	do
	{
		scanf("%c", &ch);
		
		if(ch != '\n')
		{
			Sentence[i] = ch;
			i++;
			Sentence[i] = '\0';
		}
	}while (i < 21 && ch != '\n');
	
	strcpy(*ptr, Sentence);
} 

/* getString30 is a void function that allows the user to to input String30
	@param *ptr - points to address of passed String30 variable instance
*/
void
getString30(String30 *ptr)
{
	char ch;
	int i = 0;
	String30 Sentence;
	
	do
	{
		scanf("%c", &ch);
		
		if(ch != '\n')
		{
			Sentence[i] = ch;
			i++;
			Sentence[i] = '\0';
		}
	}while (i < 31 && ch != '\n');
	
	strcpy(*ptr, Sentence);
}

/* getSentence is a void function that allows the user to to input a Sentence
	@param *ptr - points to address of passed Sentence variable instance
*/
void
getSentence(Sentence *ptr)
{
	char ch;
	int i = 0;
	Sentence question;
	
	do
	{
		scanf("%c", &ch);
		
		if(ch != '\n')
		{
			question[i] = ch;
			i++;
			question[i] = '\0';
		}
	}while (i < 151 && ch != '\n');
	
	strcpy(*ptr, question);
}

/* getInput allows the user to input a record for the Quiz Game
	@param *A - points to the first index address of the array of records passed to the function
	@param s - is the size of the array of records passed
*/ 
void
getInput(struct record *A, int s)
{
	int i, current = s-1;
	char c;
	
	if(((A+current)->questionNumber) > 0) // for adding 1 record, check if time has value
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
	}
	else
	{
		for(i = 0; i < 1/*change value to s after testing*/; i++)
		{
			printf("ITEM # %i", i+1);
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
		}
	}
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
	
		for(i=0; i < 1/*change value to s after testing*/; i++)
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

// intial run for user
// system clear code |  system("cls");
// get input code | getch();

/* showMaster allows the program to display the three foundational features of the Quiz Game
	@feature - "Manage Data"
	@feature - "Play"
	@feature - "Exit"
*/ 
int 
showMaster(){
	
	int choice = 0;
	
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
	printf("\nPlease enter your choice : ");
	scanf("%d", &choice);
	
	return choice;
}

/* getPassword allows the user to input a password in order to access the Records
	@param *password - points to the address of String20 password
*/ 
void 
getPassword(char *password){
	
	// password is set to ""
	
	String20 temp;
	int i;
	char ch;
	// password feature
		printf("%d", strlen(password));
			if(strlen(password)==0)
			{
				printf("There is no existing password, please enter one :> : ");
				
				for(i=0;i<8;i++) {
			 		ch=getch();
		 			password[i] = ch;
			 		ch = '*';
			 		printf("%c", ch);
			 	}
				 password[i]='\0';
				 	
			} else {
				printf("Please enter the existing password :> %s", password);
				scanf("%s", temp);
				if((strcmp(password, temp))==0) {
					printf("correct password");
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
showManageDataMenu(struct record *A, int s){
	int choice,temp,cmp,i;
	char ch;
	
	do
	{ 	
		choice = showManageDataSubMenu();
		switch(choice)
		{
			case 1:
			{
				// add record feature
				addStruct(A, s);
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


//int
//Binary_Search(String param_lastname, String param_firstname, struct studentTag STUDENTS[], int nStudents)
//{
//    // Encode your solution.
//    int low=0, high=nStudents-1, mid, cmp;
//    int found = 0;
//    
//    while(!found&&low<=high){
//    	mid=low+(high-low)/2;
//    	cmp = strcmp(STUDENTS[mid].name.last, param_lastname);
//    	if(!cmp)
//    		cmp = strcmp(STUDENTS[mid].name.first, param_firstname);
//    	
//    // positive cmp means current is greater
//    	if(!cmp){
//    		found=1;
//		} else if (cmp>0){
//			high=mid-1;
//		} else {
//			low=mid+1;
//		}
////    	if(param_lastname == STUDENTS[mid].name.last && param_firstname == STUDENTS[mid].name.first)
////    		found = 1;
////    	else if(param_lastname < STUDENTS[mid].name.last && param_firstname < STUDENTS[mid].name.first)
////    		high=mid-1;
////		else
////			low=mid+1;
//	}
//	
//	if(found)
//		return mid;
//	else
//		return -1;
//}

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
	 
	char password[20];
	strcpy(password, "");

	struct record quizRecord[SIZE]; // struct for the amount of Quiz Questions
	struct score quizScores[SIZE]; // struct for the amount of playes and their scores
	int choice;
	
	int flag = 1, temp = 0;
	
	while(flag){
		choice = showMaster();
		switch(choice)
		{
			case 1: 
			{
				getPassword(password);
				showManageDataMenu(quizRecord, SIZE);
				break;
			}
			case 2: 
			{
				showQuizGameMenu(quizRecord, SIZE, quizScores, SIZE);
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
				temp=getch();
				system("cls");
				break;
			}
		}
	}
	return 0;
}


// View Scores

// Exit

/* EXIT SEGMENT */


