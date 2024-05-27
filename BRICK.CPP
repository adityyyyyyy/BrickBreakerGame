//brick breaker game
 #include<stdio.h>               // for standard input and output functions
#include<graphics.h>        //for graphics functions
#include<conio.h>            // for console input and output functions
#include<dos.h>            //for delay functions
#include<stdlib.h>      //for standard library functions like exit.
#include<time.h>        // for time related functions

#define UP 72       //constants representing arrow keys codes for movement
#define DOWN 80
#define LEFT 75
#define RIGHT 77

int paddle_x = 300, paddle_y = 450;    //coordinates of paddle
int ball_x = 300, ball_y = 400; //coordinates of ball
int dx = -2,dy = -2;  // direction of ball movement
int score = 0;  // players score
int bricks[5][10];     // 2D array representing bricks layout
char buf[10];   // buffer for storing score as string

void showgamedescription()   //draws welcome screen and describes description about game
{
cleardevice();
setcolor(3);
rectangle(0,0,639,479);
setfillstyle(8,3);
floodfill(320,240,3);
setcolor(15);
rectangle(15,15,624,464);
setfillstyle(1,15);
floodfill(312,232,15);
setcolor(1);
settextstyle(1,HORIZ_DIR,4);
outtextxy(100,50,"WELCOME TO");
settextstyle(1,0,6);
outtextxy(125,120," BRICK BREAKER");
setcolor(2);
rectangle(50,100,100,125);
setfillstyle(1,2);
floodfill(75,110,2);
setcolor(5);
rectangle(25,125,75,150);
setfillstyle(1,5);
floodfill(50,130,5);
setcolor(6);
rectangle(75,125,125,150);
setfillstyle(1,6);
floodfill(100,130,6);
setcolor(9);
rectangle(50,150,100,175);
setfillstyle(1,9);
floodfill(75,160,9);
setcolor(10);
rectangle(25,175,75,200);
setfillstyle(1,10);
floodfill(50,180,10);
setcolor(12);
rectangle(75,175,125,200);
setfillstyle(1,12);
floodfill(100,180,12);
setcolor(13);
rectangle(25,200,75,225);
setfillstyle(1,13);
floodfill(50,210,13);
setcolor(14);
rectangle(75,200,125,225);
setfillstyle(1,14);
floodfill(100,210,14);
setcolor(4);
rectangle(50,225,100,250);
setfillstyle(1,4);
floodfill(75,235,4);
setcolor(0);
rectangle(324,234,612,462);
setfillstyle(9,0);
floodfill(468,348,0);
setcolor(15);
rectangle(328,238,608,458);
settextstyle(1,0,1);
outtextxy(350,250,"DESCRIPTION ABOUT GAME:");
settextstyle(2,0,5);
outtextxy(355,300,"1. Use LEFT & RIGHT Arrow keys");
outtextxy(360,320," to move the Paddle");
outtextxy(355,370,"2.BREAK ALL the BRICKS to WIN");
outtextxy(410,420,"*PRESS ANY KEY TO START*");
setcolor(1);
circle(75,275,12);
setfillstyle(1,1);
floodfill(75,275,1);
circle(157,375,12);
floodfill(157,375,1);
circle(225,275,12);
floodfill(225,275,1);
setcolor(9);
line(75,290,142,375);
line(78,290,144,375);
line(171,375,225,290);
line(174,375,228,290);
setcolor(4);
rectangle(75,400,250,420);
setfillstyle(9,4);
floodfill(175,410,4);
int bx=500,by=75,r=30;
setfillstyle(1,3);
setcolor(14);
fillellipse(bx,by,r,r);
circle(bx,by,28);
fillellipse(bx-10,by-15,5,5);
setlinestyle(1,0,3);
setcolor(13);
line(440,75,500,70);
line(430,75,500,60);
line(560,75,500,80);
line(570,75,500,90);
setlinestyle(0,0,1);
rectangle(420,50,440,125);
setfillstyle(1,13);
floodfill(430,100,13);
setcolor(14);
rectangle(560,50,580,125);
setfillstyle(1,14);
floodfill(570,100,14);
setcolor(1);
rectangle(400,25,420,100);
setfillstyle(1,1);
floodfill(410,35,1);
rectangle(580,100,600,150);
floodfill(590,125,1);
setcolor(15);
getch();
}

