#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <string.h>

#define INF 100000

typedef long long ll;

using namespace std;

struct segment_tree{
    segment_tree *left, *right;
    ll from, to, value;
    segment_tree(ll from, ll to)
    : from(from), to(to), left(NULL), right(NULL), value(1) { }
};

segment_tree* build(const vector<ll> &arr, ll l, ll r){
    if (l > r) return NULL;
    segment_tree *res = new segment_tree(l, r);
    if (l == r) {
        res->value = arr[l];
    }
    else{
        ll m = (l + r) / 2;
        res->left = build(arr, l, m);
        res->right = build(arr, m + 1, r);
        if (res->left != NULL) res->value *= res->left->value;
        if (res->right != NULL) res->value *= res->right->value;
    }
    return res;
}


// range product query
ll prod_query(segment_tree *tree, ll l, ll r){
    if (tree == NULL) return 1;
    if (l <= tree->from && tree->to <= r) return tree->value;
    if (tree->to < l) return 1;
    if (r < tree->from) return 1;
    return prod_query(tree->left, l, r) * prod_query(tree->right, l, r);
}

ll update(segment_tree *tree, ll i, ll val){
    if(tree == NULL) return 1;
    if(tree->to < i) return tree->value;
    if(i < tree->from) return tree->value;
    if(tree->from == tree->to && tree->from == i) {
        tree->value = val;
    }
    else{
        tree->value = update(tree->left, i, val) * update(tree->right, i, val);
    }
    return tree->value;
}

int main() {
    ll n, k;
    while (cin >> n >> k) {
        vector<ll> arr(n, 0);
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
        }
        getchar();
        segment_tree *st = build(arr, 0, arr.size()-1);
        char command;
        ll x, y;
        for (ll i = 0; i < k; i++) {
            cin >> command >> x >> y;
            getchar();
            if (command == 'P'){
                ll prod = prod_query(st, x-1, y-1);
                if (prod > 0)
                    cout << "+";
                else if (prod < 0)
                    cout << "-";
                else
                    cout << "0";
            }
            else{
                ll temp = update(st, x-1, y);
            }
        }
        cout << endl;
    }
    return 0;
}

