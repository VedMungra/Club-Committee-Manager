#include <iostream>      // Input and Output Stream
#include <fstream>       // File Stream Library
#include <sstream>       // String Stream Library
#include <string.h>      // String Manipulation Functions
#include <iomanip>       // Input/Output Formatting Library
#include <vector>        // Vector Container
#include <unordered_map> // Unordered Map Container For Hash Table
#include <algorithm>     // Standard Algorithm Library
#include <ctime>         // Date and Time Function
#include <conio.h>       // Console Input/Output Library
#include <limits>

// ANSI escape codes for text color
#define BLACK       "\033[30m"      /* Black */
#define RED         "\033[31m"      /* Red */
#define GREEN       "\033[32m"      /* Green */
#define BLUE        "\033[34m"      /* Blue */
#define MAGENTA     "\033[35m"      /* Magenta */
#define CYAN        "\033[36m"      /* Cyan */
#define LIGHT_GRAY   "\033[90m"      /* Light Gray */
#define LIGHT_RED    "\033[91m"      /* Light Red */
#define LIGHT_BLUE   "\033[94m"      /* Light Blue */
//reset
#define RESET "\033[0m"

using namespace std;

// Structure to hold member information
struct Member
{
    int ID;
    string name;
    string post;
    string club;
    long long int Phone_no;
};

// Function prototypes
void main_menu();
void add_new_member();
void delete_member();
void search_member();
void view_members();
void return_to_main_menu();
void Loading();
void add_new_club();
void view_clubs();
void delete_club();
int password();
bool is_member_exists(int memberID);
bool sort_clubs(const Member &a, const Member &b);
string select_category();
string select_club();

// Global constants
const string FILENAME = "record.csv";
const string CLUBS_FILE = "clubs.csv";

// Function to display main menu
void main_menu()
{
    system("cls"); // It will clears the Screen
    cout << LIGHT_RED  << "\n============== MAIN MENU ==============" << RESET << endl;
    cout << LIGHT_BLUE <<  "||\t  1. Add Member              ||" << endl;
    cout << "||\t  2. Delete Member           ||" << endl;
    cout << "||\t  3. Search Member           ||" << endl;
    cout << "||\t  4. View Members            ||" << endl;
    cout << "||\t  5. Add Club                ||" << endl;
    cout << "||\t  6. Delete Club             ||" << endl;
    cout << "||\t  7. View Clubs              ||" << endl;
    cout << "||\t  8. Close Application       ||" << RESET <<  endl;
    cout << LIGHT_RED  << "=======================================" << RESET <<  endl;
    cout << LIGHT_GRAY << "Enter Your Choice: " << RESET;

    switch (getch())
    {
    case '1':
        add_new_member();
        break;
    case '2':
        delete_member();
        break;
    case '3':
        search_member();
        break;
    case '4':
        view_members();
        break;
    case '5':
        add_new_club();
        break;
    case '6':
        delete_club();
        break;
    case '7':
        view_clubs();
        break;
    case '8':
        system("cls"); // It will clears the Screen
        cout << LIGHT_RED << "\n\n\n======================================================================" << endl << RESET;
        cout << LIGHT_BLUE << "||                                                                  ||" << endl;
        cout << "||                                                                  ||" << endl;
        cout << "||          THANK YOU FOR USING CLUB MANAGEMENT SYSTEM :)           ||" << endl;
        cout << "||                                                                  ||" << endl;
        cout << "||                     Members (noCapCoderz) :                      ||" << endl;
        cout << "||                         RAMOLIYA SHIVAM                          ||" << endl;
        cout << "||                          PRANAV MANDANI                          ||" << endl;
        cout << "||                           VED MUNGRA                             ||" << endl;
        cout << "||                         PRATHAM LAKHANI                          ||" << endl;
        cout << "||                                                                  ||" << endl << RESET;
        cout << LIGHT_RED << "======================================================================\n\n\n" << RESET;
        exit(0);
    default:
        system("cls"); // It will clears the Screen
        cout << "\a";  // Beep sound for invalid choice
        cout << "\nEnter Valid Choice !";
        _sleep(1000); // Pause it for 1.0 sec.
        main_menu();
    }
}

