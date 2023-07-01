#include "gfx.h"
#include "gridfont.h"
#include "sound.h"
#include <time.h>

// instance vars
static int max_x = 0, max_y = 0; // screen size

// launch parameters
bool manualShipPlacement = true; // decides if user will manually place the ships (default: true)

// menu
bool menuChoiceMade = false;

// size of cells
const int cellHeight = 5; // height of an arena cell
const int cellWidth = 9;  // width of an arena cell

const int offsetBetweenArenas = 10; // offset between two arenas

// arena size
const int arenaSize = 10;

// colors
// 1: white
// 2: red
// 3: green
// 4: blue
const int aliveShipColor = 1;
const int damagedShipColor = 2;
const int interfaceColor = 3;

// chars
const char aliveShipChar = '+';
const char damagedShipChar = '*';
const char pointerChar = '#';
const char shotCellChar = '/';
const char emptyCellChar = ' ';

// coordinates of the arenas
const int firstPlayersArenaY = 3;
const int firstPlayersArenaX = 5;
const int secondPlayersArenaY = firstPlayersArenaY;
const int secondPlayersArenaX = firstPlayersArenaX + cellWidth * arenaSize + offsetBetweenArenas;

// adressing array, contains information about all the cells on both arenas and the content inside
int cells[arenaSize][arenaSize][2];

// ship counters
int firstPlayerShips;
int secondPlayerShips;

// pointer coordinates
int yPointer = 0;
int xPointer = 0;

// draws a square on y, x with height and width
void draw_square(int y, int x, int height, int width)
{
    height -= 1;
    width -= 1;
    // top
    draw_line(y, x + 1, y, x + width - 1);
    // bottom
    draw_line(y + height, x + 1, y + height, x + width - 1);
    // left
    draw_line(y + 1, x, y + height - 1, x);
    // right
    draw_line(y + 1, x + width, y + height - 1, x + width);
}

// prints "press s to start the game" on the screen
void printHintToStartGame()
{

    const char start[] = "Press space to start the game";
    move(LINES - 3, (COLS / 2) - strlen(start) / 2);
    printw(start);
    refresh();
}

// prints "Schiffe Versenken" on the screen
void printGamesName()
{
    const char text[] = "Sink ships";
    int tx = max_x / 2;
    int ty = (max_y - 4) / 2 + 1;
    init_grid_font();
    draw_grid_text(ty - get_grid_char_lines() / 2, tx - strlen(text) * get_grid_char_cols() / 2, text);
    refresh();
}

// prints out game rules and key controls
void printGameRules()
{
    move(2, 3);
    printw("Game rules: \n\n   Players place their ships on a grid and take turns \n   guessing the coordinates to attack the opponent's \n   ships. The first player to sink all the opponent's ships wins. \n\n   Use arrow keys or WASD to"
           " control the pointer, space to shoot, \n   'r' to rotate");
    draw_square(1, 1, 10, 67);
}

// draws the game's intro
void intro()
{
    printGamesName();
    printHintToStartGame();
    printGameRules();

    int input = tolower(getch());

    while (input != ' ')
    {
        if (input == 'q')
        {
            exit_gfx();
            exit(0);
        }
        msleep(1);

        input = tolower(getch());
    }

    clear();
    sound_play("Sounds/correct.wav");
}

// draws an arena on y, x with height and width
void draw_arena(int y, int x, int height, int width)
{
    use_color(3);
    // draws coordinates
    const char letterCoordinates[] = "ABCDEFGHIG";
    for (int i = 0; i <= 9; i++)
    {
        move(y - 1, x + ((cellWidth - 1) / 2) + (cellWidth - 1) * i);
        printw("%c", letterCoordinates[i]);
    }
    const char numberCoorinates[] = "123456789";
    for (int i = 0; i < 9; i++)
    {
        move(y + ((cellHeight - 1) / 2) + (cellHeight - 1) * i, x - 1);
        printw("%c", numberCoorinates[i]);
    }
    move(y + ((cellHeight - 1) / 2) + (cellHeight - 1) * 9, x - 2);
    printw("10");

    // draws table
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            draw_square(y + i * (cellHeight - 1), x + j * (cellWidth - 1), cellHeight, cellWidth);
        }
    }

    // fills all cells with zeroes
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int p = 0; p < 2; p++)
            {
                cells[i][j][p] = 0;
            }
        }
    }
}

