#include<bits/stdc++.h>
using namespace std;

const int max_val=1000;
int v,e;
vector<pair<int,int>> adj[max_val];
vector<bool> used(max_val, false);

struct side{
    int x,y,w;
};

void nhap(){
    cin >> v >> e;
    int i =e;
    while(i--){
        int x,y,w ;
        cin >> x >> y >> w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
}

void prim(){
    int u; cin >> u;
    vector<side> MST;
    int sum_w=0;
    used[u]=true;
    while(MST.size() < v-1){
        int min_w=INT_MAX;
        int x,y;
        for(int i=1; i<=v; i++){
            if(used[i]){
                for(pair<int,int> temp : adj[i]){
                    int j=temp.first, weight=temp.second;
                    if(!used[j] && weight < min_w){
                        min_w=weight;
                        x=j;
                        y=i;
                    }
                }
            }
        }
        sum_w+=min_w;
        MST.push_back({x,y,min_w});
        used[x]=true;
    }

    cout << "\n\nMST: " << sum_w << endl;
    for(side t: MST) cout << t.x << " " << t.y << " " << t.w << endl;
}

int main(){
    nhap();
    prim();
    system("pause");
    return 0;
}