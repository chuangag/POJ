#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX_N=200000;

int parent[MAX_N];
int trank[MAX_N];

void init(int n){
    for(int i=0;i<n;i++){
        parent[i]=i;
        trank[i]=0;
    }
}

// return root of the tree x is in
int find(int x){
    if(parent[x]==x){
        return x;
    }else{
        return parent[x]=find(parent[x]);
    }
}

// unite set of x and y
void unite(int x,int y){
    int xset=find(x);
    int yset=find(y);
    if(xset==yset) return;
    if(trank[xset]<trank[yset]){
        parent[xset]=yset;
    }else{
        parent[yset]=xset;
        if(trank[xset]==trank[yset]) trank[xset]++;
    }
}

bool same(int x,int y){
    return find(x)==find(y);
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int type[100005],X[100005],Y[100005];
    for(int i=0;i<k;i++){
        scanf("%d %d %d",&type[i],&X[i],&Y[i]);
        //cin>>type[i]>>X[i]>>Y[i];
    }
    // x: x-A, x+n:x-B, x+2n: x-C
    init(3*n);

    int ans=0;
    for(int i=0;i<k;i++){
        int x=X[i]-1, y=Y[i]-1;
        if(x<0||x>=n||y<0||y>=n){
            ans++;
            continue;
        }
        if(type[i]==2&&x==y){
            ans++;
            continue;
        }
        if(type[i]==1){
            // same category
            if(same(x,y+n)||same(x,y+2*n)){
                ans++;
            }else{
                unite(x,y);
                unite(x+n,y+n);
                unite(x+2*n,y+2*n);
            }
        }else{
            // x eat y
            if(same(x,y)||same(x,y+2*n)){
                ans++;
            }else{
                unite(x,y+n);
                unite(x+n,y+2*n);
                unite(x+2*n,y);
            }
        }
    }
    cout<<ans<<endl;
}