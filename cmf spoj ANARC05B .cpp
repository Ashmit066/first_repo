#include<iostream>
#include<string>
#include<vector>
 
using namespace std;
 
int main(){
 
	while(true){
		int n1,n2;
 
		vector<int> first_row;
		vector<int> second_row;
 
		cin >> n1;
		if(n1==0) break;
 
		for(int i=0;i<n1;i++){
			int temp;
			cin >> temp;
			first_row.push_back(temp);
		}
 
		cin >> n2;
		for(int i=0;i<n2;i++){
			int temp;
			cin >> temp;
			second_row.push_back(temp);		
		}		
 
		long long int s1 = 0 , s2 = 0; 
 
		// first row pointer
		int i = 0;
		// second row pointer
		int j = 0 ;
 
		first_row.push_back(10001);
		second_row.push_back(10001);
 
		n1++;
		n2++;
 
		long long int answer = 0;
 
		while( i < n1 && j < n2 ){
			// move in right direction in first row
			if( first_row[i] < second_row[j] ){
				s1 += first_row[i] ;
				i++;
			}else if( first_row[i] > second_row[j] ){
				s2 += second_row[j];
				j++;
			}else {// when both elements are equal 
				answer += ( s1 >= s2 ? s1 : s2 ) + first_row[i];
				s1 = 0;
				s2 = 0;
				i++;
				j++;
			}
		}
 
		cout << answer - 10001 << endl;
 
	}
 
	return 0;
}
