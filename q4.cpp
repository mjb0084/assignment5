#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void readline(void);


int main(void){
    ifstream ans;
    string line;
    ans.open("answers.txt");

    while(1){
        readline();    
        getline(ans,line);
        if(!ans.eof()){
            cout << line;
        }
        else{
            cout << line;
            ans.close();
            ans.open("answers.txt");
        }
    }
    
}

void readline(void){
    string input;
    cout << "\nWhat is your question?\n: ";
    cin >> input;
}
