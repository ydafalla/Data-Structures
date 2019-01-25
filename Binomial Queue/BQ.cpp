#include "BQ.h"

BQ::BQ()
{
  root=NULL;
}

BQ::~BQ()
{
  Flush(root);
}

void BQ::Flush(node* rt)
{
  node* temp=rt;
  if(temp==NULL)
  return ;
  if(temp->firstChild==NULL && temp->rSibling==NULL)
  delete temp;
  else
  {
    Flush(temp->firstChild);
    Flush(temp->rSibling);
    delete temp;
  }

}

node* BQ::GetRoot()
{
  return root;
}

void BQ::SetRoot(node* rt)
{
  root=rt;
}


int BQ::Size(node* rt)
{
  node* temp=rt;
  int count=1;
  while(temp->rSibling!=NULL)
  {
    count++;
    temp=temp->rSibling;
  }
  return count;
}

void BQ::Insert(node* rt,int x)
{
  node* newNode=new node;
  newNode->data=x;
  newNode->lSibling=newNode;
  newNode->rSibling=newNode->firstChild=NULL;
  newNode->order=0;
  SetRoot(Concate(newNode,rt));
}

node* BQ::Merge(node* T1,node* T2)
{
  if(T1->order!=T2->order)
  return NULL;
  else
  {
    if(T1->data<=T2->data)
    {
      int k=T1->order;
      if(k==0)
      {
        T1->firstChild=T2;
        T1->order=1;
        return T1;
      }
      if(k>0)
      {
        T2->lSibling=T1->firstChild->lSibling;
        T2->lSibling->rSibling=T2;
        T1->firstChild->lSibling=T2;
        T1->order=T1->order+1;
        return T1;
      }
    }
    else
    return Merge(T2,T1);
  }
}

node* BQ::Concate(node* Q1,node* Q2)
{
  if(Q1==NULL)
  return Q2;
  if(Q2==NULL)
  return Q1;
  int s1=Size(Q1);
  int s2=Size(Q2);
  int i=0,j=0;
  node* a[s1];
  node* b[s2];
  node* c=NULL;
  node* Q3=NULL;
  node* temp=Q1;
  while(temp!=NULL)
  {
    a[i]=temp;
    temp=temp->rSibling;
    i++;
  }
  i=0;
  temp=Q2;
  while(temp!=NULL)
  {
    b[i]=temp;
    temp=temp->rSibling;
    i++;
  }
  for(i=0;i<s1;i++)
  {
    a[i]->lSibling=a[i];
    a[i]->rSibling=NULL;
  }
  for(i=0;i<s2;i++)
  {
    b[i]->lSibling=b[i];
    b[i]->rSibling=NULL;
  }
  i=0;
  while(i<s1 && j<s2)
  {
    if(a[i]->order < b[j]->order)
    {
      if(c==NULL)
      {
        Q3=Add(a[i],Q3);
        i++;
      }
      else
      {
        if(c->order < a[i]->order)
        {
          Q3=Add(c,Q3);
          c=NULL;
          Q3=Add(a[i],Q3);
          i++;
        }
        else
        {
          if(c->order==a[i]->order)
          {
            c=Merge(a[i],c);
            i++;
          }
        }
      }
    }
    else
    {
      if(a[i]->order == b[j]->order)
      {
        if(c==NULL)
        {
          c=Merge(a[i],b[j]);
          i++;
          j++;
        }
        else
        {
          if(c->order<a[i]->order)
          {
            Q3=Add(c,Q3);
            c=Merge(a[i],b[j]);
            i++;
            j++;
          }
          else
          {
            if(c->order==a[i]->order)
            {
              Q3=Add(c,Q3);
              c=Merge(a[i],b[j]);
              i++;
              j++;
            }
          }
        }
      }
      else
      {
        if(c==NULL)
        {
          Q3=Add(b[j],Q3);
          j++;
        }
        else
        {
          if(c->order < b[j]->order)
          {
            Q3=Add(c,Q3);
            c=NULL;
            Q3=Add(b[j],Q3);
            j++;
          }
          else
          {
            if(c->order==b[j]->order)
            {
              c=Merge(b[j],c);
              j++;
            }
          }
        }
      }
    }
  }


  while(i<s1)
  {
    if(c==NULL)
    {
      Q3=Add(a[i],Q3);
      i++;
    }
    else
    {
      if(c->order<a[i]->order)
      {
        Q3=Add(c,Q3);
        c=NULL;
        Q3=Add(a[i],Q3);
        i++;
      }
      else
      {
        if(c->order==a[i]->order)
        {
          c=Merge(a[i],c);
          //Q3=Add(c,Q3);
          //c=NULL;
          i++;
        }
      }
    }
  }
  while(j<s2)
  {
    if(c==NULL)
    {
      Q3=Add(b[j],Q3);
      j++;
    }
    else
    {
      if(c->order<b[j]->order)
      {
        Q3=Add(c,Q3);
        c=NULL;
        Q3=Add(b[j],Q3);
        j++;
      }
      else
      {
        if(c->order==b[j]->order)
        {
          c=Merge(b[j],c);
          //Q3=Add(c,Q3);
          //c=NULL;
          j++;
        }
      }
    }


  }
  if(c!=NULL)
  {
    Q3=Add(c,Q3);
    c=NULL;
  }
  return Q3;
}


