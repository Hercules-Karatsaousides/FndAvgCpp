// include / import project libraries / Headers
#include <iostream>
#include <limits>
#include <vector>
#include <windows.h>


using namespace std;

// Create method for inputting custom number of variables + creates an extra line of space between inputs
void input(double& var) {
    cin>>var;
    cout<<endl;
}

// Start of main
int main() {
    // Set console to UTF-8 (had problems with div symbol)
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Try to enable ANSI escape codes on Windows 10+ consoles
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut != INVALID_HANDLE_VALUE) {
        DWORD mode = 0;
        if (GetConsoleMode(hOut, &mode)) {
            SetConsoleMode(hOut, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
        }
    }

    // Char variable used to input user choice
    // 1 = to default 5 variables
    // 2 = to custom number of variables (max 100)
    char choice= 0;

    // Created banner as string so it's easier to clear the console when removing clatter.
    string banner = R"(
                                  ______         _
                                 |  ____|       | |   /\
                                 | |__ _ __   __| |  /  \__   ____ _
                                 |  __| '_ \ / _` | / /\ \ \ / / _` |
                                 | |  | | | | (_| |/ ____ \ V / (_| |
                                 |_|  |_| |_|\__,_/_/    \_\_/ \__, |
                                                                __/ |
                                                               |___/
                                                            by Eraklis Karatsaousides)";

    // Main program menu with instructions of how to use + text formatting using ANSI escape codes followed by user input
    cout<<"\033[1;32m"<<banner<<"\033[0m\n\n\n"<<endl;
    cout<<"\033[1;33mThis is a c++ program to help you with finding the average of 5 double numbers.\n"<<endl;
    cout<<"If you want to find the average of only 5 doubles, press 1\n"<<endl;
    cout<<"If you want to enter a custom amount of numbers to find the average of, press 2\n"<<endl;
    cout<<"\033[4mOtherwise press any other key + [Enter] to exit\033[0m\n\n\n"<<endl;
    cout<<"> ";
    cin>>choice;

    // Check user input
    // If user chooses option 1 (default) ask user for a,b,c,d,e and return their average
    // If user chooses option 2 ask user for a custom amount of numbers and return their average
    // If user chooses anything else the program exits
    if (choice == '1') {
        system("cls");
        cout<<"\033[1;32m"<<banner<<"\033[0m\n\n\n"<<endl;
        double a=0, b=0, c=0, d=0, e=0;

        cout<<"\033[97mYou have chosen option 1\n\n"<<endl;

        cout<<"Enter 5 doubles:\033[0m\n\n";
        input(a), input(b), input(c), input(d), input(e);
        cout<<a<<" + "<<b<<" + "<<c<<" + "<<d<<" + "<<e<<" ÷ "<<" 5 "<<" = "<<(a+b+c+d+e)/5<<endl;
    }
    else if (choice == '2') {

        system("cls");
        cout<<"\033[1;32m"<<banner<<"\033[0m\n\n\n"<<endl;

        int custom = 0;
        double custom_average = 0;


        cout<<"\033[97mYou have chosen option 2\n\n"<<endl;

        // Checking User input for simple errors / mistakes to avoid a program crash in the case of wrong input.
        while (true) {
            cout<<"Enter the amount of numbers you want to calculate the average of: (Max 100)\033[0m\n";
            cout<<"> ";
            cin>>custom;
            if (cin.fail() || custom <= 1 || custom > 100) {
                system("cls");
                cout<<"\033[1;32m"<<banner<<"\033[0m\n\n\n"<<endl;
                cout << "\033[31mInvalid input. Please enter a positive integer.\033[0m\n";
                cin.clear(); // clear error state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            } else {
                break;
            }
        }
        
        // Create dynamic array to hold custom number of variables (portable)
        std::vector<double> custom_table(static_cast<size_t>(custom));
        cout<<endl;
        
        // Take User input for array
        for (int i = 0; i < custom; i++) {
            cout<<"\033[97mEnter number \033[0m"<<i+1<<":\n";
            cout<<"> ";
            input(custom_table[static_cast<size_t>(i)]);
        }
        
        // Print the average of the custom number of variables
        cout<<endl;
        cout<<"\033[97mThe average of the \033[93m"<<custom<<" \033[97mnumbers you entered is: \033[0m"<<endl;
        
        // Calculate and print the sum
        double sum = 0.0;
        for (int i = 0; i < custom; i++) {
            if (i == 0) {
                cout<<custom_table[0];
            } else {
                cout<<" + "<<custom_table[static_cast<size_t>(i)];
            }
            sum += custom_table[static_cast<size_t>(i)];
        }
        
        // Finish printing the average in a UserFriendly format
        cout<<" ÷ "<<custom<<" = ";
        custom_average = sum / static_cast<double>(custom);
        cout<<custom_average<<endl;
    }

    // Press any key to exit with cin ignore so the program doesn't exit on its own
    cout<<"\033[97mPress any key to exit...\033[0m"<<endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getchar();
    return 0;
}