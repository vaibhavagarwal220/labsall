#include "bits/stdc++.h"

using namespace std;

#define SIZE 1000

struct RandomListNode {
  int label;
  struct RandomListNode *next;
  struct RandomListNode *random;
  RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
bool evaluate(int rand[],RandomListNode *newList,RandomListNode* ori);

RandomListNode* copyRandomList(RandomListNode* A) {

struct RandomListNode *temp = A , *temp1=NULL , *temp2=NULL , *copy=NULL,*copyA=NULL;
	int info = A->label ;
	while(temp!=NULL)																			// insert a copy in between 
	{
		copy= (struct RandomListNode *)malloc(sizeof(struct RandomListNode));
		copy->label=temp->label;
		copy->next=temp->next;
		temp->next = copy ;
		temp=temp->next->next ;
	}
	copyA=A->next ;
	temp=A;
	while(temp!=NULL)																			// link the randomitrary nodes 
	{
		temp->next->random=temp->random->next ;
		temp=temp->next->next ;
	}
	
	
	temp1=A;
	temp2=copyA;
	while(temp2->next!=NULL)																	// separate the two linked list 
	{
		temp1->next=temp1->next->next;
		temp1=temp1->next;
		temp2->next=temp2->next->next;
		temp2=temp2->next;
	}
	temp1=0;
	temp1=A;
	while(temp1->next!=NULL)
	{
		temp1=temp1->next;
	}
	temp1=0;
printf("LIST COPIED.\n");
return copyA;

}

void printlist(RandomListNode*head)
{
	while(head != NULL){
		cout << head->label << ' ';
		head = head->next;
	}
	
}

int main()
{
	RandomListNode * arr[SIZE+1];
	int label[SIZE+1];
	int random_array[SIZE+1];
	int index;
	srand (time(NULL));
	int T = 100, passed = 0;
	for(int i = 1;i<=SIZE;++i){
		arr[i] = (RandomListNode*)malloc(sizeof(RandomListNode));
	}
	while(T--){	
		for(int i = 1;i<SIZE;++i){
			arr[i]->label = rand();
			index = (rand()%SIZE) + 1;
			arr[i]->next = arr[i+1];
			arr[i]->random = arr[index];
			random_array[i] = index;
			label[i] = arr[i]->label;
		}
		arr[SIZE]->label = rand();
		index = (rand()%SIZE) + 1;
		arr[SIZE]->next = NULL;
 		arr[SIZE]->random = arr[index];
		random_array[SIZE] = index;
		label[SIZE] = arr[SIZE]->label;
		
		RandomListNode*copied_list = copyRandomList(arr[1]);
		//printlist(arr[1]);
		//printlist(copied_list);
		//printlist(arr[1]);
		//Restoring the original list
		for(int i = 1;i<SIZE;++i){
			arr[i]->next = arr[i+1];
			arr[i]->random = arr[random_array[i]];
			arr[i]->label = label[i];
		}
		arr[SIZE]->next = NULL;
		arr[SIZE]->random = arr[random_array[SIZE]];
		arr[SIZE]->label = label[SIZE];


		bool condition = evaluate(random_array,copied_list,arr[1]);
		if(condition == true){
			++passed;
		}
	}
	cout << "Number of Test Passed is " <<  ((double)passed)/10 << '\n';




	return 0;

}



bool evaluate(int rand[],RandomListNode *newList,RandomListNode* ori){
	set<RandomListNode*> nodes;
	RandomListNode* headori = ori;
	int size = 0;
	while(headori!=NULL){
		nodes.insert(headori);
		size++;
		headori = headori->next;
	}
	map<RandomListNode*,int> indexes;
	RandomListNode* head = newList;
	headori = ori;
	int i = 0;
	
	while(head!=NULL && headori != NULL){
		if(head->label != headori->label)return false;
		nodes.insert(head);
		indexes[head] = i+1;
		head = head->next;
		headori = headori->next;
		i++;

	}

	if(i!=size || nodes.size() != 2*size)return false;
	head = newList;
	i = 1;
	while(head != NULL){
		if(rand[i] != indexes[head->random]){
			return false;
		}
		head = head->next;
		i++;
	}


	return true;

}