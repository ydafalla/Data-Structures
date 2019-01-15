#include "SkewHeap.h"

SkewHeap::SkewHeap()
{
  SetRoot(NULL);
}

SkewHeap::~SkewHeap()
{
  Flush(GetRoot());

}

void SkewHeap::Flush(node* rt)
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

void SkewHeap::SetRoot(node* temp)
{
  root=temp;
}

node* SkewHeap::GetRoot()
{
  return root;
}


void SkewHeap::Buildheap()
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

node* SkewHeap::Concate(node* H1,node* H2)
{
  if(H1==NULL)
  return H2;
  if(H2==NULL)
  return H1;
  if(H1->key<H2->key)
  return Concate(H2,H1);
  else
  {
    node* temp=H1->rightChild;
    H1->rightChild=H1->leftChild;
    H1->leftChild=Concate(temp,H2);
    return H1;
  }
}


void SkewHeap::Insert(int x)
{
  node* newNode=new node;
  newNode->key=x;
  newNode->leftChild=NULL;
  newNode->rightChild=NULL;
  SetRoot(Concate(GetRoot(),newNode));
}

void SkewHeap::FindMax()
{
  node* rt=GetRoot();
  if(rt==NULL)
  {
    cout<<"Heap is empty\n";
    return ;
  }
  cout<<"\nThe maximum element in the heap is: "<<rt->key<<endl;
}

void SkewHeap::DeleteMax(node* rt)
{
  node* temp=rt;
  if(temp==NULL)
  {
    cout<<"Heap is empty\n";
    return ;
  }
  SetRoot(Concate(rt->leftChild,rt->rightChild));
  cout<<endl<<temp->key<<" deleted successfully\n";
  delete temp;
}


void SkewHeap::PreOrder(node* rt)
{
  node* temp=rt;
  if(temp==NULL)
  return ;
  cout<<temp->key<<" ";
  PreOrder(temp->leftChild);
  PreOrder(temp->rightChild);
}


void SkewHeap::InOrder(node* rt)
{
  node* temp=rt;
  if(temp==NULL)
  return ;
  InOrder(temp->leftChild);
  cout<<temp->key<<" ";
  InOrder(temp->rightChild);
}

void SkewHeap::PostOrder(node* rt)
{
  node* temp=rt;
  if(temp==NULL)
  return ;
  PostOrder(temp->leftChild);
  PostOrder(temp->rightChild);
  cout<<temp->key<<" ";
}


int SkewHeap::Height(node* rt)
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

void SkewHeap::LevelOrder(node* rt)
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

void SkewHeap::PrintLevel(node* rt,int level)
{
  node* temp=rt;
  if(temp==NULL)
  return ;
  if(level==1)
  {
    cout<<temp->key<<" ";
    return ;
  }
  if(level>1)
  {
    PrintLevel(temp->leftChild,level-1);
    PrintLevel(temp->rightChild,level-1);
  }
}
