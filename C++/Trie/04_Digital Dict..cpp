// Digital Dictionary 
// Neha has a digital dictionary. It has an input field in which one can search
// any string and the dictionary displays all the words whose prefix is that input 
// string in lexicographical order.
// Now you are given a task to make your own digital dictionary. You will be given 
// words that you can store in your database and then you need to design the search
// functionality. And if no such words are available for a given search word, add 
// this word to your dictionary.
// Input : 4
// Input : rat
// Input : rack  
// Input : bat 
// Input : batman
// Input : 3
// Input : r
// Output : rack
// Output : rat
// Input : bat
// Output : bat
// Output : batman
// Input : quick
// Output : No suggestion

#include<bits/stdc++.h>
using namespace std;
class node{
public:
    node* next[26];
    bool end;
    node(){
        for(int i=0; i<26; i++){
            next[i] = NULL;
        }
        end = false;
    }
};
class Trie{
private:
    node* root;
public:
    Trie(){
        root = new node();
    }
    void insert(string &s){
        node* it = root;
        for(auto c : s){
            if(!it->next[c-'a']){
                it->next[c-'a'] = new node();
            }
            it = it->next[c-'a'];
        }
        it->end = true;
    }
    void find(string &s){
        node* it = root;
        for(auto c : s){
            if(!it->next[c-'a']){
                cout<<"No suggestion\n";
                insert(s);
                return;
            }
            it = it->next[c-'a'];
        }
        vector<string> res;
        printall(it,s,res,"");
        for(auto c : res){
            cout<<s<<c<<endl;
        }
    }
    void printall(node* it, string &s, vector<string> &res, string cur){
        if(it == NULL){
            return;
        }
        if(it->end){
            res.push_back(cur);
        }
        for(int i=0; i<26; i++){
            if(it->next[i]){
                printall(it->next[i],s,res,cur + char('a'+i));
            }
        }
    }
};
int32_t main(){
    Trie t;
    int n;
    cin>>n;
    vector<string> a(n);
    for(auto &i : a){
        cin>>i;
        t.insert(i);
    }
    int q;
    cin>>q;
    while(q--){
        string s;
        cin>>s;
        t.find(s);
    }
    return 0;
}