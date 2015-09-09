#include <stdio.h>
#include <stdlib.h>



void getCard(char cards[]) {
    puts("Enter the card name: ");
    scanf("%2s", cards);
}

void editCount(int *count, int value) {
    if ((value>2) && (value<7)){
        *count = *count + 1;
    } else if (value==10){
        *count = *count - 1;
    }
    printf("Current count: %i\n", *count);
}

int setVal(char cards[], int *val){
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
    while (card_name[0]!='X'){
        getCard(card_name);
        int val = 0;
        flag = setVal(card_name, &val);
        if (flag == 1)
            editCount(&count, val);
    }
    return 0;
}


