// Kadane's Algorithm 
// Input : 8 
//         -5 -1 5 -3 -1 2 3 -6
// Output : 6


#include<iostream>
#include<vector>
#define vi vector<int>
#define rep(i,a,b) for(int i=a; i<b; i++)
using namespace std;
int main(){
    int n;
    cin>>n;
    vi a(n);
    rep(i,0,n){
        cin>>a[i];
    }
    int curr=0, maxTill=0;
    rep(i,0,n){
        curr+=a[i];
        maxTill = max(curr, maxTill); 
        if(curr<0){
            curr=0;
        }
    }
    cout<<maxTill<<endl;
    return 0;
}