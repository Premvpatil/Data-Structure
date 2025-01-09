#include<iostream>
using namespace std;

class student{
    public:
    int i=0, j=0;
    int rollno, age, prnno, key, choice;
    string name, count;

    void add()
    {
        cout<<"Enter the student data :- Student : "<<i+1<<endl;
        cout<<"Enter Name of the student "<<i+1<<" :"<<endl;
        cin>>name;
        cout<<"Enter Age of the student "<<i+1<<" :"<<endl;
        cin>>age;
        cout<<"Enter Roll no of the student "<<i+1<<" :"<<endl;
        cin>>rollno;
        cout<<"Enter PRN no of the student "<<i+1<<" :"<<endl;
        cin>>prnno;
        cout<<"\n";
        i++;
    }
    void display()
    {
        cout<<"student "<<j+1<<" Name :"<<name<<endl;
        cout<<"student "<<j+1<<" Age :"<<age<<endl;
        cout<<"student "<<j+1<<" Roll no :"<<"CS21"<<rollno<<endl;
        cout<<"student "<<j+1<<" PRN no :"<<"RBTL24CS"<<prnno<<endl;
        cout<<"\n";
        j++;
    }
    void event()
    {
        cout<<"Libliary Management Database for Student:"<<endl;
        cout<<"Enter PRN_no "<<endl;
        cin>>key;
        if(prnno = key)
        {
            cout<<"RBTL24CS"<<prnno<<"Student has done regestration successfully "<<endl;

            while (true)
            {
                cout<<"\n";
                cout<<"\n Make Your's choices : \n"
                    <<"1. Reading Book : Physics\n"
                    <<"2. Reading Book : Chemistry \n"
                    <<"3. Reading Book : Maths \n"
                    <<"4. Exit"<<endl;
                cout<<"Enter value :-";
                cin>>choice;
                
                if(choice == 1)
                {
                    cout<<"\n Students Successfull Completed Course : Physics";
                    count += "Physics \n";
                }
                else if (choice == 2)
                {
                    cout<<"Students Successfull Completed Course : Chemistry";
                    count += "Chemistry \n";
                }
                else if (choice == 3)
                {
                    cout<<"Students Successfull Completed Course : Maths";
                    count += "Maths \n";
                }
                else
                {
                    cout<<"Exit the Program"<<endl;
                    break;
                }
            }

        }
        else{
            cout<<"RBTL24CS"<<prnno<<" Student has not done regestration";
        }
    }
    void DisplayEvent()
    {
        cout<<"\n RBTL24CS"<<key<<" has Competed Courses"<<endl;
        cout<<"courses : \n"<<count;
    }
};

int main()
{
    student s1;
    int i, n, c=0;
    cout<<"Enter total count for student [limit 5]"<<endl;
    cin>>n;
    for(i=0; i<n; i++)
    {
        s1.add();
    }
    for(i=0; i<n; i++)
    {
        cout<<"Successfully Regestration Student "<<c+1<<endl;
        s1.display();
    }
    s1.event();
    s1.DisplayEvent();
    return 0;
}