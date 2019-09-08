#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STACK_SIZE 10
#define BUFFER_SIZE 100

typedef enum{
	false = 0,
	true = 1
} bool;

int stack[STACK_SIZE];
int top = -1;
bool push(int);
bool pop(int*);

int main(void) {
	int value;
	char input[BUFFER_SIZE], *ins, *pch, *dlt = " ";
	while(memset(input, '\0', BUFFER_SIZE), scanf("%[^\n]", input), getchar()){
		ins = strtok(input, dlt);
		ins[strlen(ins)] = ' ';
		pch = strtok(NULL, dlt);
		if(strncmp(ins, "pop ", 4) == 0){
			if(pch != NULL){
				printf("Too many arguments of pop\n");
				continue;
			}
			if(pop(&value))
				printf("pop %d\n",value);
			else
				printf("The stack is empty!\n");
		}

		else if(strncmp(ins, "push ", 5) == 0){
			if(pch != NULL){
				if(!(value = atoi(pch))){
					printf("push value error!\n");
					continue;
				}

			}
			else{
				printf("Too few arguments of push!\n");
				continue;
			}
			if(push(value))
				printf("push successfully!\n");
			else
				printf("The stack is full!\n");
		}
		else
			printf("Please enter meaningful instructions!\n");
	}
	return 0;
}

bool push(int value) {
	if (top == STACK_SIZE-1)
		return false;
	else{
		stack[++top] = value;
		return true;
	}
}
bool pop(int* value) {
	if (top == -1)
		return false;
	else{
		*value = stack[top--];
		return true;
	}
}


