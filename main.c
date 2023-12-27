#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct stack1{
    int size1;
    int top1;
    int *arr1;
};

void shuffle(int array[], int length);
int show(struct stack1 *p1, struct stack1 *p2, struct stack1 *p3, struct stack1 *p4, struct stack1 *p5);
int winlose(struct stack1 *p1, struct stack1 *p2, struct stack1 *p3, struct stack1 *p4, struct stack1 *p5, int turns);
void pushing(struct stack1 *p1, struct stack1 *p2, struct stack1 *p3, struct stack1 *p4, struct stack1 *p5, int tmp, int c);
void create(struct stack1 *p1, struct stack1 *p2, struct stack1 *p3, struct stack1 *p4, struct stack1 *p5);
int elements[16] = {1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4};

int isEmpty(struct stack1 *ptr){
    if(ptr -> top1 == -1){
        return 1;
    }
    else{
        return 0;
    }}

int isFull(struct stack1 * ptr){
    if(ptr -> top1 == ptr -> size1 - 1){
        return 1;
    }
    else{
        return 0;
    }
}
int push(struct stack1 * ptr, int val){
    if(isFull(ptr)){
        printf("Stack overflow.\nYou lose!\n");
        exit(0);
    }
    else{
        ptr -> top1++;
        ptr -> arr1[ptr -> top1] = val;
}}
int pop(struct stack1 * ptr){
    if(isEmpty(ptr)){
        printf("Stack underflow.\nYou lose!\n");
        exit(0);
    }
    else{
        int val = ptr -> arr1[ptr -> top1];
        ptr -> top1--;
}}
int display(struct stack1 * ptr, int i)
{
        return ptr -> arr1[ptr -> top1 - i + 1];
}

int main()
{
    int choice2, choice1, temp, score = 0;

    struct stack1 *sp1 = (struct stack1 *)malloc(sizeof(struct stack1));
    struct stack1 *sp2 = (struct stack1 *)malloc(sizeof(struct stack1));
    struct stack1 *sp3 = (struct stack1 *)malloc(sizeof(struct stack1));
    struct stack1 *sp4 = (struct stack1 *)malloc(sizeof(struct stack1));
    struct stack1 *sp5 = (struct stack1 *)malloc(sizeof(struct stack1));
    sp1 -> size1 = 4;
    sp1 -> top1 = -1;
    sp1 -> arr1 = (int *)malloc(sp1 -> size1 * sizeof(int));
    sp2 -> size1 = 4;
    sp2 -> top1 = -1;
    sp2 -> arr1 = (int *)malloc(sp1 -> size1 * sizeof(int));
    sp3 -> size1 = 4;
    sp3 -> top1 = -1;
    sp3 -> arr1 = (int *)malloc(sp1 -> size1 * sizeof(int));
    sp4 -> size1 = 4;
    sp4 -> top1 = -1;
    sp4 -> arr1 = (int *)malloc(sp1 -> size1 * sizeof(int));
    sp5 -> size1 = 4;
    sp5 -> top1 = -1;
    sp5 -> arr1 = (int *)malloc(sp1 -> size1 * sizeof(int));

    shuffle(elements, 16);
    create(sp1, sp2, sp3, sp4, sp5);

    printf("WELCOME TO NUMBER STACK!\nTRY TO GET ALL SIMILAR ELEMENTS IN ONE STACK!\nHere are the rules:\n\nA)Each stack has a number ID written below it. Use them to maneuver between stacks.\n\nB)Try to solve the puzzle in the least number of turns possible.\n\nC)If stack is overflowed or underflowed, you lose.\n\n");

    show(sp1, sp2, sp3, sp4, sp5);
    do{
    score = score + 1;
    printf("Enter the stack number you want to pop from.\nEnter 0 if you wish to submit.\n");
    scanf("%d", &choice1);
    if(choice1 != 0){
    printf("Enter the stack number you want to insert in: \n");
    scanf("%d", &choice2);}

    switch(choice1){
    case 1:
        temp = sp1 -> arr1[sp1 -> top1];
        pop(sp1);
        pushing(sp1, sp2, sp3, sp4, sp5, temp, choice2);
        show(sp1, sp2, sp3, sp4, sp5);
    break;

    case 2:
        temp = sp2 -> arr1[sp2 -> top1];
        pop(sp2);
        pushing(sp1, sp2, sp3, sp4, sp5, temp, choice2);
        show(sp1, sp2, sp3, sp4, sp5);
    break;

    case 3:
        temp = sp3 -> arr1[sp3 -> top1];
        pop(sp3);
        pushing(sp1, sp2, sp3, sp4, sp5, temp, choice2);
        show(sp1, sp2, sp3, sp4, sp5);
    break;

    case 4:
        temp = sp4 -> arr1[sp4 -> top1];
        pop(sp4);
        pushing(sp1, sp2, sp3, sp4, sp5, temp, choice2);
        show(sp1, sp2, sp3, sp4, sp5);
    break;

    case 5:
        temp = sp5 -> arr1[sp5 -> top1];
        pop(sp5);
        pushing(sp1, sp2, sp3, sp4, sp5, temp, choice2);
        show(sp1, sp2, sp3, sp4, sp5);
    break;

    }
    }while(choice1 != 0);

    winlose(sp1, sp2, sp3, sp4, sp5, score);

    return 0;

}

