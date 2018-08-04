#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main () {
	tp_stack pt;
	tp_item r_L, r_R;
	start_stack(&pt);
	push(&pt, 4, 5);
	push(&pt, 2, 1);
	push(&pt, 1, 2);
	print_stack(pt);
	pop(&pt, &r_L, &r_R);
	printf("\n");
	print_stack(pt);
	return 0;
}
