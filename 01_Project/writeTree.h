#include "stdio.h"
#include "math.h"
#include "stdlib.h"

void writeNode( FILE *fp, Node *node );
void writeTree( Node *node );
void printOut( FILE *fp, Node *node );
void destroyTree(Node *node);