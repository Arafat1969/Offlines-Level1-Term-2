#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
class Student{
char *Name;
int ID;
int cred_hour;
double cgpa;
public:
Student(char *N,int Id,int cred,double cg)
{
  Name=(char*)malloc((strlen(N)+1)*sizeof(char));
  strcpy(Name,N);
  ID=Id;
  cred_hour=cred;
  cgpa=cg;
}
~Student()
{
    free(Name);
}
void showInfo()
{
    cout<<"Name: "<<Name<<", "<<"Id: "<<ID<<", "<<"Credit Completed: "<<cred_hour<<", "<<"Cgpa:"<<cgpa<<endl;
}
change(char *N)
{
   Name=(char*)malloc((strlen(N)+1)*sizeof(char));
   strcpy(Name,N);
}
change (int Id)
{
    ID=Id;
}
addTermResult(int cred, double cg)
{
  cgpa=((cgpa*cred_hour)+(cred*cg))/(cred+cred_hour);
  cred_hour+=cred;
}

};

class Batch
{
 Student *ob;
 int count=0;
 public:
 Batch()
 {
  ob=(Student*)malloc(1200*sizeof(Student));
 }
 ~Batch()
{
    free(ob);
}
void addStudent(Student &student)
{
  ob[count]= student;
  count++;
}
 void showAllStudents()
 {
     for(int i=0;i<count;i++)
     {
       ob[i].showInfo();
     }
 }
};




int main()
{
 // Part 1
 /*A student class holds the information of the
 student name, id, credit earned so far, and
 cumulative gpa (cgpa)*/
 /*The name of a student is stored using malloc,
 which will be freed during destruction*/
 Student s1("Tamim Iqbal", 1905131, 39, 3.56);
 Student s2("Liton Das", 1905150, 39, 3.52);
 s1.showInfo();
 cout<<"Changing the name of s1"<<endl;
 /*During changing the name, you should reallocate
 memory of the new name and free the previously
 allocated memory*/
 s1.change("Tamim Iqbal Khan");
 s1.showInfo();
 cout<<"Changing the id of s2"<<endl;
 s2.change(1905149);
 s2.showInfo();
 cout<<"Adding a term result of s1"<<endl;
 /*The first argument of addTermResult is the credit
 earned in a term and second one is the gpa obtained
 in that term*/
 s1.addTermResult(19, 3.85);
 s1.showInfo();
 // Part 2
 /*Batch contains a list of students*/
 /*During construction, a Batch object allocates dynamic
 memory for 1200 students using malloc. The memory will
 be freed during destruction*/
 Batch b;
 b.addStudent(s1);
 b.addStudent(s2);
 cout<<"Printing the list of students of the batch b"<<endl;
 b.showAllStudents();
}
