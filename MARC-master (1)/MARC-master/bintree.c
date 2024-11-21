#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"
#include "stack.h"
#include <time.h>


void buildTreerandom(t_node *parent, int currentDepth, int maxDepth)
{
    if (currentDepth == maxDepth) return; // Arrêt si la profondeur maximale est atteinte

    // Choisir 4 fils avec des valeurs aléatoires
    parent->nbSons = 4;
    parent->sons = (t_node **)malloc(4 * sizeof(t_node *));

    for (int i = 0; i < 4; i++) {
        int val = (rand() % 1000) + 1; // Générer une valeur aléatoire entre 1 et 1000
        parent->sons[i] = createNode(val, 0, currentDepth + 1); // Créer un fils avec la valeur générée
        buildTreerandom(parent->sons[i], currentDepth + 1, maxDepth); // Récursion pour chaque fils
    }
}
void buildTree(t_node *parent, int currentDepth, int maxDepth, char *values, int nbValues) {
    if (currentDepth == maxDepth) return; // Arrêt si la profondeur maximale est atteinte

    for (int i = 0; i < nbValues; i++) { // Pour chaque valeur possible (A, B, C, D)
        parent->sons[i] = createNode(values[i], nbValues, currentDepth + 1); // Créer un fils
        buildTree(parent->sons[i], currentDepth + 1, maxDepth, values, nbValues); // Appel récursif
    }
}

// Affichage de l'arbre (parcours préfixe)
void printTree(t_node *node) {
    if (node == NULL) return;
    int spaces;
    spaces=node->depth;
    for (int i = 0; i < spaces; i++) printf("\t");
    // Afficher la valeur et la profondeur du nœud
    printf("Noeud (valeur = %d, profondeur = %d)\n", node->value, node->depth);

    // Parcourir les fils
    for (int i = 0; i < node->nbSons; i++) {
        printTree(node->sons[i]);
    }
}


t_node *findMinValueNode(t_node *node)
{
    if (node == NULL) return NULL;

    // Initialiser le nœud avec la valeur minimale sur le nœud actuel
    t_node *minNode = node;

    // Parcourir tous les fils pour trouver la valeur minimale dans les sous-arbres
    for (int i = 0; i < node->nbSons; i++) {
        t_node *childMinNode = findMinValueNode(node->sons[i]);
        if (childMinNode != NULL && childMinNode->value < minNode->value) {
            minNode = childMinNode;
        }
    }

    return minNode;
}

// Fonction récursive pour trouver le chemin jusqu'à une feuille donnée
#include <stdbool.h>

// Fonction récursive pour trouver le chemin jusqu'à une feuille donnée


bool findPathToLeaf(t_node *node, t_node *targetNode, int *path, int *pathLength)
{
    if (node == NULL) return false;

    // Ajouter la valeur actuelle au chemin
    path[*pathLength] = node->value;
    (*pathLength)++;

    // Si le nœud actuel est le nœud cible, on arrête la recherche
    if (node == targetNode) {
        return true;
    }

    // Explorer les fils
    for (int i = 0; i < node->nbSons; i++) {
        if (findPathToLeaf(node->sons[i], targetNode, path, pathLength)) {
            return true;
        }
    }

    // Si ce nœud ne fait pas partie du chemin vers le nœud cible, on l'enlève
    (*pathLength)--;
    return false;
}
