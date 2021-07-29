#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//Coded by Ethan Woollet - January 2021
int main(void){
    int baseIn, baseOut, rem, input[20], output[20], temp=0;
    char help, trash, num[21];
    long long int decimal=0, quot, dec[20];
    printf("\n***THIS CONVERTER ONLY WORKS WITH BASES BETWEEN 2 AND 36***\n\nWould you like to see the steps?(y or n)\n");
    scanf("%c", &help);
    if((help != 'y') && (help != 'n')){
        printf("\n'%c' is not \"yes\" or \"no\", you absolute Dum-Dum\n", help);
        return 0;
    }
    printf("What base are you converting from?\n");
    scanf("%c", &trash);
    scanf("%d", &baseIn);
    printf("What base would you like to convert to?\n");
    scanf("%d", &baseOut);
    printf("Enter the number you would like to convert:\n");
    scanf("%s", num);
    for(int i= 0; num[i]!='\0' ; i++){
        if((num[i] >= 48)&&(num[i]<=57)){
            input[i]=num[i]-48;
        }
        else if((num[i]>= 65)&&(num[i]<=90)){
            input[i]=(num[i]-65)+10;
        }
        else if((num[i]>= 97)&&(num[i]<= 122)){
            input[i]=(num[i]-97)+10;
        }
        temp=i;
    }
    if(help == 'y'){
        printf("\nConverting %s to decimal:", num);
        for(int i=0; i<=temp;i++){
            decimal+= input[i]*(pow(baseIn, (temp-i)));
            printf("\n%2d x (%2d^%2d) =   %20.0f", input[i], baseIn, (temp-i), (input[i])*(pow(baseIn, (temp-i))));
        }
        printf("  +\n-----------------------------------------------------------\n%llu\n", decimal);
        printf("\nConverting %llu to base %d\n", decimal, baseOut);
        for(int i=0; ; i++){
            if(i==0){
            rem = decimal%baseOut;
            quot = decimal/baseOut;
            dec[i] = rem;
            printf("%20llu / %2d = %20llu   +   %2d\n", decimal, baseOut, quot, rem);
            }
            else{
                printf("%20llu ", quot);
                rem =quot%baseOut;
                quot = quot/baseOut;
                dec[i] = rem;
                printf("/ %2d = %20llu   +   %2d\n", baseOut, quot, rem);
            }
            if((quot*baseOut)<baseOut){
                temp = i;
                break;
            }
        }
           printf("-----------------------------------------------------------\n\n%s in converted to from base %d to base %d is:    ", num, baseIn, baseOut);
           for(int i=temp; i>=0; i--){
               if(dec[i]>9){
                   printf("%c", 65+(dec[i]-10));
               }
               else printf("%d", dec[i]);
           }
    }
    if(help == 'n'){
        for(int i=0; i<=temp;i++){
            decimal+= input[i]*(pow(baseIn, (temp-i)));
        }
        for(int i=0; ; i++){
            if(i==0){
            rem = decimal%baseOut;
            quot = decimal/baseOut;
            dec[i] = rem;
            }
            else{
                rem =quot%baseOut;
                quot = quot/baseOut;
                dec[i] = rem;
            }
            if((quot*baseOut)<baseOut){
                temp = i;
                break;
            }
        }
           printf("--------------------------------\n\n%s in converted to from base %d to base %d is:    ", num, baseIn, baseOut);
           for(int i=temp; i>=0; i--){
               if(dec[i]>9){
                   printf("%c", 65+(dec[i]-10));
               }
               else printf("%d", dec[i]);
           }
    }
    printf("\n\n");
    return 0;
}
