#include <stdio.h>

#define MAX 9

void board();

struct stack {
  int array[MAX];
  int top;
};

void init_stack(struct stack * s) {
  s -> top = -1;
}

void push(struct stack * s, int item) {
  if (s -> top == MAX - 1) {
    printf("Stack is full. Couldn't push '%d' onto stack\n", item);
    return;
  }
  s -> top++;
  s -> array[s -> top] = item;
}

int * pop(struct stack * s) {
  int * data;
  if (s -> top == -1) {
    printf("       No moves to undo\n");
    return NULL;
  }
  data = & s -> array[s -> top];
  s -> top--;
  return data;
}

struct stack2 {
  int array2[MAX];
  int top2;
};

void init_stack2(struct stack2 * rs) {
  rs -> top2 = -1;
}

void push2(struct stack2 * rs, int item) {
  if (rs -> top2 == MAX - 1) {
    printf("   Stack is full. Couldn't push '%d' onto stack\n", item);
    return;
  }
  rs -> top2++;
  rs -> array2[rs -> top2] = item;
}

int * pop2(struct stack2 * rs) {
  int * data2;
  if (rs -> top2 == -1) {
    printf("             No moves to redo.\n");
    return NULL;
  }
  data2 = & rs -> array2[rs -> top2];
  rs -> top2--;
  return data2;
}

char square[9] = {
  '1',
  '2',
  '3',
  '4',
  '5',
  '6',
  '7',
  '8',
  '9'
};

