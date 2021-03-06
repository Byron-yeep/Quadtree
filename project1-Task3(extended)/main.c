
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
	
	// Make a count
	int count[2] = {0, 0};
	
	// [Task 3] makeChild or removeChild
	//makeOrRemove( head, count );
	
	// [Task 3-extended]
	
	//ERROR //printf("Please enter the value of maxLevel: ");
	//ERROR //scanf("&d", &maxLevel);
	
	adapt( head, count );
	
	printf("The number of all added nodes: %d.\nThe number of all removed nodes: %d.\n", count[0], count[1]);

	// print the tree for Gnuplot
	writeTree( head );
	  
	// free all nodes 
	destroyTree( head );

	return 0;
}