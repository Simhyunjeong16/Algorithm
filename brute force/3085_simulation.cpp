#include <iostream>
#include <algorithm>

using namespace std;

int n;
char a[51][51];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int answer = 0;

void row(){//행 계산
    for(int i = 0; i < n; i++){
        int cnt = 1;
        int t = a[i][0];
        for(int j = 1; j < n; j++){
            if(t == a[i][j]) cnt += 1;
            else cnt = 1;

            t = a[i][j];
            answer = max(answer, cnt);
        }
    }
}

void column(){//열 계산
    for(int j = 0; j < n; j++){
        int cnt = 1;
        int t = a[0][j];
        for(int i = 1; i < n; i++){
            if(t == a[i][j]) cnt += 1;
            else cnt = 1;

            t = a[i][j];
            answer = max(answer, cnt);
        }
    }
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }


    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){

            //가로 교환
            swap(a[i][j], a[i][j+1]);
            row();
            column();
            swap(a[i][j], a[i][j+1]);
        }
    }

    for(int j = 0; j < n; j++){
        for(int i = 0; i < n-1; i++){

            //세로 교환
            swap(a[i][j], a[i+1][j]);
            row();
            column();
            swap(a[i][j], a[i+1][j]);
        }
    }
    cout << answer;
    return 0;
}
