#include <iostream>

using namespace std;

int main(){
    int n;
    int a[101][101];

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if((a[i][j] == 0) && (a[i][k] + a[k][j] == 2)) a[i][j] = 1;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}