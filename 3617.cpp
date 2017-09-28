#include<iostream>
#include <stdio.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    char S[2005];
    char T[2005];
    for(int i=0;i<n;i++){
        cin>>S[i];
    }
    int a=0,b=n-1; //S[a]...S[b]
    int id=0;
    while(a<=b){
        bool left=false;
        for(int i=0;a+i<=b;i++){
            if(S[a+i]<S[b-i]){
                left=true;
                break;
            }
            else if(S[a+i]>S[b-i]){
                left=false;
                break;
            }
        }
        if(left){
            putchar(S[a]);
            a++;
        }else{
            putchar(S[b]);
            b--;
        }
        id++;
        if(id%80==0)
            cout<<'\n';
    }
    
}