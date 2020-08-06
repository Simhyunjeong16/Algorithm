#include <iostream>

using namespace std;

int a[10][10];
bool row[10][10];//row[a][b] = true; -> a번째 가로줄에 b라는 숫자 존재
bool col[10][10];//col[a][b] = true; -> a번째 세로줄에 b라는 숫자 존재
bool square[10][10];//square[a][b] = true; -> a번째 사각형에 b라는 숫자 존재
/* square 칸 정리
0 1 2 
3 4 5
6 7 8 ==> 사각형 구하는 방법 = (x좌표 / 3)*3 + (y좌표 / 3)
*/

void dfs(int cnt){

    if(cnt == 81){//끝까지 다돌았다!
        // cout << "\n";
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0);//스도쿠 판을 채우는 방법이 여럿인 경우 그 중 하나만 출력해야 해서 강제 종료!
    }

    //0 => (0, 0), 1 => (0, 1), 8 => (0, 8), 9 => (1, 0), 80 => (8, 8), 81 => (9, 0)
    int x = cnt / 9; //x좌표
    int y = cnt % 9; //y좌표

    if(a[x][y] == 0){
        for(int i = 1; i <= 9; i++){
            if(!row[x][i] && !col[y][i] && !square[(x/3)*3 + (y/3)][i]){
               
                a[x][y] = i;
                row[x][i] = true;
                col[y][i] = true;
                square[(x/3)*3 + (y/3)][i] = true;

                dfs(cnt+1);

                a[x][y] = 0;
                row[x][i] = false;
                col[y][i] = false;
                square[(x/3)*3 + (y/3)][i] = false;
            }
        }
    }
    else{
        dfs(cnt+1);
    }

}


int main(){

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> a[i][j];

            if(a[i][j] != 0){
                int t = a[i][j];//t라는 숫자가 존재
                int s_num = (i / 3) * 3 + (j / 3);
                
                row[i][t] = true;
                col[j][t] = true;
                square[s_num][t] = true;
            }
        }
    }

    dfs(0);

    return 0;
}