// fills one cell on y, x with some chars with a color on a specific arena
void fillOneCell(int y, int x, int player, int color, char c)
{
    // sets the char color
    // 1: white
    // 2: red
    // 3: green
    // 4: blue
    use_color(color);

    // initializes the coordiantes of the arena
    int arenaY = 0;
    int arenaX = 0;

    // sets the arena coordinates
    switch (player)
    {
    case 0:
        arenaY = firstPlayersArenaY;
        arenaX = firstPlayersArenaX;
        break;
    case 1:
        arenaY = secondPlayersArenaY;
        arenaX = secondPlayersArenaX;
        break;
    default:
        // we shoould never get here
        break;
    }

    // fills a cell with chars
    for (int i = 0; i < cellWidth - 2; i++)
    {
        for (int j = 0; j < cellHeight - 2; j++)
        {
            move(((arenaY + 1) + (cellHeight - 1) * y) + 1 * j, ((arenaX + 1) + (cellWidth - 1) * x) + 1 * i);
            printw("%c", c);
        }
    }
}

// draws a ship on y, x with height and width on a specific arena
void draw_ship(int y, int x, int height, int width, int player, int color)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            fillOneCell(y + 1 * i, x + 1 * j, player, color, aliveShipChar);
        }
    }
}

// clears a ship on y, x with height and width on a specific arena
void clear_ship(int y, int x, int player, int height, int width)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            fillOneCell(y + 1 * i, x + 1 * j, player, aliveShipColor, emptyCellChar);
            if (cells[y + 1 * i][x + 1 * j][player] == 2)
            {
                fillOneCell(y + 1 * i, x + 1 * j, player, interfaceColor, aliveShipChar);
            }
        }
    }
}

// draws both arenas
void setup()
{
    draw_arena(firstPlayersArenaY, firstPlayersArenaX, 10, 10);
    draw_arena(secondPlayersArenaY, secondPlayersArenaX, 10, 10);
}

// checks a cell on y, x on a specific arena
int shoot(int y, int x, int player)
{
    int status = cells[y][x][player];
    switch (status)
    {
    case 0:                      // there is nothing
        cells[y][x][player] = 1; // this cell is now shot
        fillOneCell(y, x, player, aliveShipColor, shotCellChar);
        return 1; // menans player missed
        break;
    case 1: // the cell was shot yet
        // do nothung
        return 0; // means no shot was made
        break;
    case 2:                      // there is a ship
        cells[y][x][player] = 3; // the cell has now a damaged ship
        fillOneCell(y, x, player, damagedShipColor, damagedShipChar);

        // update number of ship cells
        if (player == 0)
            firstPlayerShips -= 1;
        else if (player == 1)
            secondPlayerShips -= 1;

        return 2; // means player hit a ship
        break;
    case 3: // there is a damaged ship
        // do nothing
        return 0; // means no shot was made
        break;
    default:
        // we should never get here
        return 0;
        break;
    }
}

