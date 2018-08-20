#ifndef STACK_H
#define STACK_H
#include <stdio.h>

#define MAX_STACK 28

//here you can define the type of the item, remember to adjust the mask in the print function above

typedef struct{
	
	int top;
	
	int R[MAX_STACK]; // VALORES DA RIGHT
	int L[MAX_STACK]; // VALORES DA LEFT
	
}tp_stack;

//Starts the stack
void start_stack(tp_stack *stack){
	
	stack->top = -1;
	
}

//Informs if the stack is full or not
int stack_full(tp_stack *stack){
	
	if (stack->top == MAX_STACK - 1) return 1;
	
	else return 0;
	
}

//Informs if the stack is empty or not
int stack_empty(tp_stack *stack){
	
	if(stack->top == -1) return 1;
	
	else return 0;
	
}

//Add an item in the stack
int push(tp_stack *stack, int L, int R){
	
	if (stack_full(stack)) return 0;
	
	stack->top++;
	
	stack->R[stack->top] = R; 
	stack->L[stack->top] = L;
	return 1;
	
}

//Removes an item from the stack
int pop(tp_stack *stack, int *r_L, int *r_R){
	if (stack_empty(stack)) return 0;
	
	*r_L = stack->L[stack->top];
	*r_R = stack->R[stack->top];
	stack->top--;
	return 1;
}

//Inform the top of the stack without removing the item
int top(tp_stack *stack, int *r_L, int *r_R){
	
	if (stack_empty(stack)) return 0;
	
	*r_L = stack->L[stack->top];
	*r_R = stack->R[stack->top];
	return 1;
	
}

//Print the values inside the stack without removing them
void print_stack(tp_stack stack){ // apenas para testes
	
	int r_L;
	int r_R;
	
	while(!stack_empty(&stack)){
		pop(&stack, &r_L, &r_R);
		printf("%d|%d\n", r_L, r_R);	
	}
}

//Look up for the piece 
int stack_lookup(tp_stack stack, int look_L, int look_R){ // apenas para testes
	
	int r_L;
	int r_R;
	while(!stack_empty(&stack)){
		pop(&stack, &r_L, &r_R);
		if((r_L == look_L && r_R == look_R) || (r_L == look_R && r_R == look_L)) {
			return 1;
		}
	}
	return 0;
}

//Inform the height of the stack
int height_stack(tp_stack *stack){
	
	return stack->top+1;
	
}

//Concatenate two stacks in the right order
int concatenate_stack(tp_stack *stack1, tp_stack *stack2){
	
	if (stack_empty(stack2) || (stack1->top + stack2->top > MAX_STACK - 1)) return 0;
	
	tp_stack stack3;
	int r_L, r_R;
	int i;
	
	while(!stack_empty(stack2)){
		
		pop(stack2, &r_L, &r_R);
		
		push(&stack3, r_L, r_R);
		
	}
	
	while(!stack_empty(&stack3)){
		
		pop(&stack3, &r_L, &r_R);
		
		push(stack1, r_L, r_R);
		
	}
	
	return 1;
	
}

#endif
