// Number of Subsequences 
// Input : n=6, string=ac?b?c
// Output : 24

#include<iostream>
#include<vector>
#include<string.h>
#define vi vector<int>
#define rep(i,a,b) for(int i=a; i<b; i++)
using namespace std;
int main(){
    int n;
    cin>>n;
    string st;
    cin>>st;
    int e=1,a=0,ab=0,abc=0;
    rep(i,0,n){
        if(st[i] == 'a'){
            a+=e;
        }
        else if(st[i] == 'b'){
            ab+=a;
        }
        else if(st[i] == 'c'){
            abc+=ab;
        }
        else if(st[i] == '?'){
            abc = 3*abc+ab;
            ab = 3*ab+a;
            a = 3*a+e;
        }
    }
    cout<<abc<<endl;
    return 0;
}