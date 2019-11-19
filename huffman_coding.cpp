#include<iostream>
#include<string>
using namespace std;

struct tree_node{
	int data = 0;
	char name = '0';
	struct tree_node* left = NULL;
	struct tree_node* right = NULL;
};

struct linked_list{
	struct tree_node* node;
	struct linked_list* next; 
};

string insertionSort(int arr[],string str, int n){  
	int i, key, j;
	char temp;  
	for (i = 1; i < n; i++) {
		key = arr[i];
		temp = str[i]; 
		j = i - 1;  
		while (j >= 0 && arr[j] > key){  
			arr[j + 1] = arr[j]; 
			str[j + 1] = str[j]; 
			j = j - 1;  
		}  
	arr[j + 1] = key;
	str[j + 1] = temp;
	}
	return str;
	  
};

struct linked_list* add_to_sorted(struct linked_list* head, struct tree_node* new_node){
	
	struct linked_list* new_ll;
	new_ll = new linked_list();
	new_ll -> node = new_node;
	new_ll -> next = NULL;

	struct linked_list* temp = NULL;
	temp = new linked_list(); 
	
	if(head == NULL || head -> node -> data >= new_node -> data){
		new_ll -> next = head;
		return new_ll;
	}
	else{
		temp = head;
		while(temp->next != NULL && temp -> next -> node -> data < new_node -> data)
			temp = temp->next;
		new_ll -> next = temp -> next;
		temp -> next = new_ll;
		return head;
	}
};

struct linked_list* append(struct linked_list* head, struct tree_node* new_tree){
	struct linked_list* new_ll = new linked_list();
	new_ll -> node = new_tree;
	new_ll -> next = NULL;
	struct linked_list* temp = head;

	if(head == NULL)
		return new_ll;

	while(temp -> next != NULL)
		temp = temp -> next;
	temp -> next = new_ll;
	return head;
}




void printcode(struct tree_node* head, int arr[], int top){
	if(head-> left){
		arr[top] = 0;
		printcode(head->left, arr,top+1);
	}
	if (head->right){ 
        	arr[top] = 1; 
        	printcode(head->right, arr, top + 1); 
	}
	if(head -> left == NULL && head -> right == NULL){
		cout<<head->name;
		cout<<" ";
		for(int i = 0; i< top; i++)
			cout<<arr[i];
		cout<<endl;
    	} 
};

void printList(struct linked_list *ll)  
{  
    while (ll != NULL)  
    {  
        cout<<" "<<ll->node->data;  
        ll = ll->next;  
    }  
}  


int main(){
	int i,j;
	int n = 6;
	//WE ARE DOING CODING HERE ONLY FOR THESE CHARACTER
	string input = "tpxhhftkkpkpx";
	string characters = "thfkpx";
	int frequency[10] = {};
	struct tree_node* roots[10];

	struct tree_node* temp = new tree_node();

	struct tree_node* temp2 = new tree_node();

	struct tree_node* temp3 = new tree_node();

	struct linked_list* start = new linked_list();
	start = NULL;

	struct linked_list* temp1 = new linked_list();

	struct linked_list* temp4 = new linked_list();

	for(i = 0; i < input.size(); i++){
		for(j = 0; j < characters.size(); j++){
			if(characters[j] == input[i]){
				frequency[j] = frequency[j] + 1;
				break;
			}
		}
	}

	characters = insertionSort(frequency, characters, n);

	
	for(i = 0; i < n; i++){
		temp = new tree_node();
		temp -> data = frequency[i];
		temp -> name = characters[i];
		start = append(start,temp);
		}
	printList(start);
	

	temp1 = new linked_list();
	temp1 = start;
	int count = 0;

	while(start -> next != NULL){
		printList(start);
		temp2 = new tree_node();
		temp2 = start -> node;
		start = start -> next;

		temp3 = new tree_node();
		temp3 = start -> node;
		start = start -> next;

		temp = new tree_node();
		temp -> data = temp2 -> data + temp3 -> data;
		temp -> left = temp2;
		temp -> right = temp3;
		cout<<endl;
		
		start = add_to_sorted(start, temp);
		count++;
		
	}
	int arr[10], top = 0;
	printcode(start->node,arr,top);
	
	

}

