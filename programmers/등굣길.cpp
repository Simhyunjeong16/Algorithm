#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int map[101][101] = {0,};
    int dist[101][101];
    
    for(auto p : puddles){
        map[p[1]][p[0]] = -1;//물 웅덩이
    }
    
    //(1,1)-> 시작지점을 1로 만들기 위해서 둘중에 하나를 1로 만든다
    // dist[1][0] = 1;
    dist[0][1] = 1;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(map[i][j] == -1) dist[i][j] = 0;//물 웅덩이라면
            else dist[i][j] = (dist[i-1][j] + dist[i][j-1]) % 1000000007; //왼쪽 칸 + 위칸
        }
    }
    
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= m; j++){
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    
    return dist[n][m];
}