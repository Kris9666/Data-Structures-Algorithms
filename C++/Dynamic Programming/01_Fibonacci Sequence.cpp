// Fibonacci Sequence 
// Input  = 8;
// Output = 13;


// Recursive Method 
#include<iostream>
using namespace std;
int Fib(int n){
    if(n==0 || n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    return Fib(n-1)+Fib(n-2);
}
int main(){
    int n;
    cin>>n;
    
    cout<<Fib(n);
    return 0;
}

// Memorisation
#include<iostream>
using namespace std;
const int N = 1e5+2;
int dp[N];
int Fib(int n){
    if(n==0 || n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    else{
        dp[n]=Fib(n-1)+Fib(n-2);
    }
    return dp[n];
}
int main(){
    int n; cin>>n;

    for(int i=0; i<N; i++){
        dp[i]=-1;
    }
    cout<<Fib(n);
    return 0;
}

// Tabulation
#include<iostream>
#include<vector>
using namespace std;
const int N = 1e5+2, MOD = 1e9+7;
int dp[N];

signed main(){
    int n;
    cin>>n;

    vector<int> dp(n+1);

    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;

    for(int i=3; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout<<dp[n]<<endl;

    return 0;
}