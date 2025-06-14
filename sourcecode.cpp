#include <iostream>
#include <iomanip>

void startgame(std::string (&questions)[5], int (&answers)[5], int &score, std::string &name, int &answer, int &choice);

void getandDisplayUserInfo(std::string &name);
void displayMenu(std::string name, int &choice);
int main()
{
    std::string username;
    int menuChoice, gamerScore = 0, choice, answer;
    std::string riddles[5] = {
        "I am a number. Multiply me by 2 and add 6, you get 20. What am I?",
        "I'm the square of 5. What number am I?",
        "What is the sum of the first 4 natural numbers?",
        "I'm 3 more than twice 4. What number am I?",
        "What's the factorial of 5?"};
    int answers[5] = {7, 25, 10, 11, 120};

    system("cls");
    getandDisplayUserInfo(username);
    displayMenu(username, menuChoice);
    std::cout << "Option:";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        system("cls");
        std::cin.ignore();
        std::cout << "Getting Started...\nPress Enter To Begin Playing.";
        std::cin.get();
        startgame(riddles, answers, gamerScore, username, answer, choice);
        break;
    case 2:
        system("cls");
        std::cout << "Thank You For Visiting\n";
        std::cout << "Exiting Game...\n";
        break;

    default:
        std::cout << "Invalid Response.\n";
        displayMenu(username, choice);
        break;
    }
    return 0;
}
void startgame(std::string (&questions)[5], int (&answers)[5], int &score, std::string &name, int &answer, int &choice)
{
    int switcher;
    system("cls");
    name[0] = toupper(name[0]);
    std::cout << "Hey " << name << ".\nWe Will Have Five Riddles For You.\nProvide A Correct Answer To Each Riddle.\nYour Score Is Currently 0, We'll Keep Your Score Updated Throughout The Game.\nNote That All Answers Should Be Integers.\nGood Luck.\nPress Enter To Start Gaming...";

    std::cin.get();
    score = 0;
    system("cls");

    for (int i = 0; i < 5; i++)
    {
        system("cls");
        std::cout << "Riddle " << (i + 1) << ": " << questions[i] << std::endl;
        std::cout << "Answer:";
        std::cin >> answer;
        if (answer == answers[i])
        {
            score += 1;
            std::cout << "Correct Answer\nCurrent Score:" << score;

            std::cin.ignore();
            std::cout << "\nPress Enter To Continue...";
            std::cin.get();
        }
        else
        {
            std::cout << "Incorrect Answer\nCurrent Score:" << score;
            std::cin.ignore();
            std::cout << "\nPress Enter To Continue...";
            std::cin.get();
        }
    }
    system("cls");
    std::cout << "Game Over,Press Enter To View Results...";
    std::cin.get();
    system("cls");
    std::cout << "Results:\n";
    std::cout << "Gamer Name    : " << name << '\n';
    std::cout << "Highest Score : " << score << '\n';
    if (((score / float(5)) * 100) < 50)
    {
        std::cout << "Status        : Bad Gamer" << '\n';
        std::cout << "Press Enter To Continue...";
        std::cin.get();
        system("cls");
        std::cout << "Options\n1.Replay\n2.Exit Game\n   Option:";

        switch (switcher)
        {
        case 1:
            startgame((&questions)[5], (&answers)[5], score, name, answer, choice);
            break;

        default:
            std::cout << "Thank You For Playing.\nExiting Game...";
            break;
        }
    }
    else
    {
        std::cout << "Status        : Good Gamer" << '\n';
        std::cout << "Press Enter To Continue...";
        std::cin.get();
        system("cls");

        switch (switcher)
        {
        case 1:
        {
            main();
            break;
        }

        default:
        {
            std::cout << "Thank You For Playing.\nExiting Game...";
            break;
        }
        }
    }
};
void getandDisplayUserInfo(std::string &name)

{

    while (true)
    {
        std::cout << "Enter Your Username:";
        std::getline(std::cin, name);
        if (name.length() >= 7)
        {

            for (auto i = 0; i < name.length(); i++)
            {
                if (isdigit(name[i]))
                {
                    system("cls");
                    std::cout << "Username Can't Contain Digits\n";
                    getandDisplayUserInfo(name);
                }
            }
            system("cls");

            break;
        }

        else
        {
            system("cls");
            std::cout << "Username Can't Be less Than 7 Characters.\n";
        }
    }
};

void displayMenu(std::string name, int &choice)
{
    name[0] = toupper(name[0]);
    std::cout << "Hello " << name << ". Welcome To Math Riddle Trainer Game.\nThis Is A Simple Game.\nFollow Prompts And Enjoy.\nThis Game Is Developed By Boitumelo\nPress Enter To Proceed...";
    std::cin.get();
    system("cls");
    std::cout << std::setw(15) << "Options" << std::endl;
    std::cout << std::left << "1.Play" << std::endl;
    std::cout << std::setw(10) << "2.Exit Game" << std::endl;
}