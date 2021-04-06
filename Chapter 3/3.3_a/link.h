//Link.h by Jonathan Zhang (Linloir) @ 2021/4/6

#pragma once
#ifndef _LINK_H_
#define _LINK_H_

#define ElementType int

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeList();
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
Position Insert(ElementType X, Position P, List L); //Return the position of new node
void Delete(ElementType X, List L);
void DeleteList(List L);

Position Header(List L);
Position First(List L);
Position Advance(Position P);
Position Previous(Position P, List L);
ElementType Retrieve(Position P);

#endif

struct Node {
	ElementType Element;
	PtrToNode Next;
};