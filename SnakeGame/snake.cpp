#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
bool gameOver;
const int width = 40;
const int height = 40;
int x, y, fruitX, fruitY, score;
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    srand(time(NULL));
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

void Draw()
{
    system("cls");
    // creating the top row for map
    for (int i = 0; i < width+2; ++i)
    {
        cout << "#";
    }
    cout << endl;
    for (int i = 0; i < width; ++i) 
    {
        for (int j = 0; j < height; j++) // goes through each row and outputs the walls
        {
            if (j == 0)
            {
                cout << "@"; 
            }
            if (i == x && j == y){
                cout << "O";
            }
            else if (i == fruitX && j == fruitY){
                cout << "F";
            }
            else
            {
                cout << " ";
            }
            if (j == width-1)
            {
                cout << "@";
            }
        }
        cout << endl;
    }
    // creating the bottom row for the map
    for (int i = 0; i < width+2; ++i)
    {
        cout << "#";
    }
    cout << endl;

    cout << "Score: " << score << endl;
}

void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
                gameOver = true; // will quit the game
                break;

        }
    }
}

void Logic()
{
    switch(dir)
    {
        case LEFT:
        y--;
        break;
        case RIGHT:
        y++;
        break;
        case UP:
        x--;
        break;
        case DOWN:
        x++;
        break;
        default:
        break;
    }
    if (x > width-1 || x < 0 || y > height-1 || y < 0)
    {
        gameOver = true;
    }

    if (x == fruitX && y == fruitY)
    {
        score += 10;
        srand(time(NULL));
        fruitX = rand() % width;
        fruitY = rand() % height;
    }
}

int main()
{
    Setup();
    while(!gameOver)
    {
        Draw();
        Input();
        Logic();
        //Sleep(10);
    }
    return 0;
}