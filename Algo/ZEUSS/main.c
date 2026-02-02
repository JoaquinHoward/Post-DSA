#include "general.h"
#include "arrays.h"
#include "tournament.h"
#include "sort-test.h"

void tournamentSort(int arr[], int size);

int main() {
    test_sort_w_size(tournamentSort);
    return 0;
}

void tournamentSort(int arr[], int size) {
    if (size <= 1) return;

    int tree_size = size * 2 - 1;
    int elem_start = tree_size - size;
    int tree[tree_size];

    for (int i = 0; i < size; i++) {
        tree[elem_start + i] = arr[i];
    }

    initTree(tree, tree_size, elem_start);

    for (int i = 0; i < size; i++) {
        int ndx = tree[0];
        arr[i] = tree[ndx];
        tree[ndx] = INF;

        int parent = ndx;
        resetTree(tree, tree_size, elem_start, parent);
    }
}