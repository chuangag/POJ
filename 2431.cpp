#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct fuel_stop{
    int pos;
    int fuel;
} stop[10005];
bool cmp(fuel_stop a, fuel_stop b){
    return a.pos<b.pos;
}
int main(){
    
    int n;
    cin>>n;
    // the destination
    stop[0].pos=0;stop[0].fuel=0;
    for(int i=1;i<n+1;i++){
        int l,p;
        cin>>l>>p;
        stop[i].pos=l;stop[i].fuel=p;
    }
    int L,P;
    cin>>L>>P;

    // Input might not be in order
    sort(stop, stop + n+1, cmp);

    priority_queue<int> q;
    int ans=0;
    for(int i=n;i>=0;i--){
        //distance to next stop
        int d=L-stop[i].pos;
        while(P<d){
            if(q.empty()){
                cout<<"-1"<<endl;
                return 0;
            }
            P+=q.top();
            q.pop();
            ans++;
        }
        P-=d;
        L=stop[i].pos;
        q.push(stop[i].fuel);
    }
    cout<<ans<<endl;
    return 0;
}