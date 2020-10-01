#include<iostream>
using namespace std;
class selection {
public:
    void SelectionSort() {
        int n;
        int myarr[30];
        cout << "Enter Total no of Elements in Array: "<<"\n";
        cin>>n;
        cout<<"Enter the elements: ";
        for (int i = 0; i < n; i++) {
            cin >> myarr[i];
        }
        cout << "UNSORTED ARRAY: " << "\n";
        for (int i = 0; i < n; i++) {
            cout << myarr[i] << "  ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            int min = i;

            for (int j = i + 1; j < n; j++) {
                if (myarr[j] < myarr[min]) {
                    min = j;
                }
            }
            if (min != i) {
                int temp = myarr[min];
                myarr[min] = myarr[i];
                myarr[i] = temp;
            }
        }
        cout << "SORTED ARRAY: " << "\n";
        for (int i = 0; i < n; i++) {
            cout << myarr[i] << "  ";
        }


    }

};
int main() {
    selection s;
    s.SelectionSort();
    return 0;
}

