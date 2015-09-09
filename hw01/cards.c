/* Prompts the user for input and puts the reply in the given buffer.

   User input is truncated to the first two characters.

   card_name: buffer where result is stored
*/

#include <stdio.h>
#include <stdlib.h>



void getCard(char cards[]) {
    /* Takes a char array and prompts the used for input and fills the array. */
    puts("Enter the card name: ");
    scanf("%2s", cards);
}

void editCount(int *count, int value) {
    /* Takes a pointer to the count and the value of the card and increments then prints the count */
    if ((value>2) && (value<7)){
        *count = *count + 1;
    } else if (value==10){
        *count = *count - 1;
    }
    printf("Current count: %i\n", *count);
}

int setVal(char cards[], int *val){
    /* Handles the card counting logic
     * Takes a char array and a pointer to the val int and sets the val int based on the char array
     * Returns a int flag to determine if count is edited
     */
    switch(cards[0]){
    case 'K':                  
    case 'Q':
    case 'J':
        *val = 10;
        break;
    case 'A':
        *val = 11;
        break;
    case 'X':
        return 0;
    default:
        *val = atoi(cards);
        if ((*val<1) || (*val>10)) {
            puts("I don't understand that value");
            return 500;
        }
    }
    return 1;
}

int main() {
    char card_name[3];
    int count = 0;
    int flag;
    int val;
    while (card_name[0]!='X'){
        getCard(card_name);
        flag = setVal(card_name, &val);
        if (flag == 1)
            editCount(&count, val);
    }
    return 0;
}