// Check if Member ia already Exist or not
bool is_member_exists(int memberID)
{
    ifstream fin(FILENAME); // Open File to Read
    if (!fin.is_open())
    {
        cerr << BLACK << "Error opening file for reading!" << endl << RESET;
        exit(1);
    }

    Member member;
    string line;
    while (getline(fin, line))
    {
        // Creat stringstream object ss and initialize it a Line.
        // This stringstream will allow us to treat the string 'line' as a stream, facilitating parsing.
        stringstream ss(line);

        string get_line; // Declare a string variable named 'get_line' to store each extracted token.

        getline(ss, get_line, ',');
        // Read data from the stringstream 'ss' until a comma (',') is encountered.
        // Store the extracted data in the 'get_line' variable.

        member.ID = stoi(get_line); // Convert String to Integer of get_line

        if (member.ID == memberID)
        {
            fin.close();
            return true;
        }
    }
    fin.close();
    return false;
}

// Function to add a new member
void add_new_member()
{
    system("cls");
    int x = password(); // Password needed to be Entered to Add member
    if (x)
    {
        cout <<  GREEN << "\nPassword Matched !" << RESET;
        _sleep(1000);  // Wait for 1.0 Sec.
        system("cls"); // Clears the Screen
        Member member;
        ofstream fout(FILENAME, ios::app); // Opens the file in Append Mode
        cout << CYAN << "\nAdd MEMBER INFO" << endl <<RESET;
        cout << CYAN << "Member ID: " << RESET;
        cin >> member.ID;
        if (is_member_exists(member.ID)) // Check if ID Exist or Not.
        {
            cout << BLACK << "Error: Member with ID " << member.ID << " already exists!" << endl;
            cout << "Press any key to continue..." << RESET;
            getch();
            main_menu();
        }
        cin.ignore();
        cout << CYAN << "Name: ";
        getline(cin, member.name);
        cout << "Post: ";
        getline(cin, member.post);
        member.club = select_club(); // Select club by name
        cout << "Phone_Number: " << RESET;
        cin >> member.Phone_no;
        fout << member.ID << "," << member.name << "," << member.post << "," << member.club << "," << member.Phone_no << endl;
        fout.close();
        cout << GREEN << "The record is successfully added" << RESET << endl;
    flag:
        cout << MAGENTA << "Add any more (Y/N)? " << RESET;
        switch (getch())
        {
        case 'Y':
        case 'y':
        {
            add_new_member(); // Add another member
            break;
        }
        case 'N':
        case 'n':
        {
            main_menu(); // Return to MainMenu
            break;
        }
        default:
        {
            system("cls"); // Clear screen
            cout << BLACK << "\a\nEnter Valid Option !" << endl << RESET;
            _sleep(1000); // Wait for 1.0 Second
            goto flag;
        }
        }
    }
    else
    {
        system("cls"); // Clears the Screen
        cout << BLACK << "\nWrong Password !" << RESET;
        _sleep(1000); // Wait for 1.0 Second
        add_new_member();
    }
}

// Function to delete a member
void delete_member()
{
    system("cls");      // Clears the Screen
    int x = password(); // Password needed to be Entered to Delete member
    if (x)
    {
        cout << GREEN << "\nPassword Matched !" RESET;
        _sleep(1000);              // Wait for 1.0 sec
        system("cls");             // Clears the Screen
        ifstream fin(FILENAME);    // Open Record file to read
        ofstream fout("temp.csv"); // Open temp file to write
        int del;
        bool found = false;
        Member member;
        cout << CYAN <<"\nEnter the Member ID to delete: " << RESET;
        cin >> del;
        string line;
        while (getline(fin, line))
        {
            // stringstream as mentioned before
            stringstream ss(line);
            string get_line;
            getline(ss, get_line, ',');
            member.ID = stoi(get_line);
            if (member.ID != del) // Writes all Member to temp.csv exept member to be deleted
                fout << line << endl;
            else
                found = true;
        }
        fin.close();
        fout.close();
        remove(FILENAME.c_str());             // Removes the record file
        rename("temp.csv", FILENAME.c_str()); // Rename the temp.csv to record.csv
        if (found)
            cout << GREEN << "The record is successfully deleted" << RESET << endl;
        else
            cout << BLACK << "No record found with ID " << del <<RESET<< endl;
        return_to_main_menu();
    }
    else
    {
        system("cls"); // Clears the Screen
        cout << BLACK << "\nWrong Password !" << RESET;
        _sleep(1000); // wait for 1.0 sec
        delete_member();
    }
}

