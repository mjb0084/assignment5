#include <iostream>
#include <cctype>

using namespace std;

int main(void){
    char input[101];
    
    cin.getline(input,101);

    // a four letter word is any string consisting of the letters of the alphabet and delimited at each end by a blank, the
    // end of the line, or any other character that is not a letter

    // find out size of string
    int size;
    for (int i=0; input[i]!='\0';i++){size=i+1;}   

    // replace four letter words bounded by non-alphanumeric characters with 'Love' or 'love' depending on whether their first letter
    // is capitalized: "darn" -> "love"; "Dang" -> "Love";
    for(int i=0;i<size;i++){
        int z=2;
        bool num = isalnum(input[i]);
        bool nump4 = isalnum(input[i+4]);
        bool nump5 = isalnum(input[i+5]);

        // in the case that the 4 letter word is bounded on both sides
        if(!num&&!nump5){
            z=1;
        }
        // in the case that the 4 letter word starts the line
        else if ((i==0)&&!nump4){
            z=0;
        }
        else{
            z=2;
        }
        if (z==2){1+1;}
        else {
            if (isupper(input[i+z])){
                input[i+z]='L';
                input[i+z+1]='o';
                input[i+z+2]='v';
                input[i+z+3]='e';
            }
            else {
                input[i+z]='l';
                input[i+z+1]='o';
                input[i+z+2]='v';
                input[i+z+3]='e';
            }
            i=i+z+3;
        }
    }
    for (int i=0; i<size; i++){
        cout << input[i];
    }
}