char moves[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

int turn = 1;

i = -1;

v = 0;

char choice = 0;

int stacknumber = 0;

int casenumber = 1;

int playchoice = 0;


int main(void) {
    struct stack s;
    init_stack( & s);

    struct stack2 rs;
    init_stack2( & rs);

    int * k = NULL;
    int * m = NULL;
    char c;

    system("cls");
    board();
	

int valid = 0;

while(valid == 0)
{
	printf("\n\n   Would you like to play against the AI or another player? \n 	 Type (1) to play against the computer or \n              (2) to play against another player: ");
	scanf("%i", & playchoice);
	
	if (playchoice == 1)
	{
		casenumber = 2;
		valid = 1;
	}
	
	if (playchoice == 2)
	{
		casenumber = 1;
		valid = 1;
	}
	
	if (playchoice != 1 && playchoice != 2)
	{
		valid = 0;
	}
}
		
		
    switch (casenumber) {
    case 1:

      LOOP: while (i == -1) {
        if (turn % 2 == 1) {
			
		  system("cls");
          board();
          printf("\n\n          Player ONE, enter a number: ");
          scanf("%c", & choice);

          v = validno();
		  
          while (v == 1) {
            printf("   Please enter another number. This number is not valid.\n");
            printf("Number must be 1-9, or when 44 or 66 are entered, there must be moves\n");
            printf("                    to undo or redo.");

            printf("\n\n          Player ONE, enter a number: ");
            scanf("%c", & choice);
			
			v = validno();
          }
		  

          while ((square[choice - 1] == 'X') || (square[choice - 1] == 'O')) {
            printf("   Please enter another number. This position has already been taken");

            printf("\n\n          Player ONE, enter a number: ");
            scanf("%c", & choice);

          }

          if (choice == 44 && turn > 1) {
            k = pop( & s);

            c = * k + '0';

            square[ * k - 1] = c;
            turn--;

            system("cls");
            board();
            //printf("%i", * k);

            push2( & rs, * k);

            stacknumber++;

            continue;
          }

          if (choice == 66 && stacknumber != 0) {
            printf("here");
            m = pop2( & rs);

            square[ * m - 1] = 'X';
            turn++;

            system("cls");
            board();
            //printf("%i", * k);

            push( & s, * m);

            stacknumber--;

            continue;
          }

          if (choice == 66 && stacknumber == 0) {
            printf("No moves to redo. Please enter a valid number.");
            goto LOOP;
          }

          if (choice != 44 || choice != 66) {
            push( & s, choice);
            square[choice - 1] = 'X';

            system("cls");
            board();
          }
        }

        if (turn % 2 == 0) {
          printf("\n\n          Player TWO, enter a number: ");
          scanf("%c", & choice);

          v = validno();
          while (v == 1) {
            printf("   Please enter another number. This number is not valid.\n");
            printf("Number must be 1-9, or when 44 or 66 are entered, there must be moves\n");
            printf("                    to undo or redo.");

            printf("\n\n          Player TWO, enter a number: ");
            scanf("%c", & choice);

            v = validno();
          }

          while ((square[choice - 1] == 'X') || (square[choice - 1] == 'O')) {
            printf("   Please enter another number. This position has already been taken");

            printf("\n\n         Player TWO, enter a number: ");
            scanf("%c", & choice);

          }

          if (choice == 44) {
            k = pop( & s);

            c = * k + '0';

            square[ * k - 1] = c;
            turn--;

            system("cls");
            board();
            //printf("%i", * k);
            push2( & rs, * k);

            stacknumber++;

            continue;
          }

          if (choice == 66 && stacknumber != 0) {
            printf("here");
            m = pop2( & rs);

            square[ * m - 1] = 'O';
            turn++;

            system("cls");
            board();
            //printf("%i", * k);

            push( & s, * m);

            stacknumber--;

            continue;
          }

          if (choice == 66 && stacknumber == 0) {
            printf("No moves to redo. Please enter a valid number.");
            goto LOOP;
          }

          if (choice != 44 || choice != 66) {
            push( & s, choice);
            square[choice - 1] = 'O';

            system("cls");
            board();
          }
        }
        turn++;
        i = checkwin();
		
      }
	  
	  if (i == 1) {

        if (turn % 2 == 0) {
          system("cls");
          board();
          printf("\n        WINNER WINNER CHICKEN DINNER! PLAYER ONE WINS.\n");
        } else {
          system("cls");
          board();
          printf("\n        WINNER WINNER CHICKEN DINNER! PLAYER TWO WINS.\n");
        }
      }

      if (i == 0) {

        system("cls");
        board();

        printf("\n         NO WINNER THIS TIME!\n");

      }

    case 2:
      LOOP2:while(i == -1)
	{
		if(turn % 2 == 1)
		{
			system("cls");
            board();
			printf("\n\n          Player ONE, enter a number: ");
			scanf("%c", &choice);
			
			v = validno();
			while(v == 1)
			{
				printf("   Please enter another number. This number is not valid.\n");
				printf("Number must be 1-9, or when 44 or 66 are entered, there must be moves\n");
				printf("                    to undo or redo.");
				
				printf("\n\n          Player ONE, enter a number: ");
				scanf("%c", &choice);
				
				v = validno();
			}
			
			while((square[choice-1] == 'X') || (square[choice-1] == 'O'))
			{
				printf("   Please enter another number. This position has already been taken");
				
				printf("\n\n          Player ONE, enter a number: ");
				scanf("%c", &choice);

			}
			
			if(choice == 44 && turn >1)
			{
				k = pop(&s);
				
				c = *k + '0';

				square[*k-1] = c;
				turn --;
				
				system("cls");
				board();
				//printf("%i", *k);
				
				push2(&rs, *k);
				
				stacknumber++;
				
				continue;
			}
			
			if(choice == 66 && stacknumber != 0)
			{				
				printf("here");
				m = pop2(&rs);

				square[*m-1] = 'X';
				turn ++;
				
				system("cls");
				board();
				//printf("%i", *k);
				
				push(&s, *m);
				
				stacknumber--;
				
				continue;
			}
			
			if(choice == 66 && stacknumber == 0)
			{
				printf("No moves to redo. Please enter a valid number.");
				goto LOOP2;
			}

			
			if(choice != 44 || choice != 66)
			{
				push(&s, choice);
				square[choice-1] = 'X';
			
				system("cls");
				board();
			}
		}
		
		if(turn % 2 == 0)
		{		
			int r = rand() % 9;
			printf("%i", r);
			
			
			while(moves[r] != square[r])
			{
				printf("R is equal to\n");
				printf("%i\n", r);
				printf("moves is\n");
				printf("%c\n", moves[r]);
				printf("square is\n");
				printf("%c", square[r]);
				r = rand() % 9;
					
			}

				choice = r;
			
				push(&s, choice);
				square[choice] = 'O';
			
				system("cls");
				board();
				
				printf("%i", r);
				printf("%c", moves[r]);
				printf("%c", square[r]);


		}
		
		turn ++;
		i = checkwin();
	}
	
	if(i == 1)
	{
		
		if(turn % 2 == 0)
		{
			system("cls");
			board();
			printf("\n        WINNER WINNER CHICKEN DINNER! PLAYER ONE WINS.\n");
		}
		else
		{
			system("cls");
			board();
			printf("\n        WINNER WINNER CHICKEN DINNER! PLAYER TWO WINS.\n");
		}
	}
	
	if(i == 0)
	{
		
		system("cls");
		board();
		
		printf("\n         NO WINNER THIS TIME!\n");
		
	}

      return 0;
    }
}

    void board() {
      printf("  +--------------------------------------------------------+\n");
      printf("  | (1-9) Number Selection, (44) Undo Move, (66) Redo Move |\n");
      printf("  +--------------------------------------------------------+");
      printf("\n\n\n                  NOUGHTS AND CROSSES");
      printf("\n            PLAYER ONE (X) v (O) PLAYER TWO\n\n");

      printf("                     +---+---+---+\n");

      printf("                     | %c | %c | %c | \n", square[0], square[1], square[2]);

      printf("                     +---+---+---+\n");

      printf("                     | %c | %c | %c | \n", square[3], square[4], square[5]);

      printf("                     +---+---+---+\n");

      printf("                     | %c | %c | %c | \n", square[6], square[7], square[8]);

      printf("                     +---+---+---+\n");

    }

    int checkwin() {
      if (square[0] == square[1] && square[1] == square[2])
        return 1;

      else if (square[3] == square[4] && square[4] == square[5])
        return 1;

      else if (square[6] == square[7] && square[7] == square[8])
        return 1;

      else if (square[0] == square[3] && square[3] == square[6])
        return 1;

      else if (square[1] == square[4] && square[4] == square[7])
        return 1;

      else if (square[2] == square[5] && square[5] == square[8])
        return 1;

      else if (square[0] == square[4] && square[4] == square[8])
        return 1;

      else if (square[2] == square[4] && square[4] == square[6])
        return 1;

      else if (square[0] != '1' && square[1] != '2' && square[2] != '3' &&
        square[3] != '4' && square[4] != '5' && square[5] != '6' && square[6] !=
        '7' && square[7] != '8' && square[8] != '9')
        return 0;
      else
        return -1;
    }

int validno()
{
	//if (isalpha(choice))
	//{
	//	return 1;
	//}
	//else
	//{
		if (choice < 1 || choice > 9)
		{
			if (choice == 44 && turn == 1)
			{
				return 1;
			}
			
			if (choice == 44 && turn > 1)
			{
				return 0;
			}
			
			if (choice == 66)
			{
				return 0;
			}
			
			return 1;
		}
		else
		{
			return 0;
		}
	//}
}