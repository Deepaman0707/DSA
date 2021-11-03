#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
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

//recursive approach
// int decideJump(int a[], int n, int currPos)
// {
//     if (currPos >= n - 1)
//     {
//         return 0;
//     }
//     int minJump = INT_MAX, maxSteps = a[currPos];
//     while (maxSteps > 0)
//     {
//         minJump = min(minJump, 1 + decideJump(a, n, currPos + maxSteps));
//         maxSteps = maxSteps - 1;
//     }
//     return minJump;
// }

// void jump()
// {
//     int n;
//     cin >> n;
//     int a[n];
//     cin(a, n);
//     cout << decideJump(a, n, 0);
// }

//Greedy method
void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    int a[n];
    cin(a, n);
    if (a[0] == 0)
        cout << "Cannot reach the end." << endl;
    int maxreach = a[0], steps = a[0], jump = 1;
    for (int i = 1; i < n; i++)
    {
        if (i == n - 1)
            cout << jump;
        maxreach = max(maxreach, (i + a[i]));
        steps--;
        if (steps == 0)
        {
            jump++;
            if (i >= maxreach)
                cout << "Cannot reach the end." << endl;
            steps = maxreach - i;
        }
    }
}

int main()
{
    fast;
    solve();
    // jump();
    return 0;
}