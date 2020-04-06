#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n, m;
string dna[1001];
string result;
int sum = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); //cin 실행속도 향상
    cin >> n >> m; //DNA의 수, 문자열의 길이

    for(int i=0; i<n; i++)
        cin >> dna[i];
    
    int k;
    for(k=0; k<m; k++){

        int count[4] = {0,};//ACGT 사전순 초기화
        for(int j=0; j<n; j++){

            if(dna[j][k] == 'A') count[0]++;
            else if(dna[j][k] == 'C') count[1]++;
            else if(dna[j][k] == 'G') count[2]++;
            else if(dna[j][k] == 'T') count[3]++;
        }

        int tmp=0, r=0;
        for(int s=0; s<4; s++){
            if (r < count[s]){
                tmp = s;
                r = count[s];
            }   
        }

        sum += (n-r);

        if(tmp == 0) result += 'A';
        else if(tmp == 1) result += 'C';
        else if(tmp == 2) result += 'G';
        else if(tmp == 3) result += 'T';
    }
    
    cout << result << "\n" << sum << endl;

    return 0;
}