#include <bits/stdc++.h>

using namespace std;


struct Node {
	int data;
    int cnt;
	Node* left;
	Node* right;

	Node(int data) {
		this->data = data;
        cnt = 1;
		left = NULL;
		right = NULL;
	} 
};

Node* getMin(Node* root) {
	while (root->left != NULL) {
		root = root->left;
	}
	return root;
}

Node* add(Node* root, int data) {
	if (root == NULL) {
		return new Node(data);
	} 
    else if(root->data == data){
        root->cnt++;
    }
    else if (root->data > data) {
		if (root->left == NULL) {
			root->left = new Node(data);
		} else {
			root->left = add(root->left, data);
		}
	} else if (root->data < data) {
		if (root->right == NULL) {
			root->right = new Node(data);
		} else {
			root->right = add(root->right, data);
		}
	}
	return root;
}

Node* deleteNode(Node* root, int data) {
	if (root == NULL) {
		return NULL;
	} 
    else if(root->data == data){
        root->cnt--;
    }
    else if (root->data > data) {
		root->left = deleteNode(root->left, data);
		return root;
	} else if (root->data < data) {
		root->right = deleteNode(root->right, data);
		return root;
	} else {
		if (root->left == NULL && root->right == NULL) {
			delete root;
			return NULL;
		} else if (root->right == NULL) {
			Node* temp = root->left;
			delete root;
			return temp;
		} else if (root->left == NULL) {
			Node* temp = root->right;
			delete root;
			return temp;
		} else {
			Node* temp = getMin(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
			return root;
		}
	}
    return root;
}

int find(Node* root, int x) {
	if (root == NULL) {
		return 0;
	} else if (root->data == x) {
		return root->cnt;
	} else if (root->data < x) {
		return find(root->right, x);
	} else {
		return find(root->left, x);
	}
    return root->cnt;
}

int main(){
    int n; cin >> n;
    Node * root = NULL;
    for(int i = 0; i < n; i++){
        string s; int x;
        cin >> s;
        if(s == "insert"){
            cin >> x;
            root = add(root, x);
        }
        else if(s == "cnt"){
            cin >> x;
            cout << find(root, x) <<endl;
        }
        else if(s == "delete"){
            cin >> x;
            root = deleteNode(root, x);
        }
    }
}