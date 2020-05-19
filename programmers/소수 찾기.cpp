#include <string>
#include <vector>
#include <set>
#include <math.h>

using namespace std;

vector<char> v;
int chk[7];
set<int> s;

void dfs(int cnt, int finish, string number){
    
    if(cnt == finish){
        string str = "";
        for(int i = 0; i < v.size(); i++){
            str += v[i];
        }
        
        int n = stoi(str);
        int end = (int) sqrt(n);//제곱근, ex)2*4 = 4*2랑 같으니까
        
        //소수가 아니라면 return
        if(n == 0 || n == 1) return;
        for(int i = 2; i <= end; i++){
            if((n % i) == 0) return;
        }
        
        s.insert(n);
        return;
    }
    
    
    for(int i = 0; i < number.size(); i++){
        if(chk[i]) continue;
        
        chk[i] = true;
        v.push_back(number[i]);
        
        dfs(cnt+1, finish, number);
        
        chk[i] = false;
        v.pop_back();
    }
}


int solution(string numbers) {
    
    for(int i = 1; i <= numbers.size(); i++){
        dfs(0, i, numbers);
    }
    
    return s.size();
}