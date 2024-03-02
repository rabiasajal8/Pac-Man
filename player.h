#ifndef PLAYER_H
#define PLAYER_H


extern int score , level;
extern const int noLevels;
using namespace std;

class PLAYER{
    public:
        char name[30];
        char passcode[12];
        int step;
        // Score per level
        int score[50];         
        // Starting level from 1
        int level;            .

        PLAYER (){
            name[0]=0;
            level=1;
            for(int i=0;i<50;i++)
                score[i]=0;
        }

        void createAccount(){
            char cnfrmPass[12];
            level=1;
            cout<<"NAME: ";
            cin>>name;
            A:
            cout<<"Enter Password : ";
            cin>>(passcode);
            cout<<"Re-enter Password :";
            cin>>(cnfrmPass);
            if(strcmp(cnfrmPass , passcode)==0)
                cout<<"Your account has been created successfully"<<endl;
             else
             {
                    system("cls");
                    goto A;
             }


        }
        void login()
        {
            cout<<"Enter Your Name: ";
            cin>>name;
            cout<<"Enter Password: ";
            cin>>passcode;
        }

        int TotalScore(){
            int sum=0;
            for(int i=0;i<50;i++)
                sum+=score[i];
            return sum;
        }

        void display()
        {
            cout<<"Name: "<<name<<endl<<endl;
            cout<<"Password: "<<passcode<<endl<<endl;
            if(level<=noLevels)
                cout<<"Level: "<<level<<endl<<endl;
            else
                cout<<"Level: "<<" Hurray........You Finished All Levels!!!"<<endl<<endl;

            for(int i=0;(i<level && i<noLevels);i++)
                cout<<"SCORE - LEVEL "<<(i+1)<<": "<<score[i]<<endl<<endl;
            cout<<"TOTAL SCORE: "<<TotalScore()<<endl<<endl;
        }

        void incrementLevel(){
            level++;
        }

        void SetScore(int lev){
            score[lev - 1]=::score;
        }

        void SetLevel(){
            level=::level;
        }


};


#endif
