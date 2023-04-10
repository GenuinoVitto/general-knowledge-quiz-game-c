// #includes
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

/***************************General Knowledge Quiz Game*****************************
Author: Jose Mari Victorio G. Genuino
Date Started: 7 February 2023
Date Finished: 10 April 2023 
Purpose: CCPROG2 [Machine Project]
***********************************************************************************/

/********************************Acknowledgement************************************
************************************************************************************
This is to certify that this project is my own work, based on my personal
efforts in studying and applying the concepts learned. I have constructed the
functions and their
respective algorithms and corresponding code by myself. The program was run,
tested, and debugged
by my own efforts. I further certify that I have not copied in part or whole or
otherwise plagiarized the
work of other students and/or persons.
***********************************************************************************
**********************************************************************************/

/* The following are the structures defined using method 2 */
	
// struct that will store data about a quiz question
struct record {
	char topic[20];
	int questionNumber;
	char question[150];
	char choice1[30];
	char choice2[30];
	char choice3[30];
	char answer[30];
};
// struct that will store data about a player and his/her score record
struct score {
	int rowNum;
	char playerName[20];
	int score;
};
/* The following are the function prototypes for the functions used in this project 
	disclaimer: all function prototypes are arranged in alphabetical order 
*/
//int addRecord(struct record *A, int s);
//int compareTwoString(char a[], char b[]);
//void corePlay(struct record *A, int s, struct score *B, int t);
//int deleteRecord(struct record *A, int s);
//void editRecord(struct record *A, int s);
//void exit();
//void exportData(struct record *A, int s);
//void getInput(struct record *A, int s);
//int getPassword(char *password[]);
//void getSentence(char *ptr);
//void getString20(char *ptr);
//void getString30(char *ptr);
//void importData(struct record *A, int s);
//int linearSearch(char *param1, char *param2, struct record A[], int s);
//void manageData(struct record *A, int s);
//void play(struct record *A, int s, struct score *B, int t);
//int randomNumber(int minNum, int maxNum);
//void showAll(struct record A[], int s);
//int showMainMenu(char password[]);
//int showManageDataMenu();
//int showPlayMenu();
//void showRecord(struct record A[], int index);
//void showScore(struct score *B, int t);

