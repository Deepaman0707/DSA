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

string isSubset(int a1[], int a2[], int n, int m)
{
    sort(a1, a1 + n);
    sort(a2, a2 + m);
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a1[i] == a2[j])
        {
            i++;
            j++;
        }
        else
            i++;
    }

    if (j == m)
        return "Yes";
    else
        return "No";
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int a1[n], a2[m];
    cin(a1, n);
    cin(a2, m);
    cout << isSubset(a1, a2, n, m) << endl;
}

int main()
{
    fast;
    solve();
    return 0;
}