#include <stdio.h>
#include <stdlib.h>
float I=0.00f;
float V=0.00f;
float R=0.00f;
int ver=0;
int verb=1;


float Ires(float Vin,float Rin) //calculate current v/r
{
    float Ibk=0.00f;

    if (Vin>0 && Rin>0)
    {
        Ibk=(Vin/Rin);
        printf("%0.2fA %0.0fmA\n",Ibk,Ibk*1000);
    }

    else {printf("Error: non-zero values only\n");}
return 0;
}


float Rres(float Vin,float Iin)//calulate Resistance v/i
{
    float Rbk=0.00f;

    if (Vin>0 && Iin>0)
    {
        Rbk=(Vin/Iin);
        printf("%0.0fΩ %0.3fK\n",Rbk,Rbk/1000);
    }

    else {printf("Error: non-zero values only\n");}
return 0;

}

float Vres(float Rin,float Iin)//calulate Resistance v/i
{
    float Vbk=0.00f;

    if (Rin>0 && Iin>0)
    {
        Vbk=(Rin*Iin);
        printf("%0.2fV\n",Vbk);
    }

    else {printf("Error: non-zero values only\n");}
return 0;

}

int main()
{
int quit=0;

while(!quit)

{
    printf("\nOHM's V:%d.%d\n",ver,verb);
    printf("Please select a mode:\n1: Current\n2: Resistance\n3: Voltage\n4: Quit\n********\n\n");
    int sel=0;
    scanf("%d",&sel);
    //quit=sel;
    if(sel)
    {
    switch(sel)
    {
        case 1://I
        printf("Please enter the Voltage. example; 3.3(V)\n");
        scanf("%f",&V);

        printf("Please enter the Resistance. example; 1000(Ω)\n");
        scanf("%f",&R);

        Ires(V,R);
        break;

        case 2://R
        printf("Please enter the Voltage. example; 3.3(V)\n");
        scanf("%f",&V);

        printf("Please enter the Current. example; 0.500(A)\n");
        scanf("%f",&I);

        Rres(V,I);
        break;

        case 3://V
        printf("Please enter the Resistance. example; 1000(Ω)\n");
        scanf("%f",&R);

        printf("Please enter the Current. example; 0.500(A)\n");
        scanf("%f",&I);

        Vres(R,I);
        break;

        case 4:
        quit=1;
        break;


    }
    }
    else {quit=1;}
}
}
