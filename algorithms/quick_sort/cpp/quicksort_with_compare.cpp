// Quick Sort Function with compare function as in STL

#include <iostream>
using namespace std;

class Data{

 public:
 int x;
 int y;
 Data(){}
 Data(int,int);
};

Data::Data(int a,int b){
	x = a;
	y = b;
}

//compare function for comparison on data type
bool compare(Data p1,Data p2){
   if(p1.x <= p2.x){
      if(p1.x == p2.x){
         return p1.y <= p2.y;	
      }	
      return true;
   }
   
   return false;
   
}

int partition(Data *arr,int low,int high,bool (*compare)(Data,Data)){
	Data pivot = arr[high];
	int i = low-1;
	
	for(int j=low;j<high;j++){
	
	if(compare(arr[j],pivot)){
		i++;
		Data temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	
	}
	
	Data temp1 = arr[i+1];
	arr[i+1] = arr[high];
	arr[high] = temp1;

   return i+1;	
}

void qsort(Data *arr,int low,int high,bool (*compare)(Data,Data)){
   if(low <= high){
      int p = partition(arr,low,high,compare);
      qsort(arr,low,p-1,compare);
      qsort(arr,p+1,high,compare);
   }	
}

int main() {
	
   Data p1(3,4);
   Data p2(3,5);
   Data p3(5,2);
   Data p4(1,5);
   Data p5(7,2);
   Data *arr = new Data[5];
   arr[0] = p1,arr[1] = p2,arr[2] = p3,arr[3] = p4,arr[4] = p5;
   qsort(arr,0,4,compare);
   for(int i=0;i<5;i++){
     cout<<arr[i].x<<" "<<arr[i].y<<endl;	
   }
	
	return 0;
}

