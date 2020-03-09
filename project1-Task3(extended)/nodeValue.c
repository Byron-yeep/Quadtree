#include "math.h"
#include "stdio.h"

#include "treeStructure.h"
#include "buildTree.h"
#include "reduceTree.h"
#include "nodeValue.h"

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

// Compare value to determine flag

void compareValue( Node *node ) {
	int i;
	double n;
	if(judgeLeaf( node ) == 1) {
		n = nodeValue( node, 0.0 );
		if(n > 0.5) 
			node->flag = 1;
		if(n < -0.5) 
			node->flag = -1;
	}
	else {
		node->flag = 0;
		for(i = 0; i < 4; i++) {
			compareValue( node->child[i] );
		}
	}
	return;
}

// Change structure according to flag 

void makeOrRemove( Node *node, int count[2] ) {
	if(judgeLeaf( node ) == 1) {
		if(node->flag == 1) {
			makeChildren( node );
			count[0] += 4;
		}
	}
	else {
		int num = 0;
		int n;
		
		for( n = 0; n < 4; n++) 
			if(node->child[n]->flag == -1)
				num++;
		
		if(num == 4) {
			removeChildren( node );
			count[1] += 4;
		}
		
		if(judgeLeaf( node ) == 0) {
			for(n=0; n < 4; n++) 			
				makeOrRemove( node->child[n], count );
		}
	}
	
	return;
}

// Judge a leaf node or not 

int judgeLeaf( Node *node ) {
	if(node->child[0] == NULL && node->child[1] == NULL && node->child[2] == NULL && node->child[3] == NULL)
		return 1;
	else
		return 0;
}

// Plus a function about maxLevel

void adapt( Node *node, int count[2], int maxLevel ) {
	if(judgeLeaf( node ) == 1) {
		if(node->flag == 1) 
			addChildren( node, count, maxLevel );
	}
	else {
		int num = 0;
		int n;
		
		for( n = 0; n < 4; n++) {
			if(node->child[n]->flag == -1)
				num++;
		}
		if(num == 4) {
			removeChildren( node );
			count[1] += 4;
		}
		
		if(judgeLeaf( node ) == 0) {
			for(n=0; n < 4; n++) 			
				adapt( node->child[n], count, maxLevel );
		}
	}
	
	return;
}

// Make children until achieve the maxLevel

void addChildren( Node *node, int count[2], int maxLevel ) {
	int i;
	if(node->level < maxLevel) {	
		makeChildren( node );
		count[0] += 4;
		for(i = 0; i < 4; i++)
			addChildren( node->child[i], count, maxLevel);
	}
	return;
}