#include "TwoThreeTree.h"

TwoThreeTree::TwoThreeTree()
{
  root=NULL;
}


TwoThreeTree::~TwoThreeTree()
{
  Flush(root);
}

void TwoThreeTree::Flush(node* rt)
{
  node* temp=rt;
  if(temp==NULL)
  return ;
  else
  {
    Flush(temp->First);
    Flush(temp->Second);
    Flush(temp->Third);
    delete temp;
  }

}

node* TwoThreeTree::GetRoot()
{
  return root;
}

void TwoThreeTree::SetRoot(node* rt)
{
  root=rt;
}

node* TwoThreeTree::FindParent(int x,node* rt)
{
  node* temp=rt;
  if(temp->tag)
  return temp->Parent;
  else
  {
    if(x<temp->minSecond)
    return FindParent(x,temp->First);
    else
    {
      if(temp->minThird!=-1 && x>=temp->minThird)
      return FindParent(x,temp->Third);
      else
      return FindParent(x,temp->Second);
    }
  }
}

node* TwoThreeTree::FindNode(int x,node* rt)
{
  node* temp=rt;
  if(temp->tag)
  return temp;
  else
  {
    if(x<temp->minSecond)
    return FindNode(x,temp->First);
    else
    {
      if(temp->minThird!=-1 && x>=temp->minThird)
      return FindNode(x,temp->Third);
      else
      return FindNode(x,temp->Second);
    }
  }

}


bool TwoThreeTree::Search(int x,node* rt)
{
  node* temp=rt;
  if(temp==NULL)
  {
    return false;
  }
  if(temp->tag)
  return (x==temp->key);
  else
  {
    if(x<temp->minSecond)
    return Search(x,temp->First) ;
    else
    {
      if(temp->minThird!=-1 && x>=temp->minThird)
      return Search(x,temp->Third);
      else
      return Search(x,temp->Second);
    }
  }
}

int TwoThreeTree::Min(node* rt)
{
  node* temp=rt;
  if(temp==NULL)
  return -1;
  if(temp->tag)
  return temp->key;
  else
  return Min(temp->First);
}

int TwoThreeTree::Max(node* rt)
{
  node* temp=rt;
  if(temp==NULL)
  return -1;
  if(temp->tag)
  return temp->key;
  if(!(temp->Third))
  return Max(temp->Second);
  else
  return Max(temp->Third);
}


node* TwoThreeTree::Leaf(int x)
{
  node* newNode=new node;
  newNode->key=x;
  newNode->tag=true;
  newNode->minSecond=-1;
  newNode->minThird=-1;
  newNode->First=newNode->Second=newNode->Third=NULL;
  newNode->Parent=NULL;
  return newNode;
}

node* TwoThreeTree::Interior()
{
  node* newNode=new node;
  newNode->tag=false;
  newNode->key=-1;
  newNode->minSecond=-1;
  newNode->minThird=-1;
  newNode->First=newNode->Second=newNode->Third=NULL;
  newNode->Parent=NULL;
  return newNode;
}