// Function to search for a member
void search_member()
{
    system("cls");                        // Clears the Screen
    ifstream fin(FILENAME);               // Open file in read mode
    unordered_map<int, Member> memberMap; // Hashtable to store member Data
    string line;
    while (getline(fin, line))
    {
        // Stringstream as mentiond above
        stringstream ss(line);
        Member member;
        string get_line;
        getline(ss, get_line, ',');
        member.ID = stoi(get_line);
        getline(ss, member.name, ',');
        getline(ss, member.post, ',');
        getline(ss, member.club, ',');
        getline(ss, get_line, ',');
        member.Phone_no = stoll(get_line); // String to Long Long int
        memberMap[member.ID] = member;     // Pushes member to Hashtable
    }
    fin.close();
    int choice;
    cout << LIGHT_RED << "\n=====================================" << endl <<RESET;
    cout << LIGHT_BLUE << "==\tSearch by:                 ==" << endl;
    cout << "==\t1. Member ID               ==" << endl;
    cout << "==\t2. Member Name             ==" << endl;
    cout << "==\t3. Club Name               ==" << endl;
    cout << "==\t4. Return to MainMenu      ==" << endl << RESET;
    cout << LIGHT_RED<< "=====================================" << endl << RESET;
    cout << CYAN <<  "Enter your choice: " << RESET;
    char ch = _getch();
    switch (ch)
    {

    case '1': // Search By ID
    {
        system("cls"); // Clears the Screen
        int s;
        bool found = false;
        cout << CYAN << "\nEnter the Member ID to search: " << RESET;
        cin >> s;
        cin.ignore();
        if (memberMap.find(s) != memberMap.end())
        {
            Member member = memberMap[s];
            cout << GREEN << "The Member is available" << endl << RESET;
            cout << CYAN <<  "ID    : " << member.ID << endl;
            cout << "Name  : " << member.name << endl;
            cout << "Post  : " << member.post << endl;
            cout << "Club  : " << member.club << endl;
            cout << "Ph_No.: " << member.Phone_no << endl;
            cout << endl << RESET;
            found = true;
        }
        if (!found)
        {
            cout << BLACK << "No record found with ID " << s << RESET << endl;
        }
        cout << CYAN << "Press ENTER to return to the search Member section..." << RESET;
        _getch();
        search_member();
    }

    case '2': // Search by Name
    {
        system("cls"); // Clears the Screen
        string s;
        bool found = false;
        cout << CYAN << "\nEnter the Member Name to search: " << RESET;
        getline(cin, s);
        for (const auto &entry : memberMap)
        {
            Member member = entry.second;
            if (member.name == s)
            {
                cout << GREEN << "The Member is available" << endl <<RESET;
                cout <<CYAN <<  "ID    : " << member.ID << endl;
                cout << "Name  : " << member.name << endl;
                cout << "Post  : " << member.post << endl;
                cout << "Club  : " << member.club << endl;
                cout << "Ph_No.: " << member.Phone_no << endl;
                cout << endl << RESET;
                found = true;
            }
        }
        if (!found)
        {
            cout << BLACK << "No record found with name " << s << endl << CYAN;
        }
        cout << CYAN <<  "Press ENTER to return to the search Member section..." RESET;
        _getch();
        search_member();
    }

    case '3': // Search By Clubs
    {
        system("cls"); // Clears the Screen
        string club;
        bool found = false;
        cout << "\Select the Club Name to search: ";
        club = select_club(); // Needed to select the club
        system("cls");        // Clears the Screen
        cout << "The Members of " << club << " Club is as Listed Below." << endl;
        for (const auto &entry : memberMap)
        {
            Member member = entry.second;
            if (member.club == club)
            {
                cout << GREEN << "\nThe Member is available" << endl <<RESET;
                cout <<CYAN << "ID    : " << member.ID << endl;
                cout << "Name  : " << member.name << endl;
                cout << "Post  : " << member.post << endl;
                cout << "Club  : " << member.club << endl;
                cout << "Ph_No.: " << member.Phone_no << endl;
                cout << endl << RESET;
                found = true;
            }
        }
        if (!found)
        {
            cout <<BLACK <<  "No record found in club with name " << club << endl << RESET;
        }
        cout << CYAN << "Press ENTER to return to the search Member section..."<< RESET;
        _getch();
        search_member();
    }

    case '4': // Return to main menu
    {
        cout << GREEN << "\nReturning to Main Menu..." <<RESET;
        _sleep(1000); // wait for 1.0 sec
        main_menu();
    }

    default:
    {
        system("cls"); // Clears the Screen
        cout << "\a";  // Beep sound to alert
        cout << BLACK <<"\nEnter Valid Choice !" << endl << RESET;
        _sleep(1000); // wait for 1.0 sec
        search_member();
    }
    }
}

