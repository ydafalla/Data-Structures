#include "BST.h"
#include<fstream>

int main(int argc,char** argv)
{
  if(argc<2)
  {
    cout<<"Please specify file name as an argument\n";
  }
  else
  {
    BST T1;
    unsigned int option=0;
    int x;
    node* temp;
    ifstream myfile;
    myfile.open(argv[1]);
    if(myfile.is_open())
    {
      myfile>>x;
      while(!myfile.eof())
      {
        T1.SetRoot(T1.Insert(T1.GetRoot(),x));
        myfile>>x;
      }
      while(option!=10)
      {
        cout<<"\n\nPlease choose one of the following commands:\n";
        cout<<"1- Insert \n"
            <<"2- DeleteMin\n"
            <<"3- DeleteMax\n"
            <<"4- Delete\n"
            <<"5- FindMin\n"
            <<"6- FindMax\n"
            <<"7- Preorder\n"
            <<"8- Inorder\n"
            <<"9- Postorder\n"
            <<"10- Exit\n"
            <<"Enter your choice: ";
          cin>>option;
          cout<<endl;
          switch(option)
          {
            case 1:
              cout<<"Please enter the number to insert: ";
              cin>>x;
              T1.SetRoot(T1.Insert(T1.GetRoot(),x));
              cout<<x<<" has been inserted\n\n";
              break;

            case 2:
              temp=T1.GetRoot();
              if(temp==NULL)
                cout<<"Tree is empty\n";
              else
                T1.SetRoot(T1.DeleteMin(T1.GetRoot()));
              break;

            case 3:
              temp=T1.GetRoot();
              if(temp==NULL)
                cout<<"Tree is empty\n";
              else
                T1.SetRoot(T1.DeleteMax(T1.GetRoot()));
              break;

            case 4:
              cout<<"Please enter the number to delete: ";
              cin>>x;
              temp=T1.Find(x,T1.GetRoot());
              if(temp==NULL)
                cout<<endl<<x<<" is not in the tree\n";
              else
              {
                T1.SetRoot(T1.Delete(x,T1.GetRoot()));
                cout<<endl<<x<<" has been deleted\n";
              }
              break;

            case 5:
              T1.FindMinimum(T1.GetRoot());
              break;

            case 6:
              T1.FindMax(T1.GetRoot());
              break;

            case 7:
              T1.Preorder(T1.GetRoot());
              break;

            case 8:
              T1.Inorder(T1.GetRoot());
              break;

            case 9:
              T1.Postorder(T1.GetRoot());
              break;

            case 10:
              break;

            default:
              break;

          }
      }

    }
    else
    {
      cout<<"couldn't open file \n";
    }




  }

  return 0;
}
