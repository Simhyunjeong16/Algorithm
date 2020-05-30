#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){

    int n;
    stack<int> s;

    cin >> n;
    // scanf("%d", &n);
    // fgetc(stdin);//남아있는 \n 지워주기(버퍼비우기)

    for(int i = 0; i < n; i++){
        string str;
        getline(cin, str);//공백도 문자열로 받을 수 있다
        

        if(str == "pop"){
            if(s.empty()){
                printf("-1\n");
            }
            else{
                printf("%d\n", s.top());
                s.pop();
            }
        }
        else if(str == "top"){
            if(s.empty()){
                printf("-1\n");
            }
            else {
                printf("%d\n", s.top());
            }
        }
        else if(str == "size"){
            printf("%d\n", s.size());
        }
        else if(str == "empty"){
            printf("%d\n", s.empty());
        }
        else{//push
            string num = str.substr(5, str.size()-5);
            s.push(stoi(num));
        }
    }



    return 0;
}