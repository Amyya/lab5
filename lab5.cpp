#include <iostream>
#include <string>
#include <sstream>
#include "lab5.h"
using namespace std;

HugeInt::HugeInt(){
    ;
}

HugeInt::HugeInt(int parameter){
    stringstream ss;
    ss<<parameter;
    read = ss.str();
}

HugeInt::HugeInt(string parameter){
    read = parameter;
}

HugeInt operator+(const HugeInt &first, const HugeInt &second){
    int i, add = 0, temp;//add為進位數
    string First, Second, sum;
    First = first.read;
    Second = second.read;
    int difference = First.length() - Second.length();
    if(difference < 0){
        difference *= -1;
    }
    if(First.length() > Second.length()){
        for(i=0;i<difference;i++){
            Second = '0' + Second;
        }
    }
    else{
        for(i=0;i<difference;i++){
            First = '0' + First;
        }
    }
    for (i=First.length()-1;i>=0;i--) {
        temp = ( First[i] - '0' ) + ( Second[i] - '0' ) + add;
        sum = static_cast<char>(( temp % 10 + '0' )) + sum;
        add =  temp / 10;
    }
    if(add){   //沒進位的話就是0也就是false就不會進位
        sum = static_cast<char>( add + '0' ) + sum;
    }
    return sum;
}

HugeInt operator-(const HugeInt &first, const HugeInt &second){
    int i, temp, sup=0;
    string First, Second, minus;
    First = first.read;
    Second = second.read;
    int difference = First.length() - Second.length();
    if(difference < 0){
        difference *= -1;
    }
    if(First.length() > Second.length()){
        for(i=0;i<difference;i++){
            Second = '0' + Second;
        }
        for (i=First.length()-1;i>=0;i--){
            if( ((First[i] - '0') - ( Second[i] - '0' )) < 0){
                temp = ((First[i] - '0') - ( Second[i] - '0' )) + 10 - sup;
                minus = static_cast<char>(( temp % 10 + '0' )) + minus;
                sup = 1;
            }
            else{
                temp = ((First[i] - '0') - ( Second[i] - '0' ));
                minus = static_cast<char>(( temp % 10 + '0' )) + minus;
                sup = 0;
            }
        }
    }
    else{
        for(i=0;i<difference;i++){
            First = '0' + First;
        }
        for (i=First.length()-1;i>=0;i--){
            if( ((Second[i] - '0') - ( First[i] - '0' )) < 0){
                temp = ((Second[i] - '0') - ( First[i] - '0' )) + 10 - sup;
                minus = static_cast<char>(( temp % 10 + '0' )) + minus;
                sup = 1;
            }
            else{
                temp = ((Second[i] - '0') - ( First[i] - '0' ));
                minus = static_cast<char>(( temp % 10 + '0' )) + minus ;
                sup = 0;
            }
        }
    }
    return minus;
}

istream& operator>>(istream &input, HugeInt &para){
    input>>para.read;
    return input;
}

ostream& operator<<(ostream &output, const HugeInt &pa){
    output<<pa.read;
    return output;
}

