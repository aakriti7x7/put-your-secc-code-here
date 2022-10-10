#include <stdio.h>
#include <conio.h>
#include <math.h>
int main()
{
    int dec_num=0, dec_num1=0, rem, i=0, len=0, lenTemp, s=0;
    float dec_num2=0;
    char hexnum[20]; 
    printf("Enter any Hexadecimal Number: ");
    scanf("%s", hexnum);
    while(hexnum[i]!='\0') 
    {
        if(hexnum[i]=='.') // checking if there is any decimal point in the hxadecimal number and then storing its location
            s = i;
            len++; 
            i++;
    }
    len--;
    i=0;
    if(s==0) // if there is no decimal point executing the below code
    {
        while(len>=0) // converting the number
        {
            rem = hexnum[len]; // storing the character at last index of hexadecimal number in rem
            if(rem>=48 && rem<=57) // when number is between 0 to 9 storing its value in rem by subtracting 48 from its ASCII value 
                rem = rem-48;
            else if(rem>=65 && rem<=70) // when number if between 'A' to 'F' storing its value in rem by subtracting 55 from its ASCII value 
                rem = rem-55;
            else if(rem>=97 && rem<=102) // when number if between 'a' to 'f' storing its value in rem by subtracting 87 from its ASCII value 
                rem = rem-87;
            else // if none of above then the number entered is invalid
            {
                printf("\nYou've entered an invalid Hexadecimal digit.");
                return 0;
            }
            dec_num = dec_num + (rem*pow(16, i)); // storing the decimal value after conversion in dec_num for this case
            len--;
            i++;
        }
        printf("\nEquivalent Decimal Value = %d", dec_num);
    }
    else // if there is decimal point executing the below code
    {
        lenTemp = s-1; // storing the index 1 less than the position where decimal point is found
        while(lenTemp>=0) //checking if there is number present before decimal point
        {
            rem = hexnum[lenTemp];
            if(rem>=48 && rem<=57)
                rem = rem-48;
            else if(rem>=65 && rem<=70)
                rem = rem-55;
            else if(rem>=97 && rem<=102)
                rem = rem-87;
            else
            {
                printf("\nYou've entered an invalid Hexadecimal digit");
                return 0;
            }
            dec_num1 = dec_num1 + (rem*pow(16, i)); // storing the decimal value after conversion in dec_num1 for this case
            lenTemp--;
            i++;
        }
        lenTemp = s+1; // storing the index 1 greater than the position where decimal point is found
        i=-1; //for power of numbers after decimal point
        while(lenTemp<=len)
        {
            rem = hexnum[lenTemp];
            if(rem>=48 && rem<=57)
                rem = rem-48;
            else if(rem>=65 && rem<=70)
                rem = rem-55;
            else if(rem>=97 && rem<=102)
                rem = rem-87;
            else
            {
                printf("\nYou've entered an invalid Hexadecimal digit");
                return 0;
            }
            dec_num2 = dec_num2 + (rem*pow(16, i)); // storing the decimal value after conversion in dec_num2 for this case
            lenTemp++;
            i--;
        }
        dec_num2 = dec_num1+dec_num2; 
        printf("\nEquivalent Decimal Value = %0.8f", dec_num2); // printing the final decimal number when decimal point is present
    }
    return 0;
}
