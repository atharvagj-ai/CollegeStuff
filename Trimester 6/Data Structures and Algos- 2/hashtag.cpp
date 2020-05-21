#include<iostream>
#include<string>
#define max 20
using namespace std;

class student
{
public:
  int rollno;
  string name;
  char grade;

  student()
  {
      rollno=-1;
      name="---";
      grade='&';
  }
};
class hashing
{
  student hash_table[max];
public:
  void display()
  {
    for(int i=0;i<max;i++)
    {
      cout<<hash_table[i].rollno<<"\t"<<hash_table[i].name<<"\t"<<hash_table[i].grade<<endl;
    }
  }
  void lin_probing_Repl()
  {
    student ob,temp;char ch;
    do{
       display();
       int flag=0;
       cout<<"Enter roll number, name, and grade:\n";
       cin>>ob.rollno;
       cin.ignore();
       getline(cin,ob.name);
       cin>>ob.grade;

       int loc = ob.rollno%max;

       if(hash_table[loc].rollno==-1)
       {
         hash_table[loc].rollno=ob.rollno;
         hash_table[loc].name=ob.name;
         hash_table[loc].grade=ob.grade;
       }

       else
       {
         int newloc=hash_table[loc].rollno%max;
         temp.rollno=ob.rollno;
         temp.name=ob.name;
         temp.grade=ob.grade;

         if(loc!=newloc)
         {
           temp.rollno=hash_table[loc].rollno;
           temp.name=hash_table[loc].name;
           temp.grade=hash_table[loc].grade;

           hash_table[loc].rollno=ob.rollno;
           hash_table[loc].name=ob.name;
           hash_table[loc].grade=ob.grade;
         }


         for(int i=(loc+1)%max;i!=loc;i=(i+1)%max)
         {
           if(hash_table[i].rollno==-1)
           {
             hash_table[i].rollno=temp.rollno;
             hash_table[i].name=temp.name;
             hash_table[i].grade=temp.grade;
             break;
           }
           else
            flag=1;
         }
       }
       if(flag==1)
        cout<<"Hash full.";
    cout<<"Continue? y | n:";
    cin>>ch;
    }while(ch=='y');
  }
  void lin_probing_noRepl()
  {
    student ob;char ch;
    do{
       display();
       int flag=0;
       cout<<"Enter roll number, name, and grade:\n";
       cin>>ob.rollno;
       cin.ignore();
       getline(cin,ob.name);
       cin>>ob.grade;

       int loc = ob.rollno%max;

       if(hash_table[loc].rollno==-1)
       {
         hash_table[loc].rollno=ob.rollno;
         hash_table[loc].name=ob.name;
         hash_table[loc].grade=ob.grade;

       }

       else
       {
         for(int i=(loc+1)%max;i!=loc;i=(i+1)%max)
         {
           if(hash_table[i].rollno==-1)
           {
             hash_table[i].rollno=ob.rollno;
             hash_table[i].name=ob.name;
             hash_table[i].grade=ob.grade;
             break;
           }
           else
            flag=1;
         }
       }
       if(flag==1)
        cout<<"Hash full.";
    cout<<"Continue? y | n:";
    cin>>ch;
    }while(ch=='y');
  }
};
int main()
{
  hashing ob;
  ob.lin_probing_Repl();
}