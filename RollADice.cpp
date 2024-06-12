#include <iostream>
#include <string>
#include <Windows.h>
#include <cstdlib>
#include <list>
#include <ctime>

using namespace std;

class DrawCube
{
public:
    void randNumberdraw() {
        int cykl{ 1 };
        do {
            drawRandomCube();
            cykl++;
        } while (cykl != 6);
    }
    void drawRandomCube() {

        int cubeSide = rand() % 6 + 1;

        switch (cubeSide) {
        case 1:
            drawCubeNumberOne();
            break;
        case 2:
            drawCubeNumberTwo();
            break;
        case 3:
            drawCubeNumberThree();
            break;
        case 4:
            drawCubeNumberFour();
            break;
        case 5:
            drawCubeNumberFive();
            break;
        case 6:
            drawCubeNumberSix();
            break;
        }
        Sleep(500);
        system("cls");
    }
    void drawCubeNumberOne() {
        for (int i = 1; i <= 13; i++) {
            if (i == 1)
                cout << "\t-";
            else
                cout << "-";
        }
        cout << endl;
        cout << "\t|           |\n";
        cout << "\t|           |\n";
        cout << "\t|     *     |\n";
        cout << "\t|           |\n";
        cout << "\t|           |\n";
        for (int j = 1; j <= 13; j++) {
            if (j == 1)
                cout << "\t-";
            else
                cout << "-";
        }
        cout << endl;
    }
    void drawCubeNumberTwo() {
        for (int i = 1; i <= 12; i++) {
            if (i == 1)
                cout << "\t-";
            else
                cout << "-";
        }
        cout << endl;
        cout << "\t|          |\n";
        cout << "\t|   *      |\n";
        cout << "\t|          |\n";
        cout << "\t|      *   |\n";
        cout << "\t|          |\n";
        for (int j = 1; j <= 12; j++) {
            if (j == 1)
                cout << "\t-";
            else
                cout << "-";
        }
        cout << endl;
    }
    void drawCubeNumberThree() {
        for (int i = 1; i <= 13; i++) {
            if (i == 1)
                cout << "\t-";
            else
                cout << "-";
        }
        cout << endl;
        cout << "\t|           |\n";
        cout << "\t|   *       |\n";
        cout << "\t|     *     |\n";
        cout << "\t|       *   |\n";
        cout << "\t|           |\n";
        for (int j = 1; j <= 13; j++) {
            if (j == 1)
                cout << "\t-";
            else
                cout << "-";
        }
        cout << endl;
    }
    void drawCubeNumberFour() {
        for (int i = 1; i <= 13; i++) {
            if (i == 1)
                cout << "\t-";
            else
                cout << "-";
        }
        cout << endl;
        cout << "\t|           |\n";
        cout << "\t|   *   *   |\n";
        cout << "\t|           |\n";
        cout << "\t|   *   *   |\n";
        cout << "\t|           |\n";
        for (int j = 1; j <= 13; j++) {
            if (j == 1)
                cout << "\t-";
            else
                cout << "-";
        }
        cout << endl;
    }
    void drawCubeNumberFive() {
        for (int i = 1; i <= 13; i++) {
            if (i == 1)
                cout << "\t-";
            else
                cout << "-";
        }
        cout << endl;
        cout << "\t|           |\n";
        cout << "\t|   *   *   |\n";
        cout << "\t|     *     |\n";
        cout << "\t|   *   *   |\n";
        cout << "\t|           |\n";
        for (int j = 1; j <= 13; j++) {
            if (j == 1)
                cout << "\t-";
            else
                cout << "-";
        }
        cout << endl;
    }
    void drawCubeNumberSix() {
        for (int i = 1; i <= 12; i++) {
            if (i == 1)
                cout << "\t-";
            else
                cout << "-";
        }
        cout << endl;
        cout << "\t|          |\n";
        cout << "\t|   *  *   |\n";
        cout << "\t|   *  *   |\n";
        cout << "\t|   *  *   |\n";
        cout << "\t|          |\n";
        for (int j = 1; j <= 12; j++) {
            if (j == 1)
                cout << "\t-";
            else
                cout << "-";
        }
        cout << endl;
    }
};

