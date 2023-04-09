#include <stdio.h>
#include <conio.h>
#include <string.h>

struct record {
	char topic[20];
	int questionNumber;
	char question[150];
	char choice1[30];
	char choice2[30];
	char choice3[30];
	char answer[30];
};

struct score {
	int playerNum;
	char playerName[20];
	int score;
};

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
	s[i]='\0';
	strcpy(ptr,s);
}

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
	s[i]='\0';
	strcpy(ptr,s);
}

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
	s[i]='\0';
	strcpy(ptr,s);
}

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

int binarySearch(char *param1, char *param2, struct record A[], int s)
{
    // Encode your solution.
    int low=0, high=s-1, mid, cmp;
    int found=0;
    
    while(found==0&&low<=high){
    	mid=low+(high-low)/2;
    	cmp = strcmp(A[mid].question, param1);
    	if(cmp==0)
    		cmp = strcmp(A[mid].answer, param2);
    	
    // positive cmp means current is greater
    	if(cmp==0){
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

// shows single record
void showRecord(struct record A[], int index){
	printf("\nQuestion Number #%d", (A+index)->questionNumber);
	printf("\n\n%s", (A+index)->question);
	printf("\n\nA.%s\t\tB.%s\n\nC.%s\t\tAnswer = %s", (A+index)->choice1, (A+index)->choice2, (A+index)->choice3, (A+index)->answer);
}

// shows all records
void showAll(struct record A[], int s){
	int i;
	
	for(i=0;i<s;i++){
		printf("\nQuestion Number #%d", (A+i)->questionNumber);
		printf("\n\n%s", (A+i)->question);
		printf("\n\nA.%s\t\tB.%s\n\nC.%s\t\tAnswer = %s", (A+i)->choice1, (A+i)->choice2, (A+i)->choice3, (A+i)->answer);
	}
}

// getInput
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

// addRecord
int addRecord(struct record *A, int s){
	getInput(A,s);
	return s+1; // implement pointer to s
}

// editRecord
void editRecord(struct record *A, int s){
	int ctr=0,cmp,cmp2,i,j,k;
	int l,found;
	char c,dump,choiceTopic[20];
	
	// display all unique topics
	printf("\nThe Unique topics are the following : ");
	for(i=0;i<s;i++){
		ctr=0;
		for(j=0,k=s;j<k+1;j++){
			cmp=strcmp((A+i)->topic,(A+j)->topic);
			if(cmp!=0){
				cmp=strcmp((A+i)->topic,(A+j)->topic);
				if(cmp==0){
					ctr++;
				}
			}
		}
		if(ctr==0){
			printf("\n | %s", (A+i)->topic);
		}
	}
	
	// choose topic
	printf("\nPlease choose a topic : ");
	getString20(choiceTopic);
	scanf("%c",&dump);
	
	for(l=0;l<s;l++){
		printf("hello\n");
		printf("compare: %s with: %s", (A+l)->topic, choiceTopic);
		printf("\nrecord topic: %s", (A+l)->topic);
		printf("\nuser choice topic: %s", choiceTopic);
		cmp=strcmp((A+l)->topic, choiceTopic);
		printf("\n%d", cmp);
		if(!cmp){
			showRecord(A,l);
		}
	}
	scanf(" %c", &c);
	
	
	
}
// deleteRecord

// exportData

// importData

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
					break;
				}
			case 5: // Import data
				{
					break;
				}
			case 6: // Export data
				{
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

// get random number function
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

void play(struct record *A, int s){
	int random=randomNumber(0,s);
	char c;
	printf("\nrandom = %d", random);
	scanf(" %c",&c);
	
}

void exit(){
	system("cls");
		printf("\n		\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2    EXIT    \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2     Thanks for playing!     \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB\n\n");
		printf("		\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3\n");
}
// show main menu
int main(){
	struct record quizRecord[5];
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
					play(quizRecord,5);
					break;	
				}
			case 3:
				{
					exit();
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
