typedef struct Node{
	int data;
	struct Node *next;
} Node;

typedef struct LL{
	Node* root;
} LL;

Node* add_node(Node* current_node, Node* node_to_add){
	if(current_node == nullptr){
		return node_to_add;
	}
	current_node->next = add_node(current_node->next, node_to_add);
	return current_node;
}

int count(Node* d){
	if(d == nullptr){
		return 0;
	}
	return count(d->next) + 1;
}

// #define NUM_DONodeS 10
// Doll nested_dolls[NUM_DONodeS];
//
// for(int i = 0: i < NUM_DONodeS; i++){
//
// }

//Recurse
//Base Case: Stopping point
//Advance towards base case

int main(){

	Node d1 ={
		.data = 1,
		.next = &(Node){
			.data = 2,
			.next  = &(Node){
				.data = 3,
				.next = &(Node){
					.data = 4,
					.next = nullptr
				}
			}
		}
	};
	int total_nodes = count(&d1);
	Node d5 = {5, nullptr};
	add_node(&d1, &d5);
	total_nodes = count(&d1);
	return 0;
}
