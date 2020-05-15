#include <iostream>
#include <vector>

using namespace std;

int r, c, time;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int a[51][51];
int b[51][51];

vector<int> v;

int main(){
    cin >> r >> c >> time;

    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            cin >> a[i][j];

            if(a[i][j] == -1) v.push_back(i);//공기청정기
        }
    }
    
    for(int t = 0; t < time; t++){

        //미세먼지 확산
        for(int i=1; i<=r; i++){
            for(int j=1; j<=c; j++){

                if(a[i][j] != -1 && a[i][j] != 0){

                    int dust = a[i][j] / 5;
                    int cnt = 0;
                    for(int k = 0; k < 4; k++){
                        int nx = i + dx[k];
                        int ny = j + dy[k];

                        if(nx > 0 && nx <= r && ny > 0 && ny <= c && a[nx][ny] != -1){
                            b[nx][ny] += dust;
                            cnt++;
                        }
                    }

                    b[i][j] -= (dust * cnt);
                }

            }
        }
            
        for(int i=1; i<=r; i++){
            for(int j=1; j<=c; j++){
                a[i][j] += b[i][j];
                b[i][j] = 0;//재사용해야해서 초기화
            }
        }
        
        

        //위쪽 공기청정기 작동
        int vx = v[0];

        for(int k = vx-2; k >= 1; k--){//↓
            a[k+1][1] = a[k][1];
        }

        for(int k = 2; k <= c; k++){//←
            a[1][k-1] = a[1][k];
        }

        for(int k = 2; k <= vx; k++){//↑
            a[k-1][c] = a[k][c];
        }

        for(int k = c-1; k >= 2; k--){//→
            a[vx][k+1] = a[vx][k];
        }
        a[vx][2] = 0;//공기청정기 옆이니까


        //아래쪽 공기청정기 작동
        int vx2 = v[1];
        
        for(int k = vx2+2; k <= r; k++){//↑
            a[k-1][1] = a[k][1];
        }

        for(int k = 2; k <= c; k++){//←
            a[r][k-1] = a[r][k];
        }

        for(int k = r-1; k >= vx2; k--){//↓
            a[k+1][c] = a[k][c];
        }

        for(int k = c-1; k >= 2; k--){//→
            a[vx2][k+1] = a[vx2][k];
        }
        a[vx2][2] = 0;//공기청정기 옆이니까

        
    }


    int result = 0;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            if(a[i][j] != -1 && a[i][j] != 0) result += a[i][j];
        }
    }

    cout << result;
    return 0;
}