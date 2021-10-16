#include <iostream>
#include <string>

using namespace std;

string str;
char a[3][3];

bool checking(char r){

    bool chk = false;
    for(int i = 0; i < 3; i++){
        if (a[i][0] == r && a[i][0] == a[i][1] && a[i][1] == a[i][2]) chk = true;//가로
        if (a[0][i] == r && a[0][i] == a[1][i] && a[1][i] == a[2][i]) chk = true;//세로
    }

    //대각선
    if(a[1][1] == r){
        if(a[1][1] == a[0][0] && a[0][0] == a[2][2]) chk = true;
        if(a[1][1] == a[0][2] && a[0][2] == a[2][0]) chk = true;
    }
    return chk;
}

int main(){

    while(cin >> str){
        if(str == "end") break;

        int cnt_x = 0, cnt_o = 0;

        for(int i = 0; i < 9; i++){
            a[i/3][i%3] = str[i];

            if(str[i] == 'X') cnt_x++;
            else if(str[i] == 'O') cnt_o++;
        }


        if(checking('X') && !checking('O') && cnt_x-1 == cnt_o){//X가 이김
            cout << "valid" << endl;
        }
        else if(!checking('X') && checking('O') && cnt_x == cnt_o){//O가 이김
            cout << "valid" << endl;
        }
        else if(!checking('X') && !checking('O') && cnt_x == 5 && cnt_o == 4){//비김
            cout << "valid" << endl;
        }
        else{
            cout << "invalid" << endl;
        }
    }

    return 0;
}