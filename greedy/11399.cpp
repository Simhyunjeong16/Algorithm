#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> p;

int main(){
    int N;
    cin >> N;

    for(int i=0; i<N; i++){
        int x;
        cin >> x;
        p.push_back(x);
    }

    //인출하는데 걸리는시간이 적은 순서대로 정렬한 뒤 시간의 합을 구하면 된다.
    sort(p.begin(), p.end());

    int r = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<=i; j++){
            r += p[j];
        }
    }

    //이런식으로 풀어도된다.
    // for(int i=0; i<N; i++){
    //         r += p[i]*(N-i);
    // }

    cout << r << endl;

    return 0;

}