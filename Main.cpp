#include<iostream>
#include<string.h>
#include<graphics.h>
#include<conio.h>
#include<fstream>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include "object.h"
#include "pacman.h"
#include "monster.h"
#include "player.h"

using namespace std;

const int maxNoPlayers = 70;
const int noLevels = 5;

int key,score=0,level=1;
void *background=0;

//LEVELS
int maxScorePerLevel=0;

void SetMaxScorePerLevel(){
    if (level==1){
        maxScorePerLevel=180;
    }else if (level==2){
        maxScorePerLevel=180;
    }else if (level==3){
        maxScorePerLevel=180;
    }else if (level==4){
        maxScorePerLevel=270;
    }else if (level==5){
        maxScorePerLevel=270;
    }
}
char* LevelName(){
    if (level==1){
        return "level1.bmp";
    }else if (level==2){
        return "level2.bmp";
    }else if (level==3){
        return "level3.bmp";
    }else if (level==4){
        return "level4.bmp";
    }else if (level==5){
        return "level5.bmp";
    }
}
//



//MONSTER design for levels
void MonsterDesign(){
    if (level==1){
        UpdateQueue();

        static MONSTER M1(300,120),M2(1200,120),M3(1200,500),M4(200,580),M5(640,270),M6(900,650);
        //MAking a Queue of Monsters
        addToQueue(M1);
        addToQueue(M2);
        addToQueue(M3);
        addToQueue(M4);
        addToQueue(M5);
        addToQueue(M6);
        
    }else if (level==2){
        UpdateQueue();

        static MONSTER M1(300,120),M2(1050,140),M3(750,600),M4(200,580),M5(600,600), M6(600,100);
        //MAking a Queue of Monsters
        addToQueue(M1);
        addToQueue(M2);
        addToQueue(M3);
        addToQueue(M4);
        addToQueue(M5);
        addToQueue(M6);
        
    }else if (level==3){
        UpdateQueue();

        static MONSTER M1(300,600),M2(450,150),M3(1000,600), M4(1000,100),M5(460,450);
        //MAking a Queue of Monsters
        addToQueue(M1);
        addToQueue(M2);
        addToQueue(M3);
        addToQueue(M4);
        addToQueue(M5);
        //
    }else if (level==4){
        UpdateQueue();

        static MONSTER M1(300,120),M2(1200,120),M3(1000,500),M4(200,600),M5(650,300);
        //MAking a Queue of Monsters
        addToQueue(M1);
        addToQueue(M2);
        addToQueue(M3);
        addToQueue(M4);
        addToQueue(M5);
        
    }else if (level==5){
        UpdateQueue();

        static MONSTER M1(200,160),M2(330,400),M3(700,500),M4(1000,280),M5(1200,500),M6(400,630);
       //MAking a Queue of Monsters
        addToQueue(M1);
        addToQueue(M2);
        addToQueue(M3);
        addToQueue(M4);
        addToQueue(M5);
        addToQueue(M6);
        //
    }
}
//


PLAYER Player1;


int distance(int x1, int y1, int x2, int y2){
    return int(sqrtl(((x1-x2)*(x1-x2))+(y1-y2)*(y1-y2)));
}


void Update(PACMAN &P){

    P.stepType1();

    MONSTER *M=Front;
    while(M!=0){
        //checking whether distance between pacman and monster is less than 600
        if(distance(P.getCOX(),P.getCOY(),M->getCOX(),M->getCOY())<600){    
            M->Step();
            if(M->obstacleUp()==YELLOW||M->obstacleDown()==YELLOW||M->obstacleLeft()==YELLOW||M->obstacleRight()==YELLOW){  //PACMAN touching monster
                key=27;
                return;
            }
        }

        M=M->NEXT;
    }
    char pts[30];
    sprintf (pts, "Score: %d", score);
    outtextxy(30,700,pts);

}



void Background(){

    int area=0;

    // loading required level on screen
    readimagefile(LevelName(),0,0,getmaxx(),getmaxy());  
    area = imagesize(0, 0, getmaxx() , getmaxy());
    background = malloc(area);
    getimage(0 , 0 , getmaxx() , getmaxy(), background);

}

void gotoxy( int column, int line )
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(
        GetStdHandle( STD_OUTPUT_HANDLE ),
        coord
    );
}

