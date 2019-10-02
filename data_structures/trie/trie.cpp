#include <bits/stdc++.h>

using namespace std;

struct node{
	bool end;
	struct node* word[26];
} *head;

void init(){
	head = new node();
	head->end = false;
}

void add(string palavra){
	node* current = head;
	for(int i = 0; i < palavra.size(); i++){
		int letra = palavra[i]-'a';

		if(current->word[letra] == NULL) current->word[letra] = new node();

		current = current->word[letra];
	}
	current->end = true;
}
int main(){
	string palavra; cin >> palavra;
	init();
	add(palavra);
	return 0;
}
