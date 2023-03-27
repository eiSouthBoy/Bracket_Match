//==============================================================================
//
// Title:		
// Purpose:		
// Author:
// Created on:
// Copyright:
//
//==============================================================================

#ifndef __SQ_STACK_H__
#define __SQ_STACK_H__

#ifdef __cplusplus
extern "C" {
#endif

//==============================================================================
// Include files
#include <stdlib.h>
#include <string.h>

//==============================================================================
// Constants
#define MAXSIZE 100 // 顺序栈存储空间的初始分配量

#define ERROR -1
#define OK 0
#define OVERFLOW 1
//==============================================================================
// Types
typedef struct
{
	char bracket;  // 存储括号字符
	int  idx;      // 存储括号字符索引
}BracketInfo;

typedef BracketInfo ElemType;

typedef struct
{
	ElemType *base;      // 栈底指针
	ElemType *top;       // 栈顶指针
	int  stack_size;     // 栈可用的最大容量
	int  num_of_elem;    // 栈中元素数量
}SqStack_T;
//==============================================================================
// External variables

//==============================================================================
// Global functions

//int Declare_Your_Functions_Here (int x);
int stack_init(SqStack_T *sq_stack_pt);
void stack_destory(SqStack_T *sq_stack_pt);
int stack_push(SqStack_T *sq_stack_pt, ElemType elem);
int stack_pop(SqStack_T *sq_stack_pt, ElemType *elem);
ElemType stack_top_element_get(SqStack_T sq_stack_t);

#ifdef __cplusplus
}
#endif

#endif
