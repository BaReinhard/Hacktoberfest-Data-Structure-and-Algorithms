#include <iostream>
using namespace std;

int linearSearch(int* arr, int size, int num){
  for(int i = 0; i < size; i++){
    if(arr[i] == num){
      return i;
    }
  }
  return -1;
}
int main(){
  int arr[] = {1, 2, 5, 10, 7, 11, 8, 9, 22, 3};
  int size = sizeof(arr) / sizeof(arr[0]);
  int num = 7;
  int result = linearSearch(arr, size, num);
  if(result == -1)
    cout << "Element not present in list" << endl;
  else
    cout << "Element is at position " << result << endl;
  return 0;
}
