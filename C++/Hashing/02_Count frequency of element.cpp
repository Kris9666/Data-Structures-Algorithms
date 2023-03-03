// Hasing - Count frequency of elements 
// 6
// 1 2 1 3 2 1

// 1 3
// 2 2
// 3 1

// For Ordered map 
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define ff first
#define ss second 
#define setBits(x) builtin_popcount(x)

signed main(){
    int n;
    cin>>n;

    vi a(n);
    for (int i=0; i<n; i++){
        cin>>a[i];
    }
    map<int, int> freq;
    rep(i,0,n){
        freq[a[i]]++;
    }
    map<int, int> :: iterator it;
    for (it = freq.begin(); it!=freq.end(); it++){
        cout<<it->ff<<" "<<it->ss<<endl;               //ff means first and ss means second 
    }
}


// For Unordered map 
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define ff first
#define ss second 
#define setBits(x) builtin_popcount(x)

signed main(){
    int n;
    cin>>n;

    vi a(n);
    for (int i=0; i<n; i++){
        cin>>a[i];
    }
    unordered_map<int, int> freq;
    rep(i,0,n){
        freq[a[i]]++;
    }
    unordered_map<int, int> :: iterator it;
    for (it = freq.begin(); it!=freq.end(); it++){
        cout<<it->ff<<" "<<it->ss<<endl;               //ff means first and ss means second 
    }
}