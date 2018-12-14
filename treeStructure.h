//the tree node struct definitaions
struct qnode {
  int flag;
  int level;
  double xy[2];
  struct qnode *child[4];
};
typedef struct qnode Node;


