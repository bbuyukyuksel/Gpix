#include <windows.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#pragma GCC diagnostic ignored "-Wwrite-strings"
void DOS();
void DOS_Open();
void DOS_Save();
void DOS_KonumSec(char*,int);
void RefreshPanel();

void textColor(char*,int);
void fixPath(char * );
void infoForFileCommand(void);

void Window();
void RefreshWindow();
void GuncelRenkler(int,int);
void Mouse();
void Draw(int,int,char,int,int);

void line_square(int,int,int,int,int);
void pen_image();
void trigon(int,int,int,int);
void diktortgen(int,int,int,int);
int power(int,int);
int uzaklik2noktaarasi(int,int,int,int);
void alertBar(bool control);


int tempFgColor, tempBkColor;
int main()
{
    initwindow(1000,600,"Gpix");
    Window();
    Mouse();
    getch();
    closegraph();
    return 0;
}


void line_square(int left,int top,int right,int bottom,int clr){
    int x1 = left,x2=right;
    int y1 = top,y2=bottom;
    setcolor(clr);
    line(x1,y1,x2,y1);
    line(x1,y2,x2,y2);
    line(x1,y1,x1,y2);
    line(x2,y1,x2,y2);
}
void pen_image(void){
    int x1,x2,xaverage,y1,y3,y2;
    int maxx = getmaxx();
    int maxy = getmaxy();
    x1=maxx-30;
    x2=maxx-60;
    y1=60;
    y2=70;
    y3=80;
    xaverage = (x1+x2)/2;

    line(x1,y1,x2,y1);
    line(x1,y2,x2,y2);

    line(x1,y1,x1,y2);
    line(x2,y1,x2,y2);
    line(xaverage,y1,xaverage,y2);

    line(x1,y2,xaverage,y3);
    line(x2,y2,xaverage,y3);
}

void trigon(int left,int top,int right,int bottom){
    int x1,x2,y1,y2,xaverage;
    x1 = left;
    x2 = right;
    y2 = top;
    y1 = bottom;
    xaverage = (x1+x2)/2;
    line(xaverage,y2,x1,y1);
    line(xaverage,y2,x2,y1);
    line(x1,y1,x2,y1);
}

void diktortgen(int left,int top,int right,int bottom){
    int x1,x2,y1,y2,xaverage;
    x1 = left;
    x2 = right;
    y1 = top;
    y2 = bottom;

    line(x1,y1,x2,y1);
    line(x1,y2,x2,y2);
    line(x1,y1,x1,y2);
    line(x2,y1,x2,y2);
}
int uzaklik2noktaarasi(int x1,int y1,int x2,int y2){
    return (int)sqrt(power(x2-x1,2) + power(y2-y1,2));
}

int power(int taban,int us){
    int sonuc = 1;
    for(int i=us;i>0;i--){
        sonuc *= taban;
    }
    return sonuc;
}
void alertBar(bool control){
    int maxx = getmaxx();
    int maxy = getmaxy();
    int color = BLACK;
    if(control)
        color = LIGHTRED;
    setfillstyle(SOLID_FILL,color);
    bar(maxx-12,5,maxx-2,15);
}