class Element {
public:
    class Player {
    public:
        string nickname;
        int points;

        Player(string nick = "", int pts = 0) : nickname(nick), points(pts) {}
    };

    Player data;
    Element* next;

    Element(const Player& player) : data(player), next(nullptr) {}
};

class OneWayRecurringList {
public:
    Element* head;
    Element* tail; 

    OneWayRecurringList() : head(nullptr), tail(nullptr) {}

    void addElement(const Element::Player& player) {
        Element* newElement = new Element(player);

        if (head == nullptr) {
            head = newElement;
            tail = newElement;
            tail->next = head;
        }
        else {
            newElement->next = head;
            tail->next = newElement;
            tail = newElement;
        }
    }

    void printList() {
        Element* temp = head;
        do {
            cout << temp->data.nickname << " " << temp->data.points << endl;
            temp = temp->next;
        } while (temp != head);
    }

    void clear() {
        Element* temp = head;
        do {
            Element* next = temp->next;
            delete temp;
            temp = next;
        } while (temp != head);
        head = nullptr;
        tail = nullptr;
    }
};

class Game {
public:
    OneWayRecurringList players;

    int GameOption() {
        int gameChoice{ 0 }, goBack{ 0 };
        do {
            cout << "___________________________________\n";
            cout << "| --- Choice your game option --- |\n";
            cout << "| - 1: Two Players Game         - |\n";
            cout << "| - 2: Four Players Game        - |\n";
            cout << "| - 3: Six Players Game         - |\n";
            cout << "| - 0: Go Back                  - |\n";
            cout << "| - Type your choice: ";
            cin >> gameChoice;
            cin.ignore(2000, '\n');

            switch (gameChoice) {
            case 0:
                system("cls");
                goBack = 1;
                break;
            case 1:
            case 2:
            case 3:
                system("cls");
                players.clear();
                setPlayerNickname(gameChoice * 2);
                Sleep(80);
                system("cls");
                PlayersGame(gameChoice * 2);
                break;
            default:
                break;

            }
        } while (goBack != 1);
        return 0;
    }

    void setPlayerNickname(int playersNumber) {
        cout << "_________________________________\n";
        cout << "| - Creating Players Nickname - |\n";
        int playersValue = 1;
        for (int i = 0; i < playersNumber; i++) {
            cout << "| -        Player nr. " << playersValue << "       - |\n" << "| Type your nickname: ";
            string newPlayerNickName;
            getline(cin, newPlayerNickName);

            bool isNickNameUnique = false;

            while (!isNickNameUnique) {
                isNickNameUnique = true;
                Element* temp = players.head;
                if (temp != nullptr) {
                    do {
                        if (temp->data.nickname == newPlayerNickName) {
                            isNickNameUnique = false;
                            break;
                        }
                        temp = temp->next;
                    } while (temp != players.head);
                }
                if (!isNickNameUnique) {
                    cout << "Nickname is already taken!\n";
                    cout << "Please enter a new nickname: ";
                    getline(cin, newPlayerNickName);
                    cout << "\n";
                }
            }

            Element::Player newPlayer(newPlayerNickName, 0);
            players.addElement(newPlayer);
            playersValue++;
        }
    }

    bool checkIfPlayerPointsIsUnique(Element::Player currentPlayer) {
        Element* temp = players.head;
        do {
            if (temp->data.nickname != currentPlayer.nickname && temp->data.points == currentPlayer.points) {
                return false;
            }
            temp = temp->next;
        } while (temp != players.head);
        return true;
    }

