#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <graphics.h>
#include <dos.h>
#include <string.h>
 
void initialize_graphics_mode();
int get_key();
void draw();
 
union REGS i, o;
 
main()
{
  int key, i = 0, xpos, ypos, button;
  char arr[200], temp[5], *ptr;
  char a[] = "C:\\Progra~1\\Mozill~1\\firefox ";
 
  strcpy(arr,a);
 
  i = strlen(a);
 
  initialize_graphics_mode();
 
  draw();
 
  while(1)
  {
    if(kbhit())
      key = get_key();
 
    if((key>=97&&key<=122)||(key>=65&&key<=90)||key==46||key==47||key==63)
    {
      arr[i] = key;
      sprintf(temp,"%c",arr[i]);
      outtext(temp);
      if(getx()>470)
      {
        clearviewport();
        moveto(5,2);
      }
      i++;
    }
    else if (key == 13)
    {
      arr[i] = '\0';
      system(arr);
      break;
    }
    else if (key == 27)
    {
      closegraph();
      exit(EXIT_SUCCESS);
    }
    if(button==1&&xpos>=150&&xpos<=480&&ypos>=300&&ypos<=330)
    {
      system("C:\\Progra~1\\Mozill~1\\firefox programmingsimplified.com");
      break;
    }
    key = -1;
  }
 
  closegraph();
  return 0;
}
 
void initialize_graphics_mode()
{
  int gd = DETECT, gm, errorcode;
 
  initgraph(&gd,&gm,"C:\\TC\\BGI");
  errorcode = graphresult();
 
  if( errorcode != grOk )
  {
    printf("Graphics error : %s\n",grapherrormsg(errorcode));
 
    printf("Press any key to exit...\n");
    getch();
    exit(EXIT_FAILURE);
  }
}
 
int get_key()
{
  i.h.ah = 0;
  int86(22, &i, &o);
 
  return( o.h.al );
}
 
void draw()
{
  settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
  outtextxy(275,11,"Web Browser");
  outtextxy(155,451,"<a href="http://www.programmingsimplified.com"">www.programmingsimplified.com"</a>);
  outtextxy(5,105,"Enter URL : ");
  rectangle(120,100,600,130);
  setviewport(121,101,599,129,1);
  moveto(5,1);
}
