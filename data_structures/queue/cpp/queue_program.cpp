#include <iostream>
#include <conio.h> //USING GETCH()
#include <stdlib.h> //USING THE SYSTEM("CLS)
#define MAX 1000 //MAXIMUM QUEUE NUMBER

using namespace std;

int number[MAX];
int head=-1;
int tail=-1;

bool IsEmpty(){ // FUNCTION TO SHOW IF TAIL = -1
   if(tail == -1){
       return true;
   }else{
       return false;
   }
}
bool IsFull(){ // FUNCTION TO SHOW IF TAIL = MAX-1
   if(tail == MAX-1){
       return true;
   }else{
       return false;
   }
}

void AntrianMasuk(int no){
    if (IsEmpty()){
        head=tail=0;
    }else {
        tail++;
    }
    number[tail]=no;
}

void AntrianKeluar(){
    if(IsEmpty()){
        cout<<"The queue is empty ! ";
        getch();
    }else {
        for(int a=head;a<tail;a++){
            number[a]=number[a+1];
        }
        tail--;
        if(tail == -1){
            head = -1;
        }
    }
}

void Clear(){
     head=tail=-1;
}

void View(){
     if(IsEmpty()){
         cout<<"Empty queue ! ";

     }else {
         system("cls");
         for(int a=head;a<=tail;a++){
              cout << "==============================="
                   << "\n >> No. Queue : [" << number[a] << "]"
                   << "\n==============================="<< endl;
         }
     }
}

int main(){
    system("color 79");
    int choose, p=1, urut; //declaration for user selection and queue serial number
    do{
        system("cls");
        cout << "\n\n===== C++ QUEUE PROGRAM ====="
             << "\n==============================="
             << "\n|1. Add Queue            |"
             << "\n|2. Call Queue           |"
             << "\n|3. View Queue list      |"
             << "\n|4. Reset                    |"
             << "\n|5. Exit                      |"
             << "\n===============================";
        cout << "\nChoose ! "; cin >> choose;
        cout << "\n\n";
        if(choose == 1){
            if(IsFull()) {
                cout<<"The queue is full, please wait a little longer ";
            }
            else{
                urut=p;
                AntrianMasuk(urut);
                cout << "---------------------------------" << endl;
                cout << "|          NO. QUEUE            |" << endl;
                cout << "|               " << p << "              ||" << endl;
                cout << "---------------------------------" << endl;
                cout << "|       Please Queue            |" << endl;
                cout << "|      Waiting " << tail << " Queue  ||" << endl;
                cout << "---------------------------------" << endl;
                p++;
            }
        }
        else if(choose == 2){
            cout << "=================================" << endl;
            cout << "NO. QUEUE : [" << number[head] << "]";
            cout << "\n=================================" << endl;
            AntrianKeluar();
            cout << "Please Call !" << endl;
        }
        else if(choose == 3){
            View();
        }
        else if(choose == 4){
            Clear();
            cout<<"Queue emptied ! ";
        }
        else if(choose == 5){
        }
        else{
            cout << "Your input is wrong ! \n"<< endl;
        }
        getch();
    }while(choose!=5);
}
