#include<iostream>
#include<stdio.h>
using namespace std;
#define INPUT_SIZE 1024
int N;
void read_input(int input[]){
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> input[i];
  }
}
int main(){
  int input[INPUT_SIZE];
  long long int output[INPUT_SIZE];
  long long int product = 1;
  read_input(input);
  for(int i = 0; i < N; i++){
    output[i] = product;
    product = product* input[i];
  }
  product = 1;
  for(int i = N-1; i >= 0; i--){
    output[i] = output[i] * product;
    product = product * input[i];
  }
  for(int i = 0; i < N; i++){
    cout << output[i] << "\n";
  }
  return 0;

}
