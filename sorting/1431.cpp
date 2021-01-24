#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(string A, string B){

    //1)
    if(A.length() != B.length()){
        return A.length() < B.length();//A와 B의 길이가 다르면, 짧은 것이 먼저 온다.
    }

    //2)
    int sum_a = 0, sum_b = 0;

    for(int i = 0; i < A.length(); i++){//숫자인것만 더하기
        if(isdigit(A[i]) == true) sum_a += (A[i] -'0');
        if(isdigit(B[i]) == true) sum_b += (B[i] -'0');
    }
    
    if(sum_a != sum_b) return sum_a < sum_b;//작은 합을 가지는 것이 먼저옴.

    //3)
    return A < B;//사전순
    
}

int main(){
    int n;
    string str;
    vector<string> v;

    cin >> n;

    for(int i = 0; i < n; i++){//(A-Z)와 (0-9)로 이뤄져 있음.
        cin >> str;
        v.push_back(str);
    }

    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < n; i++){
        cout << v[i] << "\n";
    }

    return 0;
}
