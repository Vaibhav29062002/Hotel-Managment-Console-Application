#include<iostream>
#include<string.h>
#include <stdlib.h>
#include <conio.h>
#include<fstream>
#include <windows.h>
using namespace std;
 class Admin
{
    char username[20],password[20];
    fstream af;
    public:
        void Add_Admin()
        {
            af.open("Admin.txt",ios::app);
            char ch;
            int i=0;
            cout<<"enter username: "<<endl;
            cin>>username;
            cout<<"enter password: "<<endl;
            ch=getch();
            while(ch!=13)
            {
                password[i]=ch;
                i++;
                cout<<"*";
                ch=getch();
            }
            password[i]='\0';

            af<<username<<" "<<password<<endl;
            cout<<"\n"<<username<<" details added successfully"<<endl;
            af.close();
        }

        int Login_Admin()
        {
            char tempadmin[20],temppassword[20],ch;
            int i=0;
            af.open("Admin.txt",ios::in);
            cout<<"enter UserName for Login: "<<endl;
            cin>>tempadmin;
            cout<<"enter your password: "<<endl;
            ch=getch();
            while(ch!=13)
            {
                temppassword[i]=ch;
                i++;
                cout<<"*";
                ch=getch();
            }
            temppassword[i]='\0';
            while(1)
            {
                if((af>>username).eof())
                {
                    break;
                }
                af>>password;
                if(!strcmp(username,tempadmin) && !strcmp(password,temppassword))
                {
                    cout<<"\nlogin successfully. "<<endl;
                    return 1;
                }
                else
                {
                   cout<<"\nwrong Username & Password. "<<endl;
                   return 0;
                }
            }
            af.close();

        }
};

 void gotoxy(int x, int y)   //gotoxy(3,7);
{
            COORD c;
            c.X = x;
            c.Y = y;

            SetConsoleCursorPosition(
                GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void delay()
{
    for(int i=1;i<3000000;i++)
    {
        i++;i--;
    }
}



int checkmob(long long m)
{
    int l=0;
    while(m!=0)
    {
        l++;
        m=m/10;
    }
    if(l==10)
        return 1;
    else
        return 0;
     //   if(600000000 >= m  && 9999999999<= m)
}
void logout()
{

    char logout[50]=">>>>>>>>>>LOGOUT FROM THE PROJECT<<<<<<<<<<";
    int l=strlen(logout);
    for(int i=0;i<l;i++)
    {
        cout<<logout[i];
        delay();
    }
}
class Hotel : public Admin
{
     string hname,haddress;
     long long hmob;
     int no_of_rooms;
   public:
    fstream f,f2;
    void Hotel_View()
    {
        f.open("Hotel.txt",ios::in);
        f>>hname>>haddress>>hmob;
        cout<<"Hotel Name: "<<hname<<endl;
        cout<<"Hotel Mobile Number: "<<hmob<<endl;
        cout<<"Hotel Address: "<<haddress<<endl;
        f.close();
    }
   void Hotel_Update()
    {
        f.open("Hotel.txt",ios::out);
        cout<<"Enter Hotel Name for Update: "<<endl;
        cin>>hname;
         cout<<"Enter Hotel Address for Update: "<<endl;
        cin>>haddress;
        for(int k=1;k<=3;k++)
         {
             int x;
             cout<<"Enter Hotel Mobile Number for Update: "<<endl;
              cin>>hmob;
              x= checkmob(hmob);
              if(x==1)
              {
                  break;
              }
              else
              {
                  cout<<"Please enter valid number. you have only "<<3-k<<"  attempts"<<endl;
              }
              if(k==3)
              {
                  cout<<"PLease try after some time "<<endl;
                  logout();
                    exit(0);
              }

         }

        f<<hname<<" "<<haddress<<" "<<hmob<<endl;
        f.close();
        cout<<"Hotel Details updated Successfully. Please Wait "<<endl;
        for(int k=1;k<=8;k++)
        {
            cout<<" . ";
            delay();
        }
    }

    int Room_View()
    {
        f2.open("Room.txt",ios::in);
        f2>>no_of_rooms;
        cout<<"Available Rooms: "<<no_of_rooms<<endl;
        if(no_of_rooms > 0)
        {
            return 1;
        }
        else
            return 0;
        f2.close();
    }
    void Room_Add()
    {
        f2.open("Room.txt",ios::out);
        cout<<"Enter how many room in the hotel: "<<endl;
        cin>>no_of_rooms;
        f2<<no_of_rooms<<endl;
        f2.close();
    }
    void Room_Update()
    {
        int z;
        f2.open("Room.txt",ios::in);
        f2>>no_of_rooms;
        z=no_of_rooms;
        f2.close();
        f2.open("Room.txt",ios::out);
        z=z-1;
        f2<<z<<endl;
        f2.close();
    }
     void Room_Update_checkout()
    {
        int z;
        f2.open("Room.txt",ios::in);
        f2>>no_of_rooms;
        z=no_of_rooms;
        f2.close();
        f2.open("Room.txt",ios::out);
        z=z+1;
        f2<<z<<endl;
        f2.close();
    }
};

void Hotel_Menu()
{
    Hotel h;
    int x;
    char ch;
        do
    {
        system("cls");
        int v;
         gotoxy(10,3);
            cout<<"**********HOTEL MENU***********"<<endl;
            gotoxy(10,4);
            cout<<"Press 1 for View Hotel Information."<<endl;
            gotoxy(10,5);
            cout<<"Press 2 for Update Hotel Information."<<endl;
             gotoxy(10,6);
            cout<<"Press 3 for View Room Information."<<endl;
            gotoxy(10,7);
            cout<<"Press 4 for Add Room Information."<<endl;
            gotoxy(10,8);
            cout<<"enter your choice: "<<endl;
            gotoxy(10,9);
            cin>>x;
            switch(x)
            {
                    case 1:h.Hotel_View();
                                break;
                    case 2:v= h.Login_Admin();
                                if(v==1)
                                {
                                     h.Hotel_Update();
                                }
                                break;
                    case 3:h.Room_View();
                                break;
                    case 4:h.Room_Add();
                                break;
                    default:cout<<"wrong input."<<endl;
            }
            cout<<"\nDo you want to View Hotel Menu Again. If yes then press y:"<<endl;
            cin>>ch;

    }while(ch=='y');
}

class Employee : public  Hotel
{
           string ename;
           int salary,eid;
           long long emob;
           fstream ef;
        public:
              void AddEmployee()
                {
                    int tempid;
                   ef.open("Employee.txt",ios::in);
                   while(1)
                   {
                       if((ef>>eid).eof())
                              {
                                  break;
                              }
                              ef>>ename>>salary>>emob;
                              tempid=eid;
                   }
                   ef.close();
                   ef.open("Employee.txt",ios::app);
                     eid=tempid+1;
                    cout<<"enter employee name: "<<endl;
                    cin>>ename;
                     cout<<"enter employee salary: "<<endl;
                    cin>>salary;
                    for(int k=1;k<=3;k++)
                     {
                         int x;
                         cout<<"Enter employee Mobile Number: "<<endl;
                          cin>>emob;
                          x= checkmob(emob);
                          if(x==1)
                          {
                              break;
                          }
                          else
                          {
                              cout<<"Please enter valid number. you have only "<<3-k<<"  attempts"<<endl;
                          }
                          if(k==3)
                          {
                              cout<<"PLease try after some time "<<endl;
                              logout();
                                exit(0);
                          }

                     }
                    ef<<eid<<" "<<ename<<" "<<salary<<" "<<emob<<endl;
                    ef.close();
                    cout<<ename<<" Details added Successfully. Please Wait "<<endl;
                        for(int k=1;k<=8;k++)
                        {
                            cout<<" . ";
                            delay();
                        }
                }
                void ViewEmployee()
                {
                    int count=1;
                      ef.open("Employee.txt",ios::in);
                      Hotel_View();
                      cout<<"-----------------------------"<<endl;
                      cout<<"All the Employee Information."<<endl;

                      while(1)
                      {
                          if((ef>>eid).eof())
                          {
                              break;
                          }
                          ef>>ename>>salary>>emob;
                          cout<<count<<". Employee ID: "<<eid<<endl;
                          cout<<"Employee Name: "<<ename<<endl;
                           cout<<"Employee Salary: "<<salary<<endl;
                            cout<<"Employee Mobile Number: "<<emob<<endl;
                             cout<<"------------------------------------------"<<endl;
                             count++;
                      }
                      ef.close();
                }
                void SearchEmployee()
                {
                    int status=0;
                    int tid;
                    cout<<"enter employee id to search: "<<endl;
                    cin>>tid;
                      ef.open("Employee.txt",ios::in);
                      while(1)
                      {
                          if((ef>>eid).eof())
                          {
                              break;
                          }
                          ef>>ename>>salary>>emob;
                          if(tid ==eid )
                          {
                            cout<<"Employee ID: "<<eid<<endl;
                            cout<<"Employee Name: "<<ename<<endl;
                            cout<<"Employee Salary: "<<salary<<endl;
                            cout<<"Employee Mobile Number: "<<emob<<endl;
                            Hotel_View();
                            cout<<" ------------------------------------------"<<endl;
                            status=1;
                          }
                      }
                      if(status==0)
                      {
                          cout<<tid<<" is not found"<<endl;
                      }
                      ef.close();
                }
                void UpdateEmployee()
                {
                        fstream tef;
                        tef.open("employeetemp.txt",ios::app);
                        int status=0,x;
                        int tid;
                        cout<<"enter employee id to Update salary: "<<endl;
                        cin>>tid;
                          ef.open("Employee.txt",ios::in);
                          while(1)
                          {
                              if((ef>>eid).eof())
                              {
                                  break;
                              }
                              ef>>ename>>salary>>emob;
                              if(tid ==eid )
                              {
                                  cout<<"Enter Percentage of salary increment: "<<endl;
                                  cin>>x;
                                  if(x>0 && x<=25)
                                  {
                                      salary=salary+((salary*x)/100);
                                      cout<<ename<<" salary incremented successfully.Please Wait "<<endl;
                                            for(int k=1;k<=8;k++)
                                            {
                                                cout<<" . ";
                                                delay();
                                            }
                                  }
                                  else{
                                      cout<<"increment is not possible bcz percentage is out of range. "<<endl;
                                  }
                                    status=1;

                              }
                              tef<<eid<<" "<<ename<<" "<<salary<<" "<<emob<<endl;
                          }
                          if(status==0)
                          {
                              cout<<tid<<" is not found"<<endl;
                          }
                          ef.close();
                           tef.close();
                           remove("Employee.txt");
                           rename("employeetemp.txt","Employee.txt");

                }
};
void Employee_Menu()
{
        Employee e;
    int x;
    char ch;
        do
    {
        system("cls");
        int v;
           gotoxy(10,3);
            cout<<"**********EMPLOYEE MENU***********"<<endl;
            gotoxy(10,4);
            cout<<"Press 1 to Add New Employee."<<endl;
            gotoxy(10,5);
            cout<<"Press 2 to View All the Employee."<<endl;
            gotoxy(10,6);
            cout<<"Press 3 to Search Employee via emp id."<<endl;
            gotoxy(10,7);
            cout<<"Press 4 to Update Employee Details."<<endl;
            gotoxy(10,8);
            cout<<"enter your choice: "<<endl;
            gotoxy(10,9);
            cin>>x;
            switch(x)
            {
                    case 1:e.AddEmployee();
                                break;
                    case 2:e.ViewEmployee();
                                break;
                    case 3: e.SearchEmployee();
                                break;
                   case 4: v=e.Login_Admin();
                                if(v==1)
                                {
                                    e.UpdateEmployee();
                                }

                                break;
                    default:cout<<"wrong input."<<endl;
            }
            cout<<"\nDo you want to View Employee Menu Again. If yes then press y:"<<endl;
            cin>>ch;

    }while(ch=='y');
}

class Guest : public Hotel
{
       string gname,idproof;
       long long gmob;
       int payment,status=0,no_of_days;
            public:
                fstream gf;
                void Checkin_Guest()
                {
                   long long tempmob;
                   int count=0;
                    for(int k=1;k<=3;k++)
                             {
                                 int x;
                                cout<<"enter Guest Mobile Number: "<<endl;
                                cin>>tempmob;
                                  x= checkmob(tempmob);
                                  if(x==1)
                                  {
                                      break;
                                  }
                                  else
                                  {
                                      cout<<"Please enter valid number. you have only "<<3-k<<"  attempts"<<endl;
                                  }
                                  if(k==3)
                                  {
                                      cout<<"PLease try after some time "<<endl;
                                      logout();
                                        exit(0);
                                  }
                             }
                             gf.open("Guest.txt",ios::in);
                        while(1)
                        {
                            if((gf>>gname).eof())
                            {
                                break;
                            }
                            gf>>idproof>>gmob>>payment>>status;
                            if(tempmob==gmob)
                            {
                                cout<<"this mobile number is already register for other guest"<<endl;
                                count=1;
                            }
                        }
                        gf.close();
                    if(count==0)
                    {
                                 cout<<"enter Guest Name: "<<endl;
                            cin>>gname;
                            cout<<"enter Guest ID Proof: "<<endl;
                            cin>>idproof;
                               gmob=tempmob;
                              cout<<"enter How many days Guest will stay: "<<endl;
                              cin>>no_of_days;
                              payment= no_of_days*4000;
                              status= 1;
                              Room_Update();
                              gf.open("Guest.txt",ios::app);
                              gf<<gname<<" "<<idproof<<" "<<gmob<<" "<<payment<<" "<<status<<endl;
                              cout<<gname<<" is check in into hotel"<<endl;
                              gf.close();
                    }
                }
                void View_Guest()
                {
                    gf.open("Guest.txt",ios::in);
                    Hotel_View();
                    cout<<"-----------All the Guest List-----------"<<endl;
                    while(1)
                    {
                        if((gf>>gname).eof())
                        {
                            break;
                        }
                        gf>>idproof>>gmob>>payment>>status;
                        cout<<"Guest Name: "<<gname<<endl;
                        cout<<"Guest ID Proof: "<<idproof<<endl;
                        cout<<"Guest Mobile Number: "<<gmob<<endl;
                        cout<<"Guest Payment: "<<payment<<endl;
                        cout<<"Guest Status: "<<status<<endl;
                        cout<<"----------------------------------"<<endl;
                    }
                    gf.close();
                }
                void Search_Guest()
                {
                    long long tempmob;
                    int c=0;
                    cout<<"enter Guest Mobile Number to Search Data: "<<endl;
                    cin>>tempmob;

                    gf.open("Guest.txt",ios::in);
                    while(1)
                    {
                        if((gf>>gname).eof())
                        {
                            break;
                        }
                        gf>>idproof>>gmob>>payment>>status;
                        if(tempmob==gmob)
                        {
                              cout<<"Guest Name: "<<gname<<endl;
                            cout<<"Guest ID Proof: "<<idproof<<endl;
                            cout<<"Guest Mobile Number: "<<gmob<<endl;
                            cout<<"Guest Payment: "<<payment<<endl;
                            cout<<"Guest Status: "<<status<<endl;
                            Hotel_View();
                            cout<<"----------------------------------"<<endl;
                            c=1;
                        }
                    }
                    if(c==0)
                    {
                        cout<<"this mobile number= "<<tempmob<<" is not found"<<endl;
                    }
                    gf.close();
                }
                void Checkout_Guest()
                {
                    fstream cg;
                    cg.open("GuestTemp.txt",ios::app);
                         long long tempmob;
                    int c=0;
                    cout<<"enter Guest Mobile Number for Check Out: "<<endl;
                    cin>>tempmob;

                    gf.open("Guest.txt",ios::in);
                    while(1)
                    {
                        if((gf>>gname).eof())
                        {
                            break;
                        }
                        gf>>idproof>>gmob>>payment>>status;
                        if(tempmob==gmob)
                        {
                             Room_Update_checkout();
                             status=0;
                             cout<<gname<<" is check out from hotel"<<endl;
                            c=1;
                        }
                        cg<<gname<<" "<<idproof<<" "<<gmob<<" "<<payment<<" "<<status<<endl;
                    }
                    if(c==0)
                    {
                        cout<<"this mobile number= "<<tempmob<<" is not found"<<endl;
                    }
                    gf.close();
                    cg.close();
                    remove("Guest.txt");
                    rename("GuestTemp.txt","Guest.txt");

                }
};
void Guest_Menu()
{
        Guest g;
    int x,y;
    char ch;
        do
    {
        system("cls");
           gotoxy(10,3);
            cout<<"**********GUEST MENU***********"<<endl;
            gotoxy(10,4);
            cout<<"Press 1 to Check IN New GUEST."<<endl;
            gotoxy(10,5);
            cout<<"Press 2 to View All the GUEST."<<endl;
            gotoxy(10,6);
            cout<<"Press 3 to Search GUEST via Mobile Number."<<endl;
            gotoxy(10,7);
            cout<<"Press 4 to Check OUT GUEST."<<endl;
            gotoxy(10,8);
            cout<<"enter your choice: "<<endl;
            gotoxy(10,9);
            cin>>x;
            switch(x)
            {
                    case 1: y= g.Room_View();
                                if(y==1)
                                        g.Checkin_Guest();
                                else
                                    cout<<"Rooms are not available."<<endl;
                                break;
                    case 2:g.View_Guest();
                                break;
                    case 3: g.Search_Guest();
                                break;
                   case 4: g.Checkout_Guest();
                                break;
                    default:cout<<"wrong input."<<endl;
            }
            cout<<"\nDo you want to View GUEST Menu Again. If yes then press y:"<<endl;
            cin>>ch;

    }while(ch=='y');
}

void Admin_Menu()
{
        Admin a;
    int x,y;
    char ch;
        do
    {
        system("cls");
           gotoxy(10,3);
            cout<<"**********ADMIN MENU***********"<<endl;
            gotoxy(10,4);
            cout<<"Press 1 to Admin Login."<<endl;
            gotoxy(10,5);
            cout<<"Press 2 to Add new Admin."<<endl;
            gotoxy(10,6);
            cout<<"enter your choice: "<<endl;
            gotoxy(10,9);
            cin>>x;
            switch(x)
            {
                    case 1: a.Login_Admin();
                                break;
                    case 2:a.Add_Admin();
                                break;
                    default:cout<<"wrong input."<<endl;
            }
            cout<<"\nDo you want to View Admin Menu Again. If yes then press y:"<<endl;
            cin>>ch;

    }while(ch=='y');
}
main()
{
    gotoxy(10,2);
    char welcome[50]=">>>>>>>>>>WELCOME TO PROJECT<<<<<<<<<<\n";
    int l=strlen(welcome);
    int x;
    char ch;
    for(int i=0;i<l;i++)
    {
        cout<<welcome[i];
        delay();
    }
    do
    {
           gotoxy(10,3);
            cout<<"**********MAIN MENU***********"<<endl;
            gotoxy(10,4);
            cout<<"Press 1 for Hotel Menu."<<endl;
            gotoxy(10,5);
            cout<<"Press 2 for Employee Menu."<<endl;
            gotoxy(10,6);
            cout<<"Press 3 for Guest Menu."<<endl;
            gotoxy(10,7);
            cout<<"Press 4 for Admin Menu."<<endl;
            gotoxy(10,8);
            cout<<"Press 5 for exit from Project."<<endl;
            gotoxy(10,9);
            cout<<"enter your choice: "<<endl;
            gotoxy(10,10);
            cin>>x;
            switch(x)
            {
                    case 1:Hotel_Menu();
                                break;
                    case 2:Employee_Menu();
                                break;
                    case 3:Guest_Menu();
                                break;
                    case 4:Admin_Menu();
                                break;
                    case 5:  logout();
                                exit(0);
                    default:cout<<"wrong input."<<endl;
            }
            cout<<"\nDo you want to go Main Menu Again. If yes then press y:"<<endl;
            cin>>ch;
            if(ch!='y')
            {
                cout<<"Are you sure you want to exit if no then press y: "<<endl;
                cin>>ch;
            }
             system("cls");
    }while(ch=='y');
     logout();

}
