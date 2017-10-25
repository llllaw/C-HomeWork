#include<iostream>
#include<string>
using namespace std;
struct node{
	node* before;
	int value;
	node* next;
};
int main(){
	node* head = new node;
	node* tail = new node;
	int size = 0;
	head->next = tail;
	tail->before = head;
	tail->value = -1;
	head->value = -1;
	int n;
	bool ishead=true;
	cin >> n;
	for (int i = 0; i < n; i++){
		string operation;
		cin >> operation;
		if (operation == "ADD"){
			int n;
			cin >> n;
			node* no = new node;
			no->value = n;
			size += 1;
			if (ishead){
				tail->before->next = no;
				no->before = tail->before;
				tail->before = no;
				no->next = tail;
			}
			else{
				head->next->before = no;
				no->next = head->next;
				head->next = no;
				no->before = head;
			}
		}
		else if (operation == "REVERSE"){
			ishead = !ishead;
		}
		else if (operation == "DEL"){
			int n;
			cin >> n;
			node* node=head;
			node = node->next;
			while (node->value != -1){
				if (node->value == n){
					node->before->next = node->next;
					node->next->before = node->before;
					size--;
					
				}
				node = node->next;
			}
		}
		else if (operation == "SIZE"){
			cout << size << endl;
		}
		else if (operation == "PRINT"){
			if (ishead){
				node* node = head;
				node = node->next;
				while (node->value != -1){
					cout << node->value << " ";
					node = node->next;
				}
			}
			else{
				node* node = tail;
				node = node->before;
				while (node->value != -1){
					cout << node->value << " ";
					node = node->before;
				}
			}
			if (head->next == tail)
				cout << "NULL";
			cout << endl;
		}
		else if (operation == "REMOVEREPEAT"){
			int n;
			cin >> n;
			if (!ishead){
				bool de = false;
				node* node = head;
				node = node->next;
				while (node->value != -1){
					if (node->value == n){
						if (de){
							node->before->next = node->next;
							node->next->before = node->before;
							size--;
						}
						else{
							de = true;
						}
						
					}
					node = node->next;
				}
			}
			else{
				bool de = false;
				node* node = tail;
				node = node->before;
				while (node->value != -1){
					if (node->value == n){
						if (de){
							node->before->next = node->next;
							node->next->before = node->before;
							size--;
						}
						else{
							de = true;
						}
						
					}
					node = node->before;
				}
			}
		}
	}
}