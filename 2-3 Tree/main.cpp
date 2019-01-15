#include  "TwoThreeTree.h"
#include <fstream>
int main()
{
  TwoThreeTree T1;
  int x;
  bool check;
  unsigned int option=0;
  ifstream myfile;
  myfile.open("data.txt");
  if(myfile.is_open())
  {
    myfile>>x;
    while(!myfile.eof())
    {
      T1.Insert(x,T1.GetRoot());
      myfile>>x;
    }
    while(option!=9)
    {
      cout<<"Please choose one of the following commands: \n"
          <<"1- Insert\n"
          <<"2- Delete Min\n"
          <<"3- Delete Max\n"
          <<"4- FindMin\n"
          <<"5- FindMax\n"
          <<"6- Find\n"
          <<"7- Delete\n"
          <<"8- Level Order\n"
          <<"9- Exit\n"
          <<"Enter your choice: ";
        cin>>option;
        switch(option)
        {
          case 1:
          cout<<"Enter a number to be inserted: ";
          cin>>x;
          T1.Insert(x,T1.GetRoot());
          break;

          case 2:
          T1.DeleteMin(T1.GetRoot());
          break;

          case 3:
          T1.DeleteMax(T1.GetRoot());
          break;

          case 4:
          if((T1.Min(T1.GetRoot()))==-1)
          cout<<"Tree is empty\n";
          else
          cout<<"The minimun number in the tree is: "<<T1.Min(T1.GetRoot())<<endl;
          break;

          case 5:
          if((T1.Max(T1.GetRoot()))==-1)
          cout<<"Tree is empty\n";
          else
          cout<<"The maximun number in the tree is: "<<T1.Max(T1.GetRoot())<<endl;
          break;


          case 6:
          cout<<"Enter the number to be found: ";
          cin>>x;
          if(T1.Search(x,T1.GetRoot()))
          cout<<x<<" is found in the tree\n";
          else
          cout<<x<<" is not in the tree\n";
          break;

          case 7:
          cout<<"Enter the number to be deleted: ";
          cin>>x;
          check=T1.Search(x,T1.GetRoot());
          T1.Delete(x,T1.GetRoot());
          if(check)
          cout<<x<<" has been deleted from tree\n";
          break;

          case 8:
          T1.LevelOrder(T1.GetRoot());
          cout<<endl;
          break;

          case 9:
          cout<<"bye bye\n";
          break;

          default:
          break;
        }
    }
  }
  else
  {
    cout<<"Couldn't open file\n";
  }
  return 0;
}
