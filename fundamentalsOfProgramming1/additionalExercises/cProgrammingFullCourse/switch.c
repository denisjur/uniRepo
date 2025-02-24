#include <stdio.h>

// ####Instead of DOING THIS: ####
// 
// int main() {
//    char grade;
//
//    printf("\nEnter a letter grade: ");
//    scanf("%c", &grade);
//
//    if (grade == 'A') {
//        printf("Perfect!\n");
//    }
//    else if (grade == 'B') {
//        printf("You did good!\n");
//    }
//    else if (grade == 'C') {
//        printf("You did okay\n");
//    }
//    else if (grade == 'D') {
//        printf("At least it's not an F\n");
//    }
//    else if (grade == 'F') {
//        printf("YOU FAILED\n");
//    } 
//    else {
//        printf("That's not a valid grade\n");
//    };
//  return 0;
//  };

#include <stdio.h>

int main() {
    // switch = A more efficient alternative to using many "else if" statements
    //          allows a value to be tested for equality against many cases

    char grade;

    printf("\nEnter a letter grade: ");
    scanf("%c", &grade);

    switch (grade) {
        case 'A':
            printf("Perfect!\n");
            break;                  // Wee need the break to exit out of our switch. If we don't use it, we continue executing  every case that comes our way.
        case 'B':
            printf("You did good!\n");
            break;
        case 'C':
            printf("You did okay\n");
            break;
        case 'D':
            printf("At least it's not an F\n");
            break;
        case 'F':
            printf("YOU FAILED\n");
            break;
        default:
            printf("That's not a valid grade\n");
            break;
    };

    return 0;
};


