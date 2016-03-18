#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "pow.h"
#include "sort.h"

#define ADD 1
#define SUB 2
#define MUL 3
#define DIV 4
#define POW 5
#define MOD 6
#define SORT 7

#define OPTIONS 7

//operations can only be 4 letters long
static char *options[][5] = { {"add"}, {"sub"}, {"mul"}, {"div"}, {"pow"}, {"mod"}, {"sort"}};

void printUsage() {
    printf("Usage: myCalc <operation> a b (c, d, e...)\n");
    printf("Operations: add, sub, mul, div, pow, mod, sort\n");
	exit(1);
}

int whichOption(char *str){
    for (int i = 0; i < OPTIONS; ++i) {
        if (strcmp(str, options[i]) == 0) {
            return i;
        }
    }
    return 0;
}

int main (int argc, char *argv[]) {
    if (argc < 4)) {
	    printUsage();
    }

    int a = atoi(argv[2]);
    int b = atoi(argv[3]);

    #ifdef DEBUG
    printf("Just so you know, this is in debug mode!\n");
    #endif
    
    switch(whichOption(argv[1])) {
        case ADD:
            printf("%d\n", a + b);
            break;
        
        case SUB:
            printf("%d\n", a - b);
            break;
        
        case MUL:
            printf("%d\n", a * b);
            break;
        
        case DIV:
            printf("%d\n", a / b);
            break;
        
        case POW:
            printf("%d\n", myPow(a, b));
            break;
        
        case MOD:
            printf("%d\n", a % b);
            break;
        
        case SORT:
            int array[argc - 2];
            for (int i = argc - 1; i > 1; --i) {
                array[i] = atoi(argv[i]);
            }
            radixSort(array, argc - 2);
            printList(array, argc - 2);
        
        case default:
            printUsage();
            break;
    }
    
    return 0;
}
