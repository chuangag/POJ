#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

void solve(int x[], int r, int n)
{
    sort(x,x+n);
    int i=0,ans=0;
    while(i<n){
        // s is the most left uncovered point
        int s=x[i];
        //i++;
        // go foward till x[i]-s > r
        while(i<n&&x[i]<=s+r) i++;
        // the new marked point
        int mark=x[i-1];
        while(i<n&&x[i]<=mark+r) i++;
        ans++;
    }
    cout<<ans<<endl;
}
int main()
{
    int r, n;
    cin >> r >> n;
    while (r != -1 || n != -1)
    {
        int x[1005];
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
        }
        solve(x, r, n);
        cin >> r >> n;
    }
}