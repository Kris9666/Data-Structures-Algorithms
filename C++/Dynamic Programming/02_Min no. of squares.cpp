// Minimum number of Squares whose sum equal to given number n.
// Input  = 5;
// Output = 2;

// Input  = 1024;
// Output = 1;


// Recursion Method 
#include<iostream>
using namespace std;
const int MOD = 1e5+2;
int MinSquare(int n){
    int ans=MOD;;
    if(n==0 || n==1 || n==2 || n==3){
        return n;
    }
    for(int i=1; i*i<=n; i++){
        ans = min(ans,1+MinSquare(n-i*i));
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    cout<<MinSquare(n);
    return 0;
}

// Memorization 
#include<iostream>
using namespace std;
const int N = 1e5+2, MOD=1e9+2;
int dp[N];
int MinSquare(int n){
    if(n==0 || n==1 || n==2 || n==3){
        return n;
    }
    if(dp[n]!=MOD){
        return dp[n];
    }
    for(int i=1; i*i<=n; i++){
        dp[n] = min(dp[n], 1+MinSquare(n-i*i));
    }
    return dp[n];
}
int main(){
    for(int i=0; i<N; i++){
        dp[i]=MOD;
    }
    int n;
    cin>>n;
    cout<<MinSquare(n)<<endl;
    return 0;
}


// Tabulation 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 1e5+2, MOD = 1e9+7;
int dp[N];
signed main(){
    int n;
    cin>>n;
    vector<int> dp(n+1, MOD);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for(int i=1; i*i<=n; i++){
        for(int j=0; i*i+j<=n; j++){
            dp[i*i+j] = min(dp[i*i+j], 1+dp[j]);
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}