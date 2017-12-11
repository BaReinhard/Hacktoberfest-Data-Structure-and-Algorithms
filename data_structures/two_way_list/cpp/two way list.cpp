#include <iostream>

using namespace std;

int info[100], forw[100], backw[100], i, startr, startl, avail, arrsize, value, newitem, ptr, che=0;

void createtwowaylist()
{
    	do{
        	cout << "\nPlease enter the size of array:";
        	cin >> arrsize;
        	if(arrsize<=0)
            	cout << "\nPlease enter positive";
    	}while(arrsize<=0);
    	startr=-1;
    	startl=-1;
    	avail=0;
    	for(i=0;i<arrsize-1;i++)
        	forw[i]=i+1;
    	forw[arrsize-1]=-1;
}

void listfromleft()
{
	if(startl==-1)
    	cout << "List is empty";
	else
	{
    	ptr=startl;
    	while(ptr!=-1)
    	{
        	cout << info[ptr] << "\t";
        	ptr=forw[ptr];
    	}
	}
}

void listfromright()
{
	if(startr==-1)
    	cout << "List is empty";
	else
	{
    	ptr=startr;
    	while(ptr!=-1)
    	{
        	cout << info[ptr] << "\t";
        	ptr=backw[ptr];
    	}
	}
}

void deletefromleft()
{
	if(che==1)
	{
    	if(startl==-1)
        	cout << "List is empty";
    	else
    	{
        	if(startl==startr)
        	{
            	value=startl;
            	startl=-1;
            	startr=-1;
            	forw[value]=avail;
            	avail=value;
        	}
        	else
        	{
            	value=startl;
            	startl=forw[startl];
            	backw[startl]=-1;
            	forw[value]=avail;
            	avail=value;
        	}
    	}
	}
	else
	{
    	cout << "You should enter first.";
	}
}

void deletefromright()
{
	if(che==1)
	{
    	if(startr==-1)
        	cout << "List is empty";
    	else
    	{
        	if(startl==startr)
        	{
            	value=startr;
            	startl=-1;
            	startr=-1;
            	forw[value]=avail;
            	avail=value;
        	}
        	else
        	{
            	value=startr;
            	startr=backw[startr];
            	forw[startr]=-1;
            	forw[value]=avail;
            	avail=value;
        	}
    	}}
    	else
    	{
        	cout << "You should enter first.";
    	}

}

void insertfromleft()
{
	che=1;
	if(avail==-1)
    	cout << "List is full.";
	else
	{
    	cout << "Please enter new item";
    	cin >> newitem;
    	if(startl==-1)
    	{
        	value=avail;
        	avail=forw[avail];
        	startl=value;
        	startr=value;
        	forw[value]=-1;
        	backw[value]=-1;
        	info[value]=newitem;
    	}
    	else
    	{
        	value=avail;
        	avail=forw[avail];
        	backw[value]=-1;
        	forw[value]=startl;
        	backw[startl]=value;
        	startl=value;
        	info[startl]=newitem;
    	}
	}
}

void insertfromright()
{
	che=1;
	if(avail==-1)
    	cout << "List is full.";
	else
	{
    	cout << "Please enter new item";
    	cin >> newitem;
    	if(startr==-1)
    	{
        	value=avail;
        	avail=forw[avail];
        	startl=value;
        	startr=value;
        	forw[value]=-1;
        	backw[value]=-1;
        	info[value]=newitem;
    	}
    	else
    	{
        	value=avail;
        	avail=forw[avail];
        	forw[startr]=value;
        	forw[value]=-1;
        	backw[value]=startr;
        	startr=value;
        	info[startr]=newitem;
    	}
	}
}

int main()
{
	int k;
	while(1)
	{
    	cout << "\nPress 1 to create two way list.";
    	cout << "\nPress 2 to insert an element from left to two way list.";
    	cout << "\nPress 3 to insert an element from right to two way list.";
    	cout << "\nPress 4 to delete an element from left.";
    	cout << "\nPress 5 to delete an element from right.";
    	cout << "\nPress 6 to list from left to the two way list.";
    	cout << "\nPress 7 to list from right to the two way list.";
    	cout << "\nPress 8 to exit.";
    	cout << "\nPlease enter your choice: ";
    	cin >> k;
    	switch(k)
    	{
        	case 1: createtwowaylist();
                	break;
        	case 2: insertfromleft();
                	break;
        	case 3: insertfromright();
                	break;
        	case 4: deletefromleft();
                	break;
        	case 5: deletefromright();
                	break;
        	case 6: listfromleft();
                	break;
        	case 7: listfromright();
                	break;
        	case 8: cout << "\nSee you again.";
                	return 0;
        	default:
                	cout << "\nYou should enter 1,2,3,4,5,6,7,8.";
    	}
	}
}