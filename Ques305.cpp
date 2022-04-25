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
    int n, k;
    cin >> n;
    int a[n];
    cin(a, n);
    cin >> k;
    queue<int> q;
    int i = 0, j = 0;
    while (j < n)
    {
        if (a[j] < 0)
            q.push(a[j]);

        if (j - i + 1 < k)
            j++;
        else if (j - i + 1 == k)
        {
            if (q.empty())
                cout << 0 << endl;
            else
                cout << q.front() << endl;
            if (q.front() == a[i])
                q.pop();
            i++;
            j++;
        }
    }
}

int main()
{
    fast;
    solve();
    return 0;
}