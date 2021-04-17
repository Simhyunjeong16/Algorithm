#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<bool> a(10, true);
int n, m, b;
int answer;

bool chk(int x){

    string s = to_string(x);
    
    for(int i = 0; i < s.size(); i++){
        int t = s[i]-'0';
        if(!a[t]) return false;
    }
    
    return true;
}

int main(){
    cin >> n >> m;

    while(m--){
        cin >> b;
        a[b] = false;
    }

    answer = abs(n-100);//+-를 누른 횟수

    for(int i = 0; i <= 1000000; i++){
        if(chk(i)){
            int k = abs(n-i) + to_string(i).size();//+-를 누른 횟수 + 숫자를 누른 횟수
            answer = min(answer, k);            
        }
    }

    cout << answer;
    return 0;
}
