#include<iostream>
#include<vector>
using namespace std;

void state2(vector<char>&,int);

void state1(vector<char>& tape, int i){
    if(tape[i]=='N'){       
        state2(tape,i-1);
    }
    else{
        state1(tape,i+1);      
    }
}

void state2(vector<char>& tape, int i){
    if(tape[i]=='1'){       
        tape[i]='0';
        state2(tape,i-1);
    }
    else{
        tape[i]='1';      
        return;
    }
}

int main(){
    string w;
    vector<char> tape;
    cout << "Enter the binary number to increment: ";
    cin >> w;
    tape.push_back('N');        
    for (char ch : w)
    {
        tape.push_back(ch);
    }
    tape.push_back('N');        
    state1(tape, 1);
    cout<<"The number after the binary incrementation: ";
    for(int i=0;i<tape.size();i++){
        if (tape[i]=='N') continue;
        cout<<tape[i];
    }
    return 0;
}

