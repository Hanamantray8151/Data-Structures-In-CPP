#include<bits/stdc++.h>
using namespace std;

template<typename T>
class TreeNode{
	public:
		T data;
		vector<TreeNode<T>*> children;
		
		TreeNode(T data){
			this -> data = data;
		}
};

TreeNode<int>* takeinput(){
	int rootData;
	cout << "Enter Root Data : ";
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
	
	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	
	while(!pendingNodes.empty()){
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		
		int numofchild;
		cout << "Enter no of children of " << front -> data << endl;
		cin >> numofchild;
		
		for(int i=0;i<numofchild;i++){
			int childData;
			cout << "Enter " << i << "th child of " << front -> data << endl;
			cin >> childData;
			
			TreeNode<int>* child = new TreeNode<int>(childData);
			front -> children.push_back(child);
			pendingNodes.push(child);
		}
	}
	return root;
}

void printNodesAtLevelK(TreeNode<int>* root,int k){
	if(root == NULL){	//Edge case.
		return;
	}
	if(k == 0){
		cout << root -> data << endl;
		return;
	}
	for(int i=0;i<root->children.size();i++){
		printNodesAtLevelK(root->children[i],k-1);
	}
}

void printTree(TreeNode<int>* root){
	if(root == NULL){	//Edge case.
		return;
	}
	
	queue<TreeNode<int>*> q;
	q.push(root);
	
	while(!q.empty()){
		TreeNode<int>* front = q.front();
		q.pop();
		
		cout << front -> data << ":";
		for(int i=0;i<front->children.size();i++){
			q.push(front -> children[i]);
			if(front -> children.size() - 1 != i){
				cout << front -> children[i] -> data << ",";
			}else{
				cout << front -> children[i] -> data;
			}
		}
		cout << endl;
	}
}

int main(){
	TreeNode<int>* root = takeinput();
	
	printTree(root);
	
	printNodesAtLevelK(root,3);

	return 0;
}
