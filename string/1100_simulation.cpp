#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int answer = 0;
    string str;
    vector<string> v;

    for(int i = 0; i < 8; i++){
        cin >> str;
        v.push_back(str);
    }


    for(int i = 0; i < 8; i++){
        if((i%2) == 0){//짝수라면 하얀색부터 시작
            for(int j = 0; j < 8; j++){
                if((j%2) == 0 && v[i][j] == 'F'){
                   answer++; 
                }
            }
        }
        else{
            for(int j = 0; j < 8; j++){
                if((j%2) != 0 && v[i][j] == 'F'){
                   answer++;
                }
            }
        }
        
    }

    cout << answer;
    return 0;
}
