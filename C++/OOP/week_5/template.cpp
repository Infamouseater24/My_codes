#include<iostream>
#include<string>
using namespace std;
template <typename T>
T Sum(T value1, T value2){
    return value1+value2;
}
template <typename T>
T Sum(T value1, T value2, T value3){
    return value1+value2+value3;
}
int main(){
    cout<<Sum<char>('g','v')<<endl<<
    Sum<float>(4.567,6.77)<<endl<<
    Sum<int>(7,8)<<endl<<
    Sum<int>(7,8,9);
}