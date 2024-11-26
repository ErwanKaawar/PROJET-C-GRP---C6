#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"
#include "stack.h"
#include <time.h>



int pickRandom(int values[], int size) {
    if (size <= 0) {
        return 0;
    }

    int index = rand() % size; // Générer un indice aléatoire entre 0 et size-1
    return values[index];
}

void buildTreerandom(t_node *parent, int currentDepth, int maxDepth,int NbValues)
{
    if (currentDepth == maxDepth) return; // Arrêt si la profondeur maximale est atteinte

    // Choisir 4 fils avec des valeurs aléatoires
    parent->nbSons = NbValues;
    parent->sons = (t_node **)malloc(NbValues * sizeof(t_node *));

    for (int i = 0; i < NbValues; i++) {
        int value [] = {1,2,4,10000,10001,122,134,533};
        parent->sons[i] = createNode(value[i], 0, currentDepth + 1); // Créer un fils avec la valeur générée
        buildTreerandom(parent->sons[i], currentDepth + 1, maxDepth, NbValues-1); // Récursion pour chaque fils
    }
}
void buildTree(t_node *parent, int currentDepth, int maxDepth, int values[], int nbValues) {
    if (currentDepth == maxDepth) {
        parent->nbSons=0;
        return;
    }
    // Arrêt si la profondeur maximale est atteinte;
    for (int i = 0; i < nbValues; i++) { // Pour chaque valeur possible (A, B, C, D)
        int values[]={1,2,4,10000,1,2,4,10000};
        int valeur=pickRandom(values,4);
        valeur+=parent->value;
        parent->sons[i] = createNode(valeur, nbValues, currentDepth + 1); // Créer un fils
        buildTree(parent->sons[i], currentDepth + 1, maxDepth, values, nbValues-1); // Appel récursif
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


t_node *findMinLeaf(t_node *node)
{
    if (node == NULL) return NULL;

    // Si le nœud est une feuille, on retourne ce nœud
    if (node->nbSons == 0) {
        return node;
    }

    t_node *minNode = NULL;
    int minValue = 10000001; // Initialisation à une valeur supérieure au maximum possible

    // Parcourir les fils pour trouver la feuille avec la valeur minimale
    for (int i = 0; i < node->nbSons; i++) {
        t_node *leaf = findMinLeaf(node->sons[i]);
        if (leaf != NULL && leaf->value < minValue) {
            minValue = leaf->value;
            minNode = leaf;
        }
    }

    return minNode;
}
#include <stdbool.h>

// Fonction récursive pour trouver le chemin jusqu'à une feuille donnée


int findPathToLeaf(t_node *node, t_node *targetNode, int *path, int *pathLength)
{
    if (node == NULL) return 0;

    // Ajouter la valeur actuelle au chemin
    path[*pathLength] = node->value;
    (*pathLength)++;

    // Si le nœud actuel est le nœud cible, on arrête la recherche
    if (node == targetNode) {
        return 1;
    }

    // Explorer les fils
    for (int i = 0; i < node->nbSons; i++) {
        if (findPathToLeaf(node->sons[i], targetNode, path, pathLength)) {
            return 1;
        }
    }

    // Si ce nœud ne fait pas partie du chemin vers le nœud cible, on l'enlève
    (*pathLength)--;
    return 0;
}
