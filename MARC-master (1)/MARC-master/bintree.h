#ifndef BINTREE_H
#define BINTREE_H

#include <stdlib.h>
#include "node.h"
#include <stdbool.h>


typedef struct s_tree
{
    t_node root;
} t_tree, *p_tree;
void buildTreerandom(t_node *parent, int currentDepth, int maxDepth);
bool findPathToLeaf(t_node *node, t_node *targetNode, int *path, int *pathLength);
t_node *findMinValueNode(t_node *node);
void printTreeWithIndent(t_node *node, int indent);

void buildTree(t_node *, int, int, char *, int);
void printTree(t_node *);
void parcours(t_node *, t_tree);
#endif //BINTREE_H
