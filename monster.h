#ifndef MONSTER_H
#define MONSTER_H


class MONSTER : public OBJECT{

    private:

        void *monster , *m[1];
        time_t lastGenerated;

        void initialize(){
            NEXT=0;     

            cox=20;
            coy=20;
            step=10;
            key=0;
            lastGenerated=0;

            //monster image
            setcolor(WHITE);
            setfillstyle(SOLID_FILL,BLUE);
            sector(685 , 200 , 0 , 180 , 15 , 15);  //head
            bar(670,200,700,230);       //body
            setcolor(BLUE);
            line(671,199,699,199);
            setfillstyle(SOLID_FILL,WHITE);
            fillellipse(680,200,5,10);  //eye
            fillellipse(690,200,5,10);  //eye
            setcolor(WHITE);
            line(670,200,670,230);
            line(700,200,700,230);
            line(670,230,700,230);


            area = imagesize(0, 0, 30 , 45);
            monster = malloc(area);
            getimage(670 , 185 , 700 , 230 , monster);
            putimage(670 , 185 , monster , XOR_PUT);





            m[0]=monster;
        }

    public:

        // Self referential class
        MONSTER *NEXT;      

        MONSTER(){

            initialize();
            putimage(cox , coy , m[0] , COPY_PUT);

        }

        MONSTER(int x, int y){

            initialize();
            cox=x;
            coy=y;
            putimage(cox , coy , m[0] , COPY_PUT);

        }

        ~MONSTER(){

            eraseMonster();

        }

        void clearMonster(){

            putimage(cox , coy , m[0] , XOR_PUT);

        }

        void eraseMonster(){

            clearMonster();

        }

        int obstacleUp(){
            int colour=0;
            // up-centre collission
            if((colour=getpixel(cox+15,coy-7))!=BLACK ){ 
                return colour;
            }
            //up-left collission
            else if((colour=getpixel(cox,coy-7))!=BLACK ){ 
                return colour;
            }else if((colour=getpixel(cox+30,coy-7))!=BLACK ){ //collided up-right
                return colour;
            }else
            // case of no collission
                return 0;       
        }

        int obstacleDown(){
            int colour=0;
            //down-centre collission
            if((colour=getpixel(cox+15,coy+55))!=BLACK ){ 
                return colour;
            // down-left collission
            }else if((colour=getpixel(cox,coy+55))!=BLACK ){ 
                return colour;
            }
            //down-right collission
            else if((colour=getpixel(cox+30,coy+55))!=BLACK ){ 
                return colour;
            }else
            // no collission case
                return 0;       
        }

        int obstacleLeft(){
            int colour=0;
            // left-centre collission
            if((colour=getpixel(cox-5,coy+15))!=BLACK ) 
                return colour;
            // left-up collission
            else if((colour=getpixel(cox-5,coy))!=BLACK ) 
                return colour;
            //left-bottom collission
            else if((colour=getpixel(cox-5,coy+45))!=BLACK ) 
                return colour;
            else
            // No collission
                return 0;       
        }

        int obstacleRight(){
            int colour=0;
            // right-centre collission
            if((colour=getpixel(cox+37,coy+15))!=BLACK ) 
                return colour;
            //right-up collission
            else if((colour=getpixel(cox+37,coy))!=BLACK ) 
                return colour;
             // right-bottom collission
            else if((colour=getpixel(cox+37,coy+45))!=BLACK )
                return colour;
            else
            // No collission
                return 0;       
        }

         //Steps Calculation 
        void Step(){      

            {
                //time gap between generating random numbers... 1000 ms
                if((clock()-lastGenerated)>1000){       
                    key = rand() % 4 + 1;   
                    lastGenerated=clock();
                }
                /*
                    up      =   1
                    down    =   2
                    left    =   3
                    right   =   4
                */

                {   //styling
                    // removing back image
                    putimage(cox , coy , m[0] , XOR_PUT);   
                    int colour=0;
                    if((key==1) &&  ((colour=obstacleUp())==0 || colour==RED)){             //up, if no obstacle or if obstacle is food
                        coy-=step;

                    }else if((key==2)  &&  ((colour=obstacleDown())==0 || colour==RED)){       //down
                        coy +=step;

                    }else if((key==4)  &&  ((colour=obstacleRight())==0 || colour==RED)){       //right
                        cox +=step;

                    }else if((key==3)  &&  ((colour=obstacleLeft())==0 || colour==RED)){       //left
                        cox -=step;

                    }else if(key==27){                  //Esc(escape) key: Exit
                        //break;
                    }

                    putimage(cox , coy , m[0] , XOR_PUT);   //put new image


                }


            }

        }

};

MONSTER *Front=0,*Rear=0;


void addToQueue(MONSTER &Node){
    if(Front==0){
        Front = Rear = &Node;
        Rear->NEXT=0;
    }else{
        Rear->NEXT= &Node;
        Rear = Rear->NEXT;
        Rear->NEXT=0;
    }
}

void deleteFromQueue(){
    if(Front==0){
        return;
    }else if(Front==Rear){
        MONSTER *t=Front;
        Rear = Front =0;
        delete t;
    }else{
        MONSTER *t=Front;
        Front = Front->NEXT;
        t->NEXT=0;
        delete t;
    }
}

void UpdateQueue(){
    Front=Rear=0;
}

#endif
