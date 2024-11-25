#include <iostream>
#include <string>
using namespace std;

bool TwoOrThree1(const string& input){
	int state = 0;
	for(int i=0;i<input.length();i++){
		if(input[i]=='1'){
			if(state==0){
				state=1;
			}else if(state==1){
				state=2;
			}else if(state==2){
				state=3;
			}else if(state==3){
				return false;
			}
		}else if(input[i]=='0'){
			if(state==0){
				state=0;
			}else if(state==1){
				state=1;
			}else if(state==2){
				state=2;
			}else if(state==3){
				state=3;
			}
		}
		
	}
	
	if(state==2||state==3){
		return true;
	}
	else{
		return false;
	}
	
}


int main(){
	string input;
	cout<<"Enter any string over {0, 1} :";
	cin>>input;
	
	if(TwoOrThree1(input)){
		cout<<"Accepted!!!";
	}else{
		cout<<"Rejected!!!";
	}
	
	return 0;
}

