#include "tree.h"
#include "internalTree.h"
#include <stdlib.h>
#include <stdio.h>

TreeNode* getTreeNode(DoubleList list,void *data,compare cmp){
	Iterator it = getIterator(&list);
	TreeNode *tNode;
	if(it.hasNext(&it)){
		tNode = (TreeNode*)it.next(&it);
		if(cmp(tNode->data,data)==0)
			return tNode;
		if(tNode->children.head)
			return getTreeNode(tNode->children, data, cmp);
	}
	return 0;
}
TreeNode* createTreeNode(void *data,TreeNode *parent){
	TreeNode *treeNode = malloc(sizeof(TreeNode));
	treeNode->data = data;
	treeNode->parent = parent;
	treeNode->children = create();
	return treeNode;
}
Tree createTree(compare cmp){
	Tree tree = {cmp,NULL};
	return tree;
}
int insertToTree(Tree* tree, void* parentData, void* childData) {
	TreeNode *root = (TreeNode*)tree->root;
	TreeNode *nodeToInsert, *parentNode;
	if( tree->root == NULL){
		tree->root = createTreeNode(childData, NULL);
		return 1;
	}
	if(tree->cmp(root->data,parentData)==0){
		parentNode = root;
		nodeToInsert = createTreeNode(childData, parentNode);
		insert(&root->children, 0, nodeToInsert);
		return 1;
	}
	parentNode = getTreeNode(root->children, parentData, tree->cmp);
	nodeToInsert = createTreeNode(childData, parentNode);
	insert(&parentNode->children, 0, nodeToInsert);
	return 1;
}
void* treeNext(Iterator *it){
	TreeNode *node;
	Iterator treeIterator = getIterator(it->list);
	treeIterator.position = it->position;
	node = treeIterator.next(&treeIterator);
	it->position++;
	return node->data;
}

Iterator getChildren(Tree* tree, void *parent) {
	TreeNode *temp,*root = (TreeNode*)tree->root;
	Iterator it;
	if(tree->cmp(root->data,parent)==0)
		temp = root;
	else 
		temp = getTreeNode(root->children, parent, tree->cmp);
	it = getIterator(&temp->children);
	it.next = &treeNext;
	return it;
}

int search(Tree* tree, void* searchElement){
    TreeNode* root = (TreeNode*)(tree->root);
    if(0 == tree->cmp(searchElement,root->data))
    	return 1;
    if(NULL != getTreeNode(root->children,searchElement,tree->cmp))
        return 1;
    return 0;
}

int deleteFromTree(Tree *tree, void *data){
	TreeNode *root = (TreeNode*)tree->root;
	TreeNode *tn,*parent;
	Iterator it;
	tn = getTreeNode(root->children, data, tree->cmp);
	if(0 == tn->children.length){
		parent = tn->parent;
		it = getIterator(&parent->children);
		while(it.hasNext(&it)){
			if(tree->cmp(data,it.next(&it)))
				break;
		}
		delete(&parent->children, it.position - 1);
		return 1;
	}
	return 0;
}