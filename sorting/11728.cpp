#include <iostream>
using namespace std;

int n, m;
int a[1000001], b[1000001], c[2000002];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < m; i++){
        cin >> b[i];
    }

    int x = 0, y = 0;
    int idx = 0;
    while(x < n && y < m){
        if(a[x] < b[y]){
            c[idx++] = a[x++];
        }
        else{
            c[idx++] = b[y++];
        }
    }

    while(x < n) c[idx++] = a[x++];
    while(y < m) c[idx++] = b[y++];

    for(int i = 0; i < n+m; i++){
        cout << c[i] << " ";
    }

    return 0;
}
