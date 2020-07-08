#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main(){

    int t;//testcase 개수
    cin >> t;

    for(int i = 0; i < t; i++){

        deque<string> dq;
        int n;//배열에 들어있는 수 개수
        string p, arr;//함수, 배열

        cin >> p >> n >> arr;
        
        string x = "";
        for(int j = 1; j < arr.length(); j++){
            if(arr[j] == ',' || arr[j] == ']'){
                if(x == "") break;
                dq.push_back(x);
                x = "";
            }
            else{
                x += arr[j];
            }
        }

        bool flag = false;
        bool is_error = false;
        for(int k = 0; k < p.length(); k++){
            if(p[k] == 'R'){
                if(!flag) flag = true;
                else flag = false;
            }
            else if(p[k] == 'D'){
                if(dq.empty()) {
                    is_error = true;
                    break;
                }

                if(flag) dq.pop_back();
                else dq.pop_front();
            }
        }

        if(is_error){
            printf("error\n");
        }
        else if(dq.empty()){
            printf("[]\n");
        }
        else{
            string answer = "[";
            
            if(flag){
                for(auto r_it = dq.rbegin(); r_it != dq.rend(); r_it++){
                    answer += *r_it;
                    if(r_it == dq.rend()-1) answer += "]";
                    else answer += ",";
                }
            }
            else{
                for(auto it = dq.begin(); it != dq.end(); it++){
                    answer += *it;
                    if(it == dq.end()-1) answer += "]";
                    else answer += ",";
                }
            }

            cout << answer << "\n";
        }
    }

    return 0;
}