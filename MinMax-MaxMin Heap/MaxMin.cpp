#include "MaxMin.h"

MaxMin::MaxMin()
{
  last=0;
}

MaxMin::~MaxMin()
{

}

void MaxMin::Insert(int x)
{
  if(last==0)
  {
    array[++last]=x;
    return ;
  }
  int parent=((last+1))/2;
  if(x==array[parent])
  {
    array[++last]=x;
    return ;
  }
  if(x<array[parent])
  {
    array[++last]=x;
    if(minNode(parent))
    {
      unsigned int i=parent;
      unsigned int j=last;
      while(i>=1)
      {
        if(array[j]<array[i])
        {
          int temp;
          temp=array[i];
          array[i]=array[j];
          array[j]=temp;
        }
        else
        {
          break;
        }
        i=i/4;
        if(j==last)
          j=j/2;
        else
          j=j/4;
      }
    }
    else
    {
      unsigned int i=parent/2;
      unsigned int j=last;
      while(i>=1)
      {
        if(array[j]<array[i])
        {
          int temp;
          temp=array[i];
          array[i]=array[j];
          array[j]=temp;
        }
        else
        {
          break;
        }
        i=i/4;
        j=j/4;
      }

    }


  }
  if(x>array[parent])
  {
    array[++last]=x;
    if(minNode(parent))
    {
      unsigned int i=parent/2;
      unsigned int j=last;
      while(i>=1)
      {
        if(array[j]>array[i])
        {
          int temp;
          temp=array[i];
          array[i]=array[j];
          array[j]=temp;
        }
        else
        {
          break;
        }
        i=i/4;
        j=j/4;
      }

    }
    else
    {
      unsigned int i=parent;
      unsigned int j=last;
      while(i>=1)
      {
        if(array[j]>array[i])
        {
          int temp;
          temp=array[i];
          array[i]=array[j];
          array[j]=temp;
        }
        else
        {
          break;
        }
        i=i/4;
        if(j==last)
        j=j/2;
        else
        j=j/4;
      }

    }
  }

}

bool MaxMin::minNode(int loc)
{
  if(loc<=0)
  return false;
  else
  {
    int n=log2(loc);
    if(n%2==0)
    return false;
    else
    return true;
  }
}

void MaxMin::FindMax()
{
  if(last>0)
  cout<<"The maximum value in the tree is: "<<array[1]<<endl;
  else
  cout<<"Tree is empty\n";
}

void MaxMin::FindMin()
{
  if(last==0)
  {
    cout<<"Tree is empty\n";
    return ;
  }
  if(last==1)
  {
    cout<<"The minimum value in the tree is: "<<array[1]<<endl;
    return ;
  }
  if(last==2)
  {
    cout<<"The minimum value in the tree is: "<<array[2]<<endl;
    return ;
  }
  else
  {
    if(array[2]<=array[3])
    cout<<"The minimum value in the tree is: "<<array[2]<<endl;
    else
    cout<<"The minimum value in the tree is: "<<array[3]<<endl;
  }
}

void MaxMin::DeleteMax()
{
  if(last==0)
  {
    cout<<"Tree is empty\n";
    return ;
  }
  if(last==1)
  {
    cout<<array[1]<<" has been deleted\n";
    last--;
    return ;
  }
  if(last==2)
  {
    cout<<array[1]<<" has been deleted\n";
    array[1]=array[2];
    last--;
    return ;
  }
  if(last==3)
  {
    cout<<array[1]<<" has been deleted\n";
    array[1]=array[last];
    last--;
    if(array[2]>array[1])
    Swap(1,2);
    return ;
  }
  cout<<array[1]<<" has been deleted\n";
  int index=SecondMax(1);
  int s=array[index];
  int x=array[last];
  if(x>=s)
  {
    Swap(1,last);
    last--;
    return ;
  }
  else
  {
    Swap(1,index);
    Swap(index,last);
    last--;
    PatchMax(index);
  }
}

void MaxMin::Patch(int index)
{
  int i=index;
  if(array[i]>array[i/2] && minNode(i)==true)
  Swap(index,index/2);
  if(2*i > last)
  return ;
  if (4*i > last)
  {
    int j=2*i;
    int min=array[j],result=j,k=j+1;
    for(k;k<=j+1 && k<=last;k++)
    {
      if(array[k]<min)
      {
        min=array[k];
        result=k;
      }
    }
    if(array[i]<=array[result])
    {
      return ;
    }
    else
    {
      Swap(i,result);
      return ;
    }
  }
  if(4*i+2>last)
  {
    int j=2*i+1;
    int min=array[j],result=j,k=4*i;
    for(k;k<=4*i+3 && k<=last;k++)
    {
      if(array[k]<min)
      {
        min=array[k];
        result=k;
      }
    }
    if(array[i]<=array[result])
    {
      return ;
    }
    else
    {
      Swap(i,result);
      Patch(result);
      return ;
    }

  }
  int j=4*i;
  int min=array[j],result=j,k=j+1;
  for(k;k<=j+3 && k<=last;k++)
  {
    if(array[k]<min)
    {
      min=array[k];
      result=k;
    }
  }
  if(array[i]<=array[result])
  {
    return ;
  }
  else
  {
    Swap(i,result);
    Patch(result);
    return ;
  }

}


