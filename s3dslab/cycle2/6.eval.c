// C program to evaluate value of a postfix expression 
#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
#include <stdlib.h> 

// Stack type 
struct Stack 
{ 
	int top; 
	unsigned capacity; 
	int* array; 
}; 

// Stack Operations 
struct Stack* createStack( unsigned capacity ) 
{ 
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack)); 

	if (!stack) return NULL; 

	stack->top = -1; 
	stack->capacity = capacity; 
	stack->array = (int*) malloc(stack->capacity * sizeof(int)); 

	if (!stack->array) return NULL; 

	return stack; 
} 

int isEmpty(struct Stack* stack) 
{ 
	return stack->top == -1 ; 
} 

char peek(struct Stack* stack) 
{ 
	return stack->array[stack->top]; 
} 

char pop(struct Stack* stack) 
{ 
	if (!isEmpty(stack)) 
		return stack->array[stack->top--] ; 
	return '$'; 
} 

void push(struct Stack* stack, char op) 
{ 
	stack->array[++stack->top] = op; 
} 


// The main function that returns value of a given postfix expression 
int evaluatePostfix(char* exp) 
{ 
	// Create a stack of capacity equal to expression size 
	struct Stack* stack = createStack(strlen(exp)); 
	int i = 0; 

	
	if (!stack) return -1; 

	while (exp[i]) {
		if(exp[i] == ' ') {
			i++;
			continue;
		}

		if (isdigit(exp[i])) {
			push(stack, atoi(exp + i));
			while(exp[i] != ' ') {
				i++;
			}
			continue;
		} else { 
			int val1 = pop(stack); 
			int val2 = pop(stack); 
			switch (exp[i]) 
			{ 
			case '+': push(stack, val2 + val1); break; 
			case '-': push(stack, val2 - val1); break; 
			case '*': push(stack, val2 * val1); break; 
			case '/': push(stack, val2/val1); break; 
			} 
			i++;
		} 
	} 
	return pop(stack); 
} 

int main() 
{ 
	char exp[1000];
	printf("Enter Postfix Expression: ");
	scanf("%[^\n]", exp); 
	printf ("postfix evaluation: %d\n", evaluatePostfix(exp)); 
	return 0; 
} 
