#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    
    for(int i = 0; i < phone_book.size()-1; i++){
        string book = phone_book[i];
        
        for(int j = i+1; j < phone_book.size(); j++){
            if(book == phone_book[j].substr(0, book.size())) return false;//접두어가 있는 경우
        }
    }
    
    return answer;
}