// Comparison function to sort members based on club names
bool sort_clubs(const Member &a, const Member &b)
{
    return a.club < b.club;
}

// Function to view all members
void view_members()
{
    system("cls");          // Clears the Screen
    ifstream fin(FILENAME); // Open file in read mode
    vector<Member> members;
    Member member;
    while (fin >> member.ID)
    {
        fin.ignore();
        getline(fin, member.name, ',');
        getline(fin, member.post, ',');
        getline(fin, member.club, ',');
        fin >> member.Phone_no;
        members.push_back(member);
    }
    fin.close();

    // Sort members by club name
    sort(members.begin(), members.end(), sort_clubs);

    // Displaying Member Sorted Clubwise.
    cout << RED << "\n======================================= MEMBER LIST SORT CLUBWISE =======================================" << RESET <<endl;
    cout << MAGENTA << "||                                                                                                     ||" << endl <<RESET;
    cout << MAGENTA << "||  <MEM_ID>" << setw(13) << left << "\t<MEMBER NAME>" << setw(13) << left << "\t\t<Post>" << setw(13) << left << "\t\t<club>" << setw(13) << left << "\t\t<PHONE_NO>     ||" << endl << RESET;
    for (const auto &member : members)
    {
        cout << MAGENTA << "||  " << member.ID << "\t\t" << setw(15) << left << member.name << "\t\t" << setw(15) << left << member.post << "\t\t" << setw(15) << left << member.club << "\t\t" << setw(15) << left << member.Phone_no << "||" << endl << RESET;
    } // setw() function of library <iomapin> used to formate text on '<< left' left.
    cout << RED << "=========================================================================================================" << RESET;
    return_to_main_menu();
}

// Function to return to main menu
void return_to_main_menu()
{
    cout << CYAN << "\nPress ENTER to return to the main menu..." << RESET;
    getch();
    main_menu();
}

// Function to select club category
string select_category()
{
    string s[5];
    s[0] = "Skill Development";
    s[1] = "Art";
    s[2] = "Technical";
    s[3] = "Social";
    s[4] = "Commerce";

    cout << LIGHT_RED << "\n=========== SELECT CLUB CATEGORY ===========" << endl << RESET;
    cout << LIGHT_BLUE <<  "||           1. Skill Development         ||" << endl;
    cout << "||           2. Art                       ||" << endl;
    cout << "||           3. Technical                 ||" << endl;
    cout << "||           4. Social                    ||" << endl;
    cout << "||           5. Commerce                  ||" << endl << RESET;
    cout << LIGHT_RED "=============================================" << endl;
    cout << endl << RESET;
    cout << CYAN <<  "Enter choice : " << RESET;
    int p;
    cin >> p;
    cin.ignore();
    if (p < 1 || p > 5)
    {
        cout << BLACK << "Invalid Choice" << endl << RESET;
        _sleep(1000); // wait for 1.0 sec
        return_to_main_menu();
    }
    else
        return s[p - 1];
}

