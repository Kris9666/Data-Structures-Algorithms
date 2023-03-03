// Optimal game strategy 
// Input : 4 
//         1 2 3 4 
// Output : 6

// Recursion 
// #include "bits/stdc++.h"
// using namespace std;
// #define rep(i,a,b) for(int i=a; i<b; i++)
// vector<int> a;
// int Solve(int i, int j){
//     if(i == j){
//         return a[i];
//     }
//     if (i>j){
//         return 0;
//     }
//     int l = a[i] + min(Solve(i+2,j), Solve(i+1,j-1));
//     int r = a[j] + min(Solve(i,j-2), Solve(i+1,j-1));
//     return max(l,r);
// }
// int main(){
//     int n;
//     cin>>n;
//     a = vector<int>(n);
//     rep(i,0,n){
//         cin>>a[i];
//     }
//     cout<<Solve(0,n-1);
// }

// Memorization
// #include "bits/stdc++.h"
// using namespace std;
// #define rep(i,a,b) for(int i=a; i<b; i++)
// vector<int> a;
// int dp[100][100];
// int Solve(int i, int j){
//     if(i == j){
//         return a[i];
//     }
//     if (i>j){
//         return 0;
//     }
//     if(dp[i][j] != -1){
//         return dp[i][j];
//     }
//     int l = a[i] + min(Solve(i+2,j), Solve(i+1,j-1));
//     int r = a[j] + min(Solve(i,j-2), Solve(i+1,j-1));
//     dp[i][j] = max(l,r);
// }
// int main(){
//     rep(i,0,100){
//         rep(j,0,100){
//             dp[i][j] = -1;
//         }
//     }
//     int n;
//     cin>>n;
//     a = vector<int>(n);
//     rep(i,0,n){
//         cin>>a[i];
//     }
//     cout<<Solve(0,n-1);
// }