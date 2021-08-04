#include "stdarg.h"
#include "stdio.h"
#include "cstring.h"

//TODO: Is printf needed?

char itoc(int num)
{
    return '0' + num;
}

char itoh(int num)
{
    return num - 10 + 'a';
}

char *strrev(char *str)
{   
    char *start = str; //Start of the string  (head)
    char *end = start;   //end of the string    (tail) (Points to the beginning of the string)

    while (*end) end++;
    end--;

    //Now:
    //start points to the first char
    // end   points to the last  char
    while (start < end)
    {
        // char e = *end, s = *start;
        auto tmp = *start;
        *start = *end;
        *end = tmp;
        ++start, --end;
    }

    for (size_t i = 0; i < strlen(str); i++)
    {
        str[i+1] = end[i];
    }

    return str;
}

char *itoa(int num, char *str, int base)
{
    int counter = 0;
    int digit = 0;
    
    while (num != 0)
    {
        digit = (num % base);
        if (digit > 9)
        {
            str[counter++] = itoh(digit);
        }
        else
        {
            str[counter++] = itoc(digit);
        }
        num /= base;
    }
    
    str[counter] = '\0';
    return strrev(str);
}

int atoi(const char *str) {
    int ret = 0;
    int i;

    for (i = 0; str[i]; i++) {
        ret = ret * 10 + str[i] - '0';
    }

    return ret;
}
