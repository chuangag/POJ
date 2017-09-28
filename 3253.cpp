#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int main(){
    int n;
    cin>>n;
    priority_queue <int, vector<int>, greater<int> > pq;
    for(int i=0;i<n;i++){
        int len;
        cin>>len;
        pq.push(len);
    }
    long long sum=0;
    while(n>1){
        int l1=pq.top();
        pq.pop();
        int l2=pq.top();
        pq.pop();
        sum+=(l1+l2);
        pq.push(l1+l2);
        n--;
    }
    cout<<sum<<endl;
}