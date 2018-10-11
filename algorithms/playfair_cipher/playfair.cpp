#include <bits/stdc++.h>

using namespace std;
// NOTE: all input including key is in lowercase alphabets
void foo(char mapped[5][5],char fin,int &ansi,int&ansj)
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(mapped[i][j]==fin)
            {
                ansi=i;
                ansj=j;
                return;
            }
        }
    }
}

int main()
{
    cout<<"----------The Playfair Cipher----------\n";
    char alpha[25];
    int k=0;
    for(int i=0;i<26;i++) // assign the indices to alphabets
    {
        char c='a'+i;
        if(c!='j')          // handling i,j
            alpha[k++]='a'+i;
    }
//    for(int i=0;i<26;i++)
//        cout<<alpha[i]<<" ";
    cout<<endl;
    char mapped[5][5]; // mapping to be created
    bool mp[26]; // checking whether character has already been mapped
    memset(mp,0,sizeof(mp));
    memset(mapped,'-',sizeof(mapped));

    string key;
    cout<<"Input the key\n";
    // assume I and J in same
    cin>>key;
    int row,col;
    row=col=0;
    for(int i=0;i<key.length();i++)
    {
        if(mp[key[i]-'a']==0)
        {
            mp[key[i]-'a']=1;
            mapped[row][col]=key[i];

            if(col+1==5)    // handling of row change and column change
            {
                col=0;
                if(row+1==5)
                    break;
                else
                    row++;
            }
            else
                col++;
        }
    }
    for(int i=0;i<26;i++)
    {
        if(mp[alpha[i]-'a'] == 0)
        {
            mp[alpha[i]-'a']=1;
            mapped[row][col]=alpha[i];  //mapping the leftovers

            if(col+1==5)
            {
                col=0;
                if(row+1==5)
                    break;
                else
                    row++;
            }
            else
                col++;
        }

    }
    // the final mapping; uncomment below to print
//    for(int i=0;i<5;i++)
//    {
//        for(int j=0;j<5;j++)
//            cout<<mapped[i][j];
//        cout<<endl;
//    }

    //encryption
    cout<<"Enter the text to be encrypted\n";
    string inp;
    cin>>inp;
    string fininp="";
    fininp+=inp[0];
    // processing the input to prevent similar successive characters
    // uses z as the delimiter character
    for(int i=1;i<inp.length();i++)
    {
        if(inp[i]==inp[i-1])
        {
            fininp+='z';
            fininp+=inp[i];
        }
        else
            fininp+=inp[i];
    }
    if(fininp.length()%2==1) // length should be even to form di-grams
        fininp+='z';
    cout<<"Final input string\n";
    cout<<fininp<<endl;
    string encrypted="";
    // encryption done using the rules of playfair
    // same row,same column, both different
    for(int i=0;i<fininp.length();i+=2)
    {
        char f=fininp[i];
        char s=fininp[i+1];

        // find f
        int fi,fj;
        int si,sj;
        foo(mapped,f,fi,fj);
        foo(mapped,s,si,sj);
        if(fi==si)
        {
            char add1=mapped[(fi+1)%5][fj];
            char add2=mapped[(si+1)%5][sj];
            encrypted+=add1;
            encrypted+=add2;
        }
        else if(fj==sj)
        {
            char add1=mapped[fi][(fj+1)%5];
            char add2=mapped[si][(sj+1)%5];
            encrypted+=add1;
            encrypted+=add2;
        }
        else
        {
            char add1=mapped[fi][sj];
            char add2=mapped[si][fj];
            encrypted+=add1;
            encrypted+=add2;
        }

    }
    cout<<"Encrypted: "<<encrypted<<endl;

    //decryption
    string decrypted="";
    for(int i=0;i<encrypted.length();i+=2)
    {
        char f=encrypted[i];
        char s=encrypted[i+1];

        // find f
        int fi,fj;
        int si,sj;
        foo(mapped,f,fi,fj);
        foo(mapped,s,si,sj);
        if(fi==si)
        {
            char add1=mapped[(fi-1)%5][fj];
            char add2=mapped[(si-1)%5][sj];
            decrypted+=add1;
            decrypted+=add2;
        }
        else if(fj==sj)
        {
            char add1=mapped[fi][(fj-1)%5];
            char add2=mapped[si][(sj-1)%5];
            decrypted+=add1;
            decrypted+=add2;
        }
        else
        {
            char add1=mapped[fi][sj];
            char add2=mapped[si][fj];
            decrypted+=add1;
            decrypted+=add2;
        }

    }
    cout<<"Decrypted: "<<decrypted<<endl;
}

