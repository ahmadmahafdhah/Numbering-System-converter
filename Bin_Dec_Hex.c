#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

struct Para                                                 // a struct to add the required data.
{
    char from_base;                                         // The current base of the number.
    char from_number[300];                                  // The number we want to convert.
    char to_base;                                           // The base we want to convert the number to it.
    char to_number[300];                                    // The result (The number after conversion).
};

void clearBuffer()                                          // This function is to clear the buffer from grabage data every single time after entering data.
{
    char c;
    do
    { c = getchar(); }
    while (c != '\n' && c != EOF);
}

long int power(int a,int b)                                 // This is the power function because function pow(a,b) requires the option -lm. 
{
  long int result = 1;
  for (int i = 1; i <= b; i++)
    result = result * a;

  return result;
}

void BtoD(struct Para A)                                    // This is a binary to decimal converter.
{
    int length = strlen(A.from_number);
    int decimal = 0;
    int position = 0;
    int index = length - 1;
    while (index >= 0)
    {
        decimal=decimal+(A.from_number[index]-48) * power(2,position);
        index--;
        position++;
    }
    sprintf(A.to_number,"%d",decimal);
    printf("Number in decimal: %s",A.to_number);
}


void DtoB(struct Para A)                                    // This is a decimal to binary converter.
{
    int l = strlen(A.from_number);
    char *str = A.from_number;
    char str2[300];
    long int n = atoi(str);
    int i;
  
    for(i = 0; n > 0 ; i++)
    {
        if( n % 2 == 1)
            str2[i] = '1';
        else
            str2[i] = '0';

        n = n / 2;
    }

    printf("\nNumber in Binray: ");
    for(i = i - 1; i >= 0; i--)
    { strncat(A.to_number,&str2[i],1); }
    printf("%s\n",A.to_number);
}

void HtoD(struct Para A)                                     // This is a hexadecimal to decimal converter.
{
    char *hdec = A.from_number;
    int l = strlen(A.from_number);
    long int finalval = 0;
  
    while (*hdec)
    {
        int onebyte = *hdec++;
        if (onebyte >= '0' && onebyte <= '9'){onebyte = onebyte - '0';}
        else if (onebyte >= 'a' && onebyte <='f') {onebyte = onebyte - 'a' + 10;}
        else if (onebyte >= 'A' && onebyte <='F') {onebyte = onebyte - 'A' + 10;}
        finalval = (finalval << 4) | (onebyte & 0xF);
    }

    sprintf(A.to_number,"%ld",finalval);
    printf("\nNumber in decimal: %s\n",A.to_number);
}

void DtoH(struct Para A)                                     // This is a decimal to hexadecimal converter.
{
    long int remainder,quotient;
    long int i = 1, j, temp;
    char str[100];
    char *str2 = A.from_number;
    int l = strlen(A.from_number);
    quotient = atoi(A.from_number);

    while(quotient!=0)
    {
        temp = quotient % 16;

        if( temp < 10)
            temp = temp + 48;
        else
            temp = temp + 55;

        str[i++]= temp;
        quotient = quotient / 16;
    }

    for (j = i - 1; j > 0; j--)
        strncat(A.to_number,&str[j],1);

    printf("\nNumber in hexadecimal: %s\n",A.to_number);
}

