#include <iostream>
#include <vector>

using namespace std;

long long a[91] = {0, 1, };
vector<long long> v;

long long fibonacci(int n){//풀이방법2
    if(n == 0 || n == 1){
        return a[n];
    }
    else if(a[n] == 0){
        a[n] = fibonacci(n-1) + fibonacci(n-2);
    }

    return a[n];
}

int main(){
    int n;
    cin >> n;

    v.push_back(0);
    v.push_back(1);

    for(int i = 1; i < n; i++){//풀이방법1
        v.push_back(v[i-1] + v[i]);
    }

    cout << v[n];
    // cout << fibonacci(n);
    return 0;
}