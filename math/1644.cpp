#include <iostream>
#include <vector>

using namespace std;

int a[4000001];

int main(){

    vector<int> v;
    int answer = 0;

    int n;
    cin >> n;

    for(int i = 2; i <= n; i++){
        a[i] = i;
    }

    for(int i = 2; i <= n; i++){//에라토스테네스의 체
        if(a[i] == 0) continue;
        for(int j = i+i; j <= n; j += i){
            a[j] = 0;//소수 아닌 숫자들 지우기
        }
    }

    for(int i = 2; i <= n; i++){
        if(a[i] != 0){
            v.push_back(a[i]);
        }
    }

    //내 푼 방식
    // for(int i = 0; i < v.size(); i++){
    //     int r = 0;
    //     for(int j = i; j < v.size(); j++){
    //         r += v[j];
    //         if(r >= n){
    //             if(r == n) answer++;
    //             break;
    //         }
    //     }
    // }

    //투포인터 알고리즘
    int sum = 0;
    int low = 0, high = 0;
    while(1){
        
        if(sum >= n) sum -= v[low++];
        else if(high == v.size()) break;
        else sum += v[high++];

        if(sum == n) answer++;
    }


    cout << answer;
    return 0;
}