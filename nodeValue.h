double nodeValue( Node *node, double time );
double value( double x, double y, double time );
void addChildren( Node *parent );
void set_flag(Node *node);
int leaf_node(Node *node);
int children_node(Node *node);
void adjust_tree(Node *node);
void adapt(Node *node);

int add_num = 0;
int rem_num = 0;
int maxLevel = 6;
