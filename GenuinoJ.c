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

//#define SIZE 50

// prototypes
showMaster();
showManageDataMenu();
showManageDataSubMenu();
showQuizGameMenu();
showQuizGameSubMenu();

// typedefs
typedef char String20[20];
typedef char String30[30];
typedef char Sentence[150];

/* struct record
	- 
*/
struct record {
	String20 topic;
	int question_number;
	Sentence question;
	String30 choice1;
	String30 choice2;
	String30 choice3;
	String30 answer;
};

/* struct score
*/
struct score {
	int row_num;
	String20 player_name;
	int score;
};

// implement player name array and/or struct 
// implement linear or binary search 
// check hands on 2 and hands on 1 exams

/* getString is a void function that allows the user to to input a sentence
	@param *ptr - points to address of passed String30 variable instance
*/ 
void
getString(String30 *ptr)
{
	char ch;
	int i = 0;
	String30 Sentence;
	
	do
	{
		scanf("%c", &ch);
		
		if(ch != '\n')
		{
			menu[i] = ch;
			i++;
			menu[i] = '\0';
		}
	}while (i < 51 && ch != '\n');
	
	strcpy(*ptr, Sentence);
} // fix logic of parameters

/* getInput allows the user to input a record for the Quiz Game
	@param *A - points to the first index address of the array of records passed to the function
	@param s - is the size of the array of records passed
*/ 
void
getInput(struct menuRecord *A, int s)
{
	int i, current = s-1;
	char c;
	
	if(((A+current)->time) > 0) // for adding 1 record, check if time has value
	{
		printf("\nEnter time (1, 2 or 3): ");
		scanf("%d", &(A+s)->time);
		scanf("%c", &c); // for new line in between int and characters
		printf("Enter menu name: ");
		getString(&((A+s)->name));
		printf("Enter price: ");
		scanf("%f", &(A+s)->price);
	}
	else
	{
		for(i = 0; i < s; i++)
		{
			printf("ITEM # %i", i+1);
			printf("\nEnter time (1, 2 or 3): ");
			scanf("%d", &(A+i)->time);
			scanf("%c", &c); // for new line in between int and characters
			printf("Enter menu name: ");
			getString(&((A+i)->name));
			printf("Enter price: ");
			scanf("%f", &(A+i)->price);
		}
	}
} // fix logic

void
displayStruct(struct menuRecord A[], int s)
{
	int i, j;
	String50 schedule;
	printf("\n%-10s %-20s %-8s\n", "Time", "Menu", "Price");
	
	for(j = 0; j < 4; j++) // loop for each TIME
	{
		switch(j) // conditional for 
		{
			case 1: strcpy(schedule, "Breakfast"); break;
			case 2: strcpy(schedule, "Lunch"); break;
			case 3: strcpy(schedule, "Dinner"); break;
			default: strcpy(schedule, "NA");
		}
		
		for(i=0; i < s; i++)
		{
			if(((A+i)->time) == j)
			{
				printf("%-10s %-20s Php %-5.2f\n", schedule, (A+i)->name, (A+i)->price);
			}
		}
	}
}

int
addStruct(struct menuRecord *A, int s)
{
	getInput(A, s);
	return s + 1;
} // fix logic

void
editStruct(struct menuRecord *A, int s)
{
	int i = 0;
	int t = 1;
	char c, nl;
	
	do{
		printf("EDIT %-2i %-20s Php %-5.2f ?", (A+i)->time, (A+i)->name, (A+i)->price);
		scanf(" %c", &c);
		if(c == 121) // y
		{
			printf("\nEnter time (1, 2 or 3): ");
			scanf("%d", &(A+i)->time);
			scanf("%c", &nl); // for new line in between int and characters
			printf("Enter menu name: ");
			getString(&((A+i)->name));
			printf("Enter price: ");
			scanf("%f", &(A+i)->price);
			t = 0;
		}
		else
		{
			i++;
			t = 1;
		}
	}while(i < s && t);
} // fix logic

int
deleteStruct(struct menuRecord *A, int s)
{
	int i = 0;
	int t = 1;
	int d; // deleted index
	char c;
	
	do{
		printf("DELETE %-2i %-20s Php %-5.2f ? ", (A+i)->time, (A+i)->name, (A+i)->price);
		scanf(" %c", &c);
		if(c == 121)
		{
			// move succeeding records to the deleted position
			for(d = i; d < s; d++)
			{
				(A+d)->time = (A+(d+1))->time;
				strcpy(((A+d)->name), (A+(d+1))->name);
				(A+d)->price = (A+(d+1))->price;
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

int 
showManageDataMenu(){
	int choice,temp;
	do
	{ // vv implement password feature here vv
		choice = showManageDataSubMenu();
		switch(choice)
		{
			case 1:
			{
				// add record feature
				addStruct(// pass record pointer, int SIZE)
				break;
			}
			case 2:
			{
				// edit record feature
				editStruct(// pass record pointer, int SIZE)
				break;
			}
			case 3:
			{
				// delete a record feature
				deleteStruct(// pass record pointer, int SIZE)
				break;
			}
			case 4:
			{
				// import data feature
				// read and/or write text file
				break;
			}
			case 5:
			{
				// export data feature
				// read and/or write text file
				break;
			}
			case 6:
			{
				// go back to main menu feature
				break;
			}
		}
	}while(choice>6);
	
	return choice;
}

int 
showManageDataSubMenu(){
	int selected;
	
	do
	{
		system("cls");
		printf("\n		\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MANAGE DATA \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2 1| Add a Record    	  \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2 2| Edit a Record            \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2 3| Delete a Record          \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2 4| Import Data              \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2 5| Export Data              \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2 6| Go back to MAIN MENU     \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3\n");;
		printf("\nPlease enter your choice : ");
		scanf("%d", &selected);
	}while((selected<1)||(selected>7));
	
	return selected;
}

int 
showQuizGameMenu(){
	int choice,temp;
	do
	{
		choice = showQuizGameSubMenu();
		switch(choice)
		{
			case 1:
			{
				// play feature
				break;
			}
			case 2:
			{
				// view scores feature
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
	
	char password[10]; 
	
	struct record quizRecord[SIZE];
	
	int choice;
	
	int flag = 1, temp = 0;
	
	while(flag){
		choice = showMaster();
		switch(choice)
		{
			case 1: 
			{
				showManageDataMenu();
				break;
			}
			case 2: 
			{
				showQuizGameMenu();
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

// Menu options and transitions

/* MANAGE DATA SEGMENT*/

// ask for a password [password entry]
//	char password[20], ch;
//	int i;
//	
//	do{
//		printf("Enter the password <any 20 characters> : ");
//	
//		for(i=0;i<20;i++) {
//			ch = getch();
//			password[i] = ch;
//			ch = "*";
//			printf("%c", ch);
//		}	
//	}while()
	// password entry
	// password store

// import data

// export data

// struct for questions record

// display for questions

// go back to main menu

/* QUIZ GAME SEGMENT*/

// Play
// structs

// View Scores

// Exit

/* EXIT SEGMENT */


// Preliminary outline of functions to be created


