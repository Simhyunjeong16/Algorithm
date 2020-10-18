#include <iostream>
#define MAX 101

using namespace std;

int main(){
    
    int t, x, y;
    int answer = 0;
    bool a[MAX][MAX] = {false, };

    cin >> t;

    for(int k = 0; k < t; k++){
        cin >> x >> y;//색종이를 붙인 위치
        
        for(int i = x; i < x+10; i++){
            for(int j = y; j < y+10; j++){
                if(!a[i][j]) a[i][j] = true;
            }
        }
    }

    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(a[i][j]) answer++;
        }
    }

    cout << answer;

    return 0;
}
