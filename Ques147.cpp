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

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode *prev;

    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int x)
    {
        val = x;
        next = NULL;
        prev = NULL;
    }
};

void solve()
{
    ListNode *head = NULL;
    ListNode *tail = head;
    int opt = 0;
    do
    {
        cin >> opt;
        if (opt == 0)
            break;
        int val;
        cin >> val;
        ListNode *temp = new ListNode(val);
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }

    } while (opt != 0);

    int sum = 0;
    cin >> sum;

    ListNode *temp1 = head;
    while (temp1->next->next != tail)
    {
        ListNode *temp2 = temp1->next;
        ListNode *temp3 = tail;
        while (temp2->val < temp3->val)
            if (sum - temp1->val == (temp3->val + temp2->val))
            {
                cout << "(" << temp1->val << ", " << temp2->val << ", " << temp3->val << ")"
                     << " ";
                temp2 = temp2->next;
                temp3 = temp3->prev;
            }

            else if (sum - temp1->val < (temp3->val + temp2->val))
                temp3 = temp3->prev;

            else if (sum - temp1->val > (temp3->val + temp2->val))
                temp2 = temp2->next;
        temp1 = temp1->next;
    }
}

int main()
{
    fast;
    solve();
    return 0;
}