#include "MinMax.h"
#include "MaxMin.h"

int main(int argc,char* argv[])
{
  if(argc<2)
  {
    cout<<"To run the lab Type ./output (minmax or maxmin)\n";
    return 0;
  }
  else
  {
    if(string(argv[1])=="minmax")
    {
      MinMax heap;
      heap.Buildheap();
      int x;
      int option=0;
      while(option!=7)
       {
          cout<<"Please choose one of the following commands:\n"
              <<"1- Insert\n"
              <<"2- deleteMin\n"
              <<"3- findMin\n"
              <<"4- findMax\n"
              <<"5- deleteMax\n"
              <<"6- levelOrder\n"
              <<"7- exit\n"
              <<"Enter your option here: ";
          cin>>option;
          switch(option)
          {
            case 1:
              cout<<"Enter the number to insert: ";
              cin>>x;
              heap.Insert(x);
              cout<<x<<" was inserted to the heap\n";
              break;

            case 2:
              heap.DeleteMin();
              break;

            case 3:
              heap.FindMin();
              break;

            case 4:
              heap.FindMax();
              break;

            case 5:
              heap.DeleteMax();
              break;

            case 6:
              heap.LevelOrder();
              break;

            default:
              break;
          }
        }
      }
      else
      {
        if(string(argv[1])=="maxmin")
        {
          MaxMin heap;
          ifstream myfile;
          int x;
          myfile.open("data.txt");
          if(myfile.is_open())
          {
            myfile>>x;
            while(!myfile.eof())
            {
              heap.Insert(x);
              myfile>>x;
            }
          }
          int option=0;
          while(option!=7)
           {
              cout<<"Please choose one of the following commands:\n"
                  <<"1- Insert\n"
                  <<"2- deleteMin\n"
                  <<"3- findMin\n"
                  <<"4- findMax\n"
                  <<"5- deleteMax\n"
                  <<"6- levelOrder\n"
                  <<"7- exit\n"
                  <<"Enter your option here: ";
              cin>>option;
              switch(option)
              {
                case 1:
                  cout<<"Enter the number to insert: ";
                  cin>>x;
                  heap.Insert(x);
                  cout<<x<<" was inserted to the heap\n";
                  break;

                case 2:
                  heap.DeleteMin();
                  break;

                case 3:
                  heap.FindMin();
                  break;

                case 4:
                  heap.FindMax();
                  break;

                case 5:
                  heap.DeleteMax();
                  break;

                case 6:
                  heap.LevelOrder();
                  break;

                default:
                  break;
              }
            }
        }
      }
    }

  return 0;
}
