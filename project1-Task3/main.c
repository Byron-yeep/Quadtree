
#include "stdio.h"
#include "stdlib.h"

#include "treeStructure.h"
#include "buildTree.h"
#include "writeTree.h"
#include "reduceTree.h"
#include "nodeValue.h"

// main

int main( int argc, char **argv ) {

	Node *head;

	// make the head node
	head = makeNode( 0.0,0.0, 0 );

	// make a tree
	makeChildren( head );
	
	// Test for Task 1 & 2
	
	// (i)
	//growTree( head );
	//growTree( head );
	// (ii)
	//growTree( head );
	//makeChildren( head->child[1] );
	
	//Test for Task 3
	growTree( head );
	growTree( head );
	growTree( head );
	
	// [Task 2]remove children(all children are leaf nodes) 
	//removeChildren( head->child[1] );
	
	// [Task 3]show function F(x,y) in 2D space by quadtree
	compareValue( head );
	
	int count[2] = {0, 0};
	makeOrRemove( head, count );
	printf("The number of added nodes: %d.\nThe number of removed nodes: %d.", count[0], count[1]);

	// print the tree for Gnuplot
	writeTree( head );
	  
	// free all nodes 
	destroyTree( head );

	return 0;
}