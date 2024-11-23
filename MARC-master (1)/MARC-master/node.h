#ifndef NODE_H
#define NODE_H



typedef struct s_node
{
    int value;
    int depth;
    struct s_node **sons;
    int nbSons; // taille physique du tableau
    int *parent;
    // more to come !
} t_node;

t_node *createNode(int val, int nb_sons, int depth);



#endif //NODE_H