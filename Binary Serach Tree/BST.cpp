#include "BST.h"
BST::BST()
{
  root=NULL;
}

BST::~BST()
{
  Flush(root);
}

void BST::Flush(node* rt)
{
  if(rt==NULL)
  return;
  else
  {
    Flush(rt->leftNode);
    Flush(rt->rightNode);
    delete rt;
  }
}

node* BST::GetRoot()
{
  return root;
}


void BST::SetRoot(node* rt)
{
  root=rt;
}


node* BST::Insert(node* rt,int x)
{
  if(rt==NULL)
  {
    node* newNode=new node;
    newNode->data=x;
    rt=newNode;
    rt->leftNode=NULL;
    rt->rightNode=NULL;
    return rt;
  }
  else
  {
    if(rt->data>x)
    rt->leftNode=Insert(rt->leftNode,x);
    else
    rt->rightNode=Insert(rt->rightNode,x);
    return rt;
  }
}

node* BST::FindMin(node* rt)
{
  node* temp=rt;
  if(temp==NULL)
  return temp;
  else
  {
    while(temp->leftNode!=NULL)
    temp=temp->leftNode;
  }
  return temp;
}


node* BST::DeleteMin(node* rt)
{
  if(rt==NULL)
  {
    return rt;
  }
  else
  {

    if(rt->leftNode==NULL)
    {
      node* temp=rt->rightNode;
      cout<<rt->data<<" has been deleted\n";
      delete rt;
      return temp;
    }
    else
    {
      rt->leftNode=DeleteMin(rt->leftNode);
    }
    return rt;
  }
}

node* BST::Find(int x,node* rt)
{
  node* temp=rt;
  if(temp==NULL)
  {
    return temp;
  }
  else
  {
    if(temp->data==x)
    return temp;
    else
    {
      if(x<temp->data)
      return Find(x,temp->leftNode);
      else
      return Find(x,temp->rightNode);
    }
  }
}

node* BST::Delete(int x,node* rt)
{
  node* temp=rt;
  if(temp==NULL)
  return temp;
  else
  {
    if(x<temp->data)
    temp->leftNode=Delete(x,temp->leftNode);
    else
    {
      if(x>temp->data)
      temp->rightNode=Delete(x,temp->rightNode);
      else
      {
        if(temp->leftNode==NULL)
        {
          node* temp1=temp->rightNode;
          delete temp;
          return temp1;
        }
        else
        {
          if(temp->rightNode==NULL)
          {
            node* temp1=temp->rightNode;
            delete temp;
            return temp1;
          }
        }
        node* temp1=FindMin(temp->rightNode);
        temp->data=temp1->data;
        temp->rightNode=Delete(temp->data,temp->rightNode);
      }
    }
  }
  return temp;
}

node* BST::DeleteMax(node* rt)
{
  if(rt==NULL)
  {
    return rt;
  }
  else
  {

    if(rt->rightNode==NULL)
    {
      node* temp=rt->leftNode;
      cout<<rt->data<<" has been deleted\n";
      delete rt;
      return temp;
    }
    else
    {
      rt->rightNode=DeleteMax(rt->rightNode);
    }
    return rt;
  }

}




void BST::FindMinimum(node* rt)
{
  if(rt==NULL)
  {
    cout<<"Empty Tree\n";
  }
  else
  {
    if(rt->leftNode==NULL)
      cout<<endl<<rt->data<<" is the smallest element";
    else
      FindMinimum(rt->leftNode);
  }

}



void BST::FindMax(node* rt)
{
  if(rt==NULL)
  {
    cout<<"Empty Tree\n";
  }
  else
  {
    if(rt->rightNode==NULL)
      cout<<endl<<rt->data<<" is the largest element";
    else
      FindMax(rt->rightNode);
  }

}

void BST::Inorder(node* rt)
{
  if(rt==NULL)
  {
    return ;
  }
  else
  {
    Inorder(rt->leftNode);
    cout<<rt->data<<" ";
    Inorder(rt->rightNode);
  }
}

void BST::Preorder(node* rt)
{
  if(rt==NULL)
  {
    return ;
  }
  else
  {
    cout<<rt->data<<" ";
    Preorder(rt->leftNode);
    Preorder(rt->rightNode);
  }
}

void BST::Postorder(node* rt)
{
  if(rt==NULL)
  {
    return ;
  }
  else
  {
    Postorder(rt->leftNode);
    Postorder(rt->rightNode);
    cout<<rt->data<<" ";
  }
}
