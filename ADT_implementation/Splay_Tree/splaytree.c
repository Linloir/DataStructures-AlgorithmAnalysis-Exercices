#include "splaytree.h"
#include <stdio.h>
#include <stdlib.h>

struct splayTreeNode{
    int val;
    SplayTree leftChild;
    SplayTree rightChild;
    SplayTree parent;
};

SplayTree MakeEmpty(SplayTree tree){
    if(tree != NULL){
        MakeEmpty(tree->leftChild);
        MakeEmpty(tree->rightChild);
        free(tree);
    }
    return NULL;
}

Position _Find(SplayTree tree, int value, Position* parent){
    if(tree == NULL)
        return tree;
    if(tree->val == value){
        return tree;
    }
    if(tree->val < value){
        *parent = tree;
        _Find(tree->rightChild, value, parent);
    }
    else{
        *parent = tree;
        _Find(tree->leftChild, value, parent);
    }
}

Position _FindMax(SplayTree tree){
    Position it = tree;
    if(it == NULL)
        return NULL;
    while(it->rightChild != NULL){
        it = it->rightChild;
    }
    return it;
}

void Display(SplayTree tree, int depth){
    if(tree == NULL)
        return;
    if(tree->rightChild != NULL)
        Display(tree->rightChild, depth + 1);
    for(int i = 0; i < depth; i++)
        printf("  ");
    printf("%d\n", tree->val);
    if(tree->leftChild != NULL)
        Display(tree->leftChild, depth + 1);
}

Position Find(SplayTree tree, int value){
    Position p = NULL;
    Position x = _Find(tree, value, &p);
    x = x == NULL ? p : x;
    return Splay(x, NULL);
}

SplayTree Insert(SplayTree tree, int value){
    Position p = NULL;
    Position x = _Find(tree, value, &p);
    if(x == NULL){
        Splay(p, NULL);
        if(p == NULL){
            SplayTree insrt = (SplayTree)malloc(sizeof(struct splayTreeNode));
            insrt->val = value;
            insrt->leftChild = NULL;
            insrt->rightChild = NULL;
            insrt->parent = NULL;
            return insrt;
        }
        else if(value > p->val){
            SplayTree insrt = (SplayTree)malloc(sizeof(struct splayTreeNode));
            insrt->val = value;
            insrt->leftChild = p;
            p->parent = insrt;
            insrt->rightChild = p->rightChild;
            if(p->rightChild != NULL)
                p->rightChild->parent = insrt;
            p->rightChild = NULL;
            insrt->parent = NULL;
            return insrt;
        }
        else{
            SplayTree insrt = (SplayTree)malloc(sizeof(struct splayTreeNode));
            insrt->val = value;
            insrt->rightChild = p;
            p->parent = insrt;
            insrt->leftChild = p->leftChild;
            if(p->leftChild != NULL)
                p->leftChild->parent = insrt;
            p->leftChild = NULL;
            insrt->parent = NULL;
            return insrt;
        }
    }
    else{
        return Splay(x, NULL);
    }
}

SplayTree Delete(SplayTree tree, int value){
    Position p = NULL;
    Position x = _Find(tree, value, &p);
    if(x != NULL){
        Splay(x, NULL);
        SplayTree l = x->leftChild;
        SplayTree r = x->rightChild;
        free(x);
        if(l != NULL)
            l->parent = NULL;
        if(r != NULL)
            r->parent = NULL;
        return Join(l, r);
    }
    else{
        return Splay(p, NULL);
    }
}

SplayTree Splay(Position x, Position root){
    if(x == root)
        return x;
    while(x->parent != root){
        if(x->parent->parent == root){
            //rotate once
            if(x->parent->leftChild == x)
                SingleRotateR(x->parent);
            else
                SingleRotateL(x->parent);
        }
        else{
            //rotate twice
            Position f = x->parent;
            Position gf = f->parent;
            if(f->leftChild == x){
                if(gf->leftChild == f){
                    //left zig-zig situation
                    SingleRotateR(gf);
                    SingleRotateR(f);
                }
                else{
                    //right zig-zag situation
                    SingleRotateR(f);
                    SingleRotateL(gf);
                }
            }
            else{
                if(gf->rightChild == f){
                    //right zig-zig situation
                    SingleRotateL(gf);
                    SingleRotateL(f);
                }
                else{
                    //left zig-zag situation
                    SingleRotateL(f);
                    SingleRotateR(gf);
                }
            }
        }
    }
    return x;
}

void SingleRotateR(Position k){
    Position f = k->parent;
    Position lc = k->leftChild;
    k->leftChild = lc->rightChild;
    if(k->leftChild != NULL)
        k->leftChild->parent = k;
    lc->rightChild = k;
    k->parent = lc;
    if(f != NULL){
        if (f->leftChild == k)
            f->leftChild = lc;
        else
            f->rightChild = lc;
    }
    lc->parent = f;
}

void SingleRotateL(Position k){
    Position f = k->parent;
    Position rc = k->rightChild;
    k->rightChild = rc->leftChild;
    if(k->rightChild != NULL)
        k->rightChild->parent = k;
    rc->leftChild = k;
    k->parent = rc;
    if(f != NULL){
        if(f->leftChild == k)
            f->leftChild = rc;
        else
            f->rightChild = rc;
    }
    rc->parent = f;
}

SplayTree Join(SplayTree t1, SplayTree t2){
    SplayTree newRoot = _FindMax(t1);
    if(newRoot == NULL){
        if(t2 != NULL){
            t2->parent = NULL;
            return t2;
        }
        else
            return NULL;
    }
    else{
        Splay(newRoot, NULL);
        newRoot->rightChild = t2;
        if(t2 != NULL)
            t2->parent = newRoot;
        return newRoot;
    }
}