void TwoThreeTree::Insert(int x,node* rt)
{
  node* temp=rt;
  if(temp==NULL)
  {
    node* newNode=Leaf(x);
    SetRoot(newNode);
    return ;
  }
  if(Search(x,temp))
  {
    cout<<x<<" is already in the tree\n";
    return ;
  }
  if(temp->tag==true)
  {
    node* newNode=Leaf(x);
    node* temp1=Interior();
    if(temp->key>x)
    {
      temp1->minSecond=temp->key;
      temp1->First=newNode;
      temp1->Second=temp;
    }
    else
    {
      temp1->minSecond=x;
      temp1->First=temp;
      temp1->Second=newNode;
    }
    newNode->Parent=temp1;
    temp->Parent=temp1;
    SetRoot(temp1);
    return ;
  }
  node* parent=FindParent(x,temp);
  //cout<<parent->First->key<<" "<<parent->Second->key<<" "<<parent->Third->key<<endl;
  //cout<<parent->First->key<<" "<<parent->minThird<<endl;
  if(parent->minThird==-1)
  {
    node* newNode=Leaf(x);
    newNode->Parent=parent;
    if(x<parent->First->key)
    {
      parent->Third=parent->Second;
      parent->Second=parent->First;
      parent->First=newNode;
      parent->minSecond=parent->Second->key;
      parent->minThird=parent->Third->key;
      return ;
    }
    else
    {
      if(x>parent->minSecond)
      {
        parent->Third=newNode;
        parent->minThird=parent->Third->key;
        return ;
      }
      else
      {
        parent->Third=parent->Second;
        parent->Second=newNode;
        parent->minSecond=parent->Second->key;
        parent->minThird=parent->Third->key;
        return ;
      }

    }

  }
  else
  {
    if(parent==GetRoot())
    {
      node* node1=Interior();
      node* node2=Interior();
      node* newRoot=Interior();
      node* newNode=Leaf(x);
      if(x<parent->minSecond)
      {
        if(x<parent->First->key)
        {
          node1->First=newNode;
          node1->Second=parent->First;
        }
        else
        {
          node1->First=parent->First;
          node1->Second=newNode;
        }
        node1->First->Parent=node1;
        node1->Second->Parent=node1;
        node1->minSecond=node1->Second->key;
        node2->First=parent->Second;
        node2->Second=parent->Third;
        node2->First->Parent=node2;
        node2->Second->Parent=node2;
        node2->minSecond=node2->Second->key;
        newRoot->First=node1;
        newRoot->Second=node2;
        newRoot->minSecond=node2->First->key;
        node1->Parent=newRoot;
        node2->Parent=newRoot;
        SetRoot(newRoot);
        delete parent;
        return ;
      }
      else
      {
        if(x>parent->minThird)
        {
          node2->First=parent->Third;
          node2->Second=newNode;
        }
        else
        {
          node2->First=newNode;
          node2->Second=parent->Third;
        }
        node2->First->Parent=node2;
        node2->Second->Parent=node2;
        node2->minSecond=node2->Second->key;
        node1->First=parent->First;
        node1->Second=parent->Second;
        node1->First->Parent=node1;
        node1->Second->Parent=node1;
        node1->minSecond=node1->Second->key;
        newRoot->First=node1;
        newRoot->Second=node2;
        newRoot->minSecond=node2->First->key;
        node1->Parent=newRoot;
        node2->Parent=newRoot;
        SetRoot(newRoot);
        delete parent;
        return ;
      }

    }
    else
    {
      node* node1=Interior();
      node* node2=Interior();
      node* newNode=Leaf(x);
      if(x<parent->minSecond)
      {
        if(x<parent->First->key)
        {
          node1->First=newNode;
          node1->Second=parent->First;
        }
        else
        {
          node1->First=parent->First;
          node1->Second=newNode;
        }
        node1->First->Parent=node1;
        node1->Second->Parent=node1;
        node1->minSecond=node1->Second->key;
        node2->First=parent->Second;
        node2->Second=parent->Third;
        node2->First->Parent=node2;
        node2->Second->Parent=node2;
        node2->minSecond=node2->Second->key;
      }
      else
      {
        if(x>parent->minThird)
        {
          node2->First=parent->Third;
          node2->Second=newNode;
        }
        else
        {
          node2->First=newNode;
          node2->Second=parent->Third;
        }
        node2->First->Parent=node2;
        node2->Second->Parent=node2;
        node2->minSecond=Min(node2->Second);
        node1->First=parent->First;
        node1->Second=parent->Second;
        node1->First->Parent=node1;
        node1->Second->Parent=node1;
        node1->minSecond=Min(node1->Second);
      }
      Attach(node1,node2,parent->Parent,parent);
      return ;

    }

  }

}

