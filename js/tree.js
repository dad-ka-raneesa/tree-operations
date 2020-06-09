const Traversals = require('./traversals');
const {
  insert_node,
  search_node,
  delete_node,
  rotate_left,
  rotate_right,
  get_node_of,
  balance_tree,
} = require('./tree_with_recursion');

const main = () => {
  let values = [3, 1, 5, 0, 2, 4, 6];
  let tree = values.reduce(insert_node, null);

  console.log('tree =>');
  Traversals.printInOrder(tree);

  let result = search_node(tree, 3);
  console.log(3, 'is', result ? '' : 'not', 'present in the tree.');

  tree = delete_node(tree, 3);
  console.log('tree =>');
  Traversals.printInOrder(tree);

  result = search_node(tree, 3);
  console.log(3, 'is', result ? '' : 'not', 'present in the tree.');

  tree = values.reduce(insert_node, null);
  console.log('Rotate Right 1');
  console.log('before =>');
  Traversals.printPreOrder(tree);
  tree = rotate_right(tree, get_node_of(tree, 1));
  console.log('after =>');
  Traversals.printPreOrder(tree);

  console.log('Rotate Left 0');
  console.log('before =>');
  Traversals.printPreOrder(tree);
  tree = rotate_left(tree, get_node_of(tree, 0));
  console.log('after =>');
  Traversals.printPreOrder(tree);

  values = [1, 0, 2, 3, 4, 5, 6];
  tree = values.reduce(insert_node, null);

  console.log('Before Balancing');
  Traversals.printPreOrder(tree);

  tree = balance_tree(tree);

  console.log('After Balancing');
  Traversals.printPreOrder(tree);
};

main();

/*
     3
   /   \
  1     5
 / \   / \
0   2 4   6
*/