int main()
{
    char from[3];
    char to[3];
    struct Para A;

    printf("                              ________________________                               \n");
    printf(" ____________________________|Welcome to BDH converter|____________________________\n");
    printf("|                                                                                  |\n");
    printf("|-You can convert binary number to decimal number (or decimal to binary).          |\n");
    printf("|-You can convert binary number to hexadecimal number (or hexadecimal to binary).  |\n");
    printf("|-You can convert hexadecimal number to decimal number (or decimal to hexadecimal).|\n");
    printf("|__________________________________________________________________________________|\n");

    char terminate[30] = "";

    while(strcmp(terminate,"Done") != 0 && strcmp(terminate,"done"))
    {
        printf("\nEnter the base you want to convert from, supported bases:\nBinary base enter 2.\nDecimal base enter 10.\nHexadecimal base enter 16.\n");
        printf("\nEnter base: ");
        scanf("%s",from);
        clearBuffer();

        while (strcmp(from,"2") != 0 && strcmp(from,"10") != 0 && strcmp(from,"16") != 0)
        {
            printf("\nThe base you chose to convert from is not supported, supported bases:\nBinary base enter 2.\nDecimal base enter 10.\nHexadecimal base enter 16.\n");
            printf("\nEnter base: ");
            scanf("%s",from);
            clearBuffer();
        }

        if(strcmp(from,"2") == 0)
        {
            printf("\nEnter binary number to convert (sequence of 1's and 0's): ");
            scanf("%s",A.from_number);
            clearBuffer();
          
            char *bin = A.from_number;
            int l = strlen(A.from_number);
            for(int i = 0; i < l; i++)                                      // This is to check the validity of the binary number.
            {
                while(bin[i] != '0' && bin[i] != '1')
                    {
                        printf("Invalid binary number, please enter a valid binary number (sequence of 1's and 0's): ");
                        scanf("%s",A.from_number);
                        clearBuffer();
                        bin = A.from_number;
                        l = strlen(A.from_number);
                        i = 0;
                        break;
                    }
            }

            A.from_base = 'B';
            printf("\nEnter the base you want to convert to, supported base:\nDecimal base enter 10.\nHexadecimal base enter 16.\n");
            printf("\nEnter base: ");
            scanf("%s",to);
            clearBuffer();

            while (strcmp(to,"10") != 0 && strcmp(to,"16") != 0)
            {
                printf("\nThe base you chose to convert to is not supported, supported bases:\nDecimal base enter 10.\nHexadecimal base enter 16.\n");
                printf("\nEnter base: ");
                scanf("%s", to);
                clearBuffer();
            }

            if(strcmp(to,"10") == 0)
            {
                A.to_base = 'D';
                BtoD(A);
            }
            else if(strcmp(to,"16") == 0)
            {
                int length = strlen(A.from_number);
                int decimal = 0;
                int position = 0;
                int index = length - 1;
                while (index >= 0)
                {
                    decimal=decimal+(A.from_number[index]-48) * power(2,position);
                    index--;
                    position++;
                }
                sprintf(A.from_number,"%d",decimal);

                DtoH(A);
            }
        }

        else if(strcmp(from,"10") == 0)
        {
            printf("\nEnter decimal number to convert (numbers from 0 - 9): ");
            scanf("%s",A.from_number);
            clearBuffer();
          
            char *str2 = A.from_number;
            int l = strlen(A.from_number);
            for(int i = 0; i < l; i++)                                      // This is to check the validity of the decimal number.
            {
                if(str2[i]!='0' && str2[i]!='1' && str2[i]!='2' && str2[i]!='3' && str2[i]!='4' && str2[i]!='5' && str2[i]!='6' && str2[i]!='7' && str2[i]!='8' && str2[i]!='9')
                {
                    printf("Invalid decimal number, please enter a valid decimal number (numbers from 0 - 9): ");
                    scanf("%s",A.from_number);
                    clearBuffer();
                    str2 = A.from_number;
                    l = strlen(A.from_number);
                    i = 0;
                }
              
            }

            A.from_base = 'D';
            printf("\nEnter the base you want to convert to, supported base:\nBinary base enter 2.\nHexadecimal base enter 16.\n");
            printf("\nEnter base: ");
            scanf("%s",to);
            clearBuffer();

            while (strcmp(to,"2") != 0 && strcmp(to,"16") != 0)
            {
                printf("\nThe base you chose to convert the number to is not supported, supported base:\nBinary base enter 2.\nHexadecimal base enter 16.\n");
                printf("\nEnter base: ");
                scanf("%s",to);
                clearBuffer();
            }

            if (strcmp(to,"2") == 0)
            {
                A.to_base = 'B';
                DtoB(A);
            }

            else if (strcmp(to,"16") == 0)
            {
                A.to_base = 'H';
                DtoH(A);
            }
        }

        else if(strcmp(from,"16") == 0)
        {
            printf("\nEnter hexadecimal number to convert (numbers from 0 - 9) and letters from (A - F) either upper-case or lower-case: ");
            scanf("%s",A.from_number);
            clearBuffer();
          
            char *hdec = A.from_number;
            int l = strlen(A.from_number);
            for(int i = 0; i < l; i++)                                      // This is to check the validity of the hexadecimal number.
            {
                if(hdec[i]!='0' && hdec[i]!='1' && hdec[i]!='2' && hdec[i]!='3' && hdec[i]!='4' && hdec[i]!='5' && hdec[i]!='6' && hdec[i]!='7' && hdec[i]!='8' && hdec[i]!='9' && hdec[i]!='A' && hdec[i]!='B' && hdec[i]!='C' && hdec[i]!='D' && hdec[i]!='E' && hdec[i]!='F' && hdec[i]!='a' && hdec[i]!='b' && hdec[i]!='c' && hdec[i]!='d' && hdec[i]!='e' && hdec[i]!='f')
                {
                    printf("Invalid hexadecimal number, please enter a valid hexadecimal number (numbers from (0 to 9) and letters from (A to F) either upper-case or lower-case): ");
                    scanf("%s",A.from_number);
                    clearBuffer();
                    hdec = A.from_number;
                    l = strlen(A.from_number);
                    i = 0;
                }
                hdec = A.from_number;
                l = strlen(A.from_number);
            }

            A.from_base = 'H';
            printf("\nEnter the base you want to convert to, supported base are:\nBinary base enter 2.\nDecimal base enter 10.\n");
            printf("\nEnter base: ");
            scanf("%s",to);
            clearBuffer();

            while (strcmp(to,"2") != 0 && strcmp(to,"10") != 0)
            {
                printf("\nThe base you chose to convert the number to is not supported, supported base are:\nBinary base enter 2.\nDecimal base enter 10.\n");
                printf("\nEnter base: ");
                scanf("%s",to);
                clearBuffer();
            }

            if(strcmp(to,"10") == 0)
            {
                A.to_base = 'D';
                HtoD(A);
            }
            else if(strcmp(to,"2") == 0)
            {
                char *hdec = A.from_number;
                int l = strlen(A.from_number);
                int finalval = 0;
                
                while (*hdec)
                {
                    int onebyte = *hdec++;
                    if (onebyte >= '0' && onebyte <= '9'){onebyte = onebyte - '0';}
                    else if (onebyte >= 'a' && onebyte <='f') {onebyte = onebyte - 'a' + 10;}
                    else if (onebyte >= 'A' && onebyte <='F') {onebyte = onebyte - 'A' + 10;}
                    finalval = (finalval << 4) | (onebyte & 0xF);
                }

                sprintf(A.to_number,"%d",finalval);
                strcpy(A.from_number, A.to_number);
                strcpy(A.to_number, "");
                
                DtoB(A);
            }
        }
        printf("\n-If you want to stop the programm enter \"Done\" or \"done\".\n-Enter anything else if you want to do another conversion.\n-");
        scanf("%s",terminate);
        if(strcmp(terminate,"Done") == 0 || strcmp(terminate,"done") == 0 )
            {
                printf(" __________________________________________________________________________________ \n");
                printf("|                                                                                  |\n");
                printf("|                     Thank you for using BDH converter.  BYE!                     |\n");
                printf("|__________________________________________________________________________________|\n");
            }
    }
    
    return 0;
}
