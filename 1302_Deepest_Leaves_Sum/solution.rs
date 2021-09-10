// Definition for a binary tree node.
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
  pub val: i32,
  pub left: Option<Rc<RefCell<TreeNode>>>,
  pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
  #[inline]
  pub fn new(val: i32) -> Self {
    TreeNode {
      val,
      left: None,
      right: None
    }
  }
}
use std::rc::Rc;
use std::cell::RefCell;


static mut MAX_VAL:i32 = 0;
static mut MAX_LVL:i32 = 0;

impl Solution {
    pub fn deepest_leaves_sum(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {

        fn dfs(root: Option<Rc<RefCell<TreeNode>>>, deep: i32, max_deep: &mut i32,  sum: &mut i32) -> i32 {
            if root == None { return 0; }
            let rb = root.as_ref().unwrap().borrow_mut();
            if deep > *max_deep {
                *max_deep = deep;
                *sum = rb.val;
            } else if deep == *max_deep {
                *sum += rb.val;
            }
            helper(rb.left.clone(),  deep + 1, max_deep, sum);
            helper(rb.right.clone(), deep + 1, max_deep, sum);
            *sum
        }
        let mut max_deep = 0;
        let mut sum = 0;
        dfs(root, 0, &mut max_deep, &mut sum);
        
        sum
    }
}