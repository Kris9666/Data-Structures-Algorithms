// 0-1 Knapsack Problem 
// Input : n=3, wt[] = {15,30,45}, val[] = {60,100,150}, w=50
// Output : 160 

// Recursion 
// #include<iostream>
// #include<algorithm>
// #include<vector>
// #define vi vector<int>
// #define rep(i,a,b) for(int i=a; i<b; i++)
// using namespace std;
// const int N = 1e5+2;
// int val[N], wt[N];
// int Knapsack(int n, int w){
//     if(w<=0 || n<=0){
//         return 0;
//     }
//     if(wt[n-1]<=w){
//         return max(Knapsack(n-1,w-wt[n-1]) + val[n-1], Knapsack(n-1,w));
//     }
//     else if(wt[n-1]>w){
//         return Knapsack(n-1,w);
//     }
// }
// int main(){
//     int n;
//     cin>>n;
//     rep(i,0,n){
//         cin>>wt[i];
//     }
//     rep(i,0,n){
//         cin>>val[i];
//     }
//     int w;
//     cin>>w;

//     cout<<Knapsack(n,w);
//     return 0;
// }

// Memorization 
// #include<iostream>
// #include<vector>
// using namespace std;
// const int N = 1e3+2;
// int wt[N], val[N], dp[N][N];
// int Knapsack(int n, int w){
//     if(n<=0 || w<=0){
//         return 0;
//     }
//     if(dp[n][w]!=-1){
//         return dp[n][w];
//     }
//     if(wt[n-1]<=w){
//         dp[n][w] = max(Knapsack(n-1,w-wt[n-1])+val[n-1], Knapsack(n-1,w)); 
//     }
//     else if(wt[n-1]>w){
//         dp[n][w] = Knapsack(n-1,w);
//     }
//     return dp[n][w];
// }
// int main(){
//     int n;
//     cin>>n;
//     for(int i=0; i<n; i++){
//         cin>>wt[i];
//     }
//     for(int i=0; i<n; i++){
//         cin>>val[i];
//     }
//     int w;
//     cin>>w;
//     for(int i=0; i<N; i++){
//         for(int j=0; j<N; j++){
//             dp[i][j] = -1;
//         }
//     }
//     cout<<Knapsack(n,w);
//     return 0;
// }

// Tabulation 
#include<iostream>
#include<vector>
#define vi vector<int>
using namespace std;
int main(){
    int n;
    cin>>n;
    vi wt(n);
    for(int i=0; i<n; i++){
        cin>>wt[i];
    }
    vi val(n);
    for(int i=0; i<n; i++){
        cin>>val[i];
    }
    int w;
    cin>>w;

    int t[n+1][w+1];
    for(int i=0; i<n+1; i++){
        for(int j=0; j<w+1; j++){
            if(i==0 || j==0){
                t[i][j] = 0;
            }
        }
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<w+1; j++){
            if(wt[i-1]<=j){
                t[i][j] = max(val[i-1]+t[i-1][j-wt[i-1]], t[i-1][j]); 
            }
            else if(wt[i-1]>j){
                t[i][j] = t[i-1][j];
            }
        }
    }
    cout<<t[n][w];
}