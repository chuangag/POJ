# include <iostream>
using namespace std;
void solve(int l,int n,int x[]){
    int minT=0,maxT=0;
    for(int i=0;i<n;i++){
        minT=max(minT,min(x[i],l-x[i]));
    }
    for(int i=0;i<n;i++){
        maxT=max(maxT,max(x[i],l-x[i]));
    }
    cout<<minT<<' '<<maxT;
}
int main(){
    const int MAX_n=1000000;
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int l,n;
        cin>>l>>n;
        int x[MAX_n];
        for(int j=0;j<n;j++){
            cin>>x[j];
        }
        solve(l,n,x);
    }
}