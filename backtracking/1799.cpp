#include <iostream>

using namespace std;

int n;
int a[10][10];
bool l[20]; //오른쪽에서 왼쪽으로 가는 대각선
bool r[20]; //왼쪽에서 오른쪽으로 가는 대각선
int bishop[2];

//color == 0 : 검정색, color == 1 : 흰색
void backtracking(int cnt, int x, int y, int color){
    if(y >= n){
        x++;
        if(y % 2 == 0) y = 1;//짝수행 -> 홀수행
        else y = 0;//홀수행 -> 짝수행
    }

    if(x >= n){
        bishop[color] = max(bishop[color], cnt);
        return;
    }

    if(a[x][y] && !l[y-x+n] && !r[x+y+1]){
        l[y-x+n] = r[x+y+1] = true;
        backtracking(cnt+1, x, y+2, color);//y+2 = 같은색 칸만 고려해주기 위해
        l[y-x+n] = r[x+y+1] = false;
    }

    backtracking(cnt, x, y+2, color);
}

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    backtracking(0, 0, 0, 0);//검정색 체스판
    backtracking(0, 0, 1, 1);//흰색 체스판

    cout << bishop[0] + bishop[1];
    return 0;
}

//이해 100프로 하지못함. 나중에 다시 풀어보기