void TwoThreeTree::Attach(node* n1,node* n2,node* parent,node* splitnode)
{
  if(parent->minThird==-1)
  {
    if(n2->minSecond < parent->minSecond)
    {
      parent->First=n1;
      parent->Third=parent->Second;
      parent->Second=n2;
      n1->Parent=parent;
      n2->Parent=parent;
      parent->minSecond=Min(parent->Second);
      parent->minThird=Min(parent->Third);
    }
    else
    {
      parent->Second=n1;
      parent->Third=n2;
      n1->Parent=parent;
      n2->Parent=parent;
      parent->minSecond=Min(parent->Second);
      parent->minThird=Min(parent->Third);
    }
    delete splitnode;
  }
  else
  {
    if(parent==GetRoot())
    {
      node* node1=Interior();
      node* node2=Interior();
      node* newRoot=Interior();
      if(n2->minSecond < parent->minSecond)
      {
        node1->First=n1;
        node1->Second=n2;
        node1->First->Parent=node1;
        node1->Second->Parent=node1;
        node2->First=parent->Second;
        node2->Second=parent->Third;
        node2->First->Parent=node2;
        node2->Second->Parent=node2;
      }
      else
      {
        if(n1->minSecond > parent->minThird)
        {
          node1->First=parent->First;
          node1->Second=parent->Second;
          node1->First->Parent=node1;
          node1->Second->Parent=node1;
          node2->First=n1;
          node2->Second=n2;
          node2->First->Parent=node2;
          node2->Second->Parent=node2;
        }
        else
        {
          node1->First=parent->First;
          node1->Second=n1;
          node1->First->Parent=node1;
          node1->Second->Parent=node1;
          node2->First=n2;
          node2->Second=parent->Third;
          node2->First->Parent=node2;
          node2->Second->Parent=node2;
        }
      }
      node1->minSecond=Min(node1->Second);
      node2->minSecond=Min(node2->Second);
      node1->Parent=newRoot;
      node2->Parent=newRoot;
      newRoot->First=node1;
      newRoot->Second=node2;
      newRoot->minSecond=Min(newRoot->Second);
      SetRoot(newRoot);
      delete parent;
      delete splitnode;
    }
    else
    {
      node* node1=Interior();
      node* node2=Interior();
      if(parent->minSecond==Min(splitnode))
      {
        node1->First=parent->First;
        node1->Second=n1;
        node1->First->Parent=node1;
        node1->Second->Parent=node1;
        node2->First=n2;
        node2->Second=parent->Third;
        node2->First->Parent=node2;
        node2->Second->Parent=node2;

      }
      else
      {
        if(parent->minThird==Min(splitnode))
        {
          node1->First=parent->First;
          node1->Second=parent->Second;
          node1->First->Parent=node1;
          node1->Second->Parent=node1;
          node2->First=n1;
          node2->Second=n2;
          node2->First->Parent=node2;
          node2->Second->Parent=node2;
        }
        else
        {
          node1->First=n1;
          node1->Second=n2;
          node1->First->Parent=node1;
          node1->Second->Parent=node1;
          node2->First=parent->Second;
          node2->Second=parent->Third;
          node2->First->Parent=node2;
          node2->Second->Parent=node2;
        }
      }
      node1->minSecond=Min(node1->Second);
      node2->minSecond=Min(node2->Second);
      Attach(node1,node2,parent->Parent,parent);
      delete splitnode;

    }


  }
}

