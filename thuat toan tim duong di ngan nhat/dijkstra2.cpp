#include<iostream>
#include<cstring>
#include<vector>
#include<map>
using namespace std;

using ll = long long;
const int max_val=1000;
const int inf = 1e9;

int v,e;
vector<pair<int,int>> adj[max_val];

struct side{
    int x,y,w;
};

void input(){
    cin >> v >> e;
    for(int i=1; i<=e; i++) {
        int x,y,w;
        cin >> x >> y >> w;
        adj[x].push_back({y,w});
    }
}

void dijkstra(){
    int s; cin >> s;                 // nhap diem bat dau
    vector<ll> d(v+1, inf);                        // mang chua khoang cach tu diem bat dau den cac diem con lai
    d[s] = 0;                       // khoi tao khoang cach cua diem bat dau = 0
    vector<bool> used(v+1, false);                 // mang kiem tra diem da duoc duyet hay chua
    int sum_w=0;

    // mang khoang cach cua cac diem, di tu diem bat dau
    // {trong so, dinh}
    multimap<int,int> mp;
    mp.insert({0,s});
    vector<vector<int>> road;

    while( !mp.empty() ){
        // lay diem co trong so nho nhat va xoa diem do ra khoi mang diem ban dau
        pair<int,int> top = *mp.begin();    mp.erase(mp.begin());
        int a = top.second;
        if(used[a]) continue;
        bool flag = false;
        for(pair<int,int> temp: adj[a]){        // duyet cac canh ke cua dinh a
            int b = temp.first;
            int w = temp.second;
            // cap nhat duong di den cac dinh
            if(d[b] > d[a] + w){
                d[b] = d[a] + w;
                mp.insert({d[b],b});
                sum_w+=w;
                flag = true;
            }
        }
        used[a]=true;
        if(flag) {
            road.push_back(a);
        }
        else {
            road[road.data()].push_back(a);
        }
    }

    cout << "\nMST: " << sum_w << endl;
    cout << "Khoang cach tu dinh " << s << " toi cac dinh: ";
    for(int i=1; i<=v; i++) cout << s << "->" << i << ":" << d[i] << "  ";
    cout << "Duong di: ";

    for(int i=1; i<=v; i++){
        if(road[i].size() != 1){
            for(int x: road[i]) cout << x << " ";
        } else cout << endl;
    }
}

int main(){
    input();
    dijkstra();
    system("pause");
    return 0;
}   