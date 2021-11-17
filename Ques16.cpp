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

// Optimal approach for count inversion. Time complezcity for this algorithm is nlogn

int mergeit(int a[], int start, int mid, int end)
{
    int n1 = mid - start + 1, n2 = end - mid;
    int b[n1] = {0}, c[n2] = {0};

    for (int i = 0, k = start; k <= mid; i++, k++)
        b[i] = a[k];

    for (int i = 0, k = mid + 1; k <= end; i++, k++)
        c[i] = a[k];

    int i = 0, j = 0, k = start;
    ll count = 0;
    while (i < n1 && j < n2)
    {
        if (b[i] < c[j])
        {
            a[k] = b[i];
            i++;
        }
        else
        {
            a[k] = c[j];
            count += n1 - i;
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = b[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = c[j];
        j++;
        k++;
    }
    return count;
}

int mergeSort(int a[], int start, int end)
{
    int count = 0;
    if (start < end)
    {

        int mid = (start + end) / 2;
        count += mergeSort(a, start, mid);
        count += mergeSort(a, mid + 1, end);
        count += mergeit(a, start, mid, end);
    }
    return count;
}

// Solving same problem for the brute force method whose time complexcity is n^2.

int countbrute(int a[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
                count++;

    return count;
}

void solve()
{
    int n;
    cin >> n;
    int a[n] = {0};
    cin(a, n);
    cout << countbrute(a, n) << endl;
    cout << mergeSort(a, 0, n - 1) << endl;
    // cout(a, n);
}

int main()
{
    fast;
    solve();
    return 0;
}