int main()
{

    gotoxy(30,10);
    cout<<"PACMAN !!";
    gotoxy(28,14);
    cout<<"LOADING...)";
    delay(3000);
    system("cls");


    char choice;
    int chk = 0,window;
    fstream f;
    cout<<"Let's play but First Create Account or login:"<<endl;
    cout<<"1 : Create Account "<<endl;
    cout<<"2 : Login"<<endl;
    cout<<"3 : Delete Account"<<endl;
    cout<<"4 : View Account Details"<<endl;
    cout<<"5 : Scores"<<endl;
    cout<<"6 : Instructions for playing"<<endl;
    cout<<"7 : Exit"<<endl<<endl;

    cout<<"Enter your choice: ";
    cin>>choice;
    // for account creation
    if(choice=='1')                       
    {
        f.open("Accounts.dat" , ios::out|ios::binary|ios::app);
        system("cls");
        Player1.createAccount();
        f.write((char*)&Player1 , sizeof(Player1));
        f.close();
        cout<<"Account Created Successfully!!"<<endl<<endl<<"Loading Game ....";
        delay(2000);
        goto Z;
    }

    // Logging in user info
    if(choice=='2')                         
    {
        int chk = 0,i=0,j=0,N=0,x=12,y=0;
        char ch,name[50]={0},passcode[50]={0},k;
        PLAYER temp, List[maxNoPlayers];
        f.open("Accounts.dat" , ios::in|ios::binary);


        //List of suggestion
        i=0;
        while(f.read((char*)&List[i] , sizeof(List[i])))
        {
            i++;
            N++;
        }

        i=0;
A:      system("cls");
        cout<<"Enter Name: "<<name;
        gotoxy(50,0);
        cout<<"Suggestions:";
        while(true){
            gotoxy(x,0);
            k=getche();
            if(k=='\r')
                break;
            else if(k=='\b'){
                if(i!=0){
                    i--;
                    x--;
                }
                name[i]=0;
                goto A;
            }
            name[i++]=k;
            x++;
            name[i]=0;

           //clearing the previous suggestions
            j=0;
            y=0;
            while(j!=N){
                y+=2;
                gotoxy(50,y);
                cout<<"                             ";
                j++;
            }
            
            // displaying suggestions
            j=0;
            y=0;
            while(j!=N){                               
                if(strstr(List[j].name , name)!=0){
                    y+=2;
                    gotoxy(50,y);
                    cout<<List[j].name;
                }
                j++;
            }
        }

        i=0;
L:      gotoxy(0,2);
        cout<<"Enter Passcode: "<<passcode;
        while(true){
            k=getche();
            if(k=='\r')
                break;
            else if(k=='\b'){
                if(i!=0)
                    i--;
                passcode[i]=0;
                gotoxy(0,2);
                cout<<"Enter Passcode:                            ";
                goto L;
            }
            passcode[i++]=k;
            passcode[i]=0;
        }

        // matching data for login

        j=0;
        while(j!=N)                     
        {
           if(strcmp(passcode,List[j].passcode)==0 && strcmp(name,List[j].name)==0)
            {
                Player1 = List[j];
                level=Player1.level;
                chk++;
                break;
            }
            j++;
        }

        f.close();

        if(chk==0)
        {
            i=name[0]=passcode[0]=0;
            x=12;
            cout<<endl<<endl<<"Login Failed!!"<<endl;
            cout<<"Do You want to RETRY? (Y/N)"<<endl;
            cin>>ch;
            if(ch=='y'||ch=='Y')
            {
                goto A;
            }
            if(ch=='n' ||'N')
            {
                exit(0);
            }
        }
        if(chk!=0)
        {
            //  if all levels played 
            if(Player1.level>noLevels){   
                cout<<endl<<endl<<"Login Successful!!";
                cout<<endl<<"You have succesfully completed all levels.";
                cout<<endl<<"If you continue, you will be loaded to LEVEL 1.";
                cout<<endl<<"Your scores will be Reset.";
                cout<<endl<<"CONTINUE? (Y/N): ";
                cin>>ch;
                if(ch=='y'||ch=='Y')
                {
                    level=Player1.level=1;
                    for(int k=0;k<noLevels;k++){
                        Player1.score[k]=0;
                    }
                    cout<<endl<<endl<<"Loading Game....";
                    delay(2000);
                    goto Z;
                }
                if(ch=='n' ||'N')
                {
                    exit(0);
                }
            }else{
                cout<<endl<<endl<<"Login Successful!!"<<endl<<endl<<"Loading Game....";
                delay(2000);
                goto Z;
            }
        }

    }

     //to delete account
    if(choice=='3')            
    {
        int chk = 0,i=0,j=0,N=0,x=12,y=0,pos=-1;
        char ch,name[50]={0},passcode[50]={0},k;
        PLAYER temp, List[maxNoPlayers];
        f.open("Accounts.dat" , ios::in|ios::binary);

        // list of suggestions
        i=0;
        while(f.read((char*)&List[i] , sizeof(List[i])))
        {
            i++;
            N++;
        }

        i=0;
A2:     system("cls");
        cout<<"Enter Name: "<<name;
        gotoxy(50,0);
        cout<<"Suggestions:";
        while(true){
            gotoxy(x,0);
            k=getche();
            if(k=='\r')
                break;
            else if(k=='\b'){
                if(i!=0){
                    i--;
                    x--;
                }
                name[i]=0;
                goto A2;
            }
            name[i++]=k;
            x++;
            name[i]=0;

            // removing previous suggestions
            j=0;
            y=0;
            while(j!=N){
                y+=2;
                gotoxy(50,y);
                cout<<"                             ";
                j++;
            }
            
            // displaying suggestions
            j=0;
            y=0;
            while(j!=N){                               
                if(strstr(List[j].name , name)!=0){
                    y+=2;
                    gotoxy(50,y);
                    cout<<List[j].name;
                }
                j++;
            }
        }

        i=0;
L2:      gotoxy(0,2);
        cout<<"Enter Password: "<<passcode;
        while(true){
            k=getche();
            if(k=='\r')
                break;
            else if(k=='\b'){
                if(i!=0)
                    i--;
                passcode[i]=0;
                gotoxy(0,2);
                cout<<"Enter Password:                            ";
                goto L2;
            }
            passcode[i++]=k;
            passcode[i]=0;
        }

        // data matching for login info

        j=0;
        while(j!=N)                    
        {
           if(strcmp(passcode,List[j].passcode)==0 && strcmp(name,List[j].name)==0)
            {
                Player1 = List[j];
                pos=j;
                chk++;
                break;
            }
            j++;
        }

        f.close();

        if(chk==0)
        {
            i=name[0]=passcode[0]=0;
            x=12;
            cout<<endl<<endl<<"Login Failed!!"<<endl;
            cout<<"Do You want to RETRY? (Y/N)"<<endl;
            cin>>ch;
            if(ch=='y'||ch=='Y')
            {
                goto A2;
            }
            if(ch=='n' ||'N')
            {
                exit(0);
            }
        }
        if(chk!=0)
        {
            cout<<endl<<endl<<"Logged In!!"<<endl<<endl<<"DELETE? (Y/N) :";
            cin>>ch;
            if(ch=='y'||ch=='Y')
            {
                f.close();
                f.open("Accounts.dat",ios::in|ios::binary);
                fstream tempFile ("temp.dat" , ios::out|ios::binary);

                while(f.read((char*)&temp , sizeof(temp)))
                {
                    if(strcmp(Player1.name, temp.name)==0 && strcmp(Player1.passcode, temp.passcode)==0){
                    }else{
                        tempFile.write((char*)&temp , sizeof(temp));
                    }
                }

                f.close();
                tempFile.close();

                remove("Accounts.dat");
                rename("temp.dat","Accounts.dat");
            }
            if(ch=='n' ||'N')
            {
                exit(0);
            }

            cout<<"Account Removed..";
            delay(2000);
            exit(0);
        }
    }
    // details of account

    if(choice=='4')             
    {
        int chk = 0,i=0,j=0,N=0,x=12,y=0,pos=-1;
        char ch,name[50]={0},passcode[50]={0},k;
        PLAYER temp, List[maxNoPlayers];
        f.open("Accounts.dat" , ios::in|ios::binary);

        // list of suggestions
        i=0;
        while(f.read((char*)&List[i] , sizeof(List[i])))
        {
            i++;
            N++;
        }

        i=0;
A3:     system("cls");
        cout<<"Enter Name: "<<name;
        gotoxy(50,0);
        cout<<"Suggestions:";
        while(true){
            gotoxy(x,0);
            k=getche();
            if(k=='\r')
                break;
            else if(k=='\b'){
                if(i!=0){
                    i--;
                    x--;
                }
                name[i]=0;

                goto A3;
            }
            name[i++]=k;
            x++;
            name[i]=0;

            // removing previous suggestionsS
            j=0;
            y=0;
            while(j!=N){
                y+=2;
                gotoxy(50,y);
                cout<<"                             ";
                j++;
            }
            
            // displaying suggestions
            j=0;
            y=0;
            while(j!=N){                              
                if(strstr(List[j].name , name)!=0){
                    y+=2;
                    gotoxy(50,y);
                    cout<<List[j].name;
                }
                j++;
            }
        }

        i=0;
L3:     gotoxy(0,2);
        cout<<"Enter Password: "<<passcode;
        while(true){
            k=getche();
            if(k=='\r')
                break;
            else if(k=='\b'){
                if(i!=0)
                    i--;
                passcode[i]=0;
                gotoxy(0,2);
                cout<<"Enter Password:                            ";
                goto L3;
            }
            passcode[i++]=k;
            passcode[i]=0;
        }

        // data matching for login info

        j=0;
        while(j!=N)                     
        {
           if(strcmp(passcode,List[j].passcode)==0 && strcmp(name,List[j].name)==0)
            {
                Player1 = List[j];
                pos=j;
                chk++;
                break;
            }
            j++;
        }

        f.close();

        if(chk==0)
        {
            i=name[0]=passcode[0]=0;
            x=12;
            cout<<endl<<endl<<"Login Failed!!"<<endl;
            cout<<"Do You want to RETRY? (Y/N)"<<endl;
            cin>>ch;
            if(ch=='y'||ch=='Y')
            {
                system("cls");
                goto A3;
            }
            if(ch=='n' ||'N')
            {
                exit(0);
            }
        }
        if(chk!=0)
        {
            cout<<endl<<endl<<"Logged In!!"<<endl<<endl<<"Displaying...";

            delay(1500);
            system("cls");

            Player1.display();

            getche();
            exit(0);
        }
    }

    // Displaying scores
    if(choice=='5')         
    {
        f.close();
        f.open("Accounts.dat" , ios::in|ios::binary);
        int i=0,j=0,N=0;
        PLAYER temp, List[maxNoPlayers];

        i=0;
        while(f.read((char*)&List[i] , sizeof(List[i])))
        {
            i++;
            N++;
        }
        f.close();

        // sorting in descending
        for(i=0;i<N;i++){                           
            for(j=i;j<N;j++){
                if(List[i].TotalScore() < List[j].TotalScore()){
                    temp = List[i];
                    List[i]=List[j];
                    List[j]=temp;
                }
            }
        }

        system("cls");
        gotoxy(0,1);
        cout<<"|     Name";
        gotoxy(20,1);
        cout<<"|  Score";
        gotoxy(30,1);
        cout<<"|  Level   |";
        gotoxy(0,2);
        cout<<"__________________________________________";
        gotoxy(0,0);
        cout<<"|";
        gotoxy(20,0);
        cout<<"|";
        gotoxy(30,0);
        cout<<"|";
        gotoxy(41,0);
        cout<<"|";
        gotoxy(0,2);
        cout<<"|";
        gotoxy(20,2);
        cout<<"|";
        gotoxy(30,2);
        cout<<"|";
        gotoxy(41,2);
        cout<<"|";
        gotoxy(0,3);
        cout<<"|";
        gotoxy(20,3);
        cout<<"|";
        gotoxy(30,3);
        cout<<"|";
        gotoxy(41,3);
        cout<<"|";


        for(i=0;i<N;i++){
            gotoxy(0,i+4);
            cout<<"|  "<<List[i].name;
            gotoxy(20,i+4);
            cout<<"|    "<<List[i].TotalScore();
            gotoxy(30,i+4);
            if(List[i].level<=noLevels)
                cout<<"|    "<<List[i].level<<"     |";
            else
                cout<<"| "<<"FINISHED"<<" |";
        }

        gotoxy(0,i+4);
        cout<<"__________________________________________";
        gotoxy(0,i+4);
        cout<<"|";
        gotoxy(20,i+4);
        cout<<"|";
        gotoxy(30,i+4);
        cout<<"|";
        gotoxy(41,i+4);
        cout<<"|";

        cout<<endl<<endl;

        getche();
        exit(0);
    }

    if(choice=='6')             //instructions
    {
        system("cls");

        fstream t("instructions.txt", ios::in);
        char s[100];

        while(t.getline(s,100,'\n')){
            cout<<s<<endl;
        }

        t.close();

        getche();
        exit(0);
    }

    if(choice!='1' && choice!='2' && choice!='3' && choice!='4' && choice!='5' && choice!='6' && choice!='D')
        choice='7';

    if(choice=='7')
    {
        exit(0);
    }

    if(choice=='D')             //developer test
    {
        cout<<endl<<".CHEATER.CHEATER.CHEATER.CHEATER.CHEATER.CHEATER."<<endl;
        window=initwindow(getmaxwidth() , getmaxheight() , "Game: PACMAN");

Lable:  cleardevice();

        Background();   //initialize stuff for the background

        cleardevice();

        PACMAN P(699,48);        //97,48
        MonsterDesign();

        srand(time(NULL));

        //Displaying Background
        putimage(0,0,background, 2);

        SetMaxScorePerLevel();
        // Score keeps updating till escape key is pressed

        while(key!=27){        
            // if '3' is pressed
            if(key ==51){           
                score=maxScorePerLevel;
                key=0;
            }

            Update(P);

            // Update to next state level if enough score reaches
            if(score>=maxScorePerLevel){           
                Player1.SetScore(level);
                // Incrementing levels upto maximum
                if(level<noLevels){         
                    level++;
                    SetMaxScorePerLevel();
                    score=0;
                    Player1.SetLevel();
                    //closegraph();
                    cleardevice();
                    outtextxy(400,300,"CONGRATULATIONS!! YOU HAVE CLEARED THIS LEVEL. LOADING NEXT LEVEL...");
                    cout<<"CONGRATULATIONS!! YOU HAVE CLEARED THIS LEVEL."<<endl<<"LOADING NEXT LEVEL...";
                    delay(2000);
                    goto Lable;
                }else{
                    //closegraph();
                    system("cls");
                    cleardevice();
                    outtextxy(450,300,"CONGRATULATIONS!! YOU HAVE FINISHED THE GAME. THANK YOU...");
                    delay(3000);
                    key=27;
                }
            }
        }
    }


    exit(0);



Z:  window=initwindow(getmaxwidth() , getmaxheight() , "Game: PACMAN");

N:  cleardevice();

    Background();   //initialize stuff for the background

    cleardevice();

    PACMAN P(699,48);        //97,48
    MonsterDesign();

    srand(time(NULL));

    //Displaying Background
    putimage(0,0,background, 2);

    SetMaxScorePerLevel();

    // if 3 is pressed
    while(key!=27){         
        Update(P);
        // checking for the required score in order to proceed the next level
        if(score>=maxScorePerLevel){           
            Player1.SetScore(level);
            // next level
            if(level<noLevels){         
                level++;
                SetMaxScorePerLevel();
                score=0;
                Player1.SetLevel();
                //closegraph();
                cleardevice();
                outtextxy(400,300,"CONGRATULATIONS!! YOU HAVE CLEARED THIS LEVEL. LOADING NEXT LEVEL...");
                cout<<"CONGRATULATIONS!! YOU HAVE CLEARED THIS LEVEL."<<endl<<"LOADING NEXT LEVEL...";
                delay(2000);
                goto N;
            }else{
                //closegraph();
                system("cls");
                cleardevice();
                outtextxy(450,300,"CONGRATULATIONS!! YOU HAVE FINISHED THE GAME. THANK YOU...");
                delay(3000);
                key=27;
            }
        }
    }

    //Modify Player state in File...
    //UPDATING file
    Player1.SetLevel();
    Player1.SetScore(level);

    if(Player1.level==noLevels && score>=maxScorePerLevel){    //if player has finished last level then player's current level is set to maximum level +1 to indicate the same
        level=noLevels+1;
        Player1.SetLevel();
        score=0;
        Player1.SetScore(level);
    }

    f.open("Accounts.dat" , ios::out|ios::in|ios::binary);

    PLAYER temp;
    int siz = sizeof(PLAYER)*-1;

    while(f.read((char*)&temp , sizeof(temp)))
    {
        //Matching Player
        if(strcmp(Player1.name,temp.name)==0)        
        {
            f.seekp(siz, ios::cur);
            f.write((char*)&Player1 , sizeof(Player1));
            break;
        }

    }
    f.close();

}
