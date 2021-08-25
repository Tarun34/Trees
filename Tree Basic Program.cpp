# include <iostream>
# include <queue>
using namespace std;
struct node
{
    int data;
    node*left;
    node*right;
    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};
void preorder(node*root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(node*root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(node*root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void levelordertraversal(node*root)
{
    if(root==NULL)
    {
        return;
    }
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node*node = q.front();
        q.pop();
        if(node!=NULL)
        {
            cout<<node->data<<" ";
            if(node->left)
            {
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }
        }
        else if(!q.empty())
        {
            q.push(NULL);
        }
    }

}
int countnodes(node*root)
{
    if(root==NULL)
    {
        return 0;
    }
    return countnodes(root->left)+countnodes(root->right)+1;
}
int sumofallnodes (node*root)
{
    if(root==NULL)
    {
        return 0;
    }
    return sumofallnodes(root->left)+sumofallnodes(root->right)+root->data;
}
int sumatk(node*root,int val)
{
    int sum=0;
    int count=0;
    if(root==NULL)
    {
        return 0;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node*node = q.front();
        q.pop();
        if(node!=NULL)
        {
            if(val==count)
            {
                sum+=node->data;
            }
            if(node->left)
            {
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }
        }
        else if(!q.empty())
        {
            q.push(NULL);
            count++;
        }
    }
    return sum;
}
int main()
{
    node*root=new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    cout<<"Level Order Traversal"<<endl;
    levelordertraversal(root);
    cout<<endl;
    cout<<endl;
    cout<<"Toatal No of Nodes " <<countnodes(root)<<endl;
    cout<<endl;
    cout<<"Sum of all Nodes "<<sumofallnodes(root)<<endl;
    cout<<endl;
    cout<<"Sum at level Two " << sumatk(root,2)<<endl;
    cout<<endl;
    cout<<"Preorder"<<endl;
    preorder(root);
    cout<<endl;
    cout<<endl;
    cout<<"Inorder"<<endl;
    inorder(root);
    cout<<endl;
    cout<<endl;
    cout<<"Postorder"<<endl;
    postorder(root);
    cout<<endl;
    cout<<endl;
}