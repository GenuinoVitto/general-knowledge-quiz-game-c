#include <stdio.h>
#include <conio.h>
/*
Author: Jose Mari Victorio G. Genuino
Date Started: 7 February 2023
Date Finished: --
Purpose: QUIZ GAME - [CCPROG2] Machine Project 
*/


// prototypes
showMaster();
showManageDataMenu();
showManageDataSubMenu();
showQuizGameMenu();
showQuizGameSubMenu();

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
	{
		choice = showManageDataSubMenu();
		switch(choice)
		{
			case 1:
			{
				// add record feature
				break;
			}
			case 2:
			{
				// edit record feature
				break;
			}
			case 3:
			{
				// delete a record feature
				break;
			}
			case 4:
			{
				// import data feature
				break;
			}
			case 5:
			{
				// export data feature
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


// add a record

// edit a record

// delete a record

// import data

// export data

// struct for questions record

// display for questions

// go back to main menu

/* QUIZ GAME SEGMENT*/

// Play
// structs

typedef topic char[20];
typedef question char [150];
typedef choice char [30];
typedef answer char [30];

struct record {
		topic;
		int questionNumber;
		question n[150];
		choice option1;
		choice option2;
		choice option3;
		answer;
	};

// View Scores

// Exit

/* EXIT SEGMENT */


// Preliminary outline of functions to be created


