#include <iostream>

using namespace std;

int a[51][51];
int b[51][51];

void Change(int x, int y){
    for(int i = x; i < x+3; i++){
        for(int j = y; j < y+3; j++){
            a[i][j] = 1 - a[i][j];//0->1, 1->0
        }
    }
}

int main(){
    
    int n, m;
    int answer = 0;

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%1d", &a[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%1d", &b[i][j]);
        }
    }

    for(int i = 0; i < n-2; i++){
        for(int j = 0; j < m-2; j++){
            if(a[i][j] != b[i][j]){
                Change(i, j);
                answer++;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] != b[i][j]){
                cout << -1;
                return 0;
            }
        }
    }


    cout << answer;
    return 0;
}