// asks user to manually place 10 ships on a specific arena (1 with size of 4; 2 with size of 3; 3 with size of 2 and 4 with size of 1)
void placeShips(int player)
{

    int y = 0;              // starting x coorinate of new ships
    int x = 0;              // starting y coorinate of new ships
    int height = 4;         // starting height of new ships
    int width = 1;          // starting width of new ships
    int shipCounter = 0;    // counting placed ships
    int cellCounter = 0;    // counts cells filled with ships arround the ship
    int tmpHeight;          // to save temporary height of a ship before rotating
    int tmpWidth;           // to save temporary width of a ship before rotating
    int rotationAspect = 0; // saves the rotation aspect of a ship

    while (shipCounter < 10)
    {
        draw_ship(y, x, height, width, player, 1);
        refresh();

        // asks for key input
        switch (getch())
        {
        case 'w':
        case 'W':
        case KEY_UP: // up
            clear_ship(y, x, player, height, width);
            if (y > 0)
                y -= 1;
            break;
        case 'a':
        case 'A':
        case KEY_LEFT: // left
            clear_ship(y, x, player, height, width);
            if (x > 0)
                x -= 1;
            break;
        case 's':
        case 'S':
        case KEY_DOWN: // down
            clear_ship(y, x, player, height, width);
            if (y + height < 10)
                y += 1;
            break;
        case 'd':
        case 'D':
        case KEY_RIGHT: // right
            clear_ship(y, x, player, height, width);
            if (x + width < 10)
                x += 1;
            break;
        case 'r': // rotates the ship
        case 'R':
            clear_ship(y, x, player, height, width);
            // swap width and height
            tmpHeight = height;
            tmpWidth = width;

            height = tmpWidth;
            width = tmpHeight;

            rotationAspect++;

            // check if rotation is possible without leaving arena
            if ((y + height - 1) > 9)
            {
                y -= height - 1;
            }
            if ((x + width - 1) > 9)
            {
                x -= width - 1;
            }

            break;
        case ' ': // places the ship
            // check if there is already a ship
            for (int i = 0; i < height + 2; i++)
            {
                for (int j = 0; j < width + 2; j++)
                {
                    int cellY = (y - 1) + 1 * i;
                    int cellX = (x - 1) + 1 * j;

                    if (cells[cellY][cellX][0] == 2 && cellY >= 0 && cellX >= 0 && cellY <= 9 && cellX <= 9)
                    {
                        cellCounter++;
                    }
                }
            }

            if (cellCounter == 0) // means there are no ships
            {

                // save the ship into an array
                for (int i = y; i < y + height; i++)
                {
                    for (int j = x; j < x + width; j++)
                    {
                        cells[i][j][player] = 2; // value 2 means there is a ship now
                    }
                }

                // draw the ship
                draw_ship(y, x, height, width, player, 3);

                // count placed ships
                shipCounter++;

                // set size of the next ship
                switch (shipCounter)
                {
                // 2 ships with size 3
                case 1:
                case 2:
                    if (rotationAspect % 2 == 1)
                    { // vertical
                        height = 1;
                        width = 3;
                    }
                    else
                    { // horizontal
                        height = 3;
                        width = 1;
                    }

                    break;
                // 3 ships with size 2
                case 3:
                case 4:
                case 5:
                    if (rotationAspect % 2 == 1)
                    { // vertical
                        height = 1;
                        width = 2;
                    }
                    else
                    { // horizontal
                        height = 2;
                        width = 1;
                    }
                    break;
                // 4 ships with size 1
                case 6:
                case 7:
                case 8:
                case 9:
                    height = 1;
                    width = 1;
                    break;
                default:
                    // do nothing
                    break;
                }
            }
            else
            {
                sound_play("Sounds/error.wav"); // ship cannot be placed -> plays error sound
            }

            // reset cell counter
            cellCounter = 0;

            break;
        case 'q':
        case 'Q':
            // exit gfx framework
            exit_gfx();
            exit(0);
            break;
        default:
            // do nothing
            break;
        }
    }

    // update number of ships (start = 20)
    if (player == 0)
        firstPlayerShips = 20;
    else if (player == 1)
        secondPlayerShips = 20;

    // play the sound of placed ships
    sound_play("Sounds/correct.wav");
}

