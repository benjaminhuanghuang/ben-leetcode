/*
You are given a tree that contains N nodes, each containing an integer u which corresponds to a lowercase character c 
in the string s using 1-based indexing.
You are required to answer Q queries of type [u, c], where u is an integer and c is a lowercase letter. 
The query result is the number of nodes in the subtree of node u containing c.

https://leetcode.com/discuss/post/756125/facebook-recruiting-portal-nodes-in-a-su-fmys/

[Meta]
*/

// Add any extra import statements you may need here

// Definition for a Node
function Node(val, children) {
  this.val = val === undefined ? 0 : val;
  this.children = children === undefined ? [] : children;
}

// Add any helper functions you may need here

/*
The query result is the number of nodes in the subtree of node u containing c.
*/
function countOfNodes(root, queries, string) {
  // Write your code here
  if (root === null) return [0]; // Return if the tree is empty

  const ans = [];

  for (const query of queries) {
    const c = query[1];
    const v = query[0];
    let curr = null;
    const charCounter = new Map();

    if (root.val !== v) {
      // If root is not the target node, search in children
      for (const node of root.children) {
        if (node.val === v) {
          // Found the query node
          curr = node;
          break;
        }
      }
    } else {
      curr = root;
    }

    if (curr !== null) {
      // Traverse the n-ary tree
      traverse(curr, c, charCounter, string);
    }
    if (charCounter.size > 0) {
      // Check if the map is not empty
      ans.push(charCounter.get(c) || 0);
    }
  }

  return ans;
}

// counter for the character in the tree
function traverse(root, c, charCounter, s) {
  if (root === null) return;

  if (s[root.val - 1] === c) {
    // Check if character matches the query
    charCounter.set(c, (charCounter.get(c) || 0) + 1);
  }

  for (const node of root.children) {
    // Traverse the tree
    traverse(node, c, charCounter, s);
  }
}

// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.
function printintegerArray(array) {
  var size = array.length;
  var res = "";
  res += "[";
  var i = 0;
  for (i = 0; i < size; i++) {
    if (i !== 0) {
      res += ", ";
    }
    res += array[i];
  }
  res += "]";
  return res;
}

var test_case_number = 1;

function check(expected, output) {
  var expected_size = expected.length;
  var output_size = output.length;
  var result = true;
  if (expected_size != output_size) {
    result = false;
  }
  for (var i = 0; i < Math.min(expected_size, output_size); i++) {
    result &= output[i] == expected[i];
  }
  var rightTick = "\u2713";
  var wrongTick = "\u2717";
  if (result) {
    var out = rightTick + " Test #" + test_case_number;
    console.log(out);
  } else {
    var out = "";
    out += wrongTick + " Test #" + test_case_number + ": Expected ";
    out += printintegerArray(expected);
    out += " Your output: ";
    out += printintegerArray(output);
    console.log(out);
  }
  test_case_number++;
}

// Testcase 1
var n_1 = 3,
  q_1 = 1;
var s_1 = "aba";
var node_1 = new Array(n_1 + 1);
for (var i = 1; i <= n_1; i++) {
  node_1[i] = new Node(i);
}
var root1 = node_1[1];
node_1[1].children = [node_1[2], node_1[3]];
var queries_1 = [[1, "a"]];
var output_1 = countOfNodes(root1, queries_1, s_1);
var expected_1 = [2];
check(expected_1, output_1);

// Testcase 2
var n_2 = 7,
  q_2 = 3;
var s_2 = "abaacab";
var node_2 = new Array(n_2 + 1);
for (var i = 1; i <= n_2; i++) {
  node_2[i] = new Node(i);
}
var root2 = node_2[1];
node_2[1].children = [node_2[2], node_2[3], node_2[7]];
node_2[2].children = [node_2[4], node_2[5]];
node_2[3].children = [node_2[6]];
var queries_2 = [
  [1, "a"],
  [2, "b"],
  [3, "a"],
];
var output_2 = countOfNodes(root2, queries_2, s_2);
var expected_2 = [4, 1, 2];
check(expected_2, output_2);

// Add your own test cases here
