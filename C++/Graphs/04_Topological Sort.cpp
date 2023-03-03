// Graphs - Topological Sort 
// 4 3
// 0 1
// 1 2
// 2 3
// 0 1 2 3 
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int cnt = 0;
    vector<vector<int>> adj(n);
    vector<int> indeg(n,0);
    for (int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        // u-->v
        adj[u].push_back(v);
        indeg[v]++;
    }
    queue<int> pq;
    for (int i=0; i<n; i++){
        if (indeg[i] == 0){
            pq.push(i);
        }
    }
    while(!pq.empty()){
        cnt++;
        int x = pq.front();
        pq.pop();
        cout<<x<<" ";
        for(auto it: adj[x]){
          
            if (indeg[it] == 0){  indeg[it]--;
                pq.push(it);
            }
        }
    }
    return 0;
}