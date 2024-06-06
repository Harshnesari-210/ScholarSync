#include <iostream>
#include <vector>
#include <string>
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

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
  int ASR;
  int OOPS;
  int POCD;
  int OSPP;
  float sem1;
  float sem2;
  float sem3;
  float cgpa;

  void getdata(student_information& si) {
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

  void display() {
    cout << "name: " << name << endl
         << "srn: " << srn << endl
         << "address: " << address << endl
         << "mobile no: " << mobile_no << endl
         << "branch: " << branch << endl
         << "division: " << div << endl
         << "roll no: " << rollno << endl
         << "parent mobile no: " << parent_mob << endl;
  }

  void update(string field) {
    if (field == "name") {
      cout << "Enter new name: ";
      cin >> name;
    } else if (field == "srn") {
      cout << "Enter new SRN: ";
      cin >> srn;
    } else if (field == "address") {
      cout << "Enter new address: ";
      cin >> address;
    } else if (field == "mobile_no") {
      cout << "Enter new mobile number: ";
      cin >> mobile_no;
    } else if (field == "branch") {
      cout << "Enter new branch: ";
      cin >> branch;
    } else if (field == "div") {
      cout << "Enter new division: ";
      cin >> div;
    } else if (field == "rollno") {
      cout << "Enter new roll number: ";
      cin >> rollno;
    } else if (field == "parent_mob") {
      cout << "Enter new parent mobile number: ";
      cin >> parent_mob;
    } else {
      cout << "Invalid field. Please try again." << endl;
    }
  }
};

class academic : public student_information {
public:
  void get_academic_info(academic& a) {
    cout << "Enter academic information (marks): " << endl;
    cout << "ASR: ";
    cin >> a.ASR;
    cout << endl << "OOPS: ";
    cin >> a.OOPS;
    cout << endl << "POCD: ";
    cin >> a.POCD;
    cout << endl << "OSPP: ";
    cin >> a.OSPP;
  }

  void display_academic_info() {
    cout << "ASR: " << ASR << endl
         << "OOPS: " << OOPS << endl
         << "POCD: " << POCD << endl
         << "OSPP: " << OSPP << endl
         << "Total: " << (ASR + OOPS + POCD + OSPP) << endl
         << "CGPA: " << (ASR + OOPS + POCD + OSPP) / 40.0 << endl;

    vector<int> marks = {ASR, OOPS, POCD, OSPP};
    vector<string> subjects = {"ASR", "OOPS", "POCD", "OSPP"};

    plt::bar(subjects, marks);
    plt::xlabel("Subjects");
    plt::ylabel("Marks");
    plt::title("Academic Performance");
    plt::show();
  }
};

void menu() {
  int n, m, p;
  student_information si;
  academic ac;

  while (true) {
    cout << "Home" << endl;
    cout << " 1.Student Information \n 2.Update information \n 3.Academic Information \n 4.Attendance \n 5.Marks \n 6.Backlog Registration \n 7.Course Registration \n 8.Feedback \n 9.Progress" << endl;
    cout << "Enter your choice: ";
    cin >> n;

    if (n == 1) {
      cout << "1. Get information \n2. Display information" << endl;
      cin >> m;

      if (m == 2) {
        si.display();
        cout << "Enter 1 to go back to home page: ";
        cin >> p;
        if (p == 1) {
          continue;
        }
      } else if (m == 1) {
        si.getdata(si);
        cout << "Enter 1 to go back to home page: ";
        cin >> p;
        if (p == 1) {
          continue;
        }
      } else {
        cout << "Please enter a valid choice: " << endl;
      }
    } else if (n == 2) {
      string field;
      cout << "Enter the field you want to update (name, srn, address, mobile_no, branch, div, rollno, parent_mob): ";
      cin >> field;
      si.update(field);
      cout << "Update successful. Enter 1 to go back to home page: ";
      cin >> p;
      if (p == 1) {
        continue;
      }
    } else if (n == 3) {
      cout << "1. Get academic info \n2. Display academic info" << endl;
      cin >> m;
      if (m == 1) {
        ac.get_academic_info(ac);
      } else if (m == 2) {
        ac.display_academic_info();
      } else {
        cout << "Please enter a valid choice: " << endl;
      }
      cout << "Enter 1 to go back to home page: ";
      cin >> p;
      if (p == 1) {
        continue;
      }
    } else {
      cout << "Please enter a valid choice: " << endl;
    }
  }
}

int main() {
  menu();
  return 0;
}
