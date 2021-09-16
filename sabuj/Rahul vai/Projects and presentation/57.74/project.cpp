#include <stdio.h>
void cse1();
void eee1();
void bba1();
void addCse();
void addEee();
void addBba();
void cseWrite();
void eeeWrite();
void bbaWrite();
void modifyCse();
void modifyEee();
void modifyBba();
void deleteCse();
void deleteEee();
void deleteBba();
int cseSize,eeeSize,bbaSize;
struct student
{
    char studentName[32];
    char studentId[15];
    char studentGender[15];
    char departmentName[32];
    char studentLevel[15];
    char studentSection[12];
    char studentAddress[32];
    char studentCurrentCGPA[15];
    char studentBloodGroup[15];
    char studentPassSSC[15];
    char studentPassHSC[15];
    char advisorName[32];
}cse[151],eee[151],bba[151];
int main()
{
    FILE *fp,*fp1;
    int i,j,k;
    fp=fopen("cseSize.txt","r");
    fscanf(fp,"%d",&cseSize);
    fclose(fp);
    fp=fopen("eeeSize.txt","r");
    fscanf(fp,"%d",&eeeSize);
    fclose(fp);
    fp=fopen("bbaSize.txt","r");
    fscanf(fp,"%d",&bbaSize);
    fclose(fp);
    char ch,s1[100];
    fp=fopen("bba.txt","r");
    for(i=0;i<bbaSize;i++)
    {
        fscanf(fp,"%s%s%s%s%s%s%s%s%s%s%s%s",bba[i].studentName,bba[i].studentId,bba[i].studentGender,bba[i].departmentName,bba[i].studentLevel,bba[i].studentSection,bba[i].studentAddress,bba[i].studentCurrentCGPA,bba[i].studentBloodGroup,bba[i].studentPassSSC,bba[i].studentPassHSC,bba[i].advisorName);
    }
    fclose(fp);
    fp=fopen("eee.txt","r");
    for(i=0;i<eeeSize;i++)
    {
        fscanf(fp,"%s%s%s%s%s%s%s%s%s%s%s%s",eee[i].studentName,eee[i].studentId,eee[i].studentGender,eee[i].departmentName,eee[i].studentLevel,eee[i].studentSection,eee[i].studentAddress,eee[i].studentCurrentCGPA,eee[i].studentBloodGroup,eee[i].studentPassSSC,eee[i].studentPassHSC,eee[i].advisorName);
    }
    fclose(fp);
    fp=fopen("cse.txt","r");
    for(i=0;i<cseSize;i++)
    {
        fscanf(fp,"%s%s%s%s%s%s%s%s%s%s%s%s",cse[i].studentName,cse[i].studentId,cse[i].studentGender,cse[i].departmentName,cse[i].studentLevel,cse[i].studentSection,cse[i].studentAddress,cse[i].studentCurrentCGPA,cse[i].studentBloodGroup,cse[i].studentPassSSC,cse[i].studentPassHSC,cse[i].advisorName);
    }
    fclose(fp);
    while(1)
    {
        printf("    Choose your Department\n\n\n    1.cse\n    2.eee\n    3.bba\n    select your item : ");
        scanf("%d",&i);
        switch(i)
        {
            case 1:printf("    select your need \n\n\n    1.cse student list\n    2.cse student Add\n    3.cse student modify\n    3.cse student delete\n    select your item : ");
                scanf("%d",&j);switch(j){
                    case 1:cse1();break;
                    case 2:addCse();break;
                    case 3:modifyCse();break;
                    //case 4:deleteCse();
                    default:printf("Wrong Selection\n");break;
                    }break;
            case 2:printf("    select your need \n\n\n    1.eee student list\n    2.eee student Add\n    3.eee student modify\n    3.eee student delete\n    select your item : ");
                    scanf("%d",&j);switch(j){
                    case 1:eee1();break;
                    case 2:addEee();break;
                    case 3:modifyEee();break;
                    //case 4:deleteEee();break;
                    default:printf("Wrong Selection\n");break;
                    }break;
            case 3:printf("    select your need \n\n\n    1.bba student list\n    2.bba student Add\n    3.bba student modify\n    3.bba student delete\n    select your item : ");
                    scanf("%d",&j);switch(j){
                    case 1:bba1();break;
                    case 2:addBba();break;
                    case 3:modifyBba();break;
                    //case 4:deletbbae();break;
                    default:printf("Wrong Selection\n");break;
                    }break;
            default:printf("Wrong Selection\n");break;
        }
        getchar();
        getchar();
    }
    return 0;
}
void cse1()
{
    int i;
    for(i=0;i<cseSize;i++)
        printf("    %d . %s\n",i+1,cse[i].studentName);
    scanf("%d",&i);
    i=i-1;
    printf("%s %s %s %s %s %s %s %s %s %s %s %s \n",cse[i].studentName,cse[i].studentId,cse[i].studentGender,cse[i].departmentName,cse[i].studentLevel,cse[i].studentSection,cse[i].studentAddress,cse[i].studentCurrentCGPA,cse[i].studentBloodGroup,cse[i].studentPassSSC,cse[i].studentPassHSC,cse[i].advisorName);
}
void eee1()
{
    int i;
    for(i=0;i<eeeSize;i++)
        printf("    %d . %s\n",i+1,eee[i].studentName);
    scanf("%d",&i);
    i=i-1;
    printf("%s %s %s %s %s %s %s %s %s %s %s %s \n",eee[i].studentName,eee[i].studentId,eee[i].studentGender,eee[i].departmentName,eee[i].studentLevel,eee[i].studentSection,eee[i].studentAddress,eee[i].studentCurrentCGPA,eee[i].studentBloodGroup,eee[i].studentPassSSC,eee[i].studentPassHSC,eee[i].advisorName);
}
void bba1()
{
    int i;
    for(i=0;i<bbaSize;i++)
        printf("    %d . %s\n",i+1,bba[i].studentName);
    scanf("%d",&i);
    i=i-1;
    printf("%s %s %s %s %s %s %s %s %s %s %s %s \n",bba[i].studentName,bba[i].studentId,bba[i].studentGender,bba[i].departmentName,bba[i].studentLevel,bba[i].studentSection,bba[i].studentAddress,bba[i].studentCurrentCGPA,bba[i].studentBloodGroup,bba[i].studentPassSSC,bba[i].studentPassHSC,bba[i].advisorName);
}

