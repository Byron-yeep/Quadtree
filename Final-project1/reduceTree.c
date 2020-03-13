
#include "stdio.h"
#include "stdlib.h"

#include "treeStructure.h"
#include "reduceTree.h"

// destroy the tree

void destroyTree( Node *node )
{
    int i;

	if ( node->child[0] == NULL )
        free( node );
    else {
        for ( i=0; i<4; ++i ) {
		    destroyTree( node->child[i] );
    }
	// make other parent nodes be destroyed
		free( node );
  }
	return;
}

// remove a node's all children

void removeChildren( Node *parent )
{
	int i;
	free(parent->child[0]);
	free(parent->child[1]);
	free(parent->child[2]);
	free(parent->child[3]);
	for( i=0;i<4;++i )
		parent->child[i] = NULL;
	return;
}
