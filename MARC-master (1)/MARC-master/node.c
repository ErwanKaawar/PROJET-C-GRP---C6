#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "stack.h"
#include "bintree.h"

t_node *createNode(int val, int nb_sons, int depth)
{
    t_node *new_node;
    new_node = (t_node *)malloc(sizeof(t_node));
    new_node->value = val;
    new_node->nbSons = nb_sons;
    new_node->sons = (t_node **)malloc(nb_sons*sizeof(t_node *));
    for (int i=0; i <nb_sons; i++)
    {
        new_node->sons[i]=NULL;
    }
    new_node->depth = depth;
    return new_node;
}


