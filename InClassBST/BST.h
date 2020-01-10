#ifndef BST_H
#define BST_H

class BST{
  private:
    TreeNode *root;

  public:
    BST();
    ~BST();

    bool search(int value);
    void insert(int value);
    bool deleteNode(int value);

    //helper functions
    bool isEmpty();
    TreeNode* getMin();
    TreeNode *getMax();
    void printTree();
    void recPrint(TreeNode *node);
    TreeNode* getSuccessor(TreeNode *d);
};

BST::BST(){
  root = NULL; //empty tree
}

BST::~BST(){
  //more character building
}

void BST::recPrint(TreeNode *node){
  if(node == NULL)
    return;

  recPrint(node->left);
  cout << node->key << endl;
  recPrint(node->right);
}

void BST::printTree(){
  recPrint(root);
}

TreeNode* BST::getMax(){

  TreeNode *current = root;

  if(root == NULL)
    return NULL;

  while(current->right != NULL){
    current = current->right; //keep going down to the right side of the tree
  }

  return current; //return &(current->key)
}

TreeNode* BST::getMin(){

  TreeNode *current = root;

  if(root == NULL)
    return NULL;

  while(current->left != NULL){
    current = current->left; //keep going down to the left side of the tree
  }

  return current; //return &(current->key)
}

void BST::insert(int value){

  TreeNode *node = TreeNode(value);

  //check if value exists in tree before proceeding

  if(root == NULL){ //the tree is empty
    root = node;
  }
  else{ //the tree is not empty, so let's find the insertion point
    TreeNode *current = root;
    TreeNode *parent = NULL;

    while(true){
      parent = current;

      if(value < current->key){
        //we go left
        current = current -> left;

        if(current == NULL){
          parent->left = node;
          break;
        }
      }
      else{
        current = current -> right;

        if(current == NULL){
          parent->right = node;
          break;
        }
      }
    }
  }
}

bool BST::search(int value){

  if(root == NULL){
    return false;
  }

  //if we make it this far then we know the tree is not empty
  //let's attempt to find it
  TreeNode *current = root;

  while(current->key != value){

    if(value < current->key){
      //we go left
      current = current -> left;
    }
    else{
      current = current -> right;
    }

    if(current == NULL){
      return false;
    }
  }
  return true;
}

bool BST::deleteNode(int value){

  if(root == NULL)
    return false;

  TreeNode *parent = root;
  TreeNode *current = root;
  bool isLeft = true;

  //let's attempt to fund the node to be deleteNode
  while(current->key != value)
  {
    parent = current;

    if(value < current->key){
      //go left
      isLeft = true;
      current = current -> left;
    }
    else {
      //we go right
      isLeft = false;
      current = current ->right;
    }

    if(current == NULL) //value doesn't exist
      return false
  }
  //if we make if here, then we found the node to be deleted

  if(current -> left == NULL && current -> right ==NULL){
    //node is a leaf, no children
    if(current == root){
      root = NULL;
    }
    else if(isLeft){
      parent -> left = NULL;
    }else{
      parent -> right = NULL;
    }
  }
  else if(curent -> right == NULL ){
    //node to be deleted has one child and it's a left (no right child)
    if(current == root){
      root = current->left;
    }
    else if(isLeft){
      parent -> left = current -> left;
    }
    else{
      parent->right = current->left;
    }
  }
  else if(current -> left == NULL){
    //node to be deleted has one child and it's a right(no right child)
    if(current == root){
      root = current->right;
    }
    else if(isLeft){
      parent -> left = current -> right;
    }
    else{
      parent->right = current->right;
    }
  }
  else
  {
    //the node to be deleted has two children
    //at this state the cortisol levels increase exponentially

    TreeNode *successor = getSuccessor(current);

    if(current == root){
      root = successor;
    }
    else if(isLeft){
      parent -> left = successor;
    }
    else{
      parent -> right = successor;
    }
    successor -> left = current -> left;
  }
  return true;
}

TreeNode* BST::getSuccessor(TreeNode *d) //d is the node to be deleted
{
  TreeNode *current = d -> right;
  TreeNode *sp = d; //successor's parent
  TreeNode *successor = d;

  while(current != NULL){
    sp = successor;
    successor = current;
    current = current -> left;
  }
  //we made it here that means we found our successor

  if(successor != d -> right){
    sp -> left == successor -> right;
    successor -> right = d -> right;
  }
  return successor;
}

#endif
