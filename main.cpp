#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"treeStructure.h" 
#include"buildTree.h"
#include"writeTree.h"
#include "nodevalue.c"

int main(int argc, char **argv){
	Node *head;
	//make the head node
	head=makeNode(0.0,0.0, 0);
	//make a tree
	makeChildren(head);
	growTree(head);
	growTree(head);
	set_flag(head);
	adjust_tree(head);
	printf("%d %d\n",adapt_add_num,rem_num);
	//destroyTree(head);
	//print the tree for Gnuplot 
	writeTree(head);
	return 0;
	
}

