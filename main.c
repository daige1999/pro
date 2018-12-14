#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "treeStructure.h" 
#include "buildTree.c"
#include "writeTree.c"
#include "nodeValue.c"

int main(int argc, char **argv){
	Node *head;
	head=makeNode(0.0,0.0, 0);
	growTree(head);
	growTree(head);
	growTree(head);
	do{
		set_flag(head);
		add_num = rem_num = 0;
		adapt(head);
		printf("added %d nodes and removed %d nodes\n",add_num,rem_num);
	}while(add_num + rem_num != 0);	 
	writeTree(head);
	return 0;
}

