#include "nodeValue.h"

void addChildren( Node *parent ) {

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

// Evaluate function at centre of quadtree node
double nodeValue( Node *node, double time ) {

  int level = node->level;
  double x = node->xy[0];
  double y = node->xy[1];

  double h = pow(2.0,-level);

  return( value( x+0.5*h, y+0.5*h, time ) );
}

// Data function
double value( double x, double y, double time ) {

  return( 2.0*exp(-8.0*(x-time)*(x-time)) - 1.0 ) ;
}


//Judge it is not a leaf node and all children have flag=-1
int children_node(Node *node){
	int i;
	int count=0;
	for(i=0;i<4;i++){
		if(node->child[i]!=NULL){
			count+=node->child[i]->flag;
		}
		else{
			return 0;
		}
	}
	if(count==-4)
		return 1;
	return 0;
}

//Judge if it is a leaf node
int leaf_node(Node *node){
	int i;
	for(i=0;i<4;i++){
		if(node->child[i]!=NULL){
			return 0;
		}
	}
	return 1;
}

void set_flag(Node *node){
	int i;
	if(!leaf_node(node)) node->flag=0;
	else if(nodeValue(node,0.0)>0.5){
		node->flag=1;
	}
	else if(nodeValue(node,0.0)<-0.5){
		node->flag=-1;
	}
	else{
		node->flag=0;
	}
	for(i=0;i<4;i++){
		if(node->child[i]!=NULL){
			set_flag(node->child[i]);
		}
	}
}

void adjust_tree(Node *node){
	int i;
	if(leaf_node(node) && node->flag==1){
		addChildren(node);
		add_num += 4;
		return;
	}
	else if(children_node(node)){
		removeChildren(node);
		rem_num += 4;
		return;
	}
	for(i=0;i<4;i++){
		if(node->child[i]!=NULL)
			adjust_tree(node->child[i]);
	}
}

void adapt(Node *node){
	int i;
	if(children_node(node)){
		removeChildren(node);
		rem_num += 4;
		return;
	}
	else if((leaf_node(node) && node->flag==1) && node->level<maxLevel){
		addChildren(node);
		add_num += 4;
		return;
	}
	for(i=0;i<4;i++){
		if(node->child[i]!=NULL)
			adapt(node->child[i]);
	}
}