/* showMainMenu allows the program to display the three foundational features of the Quiz Game
	@feature - "Manage Data"
	@feature - "Play"
	@feature - "Exit"
*/ 
int showMainMenu(char password[]){
	int choice;
	system("cls");
	printf("password = %s", password);
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
/* getPassword allows the user to input a password in order to access the Records and returns an integer
	@param *password[] - points to the address of char array password
*/ 
int getPassword(char *password[]){
	
	char userEntry[20];
	int isVerified, i=0;
	char c, d;
	
	if(strlen(password)==0){
		printf("ADMIN password does not exist.\n");
		printf("Please enter one : ");
			do{
				c=getch();
				if(c==127||c==8){
					if(i!=0){
						i--;
						printf("\b \b");
					}
				} else {
					userEntry[i]=c;
					printf("*");
					i++;
				}
			}while(i<8&&c!='\r');
		
		userEntry[i-1]='\0'; // remove "enter" input from userEntry for string comparison
		printf("\nYou entered password : %s\n", userEntry);
		strcpy(password, userEntry);
	} else { // compare with existing password
		printf("ADMIN password exists.\n");
		printf("Please enter the existing password : ");
		
		do{
			c=getch();
			if(c==127||c==8){
				if(i!=0){
					i--;
					printf("\b \b");
				}
			} else {
				userEntry[i]=c;
				printf("*");
				i++;
			}
		}while(i<8&&c!='\r');
		userEntry[i-1]='\0'; // remove "enter" input from userEntry for string comparison
		
		if((strcmp(password,userEntry))==0){
			printf("\nVerified...");
			printf("Access granted!\n");
			return 1; // enter manageData
		} else {
			printf("\nNot Verified...");
			printf("Access denied!\n");
			printf("Please input the correct password.\n");
			printf("\nType y or Y to enter another password.\n");
			printf("\nType any other character to go back to MAIN MENU.\n");
			scanf(" %c",&d);
			if(d=='y'||d=='Y')
				return 0; // enter another password
			else
				return 2; // go back to MAIN MENU
		}
	}
	return 1;
}
/* getString20 is a void function that allows the user to to input a char array of size 20
	@param *ptr - points to address of passed char array instance
*/ 
void getString20(char *ptr){
	int i=0;
	char c, s[20];
	
	do{
		c=getch();
		if(c==127||c==8){
			if(i!=0){
				i--;
				printf("\b \b");
			}
		} else {
			s[i]=c;
			i++;
			printf("%c",c);
		}
	}while(i<20&&c!='\r');
	s[i-1]='\0';
	strcpy(ptr,s);
}
/* getString30 is a void function that allows the user to to input a char array of size 30
	@param *ptr - points to address of passed char array instance
*/
void getString30(char *ptr){
	int i=0;
	char c, s[30];
	
	do{
		c=getch();
		if(c==127||c==8){
			if(i!=0){
				i--;
				printf("\b \b");
			}
		} else {
			s[i]=c;
			i++;
			printf("%c",c);
		}
	}while(i<30&&c!='\r');
	s[i-1]='\0';
	strcpy(ptr,s);
}
/* getSentence is a void function that allows the user to to input a char array of size 150
	@param *ptr - points to address of passed char array instance
*/
void getSentence(char *ptr){
	int i=0;
	char c, s[150];
	
	do{
		c=getch();
		if(c==127||c==8){
			if(i!=0){
				i--;
				printf("\b \b");
			}
		} else {
			s[i]=c;
			i++;
			printf("%c",c);
		}
	}while(i<150&&c!='\r');
	s[i-1]='\0';
	strcpy(ptr,s);
}
/* linearSearch is a void function that allows the program to locate a record given param1 or param2
	@param *param1 - points to address of passed char variable instance
	@param *param2 - points to address of passed char variable instance
	@param struct record A[] - points to the first index address of the array of records passed to the function
	@param s - is the size of the array of records passed 
*/
int linearSearch(char *param1, char *param2, struct record A[], int s){
	int i, cmp;
	for(i=0;i<s;i++){
		printf("\n\n\ncompare : %s with : %s \n%s \n%s\n",A[0].question,param1, A[0].question, param1);
		cmp=strcmp(A[i].question, param1);
		if(cmp==0){
			cmp=strcmp(A[i].answer, param2);
			if(cmp==0){
				return i;
			}
		} else {
			return -1;
		}
	}
}
/* showRecord is a void function that allows the user to view a record given the index of it
	@param struct record A[] - points to the first index address of the array of records passed to the function
	@param index - is the index of the record passed 
*/
void showRecord(struct record A[], int index){
	printf("\nQuestion Topic %s", (A+index)->topic);
	printf("\nQuestion Number #%d", (A+index)->questionNumber);
	printf("\n\n%s", (A+index)->question);
	printf("\n\nA.%s\t\tB.%s\n\nC.%s\t\tAnswer = %s", (A+index)->choice1, (A+index)->choice2, (A+index)->choice3, (A+index)->answer);
}
/* showAll is a void function that allows the user to view all records 
	@param struct record A[] - points to the first index address of the array of records passed to the function
	@param s - is the size of the array of records passed
*/
void showAll(struct record A[], int s){
	int i;
	
	for(i=0;i<s;i++){
		printf("\nQuestion Topic %s", (A+i)->topic);
		printf("\nQuestion Number #%d", (A+i)->questionNumber);
		printf("\n\n%s", (A+i)->question);
		printf("\n\nA.%s\t\tB.%s\n\nC.%s\t\tAnswer = %s", (A+i)->choice1, (A+i)->choice2, (A+i)->choice3, (A+i)->answer);
	}
}
/* getInput is a void function that allows the user to input a record for the Quiz Game given certain conditions
	@param *A - points to the first index address of the array of records passed to the function
	@param s - is the size of the array of records passed
*/
void getInput(struct record *A, int s){
	int i=0, current=s-1, found=0;
	char c;
	struct record *ptr;
	
	char userEntryQuestion[150];
	char userEntryAnswer[30];
	 
	do{
		//---------------------------------------------------
		printf("Enter a question: ");
		getSentence(userEntryQuestion);
		
		printf("Enter an answer: ");
		getString30(userEntryAnswer);
		
		
		printf("\nQuestion Inputted: %s", userEntryQuestion);
		printf("\nAnswer Inputted: %s", userEntryAnswer);
		
		found=linearSearch(userEntryQuestion,userEntryAnswer,A,s); // returns index of found Q&A, if not found=-1
		printf("\nfound = %d", found);
		if(found!=-1){
			printf("\nThe entered Question and Answer has already been listed in the records.\n");
			showRecord(A, found);
			i--;
		} else {
			printf("\nThe entered Question and Answer does not exist in the records.\n");
			printf("ITEM #%d", i+1);
			printf("\nEnter topic: ");
			getString20(&((A+i)->topic));
			
			(A+i)->questionNumber=i+1;
			strcpy(&((A+i)->question),userEntryQuestion);
		
			printf("Enter choice 1: ");
			getString30(&((A+i)->choice1));
			
			printf("Enter choice 2: ");
			getString30(&((A+i)->choice2));
			
			printf("Enter choice 3: ");
			getString30(&((A+i)->choice3));
			
			strcpy(&((A+i)->answer),userEntryAnswer);
		}
		printf("\nExisting question: %s", (A+i)->question);
		i++;
		printf("\nWould you like to enter another Q&A? : ");
		scanf(" %c", &c);
		//---------------------------------------------------		
	}while(i<s&&(c=='y'||c=='Y')); //implement feature where you could change value of s 
	
}
/* addRecord allows the user to input additional records for the Quiz Game and returns an integer
	@param *A - points to the first index address of the array of records passed to the function
	@param s - is the size of the array of records passed
*/ 
int addRecord(struct record *A, int s){
	getInput(A,s);
	return s+1; // implement pointer to s
}
/* compareTwoString is just proxy code for the strcmp(); function 
	@param a[] - is a char array
	@param b[] - is a char array
*/
int compareTwoString(char a[], char b[]){  
	int flag=0,i=0;    
	while(a[i]!='\0' &&b[i]!='\0'){  
	   if(a[i]!=b[i]){
	   		flag=1;  
	    	break;
		}  
	   i++;  
	} 
	if(a[i]!='\0'||b[i]!='\0')
		return 1;
	if(flag==0)  
		return 0;  
	else  
		return 1;  
}  
/* editRecord is a void function that allows the user to edit a record for the Quiz Game
	@param *A - points to the first index address of the array of records passed to the function
	@param s - is the size of the array of records passed
*/
void editRecord(struct record *A, int s){
	int ctr=0,cmp,cmp2,i,j,k;
	int l,found,choiceQuestion;
	char c,dump,dump2,choiceTopic[20],choiceField[20];
	
	struct record res[s];
	int resSize=0;
	// display all unique topics
	for(i = 0; i < s; i++){
        ctr = 0;
        for(j = 0; j < s; j++){
        	cmp=strcmp((A+i)->topic,(A+j)->topic);
            if(cmp==0){
                ctr++;
            }
        }
        if(ctr > 0){
            found = 0;
            for(k = 0; k < resSize; k++){
            	cmp=strcmp((res+k)->topic,(A+i)->topic);
                if(cmp==0){
                    found = 1;
                }
            }
            if(!found){
                strcpy(res[resSize++].topic,(A+i)->topic);
            }
        }
    }
    for(i = 0; i < resSize; i++){
    	int length=strlen(res[i].topic);
        for(j=0;j<length;j++){
        	printf("%c",res[i].topic[j]);
		}
    }
    
	
	// choose topic
	printf("\nPlease choose a topic : ");
	getString20(choiceTopic);
	scanf("%c",&dump);
	
	for(l=0;l<s;l++){
		cmp=strcmp((A+l)->topic,choiceTopic);
		if(!cmp){
			showRecord(A,l);
		}
	}
	
	printf("\nPlease enter the question number of your desired question : ");
	scanf("%d", &choiceQuestion);
	
	for(l=0;l<s;l++){
		if(choiceQuestion==(A+l)->questionNumber){
			printf("\nEditing...");
			showRecord(A,choiceQuestion);
			printf("\nWhich field do you want to edit? : ");
			getString20(choiceField);
			scanf("%c",&dump2);
			int cmpTopic=strcmp("topic",choiceField);
			printf("choiceField length = %d", strlen(choiceField));
			printf("\ncmpTopic = %d",cmpTopic);
			if(cmpTopic==0){
				printf("\nEnter topic : ");
				getString20(&((A+l)->topic));
			}
			int cmpQuestion=strcmp("question",choiceField);
			if(cmpQuestion==0){
				printf("\nEnter question : ");
				getSentence(&((A+l)->question));
			}
			int cmpChoiceOne=strcmp("choice1",choiceField);
			if(cmpChoiceOne==0){
				printf("\nEnter choice 1 : ");
				getString30(&((A+l)->choice1));
			}
			int cmpChoiceTwo=strcmp("choice2",choiceField);
			if(cmpChoiceTwo==0){
				printf("\nEnter choice 2 : ");
				getString30(&((A+l)->choice2));
			}
			int cmpChoiceThree=strcmp("choice3",choiceField);
			if(cmpChoiceThree==0){
				printf("\nEnter choice 3 : ");
				getString30(&((A+l)->choice3));
			}
			int cmpAnswer=strcmp("answer",choiceField);
			if(cmpAnswer==0){
				printf("\nEnter answer : ");
				getString30(&((A+l)->answer));
			}
			break;
		}
	}
//	scanf(" %c", &c);	
}
/* deleteRecord allows the user to delete a record for the Quiz Game and returns an integer
	@param *A - points to the first index address of the array of records passed to the function
	@param s - is the size of the array of records passed
*/ 
//int deleteRecord(struct record *A, int s){
//	
//}
/* importData is a void function that allows the user to read a list of entries in a given text file
	@param *A - points to the first index address of the array of records passed to the function
	@param s - is the size of the array of records passed
//*/ 
//void importData(struct record *A, int s){
//	char filename[30];
//	int i=0, flag=1;
//	// file pointer declaration
//	FILE *fp;
//	
//	while(flag){
//		fprintf(stdout, "Input filename : ");
//		fscanf(stdin, "%s", filename);
//		if((fp=fopen(filename, "r"))==NULL){
//			fprintf(stderr, "ERROR: %s does not exist.\n", filename);
//			fprintf(stdout, "Please try inputting a different filename.");
//		} else {
//			do{
//				if((fscanf(fp, "%s\n%d\n%s\n%s\n%s\n%s\n%s", &((A+i)->topic), &((A+i)->questionNumber), &((A+i)->question),
//					&((A+i)->choice1), &((A+i)->choice2), &((A+i)->choice3), &((A+i)->answer)))==7){
//					fprintf(stdout, "\nA[%d] = %s\n%d\n%s\n%s\n%s\n%s\n%s", (A+i)->topic, (A+i)->questionNumber, (A+i)->question,
//					(A+i)->choice1, (A+i)->choice2, (A+i)->choice3, (A+i)->answer);
//				}
//				i++;
//			}while(i<s);
//			flag=0;
//		}
//	}
//	fclose(fp);
//}
/* exportData is a void function that allows the user to write a list of entries to a given text file
	@param *A - points to the first index address of the array of records passed to the function
	@param s - is the size of the array of records passed
*/ 
//void exportData(struct record *A, int s){
//	char filename[30];
//	FILE *fp;
//	
//	printf("Input filename : ");
//	getString30(filename);
//	
//	if((fp=fopen(filename, "w"))==NULL){ // open in "write" mode
//		printf("ERROR: %s does not exist.\n", filename);
//		exit(1);
//	} else {
//		printf("%s was opened successfully.\n", filename);
//	}
//	fclose(fp);
//}
/* showManageDataMenu provides the interface for the user to either add, display, edit, delete, import, export, records and returns an integer
*/ 
int showManageDataMenu(){
	int choice;
	do{
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
		printf("		\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3\n");
		printf("\nPlease enter your choice : ");
		scanf("%d", &choice);
	}while((choice<1)||(choice>7));
	
	return choice;
	
}
/* manageData is a void function that provides the skeleton for the "Manage Data" menu
	@param *A - points to the first index address of the array of records passed to the function
	@param s - is the size of the array of records passed
*/ 
void manageData(struct record *A, int s){
	int flag=1, choice;
	
	while(flag){
		choice=showManageDataMenu();
		switch(choice){
			case 1: // Add record
				{
					s=addRecord(A,s);
					break;
				}
			case 2: // View record
				{
					showAll(A,s);
					break;
				}
			case 3: // Edit record
				{
					editRecord(A,s);
					break;
				}
			case 4: // Delete record
				{
//					deleteRecord(A,s);
					break;
				}
			case 5: // Import data
				{
					importData(A,s);
					break;
				}
			case 6: // Export data
				{
//					exportData(A,s);
					break;
				}
			case 7: // Go back to MAIN MENU
				{
					flag=0;
					break;
				}
		}
	}
}
/* randomNumber allows the program to return a random number in a given range
	@param minNum - is the lower bound of the range
	@param maxNum - is the upper bound of the range
*/
//int randomNumber(int minNum, int maxNum){
//	int result=0,lowNum=0,highNum=0;
//	
//	if(minNum<maxNum){
//		lowNum=minNum;
//		highNum=maxNum+1;
//	} else {
//		lowNum=maxNum+1;
//		highNum=minNum;
//	}
//	srand(time(NULL));
//	result=(rand()%(highNum-lowNum))+lowNum;
//	
//	return result;
//}
/* corePlay is the core function of the play feature of this General Knowledge Quiz Game
	@param <param name-instance> - <description>
	@param <param name-instance> - <description>
*/
//void corePlay(struct record *A, int s, struct score *B, int t){
//	int accScore=0;
//	
//	int random=randomNumber(0,s);
//	char c, playerName[20];
//	printf("\nrandom = %d", random);
//	scanf(" %c",&c);
//	
//	do{
//		// ask for player name
//		printf("\nPlease enter your IGN (in-game name) : ");
//		getString20(playerName);
//		
//		// choose from topics
//		
//		// display random question (under topic)
//		
//		// answer 
//		
//		// score? or not?
//		if(cmp==0){
//			accScore++;
//		} else {
//			printf("\nSorry, the answer you chose is incorrect.");
//			// ask for another topic and generate another question
//			//--------------Input   Answer   Here-----------------
//		}
//		// keep displaying current score of player
//		printf("Current Score is %d", accScore);
//		
//		// display end game option
//		printf("\nWould you like to try again? : ");
//		scanf(" %c", &c);
//	}while(c=='y'||c=='Y');
//	
//	// if end game option is chosen, display message and acc score 
//	exit();
//	printf("\n\n");
//	showScore(B,t);
//	// Go back to Main Menu	
//}
/* showScores is a void function that allows the user to view all scores of the General Knowledge Quiz Game
	@param <param name-instance> - <description>
	@param <param name-instance> - <description>
*/
//void showScore(struct score *B, int t){
//	// read imported file?
//	int i;
//	for(i=0;i<t;i++){
//		printf("\n\tRow # %d\tPlayer Name : %s\tScore | %d", (B+i)->rowNum,(B+i)->playerName,(B+i)->score);
//	}
//}
/* showPlayMenu provides the interface for the user to either play, view scores, or go back to main menu and returns an integer
	@param <param name-instance> - <description>
	@param <param name-instance> - <description>
*/
//int showPlayMenu(){
//	int choice;
//	do{
////		system("cls");
//		printf("\n		\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MANAGE DATA \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3\n\n");
//		printf("		\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB\n\n");
//		printf("		\xDB\xDB\xDB\xDB\xB2 1| Play            	  \xB2\xDB\xDB\xDB\xDB\n\n");
//		printf("		\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB\n\n");
//		printf("		\xDB\xDB\xDB\xDB\xB2 2| View Scores              \xB2\xDB\xDB\xDB\xDB\n\n");
//		printf("		\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB\n\n");
//		printf("		\xDB\xDB\xDB\xDB\xB2 3| Exit                     \xB2\xDB\xDB\xDB\xDB\n\n");
//		printf("		\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB\n\n");
//		printf("		\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3\n");
//		printf("\nPlease enter your choice : ");
//		scanf("%d", &choice);
//	}while((choice<1)||(choice>3));
//	
//	return choice;
//}
/* play is a void function that provides the skeleton for the "Play" menu
	@param *A - points to the first index address of the array of records passed to the function
	@param s - is the size of the array of records passed
*/
//void play(struct record *A, int s, struct score *B, int t){
//	int flag=1, choice;
//	char c;
//	
//	while(flag){
//		choice=showPlayMenu();
//		switch(choice){
//			case 1:
//				{
//					// core play 
//					corePlay(A,s,B,t);
//					break;
//				}
//			case 2:
//				{
//					// view scores 
//					showScore(B,t);
//					break;
//				}
//			case 3:
//				{
//					// Go back to MAIN MENU
//					flag=0; 
//					break;
//				}
//			default:	
//				{
//					system("cls");
//					printf("Invalid Input\n");
//					printf("Please enter any letter to proceed with another choice : ");
//					scanf(" %c", &c);
//					break;
//				} 
//		}
//	}
//}
/* exit provides the interface for user exit
*/
//void exit(){
//		system("cls");
//		printf("\n		\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2    EXIT    \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3\n\n");
//		printf("		\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB\n\n");
//		printf("		\xDB\xDB\xDB\xDB\xB2     Thanks for playing!     \xB2\xDB\xDB\xDB\xDB\n\n");
//		printf("		\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB\n\n");
//		printf("		\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3\n");
//}
/* this is the main function of this General Knowledge Quiz Game
*/
int main(){
	struct record quizRecord[5];
	struct score quizScores[5];
	int flag=1, choice, isVerified=0; // verified for password
	char password[20]={'\0'};
	char c;
//	int s=; determine size 's' at the end of development 
	while(flag){
		choice=showMainMenu(password);
		switch(choice){
			case 1: // "Manage Data"
				{
					// get password
					isVerified=0;
					while(isVerified==0){
						isVerified=getPassword(password);
						if(isVerified==1)
							manageData(quizRecord, 5); 
					}
					break;
				}
			case 2:
				{
					play(quizRecord,5,quizScores,5);
					break;	
				}
			case 3:
				{
//					exit();
					flag=0;
					break;
					
				}
			default:
				{
					system("cls");
					printf("Invalid Input\n");
					printf("Please enter any letter to proceed with another choice : ");
					scanf(" %c", &c);
					break;
				}
		}
	}
	
	return 0;
}
