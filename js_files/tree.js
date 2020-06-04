const createNode = value => {
  return { value, left: null, right: null };
};

const insert = (tree, value) => {
  if (tree == null) {
    return createNode(value);
  }
  if (value < tree.value) {
    tree.left = insert(tree.left, value);
  } else {
    tree.right = insert(tree.right, value);
  }
  return tree;
};

const search_node = (tree, value) => {
  let result = false;
  let walker = tree;
  while (walker != null && !result) {
    if (value == walker.value) result = true;
    if (value < walker.value) walker = walker.left;
    else walker = walker.right;
  }
  return result;
};

const minOfRight = (root) => {
  let p_walk = root;
  while (p_walk.left != null) {
    p_walk = p_walk.left;
  }
  return p_walk;
};

const deletion = (tree, value) => {
  if (tree === null) {
    return tree;
  }
  if (value < tree.value) {
    tree.left = deletion(tree.left, value);
    return tree;
  }
  if (value > tree.value) {
    tree.right = deletion(tree.right, value);
    return tree;
  }
  if (tree.left === null) {
    let right_node = tree.right;
    delete tree;
    return right_node;
  }
  if (tree.right === null) {
    let left_node = tree.left;
    delete tree;
    return left_node;
  }
  let min = minOfRight(tree.right);
  tree.value = min.value;
  tree.right = deletion(tree.right, min.value);
  return tree;
};


const printInOrder = tree => {
  if (tree == null) {
    return;
  }
  printInOrder(tree.left);
  console.log(tree.value);
  printInOrder(tree.right);
};

const printPreOrder = tree => {
  if (tree == null) {
    return;
  }
  console.log(tree.value);
  printPreOrder(tree.left);
  printPreOrder(tree.right);
};

const printPostOrder = tree => {
  if (tree == null) {
    return;
  }
  printPostOrder(tree.left);
  printPostOrder(tree.right);
  console.log(tree.value);
};
