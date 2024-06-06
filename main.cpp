#include <iostream>
using namespace std;

class student_information;

class student {
public:
  string name;
  string srn;
  string address;
  long mobile_no;

  student() : name(""), srn(""), address(""), mobile_no(0) {}

  student(string n, string s, string a, long m)
      : name(n), srn(s), address(a), mobile_no(m) {}

   
};

class student_information : public student {
public:
  string branch;
  string div;
  int rollno;
  long parent_mob;

  void getdata(student_information& si)  { // Pass by reference
    cout << "Enter details: " << endl;
    cout << "Student Name: ";
    cin >> si.name;
    cout << endl << "Student SRN: ";
    cin >> si.srn;
    cout << endl << "Student address: ";
    cin >> si.address;
    cout << endl << "Student mobile number: ";
    cin >> si.mobile_no;
    cout << endl;
    cout << "Student branch: ";
    cin >> si.branch;
    cout << endl << "Student division: ";
    cin >> si.div;
    cout << endl << "Student roll no: ";
    cin >> si.rollno;
    cout << endl << "Parent mobile no: ";
    cin >> si.parent_mob;
    cout << endl;
  }

  void display()  {
    cout << "name: " << name << endl
         << "srn: " << srn << endl
         << "address: " << address << endl
         << "mobile no: " << mobile_no << endl
         << "branch: " << branch << endl
         << "division: " << div << endl
         << "roll no: " << rollno << endl
         << "parent mobile no: " << parent_mob << endl;
  }
};

void menu() {
  int n, m,p;
  cout << "Home" << endl;
  cout << " 1.Student Information \n 2.Update information \n 3.Academic Information \n 4.Attendance \n 5.Marks \n 6.Backlog Registration \n 7.Course Registration \n 8.Feedback \n 9.Progress" << endl;
  cout << "enter your choice: ";
  cin >> n;

  if (n == 1) {
    student_information si;
    si.getdata(si);

    cout << "1.get information \n 2. display information" << endl;
    cin >> m;

    if (m == 2) {
      si.display();

      cout<<"enter 1 to back to home page: ";
      cin>>p;

      if(p==1)
      {
        menu();
      }
    } else if (m == 1) {
      cout << "Re-entering information will overwrite previous data." << endl;
      si.getdata(si);
      cout<<"enter 1 to back to home page: ";
      cin>>p;

      if(p==1)
      {
        menu();
      }
    } else {
      cout << "please enter valid choice: " << endl;
    }
  }

}

int main() {
  menu();
  return 0;
}
