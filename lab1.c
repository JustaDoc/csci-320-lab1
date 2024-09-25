#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab1.h"
/*
 * readString - reads a line from a file given by
 * fileName and returns it as a c-string.  The line
 * return is removed from the string.
 * 
 * fileName is c-string representing the file to read.
 * 
 */
char* readString(char* fileName){
    //TODO: Replace this line with your code
    char buffer[100];

    FILE *file = fopen(fileName, "r");

    if(file == NULL){
        return NULL;
    }

    if (fgets(buffer, 100, file) != NULL){
        buffer[strcspn(buffer,"\n")] = '\0';
        fclose(file);
        
        char* res = (char*)malloc(strlen(buffer) + 1);
        strcpy(res, buffer);
        return res;
    }

    fclose(file);
    return NULL;
}

/*
 * mysteryExplode - takes a string of characters and explodes it
 * as follows:
 * 
 * A non-empty string such as "Code" is turned into "CCoCodCode".
 *
 *   Return a new string similar to the string given above.
 *
 *  Example:
 *   mysteryExplosion("Code") --> "CCoCodCode"
 *   mysteryExplosion("abc") --> "aababc"
 *   mysteryExplosion(":)") --> "::)"
 * 
 */
char* mysteryExplode(const char* str){
    //TODO: Replace this line with your code    must include malik 
    int len = strlen(str);
    int new = (len * (len+1)/2);

    
    char *result = (char*)malloc((new + 1)*sizeof(char));

    if (result == NULL){
        return NULL;
    }

    result[0] = '\0';

    for(int i = 1; i <= len; i++ ){
        strncat(result, str, i);
    }

    return result;
}