Node_ptr rotate_right(Node_ptr root){
  if(root == NULL) return root;

  Node_ptr temp = root->left;
  root->left = temp->right;
  temp->right = root;
  return root; 
}

Node_ptr rotate_left(Node_ptr root){
  if(root == NULL) return root;

  Node_ptr temp = root-right;
  root-right = temp->left;
  temp->left = root;
  return root; 
}

Node_ptr rotate(Node_ptr root, int balance_factor){
  if(balance_factor < 1){
    int left_balance_factor = get_balance_factor(root->left);
    if(left_balance_factor > 1){
      root->left = rotate_left(tree->left);
    }
    return rotate_right(tree);
  }
  int right_balance_factor = get_balance_factor(root->right);
    if(right_balance_factor > 1){
      root->right = rotate_right(tree->right);
    }
    return rotate_left(tree);
  }
}

int height(Node_ptr root){
  if(root == NULL) return 0;
  return 1 + height(root->left) + height(root->right);
}

int get_balance_factor(Node_ptr root){
  int r_height = height(root->right);
  int l_height = height(root->left);
  return r_height - l_height;
}

Node_ptr balance_with_rotation(Node_ptr root){
  Node_ptr new_root = NULL;
  int balance_factor = get_balance_factor(root);
  while(balance_factor > 1 || balance_factor < -1){
    root = rotate(root, balance_factor);
    balance_factor = get_balance_factor(root);
  }
  root->right = balance_with_rotation(root->right);
  root->left = balance_with_rotation(root->left;
  return root;
}
