#ifndef OBJECT_H
#define OBJECT_H

// Using Encapsulation here 
class OBJECT{
    protected:

        int area;
        // coordinates position of x and y
        int cox,coy;        
        char key;
        // PACMAN moving steps
        int step;           

        void initialize();

// Getter and setter methods
    public:

        int getCOX(){
            return cox;
        }

        int getCOY(){
            return coy;
        }

        // Calculating PACMAN STEPS 
        void Step();
};

#endif
