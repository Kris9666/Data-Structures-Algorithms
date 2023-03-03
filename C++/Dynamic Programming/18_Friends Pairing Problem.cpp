// Friends pairing problem
// Given n friends, each one can remain single or can be paired up with some other friend.
// Each friend can be paired only once. Find out the total number of ways in which friends
// csn remain single or can be paired up.
// Input : 3
// Output : 4

#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,0);
    dp[0]=1;
    dp[1]=1;
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1]+(i-1)*dp[i-2];
    }
    cout<<dp[n];
    return 0;
}