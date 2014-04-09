#include<iostream>
#include<stdio.h>
#include<map>
#include<string>
#include<queue>
#include<cstdlib>
using namespace std;
#define INPUT_SIZE 1024
struct PAIR{
  string str;
  int occurence;
};
class compareOccurence{
  public:
    bool operator()(PAIR& p1, PAIR& p2){
      if(p1.occurence < p2.occurence){
        return true;
      }else{
        return false;
      }
    }
};
int N, K;
map<string, int> str_map;
map<string, int>::iterator it;
void read_input(){
  string input;
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> input;
    if(str_map.find(input) != str_map.end()){
      str_map[input]++;  
    }else{
      str_map[input] = 1;
    }
  }
  cin >> K;
}
int main(){
  read_input();
  priority_queue<PAIR, vector<PAIR>, compareOccurence> pq;
  for(it = str_map.begin(); it != str_map.end(); it++){
    PAIR tmp = {it -> first, it -> second};
    pq.push(tmp);
  } 
  int current_count;
  int num_of_current_count;
  while(K > 0){
    PAIR tmp = pq.top();
    pq.pop();
    current_count = tmp.occurence;
    num_of_current_count = 0;
    for(it = str_map.begin(); it != str_map.end(); it++){
      if(it -> second == current_count){
        cout << it -> first << "\n";
        K--;
        str_map.erase(it);
        break;
      }
    }
  }
  return 0;

}
