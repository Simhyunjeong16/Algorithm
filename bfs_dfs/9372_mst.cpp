#include <iostream>

using namespace std;

/*
Minimun Spanning Tree(MST): 최소 신장 트리, 그래프의 최소 연결 부분 그래프
--> n개의 정점을 가지는 그래프의 최소 간선의 수 = n-1
*/

int main(){
    
    int t;
    cin >> t;

    while(t--){

        int n, m;
        cin >> n >> m;

        for(int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
        }

        cout << n-1 << "\n";
    }

    
    return 0;
}