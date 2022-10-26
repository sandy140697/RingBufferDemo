#include "ringbuffer.h"

uint8_t Is_Full(int* front, int* rear){
	if((*front == 0) && (*rear == (BUFF_MAX_SIZE - 1)) || (*front == *rear + 1)){		
		return true;
	}
	else{
		return false;
	}
}

uint8_t Is_Empty(int* front, int* rear){
	if((*rear == -1) && (*front == -1)){
		return true;
	}
	else{
		return false;
	} 
}


void Insert(int* front, int* rear, int* buff, int element){
	if(Is_Full(front, rear)){
		printf("\r\nBuffer Oveflow...");
		return;
	}
	if(*rear == -1){
		*rear = *front = 0;
	}
	else if(*rear == BUFF_MAX_SIZE - 1){
		*rear = 0;
	}
	else{
		*rear = *rear + 1;
	}
	
	buff[*rear] = element;
	
}

int Delete(int* front, int* rear, int* buff){
	int element;
	if(Is_Empty(front, rear)){
		printf("\r\nBuffer underflow");
		return;
	}
	
	element = buff[*front];
	
	if(*front == *rear){
		*front = *rear = -1;
	}
	else if(*front == (BUFF_MAX_SIZE - 1)){
		*front = 0;
	}
	else{
		*front = *front + 1;
	}
	return element;
}

void Display(int* front, int* rear, int* buff){
	int i,j;
	if(Is_Empty(front, rear)){
		printf("\r\nBuffer underflow");
		return;
	}
	
	if(*front > *rear){
		for(i = *front; i <= (BUFF_MAX_SIZE - 1); i++){
			printf("\r\nBUFF[%d]:  %d", i, buff[i]);
		}
		for(j = 0; j <= *rear; j++){
			printf("\r\nBUFF[%d]:   %d", j, buff[j]);
		}
	}
	else{
		for(i = *front; i <= *rear; i++){
			printf("\r\nBUFF[%d]:   %d", i, buff[i]);
		}
	}
	
}
