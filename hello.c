#include<stdio.h>
#include<math.h>



int main(){
double PI=3.14159265;
for(double x=0; x<2 *PI;x+=0.2){
    double result=(sin(x));
    int z=result*10+25;
    printf("%*s",z," ");
    printf("*\n");
}

}