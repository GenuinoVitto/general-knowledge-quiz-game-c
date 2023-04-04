#include <stdio.h>

int
main(){
	char password[20], temp[20];
	do{
		char ch;
		int i;
		if(password[0]=='\0')
		{
			printf("There is no existing password, please enter one :> : ");
	
			for(i=0;i<20;i++) {
		 		ch=getch();
		 		password[i] = ch;
		 		ch = '*';
		 		printf("%c", ch);
		 	}	
		} else {
			printf("Please enter the existing passcode :> %s", password);
			scanf("%s", temp);
		}
	 }while((strcmp(password,temp))!=0);
	
}
