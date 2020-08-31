#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    vector<int> v;
    int n, m, a;
    int answer = 0;

    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        cin >> a;
        v.push_back(a);
    }

    
    //브루트 포스
    for(int i = 0; i < n-2; i++){
        for(int j = i+1; j < n-1; j++){
            for(int k = j+1; k < n; k++){
                int sum = v[i] + v[j] + v[k];

                if(sum > answer && sum <= m) answer = sum;

            }
        }
    }


    cout << answer;
    return 0;
}