
#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;

int main()
{
    FILE *fp, *ft;
    char another, choice;

    struct student
    {
        char first_name[50], last_name[50];
        char course[100];
        int section;
    };

    struct student e;
    char xfirst_name[50], xlast_name[50];
    long int recsize;

    fp=fopen("users.txt","rb+");

    if (fp == NULL)
    {
        fp = fopen("users.txt","wb+");

        if (fp==NULL)
        {
            puts("Cannot open file");
            return 0;
        }
    }


    recsize = sizeof(e);

    while(1)
    {
        system("cls");

        cout << "\t\t====== STUDENT DATABASE MANAGEMENT SYSTEM ======";
        cout <<"\n\n                                          ";
        cout << "\n\n";
        cout << "\n \t\t\t 1. Add    Data";
        cout << "\n \t\t\t 2. List   Data";
        cout << "\n \t\t\t 3. Modify Data";
        cout << "\n \t\t\t 4. Delete Data";
        cout << "\n \t\t\t 5. Exit   Data";
        cout << "\n\n";
        cout << "\t\t\t Select any one (1,2,3,4,5) :=> ";
        fflush(stdin);
        choice = getche();
        switch(choice)
        {
        case '1' :
            fseek(fp,0,SEEK_END);
            another ='Y';
            while(another == 'Y' || another == 'y')
            {
                system("cls");
                cout << "Enter student's Firt Name : ";
                cin >> e.first_name;
                cout << "Enter student's Last Name : ";
                cin >> e.last_name;
                cout << "Enter student's Course    : ";
                cin >> e.course;
                cout << "Enter student's Section   : ";
                cin >> e.section;
                fwrite(&e,recsize,1,fp);
                cout << "\n Add Another Data? (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            break;
        case '2':
            system("cls");
            rewind(fp);
            cout << "=== View the Data in the Database ===";
            cout << "\n";
            while (fread(&e,recsize,1,fp) == 1)
            {
                cout << "\n";
                cout <<"\n" << e.first_name <<" "<< e.last_name;
                cout << "\n";
                cout <<"\n" <<e.course <<" "<< e.section;
            }
            cout << "\n\n";
            system("pause");
            break;

        case '3' :
            system("cls");
            another = 'Y';
            while (another == 'Y'|| another == 'y')
            {
                cout << "\n Enter the last name of the student : ";
                cin >> xlast_name;

                rewind(fp);
                while (fread(&e,recsize,1,fp) == 1)
                {
                    if (strcmp(e.last_name,xlast_name) == 0)
                    {
                        cout << "Enter the new Firt Name : ";
                        cin >> e.first_name;
                        cout << "Enter the new Last Name : ";
                        cin >> e.last_name;
                        cout << "Enter the new Course    : ";
                        cin >> e.course;
                        cout << "Enter the new Section   : ";
                        cin >> e.section;
                        fseek(fp, - recsize, SEEK_CUR);
                        fwrite(&e,recsize,1,fp);
                        break;
                    }
                    else
                        cout<<"record not found";
                }
                cout << "\n Modify Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            break;


        case '4':
            system("cls");
            another = 'Y';
            while (another == 'Y'|| another == 'y')
            {
                cout << "\n Enter the last name of the student to delete : ";
                cin >> xlast_name;

                ft = fopen("temp.dat", "wb");

                rewind(fp);
                while (fread (&e, recsize,1,fp) == 1)

                    if (strcmp(e.last_name,xlast_name) != 0)
                    {
                        fwrite(&e,recsize,1,ft);
                    }
                fclose(fp);
                fclose(ft);
                remove("users.txt");
                rename("temp.dat","users.txt");

                fp=fopen("users.txt","rb+");

                cout << "\n Delete Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }

            break;

        case '5':
            fclose(fp);
            cout << "\n\n";
            cout << "\t\t     Thank you for using this software !!\n\t\tAdios !!";
            cout << "\n\n";
            exit(0);
        }
    }


    system("pause");
    return 0;
}
