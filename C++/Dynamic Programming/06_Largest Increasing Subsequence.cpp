// Largest Increasing Subsequence 
// Input : 9
//         10 22 9 33 21 50 56 60 80
// Output : 7



// Recursion 
#include<iostream>
#include<vector>
#define vi vector<int>
#define rep(i,a,b) for(int i=a; i<b; i++)
using namespace std;
int LarSub(int n, vi &a){
    int ans=1;
    for(int i=0; i<n; i++){
        if(a[n]>a[i]){
            ans = max(ans, 1+LarSub(i,a));
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vi a(n);
    rep(i,0,n){
        cin>>a[i];
    }
    if(n<=0){
        return 0;
    }
    cout<<LarSub(n-1, a);
}


// Memorization 
// #include<iostream>
// #include<vector>
// #define vi vector<int>
// #define rep(i,a,b) for(int i=a; i<b; i++)
// using namespace std;
// const int N = 1e5+2;
// int dp[N];
// int LarSubsequence(int n, vi &a){
//     if(dp[n] != -1){
//         return dp[n];
//     }
//     dp[n] = 1;
//     rep(i,0,n){
//         if(a[n]>a[i]){
//             dp[n] = max(dp[n], 1+LarSubsequence(i,a));
//         }
//     }
//     return dp[n];
// }
// int main(){
//     rep(i,0,N){
//         dp[i] = -1;
//     }
//     int n;
//     cin>>n;
//     vi a(n);
//     rep(i,0,n){
//         cin>>a[i];
//     }
//     if(n<=0){
//         return 0;
//     }
//     cout<<LarSubsequence(n-1,a);
// }


// Tabulation 
// #include<iostream>
// #include<vector>
// #define vi vector<int>
// #define rep(i,a,b) for(int i=a; i<b; i++)
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     vi a(n);
//     rep(i,0,n){
//         cin>>a[i];
//     }
//     vi dp(n,1);
//     int ans = 0;
//     rep(i,1,n){
//         rep(j,0,i){
//             if(a[i]>a[j]){
//                 dp[i] = max(dp[i], 1+dp[j]);
//             }
//         }
//         ans = max(ans, dp[i]);
//     }
//     cout<<ans;
// }

