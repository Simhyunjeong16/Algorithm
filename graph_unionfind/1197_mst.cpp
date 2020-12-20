#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int v, e;
int a, b, c;
int result = 0;
int parent[10001];
vector<pair<int, pair<int, int>>> edges;

int find_parent(int x){//루트(부모) 찾는 함수
    if(parent[x] != x){
        parent[x] = find_parent(parent[x]);
    }
    return parent[x];
}

void union_parent(int x, int y){
    x = find_parent(x);
    y = find_parent(y);

    if(x < y) parent[y] = x;
    else parent[x] = y;
}

int main(){//크루스칼 알고리즘

    cin >> v >> e;

    for(int i = 1; i <= v; i++){
        parent[i] = i;
    }

    while(e--){
        cin >> a >> b >> c;
        edges.push_back(make_pair(c, make_pair(a, b)));
    }

    sort(edges.begin(), edges.end());

    for(auto e : edges){
        int a_ = e.second.first;
        int b_ = e.second.second;
        int c_ = e.first;

        if(find_parent(a_) != find_parent(b_)){
            union_parent(a_, b_);
            result += c_;
        }
    }
    
    cout << result;
    return 0;
}