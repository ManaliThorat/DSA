#include "tree_iterator.h"
#include "iterator.h"

#ifndef _COMPARE_
#define _COMPARE_
typedef int (*compare)(void* firstElement, void* secondElement);
#endif
typedef struct {
	compare cmp;
	void *root;
} Tree;

Tree createTree(compare cmp);
int insertToTree(Tree* tree, void* parentData, void* data);
Iterator getChildren(Tree* tree, void* parentData);
int deleteFromTree(Tree* tree, void* data);
int search(Tree* tree, void* data);