// automatically generates 10 ships on a specific arena (1 with size of 4; 2 with size of 3; 3 with size of 2 and 4 with size of 1)
void generateRandomShips(int player)
{
    int y = 0;           // starting x coorinate of new ships
    int x = 0;           // starting y coorinate of new ships
    int sizeY = 4;       // starting height of new ships
    int sizeX = 1;       // starting width of new ships
    int shipCounter = 0; // counting placed ships
    int cellCounter = 0; // counts cells filled with ships arround the ship
    int tmpSizeY;        // to save temporary height of a ship before rotating
    int tmpSizeX;        // to save temporary width of a ship before rotating
    int rotationArgument;

    while (shipCounter < 10)
    {

        // generate rotation argument of a ship (0 - no rotation; 1 - rotation)
        rotationArgument = (rand() % 2);
        // rotation
        if (rotationArgument == 1)
        {
            // swap width and height
            tmpSizeY = sizeY;
            tmpSizeX = sizeX;

            sizeY = tmpSizeX;
            sizeX = tmpSizeY;
        }

        // generate random y coordinate of a ship
        y = (rand() % (10 - (sizeY - 1)));

        // generate random x coordinate of a ship
        x = (rand() % (10 - (sizeX - 1)));

        // check if there is already a ship
        for (int i = 0; i < sizeY + 2; i++)
        {
            for (int j = 0; j < sizeX + 2; j++)
            {
                int cellY = (y - 1) + i;
                int cellX = (x - 1) + j;

                if (cellY >= 0 && cellX >= 0 && cellY <= 9 && cellX <= 9)
                {
                    if (cells[cellY][cellX][player] == 2)
                    {
                        cellCounter++;
                    }
                }
            }
        }

        if (cellCounter == 0) // means there are no ships
        {
            // save the ship into an array
            for (int i = y; i < y + sizeY; i++)
            {
                for (int j = x; j < x + sizeX; j++)
                {
                    cells[i][j][player] = 2; // value 2 means there is a ship now
                }
            }

            if (!manualShipPlacement && player == 0)
                draw_ship(y, x, sizeY, sizeX, player, 3);

            // count placed ships
            shipCounter++;

            // set size of the next ship
            switch (shipCounter)
            {
            // 2 ships with size 3
            case 1:
            case 2:
                sizeY = 3;
                sizeX = 1;
                break;
            // 3 ships with size 2
            case 3:
            case 4:
            case 5:
                sizeY = 2;
                sizeX = 1;
                break;
            // 4 ships with size 1
            case 6:
            case 7:
            case 8:
            case 9:
                sizeY = 1;
                sizeX = 1;
                break;
            default:
                // do nothing
                break;
            }
        }

        // reset cell counter
        cellCounter = 0;
    }

    // update number of ships (start = 20)
    if (player == 0)
        firstPlayerShips = 20;
    else if (player == 1)
        secondPlayerShips = 20;
}

// checks all the cells on a specific arena
void shootWholeArena(int player)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            shoot(i, j, player);
        }
    }
}

// clears the pointer on y, x position. used in turn() method
void clearPointer(int y, int x)
{
    switch (cells[y][x][1])
    {
    case 0:
    case 2:
        fillOneCell(y, x, 1, aliveShipColor, emptyCellChar); // the cell is not yet shot
        break;
    case 1:
        fillOneCell(y, x, 1, aliveShipColor, shotCellChar); // the cell is shot and there is no ship
        break;
    case 3:
        fillOneCell(y, x, 1, damagedShipColor, damagedShipChar); // the cell is shot and there is a ship
        break;
    default:
        break;
    }
}

