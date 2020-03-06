
#include "stdio.h"
#include "stdlib.h"

#include "treeStructure.h"
#include "buildTree.h"
#include "writeTree.h"
#include "reduceTree.h"

// main

int main( int argc, char **argv ) {

	Node *head;

	// make the head node
	head = makeNode( 0.0,0.0, 0 );

	// make a tree
	makeChildren( head );
	//makeChildren( head->child[0] );
	//makeChildren( head->child[1] );
	//makeChildren( head->child[2] );
	//makeChildren( head->child[1]->child[1] );
	//makeChildren( head->child[1]->child[1]->child[1] );
	  
	// make all leaf nodes have new children
	growTree( head );
	growTree( head );
	
	// remove children(all children are leaf nodes)
	removeChildren( head->child[1] );

	// print the tree for Gnuplot
	writeTree( head );
	  
	// free all nodes 
	destroyTree( head );

	return 0;
}