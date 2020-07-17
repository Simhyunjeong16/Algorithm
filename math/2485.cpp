#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int gcd(int a, int b){//최대공약수 -> 모든 구간에 대해 같은 간격으로 나눠야 해서
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main(){
    
    int n, x;
    cin >> n;

    vector<int> v;
    for(int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());//오름차순

    int min = gcd(v[1] - v[0], v[2] - v[1]);//맨앞 값 임의로 설정
    for(int i = 3; i < n; i++){

        int g = gcd(v[i-1] - v[i-2], v[i] - v[i-1]);
        
        if(min > g) min = g;
    }
   
    // int answer = 0;
    // for(int i = 1; i < n; i++){
    //     if(v[i] - v[i-1] != min){
    //         answer += (v[i] - v[i-1]) / min - 1;
    //     }
    // }

    int answer = (v[n-1] - v[0]) / min - n + 1;

    cout << answer;
    return 0;
}