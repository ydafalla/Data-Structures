#include "Leftist.h"

Leftist::Leftist()
{
  root=NULL;
}


Leftist::~Leftist()
{
  Flush(GetRoot());
}

void Leftist::Flush(node* rt)
{
  node* temp=rt;
  if(temp==NULL)
  return ;
  if(temp->leftChild==NULL && temp->rightChild==NULL)
  delete temp;
  else
  {
    Flush(temp->leftChild);
    Flush(temp->rightChild);
    delete temp;
  }

}

node* Leftist::GetRoot()
{
  return root;
}

void Leftist::SetRoot(node* temp)
{
  root=temp;
}

void Leftist::Buildheap()
{
  int x;
  ifstream myfile;
  myfile.open("data.txt");
  if(myfile.is_open())
  {
    myfile>>x;
    while(!myfile.eof())
    {
      Insert(x);
      myfile>>x;
    }
  }
  else
    cout<<"Couldn't open the file\n";
}

node* Leftist::Concate(node* H1,node* H2)
{
  if(H1==NULL)
  return H2;
  if(H2==NULL)
  return H1;
  if(H1->data < H2->data)
  return Concate(H2,H1);
  H1->rightChild=Concate(H1->rightChild,H2);
  H1->rank=Rank(H1);
  if(Rank(H1->leftChild) < Rank(H1->rightChild))
  {
    node* temp=H1->leftChild;
    H1->leftChild=H1->rightChild;
    H1->rightChild=temp;
  }
  return H1;
}


void Leftist::FindMax()
{
  if(root==NULL)
  {
    cout<<"Leftist Heap is empty\n";
  }
  else
  {
    cout<<"The maximum element in the leftist heap is: "<<root->data;
  }
}

void Leftist::DeleteMax()
{
  node* temp=root;
  if(temp==NULL)
  {
    cout<<"Tree is empty\n";
    return ;
  }
  else
  {
    root=Concate(root->leftChild,root->rightChild);
    cout<<temp->data<<" is deleted successfully\n";
    delete temp;
  }
}



unsigned int Leftist::Rank(node* temp)
{
  if(temp==NULL)
  return 0;
  unsigned int leftRank=Rank(temp->leftChild);
  unsigned int rightRank=Rank(temp->rightChild);
  if(leftRank<=rightRank)
  return 1+leftRank;
  else
  return 1+rightRank;
}

void Leftist::Insert(int x)
{
  node* temp=new node;
  temp->data=x;
  temp->leftChild=NULL;
  temp->rightChild=NULL;
  temp->rank=Rank(temp);
  root=Concate(GetRoot(),temp);
}

void Leftist::PreOrder(node* rt)
{
  node* temp=rt;
  if(temp==NULL)
  return ;
  cout<<temp->data<<" ";
  PreOrder(temp->leftChild);
  PreOrder(temp->rightChild);
}


void Leftist::InOrder(node* rt)
{
  node* temp=rt;
  if(temp==NULL)
  return ;
  InOrder(temp->leftChild);
  cout<<temp->data<<" ";
  InOrder(temp->rightChild);
}

void Leftist::PostOrder(node* rt)
{
  node* temp=rt;
  if(temp==NULL)
  return ;
  PostOrder(temp->leftChild);
  PostOrder(temp->rightChild);
  cout<<temp->data<<" ";
}

int Leftist::Height(node* rt)
{
  node* temp=rt;
  if(temp==NULL)
  return 0;
  else
  {
    int lheight=Height(temp->leftChild);
    int rheight=Height(temp->rightChild);
    if(lheight>=rheight)
    return 1+lheight;
    else
    return 1+rheight;
  }
}

void Leftist::LevelOrder(node* rt)
{
  node* temp=rt;
  int h=Height(temp);
  if(h==0)
  {
    cout<<"Empty tree\n";
    return ;
  }
  int i;
  for(i=1;i<=h;i++)
  {
    PrintLevel(temp,i);
    cout<<endl;
  }
}

void Leftist::PrintLevel(node* rt,int level)
{
  node* temp=rt;
  if(temp==NULL)
  return ;
  if(level==1)
  {
    cout<<temp->data<<" ";
    return ;
  }
  if(level>1)
  {
    PrintLevel(temp->leftChild,level-1);
    PrintLevel(temp->rightChild,level-1);
  }
}
