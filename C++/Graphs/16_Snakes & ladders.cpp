// Snakes and Ladders 
// The game of Snake and Ladder 
// You are at square 1 and have to reach square 100. You have complete control over 
// the die ans can get any number from 1-6. 
// For given ladders and snakes, find the minimum steps to reach. 
// 2 
// 3 90
// 56 76
// 3
// 99 10
// 30 20
// 20 5

// 3


#include<iostream>
#include<map>
#include<queue>
using namespace std;
int main(){
    int ladders, snakes;
    cin>>ladders;
    map<int,int> lad;
    map<int,int> snak;
    for (int i=0; i<ladders; i++){
        int u,v;
        cin>>u>>v;
        lad[u] = v;
    }
    cin>>snakes;
    for (int i=0; i<snakes; i++){
        int u,v;
        cin>>u>>v;
        snak[u] = v;
    }
    int moves = 0;
    queue<int> q;
    q.push(1);
    bool found = false;
    vector<int> vis(101,0);
    vis[1] = true;
    while(!q.empty() && !found){
        int sz = q.size();
        while(sz--){
            int t = q.front();
            q.pop();
            for (int die=1; die<=6; die++){
                if (t + die == 100){
                    found = true;
                }
                if (t + die <= 100 && lad[t+die] && !vis[lad[t+die]]){
                    vis[lad[t+die]] = true;
                    if (lad[t+die] == 100){
                        found = true;
                    }
                    q.push(lad[t+die]);
                }
                else if (t+die <= 100 && snak[t+die] && !vis[snak[t+die]]){
                    vis[snak[t+die]] = true;
                    if (snak[t+die] == 100){
                        found = true;
                    }
                    q.push(snak[t+die]);
                }
                else if (t+die <= 100 && !vis[t+die] && !snak[t+die] && !lad[t+die]){
                    vis[t+die] = true;
                    q.push(t+die);
                }
            }
        }
        moves++;
    }
    if (found){
        cout<<moves;
    }
    else{
        cout<<-1;
    }
    cout<<endl;
    return 0;
}