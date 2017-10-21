#include <iostream.h>

int cdeque[100],arrsize,L,R,newitem,K=0;

void createdeque()
{
    cout << "Enter the size of the array:";
    cin >> arrsize;
    if(arrsize<100)
    {
        cout << "Array created.\n";
        L = -1;
        R = -1;
        K = 1;
    }
    else
        cout << "\nPlease enter a arrsize smaller than 100.\n";
}

void deleteelement()
{
    if(K == 0)
        cout << "\n(it's funny?) You must create array first.\n";
    else
    {
        int d;
        if(L == -1)
            cout << "Queue is empty!";
        else
        {
            cout << "Plese enter 1 for left or 2 for right:";
            cin >> d;
            if(d == 1)
            {
                if(L == R)
                {
                    L = -1;
                    R = -1;
                }
                else
                {
                    L = (L+1)%arrsize;
                    cout << "-Element deleted!\n";
                }
            }
            else if(d=2)
            {
                if(R == -1)
                cout << "Queue is empty!";
                else
                {
                    if(L == R)
                    {
                        L = -1;
                        R = -1;
                    }
                    else
                    {
                        R = (R+arrsize-1)%arrsize;
                        cout << "-Element deleted!\n";
                    }
                }
            }
        }
    }

}

void insertelement()
{
    if(K == 0)
        cout << "\n(it's funny?) You must create array first.\n";

    else
    {
        int d;
        if((R+1)%arrsize == L)
            cout << "\nQueue is full!\n";
        else
        {
            cout << "Plese enter 1 for left or 2 for right:";
            cin >> d;
            if(d == 1)
            {
               cout << "Enter the new item:";
                cin >> newitem;

                if(L == -1)
                {
                    L = 0;
                    R = 0;
                }
                else
                    L = (L+arrsize-1)%arrsize;
                cdeque[L] = newitem;
                cout << "+Item added.\n";
            }
            else if(d == 2)
            {
                cout << "Enter the new item:";
                cin >> newitem;

                if(L == -1)
                {
                    L = 0;
                    R = 0;
                }
                else
                    R = (R+1)%arrsize;
                cdeque[R] = newitem;
                cout << "+Item added.\n";
            }
        }
    }
}

void listelement()
{
    int i;
    if(L == -1)
        cout << "Queue is empty!";
    else
    {
        if(L <= R)
        {
            cout << endl;
            for(i = L; i <= R; i++)
                cout << cdeque[i] << "\t";
            cout << endl;
        }
        else
        {
            cout << endl;
            for(i = L; i < arrsize; i++)
                cout << cdeque[i] << "\t";
            for(i = 0; i <= R; i++)
                cout << cdeque[i] << "\t";
            cout << endl;
        }
    }
}

int main()
{
    int n;
    while(1)
    {
        cout << "\nPress 1 to create a deque\n";
        cout << "\nPress 2 to insert a new element";
        cout << "\nPress 3 to delete element\n";
        cout << "\nPress 4 to list the elements";
        cout << "\nPress 5 to exit from program";
        cout << "\n\nEnter your choise:";
        cin >> n;

        switch(n)
        {
            case 1:createdeque();
            break;
            case 2:insertelement();
            break;
            case 3:deleteelement();
            break;
            case 4:listelement();
            break;
            case 5:cout << "\nEnd of program...\nPress any key to exit...";
            return  0;

            default:cout << "Wrong selection,try again..";
        }
    }
}
