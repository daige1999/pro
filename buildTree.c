
#include "buildTree.h"
 
// split a leaf nodes into 4 children
void makeChildren( Node *parent ) {

  double x = parent->xy[0];
  double y = parent->xy[1];

  int level = parent->level;

  double hChild = pow(2.0,-(level+1));

  parent->child[0] = makeNode( x,y, level+1 );
  parent->child[1] = makeNode( x+hChild,y, level+1 );
  parent->child[2] = makeNode( x+hChild,y+hChild, level+1 );
  parent->child[3] = makeNode( x,y+hChild, level+1 );

  return;
}

// make a node at given location (x,y) and level
Node *makeNode( double x, double y, int level ) {
  int i;

  Node *node = (Node *)malloc(sizeof(Node));

  node->level = level;

  node->xy[0] = x;
  node->xy[1] = y;

  for( i=0;i<4;++i )
    node->child[i] = NULL;
  node->flag = 0;
  return node;
}

void growTree(Node *node){
	int i,level;
	double x,y,hChild; 
	for(i=0;i<4;i++){
		if(node->child[i]==NULL){
			x = node->xy[0];
			y = node->xy[1];
			level = node->level;
			hChild = pow(2.0,-(level+1));
			if(i == 1){
				x = x+hChild;
			}
			else if(i == 2){
				x = x+hChild;
				y = y+hChild;
			}
			else if(i == 3){
				y = y+hChild;
			}
			node->child[i] = makeNode(x,y,level+1);
		}
		else{
			growTree(node->child[i]);
		}
	}
	return;
}

//remove children from a node
void removeChildren(Node *parent){
	int i;
	for(i=0;i<4;i++){
		if(parent->child[i]!=NULL){
			free(parent->child[i]);
			parent->child[i]=NULL;
		}
	}
	return;
}

//destroy the tree
void destroyTree(Node *node){
	int i;
	for(i=0;i<4;i++){
		if(node->child[i]!=NULL)
			destroyTree(node->child[i]);		
	}
	free(node);
	return;
}
