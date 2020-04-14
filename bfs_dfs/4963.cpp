#include <iostream>
#include<string.h>

using namespace std;

int dx[8] = {0, 1, 0, -1, -1, 1, 1, -1};
int dy[8] = {1, 0, -1, 0, 1, 1, -1, -1};

int a[51][51];
bool chk[51][51];

int w, h;

void dfs(int x, int y){

    chk[x][y] = true;

    for(int i=0; i<8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && nx < h && ny >= 0 && ny < w){
            if(a[nx][ny] == 1 && chk[nx][ny] == false){
                dfs(nx, ny);
            }
        }   
    }
}


int main(){
    
    while(1){        
        cin >> w >> h;
        if(w == 0 && h == 0) break;

        int island = 0;
        memset(chk, false, sizeof(chk));

        for(int i=0; i<h; i++)
            for(int j=0; j<w; j++)
                cin >> a[i][j];


        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(a[i][j] == 1 && chk[i][j] == false){
                    // cout << i << " " << j << "\n";
                    dfs(i,j);
                    island++;
                }
            }
        }

        cout << island << endl;
    }


    return 0;
}