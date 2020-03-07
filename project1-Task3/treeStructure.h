
// tree data structure

struct qnode {
	int level;
	double xy[2];
	struct qnode *child[4];
	int flag;
};
typedef struct qnode Node;