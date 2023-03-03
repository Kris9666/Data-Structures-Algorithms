// 0-N knapsack 
// Input : 5 
        // 3 2 4 5 1
        // 4 3 5 6 1 
        // 11
// Output : 16


#include<iostream>
#include<vector>
#define vi vector<int>
#define rep(i,a,b) for(int i=a; i<b; i++)
using namespace std;
int main(){
    int n;
    cin>>n;
    vi wt(n);
    rep(i,0,n){
        cin>>wt[i];
    }
    vi val(n);
    rep(i,0,n){
        cin>>val[i];
    }
    int w;
    cin>>w;
    vi dp(w+1,0);
    rep(j,0,w+1){
        rep(i,0,n){
            if(j-wt[i] >= 0){
                dp[j] = max(dp[j], val[i]+dp[j-wt[i]]);
            }
        }
    }
    cout<<dp[w];
}