void initialize(){                     // initializes the bricks array to show its initial position
    int i,j;
    for(i=0;i<5;i++){
	for(j=0;j<10;j++){
	    bricks[i][j]=1;
	}
    }
}
void drawSpaceBackground() {      //draw stars in background using random pixel position
    setcolor(WHITE);
    setbkcolor(1);
    // Draw stars in the background
    for (int i = 0; i < 50; i++) {
	putpixel(rand() % 640, rand() % 480, WHITE);
}

}

void draw(){    // clears the screen and draw the game component i.e., the paddle, ball and bricks
   int i,j;
   cleardevice();
   drawSpaceBackground();
   rectangle(0,0,639,479);
   rectangle(4,4,635,475);
   rectangle(2,2,637,477);
   setfillstyle(9,15);
   bar(paddle_x,paddle_y,paddle_x + 100, paddle_y + 10);
   setfillstyle(1,YELLOW);
   fillellipse(ball_x,ball_y, 10,10);

   for(i=0;i<5;i++){
    for(j=0;j<10;j++){
	if(bricks[i][j] == 1)
	{   switch(i)
	{
	case 0: setfillstyle(1,13);
	break;
	case 1: setfillstyle(1,12);
	break;
	case 2: setfillstyle(1,11);
	break;
	case 3: setfillstyle(1,10);
	break;
	case 4: setfillstyle(1,14);
	break;

	}
	    bar(j * 60 + 12, i * 20+ 12, j* 60+ 57, i * 20 +27);
	 }
    }
   }
   sprintf(buf,"SCORE: %d",score);
   outtextxy(550, 450, buf);
   if(score==50)
   {
   settextstyle(4,0,10);
   outtextxy(200,234,"WIN");     // it also display win message when all the bricks are broken
   }
   settextstyle(2,0,5);
}

void input(){      //  handles player input by checking for key presses 
    if (kbhit()){
	switch (getch()){
	case LEFT:  // handles paddle’s position when user uses left arrow
	    paddle_x -= 20; 
	    break;
	case RIGHT: //handles paddle’s position when user uses right arrow
	    paddle_x += 20;
	    break;
	}
    }

    if(paddle_x<=0){    // insures paddle’s stage within the ground
	paddle_x=0;
    }
    if(paddle_x>=500){
	paddle_x=500;
    }
}

void move(){    //updates the ball position and handle the collision
    int i,j;
    ball_x += dx;
    ball_y += dy;

    if(ball_x >= paddle_x && ball_x <= paddle_x + 100 && ball_y >= paddle_y - 10 && ball_y <= paddle_y + 10){
	dy = -dy;
    } // changes the ball direction when ball hits the paddle

    for(i=0;i<5;i++){
	for(j=0; j<10; j++){
	    if(bricks[i][j] == 1){
		if(ball_x >= j * 60 + 10 && ball_x <= j * 60 + 60 && ball_y >= i * 20 + 10 && ball_y <= i * 20 + 30){
		    bricks[i][j] = 0;
		    dy = -dy;
		    score++;
		} // remove the bricks when ball hits the bricks and update the score
	    }
	}
    }

    if(ball_x<=0 || ball_x>=590){
	dx = -dx;
    } //changes ball’s  direction when ball hits the wall

    if(ball_y <= 0){
	dy = -dy;  // ends game when ball goes beyond the boundary
    }

    if(ball_y >= 490){
       settextstyle(7,0,2);
       setcolor(11);
       rectangle(100,100,500,400);
       setfillstyle(10,11);
       floodfill(200,150,11);
       rectangle(110,110,490,390);
       setcolor(10);
       rectangle(105,105,495,395);
       setfillstyle(1,10);
       floodfill(195,145,10);

       setcolor(4);
	outtextxy(120,200,"GAME OVER");
	sprintf(buf,"FINAL SCORE : %d",score);
	outtextxy(120,250,buf);
	outtextxy(130,300,"*PRESS ANY KEY TO EXIT");
	getch();
	exit(0);
    }
}

int main()
/*   
•	initializes the graphics mode and display the game description.
•	Calls initialize() to set up the initial game state.
•	Enters the game loop where move(), input(), and draw() functions are called continuously.
•	Exits the loop when the game is over or when the player closes the windows.
*/
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"c:\\turboc3\\bgi");
    showgamedescription();
    initialize();
    draw();

    while(1){
	move();
	input();
	draw();

	delay(10);
    }

    getch();
    closegraph();
    return 0; }
