#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(){

	int frequency[6] = {0};
	int frequency1 = 0;
	int frequency2 = 0;
	int frequency3 = 0;
	int frequency4 = 0;
	int frequency5 = 0;
	int frequency6 = 0;


	// roll counter
	srand(time(NULL));
	int roll; 
	// roll 
	int face;

	
	for (roll = 1; roll <= 8000; roll++)
	{
		face = (1+(rand()%6));
		
		int i;
		for (int i = 0; i < sizeof(frequency); ++i)		{
			if (face == )
		}
		switch (face){


			case 1:
				++frequency1;
				break;
			case 2:
				++frequency2;
				break;
			case 3:
				++frequency3;
				break;
			case 4:
				++frequency4;
				break;
			case 5:
				++frequency5;
				break;
			case 6:
				++frequency6;
				break;

		}


		printf("%10d", face);

		if (roll%5==0)
		{
			printf("\n");

		}
	}
	int i;
	for ( i = 0; i < 6; ++i)
	{
		/* code */
	}
	printf("%10s%15s%14s\n", "Face", "Frequency","Probablity");
	printf("      1%13d%18f\n", frequency1, (float)((float)frequency1/roll*100));
	printf("      2%13d%18f\n", frequency2, (float)((float)frequency2/roll*100));
	printf("      3%13d%18f\n", frequency3, (float)((float)frequency3/roll*100));
	printf("      4%13d%18f\n", frequency4, (float)((float)frequency4/roll*100));
	printf("      5%13d%18f\n", frequency5, (float)((float)frequency5/roll*100));
	printf("      6%13d%18f\n", frequency6, (float)((float)frequency6/roll*100));

	return 0;

}