void RefreshWindow(){
    int maxx = getmaxx(),maxy = getmaxy();
    int SHIFT=0;
    setcolor(BLACK);
    settextstyle(6,0,2);
    outtextxy(maxx/2-60,5,"Gpix");
    //File Tools
    for (int i=0;i<4;i++){
        line_square(10+SHIFT,5,90+SHIFT,25,BLACK);
        SHIFT+=100;
    }
    settextstyle(0,0,1);
    setcolor(LIGHTBLUE);
    outtextxy(30,8,"OPEN");
    outtextxy(132,8,"SAVE");
    outtextxy(228,8,"CLEAR");
    outtextxy(315,8,"TERMINAL");
    //Tool Ustu Cizgi
    setfillstyle(1,LIGHTBLUE);
    bar(0,30,1000,40);
    //Renk Barlari
    SHIFT=0;
    for(int i=0;i<15;i+=2){
        setfillstyle(SOLID_FILL,i);
        bar(10+SHIFT,55,40+SHIFT,85);
        SHIFT+=50;
    }
    setfillstyle(8,BLACK);
    bar(10+SHIFT,55,40+SHIFT,85);
    SHIFT=0;
    //Toollar
    for(int i=0;i<5;i++){
        line_square(maxx-10+SHIFT,55,maxx-80+SHIFT,85,RED);
        SHIFT-=100;
    }
            //Tools Image
    {
        setcolor(BLACK);
        pen_image();
        circle(855,70,12);
        trigon(maxx-220,60,maxx-270,80);
        line_square(maxx-335,60,maxx-355,80,BLACK);
        SHIFT+=100;
        setfillstyle(1,BLACK);
        bar(maxx-10+SHIFT-10,69,maxx-80+SHIFT+10,71);
    }

    //Tool Alti Cizgi
    setfillstyle(1,LIGHTBLUE);
    bar(0,95,1000,105);
}
void Window(){
    int maxx = getmaxx(),maxy = getmaxy();
    int SHIFT=0;
    setbkcolor(WHITE);
    cleardevice();
    //Guncel Renkler
    GuncelRenkler(BLACK,WHITE);
    //Alert Bar
    alertBar(0);
    setcolor(BLACK);
    settextstyle(6,0,2);
    outtextxy(maxx/2-60,5,"Gpix");
    //File Tools
    for (int i=0;i<4;i++){
        line_square(10+SHIFT,5,90+SHIFT,25,BLACK);
        SHIFT+=100;
    }
    settextstyle(0,0,1);
    setcolor(LIGHTBLUE);
    outtextxy(30,8,"OPEN");
    outtextxy(132,8,"SAVE");
    outtextxy(228,8,"CLEAR");
    outtextxy(315,8,"TERMINAL");
    //Tool Ustu Cizgi
    setfillstyle(1,LIGHTBLUE);
    bar(0,30,1000,40);
    //Renk Barlari
    SHIFT=0;
    for(int i=0;i<15;i+=2){
        setfillstyle(SOLID_FILL,i);
        bar(10+SHIFT,55,40+SHIFT,85);
        SHIFT+=50;
    }
    setfillstyle(8,BLACK);
    bar(10+SHIFT,55,40+SHIFT,85);
    SHIFT=0;
    //Toollar
    for(int i=0;i<5;i++){
        line_square(maxx-10+SHIFT,55,maxx-80+SHIFT,85,RED);
        SHIFT-=100;
    }
            //Tools Image
    {
        setcolor(BLACK);
        pen_image();
        circle(855,70,12);
        trigon(maxx-220,60,maxx-270,80);
        line_square(maxx-335,60,maxx-355,80,BLACK);
        SHIFT+=100;
        setfillstyle(1,BLACK);
        bar(maxx-10+SHIFT-10,69,maxx-80+SHIFT+10,71);
    }

    //Tool Alti Cizgi
    setfillstyle(1,LIGHTBLUE);
    bar(0,95,1000,105);
}

