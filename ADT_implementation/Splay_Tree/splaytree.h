#ifndef _SPLAYTREE_H_
#define _SPLAYTREE_H_

struct splayTreeNode;
typedef struct splayTreeNode* SplayTree;
typedef struct splayTreeNode* Position;

//Default functions of binary tree
SplayTree MakeEmpty(SplayTree tree);//Make an empty tree
Position _Find(SplayTree tree, int value, Position* parent);//Find <value> in <tree> and return its position
Position _FindMax(SplayTree tree);//Find max value in <tree> and return its position
void Display(SplayTree tree, int depth);

//Extra functions of splay tree
Position Find(SplayTree tree, int value);
SplayTree Insert(SplayTree tree, int value);
SplayTree Delete(SplayTree tree, int value);
SplayTree Splay(Position x, Position root);//Push <x> to the child of <root>
SplayTree* Split(int x, SplayTree tree);//not complete yet
SplayTree Join(SplayTree t1, SplayTree t2);
void SingleRotateR(Position k);
void SingleRotateL(Position k);

#endif