#include "sq_stack.h"
#include <stdio.h>

int main(void)
{
	SqStack_T sq_stack_t;
	stack_init(&sq_stack_t);
	char buffer[50] = { "[a*(b+c)-d*(e-f)]" };
	printf("%s\n\n", buffer);
	int buffer_len = strlen(buffer);
	for (int i = 0; i < buffer_len; i++)
	{
		if (buffer[i] == '[' || buffer[i] == '(' || buffer[i] == '{')
		{
			BracketInfo elem = { 0 };
			elem.idx = i;
			elem.bracket = buffer[i];
			stack_push(&sq_stack_t, elem); // 入栈
		}
		else if (buffer[i] == ']' || buffer[i] == ')' || buffer[i] == '}')
		{
			BracketInfo elem_top = { 0 }, elem = {0};
			elem_top = stack_top_element_get(sq_stack_t);
			if (buffer[i] == ']')
			{
				if (elem_top.bracket == '[')
				{
					stack_pop(&sq_stack_t, &elem); // 出栈
				}
			}
			else if (buffer[i] == ')')
			{
				if (elem_top.bracket == '(')
				{
					stack_pop(&sq_stack_t, &elem); // 出栈
				}
			}
			else if (buffer[i] == '}')
			{
				if (elem_top.bracket == '{')
				{
					stack_pop(&sq_stack_t, &elem); // 出栈	
				}
			}
			if(elem.bracket == 0)
				printf("  %c    (-1,%d)\n", buffer[i], i);
			else
				printf("%c %c    (%d,%d)\n", elem.bracket, buffer[i], elem.idx, i);
		}
	}
	stack_destory(&sq_stack_t);
	return 0;
}