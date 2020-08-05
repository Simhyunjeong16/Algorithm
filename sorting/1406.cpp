#include <iostream>
#include <list>
#include <string>
using namespace std;

int main(){

    int m;
    list<char> lst;
    string str;//초기 입력 문자열
    
    cin >> str >> m;
    
    for (int i = 0; i < str.length(); i++) lst.push_back(str[i]);
    auto cursor = lst.end();

    for(int i = 0; i < m; i++){
        char c;
        cin >> c;
        
        if(c == 'L' && cursor != lst.begin()){//커서를 왼쪽으로 한칸 옮김
            cursor--;
        }
        else if(c == 'D' && cursor != lst.end()){//커서를 오른쪽으로 한칸 옮김
            cursor++;
        }
        else if(c == 'B' && cursor != lst.begin()){//커서 왼쪽에 있는 문자 삭제
            cursor--;
            cursor = lst.erase(cursor);//POINT!!!!
        }
        else if(c == 'P'){//커서 왼쪽에 추가
            char s;
            cin >> s;
            lst.insert(cursor, s);
        }
    }
    
    for(auto it = lst.begin(); it != lst.end(); it++){
        cout << *it;
    }

    return 0;
}