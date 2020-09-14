#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> v;
    int n, m, x;
    int answer = 0;
    
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }

    int i = 0, j = 0;
    int sum = 0;

    while(1){//투포인터

        if(sum >= m){
            if(sum == m) answer++;
            sum -= v[j];
            j++; 
        }
        else if(i == n){
            break;
        }
        else if(sum < m){
            sum += v[i]; 
            i++;
        }
    }

    cout << answer;

    return 0;
}