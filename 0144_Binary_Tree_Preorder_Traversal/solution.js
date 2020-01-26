function TreeNode(val) {
  this.val = val;
  this.left = this.right = null;
}

var preorderTraversal = function (root) {
  var result = [];

  if (root === null) {
    return result;
  }


  var stack = [root];
  while (stack.length > 0) {
    var curr = stack.pop();
    result.push(curr.val);

    if(curr.right){
      stack.push(curr.right);
    }
    if(curr.left){
      stack.push(curr.left);
    }
  }
  return result;
};
