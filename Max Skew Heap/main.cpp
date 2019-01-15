#include "SkewHeap.h"

int main()
{
  SkewHeap H1;
  H1.Buildheap();
  int option=0;
  while(option!=8)
  {
    cout<<"\nPlease Choose one of the following commands: \n"
        <<"1- Insert\n"
        <<"2- DeleteMax\n"
        <<"3- FindMax\n"
        <<"4- PreOrder\n"
        <<"5- InOrder\n"
        <<"6- PostOrder\n"
        <<"7- LevelOrder\n"
        <<"8- Exit\n"
        <<"Enter you choice here: ";
        cin>>option;
        switch(option)
        {
          case 1:
            int x;
            cout<<"Enter the number to insert: ";
            cin>>x;
            H1.Insert(x);
            cout<<x<<" instered successfully\n";
            break;

          case 2:
            H1.DeleteMax(H1.GetRoot());
            break;

          case 3:
            H1.FindMax();
            break;

          case 4:
            H1.PreOrder(H1.GetRoot());
            break;

          case 5:
            H1.InOrder(H1.GetRoot());
            break;

          case 6:
            H1.PostOrder(H1.GetRoot());
            break;

          case 7:
            H1.LevelOrder(H1.GetRoot());
            break;

          default:
            break;
          }
  }
  return 0;
}
