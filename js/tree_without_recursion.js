const create_node = value => {
  return { value, left: null, right: null };
};

const insert_without_recur = (tree, value) => {
  const new_node = create_node(value);
  let pos_to_insert = null;
  let walker = tree;
  while (walker != null) {
    pos_to_insert = walker;
    if (value < walker.value) walker = walker.left;
    else walker = walker.right;
  }
  if (pos_to_insert == null) return new_node;
  if (value < pos_to_insert.value) pos_to_insert.left = new_node;
  else pos_to_insert.right = new_node;
  return tree;
};

const search_without_recur = (tree, value) => {
  let result = false;
  let walker = tree;
  while (walker != null && !result) {
    if (value == walker.value) result = true;
    if (value < walker.value) walker = walker.left;
    else walker = walker.right;
  }
  return result;
};

module.exports = { insert_without_recur, search_without_recur };