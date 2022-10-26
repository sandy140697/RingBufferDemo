#ifndef __RING_BUFFER_H
#define __RING_BUFFER_H

#include <stdint.h>

#define BUFF_MAX_SIZE 5
#define true 1
#define false 0

uint8_t Is_Full(int* front, int* rear);
uint8_t Is_Empty(int* front, int* rear);
void Insert(int* front, int* rear, int* buff, int element);
int Delete(int* front, int* rear, int* buff);
void Display(int* front, int* rear, int* buff);


#endif
