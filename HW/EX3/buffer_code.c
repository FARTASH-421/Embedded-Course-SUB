#include <stdio.h>
void a0();
void a1();
void a2();
void a3();
void printBuffer();

// declare buffers
int buffer1[6];     // a1 -> a0
int buffer2[3];     // a1 -> a2
int buffer3[12];    // a3 -> a1
int buffer4[4];     // a2 -> a3

// pointer for writer and reader buffer
int index_b1 = 4, index_b2 = 2, index_b3 = 4, index_b4 = 0;


int main() {

// initialization buffers
    for(int i = 0; i < 4; i++){
        buffer1[i] = 1;

    }
    for(int i = 0; i < 2; i++){
        buffer2[i] = 1;
    }
    
    for(int i = 0; i < 4; i++){
        buffer4[i] = 1;
    }

    // print valuse all buffer initia
    printf("frist valuse: ");
    printBuffer();

    int i=0;
    while(true){
        i++;
        // these functions update all buffer, wb and rb
        a1();
            printf("fire a1: ");
            printBuffer();

        a0();
            printf("fire a0: ");
            printBuffer();

        a0();
            printf("fire a0: ");
            printBuffer();

        a2();
            printf("fire a2: ");
            printBuffer();

        a3(); 
            printf("fire a3: ");
            printBuffer();

        a3();
            printf("fire a3: ");
            printBuffer();

        a3();
            printf("fire a3: ");
            printBuffer();

        a3(); 
            printf("fire a3: ");
            printBuffer();

        a1();
            printf("fire a1: ");
            printBuffer();

        a1();
            printf("fire a3: ");
            printBuffer();
        printf("-------> End of Trun <-------");
        printf("\n------------------------------\n");

        i++;
    }
  
    return 0;
}


void a0(){
// counsume
    for (int i = 0; i < 3 ; i++)
    {
        index_b1 = index_b1-1;
        buffer1[index_b1] = 0;
    }
}

void a1(){
// counsume
    for (int i = 0; i < 4 ; i++)
    {
        index_b3 = index_b3-1;
        buffer3[index_b3] = 0;
    }

// Produce a1 to a0
    for (int i = 0; i < 2 ; i++){ 
        buffer1[index_b1] = 1;
        index_b1 = index_b1 + 1;
    }

// Produce a1 to a2
    for (int i = 0; i < 1 ; i++){
        buffer2[index_b2] = 1;
        index_b2 = index_b2 + 1;
    }  
}

void a2(){

// counsume
    for (int i = 0; i < 3 ; i++)
    {
        index_b2 = index_b2-1;
        buffer2[index_b2] = 0;
    }

// Produce a1 to a0
    for (int i = 0; i < 4 ; i++)
    {   
        buffer4[index_b4] = 1;
        index_b4 = index_b4 + 1;
    }

}

void a3(){
// counsume 
    index_b4 = index_b4-1;
    buffer4[index_b4] = 0;   

// Produce a3 to a1
    for (int i = 0; i < 3 ; i++)
    {   
        buffer3[index_b3] = 1;
        index_b3 = index_b3 + 1;
    }
}

void printBuffer(){

 printf("{%d, %d, %d, %d}\n", index_b1, index_b2, index_b3, index_b4);

    
}