void shuffle(int array[], int length)
{
  srand( time(NULL) );

  for (int i = 0; i < length; i++)
  {
    int swap_index = rand() % length;

    int temp = array[i];
    array[i] = array[swap_index];
    array[swap_index] = temp;
  }

}

void create(struct stack1 *p1, struct stack1 *p2, struct stack1 *p3, struct stack1 *p4, struct stack1 *p5){
    for(int i = 0; i < 4; i++){
    push(p1, elements[i]);}
    for(int j = 4; j < 8; j++){
    push(p2, elements[j]);}
    for(int k = 8; k < 12; k++){
    push(p3, elements[k]);}
    for(int l = 12; l < 16; l++){
    push(p4, elements[l]);}
    }

int show(struct stack1 *p1, struct stack1 *p2, struct stack1 *p3, struct stack1 *p4, struct stack1 *p5){
    //First stack

    printf("\t\t\t\t\t\t\t(' _ ')\n");
    printf("\t\t\t\t\t\t\t/    /\n\n");
    if(p1 -> top1 == -1){
        for(int index = 0; index < 4; index++){
            printf("\t\t\t\t\t\t\t|   |\n");
            }
    }
    else if(p1 -> top1 == 0){
        for(int index = 0; index < 3; index++){
            printf("\t\t\t\t\t\t\t|   |\n");
        }
        printf("\t\t\t\t\t\t\t| %d |\n", display(p1, 1));
    }
    else if(p1 -> top1 == 1){
        for(int index = 0; index < 2; index++){
            printf("\t\t\t\t\t\t\t|   |\n");
        }
        for(int jndex = 1; jndex <= 2; jndex++){
            printf("\t\t\t\t\t\t\t| %d |\n", display(p1, jndex));
        }
    }
    else if(p1 -> top1 == 2){
        printf("\t\t\t\t\t\t\t|   |\n");
        for(int jndex = 1; jndex <= 3; jndex++){
            printf("\t\t\t\t\t\t\t| %d |\n", display(p1, jndex));
        }
    }
    else if(p1 -> top1 == 3){
        for(int jndex = 1; jndex <= 4; jndex++){
            printf("\t\t\t\t\t\t\t| %d |\n", display(p1, jndex));
        }
    }
    printf("\t\t\t\t\t\t\t|___|\n");
    printf("\t\t\t\t\t\t\tStack 1");
    printf("\n\n");

    //For second stack

    if(p2 -> top1 == -1){
        for(int index = 0; index < 4; index++){
            printf("\t\t\t\t\t\t\t|   |\n");
            }
    }
    else if(p2 -> top1 == 0){
        for(int index = 0; index < 3; index++){
            printf("\t\t\t\t\t\t\t|   |\n");
        }
        printf("\t\t\t\t\t\t\t| %d |\n", display(p2, 1));
    }
    else if(p2 -> top1 == 1){
        for(int index = 0; index < 2; index++){
            printf("\t\t\t\t\t\t\t|   |\n");
        }
        for(int jndex = 1; jndex <= 2; jndex++){
            printf("\t\t\t\t\t\t\t| %d |\n", display(p2, jndex));
        }
    }
    else if(p2 -> top1 == 2){
        printf("\t\t\t\t\t\t\t|   |\n");
        for(int jndex = 1; jndex <= 3; jndex++){
            printf("\t\t\t\t\t\t\t| %d |\n", display(p2, jndex));
        }
    }
    else if(p2-> top1 == 3){
        for(int jndex = 1; jndex <= 4; jndex++){
            printf("\t\t\t\t\t\t\t| %d |\n", display(p2, jndex));
        }
    }
    printf("\t\t\t\t\t\t\t|___|\n");
    printf("\t\t\t\t\t\t\tStack 2");
    printf("\n\n");

    //For third stack
    if(p3 -> top1 == -1){
        for(int index = 0; index < 4; index++){
            printf("\t\t\t\t\t\t\t|   |\n");
            }
    }
    else if(p3 -> top1 == 0){
        for(int index = 0; index < 3; index++){
            printf("\t\t\t\t\t\t\t|   |\n");
        }
        printf("\t\t\t\t\t\t\t| %d |\n", display(p3, 1));
    }
    else if(p3 -> top1 == 1){
        for(int index = 0; index < 2; index++){
            printf("\t\t\t\t\t\t\t|   |\n");
        }
        for(int jndex = 1; jndex <= 2; jndex++){
            printf("\t\t\t\t\t\t\t| %d |\n", display(p3, jndex));
        }
    }
    else if(p3 -> top1 == 2){
        printf("\t\t\t\t\t\t\t|   |\n");
        for(int jndex = 1; jndex <= 3; jndex++){
            printf("\t\t\t\t\t\t\t| %d |\n", display(p3, jndex));
        }
    }
    else if(p3 -> top1 == 3){
        for(int jndex = 1; jndex <= 4; jndex++){
            printf("\t\t\t\t\t\t\t| %d |\n", display(p3, jndex));
        }
    }
    printf("\t\t\t\t\t\t\t|___|\n");
    printf("\t\t\t\t\t\t\tStack 3");
    printf("\n\n");

    //For fourth stack

    if(p4 -> top1 == -1){
        for(int index = 0; index < 4; index++){
            printf("\t\t\t\t\t\t\t|   |\n");
            }
    }
    else if(p4 -> top1 == 0){
        for(int index = 0; index < 3; index++){
            printf("\t\t\t\t\t\t\t|   |\n");
        }
        printf("\t\t\t\t\t\t\t| %d |\n", display(p4, 1));
    }
    else if(p4 -> top1 == 1){
        for(int index = 0; index < 2; index++){
            printf("\t\t\t\t\t\t\t|   |\n");
        }
        for(int jndex = 1; jndex <= 2; jndex++){
            printf("\t\t\t\t\t\t\t| %d |\n", display(p4, jndex));
        }
    }
    else if(p4 -> top1 == 2){
        printf("\t\t\t\t\t\t\t|   |\n");
        for(int jndex = 1; jndex <= 3; jndex++){
            printf("\t\t\t\t\t\t\t| %d |\n", display(p4, jndex));
        }
    }
    else if(p4 -> top1 == 3){
        for(int jndex = 1; jndex <= 4; jndex++){
            printf("\t\t\t\t\t\t\t| %d |\n", display(p4, jndex));
        }
    }
    printf("\t\t\t\t\t\t\t|___|\n");
    printf("\t\t\t\t\t\t\tStack 4");
    printf("\n\n");

    //For fifth stack

    if(p5 -> top1 == -1){
        for(int index = 0; index < 4; index++){
            printf("\t\t\t\t\t\t\t|   |\n");
            }
    }
    else if(p5 -> top1 == 0){
        for(int index = 0; index < 3; index++){
            printf("\t\t\t\t\t\t\t|   |\n");
        }
        printf("\t\t\t\t\t\t\t| %d |\n", display(p5, 1));
    }
    else if(p5-> top1 == 1){
        for(int index = 0; index < 2; index++){
            printf("\t\t\t\t\t\t\t|   |\n");
        }
        for(int jndex = 1; jndex <= 2; jndex++){
            printf("\t\t\t\t\t\t\t| %d |\n", display(p5, jndex));
        }
    }
    else if(p5 -> top1 == 2){
        printf("\t\t\t\t\t\t\t|   |\n");
        for(int jndex = 1; jndex <= 3; jndex++){
            printf("\t\t\t\t\t\t\t| %d |\n", display(p5, jndex));
        }
    }
    else if(p5 -> top1 == 3){
        for(int jndex = 1; jndex <= 4; jndex++){
            printf("\t\t\t\t\t\t\t| %d |\n", display(p5, jndex));
        }
    }
    printf("\t\t\t\t\t\t\t|___|\n");
    printf("\t\t\t\t\t\t\tStack 5");
    printf("\n\n");
    }

