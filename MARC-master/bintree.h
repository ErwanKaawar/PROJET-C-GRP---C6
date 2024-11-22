#ifndef BINTREE_H
#define BINTREE_H

#include <stdlib.h>
#include "node.h"
#include <stdbool.h>


typedef struct s_tree
{
    t_node root;
} t_tree, *p_tree;
void buildTreerandom(t_node *parent, int currentDepth, int maxDepth,int nbValues);
int findPathToLeaf(t_node *node, t_node *targetNode, int *path, int *pathLength);
t_node *findMinLeaf(t_node *node, int *);
void buildTree(t_node *, int, int, char *, int, int);
void printTree(t_node *);
#endif //BINTREE_H