void Mouse(){
    bool control = false;
    int maxx = getmaxx();
    int maxy = getmaxy();
    int shift = 0;
    int mX,mY,clr = BLACK,clrBackGround = WHITE;
    char cmd='p';

    while(true){
        clearmouseclick(WM_LBUTTONDOWN);
        clearmouseclick(WM_RBUTTONDOWN);
        alertBar(ismouseclick(WM_LBUTTONDOWN));
        delay(1);
        if(ismouseclick(WM_RBUTTONDOWN)){
            mX = mousex();
            mY = mousey();
            delay(1);
            if(mY >= 55 && mY <= 85){
                //Choosing Color :: Start.
                if(mX >= 10 && mX <= 40){
                    clrBackGround = 0;
                }
                else if(mX >=60 && mX <= 90){
                    clrBackGround = 2;

                }
                else if(mX >=110 && mX <= 140){
                    clrBackGround = 4;
                }
                else if(mX >=160 && mX <= 190){
                    clrBackGround = 6;
                }
                else if(mX >=210 && mX <= 240){
                    clrBackGround = 8;
                }
                else if(mX >=260 && mX <= 290){
                    clrBackGround = 10;
                }
                else if(mX >=310 && mX <= 340){
                    clrBackGround = 12;
                }
                else if(mX >=360 && mX <= 390){
                    clrBackGround = 14;
                }
                else if(mX >=410 && mX <= 440){
                    clrBackGround = WHITE;
                }
                GuncelRenkler(clr,clrBackGround);
            }
        }
        if(control = ismouseclick(WM_LBUTTONDOWN)){
            alertBar(control);

            mX = mousex();
            mY = mousey();
            clearmouseclick(WM_LBUTTONDOWN);

            if(mY >= 5 && mY <= 25){
                if(mX >= 10 && mX <= 90){
                    cmd = 'a'; //OPEN
                    DOS_Open();

                }
                else if(mX >= 110 && mX <= 190){
                    cmd = 'k';
                    DOS_Save();
                }

                else if(mX >= 210 && mX <= 290){
                    cmd = 't';
                    setfillstyle(SOLID_FILL,clrBackGround);
                    bar(1,105,maxx,maxy);
                }
                else if(mX >= 310 && mX <= 390){
                    cmd = 'T';
                    DOS();
                }

            }
            if(mY >= 55 && mY <= 85){
                //Choosing Color :: Start.
                if(mX >= 10 && mX <= 40){
                    clr = 0;
                }
                else if(mX >=60 && mX <= 90){
                    clr = 2;

                }
                else if(mX >=110 && mX <= 140){
                    clr = 4;
                }
                else if(mX >=160 && mX <= 190){
                    clr = 6;
                }
                else if(mX >=210 && mX <= 240){
                    clr = 8;
                }
                else if(mX >=260 && mX <= 290){
                    clr = 10;
                }
                else if(mX >=310 && mX <= 340){
                    clr = 12;
                }
                else if(mX >=360 && mX <= 390){
                    clr = 14;
                }
                else if(mX >=410 && mX <= 440){
                    clr = WHITE;
                }

                //Choosing Color :: End
                //Choosing Tools :: Start
                else if(mX >= maxx-80 && mX <= maxx-10){
                    cmd ='p';
                }
                else if(mX >= maxx-180 && mX  <= maxx-110){
                    cmd ='c';
                }

                else if(mX >= maxx-280 && mX  <= maxx-210){
                    cmd ='u';
                }

                else if(mX >= maxx-380 && mX  <= maxx-310){
                    cmd ='r';
                }


                else if(mX >= maxx-480 && mX  <= maxx-410){
                    cmd='l';
                }
                GuncelRenkler(clr,clrBackGround);
                //Choosing Tools : End
            }
        //printf("COLOR : %d ,BackColor : %d, COMMAND : %c \n",clr,clrBackGround,cmd);
        delay(10);
        tempFgColor = clr;
        tempBkColor = clrBackGround;
        Draw(mX,mY,cmd,clr,clrBackGround);
        }

    }

}