void pushing(struct stack1 *p1, struct stack1 *p2, struct stack1 *p3, struct stack1 *p4, struct stack1 *p5, int tmp, int c){

        if(c == 1){
            push(p1, tmp);
        }
        else if(c == 2){
            push(p2, tmp);
        }
        else if(c == 3){
            push(p3, tmp);
        }
        else if(c == 4){
            push(p4, tmp);
        }
        else if(c == 5){
            push(p5, tmp);
        }

    }

int winlose(struct stack1 *p1, struct stack1 *p2, struct stack1 *p3, struct stack1 *p4, struct stack1 *p5, int turns){

    if (isEmpty(p1)){
         if(p2 -> arr1[p2 -> top1] == p2 -> arr1[p2 -> top1 - 1] && p2 -> arr1[p2 -> top1 - 1] == p2 -> arr1[p2 -> top1 - 2] && p2 -> arr1[p2 -> top1 - 2] == p2 -> arr1[p2 -> top1 - 3]){
                if(p3 -> arr1[p3 -> top1] == p3 -> arr1[p3 -> top1 - 1] && p3 -> arr1[p3 -> top1 - 1] == p3 -> arr1[p3 -> top1 - 2] && p3 -> arr1[p3 -> top1 - 2] == p3 -> arr1[p3 -> top1 - 3]){
                    if(p4 -> arr1[p4 -> top1] == p4 -> arr1[p4-> top1 - 1] && p4 -> arr1[p4-> top1 - 1] == p4 -> arr1[p4 -> top1 - 2] && p4 -> arr1[p4 -> top1 - 2] == p4 -> arr1[p4 -> top1 - 3]){
                            if(p5 -> arr1[p5 -> top1] == p5 -> arr1[p5-> top1 - 1] && p5 -> arr1[p5 -> top1 - 1] == p5 -> arr1[p5 -> top1 - 2] && p5 -> arr1[p5 -> top1 - 2] == p5 -> arr1[p5 -> top1 - 3]){
                                printf("Success! It took you only %d turns to solve B)\n", turns);
}
    else{printf("You lose!\n");}
}
    else{printf("You lose!\n");}
}
    else{printf("You lose!\n");}
}
    else{printf("You lose!\n");}
    }


    else if(isEmpty(p2)){
            if(p1 -> arr1[p1 -> top1] == p1 -> arr1[p1 -> top1 - 1] && p1 -> arr1[p1 -> top1 - 1] == p1 -> arr1[p1 -> top1 - 2] && p1 -> arr1[p1 -> top1 - 2] == p1 -> arr1[p1 -> top1 - 3]){
                if(p3 -> arr1[p3 -> top1] == p3 -> arr1[p3 -> top1 - 1] && p3 -> arr1[p3 -> top1 - 1] == p3 -> arr1[p3 -> top1 - 2] && p3 -> arr1[p3 -> top1 - 2] == p3 -> arr1[p3 -> top1 - 3]){
                    if(p4 -> arr1[p4 -> top1] == p4 -> arr1[p4-> top1 - 1] && p4 -> arr1[p4-> top1 - 1] == p4 -> arr1[p4 -> top1 - 2] && p4 -> arr1[p4 -> top1 - 2] == p4 -> arr1[p4 -> top1 - 3]){
                            if(p5 -> arr1[p5 -> top1] == p5 -> arr1[p5-> top1 - 1] && p5 -> arr1[p5 -> top1 - 1] == p5 -> arr1[p5 -> top1 - 2] && p5 -> arr1[p5 -> top1 - 2] == p5 -> arr1[p5 -> top1 - 3]){
                                printf("Success! It took you only %d turns to solve B)\n", turns);
}
    else{printf("You lose!\n");}
}
    else{printf("You lose!\n");}
}
    else{printf("You lose!\n");}
}
    else{printf("You lose!\n");}
    }

    else if(isEmpty(p3)){
         if(p1 -> arr1[p1 -> top1] == p1 -> arr1[p1 -> top1 - 1] && p1 -> arr1[p1 -> top1 - 1] == p1 -> arr1[p1 -> top1 - 2] && p1 -> arr1[p1 -> top1 - 2] == p1 -> arr1[p1 -> top1 - 3]){
                if(p2 -> arr1[p2 -> top1] == p2 -> arr1[p2 -> top1 - 1] && p2 -> arr1[p2 -> top1 - 1] == p2 -> arr1[p2 -> top1 - 2] && p2 -> arr1[p2 -> top1 - 2] == p2 -> arr1[p2 -> top1 - 3]){
                    if(p4 -> arr1[p4 -> top1] == p4 -> arr1[p4-> top1 - 1] && p4 -> arr1[p4-> top1 - 1] == p4 -> arr1[p4 -> top1 - 2] && p4 -> arr1[p4 -> top1 - 2] == p4 -> arr1[p4 -> top1 - 3]){
                            if(p5 -> arr1[p5 -> top1] == p5 -> arr1[p5-> top1 - 1] && p5 -> arr1[p5 -> top1 - 1] == p5 -> arr1[p5 -> top1 - 2] && p5 -> arr1[p5 -> top1 - 2] == p5 -> arr1[p5 -> top1 - 3]){
                                printf("Success! It took you only %d turns to solve B)\n", turns);
}
    else{printf("You lose!\n");}
}
    else{printf("You lose!\n");}
}
    else{printf("You lose!\n");}
}
    else{printf("You lose!\n");}
    }

    else if(isEmpty(p4)){
            if(p1 -> arr1[p1 -> top1] == p1 -> arr1[p1 -> top1 - 1] && p1 -> arr1[p1 -> top1 - 1] == p1 -> arr1[p1 -> top1 - 2] && p1 -> arr1[p1 -> top1 - 2] == p1 -> arr1[p1 -> top1 - 3]){
                if(p2 -> arr1[p2 -> top1] == p2 -> arr1[p2 -> top1 - 1] && p2 -> arr1[p2 -> top1 - 1] == p2 -> arr1[p2 -> top1 - 2] && p2 -> arr1[p2 -> top1 - 2] == p2 -> arr1[p2 -> top1 - 3]){
                    if(p3 -> arr1[p3 -> top1] == p3 -> arr1[p3 -> top1 - 1] && p3 -> arr1[p3 -> top1 - 1] == p3 -> arr1[p3 -> top1 - 2] && p3 -> arr1[p3 -> top1 - 2] == p3 -> arr1[p3 -> top1 - 3]){
                            if(p5 -> arr1[p5 -> top1] == p5 -> arr1[p5-> top1 - 1] && p5 -> arr1[p5 -> top1 - 1] == p5 -> arr1[p5 -> top1 - 2] && p5 -> arr1[p5 -> top1 - 2] == p5 -> arr1[p5 -> top1 - 3]){
                                printf("Success! It took you only %d turns to solve B)\n", turns);
}
    else{printf("You lose!\n");}
}
    else{printf("You lose!\n");}
}
    else{printf("You lose!\n");}
}
    else{printf("You lose!\n");}
    }



else if(isEmpty(p5)){
        if(p1 -> arr1[p1 -> top1] == p1 -> arr1[p1 -> top1 - 1] && p1 -> arr1[p1 -> top1 - 1] == p1 -> arr1[p1 -> top1 - 2] && p1 -> arr1[p1 -> top1 - 2] == p1 -> arr1[p1 -> top1 - 3]){
                if(p2 -> arr1[p2 -> top1] == p2 -> arr1[p2 -> top1 - 1] && p2 -> arr1[p2 -> top1 - 1] == p2 -> arr1[p2 -> top1 - 2] && p2 -> arr1[p2 -> top1 - 2] == p2 -> arr1[p2 -> top1 - 3]){
                    if(p3 -> arr1[p3 -> top1] == p3 -> arr1[p3 -> top1 - 1] && p3 -> arr1[p3 -> top1 - 1] == p3 -> arr1[p3 -> top1 - 2] && p3 -> arr1[p3 -> top1 - 2] == p3 -> arr1[p3 -> top1 - 3]){
                            if(p4 -> arr1[p4 -> top1] == p4 -> arr1[p4-> top1 - 1] && p4 -> arr1[p4-> top1 - 1] == p4 -> arr1[p4 -> top1 - 2] && p4 -> arr1[p4 -> top1 - 2] == p4 -> arr1[p4 -> top1 - 3]){
                                printf("Success! It took you only %d turns to solve B)\n", turns);
}
    else{printf("You lose!\n");}
}
    else{printf("You lose!\n");}
}
    else{printf("You lose!\n");}
}
    else{printf("You lose!\n");}
    }
}