void TwoThreeTree::Delete(int x,node* rt)
{
  node* temp=rt;
  if(temp==NULL)
  {
    cout<<"Tree is empty\n";
    return ;
  }
  if(!(Search(x,temp)))
  {
    cout<<x<<" is not in the tree\n";
    return ;
  }
  if(temp->tag)
  {
    delete temp;
    SetRoot(NULL);
    return ;
  }
  node* parent=FindParent(x,temp);
  node* cnode=FindNode(x,temp);
  if(parent->minThird!=-1)
  {
    if(parent->minSecond==x)
    {
      delete parent->Second;
      parent->Second=parent->Third;
      parent->Third=NULL;
    }

    else
    {
      if(parent->minThird==x)
      {
        delete parent->Third;
        parent->Third=NULL;
      }

      else
      {
        delete parent->First;
        parent->First=parent->Second;
        parent->Second=parent->Third;
        parent->Third=NULL;
      }
    }
    parent->minSecond=Min(parent->Second);
    parent->minThird=Min(parent->Third);
    Update(parent->Parent);
    return ;
  }
  else
  {
    if(parent==GetRoot())
    {
      if(cnode==parent->First)
      {
        SetRoot(parent->Second);
        delete cnode;
        delete parent;
        return ;
      }
      else
      {
        SetRoot(parent->First);
        delete cnode;
        delete parent;
        return ;
      }

    }
    else
    {
      node* gparent=parent->Parent;
      if(parent==gparent->First)
      {
        node* snode=gparent->Second;
        if(snode->minThird!=-1)
        {
          if(cnode==parent->First)
          {
            parent->First=parent->Second;
          }
          parent->Second=snode->First;
          snode->First=snode->Second;
          snode->Second=snode->Third;
          snode->Third=NULL;
          parent->First->Parent=parent;
          parent->Second->Parent=parent;
          snode->First->Parent=snode;
          snode->Second->Parent=snode;
          snode->minSecond=Min(snode->Second);
          snode->minThird=Min(snode->Third);
          parent->minSecond=Min(parent->Second);
          parent->minThird=Min(parent->Third);
          delete cnode;
          Update(gparent);
          return ;
        }
        else
        {
          snode->Third=snode->Second;
          snode->Second=snode->First;
          if(cnode==parent->First)
          {
            snode->First=parent->Second;
          }
          else
          {
            snode->First=parent->First;
          }
          snode->First->Parent=snode;
          snode->minSecond=Min(snode->Second);
          snode->minThird=Min(snode->Third);
          parent->First=parent->Second=NULL;
          delete cnode;
          DeleteNode(parent,gparent);
        }
      }

      else
      {
        if(parent==gparent->Second)
        {
          node* snode=gparent->First;
          if(snode->minThird!=-1)
          {
            if(cnode==parent->First)
            {
              parent->First=snode->Third;
            }
            else
            {
              parent->Second=parent->First;
              parent->First=snode->Third;
            }
            snode->Third=NULL;
            parent->First->Parent=parent;
            parent->Second->Parent=parent;
            snode->First->Parent=snode;
            snode->Second->Parent=snode;
            snode->minSecond=Min(snode->Second);
            snode->minThird=Min(snode->Third);
            parent->minSecond=Min(parent->Second);
            parent->minThird=Min(parent->Third);
            delete cnode;
            Update(gparent);
            return ;
          }
          else
          {
            node* ssnode=gparent->Third;
            if(ssnode==NULL || ssnode->minThird==-1)
            {
              if(cnode==parent->First)
              {
                snode->Third=parent->Second;
              }
              else
              {
                snode->Third=parent->First;
              }
              snode->Third->Parent=snode;
              snode->minSecond=Min(snode->Second);
              snode->minThird=Min(snode->Third);
              parent->First=parent->Second=NULL;
              delete cnode;
              DeleteNode(parent,gparent);
            }
            else
            {
              if(cnode==parent->First)
              {
                parent->First=parent->Second;
              }
              parent->Second=ssnode->First;
              ssnode->First=ssnode->Second;
              ssnode->Second=ssnode->Third;
              ssnode->Third=NULL;
              parent->Second->Parent=parent;
              ssnode->minSecond=Min(ssnode->Second);
              ssnode->minThird=Min(ssnode->Third);
              parent->minSecond=Min(parent->Second);
              parent->minThird=Min(parent->Third);
              Update(gparent);
              delete cnode;
            }
          }
        }
        else
        {
          node* snode=gparent->Second;
          if(snode->minThird!=-1)
          {
            if(cnode==parent->First)
            {
              parent->First=snode->Third;
            }
            else
            {
              parent->Second=parent->First;
              parent->First=snode->Third;
            }
            snode->Third=NULL;
            parent->First->Parent=parent;
            parent->Second->Parent=parent;
            snode->First->Parent=snode;
            snode->Second->Parent=snode;
            snode->minSecond=Min(snode->Second);
            snode->minThird=Min(snode->Third);
            parent->minSecond=Min(parent->Second);
            parent->minThird=Min(parent->Third);
            delete cnode;
            Update(gparent);
            return ;
          }
          else
          {
            if(cnode==parent->First)
            {
              snode->Third=parent->Second;
            }
            else
            {
              snode->Third=parent->First;
            }
            snode->Third->Parent=snode;
            snode->minSecond=Min(snode->Second);
            snode->minThird=Min(snode->Third);
            parent->First=parent->Second=NULL;
            delete cnode;
            DeleteNode(parent,gparent);
          }
        }

      }

    }

  }
}


