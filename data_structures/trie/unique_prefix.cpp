#include <bits/stdc++.h>
using namespace std;

class node
{
  public:
  char data;
  unordered_map<char, node*> children;
  bool  terminal;
  int count;

  node(char d)
  {
    data = d;
    terminal = false;
    count = 0;
  }
};


class Trie
{
  node* root;

  public:
  Trie()
  {
    root = new node('\0');
  }

  void insert(char *w)
  {
     node* temp = root;
    for(int i=0; w[i]!='\0'; i++)
    {
      char ch = w[i];
      if(temp->children.count(ch))
      {
        temp = temp->children[ch];
         temp->count++;
      }
      else
      {
        node* n = new node(ch);
        temp->children[ch]=n;
        temp = n;
        temp->count++;
      }
    }
    temp->terminal = true; //ending of word
  }

  bool find(char *w)
  {
    node* temp = root;
    for(int i=0; w[i]!='\0'; i++)
    {
      char ch = w[i];
      if(temp->children.count(ch)==0)
      {
        return false;
      }
      else
      {
        temp = temp->children[ch];
      }
    }
    return temp->terminal;
  }

  void getUniquePrefix(char *w)
  {
    node* temp = root;
    for(int i=0; w[i]!='\0'; i++)
    {
      char ch = w[i];
      temp = temp->children[ch];
      if(temp->count==1)
      {
        cout<<ch;
        return;
      }
      else
      {
        cout<<ch;
      }
    }
    cout<<"(-1)";
    return;
  }
};

int main()
{
  Trie t;
  char words[][10] = {"zebra", "dog", "dove", "duck", "zebras"};

  for(int i=0; i<5; i++)
  {
    t.insert(words[i]);
  }
  
  char *c;
  cin>>c;
  t.getUniquePrefix(c);
  return 0;
}
