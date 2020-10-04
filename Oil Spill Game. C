Oil Spill Game in C.

#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<dos.h>

#define L  75
#define R  77
		 		  /*  variable initialisations */

union REGS i,o;
int ch1,ch2;
int mx,my,vx=270,vy;
int temp,retval;
char s[20],s1[20];
char ch;
int gd=DETECT,gm;
int x,y=400,r,c=7,score=0,lifes=4,flag=0,dlyfactor=0;

		        /*  main function */
main()
{
 initialise();
 firstscreen();
 displaylifes();
 displayscore();
 welcome();
 while(1)
 {
   condition1();
   display_drop();
   is_keyhit();
   check_catchdrop();
   check_looselife();
 }
  nosound();
}
		      /*  sub functions */


initialise()
 {
    initgraph(&gd,&gm,"");
    mx=getmaxx();my=getmaxy();
    setcolor(4);
    x=mx/2;

    image(x,y,c);
    vy=20;
 }
firstscreen()
 {

     button3d(100,0,430,5);
     button3d(100,0,5,450);
     button3d(100,450,430,5);
     button3d(525,0,5,455);

   setfillstyle(1,7);
     bar(270,5,275,10);
     bar(320,5,325,10);
     bar(370,5,375,10);

   setfillstyle(1,8);
     bar(267,10,278,15);
     bar(317,10,328,15);
     bar(367,10,378,15);

     button3d(280,448,80,9);
     setcolor(4);
     outtextxy(290,450,"OIL SPIL");
 }
welcome()
 {
   setfillstyle(1,0);
      bar(200,250,450,350);
      clk_but3d(200,250,250,100);
      settextstyle(0,0,2);
      setcolor(4);
      outtextxy(240,280," WELCOME");
      outtextxy(215,310, " TO OILSPIL");
      getch();
      setfillstyle(1,0);
      bar(200,250,453,353);
      return;
  }


is_keyhit()
 {
  if(kbhit())
   {
     i.h.ah=0;
     int86(22,&i,&o);
     if(o.h.ah==1)  {   nosound();closegraph();exit(0);            }
     if(o.h.ah==75) {
sound(1800);image(x,y,0);x=x-10;image(x,y,c);nosound(); }
     if(o.h.ah==77) {
sound(1800);image(x,y,0);x=x+10;image(x,y,c);nosound(); }
     if(o.h.ah==80) {   dlyfactor+=250; }
     if(o.h.ah==72) {   dlyfactor-=250; }
   }
 }
image(int x,int y,int c)
  {
    int b;
    setcolor(c);
    rectangle(x-10,y+6,x+10,y+20);
    setcolor(0);
    line(x-9,y+6,x+9,y+6);
    setfillstyle(1,c);
    bar(x-9,y+6,x+9,y+19);
    setfillstyle(1,0);
     bar(x-6,y+6,x+6,y+19);
    setcolor(c);
    for(b=1;b<=6;b++)
    line(x-10+b,y+19+b,x+10-b,y+19+b);
    setfillstyle(1,c);
    bar(x-1,y+19+b,x+1,y+25+b);
    fillellipse(x,y+25+b+3,8,3);
  }
object(int x,int y,int c)
  {
    setcolor(c);
    setfillstyle(1,c);
    fillellipse(x,y+5,4,8);
  }
condition1()
    {
      if(flag==1||vy>410)
		 {
		   vy = 20;
		   temp = random(3);
		    if(temp==0)  vx=270;
		     else if(temp==1) vx=320;
		       else if(temp==2) vx =370;
		   flag=0;
		 }
    }


check_looselife()
   {
    if(lifes==0)
     {
      setfillstyle(1,0);
      bar(200,250,450,350);
      clk_but3d(200,250,250,100);
      settextstyle(0,0,2);
      setcolor(1);
      outtextxy(240,290,"GAME OVER");
      getch();
      closegraph();
      play_again();
      exit(0);
     }
   }
display_drop()
  {
   object(vx,vy,8);
   delay(3000+dlyfactor);
   object(vx,vy,0);
   vy+=10;
  }
check_catchdrop()
  {
   if((x-5<=vx)&&(vx<=x+5)&&vy==410)
       displayscore();
   else if(vy>410)
      displaylifes();
   nosound();
  }
   displaylifes()
   {
      settextstyle(0,0,1);
      clk_but3d(0,440,90,13);
      setcolor(7);
      outtextxy(5,445,s1);
      lifes = lifes -1;
      sprintf(s1,"LIFES = %d", lifes);
      setcolor(4);
      outtextxy(5,445,s1);
      flag=0;
   }
   displayscore()
   {
       settextstyle(0,0,1);
       clk_but3d(540,440,90,13);
       setcolor(7);
       outtextxy(545,445,s);
       score=score+1;
       sprintf(s,"SCORE = %d",score);
       setcolor(4);
       outtextxy(545,445,s);
       flag=1;
       vy=20;
   }
   button3d(int x,int y,int l,int w)
 {
    setcolor(LIGHTGRAY);
    setfillstyle(1,LIGHTGRAY);

    bar(x,y,x+l,y+w);

    setcolor(WHITE);
    line(x,y,x+l,y);
    line(x,y,x,y+w);

    setcolor(DARKGRAY);
    line(x+l+1,y,x+l+1,y+w+1);
    line(x,y+w+1,x+l+1,y+w+1);
 }
 clk_but3d(int x,int y,int l,int w)
 {
    setcolor(LIGHTGRAY);
    setfillstyle(1,LIGHTGRAY);

    bar(x,y,x+l,y+w);

    setcolor(DARKGRAY);
    line(x,y,x+l,y);
    line(x,y,x,y+w);

    setcolor(WHITE);
    line(x+l+1,y,x+l+1,y+w+1);
    line(x,y+w+1,x+l+1,y+w+1);
 }


 letter(int x,int y,int l,int w)
  {
    char s[1];
    int ch=3;
    setcolor(RED);
    sprintf(s,"%c",ch);
    outtextxy(x + l/4 + 2,y + w/5, s);
  }
 restore_defaults()
  {
   y=400;c=7;score=0;lifes=4;flag=0;dlyfactor=0;
  }
 play_again()
  {
    printf("To Play again Press 'y'");
    if(getch()=='y')
      {
      restore_defaults();
      main();
      }
    else
     }
