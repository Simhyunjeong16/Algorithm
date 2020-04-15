#include <iostream>
#include <vector>

using namespace std;

vector<int> a; //이제 벡터를 사용해보기
// int d[11];

int main(){
    int N, K;
    cin >> N >> K; //K원

    // for(int i=1; i<=N; i++){
    //     cin >> d[i];
    // }

    for(int i=0; i<N; i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    
    int r = 0;
    // for(int i=N; i>0; i--){
    //     r += K/d[i];
    //     K %= d[i];
    // }
    for(int i=N-1; i>=0; i--){
        r += K/a[i];
        K %= a[i];
    }


    cout << r << endl;
    
    return 0;
}