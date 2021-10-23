#include<stdio.h>  // HEADER FILE FOR STANDARD I/0
#include<graphics.h> // HEADER FILE FOR GRAPHICS MODE
#include<dos.h>     //  HEADER FILE FOR ENABLING SOUND
#include<conio.h>  // HEADER FILE FOR CONSOLE I/O
#include<stdlib.h> // HEADER FILE FOR LIBRARY FUNCTIONS
union REGS i, o;
int initmouse();        // FUNCTION TO INITIALIZE MOUSE POINTER
void showmouseptr();   // FUNCTION TO SHOW POINTER
void restrictmouseptr(int, int, int, int); // FUNCTION TO RESTRICT POINTER
void getmousepos(int*, int*, int*); // TO GET POINTER POSITION
void format();     // FUNCTION TO DRAW LAYOUT OF EVM
void graph();      // FUNCTION TO DISPLAY RESULT AS GRAPH
void welcome();    // FUNCTION TO DISPLAY WELCOME MESSAGE
void boundry();
int vote1 = 0, vote2 = 0, vote3 = 0, vote4 = 0;  // VARIABLES TO HOLD VOTES FOR CANDIDATES
int button, x, y;
int main()
{
    int  gd = DETECT, gm;
    initgraph(&gd, &gm, "c:\\turboc3\\bgi");  // INITIALIZING GRAPHICS MODE
    randomize();
    boundry();
    welcome();                // CALLING WELCOME FUNCTION
    cleardevice();            // CLEARING THE SCREEN
    format();                 // CALLING FORMAT FUNCTION
    showmouseptr();
    restrictmouseptr(0, 0, 675, 435);    // RESTRICTING MOUSE POINTER WITHIN SCREEN
    do
    {
        getmousepos(&button, &x, &y);
        if ((button & 1) == 1 && x > 475 && x < 580 && y>250 && y < 280)
        {
            break;
        }
        else if ((button & 1) == 1 && x > 280 && x < 380 && y>105 && y < 125)
        {
            setcolor(RED);circle(270, 115, 5);
            sound(1200);
            delay(500);
            nosound();
            setcolor(BLACK);circle(270, 115, 5);
            vote1++;
        }
        else if ((button & 1) == 1 && x > 280 && x < 380 && y>155 && y < 175)
        {
            setcolor(RED);circle(270, 165, 5);
            sound(1200);
            delay(500);
            nosound();
            setcolor(BLACK);circle(270, 165, 5);
            vote2++;
        }
        else if ((button & 1) == 1 && x > 280 && x < 380 && y>205 && y < 225)
        {
            setcolor(RED);circle(270, 215, 5);
            sound(1200);
            delay(500);
            nosound();
            setcolor(BLACK);circle(270, 215, 5);
            vote3++;
        }
        else if ((button & 1) == 1 && x > 280 && x < 380 && y>255 && y < 275)
        {
            setcolor(RED);circle(270, 265, 5);
            sound(1200);
            delay(500);
            nosound();
            setcolor(BLACK);circle(270, 265, 5);
            vote4++;
        }

    }               // END OF DO
    while (1);
    cleardevice();
    initmouse();
    showmouseptr();
    boundry();
    graph();
    getch();
    return 0;
}                   // END OF MAIN FUNCTION
void boundry()
{
    setcolor(1 + random(14));
    rectangle(0, 0, 635, 475);
    setcolor(1 + random(14));
    rectangle(3, 3, 632, 472);
}
void welcome()
{
    randomize();
    settextstyle(8, 0, 4);
    setcolor(1 + random(14));
    outtextxy(200, 100, "WELCOME");
    delay(800);
    setcolor(1 + random(14));
    outtextxy(250, 160, "TO");
    delay(800);
    setcolor(1 + random(14));
    outtextxy(50, 220, "ELECTRONIC VOTING SYSTEM");
    delay(800);
    while (!kbhit())
    {
        setcolor(1 + random(14));
        outtextxy(50, 400, "Press any key to continue.....");
        delay(500);
        setcolor(BLACK);
        outtextxy(50, 400, "Press any key to continue.....");
        delay(500);
    }


}

void format()
{
    setcolor(6);
    rectangle(90, 30, 400, 380);
    rectangle(87, 27, 403, 383);
    settextstyle(0, 0, 5);
    outtextxy(140, 40, "E V M");
    line(90, 80, 400, 80);
    settextstyle(8, 0, 2);

    outtextxy(100, 100, "MUKUND");
    rectangle(95, 100, 250, 130);

    outtextxy(100, 150, "TUSAHR");
    rectangle(95, 150, 250, 180);


    outtextxy(100, 200, "Maneesh");
    rectangle(95, 200, 250, 230);

    outtextxy(100, 250, "SOROV");
    rectangle(95, 250, 250, 280);


    rectangle(475, 250, 580, 280);
    outtextxy(480, 250, "RESULT");


}
void showmouseptr()
{
    i.x.ax = 1;
    int86(0x33, &i, &o);
}
void restrictmouseptr(int x1, int y1, int x2, int y2)
{
    i.x.ax = 7;
    i.x.cx = x1;
    i.x.dx = x2;
    int86(0x33, &i, &o);
    i.x.ax = 8;
    i.x.cx = y1;
    i.x.dx = y2;
    int86(0x33, &i, &o);
}
void getmousepos(int* button, int* x, int* y)
{
    i.x.ax = 3;
    int86(0x33, &i, &o);
    *button = o.x.bx;
    *x = o.x.cx;
    *y = o.x.dx;
}
void graph()
{
    outtextxy(200, 100, "RESULTS(in % votes)");
    int candidate1 = ((vote1 * 100) / (vote1 + vote2 + vote3 + vote4));
    int candidate2 = ((vote2 * 100) / (vote1 + vote2 + vote3 + vote4));
    int candidate3 = ((vote3 * 100) / (vote1 + vote2 + vote3 + vote4));
    int candidate4 = ((vote4 * 100) / (vote1 + vote2 + vote3 + vote4));

    setcolor(2);
    rectangle(100, 300, 130, 300 - candidate1);outtextxy(100, 300, "Mukund");
    rectangle(200, 300, 230, 300 - candidate2);outtextxy(200, 300, "Tushar");
    rectangle(300, 300, 330, 300 - candidate3);outtextxy(300, 300, "Maneesh");
    rectangle(400, 300, 430, 300 - candidate4);outtextxy(400, 300, "Saurabh");

    setcolor(1 + random(14));
    rectangle(545, 400, 600, 430);
    outtextxy(550, 400, "EXIT");

    do
    {
        getmousepos(&button, &x, &y);
        if ((button & 1) == 1 && x > 545 && x < 600 && y>400 && y < 430)
        {
            break;
        }
    }               // END OF DO
    while (1);


}
initmouse()
{
    i.x.ax = 0;
    int86(0x33, &i, &o);
    return(o.x.ax);
}