void Draw(int mX,int mY,char cmd,int clr,int clrBackGround){
    int maxx = getmaxx();
    int maxy = getmaxy();
    if(!(mY <= 105)){
        if(cmd == 'l'){
            int tempX = mX,tempY = mY;
            int static del_1X,del_1Y;
            int static del_2X,del_2Y;
            clearmouseclick(WM_LBUTTONDOWN);
            printf("Temp Coor : (%d,%d)\n",tempX,tempY);
            while(!ismouseclick(WM_LBUTTONDOWN)){
                int mX = mousex();
                int mY = mousey();
                delay(50);
                if(!(mY <= 105)){
                    setfillstyle(SOLID_FILL,clrBackGround);
                    setcolor(clrBackGround);
                    line(del_1X,del_1Y,del_2X,del_2Y);
                    setcolor(clr);
                    line(tempX,tempY,mX,mY);
                    del_1X = tempX; del_1Y = tempY;
                    del_2X = mX; del_2Y = mY;
                }
            }
            clearmouseclick(WM_LBUTTONDOWN);
            del_1X = maxx; del_1Y = maxy;
            del_2X = maxx; del_2Y = maxy;
        }
        if(cmd=='r'){
            int static del_1X,del_1Y;
            int static del_2X,del_2Y;
            int tempX = mX,tempY = mY;
            printf("Temp Coor: (%d,%d)\n",tempX,tempY);
            clearmouseclick(WM_LBUTTONDOWN);
            while(!ismouseclick(WM_LBUTTONDOWN)){
                int mX=mousex();
                int mY=mousey();
                delay(50);
                if(!(mY<105)){
                    setcolor(clrBackGround);
                    diktortgen(del_1X,del_1Y,del_2X,del_2Y);
                    setcolor(clr);
                    diktortgen(tempX,tempY,mX,mY);
                    del_1X = tempX; del_1Y = tempY;
                    del_2X = mX; del_2Y = mY;
                    }
            }
            del_1X = maxx; del_1Y = maxy;
            del_2X = maxx; del_2Y = maxy;
        }
        if(cmd=='u'){
            int static del_1X,del_1Y;
            int static del_2X,del_2Y;
            int tempX = mX,tempY = mY;
            printf("Temp Coor: (%d,%d)\n",tempX,tempY);
            clearmouseclick(WM_LBUTTONDOWN);
            while(!ismouseclick(WM_LBUTTONDOWN)){
                int mX=mousex();
                int mY=mousey();
                delay(50);
                if(!(mY <= 105)){
                    setcolor(clrBackGround);
                    trigon(del_1X,del_1Y,del_2X,del_2Y);
                    setcolor(clr);
                    trigon(tempX,tempY,mX,mY);
                    del_1X = tempX; del_1Y = tempY;
                    del_2X = mX; del_2Y = mY;
                }
            }
            clearmouseclick(WM_LBUTTONDOWN);
            del_1X = maxx; del_1Y = maxy;
            del_2X = maxx; del_2Y = maxy;
        }
        if(cmd=='c'){
            int static del_1X,del_1Y;
            int static del_2X,del_2Y;
            int r;
            int static rTemp;
            int tempX = mX,tempY = mY;
            printf("Temp Coor: (%d,%d)\n",tempX,tempY);
            clearmouseclick(WM_LBUTTONDOWN);
            while(!ismouseclick(WM_LBUTTONDOWN)){
                int mX=mousex();
                int mY=mousey();
                delay(50);
                r = uzaklik2noktaarasi(tempX,tempY,mX,mY);
                if(!(mY <= 105) && !(tempY - r <= 105)){
                    setcolor(clrBackGround);
                    circle(tempX,tempY,rTemp);
                    setcolor(clr);
                    circle(tempX,tempY,r);
                    del_1X = tempX; del_1Y = tempY;
                    del_2X = mX; del_2Y = mY;
                    rTemp = uzaklik2noktaarasi(del_1X,del_1Y,del_2X,del_2Y);
                    if(tempY - r < 105){
                        r=0; rTemp = 0;
                    }
                }
            }
            clearmouseclick(WM_LBUTTONDOWN);
            rTemp = 0;
            RefreshWindow();
        }
        if(cmd=='p'){
            while(!ismouseclick(WM_LBUTTONDOWN)){
                delay(1);
                setfillstyle(SOLID_FILL,clr);
                if(mY > 106)
                bar(mX-3,mY-3,mX+3,mY+3);
                mX = mousex();
                mY = mousey();
            }
        clearmouseclick(WM_LBUTTONDOWN);
        }
    }
}

