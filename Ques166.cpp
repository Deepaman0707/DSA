#include <bits/stdc++.h>
using namespace std;

#define int long long int
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
#define MOD 1000000007
#define cin(a, n)               \
    for (int i = 0; i < n; i++) \
    cin >> a[i]

#define cout(a, n)              \
    for (int i = 0; i < n; i++) \
    cout << a[i]

#define rep(i, n) for (int i = 0; i < n; i++)
#define forr(i, n) for (int i = n; i >= 0; i--)
#define fep(i, a, b) for (int i = a; i < b; i++)

typedef struct treenode
{
    int val;
    struct treenode *left;
    struct treenode *right;
} node;

node *createNode(int val)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Helper function to print Inorder traversal
void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << " " << root->val;
    inorder(root->right);
}

void mirrorify(node *root, node *&mirror)
{
    if (root == NULL)
    {
        mirror = NULL;
        return;
    }

    // Create new mirror node from original tree node
    mirror = createNode(root->val);
    mirrorify(root->left, mirror->right);
    mirrorify(root->right, mirror->left);
}

int32_t main()
{
    fast;
    node *tree = createNode(5);
    tree->left = createNode(3);
    tree->right = createNode(6);
    tree->left->left = createNode(2);
    tree->left->right = createNode(4);

    cout << "Inorder of original tree: ";
    inorder(tree);
    node *mirror = NULL;
    mirrorify(tree, mirror);

    cout << "\nInorder of mirror tree: ";
    inorder(mirror);

    return 0;
}