
#include <iostream>

 

using namespace std;

 

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
    

 

TreeNode *insert(TreeNode *tree, int val) {
  if(!tree) {
    tree = new TreeNode(val);
    return tree;
  }
  if(val <= tree->val) tree->left = insert(tree->left, val);
  else tree->right = insert(tree->right, val);
  return tree;
}
bool func(TreeNode *tree, string s){
    TreeNode *node = tree;
    
    for(int i=0;i<s.size();i++){
        if(s[i]=='L'){
            node = node->left;
        }else{
            node = node->right;
        }
        if(node == NULL){
            return false;
        }
    }
    return true;
}

 
TreeNode *root;
int main()
{
    int n,m,p; cin >> n >> m >> p;
    root = insert(root, p);
    for(int i = 1; i < n; i++){
        cin >> p;
        insert(root, p);
    }
    string s;
    for(int i=0;i<m;i++){
        cin>>s;
        if(func(root,s)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    

 

    return 0;
}