void fixPath(char *path){
    char * newPath = (char*)malloc((strlen(path)-2)*sizeof(char));
    int i,k=0;
    for(i=3;i<strlen(path);i++)
        newPath[k++] = path [i];
    newPath[k] = '\0';
    strcpy(path,newPath);
    free(newPath);
}
void textColor(char * text,int color){
    HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
    WORD wOldColorAttrs;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    /******************************************
    * First save the current color information
    *******************************************/
    GetConsoleScreenBufferInfo(h, &csbiInfo);
    wOldColorAttrs = csbiInfo.wAttributes;
    /**************************************
    * Set the new color information
    **************************************/
    SetConsoleTextAttribute ( h, color | FOREGROUND_INTENSITY );
    printf("%s",text);
    /**************************************
    * Restore the original colors
    ***************************************/
    SetConsoleTextAttribute ( h, wOldColorAttrs);
}
void infoForFileCommand(){
    textColor("\n\t\t\t\t\t\t\t\t\n",120);
    textColor(" \n",120);
    textColor(" ",120);    textColor("  SHOW   ",14);  printf(" :\t"); textColor("Bulunulan Konumun Dosyalarini Goruntuler\n",13);
    textColor(" ",120);    textColor("  SELECT ",14);  printf(" :\t"); textColor("Konum Degistirir\n",13);
    textColor(" ",120);    textColor("  TREE   ",14);  printf(" :\t"); textColor("Bulunulan Konumun Dosya Agacini Gosterir\n",13);
    textColor(" ",120);    textColor("  DESKTOP",14);  printf(" :\t"); textColor("Masaustune Git\n",13);
    textColor(" ",120);    textColor("  EXIT   ",14);  printf(" :\t"); textColor("Dosyalama Islemini Kapat | Komuttan Cik\n",13);
    textColor(" ",120);    textColor("  RESET  ",14);  printf(" :\t"); textColor("C:\\\n",13);

    textColor(" ",120);    textColor("\n\t\t\t\t\t\t\t\t\n",120);
    textColor(" \n",120);
    textColor(" ",120);    textColor("  OPEN   ",3);  printf(" :\t"); textColor("Bulunulan Konumdaki Dosyayi Ac\n",8);
    textColor(" ",120);    textColor("  SAVE   ",3);  printf(" :\t"); textColor("Bulunulan Konuma Dosyayi Kaydet\n",8);
    textColor(" \n",120);
    textColor("\t\t\t\t\t\t\t\t\n\n",120);
}