void addCse()
{
    int i=cseSize;
    scanf("%s%s%s%s%s%s%s%s%s%s%s%s",&cse[i].studentName,&cse[i].studentId,&cse[i].studentGender,&cse[i].departmentName,&cse[i].studentLevel,&cse[i].studentSection,&cse[i].studentAddress,&cse[i].studentCurrentCGPA,&cse[i].studentBloodGroup,&cse[i].studentPassSSC,&cse[i].studentPassHSC,&cse[i].advisorName);
    cseSize++;
    cseWrite();
}
void addEee()
{
    int i=eeeSize;
    scanf("%s%s%s%s%s%s%s%s%s%s%s%s",&eee[i].studentName,&eee[i].studentId,&eee[i].studentGender,&eee[i].departmentName,&eee[i].studentLevel,&eee[i].studentSection,&eee[i].studentAddress,&eee[i].studentCurrentCGPA,&eee[i].studentBloodGroup,&eee[i].studentPassSSC,&eee[i].studentPassHSC,&eee[i].advisorName);
    eeeSize++;
    eeeWrite();
}
void addBba()
{
    int i=bbaSize;
    scanf("%s%s%s%s%s%s%s%s%s%s%s%s",&bba[i].studentName,&bba[i].studentId,&bba[i].studentGender,&bba[i].departmentName,&bba[i].studentLevel,&bba[i].studentSection,&bba[i].studentAddress,&bba[i].studentCurrentCGPA,&bba[i].studentBloodGroup,&bba[i].studentPassSSC,&bba[i].studentPassHSC,&bba[i].advisorName);
    bbaSize++;
    bbaWrite();
}
void cseWrite()
{
    FILE *fp;
    fp=fopen("cse.txt","w");
    for(int i=0;i<cseSize;i++)
    {
        fprintf(fp,"%s %s %s %s %s %s %s %s %s %s %s %s ",cse[i].studentName,cse[i].studentId,cse[i].studentGender,cse[i].departmentName,cse[i].studentLevel,cse[i].studentSection,cse[i].studentAddress,cse[i].studentCurrentCGPA,cse[i].studentBloodGroup,cse[i].studentPassSSC,cse[i].studentPassHSC,cse[i].advisorName);
    }
    fclose(fp);
    fp=fopen("cseSize.txt","w");
    fprintf(fp,"%d",cseSize);
    fclose(fp);
}
void eeeWrite()
{
    FILE *fp;
    fp=fopen("eee.txt","w+");
    for(int i=0;i<eeeSize;i++)
    {
        fprintf(fp,"%s %s %s %s %s %s %s %s %s %s %s %s ",eee[i].studentName,eee[i].studentId,eee[i].studentGender,eee[i].departmentName,eee[i].studentLevel,eee[i].studentSection,eee[i].studentAddress,eee[i].studentCurrentCGPA,eee[i].studentBloodGroup,eee[i].studentPassSSC,eee[i].studentPassHSC,eee[i].advisorName);
    }
    fclose(fp);
    fp=fopen("eeeSize.txt","w");
    fprintf(fp,"%d",eeeSize);
    fclose(fp);
}
void bbaWrite()
{
    FILE *fp;
    fp=fopen("bba.txt","w+");
    for(int i=0;i<bbaSize;i++)
    {
        fprintf(fp,"%s %s %s %s %s %s %s %s %s %s %s %s ",bba[i].studentName,bba[i].studentId,bba[i].studentGender,bba[i].departmentName,bba[i].studentLevel,bba[i].studentSection,bba[i].studentAddress,bba[i].studentCurrentCGPA,bba[i].studentBloodGroup,bba[i].studentPassSSC,bba[i].studentPassHSC,bba[i].advisorName);
    }
    fclose(fp);
    fp=fopen("bbaSize.txt","w");
    fprintf(fp,"%d",bbaSize);
    fclose(fp);
}
void modifyCse()
{
    int i;
    for(i=0;i<cseSize;i++)
        printf("    %d . %s\n",i+1,cse[i].studentName);
    scanf("%d",&i);
    i=i-1;
    scanf("%s%s%s%s%s%s%s%s%s%s%s%s",&cse[i].studentName,&cse[i].studentId,&cse[i].studentGender,&cse[i].departmentName,&cse[i].studentLevel,&cse[i].studentSection,&cse[i].studentAddress,&cse[i].studentCurrentCGPA,&cse[i].studentBloodGroup,&cse[i].studentPassSSC,&cse[i].studentPassHSC,&cse[i].advisorName);
    cseWrite();
}
void modifyEee()
{
    int i;
    for(i=0;i<eeeSize;i++)
        printf("    %d . %s\n",i+1,eee[i].studentName);
    scanf("%d",&i);
    i=i-1;
    scanf("%s%s%s%s%s%s%s%s%s%s%s%s",&eee[i].studentName,&eee[i].studentId,&eee[i].studentGender,&eee[i].departmentName,&eee[i].studentLevel,&eee[i].studentSection,&eee[i].studentAddress,&eee[i].studentCurrentCGPA,&eee[i].studentBloodGroup,&eee[i].studentPassSSC,&eee[i].studentPassHSC,&eee[i].advisorName);
    eeeWrite();
}
void modifyBba()
{
    int i;
    for(i=0;i<bbaSize;i++)
        printf("    %d . %s\n",i+1,bba[i].studentName);
    scanf("%d",&i);
    i=i-1;
    scanf("%s%s%s%s%s%s%s%s%s%s%s%s",&bba[i].studentName,&bba[i].studentId,&bba[i].studentGender,&bba[i].departmentName,&bba[i].studentLevel,&bba[i].studentSection,&bba[i].studentAddress,&bba[i].studentCurrentCGPA,&bba[i].studentBloodGroup,&bba[i].studentPassSSC,&bba[i].studentPassHSC,&bba[i].advisorName);
    bbaWrite();
}
void deleteCse()
{
    int i;
    for(i=0;i<cseSize;i++)
        printf("    %d . %s\n",i+1,cse[i].studentName);
    scanf("%d",&i);
    i=i-1;
}
void deleteEee()
{
    int i;
    for(i=0;i<eeeSize;i++)
        printf("    %d . %s\n",i+1,eee[i].studentName);
    scanf("%d",&i);
    i=i-1;
}
void deleteBba()
{
    int i;
    for(i=0;i<bbaSize;i++)
        printf("    %d . %s\n",i+1,bba[i].studentName);
    scanf("%d",&i);
    i=i-1;
}
