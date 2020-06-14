#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, s, a;
int answer = 0;
vector<int> v;

void dfs(int i, int sum){

    sum += v[i];

    if(i == n) {//노드가 끝까지 간 경우
        return;
    }

    if(sum == s){
        answer++;
    }
    
    dfs(i+1, sum - v[i]);//인덱스 노드를 포함하지않는 경우
    dfs(i+1, sum);//인덱스 노드를 포함하는 경우
}


int main(){

    cin >> n >> s;
    
    for(int i = 0; i < n; i++){
        cin >> a;
        v.push_back(a);
    }

    dfs(0, 0);

    cout << answer;

    return 0;
}