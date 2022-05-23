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

    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data)
    {
        val = data;
        next = NULL;
    }
};

// class myComparator
// {
// public:
//     bool operator()(ListNode *p1, ListNode *p2)
//     {
//         return p1->val > p2->val;
//     }
// };

ListNode *partition(ListNode *head, ListNode *tail, ListNode *&newHead, ListNode *&newTail)
{
    ListNode *temp1 = new ListNode();
    ListNode *tempHead1 = temp1;
    ListNode *temp2 = new ListNode();
    ListNode *tempHead2 = temp2;
    ListNode *temp = head;
    ListNode *pivot = tail;

    while (temp != tail)
    {
        if (temp->val < pivot->val)
        {
            temp1->next = temp;
            temp = temp->next;
            temp1 = temp1->next;
            temp1->next = NULL;
        }
        else
        {
            temp2->next = temp;
            temp = temp->next;
            temp2 = temp2->next;
            temp2->next = NULL;
        }
    }
    newHead = tempHead1->next;
    temp1->next = pivot;
    pivot->next = tempHead2->next;
    newTail = temp2;
    if (newHead == NULL)
        newHead = pivot;
    return pivot;
}

ListNode *quicksort(ListNode *head, ListNode *tail)
{
    if (!head || head == tail)
        return head;

    ListNode *newHead = NULL;
    ListNode *newTail = NULL;
    ListNode *pivot = partition(head, tail, newHead, newTail);

    ListNode *temp = newHead;

    if (newHead != pivot)
    {
        ListNode *temp = newHead;
        while (temp->next != pivot)
            temp = temp->next;
        temp->next = NULL;
        // cout << newHead->val << "->";
        newHead = quicksort(newHead, temp);

        temp = newHead;
        while (temp->next)
            temp = temp->next;

        temp->next = pivot;
    }
    pivot->next = quicksort(pivot->next, newTail);

    return newHead;
}

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

    // ListNode *newHead = NULL;
    // ListNode *newTail = NULL;
    // ListNode *pivot = partition(head, tail, newHead, newTail);

    // cout << endl << pivot->val << endl;
    ListNode *ans = quicksort(head, tail);
    while (ans)
    {
        cout << ans->val << "->";
        ans = ans->next;
    }
}

int main()
{
    fast;
    solve();
    return 0;
}