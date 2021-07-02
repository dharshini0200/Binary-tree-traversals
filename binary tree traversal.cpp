#include<iostream>
#include<stack>
#include<queue>
using namespace std;
struct binarytree
{
    int data;
    struct binarytree *left;
    struct binarytree *right;
}*root;
binarytree* newnode(int data)
{
    struct binarytree* current=root;;
    current= new binarytree;
    current->data=data;
    current->left=NULL;
    current->right=NULL;
    return current;
}

void preorder(struct binarytree* node)
{
    if(node==NULL)
        return;
    cout<<node->data<<" ";
    preorder(node->left);
    preorder(node->right);
}
void  nonrecursivepreorder(struct binarytree* root)
{
    struct binarytree* current=root;
    stack<binarytree*>s;
    s.push(current);
    while(!s.empty())
    {
        current=s.top();
        s.pop();
        cout<<current->data<<" ";
        if(current->right)
          s.push(current->right);
        if(current->left)
            s.push(current->left);


    }
}
void inorder(struct binarytree *node)
{
    if(node==NULL)
    return;
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}
void nonrecursiveinorder(struct binarytree* root)
{
    struct binarytree* current=root;
    stack<binarytree*>s;
    while(current!=NULL || s.empty()==false)
    {
        while(current!=NULL)
        {
            s.push(current);
            current=current->left;
        }
        current=s.top();
        s.pop();
        cout<<current->data<<" ";
        current=current->right;
    }
}

void postorder(struct binarytree *node)
{
    if(node==NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    cout<<node->data<<" ";
}

void  nonrecursivepostorder(struct binarytree* root)
{
    struct binarytree* current=root;
    stack<binarytree*>s1,s2;
    s1.push(current);
    while(s1.empty()==false)
    {
        current=s1.top();
        s1.pop();
        s2.push(current);
        if(current->left)
            s1.push(current->left);
        if(current->right)
            s1.push(current->right);
    }
    while(!s2.empty())
    {
        current=s2.top();
        s2.pop();
        cout<<current->data<<" ";

    }
}
void printlevelorder(struct binarytree *root)
{

	if (root == NULL) return;
	queue<binarytree*> q;
	q.push(root);

	while (q.empty() == false)
	{
		binarytree *node = q.front();
		cout << node->data << " ";
		q.pop();


		if (node->left != NULL)
			q.push(node->left);


		if (node->right != NULL)
			q.push(node->right);
	}
}
void reverselevelorder(struct binarytree* root)
{
    stack <binarytree *> S;
    queue <binarytree*> Q;
    Q.push(root);

    while (Q.empty() == false)
    {
        root = Q.front();
        Q.pop();
        S.push(root);

        if (root->right)
            Q.push(root->right);

        if (root->left)
            Q.push(root->left);
    }

    while (S.empty() == false)
    {
        root = S.top();
        cout << root->data << " ";
        S.pop();
    }
}
int height( struct binarytree* root)
{
    if (root == NULL)
        return -1;
    else
    {
        int lDepth = height(root->left);
        int rDepth = height(root->right);


        if (lDepth > rDepth)
            return(lDepth + 1);
        else return(rDepth + 1);
    }
}



int main()
{
    int ch;
    root=newnode(1);
    root->left=newnode(2);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    root->right=newnode(3);
    while(1){
    cout<<endl;
    cout<<" 1.Preorder: "<<endl;
    cout<<" 2.Non recursive preorder:"<<endl;
    cout<<" 3.Inorder:"<<endl;
    cout<<" 4.Non recursive inorder:"<<endl;
    cout<<" 5.Postorder:"<<endl;
    cout<<" 6.Non recursive postorder:"<<endl;
    cout<<" 7.Leveleorder:"<<endl;
    cout<<" 8.Leveleorder in reverse :"<<endl;
    cout<<" 9.height:"<<endl;

    cout<<"Enter the choice:";
    cin>>ch;
    switch(ch)
    {
    case 1:
        cout<<"preorder:";
        preorder(root);
        break;
    case 2:
        cout<<"non recursive preorder:";
        nonrecursivepreorder(root);
        break;
    case 3:
        cout<<"inorder:";
        inorder(root);
        break;
    case 4:
        cout<<"nonrecursive inorder:";
        nonrecursiveinorder(root);
        break;
    case 5:
        cout<<"Postorder:";
        postorder(root);
        break;
    case 6:
        cout<<"nonrecursive postorder:";
        nonrecursivepostorder(root);
        break;
    case 7:
        cout<<"levelorder:";
        printlevelorder(root);
        break;
    case 8:
        cout<<"levelorder (reverse):";
        reverselevelorder(root);
        break;
    case 9:
        cout<<"height:";
        cout<< height(root);
        break;

    }
    }

}
