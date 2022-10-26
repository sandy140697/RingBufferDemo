#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "ringbuffer.h"


int rear = -1;
int front = -1;
int buff[BUFF_MAX_SIZE];


int main() {
	int i=0;
	int element, choice = 0;
	
	
menu:
	printf("\r\nChoose Operation:  \r\n1. Insert  \r\n2. Delete   \r\n3. Display   \r\n4. Is empty  \r\n5. Is full  \r\n6. Exit  \r\n7. PrintfBuffer\r\n");
	scanf("%d", &choice);
	
	switch(choice){
		case 1:
			printf("\r\nEnter element to insert: \r\n");
			scanf("%d", &element);
			Insert(&front, &rear, buff, element); 
			printf("\r\nElement inserted..........");
			goto menu; 
			break;
		
		case 2:
			Delete(&front, &rear, buff);
			printf("\r\nElement deleted..........");
			goto menu;
			break;
		
		case 3:
			Display(&front, &rear, buff);
			printf("\r\nfront: %d", front);
			printf("\r\nrear: %d", rear);
			goto menu;
			break;
			
		case 4:
			if(Is_Empty(&front, &rear)){
				printf("\r\nBuffer is empty");
			}
			else{
				printf("\r\nBuffer is not Empty");
			} 
			goto menu;
			break;
			
		case 5:
			if(Is_Full(&front, &rear)){
				printf("\r\nBuffer is full");
			}
			else{
				printf("\r\nBuffer is not full");
			} 
			goto menu; 
			break;
			
		case 6:
			return 0;
			break;
		
		case 7:
			printf("\r\nBUFF:  [ ");
			for(i = 0; i < BUFF_MAX_SIZE; i++){
				printf("%d ",buff[i]);
			}
			printf("]");
			goto menu;
			break;
			
		default:
			printf("\r\nInvalid selection!!!");
			goto menu;
			break;
	}
	return 0;
	
}
