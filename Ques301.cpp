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

void solve()
{
    int n;
    cin >> n;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        q.push(temp);
    }
    stack<int> st;

    int size = q.size();
    while (q.size() != size / 2)
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    int x = size / 2;
    while (x--)
    {
        int temp = q.front();
        q.pop();
        q.push(temp);
    }

    while (q.size() != size / 2)
    {
        st.push(q.front());
        q.pop();
    }

    queue<int> ans;
    while (!q.empty())
    {
        ans.push(st.top());
        ans.push(q.front());
        st.pop();
        q.pop();
    }

    while (!ans.empty())
    {
        cout << ans.front() << " ";
        ans.pop();
    }
}

int32_t main()
{
    fast;
    solve();
    return 0;
}