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
    ListNode(int data)
    {
        val = data;
        next = NULL;
        prev = NULL;
    }
};

class myComparator
{
public:
    bool operator()(ListNode *p1, ListNode *p2)
    {
        return p1->val > p2->val;
    }
};

void solve()
{
    ListNode *head = NULL;
    ListNode *tail = NULL;

    int opt = 0;
    do
    {
        int val;
        cin >> opt;
        if (opt == 0)
            break;
        cin >> val;
        ListNode *dummy = new ListNode(val);
        if (head == NULL)
        {
            head = dummy;
            tail = dummy;
        }
        else
        {
            tail->next = dummy;
            tail = tail->next;
        }
    } while (opt != 0);

    int k;
    cin >> k;

    priority_queue<ListNode *, vector<ListNode *>, myComparator> pq;
    for (int i = 0; head != NULL && i <= k; i++, head = head->next)
        pq.push(head);

    ListNode *newHead = NULL;
    ListNode *last = newHead;
    while (!pq.empty())
    {
        if (!newHead)
        {
            newHead = pq.top();
            newHead->prev = NULL;
            last = newHead;
        }
        else
        {
            last->next = pq.top();
            pq.top()->prev = last;
            last = last->next;
        }
        pq.pop();

        if (head)
        {
            pq.push(head);
            head = head->next;
        }
    }
    last->next = NULL;

    ListNode *temp = newHead;
    while (temp != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
}

int main()
{
    fast;
    solve();
    return 0;
}