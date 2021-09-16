#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <string>
using namespace std;
int doctorSize,patientSize,nurseSize;
void gotoxy(int x,int y);
void doctorList();
void doctorList1();
void doctorModify();
void doctorDelete();
void doctorAdd();
void doctorWrite();
void patientList();
void patientList1();
void patientModify();
void patientDelete();
void patientAdd();
void patientWrite();
void nurseList();
void nurseList1();
void nurseModify();
void nurseDelete();
void nurseAdd();
void nurseWrite();
void design();
void design1();
void design2();
int  wherex();
int  wherey();
void doctorDesign();
void nurseDesign();
void patientDesign();
char *doctorSearch(string z);
char *doctorSearch();
char *doctorSearch1(int pos,string z);
char *nurseSearch1(int pos,string z);
void patientSearchDesign1(int pos);
void patientSearchDesign2(int pos);
struct doctor
{
    char name[32];
    char sex[12];
    int  age;
    char category[22];
    char chamberNo[12];
    char appointmentSchedule[12];
    char contactNo[15];
}d1[10],d2[10];
struct patient
{
    char name[32];
    char sex[12];
    int age;
    char patientType[22];
    char bloodGroup[12];
    char addmissionDate[12];
    char assignDoctorName[32];
    char wardName[12];
    char relationStatus[12];
    char address[32];
    char assignNurseName[32];
    char occupation[12];
}p1[10],p2[10];
struct nurse
{
    char name[32];
    char sex[12];
    int age;
    char study[22];
    char skil[22];
}n1[10],n2[10];
int main()
{
    int i=0,j,k;
    char ch,ch1,s1[100],s2[100];
    FILE *fp,*fp1;
    fp1=fopen("doctorSize.txt","r");
    fscanf(fp1,"%d",&doctorSize);
    fclose(fp1);
    fp1=fopen("patientSize.txt","r");
    fscanf(fp1,"%d",&patientSize);
    fclose(fp1);
    fp1=fopen("nurseSize.txt","r");
    fscanf(fp1,"%d",&nurseSize);
    fclose(fp1);
    fp=fopen("doctor.txt","rb");
    for(i=0;i<=doctorSize;i++)
    {
        fread(&d1[i],sizeof(d1[i]),1,fp);
    }
    fclose(fp);
    fp=fopen("patient.txt","rb");
    for(i=0;i<=patientSize;i++)
    {
        fread(&p1[i],sizeof(p1[i]),1,fp);
    }
    fclose(fp);
    fp=fopen("nurse.txt","rb");
    for(i=0;i<=nurseSize;i++)
    {
        fread(&n1[i],sizeof(n1[i]),1,fp);
    }
    fclose(fp);
    while(1)
    {
        gotoxy(18,3);
        cout<<"AosNillSetua Hospital Management";
        gotoxy(18,4);
        cout<<"________________________________";
        gotoxy(30,6);
        cout<<"1.doctor "<<endl;
        gotoxy(30,7);
        cout<<"2.patient"<<endl;
        gotoxy(30,8);
        cout<<"3.nurse";
        design();
        gotoxy(44,11);
        cin>>k;
        system("cls");
        switch(k)
        {
            case 1:dD:doctorDesign();gotoxy(27,25);design1();gotoxy(44,13);cin>>j;system("cls");switch(j){
                case 1:dl:doctorList1();gotoxy(23,15);cout<<"Want to see doctor list again ,press B :";
                                gotoxy(30,16);cout<<"Or";
                                gotoxy(23,17);cout<<"Want to see doctor menu again ,press M :";
                                char ch;
                                ch=getch();
                                system("cls");
                                if((ch=='b') || (ch=='B'))
                                    goto dl;
                                else if((ch=='m') || (ch=='M'))
                                    goto dD;
                                else
                                    break;
                                ;
                case 2:dM:doctorModify();gotoxy(18,15);cout<<"Want to doctor modify again ,press B :";
                                gotoxy(30,16);cout<<"Or";
                                gotoxy(18,17);cout<<"Want to see doctor menu again ,press M :";
                                ch=getch();
                                system("cls");
                                if((ch=='b') || (ch=='B'))
                                    goto dM;
                                else if((ch=='m') || (ch=='M'))
                                    goto dD;
                                else
                                    break;
                                ;
                case 3:dd:doctorDelete();gotoxy(18,15);cout<<"Want to doctor Delete again ,press B :";
                                gotoxy(30,16);cout<<"Or";
                                gotoxy(18,17);cout<<"Want to see doctor menu again ,press M :";
                                ch=getch();
                                system("cls");
                                if((ch=='b') || (ch=='B'))
                                    goto dd;
                                else if((ch=='m') || (ch=='M'))
                                    goto dD;
                                else
                                    break;
                                ;
                case 4:dA:doctorAdd();gotoxy(18,15);cout<<"Want to doctor Add again ,press B :";
                                gotoxy(30,16);cout<<"Or";
                                gotoxy(18,17);cout<<"Want to see doctor menu again ,press M :";
                                ch=getch();
                                system("cls");
                                if((ch=='b') || (ch=='B'))
                                    goto dA;
                                else if((ch=='m') || (ch=='M'))
                                    goto dD;
                                else
                                    break;
                                ;
                }break;
            case 2:pD:patientDesign();design1();gotoxy(44,13);cin>>j;system("cls");switch(j){
                case 1:pL:patientList1();gotoxy(23,20);cout<<"Want to patient list again ,press B :";
                                gotoxy(30,21);cout<<"Or";
                                gotoxy(23,22);cout<<"Want to see patient menu again ,press M :";
                                ch=getch();
                                system("cls");
                                if((ch=='b') || (ch=='B'))
                                    goto pL;
                                else if((ch=='m') || (ch=='M'))
                                    goto pD ;
                                else
                                    break;
                                ;
                case 2:pM:patientModify();gotoxy(23,20);cout<<"Want to patient Modify again ,press B :";
                                gotoxy(30,21);cout<<"Or";
                                gotoxy(23,22);cout<<"Want to see patient menu again ,press M :";
                                ch=getch();
                                system("cls");
                                if((ch=='b') || (ch=='B'))
                                    goto pM;
                                else if((ch=='m') || (ch=='M'))
                                    goto pD ;
                                else
                                    break;
                                ;
                case 3:pd:patientDelete();gotoxy(23,20);cout<<"Want to patient Delete again ,press B :";
                                gotoxy(30,21);cout<<"Or";
                                gotoxy(23,22);cout<<"Want to see patient menu again ,press M :";
                                ch=getch();
                                system("cls");
                                if((ch=='b') || (ch=='B'))
                                    goto pd;
                                else if((ch=='m') || (ch=='M'))
                                    goto pD ;
                                else
                                    break;
                                ;
                case 4:pA:patientAdd();gotoxy(23,20);cout<<"Want to patient Add again ,press B :";
                                gotoxy(30,21);cout<<"Or";
                                gotoxy(23,22);cout<<"Want to see patient menu again ,press M :";
                                ch=getch();
                                system("cls");
                                if((ch=='b') || (ch=='B'))
                                    goto pA;
                                else if((ch=='m') || (ch=='M'))
                                    goto pD ;
                                else
                                    break;
                                ;
                }break;
            case 3:nD:nurseDesign();design1();gotoxy(44,13);cin>>j;system("cls");switch(j){
                case 1:nL:nurseList1();gotoxy(23,13);cout<<"Want to nurse List again ,press B :";
                                gotoxy(30,14);cout<<"Or";
                                gotoxy(23,15);cout<<"Want to see nurse menu again ,press M :";
                                ch=getch();
                                system("cls");
                                if((ch=='b') || (ch=='B'))
                                    goto nL;
                                else if((ch=='m') || (ch=='M'))
                                    goto nD ;
                                else
                                    break;
                                ;
                case 2:nM:nurseModify();gotoxy(23,13);cout<<"Want to nurse Modify ,press B :";
                                gotoxy(30,14);cout<<"Or";
                                gotoxy(23,15);cout<<"Want to see nurse menu again ,press M :";
                                ch=getch();
                                system("cls");
                                if((ch=='b') || (ch=='B'))
                                    goto nM;
                                else if((ch=='m') || (ch=='M'))
                                    goto nD ;
                                else
                                    break;
                                ;
                case 3:nd:nurseDelete();gotoxy(23,13);cout<<"Want to nurse Delete again ,press B :";
                                gotoxy(30,14);cout<<"Or";
                                gotoxy(23,15);cout<<"Want to see nurse menu again ,press M :";
                                ch=getch();
                                system("cls");
                                if((ch=='b') || (ch=='B'))
                                    goto nd;
                                else if((ch=='m') || (ch=='M'))
                                    goto nD ;
                                else
                                    break;
                                ;
                case 4:nA:nurseAdd();gotoxy(23,13);cout<<"Want to nurse Add again ,press B :";
                                gotoxy(30,14);cout<<"Or";
                                gotoxy(23,15);cout<<"Want to see nurse menu again ,press M :";
                                ch=getch();
                                system("cls");
                                if((ch=='b') || (ch=='B'))
                                    goto nA;
                                else if((ch=='m') || (ch=='M'))
                                    goto nD ;
                                else
                                    break;
                                ;
                }break;
            default:cout<<"worng select\n";
        }
        system("cls");
    }
    return 0;
}
void doctorList()
{
    gotoxy(18,4);
    cout<<".....Doctor Database list.....";
    gotoxy(18,5);
    cout<<"________________________________";
    gotoxy(24,6);
    cout<<" SL-NO    doctor name";
    gotoxy(24,7);
    cout<<"------   -------------";
    int j=8;
    for(int i=0;i<=doctorSize;i++){
            gotoxy(26,j);
        cout<<i+1<<".       "<<d1[i].name<<endl;
        j++;
    }
}
void doctorList1()
{
    gotoxy(18,4);
    cout<<".....Doctor Database list.....";
    gotoxy(18,5);
    cout<<"________________________________";
    gotoxy(24,6);
    cout<<" SL-NO    doctor name";
    gotoxy(24,7);
    cout<<"------   -------------";
    int j=8;
    for(int i=0;i<=doctorSize;i++){
            gotoxy(26,j);
        cout<<i+1<<".       "<<d1[i].name<<endl;
        j++;
    }
    int i;
    gotoxy(20,j);
    cout<<"-------------------------";
    j++;
    gotoxy(25,j);
    cout<<"Select your item :";
    j++;
    gotoxy(20,j);
    cout<<"-------------------------\n";
    j--;
    gotoxy(44,j);
    cin>>i;
    system("cls");
    gotoxy(18,3);
    cout<<"......Doctor Details Are.......";
    gotoxy(18,4);
    cout<<"________________________________";
    i=i-1;
    gotoxy(23,6);
    cout<<"Doctor name :  ";
    cout<<d1[i].name<<endl;
    gotoxy(23,7);
    cout<<"Doctor sex :  ";
    cout<<d1[i].sex<<endl;
    gotoxy(23,8);
    cout<<"Doctor age :  ";
    cout<<d1[i].age<<endl;
    gotoxy(23,9);
    cout<<"Doctor category :  ";
    cout<<d1[i].category<<endl;
    gotoxy(23,10);
    cout<<"Doctor chamberNo :  ";
    cout<<d1[i].chamberNo<<endl;
    gotoxy(23,11);
    cout<<"Doctor appointmentSchedule :  ";
    cout<<d1[i].appointmentSchedule<<endl;
    gotoxy(23,12);
    cout<<"Doctor contactNo :  ";
    cout<<d1[i].contactNo<<endl;
    gotoxy(23,15);
    cout<<"Press enter to continue ";
}
void doctorModify()
{
    int i,pos,j=doctorSize+9;
    doctorList();
    gotoxy(20,j);
    cout<<"-------------------------";
    j++;
    gotoxy(25,j);
    cout<<"Select your item :";
    j++;
    gotoxy(20,j);
    cout<<"-------------------------\n";
    j--;
    gotoxy(44,j);
    cin>>pos;
    system("cls");
    gotoxy(18,4);
    cout<<"....Doctor Database Modify.....";
    gotoxy(18,5);
    cout<<"________________________________";
    pos=pos-1;
    gotoxy(18,6);
    cout<<"Doctor name :  ";
    strcpy(d1[pos].name,doctorSearch("Modify"));

    gotoxy(18,4);
    cout<<".....Doctor Database Modify.....";
    gotoxy(18,5);
    cout<<"________________________________";
    gotoxy(18,6);
    cout<<"Doctor name :  ";

    cout<<d1[pos].name;
    gotoxy(18,7);
    cout<<"Doctor sex :  ";
    cin>>d1[pos].sex;
    gotoxy(18,8);
    cout<<"Doctor age :  ";
    cin>>d1[pos].age;
    gotoxy(18,9);
    cout<<"Doctor category :  ";
    cin>>d1[pos].category;
    gotoxy(18,10);
    cout<<"Doctor chamberNo :  ";
    cin>>d1[pos].chamberNo;
    gotoxy(18,11);
    cout<<"Doctor appointmentSchedule :  ";
    cin>>d1[pos].appointmentSchedule;
    gotoxy(18,12);
    cout<<"Doctor contactNo :  ";
    cin>>d1[pos].contactNo;
    gotoxy(18,15);
    cout<<"Press enter to continue ";
    doctorWrite();
}
void doctorDelete()
{
    int pos,j=doctorSize+9;
    doctorList();
    gotoxy(20,j);
    cout<<"-------------------------";
    j++;
    gotoxy(25,j);
    cout<<"Select your item :";
    j++;
    gotoxy(20,j);
    cout<<"-------------------------\n";
    j--;
    gotoxy(44,j);
    cin>>pos;
    system("cls");
    pos=pos-1;
    for(;pos<=doctorSize;pos++)
    {
        strcpy(d1[pos].name,d1[pos+1].name);
        strcpy(d1[pos].sex,d1[pos+1].sex);
        d1[pos].age=d1[pos+1].age;
        strcpy(d1[pos].category,d1[pos+1].category);
        strcpy(d1[pos].chamberNo,d1[pos+1].chamberNo);
        strcpy(d1[pos].appointmentSchedule,d1[pos+1].appointmentSchedule);
        strcpy(d1[pos].contactNo,d1[pos+1].contactNo);
    }
    doctorSize--;
    doctorWrite();
}
void doctorAdd()
{
    gotoxy(18,4);
    cout<<".....Doctor Database Add.....";
    gotoxy(18,5);
    cout<<"________________________________";
    int pos;
    doctorSize++;
    pos=doctorSize;
    gotoxy(18,6);
    cout<<"Doctor name :  ";
    strcpy(d1[pos].name,doctorSearch("Add"));

    gotoxy(18,4);
    cout<<".....Doctor Database Add.....";
    gotoxy(18,5);
    cout<<"________________________________";

    gotoxy(18,6);
    cout<<"Doctor name :  ";
    cout<<d1[pos].name<<endl;
    gotoxy(18,7);
    cout<<"Doctor sex :  ";
    cin>>d1[pos].sex;
    gotoxy(18,8);
    cout<<"Doctor age :  ";
    cin>>d1[pos].age;
    gotoxy(18,9);
    cout<<"Doctor category :  ";
    cin>>d1[pos].category;
    gotoxy(18,10);
    cout<<"Doctor chamberNo :  ";
    cin>>d1[pos].chamberNo;
    gotoxy(18,11);
    cout<<"Doctor appointmentSchedule :  ";
    cin>>d1[pos].appointmentSchedule;
    gotoxy(18,12);
    cout<<"Doctor contactNo :  ";
    cin>>d1[pos].contactNo;
    gotoxy(18,15);
    cout<<"Press enter to continue ";
    doctorWrite();
}
void doctorWrite()
{
    int i;
    FILE *fp,*fp1;
    fp=fopen("doctor.txt","wb");
    for(i=0;i<=doctorSize;i++)
    {
        fwrite(&d1[i],sizeof(d1[i]),1,fp);
    }
    fclose(fp);
    fp1=fopen("doctorSize.txt","w");
    fprintf(fp1,"%d",doctorSize);
    fclose(fp1);
}
void patientList()
{
    gotoxy(18,4);
    cout<<".....Patient Database list.....";
    gotoxy(18,5);
    cout<<"________________________________";
    gotoxy(24,6);
    cout<<" SL-NO    Patient Name";
    gotoxy(24,7);
    cout<<"------   -------------";
    int j=8;
    for(int i=0;i<=patientSize;i++){
        gotoxy(26,j);
        cout<<i+1<<".      "<<p1[i].name<<endl;
    j++;
    }
}
void patientList1()
{
    gotoxy(18,4);
    cout<<".....Patient Database list.....";
    gotoxy(18,5);
    cout<<"________________________________";
    gotoxy(24,6);
    cout<<" SL-NO    Patient Name";
    gotoxy(24,7);
    cout<<"------   -------------";
    int j=8;
    for(int i=0;i<=patientSize;i++){
        gotoxy(26,j);
        cout<<i+1<<".      "<<p1[i].name<<endl;
    j++;
    }
    int i;
    gotoxy(20,j);
    cout<<"-------------------------";
    j++;
    gotoxy(25,j);
    cout<<"Select your item :";
    j++;
    gotoxy(20,j);
    cout<<"-------------------------\n";
    j--;
    gotoxy(44,j);
    int pos;
    cin>>pos;
    system("cls");
    gotoxy(18,3);
    cout<<"......Patient Details Are.......";
    gotoxy(18,4);
    cout<<"________________________________";
    pos=pos-1;
    gotoxy(23,6);
    cout<<"Patient name :  "<<p1[pos].name<<endl;
    gotoxy(23,7);
    cout<<"Patient sex :  "<<p1[pos].sex<<endl;
    gotoxy(23,8);
    cout<<"Patient age :  "<<p1[pos].age<<endl;
    gotoxy(23,9);
    cout<<"Patient type :  "<<p1[pos].patientType<<endl;
    gotoxy(23,10);
    cout<<"Patient bloodGroup :  "<<p1[pos].bloodGroup<<endl;
    gotoxy(23,11);
    cout<<"Patient admission date :  "<<p1[pos].addmissionDate<<endl;
    gotoxy(23,12);
    cout<<"Patient assign doctor name :  "<<p1[pos].assignDoctorName<<endl;
    gotoxy(23,13);
    cout<<"Patient word name  :  "<<p1[pos].wardName<<endl;
    gotoxy(23,14);
    cout<<"Patient relation status :  "<<p1[pos].relationStatus<<endl;
    gotoxy(23,15);
    cout<<"Patient address :  "<<p1[pos].address<<endl;
    gotoxy(23,16);
    cout<<"Patient assign nurse name :  "<<p1[pos].assignNurseName<<endl;
    gotoxy(23,17);
    cout<<"Patient occupation  :  "<<p1[pos].occupation<<endl;
}
void patientModify()
{
    int i,pos,j=patientSize+9;
    patientList();
    gotoxy(20,j);
    cout<<"-------------------------";
    j++;
    gotoxy(25,j);
    cout<<"Select your item :";
    j++;
    gotoxy(20,j);
    cout<<"-------------------------\n";
    j--;
    gotoxy(44,j);
    cin>>pos;
    pos=pos-1;
    system("cls");
    gotoxy(18,3);
    cout<<"....Patient Database Modify.....";
    gotoxy(18,4);
    cout<<"________________________________";
    gotoxy(18,5);
    cout<<"Patient name :  ";
    cin>>p1[pos].name;
    gotoxy(18,6);
    cout<<"Patient sex :  ";
    cin>>p1[pos].sex;
    gotoxy(18,7);
    cout<<"Patient age :  ";
    cin>>p1[pos].age;
    gotoxy(18,8);
    cout<<"Patient type :  ";
    cin>>p1[pos].patientType;
    gotoxy(18,9);
    cout<<"Patient bloodGroup :  ";
    cin>>p1[pos].bloodGroup;
    gotoxy(18,10);
    cout<<"Patient addmission date :  ";
    cin>>p1[pos].addmissionDate;
    gotoxy(18,11);
    cout<<"Patient assign doctor name :  ";
    system("cls");

    strcpy(p1[pos].assignDoctorName,doctorSearch1(pos,"Modify"));
    gotoxy(18,3);
    cout<<"....Patient Database Modify.....";
    gotoxy(18,4);
    cout<<"________________________________";
    patientSearchDesign1(pos);
    cout<<p1[pos].assignDoctorName;

    gotoxy(18,12);
    cout<<"Patient word name  :  ";
    cin>>p1[pos].wardName;
    gotoxy(18,13);
    cout<<"Patient relation status :  ";
    cin>>p1[pos].relationStatus;
    gotoxy(18,14);
    cout<<"Patient address :  ";
    cin>>p1[pos].address;
    gotoxy(18,15);
    cout<<"Patient assign nurse name :  ";
    system("cls");
    strcpy(p1[pos].assignNurseName,nurseSearch1(pos,"Modify"));

    gotoxy(18,3);
    cout<<"....Patient Database Modify.....";
    gotoxy(18,4);
    cout<<"________________________________";
    gotoxy(18,5);
    patientSearchDesign2(pos);
    cout<<p1[pos].assignNurseName;


    gotoxy(18,16);
    cout<<"Patient occupation  :  ";
    cin>>p1[pos].occupation;
    gotoxy(18,19);
    cout<<"Press enter to continue :";
    patientWrite();
}
void patientDelete()
{
    int pos,j=patientSize+9;
    patientList();
    gotoxy(20,j);
    cout<<"-------------------------";
    j++;
    gotoxy(25,j);
    cout<<"Select your item :";
    j++;
    gotoxy(20,j);
    cout<<"-------------------------\n";
    j--;
    gotoxy(44,j);
    cin>>pos;
    pos=pos-1;
    for(;pos<=patientSize;pos++)
    {
        strcpy(p1[pos].name,p1[pos+1].name);
        strcpy(p1[pos].sex,p1[pos+1].sex);
        p1[pos].age=p1[pos+1].age;
        strcpy(p1[pos].patientType,p1[pos+1].patientType);
        strcpy(p1[pos].bloodGroup,p1[pos+1].bloodGroup);
        strcpy(p1[pos].addmissionDate,p1[pos+1].addmissionDate);
        strcpy(p1[pos].assignDoctorName,p1[pos+1].assignDoctorName);
        strcpy(p1[pos].wardName,p1[pos+1].wardName);
        strcpy(p1[pos].relationStatus,p1[pos+1].relationStatus);
        strcpy(p1[pos].address,p1[pos+1].address);
        strcpy(p1[pos].assignNurseName,p1[pos+1].assignNurseName);
        strcpy(p1[pos].occupation,p1[pos+1].occupation);
    }
    gotoxy(20,j+4);
    cout<<"Press enter to continue :";
    patientSize--;
    patientWrite();
}
void patientAdd()
{
    gotoxy(18,3);
    cout<<".....Patient Database Add.....";
    gotoxy(18,4);
    cout<<"________________________________";
    int pos;
    patientSize++;
    pos=patientSize;


    gotoxy(18,5);
    cout<<"Patient name :  ";
    cin>>p1[pos].name;
    gotoxy(18,6);
    cout<<"Patient sex :  ";
    cin>>p1[pos].sex;
    gotoxy(18,7);
    cout<<"Patient age :  ";
    cin>>p1[pos].age;
    gotoxy(18,8);
    cout<<"Patient type :  ";
    cin>>p1[pos].patientType;
    gotoxy(18,9);
    cout<<"Patient bloodGroup :  ";
    cin>>p1[pos].bloodGroup;
    gotoxy(18,10);
    cout<<"Patient addmission date :  ";
    cin>>p1[pos].addmissionDate;
    gotoxy(18,11);
    cout<<"Patient assign doctor name :  ";
    system("cls");

    strcpy(p1[pos].assignDoctorName,doctorSearch1(pos,"Add"));
    gotoxy(18,3);
    cout<<"....Patient Database Add.....";
    gotoxy(18,4);
    cout<<"________________________________";
    patientSearchDesign1(pos);
    cout<<p1[pos].assignDoctorName;

    gotoxy(18,12);
    cout<<"Patient word name  :  ";
    cin>>p1[pos].wardName;
    gotoxy(18,13);
    cout<<"Patient relation status :  ";
    cin>>p1[pos].relationStatus;
    gotoxy(18,14);
    cout<<"Patient address :  ";
    cin>>p1[pos].address;
    gotoxy(18,15);
    cout<<"Patient assign nurse name :  ";
    system("cls");
    strcpy(p1[pos].assignNurseName,nurseSearch1(pos,"Add"));

    gotoxy(18,3);
    cout<<"....Patient Database Add.....";
    gotoxy(18,4);
    cout<<"________________________________";
    gotoxy(18,5);
    patientSearchDesign2(pos);
    cout<<p1[pos].assignNurseName;


    gotoxy(18,16);
    cout<<"Patient occupation  :  ";
    cin>>p1[pos].occupation;
    gotoxy(18,19);
    cout<<"Press enter to continue :";
    patientWrite();



    /*gotoxy(18,6);
    cout<<"Patient name :  ";
    cin>>p1[pos].name;
    gotoxy(18,7);
    cout<<"Patient sex :  ";
    cin>>p1[pos].sex;
    gotoxy(18,8);
    cout<<"Patient age :  ";
    cin>>p1[pos].age;
    gotoxy(18,9);
    cout<<"Patient type :  ";
    cin>>p1[pos].patientType;
    gotoxy(18,10);
    cout<<"Patient bloodGroup :  ";
    cin>>p1[pos].bloodGroup;
    gotoxy(18,11);
    cout<<"Patient addmission date :  ";
    cin>>p1[pos].addmissionDate;
    gotoxy(18,12);
    cout<<"Patient assign doctor name :  ";
    //getch();
    //system("cls");

    //char *s;
    //s=doctorSearch1(pos);
    //strcpy(p1[pos].assignDoctorName,s);

    gotoxy(18,3);
    cout<<"....Patient Database Add.....";
    gotoxy(18,4);
    cout<<"________________________________";
    //gotoxy(18,5);
    patientSearchDesign1(pos);

    gotoxy(18,12);
    cout<<"Patient word name  :  ";
    cin>>p1[pos].wardName;
    gotoxy(18,13);
    cout<<"Patient relation status :  ";
    cin>>p1[pos].relationStatus;
    gotoxy(18,14);
    cout<<"Patient address :  ";
    cin>>p1[pos].address;
    gotoxy(18,15);
    cout<<"Patient assign nurse name :  ";
    getch();
    system("cls");
    //s=nurseSearch();
    //strcpy(p1[pos].assignNurseName,s);

    gotoxy(18,3);
    cout<<"....Patient Database Add.....";
    gotoxy(18,4);
    cout<<"________________________________";
    gotoxy(18,5);
    patientSearchDesign2(pos);


    gotoxy(18,16);
    cout<<"patient occupation :  ";
    cin>>p1[pos].occupation;
    gotoxy(18,19);
    cout<<"Press enter to continue ";
    patientWrite();*/
}
void patientWrite()
{
    int i;
    FILE *fp,*fp1;
    fp=fopen("patient.txt","wb");
    for(i=0;i<=patientSize;i++)
    {
        fwrite(&p1[i],sizeof(p1[i]),1,fp);
    }
    fclose(fp);
    fp1=fopen("patientSize.txt","w");
    fprintf(fp1,"%d",patientSize);
    fclose(fp1);
}
void nurseList()
{
    gotoxy(18,4);
    cout<<".....Nurse Database list.....";
    gotoxy(18,5);
    cout<<"________________________________";
    gotoxy(24,6);
    cout<<" SL-NO    Nurse Name";
    gotoxy(24,7);
    cout<<"------   -------------";
    int j=8;
    for(int i=0;i<=nurseSize;i++){
        gotoxy(20,j);
        cout<<i+1<<".  "<<n1[i].name<<endl;
    j++;
    }
}
void nurseList1()
{
    gotoxy(18,4);
    cout<<".....Nurse Database list.....";
    gotoxy(18,5);
    cout<<"________________________________";
    gotoxy(24,6);
    cout<<" SL-NO    Nurse Name";
    gotoxy(24,7);
    cout<<"------   -------------";
    int j=8;
    for(int i=0;i<=nurseSize;i++){
        gotoxy(20,j);
        cout<<i+1<<".  "<<n1[i].name<<endl;
    j++;
    }
    int i;
    gotoxy(20,j);
    cout<<"-------------------------";
    j++;
    gotoxy(25,j);
    cout<<"Select your item :";
    j++;
    gotoxy(20,j);
    cout<<"-------------------------\n";
    j--;
    gotoxy(44,j);
    int pos;
    cin>>pos;
    system("cls");
    gotoxy(18,3);
    cout<<"......Nurse Details Are.......";
    gotoxy(18,4);
    cout<<"________________________________";
    pos=pos-1;
    gotoxy(23,6);
    cout<<"Nurse name :  "<<n1[pos].name<<endl;
    gotoxy(23,7);
    cout<<"Nurse sex :  "<<n1[pos].sex<<endl;
    gotoxy(23,8);
    cout<<"Nurse age :  "<<n1[pos].age<<endl;
    gotoxy(23,9);
    cout<<"Nurse study :  "<<n1[pos].study<<endl;
    gotoxy(23,10);
    cout<<"Nurse skil :  "<<n1[pos].skil<<endl;
    gotoxy(23,13);
    cout<<"Press enter to continue ";
}
void nurseModify()
{
    int i,pos,j=nurseSize+9;
    nurseList();
    gotoxy(20,j);
    cout<<"-------------------------";
    j++;
    gotoxy(25,j);
    cout<<"Select your item :";
    j++;
    gotoxy(20,j);
    cout<<"-------------------------\n";
    j--;
    gotoxy(44,j);
    cin>>pos;
    system("cls");
    gotoxy(18,3);
    cout<<"....Nurse Database Modify....";
    gotoxy(18,4);
    cout<<"________________________________";
    pos=pos-1;
    gotoxy(18,5);
    cout<<"Nurse name :  ";
    cin>>n1[pos].name;
    gotoxy(18,6);
    cout<<"Nurse sex :  ";
    cin>>n1[pos].sex;
    gotoxy(18,7);
    cout<<"Nurse age :  ";
    cin>>n1[pos].age;
    gotoxy(18,8);
    cout<<"Nurse study :  ";
    cin>>n1[pos].study;
    gotoxy(18,9);
    cout<<"Nurse skill :  ";
    cin>>n1[pos].skil;
    gotoxy(18,12);
    cout<<"Press enter to continue :";
    nurseWrite();
}
void nurseDelete()
{
    int pos,j=nurseSize+9;
    nurseList();
    gotoxy(20,j);
    cout<<"-------------------------";
    j++;
    gotoxy(25,j);
    cout<<"Select your item :";
    j++;
    gotoxy(20,j);
    cout<<"-------------------------\n";
    j--;
    gotoxy(44,j);
    cin>>pos;
    pos=pos-1;
    for(;pos<=nurseSize;pos++)
    {
        strcpy(n1[pos].name,n1[pos+1].name);
        strcpy(n1[pos].sex,n1[pos+1].sex);
        n1[pos].age=n1[pos+1].age;
        strcpy(n1[pos].study,n1[pos+1].study);
        strcpy(n1[pos].skil,n1[pos+1].skil);
    }
    gotoxy(20,j+4);
    cout<<"Press enter to continue ";
    nurseSize--;
    nurseWrite();
}
void nurseAdd()
{
    gotoxy(18,4);
    cout<<".....Nurse Database Add.....";
    gotoxy(18,5);
    cout<<"________________________________";
    int pos;
    nurseSize++;
    pos=nurseSize;
    gotoxy(18,6);
    cout<<"nurse name :  ";
    cin>>n1[pos].name;
    gotoxy(18,7);
    cout<<"nurse sex :  ";
    cin>>n1[pos].sex;
    gotoxy(18,8);
    cout<<"nurse age :  ";
    cin>>n1[pos].age;
    gotoxy(18,9);
    cout<<"nurse study :  ";
    cin>>n1[pos].study;
    gotoxy(18,10);
    cout<<"nurse skill :  ";
    cin>>n1[pos].skil;
    gotoxy(18,13);
    cout<<"Press enter to continue :";
    nurseWrite();
}
void nurseWrite()
{
    int i;
    FILE *fp,*fp1;
    fp=fopen("nurse.txt","wb");
    for(i=0;i<=doctorSize;i++)
    {
        fwrite(&n1[i],sizeof(n1[i]),1,fp);
    }
    fclose(fp);
    fp1=fopen("nurseSize.txt","w");
    fprintf(fp1,"%d",nurseSize);
    fclose(fp1);
}
void gotoxy(int x,int y)
{
    COORD ord;
    ord.X = x;
    ord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),ord);

}
void design()
{
    gotoxy(20,10);
    cout<<"-------------------------";
    gotoxy(25,11);
    cout<<"Select your item :";
    gotoxy(20,12);
    cout<<"-------------------------\n";

}
int wherex()
  {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  if (!GetConsoleScreenBufferInfo(
         GetStdHandle( STD_OUTPUT_HANDLE ),
         &csbi
         ))
    return -1;
  return csbi.dwCursorPosition.X;
  }

