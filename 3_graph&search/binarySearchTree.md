# 二叉树的遍历

- 前序遍历：根节点 --- 左子树 --- 右子树
- 中序遍历：左子树 --- 根节点 --- 右子树
- 后序遍历：左子树 --- 右子树 --- 根节点
- 层次遍历：按层遍历

> 前序遍历

```
# 递归版本
void preOrder(TreeNode* root)
{
    if(root != null)
    {
        cout<<root->val<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

# 非递归版本 - linkedList
void preOrder(TreeNode* root)
{
    LinkedList<TreeNode*>stack = new LinkedList<>();
    TreeNode* x = root;
    while(!x || !stack.isEmpty())
    {
        if(x)
        {
            cout<<x->val;
            stack.push(x);
            if(x->left)x = x->left;
        }else
        {
            x = stack.pop();
            x = x->right;
        }
    }
}


# 非递归版本 - array

```

> 中序遍历

```
# 递归版本
void inOrder(TreeNode* root)
{
    if(root != null)
    {
        inOrder(root->left);
        cout<<root->val<<" ";
        inOrder(root->right);
    }
}

# 非递归版本
void inOrder(TreeNode* root)
{
    LinkedList<TreeNode*>stack = new LinkedList<>();
    TreeNode* x = root;
    while(!x || !stack.isEmpty())
    {
        if(x)
        {
            stack.push(x);
            if(x->left)x = x->left;
        }else
        {
            x = stack.pop();
            cout<<x->val();
            x = x->right;
        }
    }
}
```

> 后续遍历

```
# 递归版本
void postOrder(TreeNode* root)
{
    if(root != null)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->val<<" ";
    }
}

# 非递归版本
void inOrder(TreeNode* root)
{
    LinkedList<TreeNode*>stack = new LinkedList<>();
    TreeNode* x = root;
    while(!x || !stack.isEmpty())
    {
        if(x)
        {
            stack.push(x);
            if(x->left)x = x->left;
        }else
        {
            
        }
    }
}
```

> 层次遍历

```
void levelOrder(TreeNode* root)
{
	if(!root)return;
	LinkedList<TreeNode*> queue = new LinkedList<>();
	queue.offer(root);
	while(!queue.isEmpty())
	{
		TreeNode* node = queue.poll()
		cout>>node->val>>" ";
		if(node.left)queue.offer(node.left);
		if(node.right)queue.offer(node.left);
	}
}
```



https://blog.csdn.net/My_Jobs/article/details/43451187