void DOS(){
    int shift = 137;
    int maxx = getmaxx();
    int maxy = getmaxy();
    char command[10] = "";
    char path[100] = "cd C:\\Users\\";
    char pathTemp[100] = "";
    char * userName = (char *)malloc(30*sizeof(char));
    userName = getenv("username");
    strcat(path,userName);
    strcat(path,"\\");
    infoForFileCommand();
    while(1){
        textColor("   Komut : ",2);
        scanf("%s",command);
        if(strcmp(strlwr(command),"exit")==0){
            break;
        }
        else if(strcmp(strlwr(command),"show")==0){
        printDir :
            strcpy(pathTemp,path);
            strcat(pathTemp," & dir");
            system(pathTemp);
        }
        else if(strcmp(strlwr(command),"select")==0){
            char * nameOfDir = (char *)malloc(50*sizeof(char));
            textColor("\n   Klasor Adi : ",6);
            scanf("%s",nameOfDir);
            if(strcmp(strlwr(nameOfDir),"exit")==0) continue;
            strcat(path,nameOfDir);
            strcat(path,"\\");
            free(nameOfDir);
            goto printDir;
            printf("\n");
        }
        else if(strcmp(strlwr(command),"tree")==0){
            strcpy(pathTemp,path);
            strcat(pathTemp," & tree");
            system(pathTemp);
        }
        else if(strcmp(strlwr(command),"reset")==0){
            strcpy(path,"cd C:\\");
        }
        else if(strcmp(strlwr(command),"desktop")==0){
            printf("\n");
            strcpy(pathTemp,"cd C:\\Users\\");
            strcat(pathTemp,userName);
            strcat(pathTemp,"\\Desktop & dir /D");
            system(pathTemp);
            strcpy(path,"cd C:\\Users\\");
            strcat(path,userName);
            strcat(path,"\\Desktop\\");
        }
        else if(strcmp(strlwr(command),"open")==0){
            char * NameOfOpenFile = (char*)malloc(30*sizeof(char));
            strcpy(pathTemp,path);
            strcat(pathTemp," & DIR /D | FIND \".gpix\""); /*.Gpix*/
            system("CLS");
            system(pathTemp);
            textColor("Acilacak Dosyanin Adi(Buyuk\\Kucuk Duyarli) : ",4);
            scanf("%s",NameOfOpenFile);
            strcat(NameOfOpenFile,".gpix"); /*.Gpix*/
            printf("Dosya Adi :\t%s\n",NameOfOpenFile);
            strcat(path,NameOfOpenFile);
            free(NameOfOpenFile);
            fixPath(path);
            printf("Dosya Konumu :\t%s\n",path);
            FILE * dosya = fopen(path,"r");
            if(dosya == NULL) {
                textColor("Dosya Acilamadi!",LIGHTGREEN);
                textColor(" -> *Kullanici Adinizi Yanlis Yazmis Olabilirsiniz",YELLOW);
            }
            int ** tempColor = (int **) malloc(maxy * sizeof(int));
            if(tempColor == NULL);
            for(int i=0;i<maxy-105;i++){
                tempColor[i] = (int *)malloc(maxx * sizeof(int));
                if(tempColor[i]==NULL) printf("Yer Ayrilamadi");
            }
            for(int i=0;i<=maxy;i++){
                for(int j=0;j<maxx;j++){
                    fscanf(dosya,"%d",&tempColor[i][j]);
                }
            }
            textColor("Gecici Okuma Tamamlandi !\n",GREEN);
            delay(1000);
            int m=0;
            bool control = false;
            system("CLS");
            textColor("Ekrana Basiliyor : ",GREEN);
            for(int i=105;i<maxy;i++){
                for(int j=0;j<maxx;j++){
                    if(control = ismouseclick(WM_RBUTTONDOWN)){
                        control = true;
                        break;
                    }
                    putpixel(j,i,tempColor[m][j]);
                }
                if(control) {control = false; break;}
                    m++;
                    if(i%49==0){
                    textColor("# ",RED);
                    setfillstyle(SOLID_FILL,LIGHTGREEN);
                    bar(maxx-150,5,maxx-(shift),15);
                    shift -= 13;
                    line_square(maxx-150,5,maxx-20,15,LIGHTGRAY);
                }
            }
            delay(200);
            setfillstyle(SOLID_FILL,WHITE);
            bar(maxx-150,5,maxx-19,16);
            textColor("\nEkrana Bastirildi!\n",GREEN);
            /*Dosya Okuma Fonk*/
            break;
        }
        else if(strcmp(strlwr(command),"save")==0){
            char fileName[50];
            FILE * dosya;
            fixPath(path);
            printf("First Path :%s",path);
            //strcat(path,"\\");
            textColor("LUTFEN BOSLUK ve TURKCE karakterler kullanmayiniz !\n\n",GREEN);
            textColor("Dosya Adi : ",RED);
            scanf("%s",fileName);
            strcat(path,fileName);
            strcat(path,".gpix");
            printf("Kaydedilecek Konum : %s",path);
            /*Dosya Yazdirma Fonk*/
            dosya = fopen(path,"w");
            if(dosya == NULL) printf("\nKaydedilemedi!");
            else
                printf("\nKaydedildi!");
            for(int i=105;i<maxy;i++){
                for(int j=0;j<maxx;j++){
                    fprintf(dosya,"%d ",getpixel(j,i));
                }
                fprintf(dosya,"\n");
            }
            break;
        }
    }
    textColor("\n\t\tDosya Islemlerinden Cikilmistir !\n",4);
}
void DOS_Open(){
    int maxx = getmaxx();
    int maxy = getmaxy();
    int shift = 137;
    char * path = (char*)malloc(100*sizeof(char));
    char * pathTemp = (char*)malloc(150*sizeof(char));
    char * userName = (char*)malloc(20*sizeof(char));
    char * NameOfOpenFile = (char*)malloc(30*sizeof(char));
    char * konum = (char*)malloc(20*sizeof(char));
    DOS_KonumSec(konum,LIGHTRED);
    userName = getenv("USERNAME");
    strcpy(path,"cd C:\\Users\\");
    strcat(path,userName);
    strcat(path,konum);
    strcpy(pathTemp,path);
/*.Gpix*/   strcat(pathTemp," & DIR /D | FIND \".gpix\"");
    system("CLS");
    system(pathTemp);
    textColor("Acilacak Dosyanin Adi(Buyuk\\Kucuk Duyarli) : ",4);
    scanf("%s",NameOfOpenFile);
/*.Gpix*/    strcat(NameOfOpenFile,".gpix");
    printf("Dosya Adi :\t%s\n",NameOfOpenFile);
    strcat(path,NameOfOpenFile);
    free(NameOfOpenFile);
    fixPath(path);
    printf("Dosya Konumu :\t%s\n",path);
    FILE * dosya = fopen(path,"r");
    if(dosya == NULL) {
        textColor("Dosya Acilamadi!",LIGHTGREEN);
        textColor(" -> *Kullanici Adinizi Yanlis Yazmis Olabilirsiniz",YELLOW);
    }
    int ** tempColor = (int **) malloc(maxy * sizeof(int));
    if(tempColor == NULL);
        for(int i=0;i<maxy-105;i++){
            tempColor[i] = (int *)malloc(maxx * sizeof(int));
            if(tempColor[i]==NULL) printf("Yer Ayrilamadi");
        }
    for(int i=0;i<=maxy;i++){
        for(int j=0;j<maxx;j++){
            fscanf(dosya,"%d",&tempColor[i][j]);
        }
    }
    setfillstyle(SOLID_FILL,WHITE);
    bar(1,105,maxx,maxy);
    textColor("Gecici Okuma Tamamlandi !\n",GREEN);
    delay(1000);
    system("CLS");
    cleardevice();
    RefreshWindow();
    GuncelRenkler(tempFgColor,tempBkColor);
    int m=0;
    bool control = false;
    textColor("Ekrana Basiliyor : ",GREEN);
    for(int i=105;i<maxy;i++){
        for(int j=0;j<maxx;j++){
            if(control = ismouseclick(WM_RBUTTONDOWN)){
                control = true;
                break;
            }
        putpixel(j,i,tempColor[m][j]);
        }
        if(control) {control = false; break;}
        m++;
        if(i%49==0){
            textColor("# ",RED);
            setfillstyle(SOLID_FILL,LIGHTGREEN);
            bar(maxx-150,5,maxx-(shift),15);
            shift -= 13;
            line_square(maxx-150,5,maxx-20,15,LIGHTGRAY);
        }
    }
    delay(200);
    setfillstyle(SOLID_FILL,WHITE);
    bar(maxx-150,5,maxx-19,16);
    textColor("\nEkrana Bastirildi!\n",GREEN);
    fclose(dosya);
    free(path);
    free(pathTemp);
    free(userName);
    free(NameOfOpenFile);
}
void DOS_Save(){
    char * konum = (char*)malloc(20*sizeof(char));
    DOS_KonumSec(konum,GREEN);
    printf("Secilen Konum : %s",konum);
    int maxx = getmaxx();
    int maxy = getmaxy();
	FILE * dosya;
	char fileName[50];
	char * path = (char*)malloc(50*sizeof(char));
	char * userName = (char*)malloc(20*sizeof(char));
	userName = getenv("USERNAME");
	strcpy(path,"C:\\Users\\");
	strcat(path,userName);
	strcat(path,konum);
	textColor("LUTFEN BOSLUK ve TURKCE karakterler kullanmayiniz !\n\n",GREEN);
	textColor("Dosya Adi : ",RED);
	scanf("%s",fileName);
	strcat(path,fileName);
	strcat(path,".gpix");
	/*Dosya Yazdirma Fonk*/
	dosya = fopen(path,"w");
	if(dosya == NULL) printf("\nKaydedilemedi!");
	else printf("\nKaydedildi!");
	for(int i=105;i<maxy;i++){
		for(int j=0;j<maxx;j++){
			fprintf(dosya,"%d ",getpixel(j,i));
        }
	fprintf(dosya,"\n");
	}
    setcolor(LIGHTGRAY);
    settextstyle(9,0,2);
    outtextxy(850,575,"Kaydedildi!");
    delay(500);
    setfillstyle(SOLID_FILL,WHITE);
    cleardevice();
    RefreshWindow();
    //Guncel Renkler
    GuncelRenkler(tempFgColor,tempBkColor);
	fclose(dosya);
	free(path);
	free(userName);
	free(konum);
}
void GuncelRenkler(int clr,int clrBackGround){
    setfillstyle(SOLID_FILL,clrBackGround);
    int x = 470;
    int y = 60;
    int range = 20;
    line_square(x,y,x+range,y+range,LIGHTGRAY);
    bar(x,y,x+range,y+range);
    setfillstyle(SOLID_FILL,clr);
    line_square(x-5,y-5,x-5+range,y-5+range,LIGHTGRAY);
    bar(x-5,y-5,x-5+range,y-5+range);
}
void DOS_KonumSec(char* konum,int clr){
    int x = 140;
    int y = 0;
    int width = 615;
    int hight = 105;
    int mX,mY;
    int maxx = getmaxx();
    int maxy = getmaxy();
    char * imPath = (char*)malloc(200*sizeof(char));
    char * userNAME = (char*)malloc(50*sizeof(char));
    userNAME = getenv("USERNAME");
    strcpy(imPath,"C:\\users\\");
    strcat(imPath,userNAME);

    strcat(imPath,"\\Desktop\\Gpix\\imFile\\01.jpg");
    setfillstyle(SOLID_FILL,WHITE);
    bar(1,0,maxx,105);
    readimagefile(imPath,x,y,x+width,y+hight);
    clearmouseclick(WM_LBUTTONDOWN);
    while(true){
        delay(5);
        mX = mousex();
        mY = mousey();
        if(ismouseclick(WM_MOUSEMOVE)){
            RefreshPanel();
        }
        if(mY>= 1 && mY <=51){
            if(mX>=130  && mX<= 385){
                line_square(130,1,385,51,clr);
            }
            else if(mX>=130+1*255 && mX<= 385+1*255){
                line_square(130+1*255,1,385+1*255,51,clr);
            }
            else if(mX>=130+2*255  && mX<= 385+2*255){
                line_square(130+2*255,1,385+2*255,51,clr);
            }

        }
        if(mY>= 51 && mY <=101){
            if(mX>=130  && mX<= 385){
                line_square(130,51,385,101,clr);
            }
            else if(mX>=130+1*255 && mX<= 385+1*255){
                line_square(130+1*255,51,385+1*255,101,clr);
            }
            else if(mX>=130+2*255  && mX<= 385+2*255){
                line_square(130+2*255,51,385+2*255,101,clr);
            }
        }

        if(ismouseclick(WM_LBUTTONDOWN)){
            mX = mousex();
            mY = mousey();

            if(mY>= 1 && mY <=51){
                if(mX>=130  && mX<= 385){
                    strcpy(konum,"\\Documents\\"); //Belgeler
                }
                else if(mX>=130+1*255 && mX<= 385+1*255){
                    strcpy(konum,"\\Downloads\\"); //Indirilenler
                }
                else if(mX>=130+2*255  && mX<= 385+2*255){
                    strcpy(konum,"\\Desktop\\"); //Masaustu
                }
            }
            if(mY>= 51 && mY <=101){
                if(mX>=130  && mX<= 385){
                    strcpy(konum,"\\Music\\"); //Muzikler
                }
                else if(mX>=130+1*255 && mX<= 385+1*255){
                    strcpy(konum,"\\Pictures\\"); //Resimler
                }
                else if(mX>=130+2*255  && mX<= 385+2*255){
                    strcpy(konum,"\\Videos\\"); //Videolar
                }
            }
            //printf("Secim : %s\n",konum);
            clearmouseclick(WM_LBUTTONDOWN);
            free(imPath);
            free(userNAME);
            break;
        }
    }
}

void RefreshPanel(){
    int shift = 0;
    for(int i=0;i<3;i++){
    line_square(130+shift,1,385+shift,51,LIGHTGRAY);
    line_square(130+shift,51,385+shift,101,LIGHTGRAY);
    shift+=255;
    }
}
