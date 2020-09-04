#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> v;
vector<char> r;
int L, C;
char n;

void dfs(int pos, int cnt){//버전1

    if(cnt == L) {

        int a = 0, b = 0;//모음, 자음

        for(int i = 0; i < r.size(); i++){
            if(r[i] == 'a' || r[i] == 'e' || r[i] == 'i' || r[i] == 'o' || r[i] == 'u') a++;
            else b++;
        }
        
        if(a >= 1 && b >= 2){
            string str = "";
            for(int i = 0; i < r.size(); i++){
                str += r[i];
            }

            cout << str << "\n";
        }
        
        return;
    }


    for(int i = pos; i < C; i++){
        r.push_back(v[i]);
        dfs(i+1, cnt+1);
        r.pop_back();
    }

}

void dfs2(int pos, int cnt, int a, int b, string str){//버전2

    if(cnt == L) {

        if(a >= 1 && b >= 2){
            cout << str << "\n";
        }
        
        return;
    }


    for(int i = pos; i < C; i++){

        if(v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u'){
            dfs2(i+1, cnt+1, a+1, b, str+v[i]);
        }
        else{
            dfs2(i+1, cnt+1, a, b+1, str+v[i]);
        }
        
    }

}

int main(){
    
    cin >> L >> C;//암호의 길이, 사용한 알파벳의 개수
    
    for(int i = 0; i < C; i++){
        cin >> n;
        v.push_back(n);
    }

    sort(v.begin(), v.end());//증가하는 암호를 위해서

    // dfs(0, 0);
    dfs2(0, 0, 0, 0, "");

    return 0;
}