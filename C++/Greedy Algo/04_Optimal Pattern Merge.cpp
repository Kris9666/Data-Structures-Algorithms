// Optimal Pattern Merge 
// You are given n files with their computation times in a array.
// Choose any two files, add their computation times and append it to the 
// list of computation times. {cost  = sum of computation time}. 
// Do this until we are left with only one file in the array. We have to do this 
// operation such that we get minimum cost finally.
// Input : 4 
//         5 2 4 7
// Output : 35


#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define int long long

signed main(){
    int n;
    cin>>n;

    vector<int> a(n);
    for (int i=0; i<n; i++){
        cin>>a[i];
    }
    priority_queue<int, vector<int>, greater<int>> minheap;
    for (int i=0; i<n; i++){
        minheap.push(a[i]);
    }
    int ans = 0;
    while(minheap.size() > 1){
        int e1 = minheap.top();
        minheap.pop();
        int e2 = minheap.top();
        minheap.pop();

        ans += e1 + e2;
        minheap.push(e1 + e2);
    }
    cout<<ans<<endl;
    return 0;
}