// Function to add club
void add_new_club()
{
    system("cls");      // Clears the Screen
    int x = password(); // Password needed to  Add the new clubs
    if (x)
    {
        cout << GREEN << "\nPassword Matched !" << RESET;
        _sleep(1000);                        // wait for 1.0 sec
        system("cls");                       // Clears the Screen
        ofstream fout(CLUBS_FILE, ios::app); //  File opened in append Mode
        string clubName;
        string clubCategory;
        clubCategory = select_category(); // Select the Club category
        cout << CYAN << "\nEnter Club Name: " << RESET;
        getline(cin, clubName);
        fout << "\n" << clubName << "," << clubCategory << endl;
        fout.close();
        cout << GREEN << "Club added successfully!" << endl << RESET;
        return_to_main_menu();
    }
    else
    {
        system("cls"); // Clears the Screen
        cout << BLACK <<  "\nWrong Password !" << RESET;
        _sleep(1000); // wait for 1.0 sec
        add_new_club();
    }
}

// Function to select club by name
string select_club()
{
    ifstream fin(CLUBS_FILE);
    if (!fin.is_open())
    {
        cout << BLACK << "Error opening file: " << CLUBS_FILE << endl << RESET;
        return "";
    }

    vector<string> clubs;
    string line;
    int club = 1;

    cout << CYAN <<  "\nSelect Club:" << endl << RESET;
    cout << RED <<  "==================" << endl << RESET; 

    while (getline(fin, line))
    {
        // srtringstream as mentioned above
        stringstream ss(line);
        string clubName;
        getline(ss, clubName, ','); // Read only the first get_line (club name)
        clubs.push_back(clubName);
        cout << LIGHT_BLUE <<  club << ". " << clubName << endl << RESET;
        club++;
    }

    fin.close();

    cout << RED << "==================" << endl << RESET;
    int choice;
    cout << CYAN << "Enter Club ID: " << RESET;
    cin >> choice;

    if (choice < 1 || choice > clubs.size())
    {
        cout << BLACK << "Invalid Club ID" << endl << RESET;
        return_to_main_menu();
    }

    return clubs[choice - 1];
}

// Function to View all the Clubs.
void view_clubs()
{
    system("cls");            // Clears the Screen
    ifstream fin(CLUBS_FILE); //  File Open in read Mode
    if (!fin.is_open())
    {
        cout << BLACK <<  "Error opening file: " << CLUBS_FILE << endl << RESET;
        return;
    }

    string line;
    int i = 1;
    cout << RED <<  "\nClubs List" << endl << RESET;
    cout << MAGENTA <<  setw(30) << left << "<CLUBS>" << setw(25) << left << "<CLUB_CATEGORY>" << endl << RESET;

    while (getline(fin, line))
    {
        // stringstream as mentioned above
        stringstream ss(line);
        vector<string> tokens;
        string token;

        while (getline(ss, token, ','))
        {
            tokens.push_back(token);
        }

        if (tokens.size() >= 2)
        {
            if(i<10){
            cout << BLUE << "0" << i << ". " << setw(30) << left << tokens[0] << setw(25) << left << tokens[1] << endl << RESET;
            i++;
            }
            else{
            cout <<BLUE << i << ". " << setw(30) << left << tokens[0] << setw(25) << left << tokens[1] << endl << RESET;
            i++;
            }
        }
    }
    return_to_main_menu();
    fin.close();
}

