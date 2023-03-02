#include <stdio.h>
int main(void){
    float bill,sale,tip,final;
    printf("Enter bill: ");
    scanf("%f",&bill);
    printf("Enter sale tax %%: ");
    scanf("%f",&sale);
    printf("Enter tip %%: ");
    scanf("%f",&tip);
    sale/=100;
    tip/=100;
    final=bill+(bill*sale)+(bill+(bill*sale))*tip;
    final/=2;
    printf("You will owe $%0.2f each!\n",final);
}