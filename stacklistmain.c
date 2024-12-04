#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stacklist.h"

int main() {
	sk S1;
	init(&S1);
	Push(&S1, 1);
	printf("%d\n",Pop(&S1));
	
	Push(&S1,1);
	Push(&S1, 2);
	Push(&S1, 3);
	Push(&S1, 4);
	print_stack(S1);
	Push(&S1, 5);
	print_stack(S1);
	printf("%d\n",Pop(&S1));
	printf("%d\n",Peek(S1));
	print_stack(S1);
	
	return 0;
}
