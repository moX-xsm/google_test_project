/*************************************************************************
	> File Name: linklist.h
	> Author: 
	> Mail: 
	> Created Time: 2020年09月22日 星期二 15时36分45秒
 ************************************************************************/

#ifndef _LINKLIST_H
#define _LINKLIST_H


#define offset(T, name) ((long long)(&(((T *)(0))->name)))
#define Head(p, T, name) ((T *)(((char *)p) - offset(T, name)))

//这样设计的链表可以存储任意类型 链表外骨骼
struct LinkNode{
    struct LinkNode *next;    
};

#endif
