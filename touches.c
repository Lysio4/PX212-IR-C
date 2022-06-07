#include <stdlib.h>
#include <stdio.h>
#include "header.h"

char touche;
int ascii_touche;

int ascii(char value) {  
    //char c;
    //printf("Enter a character: ");
    //scanf("%c", &c);  
    
    // %d displays the integer value of a character
    // %c displays the actual character
    //printf("ASCII value of %c = %d", c, c);
    printf("ASCII value = %d", value);
    
    return 0;
}

void touches(){
    touche = litClavier();
    ascii_touche = ascii(touche);
    switch(ascii_touche){
        case 37: //left arrow
        break;
        case 38: //up arrow
        break;
        case 39: //right arrow
        break;
        case 40: //down arrow
        break;
        case 8: //backspace
        break;
        case 13: //enter
        break;
    }
}