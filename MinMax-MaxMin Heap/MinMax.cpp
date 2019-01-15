#include "MinMax.h"

MinMax::MinMax()
{
  last=0;
}

MinMax::~MinMax()
{

}


void MinMax::Buildheap()
{
  int x;
  ifstream myfile;
  myfile.open("data.txt");
  if(myfile.is_open())
  {
    myfile>>x;
    while(!myfile.eof())
    {
      array[++last]=x;
      myfile>>x;
    }
  }
  x=last/2;
  for(x;x>=1;x--)
  {
    if(minNode(x))
    {
      Patch1(x);
    }
    else
    {
      Patch2(x);
    }
  }
}

void MinMax::Patch1(int index)
{
  int i=index;
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
      if(array[result]>array[result/2])
      Swap(result,result/2);
      Patch1(result);
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
    if(array[result]>array[result/2])
    Swap(result,result/2);
    Patch1(result);
    return ;
  }
}

void MinMax::Patch2(int index)
{
  int i=index;
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
      if(array[result]<array[result/2])
      Swap(result,result/2);
      Patch2(result);
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
    if(array[result]<array[result/2])
    Swap(result,result/2);
    Patch2(result);
    return ;
  }

}

void MinMax::Insert(int x)
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

bool MinMax::minNode(int loc)
{
  if(loc<=0)
  return false;
  else
  {
    int n=log2(loc);
    if(n%2==0)
    return true;
    else
    return false;
  }
}

void MinMax::FindMin()
{
  if(last>0)
  cout<<"The minimum value in the tree is: "<<array[1]<<endl;
  else
  cout<<"Tree is empty\n";
}

void MinMax::FindMax()
{
  if(last==0)
  {
    cout<<"Tree is empty\n";
    return ;
  }
  if(last==1)
  {
    cout<<"The maximum value in the tree is: "<<array[1]<<endl;
    return ;
  }
  if(last==2)
  {
    cout<<"The maximum value in the tree is: "<<array[2]<<endl;
    return ;
  }
  else
  {
    if(array[2]>=array[3])
    cout<<"The maximum value in the tree is: "<<array[2]<<endl;
    else
    cout<<"The maximum value in the tree is: "<<array[3]<<endl;
  }
}

void MinMax::DeleteMin()
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
    if(array[2]<array[1])
    Swap(1,2);
    return ;
  }
  cout<<array[1]<<" has been deleted\n";
  int index=SecondMin();
  int s=array[index];
  int x=array[last];
  if(x<=s)
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
    Patch(index);
  }

}

void MinMax::Patch(int index)
{
  int i=index;
  if((i!=1) && array[i]>array[i/2] && minNode(i)==true)
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


void MinMax::DeleteMax()
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
    if(array[2]>array[3])
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
  int max_index;
  if(array[2]>array[3])
  max_index=2;
  else
  max_index=3;
  cout<<array[max_index]<<" has been deleted\n";
  int index=SecondMax(max_index);
  int s=array[index];
  int x=array[last];
  if(x>=s)
  {
    Swap(max_index,last);
    last--;
    return ;
  }
  else
  {
    Swap(max_index,index);
    Swap(index,last);
    last--;
    PatchMax(index);
  }
}

void MinMax::PatchMax(int index)
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
  }

}


int MinMax::SecondMax(int index)
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


int MinMax::SecondMin()
{
  if(last>5)
  {
    unsigned int i=4,result=4;
    int min=array[4];
    for(i;i<=7 && i<=last; i++)
    {
      if(array[i]<min)
      {
        min=array[i];
        result=i;
      }
    }
    return result;
  }
  else
  {
    unsigned int i=3,result=3;
    int min=array[3];
    for(i=4;i<=7 && i<=last; i++)
    {
      if(array[i]<min)
      {
        min=array[i];
        result=i;
      }
    }
    return result;
  }

}

void MinMax::Swap(unsigned int a,unsigned int b)
{
  int temp=array[a];
  array[a]=array[b];
  array[b]=temp;
}

void MinMax::LevelOrder()
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


bool MinMax::PowerOfTwo(unsigned int x)
{
  return x && !(x & (x-1));
}
