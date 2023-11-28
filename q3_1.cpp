#include <fstream>
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// checks if num1 is smaller than or equal to num2
bool isSmaller(int num1,int num2);

// returns the larger of two ints or first if equal
int largerValue(int num1,int num2);

// returns the smaller of two ints or the first if equal
int smallerValue(int num1, int num2);

// converts a C-string array to an integer value, given the length of the string
int cString2Int(char number[100],int count);



int main(void){
    ifstream inStream1,inStream2;
    ofstream outStream;

    string input1("file1.txt"),input2("file2.txt"),output("file3.txt");

    inStream1.open(input1);
    inStream2.open(input2);
    outStream.open(output);

    // reads through file1, creates an array of ints
    // reads through file2, creates an array of ints

    // iterates through both arrays and compares values, 
    // sending the lower value to file3

    int count=0;
    int size1=0,size2=0;
    char next1,next2;
    char number1[100],number2[100];
    int numbers1[100],numbers2[100];

    inStream1.get(next1);
    while(!inStream1.eof()){
        while(next1!='\n'&&!inStream1.eof()){
            number1[count]=next1;
            count ++;
            inStream1.get(next1);
        }
        numbers1[size1]=cString2Int(number1,count);
        count = 0;
        size1++;
        inStream1.get(next1);
    }

    count = 0;
    inStream2.get(next2);
    while(!inStream2.eof()){
        while(next2!='\n'&&!inStream2.eof()){
            number2[count]=next2;
            count ++;
            inStream2.get(next2);
        }
        numbers2[size2]=cString2Int(number2,count);
        count = 0;
        size2++;
        inStream2.get(next2);
    }

    int smaller=smallerValue(size1,size2);
    int i=0,j=0;
    while(i<size1&&j<size2){
        if(isSmaller(numbers1[i],numbers2[j])){
            outStream << numbers1[i]<<"\n";
            i++;
        }
        else {
            outStream << numbers2[j]<<"\n";
            j++;
        }
    }
    if (smaller==size1){
        while (j<size2){
            outStream << numbers2[j]<<"\n";
            j++;
        }
    }
    else {
        while (i<size1){
            outStream << numbers1[i]<<"\n";
            i++;
        }

    }
    

    inStream1.close();
    inStream2.close();    
    outStream.close();
}

bool isSmaller(int num1,int num2){
    if(num1<=num2){return 1;}
    else return 0;
}

int largerValue(int num1,int num2){
    if (num1>=num2){return num1;}
    else return num2;
}

int smallerValue(int num1, int num2){
    if (num1<=num2){return num1;}
    else return num2;
}

int cString2Int(char number[100],int count){
    int num=0;
    count--;
    int counter=count+1;
    for(int i=0;i<counter;i++){
        num+=(number[i]-48)*(pow(10,count));
        count--;
    }
    return num;
}
