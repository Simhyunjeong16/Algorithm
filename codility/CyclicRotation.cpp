#include <vector>

using namespace std;

vector<int> solution(vector<int> &A, int K) {
    
    if(A.empty()) return A;//예외처리
    
    while(K--){
        A.insert(A.begin(), A.back());
        A.pop_back();
    }
    
    return A;
}
