#include<iostream>
#include<string>
using namespace std;
class Data
{
    char *name = new char[20];
    int roll;
    int year;
    char *div = new char[1];
    char *clas = new char[3];
    string dob;
    long int phone;
    string college;
    public:
        static int count;
        Data()
        {
            roll = 0;
            year = 0;
            dob = "";
            phone = 0;
            count = 0;
        }
        ~Data()
        {
            delete [] div;
            delete [] clas;
            delete [] name;
        }
        Data(Data &obj)
        {
            this->college = obj.college;
        }
        inline static int getCount()
        {
            return count;
        }
        void inputData()
        {
            cout<<"Enter Student Name : ";
            cin>>name;
            cout<<"Enter Roll No : ";
            cin>>roll;
            cout<<"Enter Year : ";
            cin>>year;
            cout<<"Enter Class : ";
            cin>>clas;
            cout<<"Enter Division : ";
            cin>>div;
            cout<<"Enter Date Of Birth (dd/mm/yyy) : ";
            cin>>dob;
            cout<<"Enter Phone Number : ";
            cin>>phone;
            count++;
            cout<<"\n\n";
            try{
                if (roll < 1)
                {
                    throw(roll);
                }
            }catch(char i){
                roll=0;
                year=0;
                clas=0;
                dob = "";
                
            }
        }
        void setCollege(string college)
        {
            this->college = college;
        }
        friend class Display;
};
int Data::count;
class Display
{
public:
    void display(Data &obj)
    {
        cout<<"College Name : "<<obj.college<<"\n";
        cout<<"Student Name : "<<obj.name<<"\n";
        cout<<"Roll No : "<<obj.roll<<"\n";
        cout<<"Year : "<<obj.year<<"\n";
        cout<<"Class : "<<obj.clas<<"\n";
        cout<<"Division : "<<obj.div<<"\n";
        cout<<"Date of Birth : "<<obj.dob<<"\n";
        cout<<"Phone No : "<<obj.phone<<"\n\n";
    }
};
int main()
{
    string college;
    cout<<"Enter College Name : ";
    cin>>college;
    Data a;
    a.inputData();
    a.setCollege(college);
    Display ad;
    Data b(a);
    b.inputData();
    ad.display(a);
    ad.display(b);
    cout<<"\nTotal Student Entries : "<<a.getCount()<<"\n";

    return 0;
}