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

void levelOrderTraversal(tree *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
    {
        cout << 0;
        return;
    }
    queue<tree *> node;
    node.push(root);
    while (!node.empty())
    {
        vector<int> level;
        int size = node.size();
        for (int i = 0; i < size; i++)
        {
            tree *temp = node.front();
            node.pop();
            if (temp->left != NULL)
                node.push(temp->left);
            if (temp->right != NULL)
                node.push(temp->right);
            level.pb(temp->val);
        }
        ans.pb(level);
    }

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
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

    levelOrderTraversal(root);
}

int main()
{
    fast;
    solve();
    return 0;
}