// Function to delete club
void delete_club()
{
    system("cls");      // Clears the Screen
    int x = password(); // Password needed to delete the club
    if (x)
    {
        cout << GREEN << "\nPassword Matched!" << RESET;
        _sleep(1000);  // wait for 1.0 sec
        system("cls"); // Clears the Screen
        ifstream fin(CLUBS_FILE);
        if (!fin)
        {
            cerr << BLACK <<  "Error: Unable to open clubs file for reading." << endl << RESET;
            return_to_main_menu();
        }

        vector<string> clubs; // Vector to store club
        string line;
        int clubID = 1;

        cout << CYAN << "\nSelect Club to Delete:" << endl << RESET;
        cout << RED <<  "================" << endl << RESET;

        while (getline(fin, line))
        {
            clubs.push_back(line);
            cout << BLUE << clubID << ". " << line << endl << RESET;
            clubID++;
        }

        fin.close();

        cout << RED << "================" << endl << RESET;
        int choice;
        cout << CYAN << "Enter Club ID to Delete: " RESET;
        cin >> choice;

        if (choice < 1 || choice > clubs.size())
        {
            cout << BLACK << "Invalid Club ID!" << endl << RESET;
            _sleep(1000); // wait for 1.0 sec
            delete_club();
            return;
        }

        cout << GREEN << "Deleting club: " << clubs[choice - 1] << endl << RESET;
        clubs.erase(clubs.begin() + choice - 1);

        ofstream fout("temp.csv");
        for (const string &club : clubs) // Write all club name exept which is needed to delete
        {
            fout << club << endl;
        }
        fout.close();

        remove(CLUBS_FILE.c_str());             // Delete the clubs.csv file
        rename("temp.csv", CLUBS_FILE.c_str()); // rename the temp.csv to clubs.csv
        cout <<GREEN << "Club deleted successfully!" << endl << RESET;
        return_to_main_menu();
    }
    else
    {
        system("cls"); // Clears the Screen
        cout << "\nWrong Password!";
        _sleep(1000); // wait for 1.0 sec
        delete_club();
    }
}

// Function for Loading page
void Loading()
{
    system("cls"); // Clears the Screen
    char ch;
    cout << endl;
    cout << MAGENTA << "           WE HEARTLY WELCOMES YOU :)           " << endl << RESET;
    cout << RED << "==============================================" << endl << RESET;
    cout << BLUE << "||          CLUB MANAGEMENT SYSTEM          ||" << endl;
    cout << "||            By noCapCoderz :)             ||" << endl;
    cout << RED << "==============================================" << endl << RESET;
    cout << endl;
    cout << RED << "==============================================" << endl << RESET;
    cout << BLUE << "||                Members :                 ||" << endl;
    cout << "||             RAMOLIYA SHIVAM              ||" << endl;
    cout << "||              PRANAV MANDANI              ||" << endl;
    cout << "||                VED MUNGRA                ||" << endl;
    cout << "||             PRATHAM LAKHANI              ||" << endl << RESET;
    cout << RED << "==============================================" << endl;
    cout << endl << RESET;
    cout << CYAN << " Press any KEY to enter our the System....." << RESET;
    getch();
    system("cls"); // Clears the Screen
    cout << endl;
    cout << MAGENTA << "           WE HEARTLY WELCOMES YOU :)           " << endl << RESET;
    cout << RED << "==============================================" << endl << RESET;
    cout << BLUE << "||          CLUB MANAGEMENT SYSTEM          ||" << endl;
    cout << "||            By noCapCoderz :)             ||" << endl;
    cout << RED << "==============================================" << endl << RESET;
    cout << endl;
    cout << RED << "==============================================" << endl << RESET;
    cout << BLUE << "||                Members :                 ||" << endl;
    cout << "||             RAMOLIYA SHIVAM              ||" << endl;
    cout << "||              PRANAV MANDANI              ||" << endl;
    cout << "||                VED MUNGRA                ||" << endl;
    cout << "||             PRATHAM LAKHANI              ||" << endl << RESET;
    cout << RED << "==============================================" << endl;
    cout << endl << RESET;
    cout << CYAN << "\n\t\tPlease Wait!!" << endl << RESET;
    cout << GREEN << "\t\tLoading " << RESET;
    for (int i = 0; i < 7; i++)
    {
        cout << ".";
        _sleep(300); // Wait for 0.3 seconds
    }
    system("cls"); // Clears the Screen
    main_menu();
}

// Function to prompt for password
int password()
{
    system("cls");                              // Clears the Screen
    char pass[10], ch, password[10] = "123456"; // Define password
    int i = 0;
    cout << "* Please check Secret.txt file before running code !" << endl;
    cout << endl;
    cout << CYAN <<"\nEnter the password to Enter: " << RESET;
    while (ch != 13) // Loop until Enter key is pressed
    {
        ch = getch();
        if (ch != 13 && ch != 8) // Display '*' for each character entered
        {
            cout << "*";
            pass[i] = ch;
            i++;
        }
    }
    pass[i] = '\0';
    if (strcmp(pass, password) == 0) // Check if password matches
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Main function
int main()
{
    Loading();
    return 0;
}
