#include <iostream>

using namespace std;

int n, m;
int a, b, c;//버스의 시작 도시, 도착 도시, 비용
int v[101][101];
const int INF = 1e9;//최대값

int main(){
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i != j){//시작 도시와 도착 도시가 같은 경우는 없다.
                v[i][j] = INF;
            }
        }
    }

    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        v[a][b] = min(v[a][b], c);
    }
    
    //플로이드 와샬
    for(int k = 1; k <= n; k++){//거쳐가는 도시
        for(int i = 1; i <= n; i++){//시작 도시
            for(int j = 1; j <= n; j++){//도착 도시
                v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(v[i][j] == INF) cout << 0 << " ";//i에서 j로 갈 수 없는 경우에는 그 자리에 0을 출력
            else cout << v[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