    void checkWhichPlayerHasHighestNumber(Element::Player currentPlayer) {
        Element* temp = players.head;
        do {
            if (temp->data.nickname != currentPlayer.nickname && temp->data.points > currentPlayer.points) {
                cout << "| - Won by " << temp->data.nickname << "\n";
            }
            else if (temp->data.nickname != currentPlayer.nickname && temp->data.points < currentPlayer.points) {
                cout << "| - Won by " << currentPlayer.nickname << "\n";
            }
            temp = temp->next;
        } while (temp != players.head);
    }

    void PlayersGame(int playersNumber) {
        int time{ 0 }, round{ 1 }, currentPoint{ 0 };
        string input {""};
        DrawCube draw;
        Element* currentPlayer = players.head;

        do {
            cout << "_________________________________\n";
            cout << "| ---      Round nr. " << round << "      --- |\n";
            cout << "| - " << currentPlayer->data.nickname << " turn \n";
            cout << "| - To roll a dice type (l): ";
            cin >> input;
            cin.ignore(2000, '\n');
            cout << "\n";

            if (input == "l") {
                currentPoint = rand() % 6 + 1;
                system("cls");
                draw.randNumberdraw();
                
                switch (currentPoint) {
                case 1:
                    draw.drawCubeNumberOne();
                    break;
                case 2:
                    draw.drawCubeNumberTwo();
                    break;
                case 3:
                    draw.drawCubeNumberThree();
                    break;
                case 4:
                    draw.drawCubeNumberFour();
                    break;
                case 5:
                    draw.drawCubeNumberFive();
                    break;
                case 6:
                    draw.drawCubeNumberSix();
                    break;
                default:
                    break;
                }

                cout << "__________________________________\n";
                cout << "| - Your number is: " << currentPoint;
                cout << "\n";
                Sleep(1200);

                currentPlayer->data.points = currentPoint;

                if (!checkIfPlayerPointsIsUnique(currentPlayer->data)) {
                    cout << "| - Your number is the same. Rolling the dice again!\n";
                    Sleep(1200);
                    system("cls");
                    continue;   
                }
            }

            time++;

            switch (playersNumber) {
            case 2:
                if (time % 2 == 0) {
                    system("cls");
                    cout << "__________________________________\n";
                    cout << "| ---      The " << round << ". Round      --- |\n";
                    checkWhichPlayerHasHighestNumber(currentPlayer->data);
                    Sleep(2500);
                    round++;
                }
                break;
            case 4:
                if (time % 4 == 0) {
                    system("cls");
                    cout << "__________________________________\n";
                    cout << "| ---      The " << round << ". Round      --- |\n";
                    checkWhichPlayerHasHighestNumber(currentPlayer->data);
                    Sleep(2500);
                    round++;
                }
                break;
            case 6:
                if (time % 6 == 0) {
                    system("cls");
                    cout << "__________________________________\n";
                    cout << "| ---      The " << round << ". Round      --- |\n";
                    checkWhichPlayerHasHighestNumber(currentPlayer->data);
                    Sleep(2500);
                    round++;
                }
                break;
            default:
                break;
            }

            system("cls");
            currentPlayer = currentPlayer->next;

        } while (round <= 5);
        players.clear();
    }
};
int main()
    {
        setlocale(LC_ALL, "Polish");
        int choice{ 0 }, exit{ 0 }, time{ 0 };
        do {
            if (time > 1) {
                system("cls");
            }
            else {
                time++;
            }
            cout << "__________________________________\n";
            cout << "| --- Welcome to Roll a Dice --- |\n";
            cout << "| - 1: Game mode               - |\n";
            cout << "| - 0: Exit                    - |\n";
            cout << "| ------------------------------ |\n";
            cout << "| Wprowadz numer: ";
            cin >> choice;
            cin.ignore(2000, '\n');
            Game show;

            switch (choice)
            {
            case 0:
                exit = 1;
                break;
            case 1:
                system("cls");
                show.GameOption();
                break;
            default:
                break;
            }
        } while (exit != 1);

        return 0;
    }