void TwoThreeTree::DeleteNode(node* parent,node* gparent)
{
  if(gparent->minThird!=-1)
  {
    if(parent==gparent->First)
    {
      gparent->First=gparent->Second;
      gparent->Second=gparent->Third;
    }
    else
    {
      if(parent==gparent->Second)
      {
        gparent->Second=gparent->Third;
      }

    }
    gparent->Third=NULL;
    Update(gparent);
    delete parent;
    return ;
  }
  else
  {
    if(gparent==GetRoot())
    {
      if(parent==gparent->First)
      {
        SetRoot(gparent->Second);
      }
      else
      {
        SetRoot(gparent->First);
      }
      root->Parent=NULL;
      Update(GetRoot());
      delete parent;
      delete gparent;
      return ;
    }
    else
    {
      node* ggparent=gparent->Parent;
      if(gparent==ggparent->First)
      {
        node* snode=ggparent->Second;
        {
          if(snode->minThird!=-1)
          {
            if(parent==gparent->First)
            {
              gparent->First=gparent->Second;
            }
            gparent->Second=snode->First;
            snode->First=snode->Second;
            snode->Second=snode->Third;
            snode->Third=NULL;
            gparent->First->Parent=gparent;
            gparent->Second->Parent=gparent;
            snode->First->Parent=snode;
            snode->Second->Parent=snode;
            snode->minSecond=Min(snode->Second);
            snode->minThird=Min(snode->Third);
            gparent->minSecond=Min(gparent->Second);
            gparent->minThird=Min(gparent->Third);
            delete parent;
            Update(ggparent);
            return ;
          }
          else
          {
            snode->Third=snode->Second;
            snode->Second=snode->First;
            if(parent==gparent->First)
            {
              snode->First=gparent->Second;
            }
            else
            {
              snode->First=gparent->First;
            }
            snode->First->Parent=snode;
            snode->minSecond=Min(snode->Second);
            snode->minThird=Min(snode->Third);
            delete parent;
            DeleteNode(gparent,ggparent);
          }
        }
      }
      else
      {
        if(gparent==ggparent->Second)
        {
          node* snode=ggparent->First;
          {
            if(snode->minThird!=-1)
            {
              if(parent==gparent->First)
              {
                gparent->First=snode->Third;
              }
              else
              {
                gparent->Second=gparent->First;
                gparent->First=snode->Third;
              }
              snode->Third=NULL;
              gparent->First->Parent=gparent;
              gparent->Second->Parent=gparent;
              snode->First->Parent=snode;
              snode->Second->Parent=snode;
              snode->minSecond=Min(snode->Second);
              snode->minThird=Min(snode->Third);
              gparent->minSecond=Min(gparent->Second);
              gparent->minThird=Min(gparent->Third);
              delete parent;
              Update(ggparent);
              return ;
            }
            else
            {
              node* ssnode=ggparent->Third;
              if(ssnode==NULL || ssnode->minThird==-1)
              {
                if(parent==gparent->First)
                {
                  snode->Third=gparent->Second;
                }
                else
                {
                  snode->Third=gparent->First;
                }
                snode->Third->Parent=snode;
                gparent->First=gparent->Second=NULL;
                snode->minSecond=Min(snode->Second);
                snode->minThird=Min(snode->Third);
                delete parent;
                DeleteNode(gparent,ggparent);
              }
              else
              {
                if(parent==gparent->First)
                {
                  gparent->First=gparent->Second;
                }
                gparent->Second=ssnode->First;
                gparent->Second->Parent=gparent;
                ssnode->First=ssnode->Second;
                ssnode->Second=ssnode->Third;
                ssnode->Third=NULL;
                ssnode->minSecond=Min(ssnode->Second);
                ssnode->minThird=Min(ssnode->Third);
                gparent->minSecond=Min(gparent->Second);
                gparent->minThird=Min(gparent->Third);
                delete parent;
                Update(ggparent);
                return ;
              }

            }

          }
        }
        else
        {
          node* snode=ggparent->Second;
          if(snode->minThird!=-1)
          {
            if(parent==gparent->First)
            {
              gparent->First=snode->Third;
            }
            else
            {
              gparent->Second=gparent->First;
              gparent->First=snode->Third;
            }
            snode->Third=NULL;
            gparent->First->Parent=gparent;
            gparent->Second->Parent=gparent;
            snode->First->Parent=snode;
            snode->Second->Parent=snode;
            snode->minSecond=Min(snode->Second);
            snode->minThird=Min(snode->Third);
            gparent->minSecond=Min(gparent->Second);
            gparent->minThird=Min(gparent->Third);
            delete parent;
            Update(ggparent);
            return ;
          }
          else
          {
            if(parent==gparent->First)
            {
              snode->Third=gparent->Second;
            }
            else
            {
              snode->Third=gparent->First;
            }
            snode->Third->Parent=snode;
            snode->minSecond=Min(snode->Second);
            snode->minThird=Min(snode->Third);
            delete parent;
            DeleteNode(gparent,ggparent);
          }
        }
      }

    }
  }
}

void TwoThreeTree::DeleteMin(node* rt)
{
  node* temp=rt;
  if(temp==NULL)
  {
    cout<<"Can't delete from empty tree\n";
    return ;
  }
  int x=Min(temp);
  Delete(x,temp);
  cout<<x<<" has been deleted from the tree\n";
  return ;
}

void TwoThreeTree::DeleteMax(node* rt)
{
  node* temp=rt;
  if(temp==NULL)
  {
    cout<<"Can't delete from empty tree\n";
    return ;
  }
  int x=Max(temp);
  Delete(x,temp);
  cout<<x<<" has been deleted from the tree\n";
  return ;
}

void TwoThreeTree::Update(node* rt)
{
  node* temp=rt;
  if(temp==NULL)
  return ;
  temp->minSecond=Min(temp->Second);
  temp->minThird=Min(temp->Third);
  Update(temp->Parent);
}

void TwoThreeTree::LevelOrder(node* rt)
{
  node* temp=rt;
  if(temp==NULL)
  return ;
  if(temp->tag)
  {
    cout<<temp->key<<" ";
    return ;
  }
  LevelOrder(temp->First);
  LevelOrder(temp->Second);
  LevelOrder(temp->Third);
  cout<<"|";
}
