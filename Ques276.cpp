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
    cout << a[i] << " "

#define rep(i, n) for (int i = 0; i < n; i++)
#define forr(i, n) for (int i = n; i >= 0; i--)
#define fep(i, a, b) for (int i = a; i < b; i++)

class listnode
{
public:
    int val;
    listnode *left;
    listnode *right;
    listnode *middle;

    listnode()
    {
        val = 0;
        left = NULL;
        right = NULL;
    }

    listnode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }

    ~listnode()
    {
        int data = val;
        if (left != NULL && right != NULL)
        {
            delete left;
            delete right;
            left = NULL;
            right = NULL;
        }
        cout << "Memory released for: " << val << endl;
    }
};

void display(listnode *&head, listnode *&tail)
{
    listnode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << "<->";
        temp = temp->right;
    }
}

void push(int data, listnode *&head, listnode *&middle, listnode *&tail, int &flag)
{
    listnode *temp = new listnode(data);
    if (head == NULL)
    {
        head = temp;
        middle = temp;
        tail = temp;
        flag = 0;
    }
    else
    {
        tail->right = temp;
        temp->left = tail;
        tail = temp;
        if (flag == 0)
        {
            flag = 1;
            middle = middle->right;
        }
        else
            flag = 0;
    }
}

int getMiddle(listnode *middle)
{
    return middle->val;
    // return 0;
}

void pop(listnode *&head, listnode *&middle, listnode *&tail, int &flag)
{
    if (head == NULL)
        cout << "List is empty." << endl;

    else
    {
        listnode *temp = tail;
        tail = tail->left;
        tail->right = NULL;
        delete temp;
        if (flag == 1)
        {
            flag = 0;
            middle = middle->left;
        }
        else
            flag = 1;
    }
}

void solve()
{
    listnode *head = NULL;
    listnode *tail = NULL;
    listnode *middle = NULL;
    int flag = 0;

    int opt;
    do
    {
        cin >> opt;
        if (opt == 0)
            pop(head, middle, tail, flag);
        else if (opt == 1)
        {
            int val;
            cin >> val;
            push(val, head, middle, tail, flag);
        }
        else if (opt == 2)
            cout << getMiddle(middle) << endl;
        else if (opt == 3)
        {
            display(head, tail);
            cout << endl;
        }
    } while (opt != -1);
}

int main()
{
    fast;
    solve();
    return 0;
}