// lets first player to make a turn
void turn()
{

    bool missed = false;
    int result;
    while (!missed && secondPlayerShips != 0 && secondPlayerShips != 0)
    {
        fillOneCell(yPointer, xPointer, 1, interfaceColor, pointerChar);
        refresh();

        // asks for key input
        switch (getch())
        {
        case 'w':
        case 'W':
        case KEY_UP: // up
            clearPointer(yPointer, xPointer);
            if (yPointer > 0)
                yPointer -= 1;
            break;
        case 'a':
        case 'A':
        case KEY_LEFT: // left
            clearPointer(yPointer, xPointer);
            if (xPointer > 0)
                xPointer -= 1;
            break;
        case 's':
        case 'S':
        case KEY_DOWN: // down
            clearPointer(yPointer, xPointer);
            if (yPointer < 9)
                yPointer += 1;
            break;
        case 'd':
        case 'D':
        case KEY_RIGHT: // right
            clearPointer(yPointer, xPointer);
            if (xPointer < 9)
                xPointer += 1;
            break;
        case ' ': // shot
            clearPointer(yPointer, xPointer);

            // refresh the screen
            refresh();
            // check the cell at y, x

            result = shoot(yPointer, xPointer, 1);
            // refresh the screen
            refresh();

            switch (result)
            {
            case 0: // no shot by player was made
                missed = false;
                sound_play("Sounds/error.wav"); // shot cannot be made -> plays error sound
                break;
            case 1: // player missed
                missed = true;
                sound_play("Sounds/splash.wav"); // playing sound of a splash
                msleep(2000);
                break;
            case 2:
                missed = false;                     // player hit a ship
                sound_play("Sounds/explosion.wav"); // playing sound of an explosion
                msleep(2000);                       // pause before drawing pointer again so player sees the damaged ship
                break;
            default:
                break;
            }
            break;
        case 'q':
        case 'Q':
            // exit gfx framework
            exit_gfx();
            exit(0);

            break;
        default:
            break;
        }
    }
}

// generates a computers turn
void computerTurn()
{

    if (tolower(getch()) == 'q')
    {
        exit_gfx();
        exit(0);
    }

    int y = 0;
    int x = 0;
    bool missed = false;
    int result;

    while (!missed && firstPlayerShips != 0 && secondPlayerShips != 0)
    {
        y = rand() % 10; // generate y coordinate of a shot
        x = rand() % 10; // generate x coordinate of a shot

        result = shoot(y, x, 0); // make a shot
        refresh();               // refresh the screen
        switch (result)
        {
        case 0: // no shot by computer was made
            missed = false;
            break;
        case 1: // computer missed
            missed = true;
            sound_play("Sounds/splash.wav"); // playing sound of a splash
            msleep(2000);
            break;
        case 2:
            missed = false;                     // computer hit a ship
            sound_play("Sounds/explosion.wav"); // playing sound of an explosion
            msleep(2000);
            break;
        default:
            break;
        }
    }
}

// prints out the game's outcome
void playerWon()
{
    // gray
    use_color(1);

    if (secondPlayerShips == 0)
    {
        const char text[] = "YOU WON!";
        int tx = max_x / 2;
        int ty = (max_y - 4) / 2 + 1;
        init_grid_font();
        draw_grid_text(ty - get_grid_char_lines() / 2, tx - strlen(text) * get_grid_char_cols() / 2, text);

        sound_play("Sounds/win.wav"); // play a win sound
    }
    if (firstPlayerShips == 0)
    {
        const char text[] = "COMPUTER WON!";
        int tx = max_x / 2;
        int ty = (max_y - 4) / 2 + 1;
        init_grid_font();
        draw_grid_text(ty - get_grid_char_lines() / 2, tx - strlen(text) * get_grid_char_cols() / 2, text);

        sound_play("Sounds/lose.wav"); // play a lose sound
    }

    const char quit[] = "Press 'q' to quit the game";
    move(LINES - 3, (COLS / 2) - strlen(quit) / 2);
    printw(quit);

    refresh();
}

