#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue<int> q;
    int n;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    cin.ignore();

    for(int i = 0; i < n; i++){
        string str;
        getline(cin, str);

        if(str.substr(0, 4) == "push"){
            string res = str.substr(5);
            q.push(stoi(res));
        }
        else if(str == "size"){
            cout << q.size() << "\n";
        }
        else if(str == "empty"){
            cout << q.empty() << "\n";
        }
        else{
            if(q.empty()){
                cout << -1 << "\n";
            }
            else if(str == "front"){
                cout << q.front() << "\n";
            }
            else if(str == "back"){
                cout << q.back() << "\n";
            }
            else if(str == "pop"){
                cout << q.front() << "\n";
                q.pop();
            }
        }
        
    }


    return 0;
}
