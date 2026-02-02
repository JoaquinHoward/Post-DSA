#ifndef TOURNAMENT_H
#define TOURNAMENT_H

// Normally we get INT_MAX from general, but this local header needs limits.h if standalone.
// Since it's included in main, it will inherit imports, but it's safer to ensure INF is defined.
#ifndef INF
#define INF INT_MAX
#endif

void initTree(int tree[], int tree_size, int elem_start) {
    for (int i = (tree_size - 2) / 2; i >= 0; i--) {
        int left_trav = i * 2 + 1;
        int right_trav = i * 2 + 2;

        if (left_trav < elem_start) {
            left_trav = tree[left_trav];
        }
        if (right_trav < elem_start) {
            right_trav = tree[right_trav];
        }
        tree[i] = (right_trav >= tree_size || tree[left_trav] < tree[right_trav]) ? left_trav : right_trav;
    }
}

void resetTree(int tree[], int tree_size, int elem_start, int parent) {
    while (parent > 0) {
        parent = (parent - 1) / 2;
        int left_trav = parent * 2 + 1;
        int right_trav = left_trav + 1;

        if (left_trav < elem_start) {
            left_trav = tree[left_trav];
        }
        if (right_trav < elem_start) {
            right_trav = tree[right_trav];
        }
        tree[parent] = (right_trav >= tree_size || tree[left_trav] < tree[right_trav]) ? left_trav : right_trav;
    }
}
#endif