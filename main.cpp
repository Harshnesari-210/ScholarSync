#include<iostream>
using namespace std;

class student_information;

class student
{
    protected:
    string name;
    string srn;
    string address;
    long mobile_no;

    public:

    student()
    {
       name=" ";
       srn=" ";
       address=" ";
       mobile_no=0000000000;
    }

    student(string n,string s,string a,long m)
    {
        name=n;
        srn=s;
        address=a;
        mobile_no=m;
    }

    void getdata()
    {
        cout<<"Enter details: "<<endl;
        cout<<"Student Name: ";
        cin>>name;
        cout<<endl<<"Student Name: ";
        cin>>srn;
        cout<<endl<<"Student address: ";
        cin>>address;
        cout<<endl<<"Student mobile number: ";
        cin>>mobile_no;
        cout<<endl;
    }

    virtual void display()=0;
};



class student_information:public student
{
     string branch;
     string div;
     int rollno;
     long parent_mob;

     public:

     void get_data()
     {
        getdata();
        cin.ignore(); // Clearing input buffer
        getline(cin, branch); 
        cout<<"Student branch: ";
        cin>>branch;
        cout<<endl<<"student division: ";
        cin>>div;
        cout<<endl<<"student roll no: ";
        cin>>rollno;
        cout<<endl<<"prent mobile no: ";
        cin>>parent_mob;
        cout<<endl;
     }

   void display()
   {
       cout<<endl<<name<<endl<<srn<<endl<<address<<endl<<mobile_no<<endl;
   }

};


void menu()
{
    int n,m;
    cout<<"Home"<<endl;
    cout<<" 1.Student Information \n 2.Update information \n 3.Academic Information \n 4.Attendance \n 5.Marks \n 6.Backlog Registration \n 7.Course Registration \n 8.Feedback \n 9.Progress"<<endl;
    cout<<"enter your choice: ";
    cin>>n;

    if(n==1)
    {
        student_information si;
        
        cout<<"1.get information \n 2. display information"<<endl;
        cin>>m;

          if(m==1)
          {
            si.get_data();
          }
          else if(m==2)
          {
            si.display();
          }
          else{
            cout<<"please entr valid choice: "<<endl;
          }

    }

}

int main()
{
    menu();
    return 0;
}


