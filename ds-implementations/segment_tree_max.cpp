#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#define MINF -100000

using namespace std;

struct segment_tree{
    segment_tree *left, *right;
    int from, to, value;
    segment_tree(int from, int to)
    : from(from), to(to), left(NULL), right(NULL), value(MINF) { }
};

segment_tree* build(const vector<int> &arr, int l, int r){
    if (l > r) return NULL;
    segment_tree *res = new segment_tree(l, r);
    if (l == r) {
        res->value = arr[l];
    }
    else{
        int m = (l + r) / 2;
        res->left = build(arr, l, m);
        res->right = build(arr, m + 1, r);
        if (res->left != NULL) res->value = max(res->value, res->left->value);
        if (res->right != NULL) res->value = max(res->value, res->right->value);
    }
    return res;
}


// range sum query
int max_query(segment_tree *tree, int l, int r){
    if (tree == NULL) return MINF;
    if (l <= tree->from && tree->to <= r) return tree->value;
    if (tree->to < l) return MINF;
    if (r < tree->from) return MINF;
    return max(max_query(tree->left, l, r), max_query(tree->right, l, r));
}

int update(segment_tree *tree, int i, int val){
    if(tree == NULL) return 0;
    if(tree->to < i) return tree->value;
    if(i < tree->from) return tree->value;
    if(tree->from == tree->to && tree->from == i) {
        tree->value = val;
    }
    else{
        tree->value = min(update(tree->left, i, val), update(tree->right, i, val));
    }
    return tree->value;
}

int main() {
    vector<int> arr(7, 0);
    arr[0] = 1;
    arr[1] = 0;
    arr[2] = 7;
    arr[3] = 8;
    arr[4] = 5;
    arr[5] = 9;
    arr[6] = 3;
    segment_tree *st = build(arr, 0, arr.size());
    cout << "array before update: " << endl;
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    int maxx = max_query(st, 0, 4);
    cout << "range max query before update: " << maxx << endl;
    int temp = update(st, 3, 5);
    arr[3] = 5;
    cout << "array after update: " << endl;
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    maxx = max_query(st, 0, 4);
    cout << "range min query after update: " << maxx << endl;
    return 0;
}
