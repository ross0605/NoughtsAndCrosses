#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void display(void);
void insert(int, int);
int hashCode(int);
void board();
int checkwin();
int i = -1;

char square[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char X = 'X';
char O = 'O';
int turn = 0;

#define SIZE 9

struct DataItem
{
	int val;
	int ply;
};

struct DataItem* hashArray[SIZE];
struct DataItem* tempItem;
struct DataItem* item;

int main(void)
{

	int choice = 0;
	int player = 1;	
	
	tempItem = (struct DataItem*) malloc(sizeof(struct DataItem));
	tempItem -> val = -1;
	tempItem -> ply = -1;
	
	insert(1, 1); // Player One
	insert(2, 2);               // Player Two
	insert(1, 3); // Player One
	insert(2, 4);               // Player Two
	insert(1, 5); // Player One
	insert(2, 6);               // Player Two
	insert(1, 7); // Player One
	insert(2, 8);               // Player Two
	insert(1, 9); // Player One


	system("cls");
	display();
	board();
	
	while(i == -1)
	{
		if(hashArray[turn] -> ply == 1)
		{
			printf("\n\n    Player ONE, enter a number: ");
			scanf("%i", &choice);
		
			while((square[choice-1] == X) || (square[choice-1] == O))
			{
				printf("Please enter another number. This position has already been taken");
				
				printf("\n\n    Player ONE, enter a number: ");
				scanf("%i", &choice);

			}
			

			hashArray[turn] -> val = choice;
			square[choice-1] = X;
			
			system("cls");
			display();
			board();
			
			player ++;

			
		};
		
		if(hashArray[turn] -> ply == 2)
		{
			printf("\n\n    Player TWO, enter a number: ");
			scanf("%i", &choice);
		
			while((square[choice-1] == X) || (square[choice-1] == O))
			{
				printf("Please enter another number. This position has already been taken");
				
				printf("\n\n    Player TWO, enter a number: ");
				scanf("%i", &choice);

			}
			
			hashArray[turn] -> val = choice;
			square[choice-1] = O;
			
			system("cls");
			display();
			board();
			
			player--;

		};
		
		turn++;
		
		i = checkwin();
	}
	
	
	if(i == 1)
	{
		
		if(player-1 == 1)
		{
			system("cls");
			display();
			board();
			printf("\nWINNER WINNER CHICKEN DINNER! PLAYER ONE WINS.\n");
		}
		else
		{
			system("cls");
			display();
			board();
			printf("\nWINNER WINNER CHICKEN DINNER! PLAYER TWO WINS.\n");
		}
	}
	
	if(i == 0)
	{
		
		system("cls");
		display();
		board();
		
		printf("\n         NO WINNER THIS TIME!\n");
		
	}
	
		
	return(0);

}


void display(void)
{
	int i;
	for(i=0; i<SIZE; i++)
	{
		if(hashArray[i] != NULL)
			printf(" (%d,%d)", hashArray[i] -> ply, hashArray[i] -> val);
		else
			printf(" ~,~ ");
	}
	printf("\n");
}


void insert(int ply, int val)
{
	struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
	item -> val = val;
	item -> ply = ply;
	
	int hashIndex = hashCode(ply-1);
	while(hashArray[hashIndex] != NULL && hashArray[hashIndex] -> ply != -1)
	{
		++hashIndex;
		hashIndex %= SIZE;

	}
	hashArray[hashIndex] = item;
}


int hashCode(int ply)
{
	return ply % SIZE;
}

void board()
{
			
	
	printf("\n\n         NOUGHTS AND CROSSES");
	printf("\n   PLAYER ONE (X) v (O) PLAYER TWO\n\n");
	
	printf("            +---+---+---+\n");
	
	printf("            | %c | %c | %c |\n", square[0], square[1], square[2]);
	
	printf("            +---+---+---+\n");
	
	printf("            | %c | %c | %c |\n", square[3], square[4], square[5]);
	
	printf("            +---+---+---+\n");
	
	printf("            | %c | %c | %c |\n", square[6], square[7], square[8]);
	
	printf("            +---+---+---+\n");
	
}	


int checkwin()
{
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
        
    //else if (square[0] != '1' && square[1] != '2' && square[2] != '3' &&
        //square[3] != '4' && square[4] != '5' && square[5] != '6' && square[6] 
        //!= '7' && square[7] != '8' && square[8] != '9')
	else if (turn == 9) 
        return 0;
    else
        return  - 1;
}

		