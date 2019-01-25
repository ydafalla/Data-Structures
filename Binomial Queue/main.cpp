#include "BQ.h"
#include <fstream>
int main()
{
  BQ Q1;
  int x;
  unsigned int option=0;
  ifstream myfile;
  myfile.open("data.txt");
  if(myfile.is_open())
  {
    myfile>>x;
    while(!myfile.eof())
    {
      Q1.Insert(Q1.GetRoot(),x);
      myfile>>x;
    }
    while(option!=5)
    {
      cout<<"Please choose one of the following commands: \n"
          <<"1- Insert\n"
          <<"2- DeleteMin\n"
          <<"3- FindMin\n"
          <<"4- Print\n"
          <<"5- Exit\n"
          <<"Enter your choice: ";
        cin>>option;
        switch(option)
        {
          case 1:
          cout<<"Enter a number to be inserted: ";
          cin>>x;
          Q1.Insert(Q1.GetRoot(),x);
          cout<<"Insert successful\n";
          break;

          case 2:
          Q1.DeleteMin(Q1.GetRoot());
          cout<<"Delete Successful\n";
          break;

          case 3:
          int y;
          y=Q1.FindMin(Q1.GetRoot());
          if(y!=0)
          cout<<"The minimum element in the Queue is: "<<y<<endl;
          break;

          case 4:
          Q1.Print(Q1.GetRoot());
          break;

          case 5:
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
