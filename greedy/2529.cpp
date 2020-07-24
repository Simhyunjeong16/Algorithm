#include <iostream>
#include <vector>

using namespace std;

int k;
char x;
string minvalue = "9999999999", maxvalue = "-1";
vector<int> res;
vector<char> sign;
int chk[10] = { false, };

void dfs(int n, int cnt){
    if(cnt == k+1){//끝까지 다 돌렸을 때
        
        string str = "";
        for(int i = 0; i < res.size(); i++){
            str += (char)(res[i] + '0');
        }
        
        if(str > maxvalue) maxvalue = str;//최댓값
        if(str < minvalue) minvalue = str;//최솟값

        return;
    }

    if(sign[cnt-1] == '>'){//1부터 시작하니까 -1을 해야 함
        for(int i = 0; i < n; i++){//이전에 온 것 보다 작은 값 넣기
            if(chk[i]) continue;

            chk[i] = true;
            res.push_back(i);

            dfs(i, cnt+1);
            
            chk[i] = false;
            res.pop_back();
        }

    }
    else if(sign[cnt-1] == '<'){
        for(int i = n+1; i <= 9; i++){//이전에 온 것보다 큰 값 넣기
            if(chk[i]) continue;
            
            chk[i] = true;
            res.push_back(i);

            dfs(i, cnt+1);
            
            chk[i] = false;
            res.pop_back();
        }

    }

    return;
}


int main(){
    
    cin >> k;//부등호 문자의 개수

    for(int i = 0; i < k; i++){
        cin >> x;
        sign.push_back(x);//부등호 넣기
    }

    for(int i = 0; i <= 9; i++){
        chk[i] = true;
        res.push_back(i);

        dfs(i, 1);//n, cnt
        
        chk[i] = false;
        res.pop_back();
    }
    

    cout << maxvalue << "\n" << minvalue;
    
    return 0;
}