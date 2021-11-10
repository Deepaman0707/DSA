#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define pb push_back
#define pob pop_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define ff first
#define ss second
#define ll long long int
#define fast ios_base::sync_with_stdio(NULL), cin.tie(0), cout.tie(0)
#define MOD 1e9 + 7
#define cin(a, n)               \
    for (int i = 0; i < n; i++) \
    cin >> a[i]

#define cout(a, n)              \
    for (int i = 0; i < n; i++) \
    cout << a[i]

#define rep(i, n) for (int i = 0; i < n; i++)
#define forr(i, n) for (int i = n; i >= 0; i--)
#define fep(i, a, b) for (int i = a; i < b; i++)

struct tree
{
    int val;
    tree *left;
    tree *right;
    tree(int value)
    {
        val = value;
        left = NULL;
        right = NULL;
    }
};

// Recursive method for preorder traversal.

void preOrderTraversal(tree *node)
{
    if (node == NULL)
        return;
    cout << node->val << " ";
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

void solve()
{
    tree *root = new tree(1);
    root->left = new tree(2);
    root->right = new tree(3);
    root->left->left = new tree(4);
    root->left->right = new tree(5);
    root->right->left = new tree(6);
    root->right->right = new tree(7);

    preOrderTraversal(root);
}

int main()
{
    fast;
    solve();
    return 0;
}