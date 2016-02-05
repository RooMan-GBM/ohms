#include <stdio.h>
#include <stdlib.h>

float I=0.00f; //holds the current value
float V=0.00f; //holds the voltage value
float R=0.00f; //holds the resistance value
int ver=0; //holds verion X.0
int verb=1; // holds 0.X


float Ires(float Vin,float Rin) //calculate current v/r
{
    float Ibk=0.00f;

    if (Vin>0 && Rin>0) // can't devide by zero
    {
        Ibk=(Vin/Rin);
        printf("%0.2fA %0.0fmA\n",Ibk,Ibk*1000);
    }

    else {printf("Error: non-zero values only\n");} // no blanks or chars
return 0;
}


float Rres(float Vin,float Iin)//calulate Resistance v/i
{
    float Rbk=0.00f;

    if (Vin>0 && Iin>0) // can't devide by zero
    {
        Rbk=(Vin/Iin);
        printf("%0.0fΩ %0.3fK\n",Rbk,Rbk/1000);
    }

    else {printf("Error: non-zero values only\n");} // no blanks or chars
return 0;  // this can be used to return the result back

}

float Vres(float Rin,float Iin)//calulate voltage r*i
{
    float Vbk=0.00f;

    if (Rin>0 && Iin>0) // no blanks or zeros, just in case
    {
        Vbk=(Rin*Iin);
        printf("%0.2fV\n",Vbk);
    }

    else {printf("Error: non-zero values only\n");}
return 0; // this can be used to return the result back

}

int main() // entry point
{
int quit=0;//dont quit yet, we've only just started

while(!quit) // run forever untill we quit

{
    printf("\nOHM's V:%d.%d\n",ver,verb); // version info
    printf("Please select a mode:\n1: Current\n2: Resistance\n3: Voltage\n4: Quit\n********\n\n"); // main menu
    
    int sel=0;// lets have somewhere to store the input
    scanf("%d",&sel); // get input
    
    if(sel) // is the input a number (i admit this is a crude test)
    {
    switch(sel)
    {
        case 1://Current (I)
        printf("Please enter the Voltage. example; 3.3(V)\n");
        scanf("%f",&V);

        printf("Please enter the Resistance. example; 1000(Ω)\n");
        scanf("%f",&R);

        Ires(V,R);
        break;

        case 2://Resistance (R)
        printf("Please enter the Voltage. example; 3.3(V)\n");
        scanf("%f",&V);

        printf("Please enter the Current. example; 0.500(A)\n");
        scanf("%f",&I);

        Rres(V,I);
        break;

        case 3://Voltage (V)
        printf("Please enter the Resistance. example; 1000(Ω)\n");
        scanf("%f",&R);

        printf("Please enter the Current. example; 0.500(A)\n");
        scanf("%f",&I);

        Vres(R,I);
        break;

        case 4: // lets get outta here
        quit=1;
        break;


    }
    }
    else {quit=1;} // it seems the input is invalid, exit or error message
}
}
