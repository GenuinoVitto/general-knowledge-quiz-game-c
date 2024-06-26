// #includes
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

/***************************General Knowledge Quiz Game*****************************

Author: Jose Mari Victorio G. Genuino
Date Started: 7 February 2023
Date Finished: 11 April 2023 
Purpose: CCPROG2 [Machine Project]

-------------------------------------Disclaimer------------------------------------ 
	Variable value checkers throughout the program may be found as in-line comments	
-----------------------------------------------------------------------------------
								
***********************************************************************************/

/********************************Acknowledgement************************************
************************************************************************************
	This is to certify that this project is my own work, based on my personal
	efforts in studying and applying the concepts learned. I have constructed the
	functions and their respective algorithms and corresponding code by myself. 
	The program was run, tested, and debugged by my own efforts. I further certify 
	that I have not copied in part or whole or otherwise plagiarized the work of 
	other students and/or persons.
											Jose Mari Victorio G. Genuino, 11944692
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
struct scoreRecord {
	int rowNum;
	char player[20];
	int score;
};

/* The following are the function prototypes for the functions used in this project 
	disclaimer: all function prototypes are arranged in alphabetical order 
*/
int addRecord(struct record *A, int s);
int compareTwoString(char a[], char b[]);
void corePlay(FILE *fp, struct record *A, int s, struct scoreRecord *B, int t);
int deleteRecord(struct record *A, int s);
void editRecord(struct record *A, int s);
void exportData(struct record *A, int s);
void getInput(struct record *A, int s);
int getPassword(char *password);
void getSentence(char *ptr);
void getString20(char *ptr);
void getString30(char *ptr);
void importData(struct record *A, int s);
int linearSearch(char *param1, char *param2, struct record A[], int s);
int linearSearchScore(char *param, struct scoreRecord B[], int s);
void manageData(struct record *A, int s);
void play(struct record *A, int s, struct scoreRecord *B, int t);
int randomNumber(int minNum, int maxNum);
void showAll(struct record A[], int s);
int showMainMenu(char password[]);
int showManageDataMenu();
int showPlayMenu();
void showRecord(struct record A[], int index);
void showRecord(struct record A[], int index);
void showScore(struct scoreRecord *B, int t);

