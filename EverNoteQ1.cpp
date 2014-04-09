#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
#define INPUT_SIZE 16384
class Buffer{
  public:
    Buffer(int);
    void insert(string);
    void remove_str(int);
    void print_all();
  private:
    int size;
    string *str;
    int begin_index;
    int end_index;
    int capacity;
    int AddOne(int);
};
Buffer::Buffer(int size_of_buffer){
  size = size_of_buffer;
  str = new string[size];
  begin_index = -1;
  end_index = 0;
  capacity = 0;
}
void Buffer::insert(string input){
  if(begin_index == -1){
    str[0] = input;
    begin_index = 0;
    capacity = 1;
  }else{
    begin_index = AddOne(begin_index);
    str[begin_index] = input;
    if(begin_index == end_index){
      end_index = AddOne(end_index);
    }
    if(capacity != size){
      capacity++;
    }
  }
}
void Buffer::remove_str(int number_of_element){
  if(capacity < number_of_element){
    number_of_element = capacity;
  }
  for(int i = 0; i < number_of_element; i++){
    str[end_index] = "";
    end_index = AddOne(end_index);
  }
  capacity = capacity - number_of_element;
  if(capacity == 0){
    begin_index = -1;
    end_index = 0;
  }
}
void Buffer::print_all(){
  int current_start = end_index;
  if(capacity ==0){
    cout << "\n";
  }
  for(int i = 0; i < capacity; i++){
    cout << str[current_start] << "\n";
    current_start = AddOne(current_start);
  }
}
int Buffer::AddOne(int index){
  return (index + 1) % size;
}
int main(){
  int N;
  string input;
  char action;
  int number_of_actions;
  bool end = false;
  cin >> N;
  if(N == 0){
    return 0;
  }
  Buffer buffer(N);
  while(!end){
    cin >> action;
    switch(action){
      case 'A':
        cin >> number_of_actions;
        for(int j = 0; j < number_of_actions; j++){
          cin >> input;
          buffer.insert(input);
        }
        break;
      case 'R':
        cin >> number_of_actions;
        buffer.remove_str(number_of_actions);
        break;
      case 'L':
        buffer.print_all();
        break;
      case 'Q':
        end = true;
        break;
      default:
        break;
    }
  }
  return 0;

}
