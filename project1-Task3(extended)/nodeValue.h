
// value function definitions

double nodeValue( Node *node, double time );
double value( double x, double y, double time );

void compareValue( Node *node );
void makeOrRemove( Node *node, int count[2], int maxLevel );
int judgeLeaf( Node *node );

void adapt( Node *node, int count[2], int maxLevel );
