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

void solve()
{
    int n;
    cin >> n;
    queue<int> q1;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        q1.push(temp);
    }

    queue<int> q2;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        q2.push(temp);
    }

    stack<int> st;

    while (!q1.empty() && !q2.empty())
    {
        if (q1.front() == q2.front())
        {
            q2.pop();
            while (!st.empty() && !q2.empty())
            {
                if (st.top() != q2.front())
                    break;

                st.pop();
                q2.pop();
            }
        }
        else
        {
            st.push(q1.front());
        }
        q1.pop();
    }
    if (q1.empty() && q2.empty())
        cout << "Yes" << endl;
    else
        cout << "Not possible" << endl;
}

int main()
{
    fast;
    solve();
    return 0;
}

// 0 1 2 3 4 5 6 7 8 9 10 11 12 13
// ( ) ( ( ( ) ) ( ) ( ) ) ) ( )
