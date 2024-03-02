#ifndef PACMAN_H
#define PACMAN_H

extern int score , key;

class PACMAN : public OBJECT{

    private:

        void *rightPac , *leftPac, *upPac, *downPac, *p[3];
        int index ,keyBoardPressed;
        char chk;

        void initialize(){

            cox=20;
            coy=20;
            index=0;
            step=10;
            keyBoardPressed=0;
            chk=0;


            //black
            setcolor(BLACK);
            setfillstyle(SOLID_FILL,BLACK);
            fillellipse(685,200,15,15);

            area = imagesize(0, 0, 40 , 40);
            p[2] = malloc(area);
            getimage(670 , 185 , 700 , 215 , p[2]);
            putimage(670 , 185 , p[2] , XOR_PUT);


            //closed mouth
            setcolor(BLACK);
            setfillstyle(SOLID_FILL,YELLOW);
            fillellipse(685,200,15,15);

            area = imagesize(0, 0, 40 , 40);
            p[1] = malloc(area);
            getimage(670 , 185 , 700 , 215 , p[1]);
            putimage(670 , 185 , p[1] , XOR_PUT);

            //right
            setcolor(BLACK);
            setfillstyle(SOLID_FILL,BLACK);
            fillellipse(685,200,15,15);
            setfillstyle(SOLID_FILL,YELLOW);
            sector(685 , 200 , 30 , 330 , 15 , 15);

            area = imagesize(0, 0, 40 , 40);
            rightPac = malloc(area);
            getimage(670 , 185 , 700 , 215 , rightPac);
            putimage(670 , 185 , rightPac , XOR_PUT);

            //left
            setcolor(BLACK);
            setfillstyle(SOLID_FILL,YELLOW);
            fillellipse(685,200,15,15);
            setfillstyle(SOLID_FILL,BLACK);
            sector(685 , 200 , 150 , 210 , 15 , 15);

            area = imagesize(0, 0, 40 , 40);
            leftPac = malloc(area);
            getimage(670 , 185 , 700 , 215 , leftPac);
            putimage(670 , 185 , leftPac , XOR_PUT);

            //up
            setcolor(BLACK);
            setfillstyle(SOLID_FILL,YELLOW);
            fillellipse(685,200,15,15);
            setfillstyle(SOLID_FILL,BLACK);
            sector(685 , 200 , 60 , 120 , 15 , 15);

            area = imagesize(0, 0, 40 , 40);
            upPac = malloc(area);
            getimage(670 , 185 , 700 , 215 , upPac);
            putimage(670 , 185 , upPac , XOR_PUT);

            //down
            setcolor(BLACK);
            setfillstyle(SOLID_FILL,YELLOW);
            fillellipse(685,200,15,15);
            setfillstyle(SOLID_FILL,BLACK);
            sector(685 , 200 , 240 , 300 , 15 , 15);

            area = imagesize(0, 0, 40 , 40);
            downPac = malloc(area);
            getimage(670 , 185 , 700 , 215 , downPac);
            putimage(670 , 185 , downPac , XOR_PUT);



            p[0]=rightPac;

        }

    public:

        PACMAN(){

            initialize();
            putimage(cox , coy , p[0] , COPY_PUT);

        }

        PACMAN(int x, int y){

            initialize();
            cox=x;
            coy=y;
            putimage(cox , coy , p[0] , COPY_PUT);

        }

        ~PACMAN(){

            erasePacman();

        }

        void clearPacman(){

            putimage(cox , coy , p[2] , COPY_PUT);

        }

