#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;
#define size 7
#define number 5
#define seats 10

int p = 0;
class bus
{
public:
    char bus_num[size], driver[size], depart[size], arrival[size], from[size], to[size], seat[seats] = {};
    void install();
    void reservation(int checker);
    void show(int checker);
} buses[number];

int main()
{
jump:
    int choice;
    char entry[size];
    int checker = -1;
    system("cls");
    cout << "\n1. install ";
    cout << "\n2. Enquiry ";
    cout << "\n3. Reservation ";
    cout << "\n4. Exit ";
    cout << "\nEnter your choice :";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        system("cls");
        buses[p].install();
        goto jump;
        break;
    }
    case 2:
    {
        system("cls");
        cout << "Enter Bus Number :";
        cin >> entry;
        for (int i = 0; i < p; i++)
        {
            if (strcmp(entry, buses[i].bus_num) == 0)
            {
                checker = i;
                break;
            }
        }
        if (checker != -1)
        {
            buses[checker].show(checker);
        }
        cout << "Press any key to go on main menu :";
        getch();
        goto jump;
        break;
    }
    case 3:
    {
        system("cls");
        cout << "Enter Bus Number :";
        cin >> entry;
        for (int i = 0; i < p; i++)
        {
            if (strcmp(entry, buses[i].bus_num) == 0)
            {
                checker = i;
                break;
            }
        }
        if (checker != -1)
        {
            buses[checker].reservation(checker);
        }
        cout << "Press any key to go on main menu :";
        getch();
        goto jump;
        break;
    case 4:
        return 0;
    default:
        cout << "Invalid input\n";
        cout << "Press any key to go on main menu :";
        getch();
        goto jump;
    }
    }

    return 0;
}

void bus ::show(int checker)
{
    cout << "Driver's name : " << buses[checker].driver << endl;
    cout << "Arrival time : " << buses[checker].arrival
         << "     Departure time : " << buses[checker].depart << endl;
    cout << "From : " << buses[checker].from
         << "           To : " << buses[checker].to << endl;
    cout << "\n\n";
    for (int i = 0; i < seats; i++)
    {
        cout << i + 1 << " ";
        if (buses[checker].seat[i] == '\0')
        {
            cout << "empty" << endl;
        }
        else
            cout << "Booked" << endl;
    }
}

void bus ::install()
{
    cout << "Enter bus number :";
    cin >> buses[p].bus_num;
    cout << "Enter driver name :";
    cin >> buses[p].driver;
    cout << "Enter arrival time :";
    cin >> buses[p].arrival;
    cout << "Enter depart time :";
    cin >> buses[p].depart;
    cout << "From :";
    cin >> buses[p].from;
    cout << "To :";
    cin >> buses[p].to;
    cout << "details are installed successfully\n\n\nPress any key to go on main menu :";
    getch();
    p++;
}

void bus ::reservation(int checker)
{
    show(checker);
    int temp_seat;
here:
    cout << "\nPlease enter the seat number you want to book :";
    cin >> temp_seat;
    if (buses[checker].seat[temp_seat - 1] != '0' && temp_seat < seats)
    {
        buses[checker].seat[temp_seat - 1] = '1';
        cout << "\nYour seat is booked successfully";
    }
    else
    {
        cout << "\nEither the seat is booked or you entered wrong input.\n";
        goto here;
    }
}
