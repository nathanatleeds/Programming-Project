#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "treeStructure.h"


// make a node at given location (x,y) and level

Node *makeNode( double x, double y, int level ) {

  int i;

  Node *node = (Node *)malloc(sizeof(Node));

  node->level = level;

  node->xy[0] = x;
  node->xy[1] = y;

  for( i=0;i<4;++i )
    node->child[i] = NULL;

  return node;
}

// split a leaf nodes into 4 children

void makeChildren( Node *parent, int maxLvl ) {
   if(parent->level >= maxLvl) return;

  double x = parent->xy[0];
  double y = parent->xy[1];

  int level = parent->level;

  double hChild = pow(2.0,-(level+1));

  parent->child[0] = makeNode( x,y, level+1 );
  parent->child[1] = makeNode( x+hChild,y, level+1 );
  parent->child[2] = makeNode( x+hChild,y+hChild, level+1 );
  parent->child[3] = makeNode( x,y+hChild, level+1 );
}

// Grows the tree by one lvl

void growTree( Node *node, int maxLvl ) {

  if( node->child[0] == NULL) {
      makeChildren(node, maxLvl);
  }

  else {
      int i;
    for ( i=0; i<4; ++i ) {
        growTree (node->child[i], maxLvl);
    }
  }
}
