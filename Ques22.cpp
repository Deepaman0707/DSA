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

int multiply(int x, int a[], int size)
{
    int carry = 0;
    for (int i = 0; i < size; i++)
    {
        int prod = a[i] * x + carry;
        a[i] = prod % 10;
        carry = prod / 10;
    }

    while (carry)
    {
        a[size] = carry % 10;
        carry /= 10;
        size++;
    }
    return size;
}

void solve()
{
    int n;
    cin >> n;
    int a[500];
    a[0] = 1;
    int size = 1;
    for (int i = 2; i <= n; i++)
        size = multiply(i, a, size);

    for (int i = size - 1; i >= 0; i--)
        cout << a[i];
}

int main()
{
    fast;
    solve();
    return 0;
}