void MaxMin::DeleteMin()
{
  if(last==0)
  {
    cout<<"Tree is empty\n";
    return ;
  }
  if(last==1)
  {
    cout<<array[1]<<" has been deleted\n";
    last--;
    return ;
  }
  if(last==2)
  {
    cout<<array[2]<<" has been deleted\n";
    last--;
    return ;
  }
  if(last==3)
  {
    if(array[2]<array[3])
    {
      cout<<array[2]<<" has been deleted\n";
      array[2]=array[3];
    }
    else
    {
      cout<<array[3]<<" has been deleted\n";
    }
    last--;
    return ;
  }
  int min_index;
  if(array[2]<array[3])
  min_index=2;
  else
  min_index=3;
  cout<<array[min_index]<<" has been deleted\n";
  int index=SecondMin(min_index);
  int s=array[index];
  int x=array[last];
  if(x<=s)
  {
    Swap(min_index,last);
    last--;
    return ;
  }
  else
  {
    Swap(min_index,index);
    Swap(index,last);
    last--;
    Patch(index);
  }
}

void MaxMin::PatchMax(int index)
{
  int i=index;
  if(array[i]<array[i/2] && minNode(i)==false)
  Swap(index,index/2);
  if(2*i > last)
  return ;
  if (4*i > last)
  {
    int j=2*i;
    if(j+1<=last)
    {
      if(array[j]>array[j+1])
      {
        if(array[i]>array[j])
        return;
        else
        Swap(i,j);
      }
      else
      {
        if(array[i]>array[j+1])
        return;
        else
        Swap(i,j+1);
      }
    }
    else
    {
      if(array[i]>array[j])
      return ;
      else
      Swap(i,j);
    }
  }
  if(4*i+2>last)
  {
    int j=2*i+1;
    int max=array[j],result=j,k=4*i;
    for(k;k<=4*i+3 && k<=last;k++)
    {
      if(array[k]>max)
      {
        max=array[k];
        result=k;
      }
    }
    if(array[i]>=array[result])
    {
      return ;
    }
    else
    {
      Swap(i,result);
      PatchMax(result);
      return ;
    }
  }
  int j=4*i;
  int max=array[j],result=j,k=j+1;
  for(k;k<=j+3 && k<=last;k++)
  {
    if(array[k]>max)
    {
      max=array[k];
      result=k;
    }
  }
  if(array[i]>=array[result])
  {
    return ;
  }
  else
  {
    Swap(i,result);
    PatchMax(result);
    return ;
  }/* code */

}


int MaxMin::SecondMax(int index)
{
  if(2*index>last)
  {
    return index;
  }
  if(4*index>last)
  {
    unsigned int i=2*index,result=i;
    int max=array[i],k=i+1;
    for(k;k<=i+1 && k<=last;k++)
    {
      if(array[k]>max)
      {
        max=array[k];
        result=k;
      }
    }
    return result;
  }
  if(4*index+2>last)
  {
    unsigned int i=2*index+1,result=2*index+1;
    int max=array[result];
    for(i=4*index;i<=(4*index+3) && i<=last; i++)
    {
      if(array[i]>max)
      {
        max=array[i];
        result=i;
      }
    }
    return result;
  }
  unsigned int i=4*index,result=4*index;
  int max=array[result];
  for(i;i<=(4*index+3) && i<=last; i++)
  {
    if(array[i]>max)
    {
      max=array[i];
      result=i;
    }
  }
  return result;
}


int MaxMin::SecondMin(int index)
{
  if(2*index>last)
  {
    return index;
  }
  if(4*index>last)
  {
    unsigned int i=2*index,result=i;
    int min=array[i],k=i+1;
    for(k;k<=i+1 && k<=last;k++)
    {
      if(array[k]<min)
      {
        min=array[k];
        result=k;
      }
    }
    return result;
  }
  if(4*index+2>last)
  {
    unsigned int i=2*index+1,result=2*index+1;
    int min=array[result];
    for(i=4*index;i<=(4*index+3) && i<=last; i++)
    {
      if(array[i]<min)
      {
        min=array[i];
        result=i;
      }
    }
    return result;
  }
  unsigned int i=4*index,result=4*index;
  int min=array[result];
  for(i;i<=(4*index+3) && i<=last; i++)
  {
    if(array[i]<min)
    {
      min=array[i];
      result=i;
    }
  }
  return result;

}

void MaxMin::Swap(unsigned int a,unsigned int b)
{
  int temp=array[a];
  array[a]=array[b];
  array[b]=temp;
}

void MaxMin::LevelOrder()
{
  if(last==0)
  {
    cout<<"Tree is empty\n";
    return ;
  }
  unsigned int i;
  for(i=1;i<=last;i++)
  {
    if(i%2==0 && i!=2)
    {
      if(PowerOfTwo(i))
      cout<<endl;
      else
      cout<<"- ";
    }
    cout<<array[i]<<" ";
    if(i==1)
    cout<<endl;
  }
  cout<<endl;
}


bool MaxMin::PowerOfTwo(unsigned int x)
{
  return x && !(x & (x-1));
}
