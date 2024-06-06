#include<iostream>
using namespace std;

class student_information;

class student
{
public:
    string name;
    string srn;
    string address;
    long mobile_no;

    student()
        : name(""), srn(""), address(""), mobile_no(0) {}

    student(string n, string s, string a, long m)
        : name(n), srn(s), address(a), mobile_no(m) {}

    virtual void getdata() {};

    virtual void display()  {};
};

class student_information : public student
{
    string branch;
    string div;
    int rollno;
    long parent_mob;

public:
    void getdata() override
    {
        cout << "Enter details: " << endl;
        cout << "Student Name: ";
        cin >> name;
        cout << endl << "Student SRN: ";
        cin >> srn;
        cout << endl << "Student address: ";
        cin >> address;
        cout << endl << "Student mobile number: ";
        cin >> mobile_no;  
        cout << endl;
        cout << "Student branch: ";
        cin >> branch;
        cout << endl << "Student division: ";
        cin >> div;
        cout << endl << "Student roll no: ";
        cin >> rollno;
        cout << endl << "Parent mobile no: ";
        cin >> parent_mob;
        cout << endl;
    }

    void display() override
    {
        student::display(); // Call base class display function
    }
};

void menu()
{
    int n, m;
    cout << "Home" << endl;
    cout << " 1.Student Information \n 2.Update information \n 3.Academic Information \n 4.Attendance \n 5.Marks \n 6.Backlog Registration \n 7.Course Registration \n 8.Feedback \n 9.Progress" << endl;
    cout << "enter your choice: ";
    cin >> n;

    if (n == 1)
    {

        student_information si;


        cout << "1.get information \n 2. display information" << endl;
        cin >> m;

        if (m == 1)
        {
            si.getdata();
            cout << "Please enter 1 to return home page:";
            cin >> m;
            if (m == 1) {
                menu();
            }
        }
        else if (m == 2)
        {
            si.display();
        }
        else {
            cout << "please enter valid choice: " << endl;
        }

    }

}

int main()
{
    menu();
    return 0;
}
