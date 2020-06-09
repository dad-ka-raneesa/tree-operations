const createNode = value => {
  return { value, left: null, right: null };
};

const insert_node = (tree, value) => {
  if (tree == null) {
    return createNode(value);
  }
  if (value < tree.value) {
    tree.left = insert_node(tree.left, value);
  } else {
    tree.right = insert_node(tree.right, value);
  }
  return tree;
};

const search_node = (tree, value) => {
  if (tree == null) return false;
  if (value == tree.value) return true;
  if (value < tree.value) return search_node(tree.left, value);
  return search_node(tree.right, value);
};

const minOfRight = (root) => {
  let min_of_right = root;
  while (min_of_right && min_of_right.left != null) {
    min_of_right = min_of_right.left;
  }
  return min_of_right;
};

const delete_node = (tree, value) => {
  if (tree === null) {
    return tree;
  }
  if (value < tree.value) {
    tree.left = delete_node(tree.left, value);
    return tree;
  }
  if (value > tree.value) {
    tree.right = delete_node(tree.right, value);
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
  tree.right = delete_node(tree.right, min.value);
  return tree;
};

const rotate_right = (tree, pivot) => {
  if (tree == null) return tree;
  if (pivot.value < tree.value) {
    tree.left = rotate_right(tree.left, pivot);
    return tree;
  }
  if (pivot.value > tree.value) {
    tree.right = rotate_right(tree.right, pivot);
    return tree;
  }
  const pivot_Left = pivot.left;
  if (pivot_Left == null) return pivot;
  pivot.left = pivot_Left.right;
  pivot_Left.right = pivot;
  return pivot_Left;
};

const rotate_left = (tree, pivot) => {
  if (tree == null) return tree;
  if (pivot.value < tree.value) {
    tree.left = rotate_left(tree.left, pivot);
    return tree;
  }
  if (pivot.value > tree.value) {
    tree.right = rotate_left(tree.right, pivot);
    return tree;
  }
  const pivot_Right = pivot.right;
  if (pivot_Right == null) return pivot;
  pivot.right = pivot_Right.left;
  pivot_Right.left = pivot;
  return pivot_Right;
};

const get_sorted_tree_list = (tree, array) => {
  if (tree == null) return array;
  get_sorted_tree_list(tree.left, array);
  array.push(tree.value);
  get_sorted_tree_list(tree.right, array);
  return array;
};

const balance_tree = tree => {
  let new_tree = null;
  let tree_values_in_order = [];
  tree_values_in_order = get_sorted_tree_list(tree, tree_values_in_order);
  const pivot_index = tree_values_in_order.length / 2;
  new_tree = tree_values_in_order
    .slice(pivot_index, pivot_index + 1)
    .reduce(insert_node, new_tree);
  new_tree = tree_values_in_order
    .slice(0, pivot_index)
    .reduce(insert_node, new_tree);
  new_tree = tree_values_in_order
    .slice(pivot_index + 1)
    .reduce(insert_node, new_tree);
  return new_tree;
};

const get_node_of = (tree, value) => {
  if (tree == null || value == tree.value) return tree;
  if (value < tree.value) return get_node_of(tree.left, value);
  return get_node_of(tree.right, value);
};

module.exports = {
  insert_node,
  search_node,
  delete_node,
  rotate_left,
  rotate_right,
  get_node_of,
  balance_tree,
};
