#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<unistd.h>
int height=20, width=20, i ,j, gameover, score;
int x,y,fruitx,fruity, flag;
int main()
{
    setup();
    while(!gameover){
        draw();
        input();
        logic();
    }
    return 0;
}
void draw()
{
    system("cls");
    for(i=0;i<height;i++)
    {
        for(j=0;j<width;j++)
        {
            if(i==0||j==0||i==width-1||j==height-1)
            {
                printf("#");
            }
            else{
                if(i==x&&j==y)
                    printf("0");
                else if(i==fruitx&&j==fruity)
                    printf("*");
                else
                    printf(" ");
            }
        }
       printf("\n");
   }
   printf("%d\n", score);
   printf("Press x to quit the game");

}
void setup()
{
    gameover=0;
    x=height/2;
    y=width/2;
    label1:
        fruitx=rand()%20;
        if(fruitx==0)
            goto label1;
    label2:
        fruity=rand()%20;
        if(fruity==0)
            goto label2;
        score=0;
}

 void input()
 {
    if(kbhit())
    {
        switch(getch())
        {
            case 'a':
                flag=1;
                break;
            case 'b':
                flag=2;
                break;
            case 'c':
                flag=3;
                break;
            case 'd':
                flag=4;
                break;
            case 'x':
                gameover=1;
                break;

        }
    }
 }
void logic()
{
    sleep(0.01);
    switch(flag)
    {
        case 1:
            y--;
            break;
        case 2:
            x++;
            break;
        case 3:
            y++;
            break;
        case 4:
            x--;
            break;
        default:
            break;
    }
    if(x<0||y<0||x>height||y>width)
    {
        gameover=1;

    }
    if(x==fruitx&&y==fruity)
    {
        label3:
        fruitx= rand()%20;
        if(fruitx==0)
            goto label3;

        label4:
        fruity=rand()%20;
        if(fruity==0)
            goto label4;
        score=score+10;
    }
}

