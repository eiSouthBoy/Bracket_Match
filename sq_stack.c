//==============================================================================
//
// Title:
// Purpose:
// Author:
// Created on:
// Copyright:
//
//==============================================================================

//==============================================================================
// Include files
#include "sq_stack.h"
#include <stdio.h>
//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables

//==============================================================================
// Global variables


//==============================================================================
// Static functions

//==============================================================================
// Global functions

/// HIFN  What does your function do?
/// HIPAR x/What inputs does your function expect?
/// HIRET What does your function return?
//int Define_Your_Functions_Here (int x)
//{
//	return x;
//}
// 栈初始化
int stack_init(SqStack_T *sq_stack_pt)
{
	/* base为栈底指针，初始化完成后，栈底指针base始终指向栈底位置.
	 * 若base的值为NULL，则表明栈结构不存在。
	*/
	sq_stack_pt->base = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
	if (NULL == sq_stack_pt->base)
	{
		//printf("malloc memory fail\n");
		exit(OVERFLOW); // 退出程序
	}
	sq_stack_pt->top = sq_stack_pt->base;
	sq_stack_pt->stack_size = MAXSIZE;
	sq_stack_pt->num_of_elem = 0;
	return OK;
}

// 栈销毁
void stack_destory(SqStack_T *sq_stack_pt)
{
	if (sq_stack_pt->base != NULL)
		free(sq_stack_pt->base);
	sq_stack_pt->base = NULL;
	sq_stack_pt->top = NULL;
	sq_stack_pt->num_of_elem = 0;
}

// 入栈
int stack_push(SqStack_T *sq_stack_pt, ElemType elem)
{
	// 入栈前，先判断是否栈满
	if (sq_stack_pt->base - sq_stack_pt->top == sq_stack_pt->stack_size)
	{
		printf("stack full\n");
		return ERROR;
	}
	// 元素入栈，栈顶指针top+1
	*(sq_stack_pt->top) = elem;
	(sq_stack_pt->top)++;
	(sq_stack_pt->num_of_elem)++;
	return OK;
}

// 出栈
int stack_pop(SqStack_T *sq_stack_pt, ElemType *elem)
{
	// 出栈前，先判断是否栈空
	if (sq_stack_pt->top == sq_stack_pt->base)
	{
		printf("stack empty\n");
		return ERROR;
	}
	// 元素出栈，栈顶指针top-1
	(sq_stack_pt->top)--;
	(sq_stack_pt->num_of_elem)--;
	*elem = *(sq_stack_pt->top);
	return OK;
}

// 取栈顶元素
ElemType stack_top_element_get(SqStack_T sq_stack_t)
{
	ElemType elem = { 0 };
	if (sq_stack_t.top != sq_stack_t.base)
		elem = *(sq_stack_t.top - 1);
	return elem;
}