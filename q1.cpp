#include <iostream>

using namespace std;

int main(void){
    char input[101];
    
    cin.getline(input,101);
    int i=0;
    bool cont=1;

    do{
        if (i==0){input[0]=toupper(input[0]);}
        else{
            if(input[i]=='\0'){break;}
            while (input[i+1]==' '){
                    if (input[i]==' '){i++;}
                    else break;
            }
            input[i] = tolower(input[i]);
        }
        cout.put(input[i]);
        i++;
    }while (i<100);
}