#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string s;
    int cnt = 0;
    vector<string> v = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

    cin >> s;

    for(int i = 0; i < v.size(); i++){
        while(1){
            int a = s.find(v[i]);
            if(a == string::npos) break;

            s.replace(a, v[i].length(), "#");//a번째 인자에서부터 v[i].length()개를 #으로 대체
        }
    }
    
    cout << s.length();
    return 0;
}
