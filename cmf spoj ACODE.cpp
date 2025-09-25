#include<iostream>
#include<string>
#include<vector>
 
using namespace std;
 
int countWays(string s){
    // 25114
    // n = 5
    int n = s.size() ;
    
    vector<int> answer( n, 0 ); // O(n)
    answer[0] = 1;       
    for(int i=1;i<n;i++){
        // ith character must not be 0
        if( s[i] != '0'){
            // Using ith character independently
            // We are treating ith character as directly appending
            answer[i] = answer[i-1];
        }
        //10 .... 19       (i-1)th should be 1
        //20 ..... 26      (i-1)th should be 2 but ith char shoul <= 6
        if( s[i-1]=='1' || ( s[i-1]=='2' && s[i] <= '6' )  )  
        { 
            if( i==1 ){
                answer[i] += 1; 
            }else{
                answer[i] += answer[i-2]; 
            }
        }
    }
    
    return answer[n-1];
}
 
int main(){
    
    while(true){
        string s;
        cin>>s;
        //25114
        if(s[0]=='0'){
            break;
        }
        cout << countWays(s) << endl ;
    }
    return 0;
}