node* BQ::Add(node* t,node* q)
{
  node* pNav=q;
  if(pNav==NULL)
  {
    return t;
  }
  while(pNav->rSibling!=NULL)
  {
    pNav=pNav->rSibling;
  }
  pNav->rSibling=t;
  t->lSibling=pNav;
  t->rSibling=NULL;
  q->lSibling=t;
  return q;
}

void BQ::DeleteMin(node* rt)
{
  if(rt==NULL)
  return ;
  else
  {
    node* temp=rt;
    node* pNav=rt;
    node* min=rt;
    while(pNav!=NULL)
    {
      if(pNav->data < min->data)
      min=pNav;
      pNav=pNav->rSibling;
    }
    while(temp->rSibling!=NULL)
    {
      temp=temp->rSibling;
    }
    if(min->lSibling==min && min->rSibling==NULL)
    {
      SetRoot(Concate(NULL,min->firstChild));
      delete min;
    }
    else
    {
      if(min->lSibling==temp && min->rSibling!=NULL)
      {
        min->rSibling->lSibling=temp;
        SetRoot(Concate(min->rSibling,min->firstChild));
        delete min;
      }
      else
      {
        if(min->lSibling!=temp && min->rSibling!=NULL)
        {
          min->lSibling->rSibling=min->rSibling;
          min->rSibling->lSibling=min->lSibling;
          SetRoot(Concate(rt,min->firstChild));
          delete min;
        }
        else
        {
          node* t=min->lSibling;
          rt->lSibling=t;
          t->rSibling=NULL;
          SetRoot(Concate(rt,min->firstChild));
          delete min;
        }

      }
    }
  }

}

int BQ::FindMin(node* rt)
{
  node* temp=rt;
  if(temp==NULL)
  {
    cout<<"Queue is empty\n";
    return 0;
  }
  int min=temp->data;
  while(temp!=NULL)
  {
    if(temp->data<min)
    min=temp->data;
    temp=temp->rSibling;
  }
  return min;
}

void BQ::Print(node* rt)
{
  node* temp=rt;
  if(temp==NULL)
  {
    cout<<"Binomial Queue is empty\n";
    return ;
  }
  while(temp!=NULL)
  {
    PrintBT(temp);
    cout<<endl<<endl;
    temp=temp->rSibling;
  }
}



void BQ::PrintBT(node* rt)
{
  queue <node*> q;
  node* temp=rt;
  if(temp==NULL)
  return ;
  node* newNode=new node;
  newNode->lSibling=newNode->rSibling=newNode->firstChild=NULL;
  newNode->order=0;
  newNode->data=-1;

  while(1)
  {
    if(temp==rt)
    {

      cout<<temp->data<<endl;
      temp=temp->firstChild;
    }
    if(temp==newNode)
    cout<<endl;
    while(temp!=NULL && temp!=newNode)
    {
      if(temp->firstChild!=NULL)
      {
        if(q.empty())
        {
          q.push(newNode);
          q.push(temp->firstChild);
        }
        else
        {
          q.push(temp->firstChild);
        }
      }
      cout<<temp->data<<" ";
      temp=temp->rSibling;
    }
    if(q.empty())
    return ;
    else
    {
      temp=q.front();
      q.pop();
    }
  }
}