        void erasePacman(){
            if(p[0]==rightPac){
                int sAngle=30, eAngle=330;
                while(sAngle!=eAngle){
                    setcolor(BLACK);
                    setfillstyle(SOLID_FILL,BLACK);
                    fillellipse(cox+15,coy+15,15,15);
                    setfillstyle(SOLID_FILL,YELLOW);
                    sector(cox+15,coy+15 , sAngle , eAngle , 15 , 15);

                    sAngle+=10;
                    eAngle-=10;

                    if(sAngle>=360){
                        sAngle-=360;
                    }else if(sAngle<0){
                        sAngle+=360;
                    }
                    if(eAngle>=360){
                        eAngle-=360;
                    }else if(eAngle<0){
                        eAngle+=360;
                    }
                    delay(50);
                }
                putimage(cox , coy , p[2] , COPY_PUT);

            }else if(p[0]==leftPac){
                int sAngle=150, eAngle=210;
                while(sAngle!=eAngle){
                    setcolor(BLACK);
                    setfillstyle(SOLID_FILL,YELLOW);
                    fillellipse(cox+15,coy+15,15,15);
                    setfillstyle(SOLID_FILL,BLACK);
                    sector(cox+15,coy+15, sAngle , eAngle  , 15 , 15);

                    sAngle-=10;
                    eAngle+=10;

                    if(sAngle>=360){
                        sAngle-=360;
                    }else if(sAngle<0){
                        sAngle+=360;
                    }
                    if(eAngle>=360){
                        eAngle-=360;
                    }else if(eAngle<0){
                        eAngle+=360;
                    }

                    delay(50);
                }
                putimage(cox , coy , p[2] , COPY_PUT);

            }else if(p[0]==upPac){
                int sAngle=60, eAngle=120;
                while(sAngle!=eAngle){
                    setcolor(BLACK);
                    setfillstyle(SOLID_FILL,YELLOW);
                    fillellipse(cox+15,coy+15,15,15);
                    setfillstyle(SOLID_FILL,BLACK);
                    sector(cox+15,coy+15, sAngle , eAngle  , 15 , 15);

                    sAngle-=10;
                    eAngle+=10;

                    if(sAngle>=360){
                        sAngle-=360;
                    }else if(sAngle<0){
                        sAngle+=360;
                    }
                    if(eAngle>=360){
                        eAngle-=360;
                    }else if(eAngle<0){
                        eAngle+=360;
                    }

                    delay(50);
                }
                putimage(cox , coy , p[2] , COPY_PUT);

            }else if(p[0]==downPac){
                int sAngle=240, eAngle=300;
                while(sAngle!=eAngle){
                    setcolor(BLACK);
                    setfillstyle(SOLID_FILL,YELLOW);
                    fillellipse(cox+15,coy+15,15,15);
                    setfillstyle(SOLID_FILL,BLACK);
                    sector(cox+15,coy+15, sAngle , eAngle  , 15 , 15);

                    sAngle-=10;
                    eAngle+=10;

                    if(sAngle>=360){
                        sAngle-=360;
                    }else if(sAngle<0){
                        sAngle+=360;
                    }
                    if(eAngle>=360){
                        eAngle-=360;
                    }else if(eAngle<0){
                        eAngle+=360;
                    }

                    delay(50);
                }
                putimage(cox , coy , p[2] , COPY_PUT);

            }
        }

        int obstacleUp(){
            int colour=0;
            if((colour=getpixel(cox+15,coy-7))!=BLACK ){ //collided up-centre
                return colour;
            }else if((colour=getpixel(cox,coy-7))!=BLACK ){ //collided up-left
                return colour;
            }else if((colour=getpixel(cox+30,coy-7))!=BLACK ){ //collided up-right
                return colour;
            }else
                return 0;       //0 = no collision
        }

        int obstacleDown(){
            int colour=0;
            if((colour=getpixel(cox+15,coy+35))!=BLACK ){ //collided down-centre
                return colour;
            }else if((colour=getpixel(cox,coy+35))!=BLACK ){ //collided down-left
                return colour;
            }else if((colour=getpixel(cox+30,coy+35))!=BLACK ){ //collided down-right
                return colour;
            }else
                return 0;       //0 = no collision
        }

        int obstacleLeft(){
            int colour=0;
            if((colour=getpixel(cox-5,coy+15))!=BLACK ) //collided left-centre
                return colour;
            else if((colour=getpixel(cox-5,coy))!=BLACK ) //collided left-up
                return colour;
            else if((colour=getpixel(cox-5,coy+30))!=BLACK ) //collided left-bottom
                return colour;
            else
                return 0;       //0 = no collision
        }

        int obstacleRight(){
            int colour=0;
            if((colour=getpixel(cox+37,coy+15))!=BLACK ) //collided right-centre
                return colour;
            else if((colour=getpixel(cox+37,coy))!=BLACK ) //collided right-up
                return colour;
            else if((colour=getpixel(cox+37,coy+30))!=BLACK ) //collided right-bottom
                return colour;
            else
                return 0;       //0 = no collision
        }

        //step by 1 forward
        void stepType1(){       

            {

                while(kbhit()){
                    key=getch();
                    ::key=key;
                }
                {   // styling... 
                // removing old image
                    putimage(cox , coy , p[2] , COPY_PUT);   
                    int colour =0;  

                    // Go up if no obstacle or THERE is food
                    if((key=='w'||key=='W') && ((colour=obstacleUp())==0 || colour==RED)){             
                        coy-=step;
                        p[0]=upPac;
                        if(colour==RED)
                            score++;

                    }
                    // Go down if no obstacle or THERE is food
                    else if((key=='s'||key=='S')  && ((colour=obstacleDown())==0 || colour==RED)){       
                        coy +=step;
                        p[0]=downPac;
                        if(colour==RED)
                            score++;

                    }
                    // Go right if no obstacle or THERE is food
                    else if((key=='d'||key=='D')  && ((colour=obstacleRight())==0 || colour==RED)){       
                        cox +=step;
                        p[0]=rightPac;
                        if(colour==RED)
                            score++;

                    }
                    // Go left if no obstacle or THERE is food
                    else if((key=='a'||key=='A')  && ((colour=obstacleLeft())==0 || colour==RED)){       
                        cox -=step;
                        p[0]=leftPac;
                        if(colour==RED)
                            score++;

                    }
                    // Exit key
                    else if(key==27){                 
                        //break;
                        ::key=27;
                    }

                    putimage(cox , coy , p[index] , COPY_PUT);   //put new image
                    index=!index;
                    delay(100);

                }


            }

        }

};


#endif