// lets the player decide how they want to place their ships (manual or automatically)
void chooseGameMode()
{
    clear();

    // initialize text
    const char firstLine[] = "DO YOU WANT TO PLACE";
    const char secondLine[] = "SHIPS BY YOURSELF?";

    // calculate psotion of the text
    int tx = max_x / 2;
    int ty = (max_y - 4) / 2 + 1;
    init_grid_font();

    // draw text
    draw_grid_text(ty - 5 - get_grid_char_lines() / 2, tx - strlen(firstLine) * get_grid_char_cols() / 2, firstLine);
    draw_grid_text(ty - get_grid_char_lines() / 2, tx - strlen(secondLine) * get_grid_char_cols() / 2, secondLine);

    // print variants
    const char choiceLine[] = "Yes, let me place my ships          No, let computer generate my ships";
    move(LINES - 7, (COLS / 2) - strlen(choiceLine) / 2);
    printw(choiceLine);

    const char hintLine[] = "Use arrow keys or WASD and space to make a choice.";
    move(LINES - 2, 4);
    printw(hintLine);

    // draw start underline
    draw_line(LINES - 6, (COLS / 2) - strlen(choiceLine) / 2, LINES - 6, (COLS / 2) - strlen(choiceLine) / 2 + 26);

    while (menuChoiceMade == false)
    {
        switch (getch())
        {
        case 'd':
        case 'D':
        case KEY_RIGHT:
            // clear another line
            for (int i = 0; i < 200; i++)
            {
                move(LINES - 6, i);
                printw(" ");
            }

            // draw new line
            draw_line(LINES - 6, (COLS / 2) - strlen(choiceLine) / 2 + 36, LINES - 6, (COLS / 2) - strlen(choiceLine) / 2 + 36 + 34);
            refresh();

            manualShipPlacement = false;
            break;
        case 'a':
        case 'A':
        case KEY_LEFT:
            for (int i = 0; i < 200; i++)
            {
                move(LINES - 6, i);
                printw(" ");
            }

            // draw new line
            draw_line(LINES - 6, (COLS / 2) - strlen(choiceLine) / 2, LINES - 6, (COLS / 2) - strlen(choiceLine) / 2 + 26);
            refresh();

            manualShipPlacement = true;
            break;
        case ' ':
            menuChoiceMade = true;
            sound_play("Sounds/correct.wav");
            break;
        case 'q':
        case 'Q':
            // exit gfx framework
            exit_gfx();
            exit(0);
            break;
        default:
            break;
        }
    }

    clear();
}

// main method
int main()
{
    // initialize frameworks
    init_gfx();
    init_color();
    sound_init();

    // get screen size
    getmaxyx(stdscr, max_y, max_x);

    // generates new seed for random numbers
    srand(time(NULL));

    // makes all chars bold
    use_attr_bold();

    // check resolution of the terminal window
    if (COLS < 189 || LINES < 44) // smaller than required
    {
        // prints out that the terminal window is too small
        move(1, 1);
        printw("Your current terminal resolution is %d x %d, which is too small. The minimum required resolution is 190 x 45.", COLS, LINES);

        move(2, 1);
        printw("Please, check your terminal settings and try again.");

        move(3, 1);
        printw("Press 'q' to quit.", COLS, LINES);

        refresh();

        // wait for pressing 'q' to quit the game
        while (tolower(getch()) != 'q')
            msleep(1);

        // exit gfx framework
        exit_gfx();

        return (0);
    }

    // draws the intro, including game's name and hint to start the game
    intro();

    // lets the player decide how they want to place their ships (manual or automatically)
    chooseGameMode();

    // draws two arenas for two players
    setup();

    // lets the first player to place their ships or generates them
    if (manualShipPlacement)
        placeShips(0);
    else
        generateRandomShips(0);

    // generate random ships on the second arena
    generateRandomShips(1);

    // game loop
    while (firstPlayerShips != 0 && secondPlayerShips != 0)
    {
        // players turn
        turn();

        // refresh the window
        refresh();

        // computers turn
        computerTurn();

        // refresh the window
        refresh();
    }

    // clear the screen
    clear();

    // player won message
    playerWon();

    // wait for pressing 'q' to quit the game
    while (tolower(getch()) != 'q')
        msleep(1);

    // exit gfx framework
    exit_gfx();

    return (0);
}
