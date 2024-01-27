#include<iostream>
#include<map>
using namespace std;
const int max_val=1000;
int v,e;
map<int,pair<int,int>> adj[max_val];
bool used[max_val];
void input(){
    cin >> v >> e;
    int i = e;
    while(i--){
        int x,y,w;
        cin >> x >> y >> w;
        adj[x].insert({y,w});
    }
    memset(used, false, sizeof(used));
}
void kruskal(){
    vector<pair<int,int>> MST;
    int sum_w=0;
    used[(*G->begin()).second.first]=true;
    while(MST.size() < v-1){
        auto 

    }

}

int main(){
    input();
    kruskal();
    system("pause");
    return 0;
}