int wherey()
  {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  if (!GetConsoleScreenBufferInfo(
         GetStdHandle( STD_OUTPUT_HANDLE ),
         &csbi
         ))
    return -1;
  return csbi.dwCursorPosition.Y;
  }
void doctorDesign()
{
    gotoxy(18,4);
    cout<<"AosNillSetua Hospital Management";
    gotoxy(18,5);
    cout<<"________________________________";
    gotoxy(27,7);
    cout<<"1. doctor List";
    gotoxy(27,8);
    cout<<"2. doctor modify";
    gotoxy(27,9);
    cout<<"3. doctor delete";
    gotoxy(27,10);
    cout<<"4. doctor add\n";
}
void nurseDesign()
{
    gotoxy(18,4);
    cout<<"AosNillSetua Hospital Management";
    gotoxy(18,5);
    cout<<"________________________________";
    gotoxy(27,7);
    cout<<"1. nurse List";
    gotoxy(27,8);
    cout<<"2. nurse modify";
    gotoxy(27,9);
    cout<<"3. nurse delete";
    gotoxy(27,10);
    cout<<"4. nurse add\n";
}
void patientDesign()
{
    gotoxy(18,4);
    cout<<"AosNillSetua Hospital Management";
    gotoxy(18,5);
    cout<<"________________________________";
    gotoxy(27,7);
    cout<<"1. patient List";
    gotoxy(27,8);
    cout<<"2. patient modify";
    gotoxy(27,9);
    cout<<"3. patient delete";
    gotoxy(27,10);
    cout<<"4. patient add\n";
}
void design1()
{
    gotoxy(20,12);
    cout<<"-------------------------";
    gotoxy(25,13);
    cout<<"Select your item :";
    gotoxy(20,14);
    cout<<"-------------------------\n";
}
char *doctorSearch(string z)
{
    int j=0;
    char ch;
    char a[32];
    while(1)
    {
        gotoxy(18,4);
        cout<<".....Doctor Database "<<z<<".....";
        gotoxy(18,5);
        cout<<"________________________________";
        gotoxy(18,6);
        cout<<"Doctor name :  ";
        gotoxy(j+33,6);
        int i,k,l;
        int flag=0;
        int n=0;
        ch=getch();
        system("cls");
        if(ch==8)
        {
            j--;
            system("cls");
            gotoxy(33,6);
            for(k=0;k<j;k++)
            cout<<a[k];
            j--;
            if(j<0)
                j=-1;
        }
        else if(ch==13){
            a[j]=NULL;
            break;
        }
        else{
            a[j]=ch;
        }
        gotoxy(j+33,6);
        cout<<ch;
        gotoxy(33,7);
        cout<<"--------\n";
        for(k=0;k<=10;k++)
        {
            for(l=0;l<=j;l++)
            {
                if(a[l]!=d1[k].name[l])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                gotoxy(33,n+8);
                cout<<d1[k].name<<endl;
                n++;
            }
            flag=0;
        }
        gotoxy(33,6);
        for(k=0;k<j;k++)
            cout<<a[k];
        j++;
    }
    return a;
}
char *doctorSearch1(int pos,string z)
{
    int j=0;
    char ch;
    char a[32];
    while(1)
    {
        gotoxy(18,3);
        cout<<"....Patient Database "<<z<<".....";
        gotoxy(18,4);
        cout<<"________________________________";
        gotoxy(18,5);
        patientSearchDesign1(pos);
        gotoxy(j+48,11);
        int i,k,l;
        int flag=0;
        int n=0;
        ch=getch();
        system("cls");
        if(ch==8)
        {
            j--;
            system("cls");
            gotoxy(48,11);
            for(k=0;k<j;k++)
            cout<<a[k];
            j--;
            if(j<0)
                j=-1;
        }
        else if(ch==13){
            a[j]=NULL;
            break;
        }
        else{
            a[j]=ch;
        }
        gotoxy(j+48,11);
        cout<<ch;
        gotoxy(48,12);
        cout<<"--------\n";
        for(k=0;k<=10;k++)
        {
            for(l=0;l<=j;l++)
            {
                if(a[l]!=d1[k].name[l])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                gotoxy(48,n+13);
                cout<<d1[k].name<<endl;
                n++;
            }
            flag=0;
        }
        gotoxy(48,11);
        for(k=0;k<j;k++)
            cout<<a[k];
        j++;
    }
    return a;
}
void patientSearchDesign1(int pos)
{
    gotoxy(18,5);
    cout<<"Patient name :  ";
    cout<<p1[pos].name;
    gotoxy(18,6);
    cout<<"Patient sex :  ";
    cout<<p1[pos].sex;
    gotoxy(18,7);
    cout<<"Patient age :  ";
    cout<<p1[pos].age;
    gotoxy(18,8);
    cout<<"Patient type :  ";
    cout<<p1[pos].patientType;
    gotoxy(18,9);
    cout<<"Patient bloodGroup :  ";
    cout<<p1[pos].bloodGroup;
    gotoxy(18,10);
    cout<<"Patient addmission date :  ";
    cout<<p1[pos].addmissionDate;
    gotoxy(18,11);
    cout<<"Patient assign doctor name :  ";
}
void patientSearchDesign2(int pos)
{
    int i,j=patientSize+9;
    cout<<"Patient name :  ";
    cout<<p1[pos].name;
    gotoxy(18,6);
    cout<<"Patient sex :  ";
    cout<<p1[pos].sex;
    gotoxy(18,7);
    cout<<"Patient age :  ";
    cout<<p1[pos].age;
    gotoxy(18,8);
    cout<<"Patient type :  ";
    cout<<p1[pos].patientType;
    gotoxy(18,9);
    cout<<"Patient bloodGroup :  ";
    cout<<p1[pos].bloodGroup;
    gotoxy(18,10);
    cout<<"Patient addmission date :  ";
    cout<<p1[pos].addmissionDate;
    gotoxy(18,11);
    cout<<"Patient assign doctor name :  ";
    cout<<p1[pos].assignDoctorName;
    gotoxy(18,12);
    cout<<"Patient word name  :  ";
    cout<<p1[pos].wardName;
    gotoxy(18,13);
    cout<<"Patient relation status :  ";
    cout<<p1[pos].relationStatus;
    gotoxy(18,14);
    cout<<"Patient address :  ";
    cout<<p1[pos].address;
    gotoxy(18,15);
    cout<<"Patient assign nurse name :  ";
}
char *nurseSearch1(int pos,string z)
{
    int j=0;
    char ch;
    char a[32];
    while(1)
    {
        gotoxy(18,3);
        cout<<"....Patient Database "<<z<<".....";
        gotoxy(18,4);
        cout<<"________________________________";
        gotoxy(18,5);
        patientSearchDesign2(pos);
        gotoxy(j+47,15);
        int i,k,l;
        int flag=0;
        int n=0;
        ch=getch();
        system("cls");
        if(ch==8)
        {
            j--;
            system("cls");
            gotoxy(47,15);
            for(k=0;k<j;k++)
            cout<<a[k];
            j--;
            if(j<0)
                j=-1;
        }
        else if(ch==13){
            a[j]=NULL;
            break;
        }
        else{
            a[j]=ch;
        }
        gotoxy(j+47,15);
        cout<<ch;
        gotoxy(47,16);
        cout<<"--------\n";
        for(k=0;k<=10;k++)
        {
            for(l=0;l<=j;l++)
            {
                if(a[l]!=n1[k].name[l])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                gotoxy(47,n+17);
                cout<<n1[k].name<<endl;
                n++;
            }
            flag=0;
        }
        gotoxy(47,15);
        for(k=0;k<j;k++)
            cout<<a[k];
        j++;
    }
    return a;
}
