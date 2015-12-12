#include <iostream>
#include <fstream>

using namespace std;

struct word {
public:
	char name[20];
	word *next;
	word *pre;
	word(char *name)
	{
		strcpy(this->name,name);
	}
};
class linkedlist
{
	word *head;
public:
	void add(char []);
	void print();
	void remove(char []);
	word *revers();
	linkedlist()
	{
		head=nullptr;
	}

};
void linkedlist::print()
{
	word *temp;
	ofstream output_file;
	output_file.open("output.txt");

	for(temp = head ; temp->next != head ; temp=temp->next)
	{
		output_file <<temp->name<<"\n";

	}
	output_file<<temp->name;

	
}
void linkedlist::add( char input_word_string[])
{
	if(strcmp(input_word_string ,"")==0)
	{
		return;
	}
	else{
		word *input_word;
		input_word = new word(input_word_string);
		if(!head)
		{
			head =input_word;
			head->next = head;
			head ->pre = head;
		}
		else 
		{
			word *temp;
			for (temp=head;strcmp(temp->name , input_word->name)<0 && temp->next!=head;temp=temp->next);
			if(temp->next==head)
			{
				head->pre = input_word;
				input_word->next = head;
				input_word->pre = temp;
				temp->next = input_word;
			}
			else{
				input_word->next = temp;
				input_word->pre = temp->pre;
				temp->pre->next = input_word;
				temp->pre = input_word;
			}
			if(temp==head)
			{
				head=input_word;
			}
		}
	}
}
void linkedlist::remove( char input_word_string[]){
	word * temp;
	for(temp=head;strcmp(temp->name,input_word_string)!=0 && temp->next!=head;temp=temp->next);
	if(temp->next==head && strcmp(temp->name,input_word_string)!=0 ) return;
		temp->next->pre=temp->pre;
		temp->pre->next=temp->next;
		if(temp==head){
			if(head->next==head){
			head=nullptr;
			}
			else{
			head=head->next;
			}
		}
		delete(temp);
}
word * linkedlist::revers()
{
	word * temp ;
	for(temp=head ; temp->next != head; )
	{
		word *temp_rev = temp->next;
		word * k = temp->next;
		temp->next=temp->pre;
		temp->pre = temp_rev;
		temp = k;
	}
	word *temp_rev;
	temp_rev = temp->next;
	temp->next = temp->pre;
	temp->pre = temp_rev;
	
	return temp;
}
int main()
{
	ifstream input;
	input.open("input.txt");
	linkedlist list;
	char  in_word[20];

	while(!input.eof())
	{
		input>>in_word;
		list.add(in_word);
	}
	list.remove("mina");
	list.print();

		word * revers_temp = list.revers();
	word *temp;

	for(temp = revers_temp ; temp->next != revers_temp ; temp=temp->next)
	{
		cout <<temp->name<<"\n";

	}
	cout<<temp->name;
	int a;
	cin >>a;
}