/* showMainMenu allows the program to display the three foundational features of the Quiz Game
	@feature - "Manage Data"
	@feature - "Play"
	@feature - "Exit"
*/ 
int showMainMenu(char password[]){
	int choice;
	system("cls");
	
	/* for checking the set User ADMIN password
		printf("password = %s", password);
	*/
	
	printf("\n\n		\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3\n\n");
	printf("		\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB\n\n");
	printf("		\xDB\xDB\xDB\xDB\xB2 1| Manage Data     	  \xB2\xDB\xDB\xDB\xDB\n\n");
	printf("		\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB\n\n");
	printf("		\xDB\xDB\xDB\xDB\xB2 2| Play                     \xB2\xDB\xDB\xDB\xDB\n\n");
	printf("		\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB\n\n");
	printf("		\xDB\xDB\xDB\xDB\xB2 3| Exit                     \xB2\xDB\xDB\xDB\xDB\n\n");
	printf("		\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB\n\n");
	printf("		\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3\n");	
	printf("\n\t\tPlease enter your choice : ");
	scanf("%d", &choice);
	return choice;
}
/* getPassword allows the user to input a password in order to access the Records and returns an integer
	@param *password[] - points to the address of char array password
*/ 
int getPassword(char *password){
	char c, d, userEntry[20];
	int i=0;
	
	if(strlen(password)==0){ // if password has no value
		system("cls");
		printf("\n\t\t\t---------------------------------------------------\n");
		printf("\n\t\t\t---------- ADMIN password does not exist ----------\n");
		printf("\n\t\t\t---------------------------------------------------\n");
		printf("\n\t\t\t      Please enter one : ");
			
			// do-while loop for getting password
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
		
		/* to check User-entered password
			 printf("\n\t\t\t      You entered password : %s\n", userEntry);
		*/
		
		strcpy(password, userEntry);
		
	} else { // compare with existing password
		system("cls");
		printf("\n\t\t\t---------------------------------------------------\n");
		printf("\n\t\t\t-------------- ADMIN password exists --------------\n");
		printf("\n\t\t\t---------------------------------------------------\n");
		printf("\n\t\t\t      Please enter password : ");
			// do-while loop for getting password
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
			printf("\n\n\t\t\t---------------------------------------------------\n");
			printf("\n\t\t\t--------------  Verification Error! ---------------\n");
			printf("\n\t\t\t-------------- Sorry, Access Denied --------------\n");
			printf("\n\t\t\t---------------------------------------------------\n");
			printf("\n\t\t\t Type 'y' or 'Y' to enter another password.\n");
			printf("\n\t\t\t Type any other character to go back to MAIN MENU : ");
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
				printf("\b \b"); // take into account backspace
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
				printf("\b \b"); // take into account backspace
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
				printf("\b \b"); // take into account backspace
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
		
		/* for checking the strings being compared
			printf("\n\n\ncompare : %s with : %s \n%s \n%s\n",A[0].question,param1, A[0].question, param1);
		*/
		cmp=strcmp(A[i].question, param1);
		if(cmp==0){
			cmp=strcmp(A[i].answer, param2);
			if(cmp==0){
				return i; // return index if found
			}
		} else {
			return -1;
		}
	}
	return 0;
}
/* linearSearch is a void function that allows the program to locate a record given param
	@param *param - points to address of passed char variable instance
	@param struct record A[] - points to the first index address of the array of records passed to the function
	@param s - is the size of the array of records passed 
*/
int linearSearchScore(char *param, struct scoreRecord B[], int s){
	int i, cmp;
	for(i=0;i<s;i++){
		/* for checking the strings being compared
			printf("\n\n\ncompare : %s with : %s \n%s \n%s\n",A[0].question,param1, A[0].question, param1);
		*/
		cmp=strcmp(B[i].player, param);
		if(cmp==0){
			return i; // return index if found
		} else {
			return -1;
		}
	}
	return 0;
}
/* showRecord is a void function that allows the user to view a record given the index of it
	@param struct record A[] - points to the first index address of the array of records passed to the function
	@param index - is the index of the record passed 
*/
void showRecord(struct record A[], int index){
	printf("\n\t\t\t------------Question Number [%d]-----------\n", (A+index)->questionNumber);
	printf("\n\t\t\tQuestion Topic : %s", (A+index)->topic);
	printf("\n\n\t\t\tQuestion : %s", (A+index)->question);
	printf("\n\n\t\t\t- %s\t\t- %s\n\n\t\t\t- %s\t\tAnswer = %s", (A+index)->choice1, (A+index)->choice2, (A+index)->choice3, (A+index)->answer);
	printf("\n\n\t\t\t------------------------------------------\n");
}
/* showRecordPlay is a void function that allows the user to view a record without the answer given the index of it
	@param struct record A[] - points to the first index address of the array of records passed to the function
	@param index - is the index of the record passed 
*/
void showRecordPlay(struct record A[], int index){
	printf("\n\t\t\t------------Question Number [%d]-----------\n", (A+index)->questionNumber);
	printf("\n\t\t\tQuestion Topic : %s", (A+index)->topic);
	printf("\n\n\t\t\tQuestion : %s", (A+index)->question);
	printf("\n\n\t\t\t- %s\t\t- %s\n\n\t\t\t- %s", (A+index)->choice1, (A+index)->choice2, (A+index)->choice3);
	printf("\n\n\t\t\t------------------------------------------\n");
}
/* showAll is a void function that allows the user to view all records 
	@param struct record A[] - points to the first index address of the array of records passed to the function
	@param s - is the size of the array of records passed
*/
void showAll(struct record A[], int s){
	int i;
	char c;
	
	system("cls"); // clear screen
	for(i=0;i<s;i++){
		printf("\n\t\t\t------------Question Number [%d]-----------\n", (A+i)->questionNumber);
		printf("\n\t\t\tQuestion Topic : %s", (A+i)->topic);
		printf("\n\n\t\t\tQuestion : %s", (A+i)->question);
		printf("\n\n\t\t\t- %s\t\t- %s\n\n\t\t\t- %s\t\tAnswer = %s", (A+i)->choice1, (A+i)->choice2, (A+i)->choice3, (A+i)->answer);
		printf("\n\n\t\t\t------------------------------------------\n");
	}
	printf("\n\t\t\tPlease enter any letter to proceed : ");
	scanf(" %c", &c);
}
/* getInput is a void function that allows the user to input a record for the Quiz Game given certain conditions
	@param *A - points to the first index address of the array of records passed to the function
	@param s - is the size of the array of records passed
*/
void getInput(struct record *A, int s){
	int i=0, found=0;
	char c;
	// start from index of last element
	char userEntryQuestion[150];
	char userEntryAnswer[30];
	
	do{
		system("cls"); // clear screen
		printf("\n\t\t\t------------- Preliminary Check ------------\n");
		printf("\n\t\t\tEnter a question : ");
		getSentence(userEntryQuestion);
		printf("\n\n\t\t\t------------------------------------------\n");
		printf("\n\t\t\tEnter the answer to your question : ");
		getString30(userEntryAnswer);
		printf("\n\n\t\t\t------------------------------------------\n");
		
		/* for checking value of User-entered Question & Answer
		 	printf("\nQuestion Inputted: %s", userEntryQuestion);
		 	printf("\nAnswer Inputted: %s", userEntryAnswer); 
		*/
		
		// returns index of found Question & Answer, if not found=-1
		found=linearSearch(userEntryQuestion,userEntryAnswer,A,s); 
		
		/* for checking value of integer variable "found"
			printf("\nfound = %d", found);
		*/
		
		if(found!=-1){
			printf("\n\t\t\tThe entered Question & Answer already exists in the records.\n");
			showRecord(A, found);
			i--;
		} else {
			printf("\n\t\t\tThe entered Question & Answer does not exist in the records.\n");
			printf("\n\t\t\tGetting ITEM #%d...", i+1);
			printf("\n\n\t\t\tEnter the topic of your question : ");
			
			// Enter topic
			getString20(((A+i)->topic));
			// Question number
			(A+i)->questionNumber=i+1;
			strcpy(((A+i)->question),userEntryQuestion);
			// Enter Choice 1
			printf("\n\t\t\tEnter the 1st choice of your question : ");
			getString30(((A+i)->choice1));
			// Enter Choice 2
			printf("\n\t\t\tEnter the 2nd choice of your question : ");
			getString30(((A+i)->choice2));
			// Enter Choice 3
			printf("\n\t\t\tEnter the 3rd choice of your question : ");
			getString30(((A+i)->choice3));
			// Question Answer
			strcpy(((A+i)->answer),userEntryAnswer);
		}
		
		/* for checking the current question being inputted
			printf("\n\nExisting question: %s", (A+i)->question);
		*/
		
		i++;
		printf("\n\n\t\t\tWould you like to enter another Question & Answer?");
		printf("\n\n\t\t\tType 'y' or 'Y' to enter another.");
		printf("\n\n\t\t\tType any other character to go back to MANAGE DATA MENU : ");
		scanf(" %c", &c);		
	}while(i<s&&(c=='y'||c=='Y'));  
	
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
	disclaimer: code not used but is kept just in case needed
	@param a[] - is a char array
	@param b[] - is a char array
*/
int compareTwoString(char a[], char b[]){  
	int flag=0, i=0;    
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
	int ctr=0, resSize=0, i, j, k, l, found, choiceQuestion, choiceField, cmp;
	char c, choiceTopic[20];
	struct record res[s];
	
	
	do{
		system("cls"); // clear screen
		// append all topics to struct record res array
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
	    
	    // present all topics without duplicates
	    printf("\n\n\t\t\t----------------All Topics----------------\n");
	    for(i = 0; i < resSize; i++){
	    	printf("\n\t\t\t\t   ");
	    	int length=strlen(res[i].topic);
	        for(j=0;j<length;j++){
	        	printf("%c",res[i].topic[j]);
			}
			printf("\n");
	    }
	    printf("\n\n\t\t\t------------------------------------------\n");
	    
		// allow user to choose topic
		printf("\n\t\t\tPlease choose a topic : ");
		getString20(choiceTopic);
		printf("\n\n\t\t\tHere are the questions under your chosen topic...");
		for(l=0;l<s;l++){
			cmp=strcmp((A+l)->topic,choiceTopic);
			if(!cmp){
				printf("\n");
				showRecord(A,l);
			}
		}
		
		// allow user to choose question number 
		printf("\n\n\t\t\tPlease enter the question number of your desired question : ");
		scanf("%d", &choiceQuestion);
		
		// allow user to edit chosen question
		for(l=0;l<s;l++){
			if(choiceQuestion==(A+l)->questionNumber&&(strcmp((A+l)->topic,choiceTopic))==0){
				printf("\n\t\t\tCurrently Editing...\n");
				showRecord(A,l);
				printf("\n\t\t\t1 | Edit Topic");
				printf("\n\t\t\t2 | Edit Question");
				printf("\n\t\t\t3 | Edit Choice 1");
				printf("\n\t\t\t4 | Edit Choice 2");
				printf("\n\t\t\t5 | Edit Choice 3");
				printf("\n\t\t\t6 | Edit Answer\n");
				printf("\n\t\t\tWhich field do you want to edit? : ");
				scanf("%d", &choiceField);
				if(choiceField==1){
					printf("\n\t\t\tEnter topic : ");
					getString20(((A+l)->topic));
					/* for checking newly edited question */
					printf("\n\n\t\t\tHere is your newly edited question!\n");
					showRecord(A,l);
				}
				if(choiceField==2){
					printf("\n\t\t\tEnter question : ");
					getSentence(((A+l)->question));
					/* for checking newly edited question */
					printf("\n\n\t\t\tHere is your newly edited question!\n");
					showRecord(A,l);
				}
				if(choiceField==3){
					printf("\n\t\t\tEnter choice 1 : ");
					getString30(((A+l)->choice1));
					/* for checking newly edited question */
					printf("\n\n\t\t\tHere is your newly edited question!\n");
					showRecord(A,l);
				}
				if(choiceField==4){
					printf("\n\t\t\tEnter choice 2 : ");
					getString30(((A+l)->choice2));
					/* for checking newly edited question */
					printf("\n\n\t\t\tHere is your newly edited question!\n");
					showRecord(A,l);
				}
				if(choiceField==5){
					printf("\n\t\t\tEnter choice 3 : ");
					getString30(((A+l)->choice3));
					/* for checking newly edited question */
					printf("\n\n\t\t\tHere is your newly edited question!\n");
					showRecord(A,l);
				}
				if(choiceField==6){
					printf("\n\t\t\tEnter answer : ");
					getString30(((A+l)->answer));
					/* for checking newly edited question */
					printf("\n\n\t\t\tHere is your newly edited question!\n");
					showRecord(A,l);
				}
			}
		}
		printf("\n\n\t\t\tWould you like to edit another question?");
		printf("\n\n\t\t\tType 'y' or 'Y' to enter another.");
		printf("\n\n\t\t\tType any other character to go back to MANAGE DATA MENU : ");
		scanf(" %c", &c);			
	}while(c=='y'||c=='Y');

}
/* deleteRecord allows the user to delete a record for the Quiz Game and returns an integer
	@param *A - points to the first index address of the array of records passed to the function
	@param s - is the size of the array of records passed
*/ 
int deleteRecord(struct record *A, int s){
	int ctr=0, resSize=0, d, i, j, k, l, m, found, cmp, choiceQuestion;
	char c, choiceTopic[20];
	struct record res[s];
	
	do{
		system("cls"); // clear screen
		// append all topics to struct record res array
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
	    
	    // present all topics without duplicates
	    printf("\n\n\t\t\t----------------All Topics----------------\n");
	    for(i = 0; i < resSize; i++){
	    	printf("\n\t\t\t\t\t   ");
	    	int length=strlen(res[i].topic);
	        for(j=0;j<length;j++){
	        	printf("%c",res[i].topic[j]);
			}
			printf("\n");
	    }
	    printf("\n\n\t\t\t------------------------------------------\n");
		
		// allow user to choose topic
		printf("\n\t\t\tPlease choose a topic : ");
		getString20(choiceTopic);
		printf("\n");
		for(l=0;l<s;l++){
			cmp=strcmp((A+l)->topic,choiceTopic);
			if(!cmp){
				showRecord(A,l);
			}
		}
		
		// allow user to choose question number 
		printf("\n\t\t\tPlease enter the question number of the question you want to delete : ");
		scanf("%d", &choiceQuestion);
		
		// user confirmation
		printf("\n\t\t\tAre you sure you want to delete this record? : ");
		printf("\n\n\t\t\tType 1 to confirm.");
		printf("\n\n\t\t\tType any other character to go back to MANAGE DATA MENU : ");
		scanf(" %d", &d);
		
		if(d==1){
			// allow user to delete chosen question
			for(l=0;l<s;l++){
				if(choiceQuestion==(A+l)->questionNumber&&(strcmp((A+l)->topic,choiceTopic))==0){
					printf("\n\t\t\tCurrently Deleting...\n");
					showRecord(A,l);
					for(m=l;m<s;m++){
						strcpy(((A+m)->topic), (A+(m+1))->topic);
						// no need to delete questionNumber
						strcpy(((A+m)->question), (A+(m+1))->question);
						strcpy(((A+m)->choice1), (A+(m+1))->choice1);
						strcpy(((A+m)->choice2), (A+(m+1))->choice2);
						strcpy(((A+m)->choice3), (A+(m+1))->choice3);
						strcpy(((A+m)->answer), (A+(m+1))->answer);
					}
					printf("\n\t\t\tDeleted! :) ");
					s--;
				}
			}	
		} else {
			c='n';
		}
		printf("\n\n\t\t\tWould you like to delete another question?");
		printf("\n\n\t\t\tType 'y' or 'Y' to enter another.");
		printf("\n\n\t\t\tType any other character to go back to MANAGE DATA MENU : ");
		scanf(" %c", &c);
	}while(c=='y'||c=='Y');
	
	return s; // return new value of s
}
/* importData is a void function that allows the user to read a list of entries in a given text file
	@param *A - points to the first index address of the array of records passed to the function
	@param s - is the size of the array of records passed
*/ 
void importData(struct record *A, int s){
	char c, filename[30];
	int i=0, flag=1;
	// file pointer declaration
	FILE *fp;
	
	system("cls");
	while(flag){
		fprintf(stdout, "\n\t\t\t---------------------------------------------------\n");
		fprintf(stdout, "\n\t\t\t------------------   IMPORTING   ------------------\n");
		fprintf(stdout, "\n\t\t\t---------------------------------------------------\n");
		fprintf(stdout, "\n\t\t\tPlease input filename : ");
		fscanf(stdin, "%s", filename);
		if((fp=fopen(filename, "r"))==NULL){
			fprintf(stdout, "\n\t\t\t---------------------------------------------------\n");
			fprintf(stderr, "\n\t\t\t----------   ERROR : %s does not exist  -----------\n", filename);
			fprintf(stdout, "\n\t\t\t---------------------------------------------------\n");
			fprintf(stdout, "\n\t\t\tPlease try inputting a different filename.\n");
			flag=1;
		} else {
				while((fscanf(fp, "%s\n%d\n %[^\n]\n%s\n%s\n%s\n%s",  ((A+i)->topic), &((A+i)->questionNumber), ((A+i)->question),
					((A+i)->choice1), ((A+i)->choice2), ((A+i)->choice3), ((A+i)->answer))==7)){ // changed 2nd %s to <SPACE>%[^\n]
					
					fprintf(stdout, "\n\t\t\t------------Question Number [%d]-----------\n", (A+i)->questionNumber);
					fprintf(stdout, "\n\t\t\tQuestion Topic : %s", (A+i)->topic);
					fprintf(stdout, "\n\n\t\t\tQuestion : %s", (A+i)->question);
					fprintf(stdout, "\n\n\t\t\tA.%s\t\tB.%s\n\n\t\t\tC.%s\t\tAnswer = %s", (A+i)->choice1, (A+i)->choice2, (A+i)->choice3, (A+i)->answer);
					fprintf(stdout, "\n\n\t\t\t------------------------------------------\n"); 
					i++;
				}
				flag=0;
			}
		}
		printf("\n\n\t\t\tHere are the imported data!");
		printf("\n\n\t\t\tType any other character to go back to MANAGE DATA MENU : ");
		scanf(" %c", &c);
		fclose(fp);
}
/* exportData is a void function that allows the user to write a list of entries to a given text file
	@param *A - points to the first index address of the array of records passed to the function
	@param s - is the size of the array of records passed
*/ 
void exportData(struct record *A, int s){
	char filename[30];
	int i;
	// file pointer declaration
	FILE *fp;
	
	system("cls");
	fprintf(stdout, "\n\t\t\t---------------------------------------------------\n");
	fprintf(stdout, "\n\t\t\t------------------   EXPORTING   ------------------\n");
	fprintf(stdout, "\n\t\t\t---------------------------------------------------\n");
	fprintf(stdout, "\n\t\t\tPlease input filename to export to : ");
	getString30(filename);
	
	fp=fopen(filename, "w"); // open in write mode
	
	for(i=0;i<s;i++){
		fprintf(fp,"%s\n%d\n%s\n%s\n%s\n%s\n%s\n\n", ((A+i)->topic), ((A+i)->questionNumber), ((A+i)->question),
					((A+i)->choice1), ((A+i)->choice2), ((A+i)->choice3), ((A+i)->answer));
	}
	
	fclose(fp);
}
/* showManageDataMenu provides the interface for the user to either add, display, edit, delete, import, export, records and returns an integer
*/ 
int showManageDataMenu(){
	int choice;
	do{
		system("cls"); // clear screen
		printf("\n\n		\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MANAGE DATA \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3\n\n");
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
		printf("\n\t\tPlease enter your choice : ");
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
					s=deleteRecord(A,s);
					break;
				}
			case 5: // Import data
				{
					importData(A,s);
					break;
				}
			case 6: // Export data
				{
					exportData(A,s);
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
int randomNumber(int minNum, int maxNum){
	int result=0,lowNum=0,highNum=0;
	
	if(minNum<maxNum){
		lowNum=minNum;
		highNum=maxNum+1;
	} else {
		lowNum=maxNum+1;
		highNum=minNum;
	}
	srand(time(NULL));
	result=(rand()%(highNum-lowNum))+lowNum;
	
	return result;
}
/* showScores is a void function that allows the user to view all scores of the General Knowledge Quiz Game
	@param <param name-instance> - <description>
	@param <param name-instance> - <description>
*/
void showScore(struct scoreRecord *B, int t){
	int i;
	char c;
	printf("\n\t\t\t---------------------------------------------------\n");
	for(i=0;i<t;i++){
		if(((B+i)->rowNum)>0)
			printf("\n\t\t\t  Row # %d\tPlayer : %s\t\tScore | %d\n", (B+i)->rowNum,(B+i)->player,(B+i)->score);
	}
	printf("\n\t\t\t---------------------------------------------------\n");
	printf("\n\n\t\t\tType any character to go back to MANAGE DATA MENU : ");
	scanf(" %c", &c);
}
/* corePlay is the core function of the play feature of this General Knowledge Quiz Game
	@param <param name-instance> - <description>
	@param <param name-instance> - <description>
*/
void corePlay(FILE *fp, struct record *A, int s, struct scoreRecord *B, int t){
	int i, j=0, k, l, cmp, ctr, found, foundTwo, random, resSize=0, accScore=0;
	char c, dump, playerName[20], choiceTopic[20], choiceAnswer[30];
	struct record res[s];
	
	/* for checking the random number generated
	 printf("\nRandom = %d\n", random);
	 scanf(" %c",&c);
	*/
	
	do{
		system("cls"); // clear screen
		// generated random number
		random=randomNumber(1,6);
		// ask for player name
		printf("\n\t\t\tPlease enter your IGN (in-game name) : ");
		getString20(playerName);
		
		// if playerName exists or does not exist
		found=linearSearchScore(playerName,B,s);
		if(found==-1){
			printf("\n\t\t\t------------------------------------------");
			printf("\n\t\t\t\tNew User Alert! Welcome %s!", playerName);
			printf("\n\t\t\t------------------------------------------");
			strcpy((B+j)->player,playerName);
			(B+j)->rowNum=j+1;
		} else {
			printf("\n\t\t\t-----------------------------------------");
			printf("\n\t\t\t\t    Welcome back %s!\n", playerName);
			printf("\n\t\t\t-----------------------------------------");
		}
		
		// append all topics to struct record res array
		for(i = 0; i < s; i++){
	        ctr = 0;
	        for(j = 0; j < s; j++){
	        	cmp=strcmp((A+i)->topic,(A+j)->topic);
	            if(cmp==0){
	                ctr++;
	            }
	        }
	        if(ctr > 0){
	            foundTwo = 0;
	            for(k = 0; k < resSize; k++){
	            	cmp=strcmp((res+k)->topic,(A+i)->topic);
	                if(cmp==0){
	                    foundTwo = 1;
	                }
	            }
	            if(!foundTwo){
	                strcpy(res[resSize++].topic,(A+i)->topic);
	            }
	        }
	    }
	    
	    // present all topics without duplicates
	    printf("\n\n\t\t\t----------------All Topics----------------\n");
	    for(i = 0; i < resSize; i++){
	    	printf("\n\t\t\t\t   ");
	    	int length=strlen(res[i].topic);
	        for(j=0;j<length;j++){
	        	printf("%c",res[i].topic[j]);
			}
			printf("\n");
	    }
	    printf("\n\n\t\t\t------------------------------------------\n");
	    
		// choose from topics
		printf("\n\t\t\tPlease choose a topic : ");
		getString20(choiceTopic);
		scanf("%c",&dump);
		printf("\n");
		// display random question (under topic)
		for(l=0;l<6;l++){
			if(random==(A+l)->questionNumber&&(strcmp((A+l)->topic,choiceTopic))==0){
				showRecordPlay(A,l);
				printf("\n\t\t\tPlease input your answer : ");
				getString30(choiceAnswer);
				// answer 
				cmp=strcmp((A+l)->answer,choiceAnswer);
				// score? or not?
				if(cmp==0){ // correct answer
					printf("\n\t\t\tCorrect Answer!");
					accScore++;
					// record score to current player
					for(k=0;k<s;k++){
						cmp=strcmp((B+k)->player,playerName);
						if(!cmp){
							(B+k)->score=accScore;
						} 
					}
				} else { // wrong answer
					printf("\n\t\t\tSorry, the answer you chose is incorrect.");
					// ask for another topic and generate another question
					//--------------Input   Answer   Here-----------------
				}
			}
		}
		// keep displaying current score of player
		printf("\n\t\t\tCurrent Score is %d\n", accScore);
		// display end game option
		printf("\n\t\t\tWould you like to try again? : ");
		scanf(" %c", &c);
		j++; // increment j
	}while(c=='y'||c=='Y');
	// if end game option is chosen, display message and acc score  
	printf("\n\n");
	printf("\n\t\t\t---------------------------------------------------\n");
	printf("\n\t\t\t-------------- Score Record History ---------------\n");
	showScore(B,t);
	// save score of current player to "score.txt"
	for(i=0;i<s;i++){
		if(((B+i)->rowNum)>0)
			fprintf(fp,"Row # %d\t Player: %s\tScore: %d\n", ((B+i)->rowNum), ((B+i)->player), ((B+i)->score));
	}
	// Go back to Main Menu	
}
/* showPlayMenu provides the interface for the user to either play, view scores, or go back to main menu and returns an integer
	@param <param name-instance> - <description>
	@param <param name-instance> - <description>
*/
int showPlayMenu(){
	int choice;
	do{
		system("cls");
		printf("\n\n		\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MANAGE DATA \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2 1| Play            	  \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2 2| View Scores              \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2 3| Exit                     \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3\n");
		printf("\n\t\tPlease enter your choice : ");
		scanf("%d", &choice);
	}while((choice<1)||(choice>3));
	
	return choice;
}
/* play is a void function that provides the skeleton for the "Play" menu
	@param *A - points to the first index address of the array of records passed to the function
	@param s - is the size of the array of records passed
*/
void play(struct record *A, int s, struct scoreRecord *B, int t){
	int flag=1, choice;
	char c;
	
	FILE *fp;
	if((fp=fopen("score.txt", "w"))!=NULL){
		fprintf(stdout, "Successfully loaded score file!\n");
	}
	
	while(flag){
		choice=showPlayMenu();
		switch(choice){
			case 1:
				{
					// core play 
					corePlay(fp,A,s,B,t);
					break;
				}
			case 2:
				{
					// view scores 
					showScore(B,t);
					break;
				}
			case 3:
				{
					// Go back to MAIN MENU
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
	fclose(fp);
}
/* this is the main function of this General Knowledge Quiz Game
*/
int main(){
	struct record quizRecord[50];
	struct scoreRecord quizScores[50];
	int s=20, t=20, choice, flag=1, isVerified=0; // verified for password
	char c, password[20]={'\0'};
	while(flag){
		choice=showMainMenu(password);
		switch(choice){
			case 1: // "Manage Data" core feature
				{
					// get password
					isVerified=0;
					while(isVerified==0){
						isVerified=getPassword(password);
						if(isVerified==1)
							manageData(quizRecord,s); 
					}
					break;
				}
			case 2: // "Play" core feature
				{
					play(quizRecord,s,quizScores,t);
					break;	
				}
			case 3: // "Exit"
				{
					system("cls");
					printf("\n\n		\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2    EXIT    \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3\n\n");
					printf("		\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB\n\n");
					printf("		\xDB\xDB\xDB\xDB\xB2     Thanks for playing!     \xB2\xDB\xDB\xDB\xDB\n\n");
					printf("		\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB\n\n");
					printf("		\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3\n");
					flag=0;
					break;
					
				}
			default: // default
				{
					system("cls");
					printf("\n\t\t\tInvalid Input");
					printf("\n\n\t\t\tPlease enter any letter to proceed with another choice : ");
					scanf(" %c", &c);
					break;
				}
		}
	}
	return 0;
}
