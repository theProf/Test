#include <stdio.h>
#include <math.h>

#define NELEMS(x) (sizeof(x) / sizeof((x)[0]))

typedef enum Menu {
  CALCULATE = 1,
  HELP = 2,
  EXIT = 3
} Menu;

int bandColor[4];
float tolerance = 0.10;

int calculate(void);
int metricScale(void);
int help(void);

int main()
{
    int userInput;

    while(1) {
      printf("Please choose an option.\n");
      printf("\t1. calculate the resistance value\n");
      printf("\t2. Help\n");
      printf("\t3. Exit\n");
      scanf("%d", &userInput);

      switch(userInput)
      {
          case CALCULATE:
              calculate();
              metricScale();
              break;
          case HELP:
              help();
              break;
          case EXIT:
              printf("Have a Nice Day!\n");
              return 0;
              break;
          default:
              printf("Please Enter a Valid Number.\n");
              break;
      }
    }
    return 0;
}

int promptBand(int index) {
  int min = 0;
  int max = 9;
  if(index > 1)
    max = 11;
  if(index > 2)
    min = 10;

  while(1) {
    printf("Please enter the color for band %d:\n", index+1);
    scanf("%d", &bandColor[index]);
    if(bandColor[index] >= min || bandColor[index] <= max)
      return 0;
    printf("Please enter a valid number [%d-%d]\n\n", min, max);
  }
}

int calculate()
{
    long resistance =0;
    int fuck;

    printf("These are the color choices for the bands\n");
    printf("\t0. black\n");
    printf("\t1. brown\n");
    printf("\t2. red\n");
    printf("\t3. orange\n");
    printf("\t4. yellow\n");
    printf("\t5. green\n");
    printf("\t6. blue\n");
    printf("\t7. violet\n");
    printf("\t8. grey\n");
    printf("\t9. white\n");
    printf("\t10. gold\n");
    printf("\t11. silver\n");

    for(int i = 0; i < NELEMS(bandColor); ++i) {
      promptBand(i);
    }

    printf("\nThe Value of the resistor is.\n");
    tolerance = bandColor[3] == 10 ? 0.05 : 0.10;
    return 0;
}

char *getScale(void) {
  switch(bandColor[2]) {
    case 2:
    case 3:
    case 4:
      return " K-ohms";
    case 5:
    case 6:
    case 7:
      return " M-ohms";
    case 8:
    case 9:
      return " G-ohms";
    default:
      return " ohms";
  }
}

int metricScale(void)
{
    float power = bandColor[2] == 10 ? 0 :
                  bandColor[2] == 11 ? -1 : (bandColor[2]+1) % 3;
    float value = ((float)bandColor[0] + (float)bandColor[1]/10.0) * pow(10, power);
    tolerance = value * tolerance;

    printf("%.2f ~ %.2f %s\n", value, tolerance, getScale());
    return 0;
}

int help()
{
    printf("you will be prompted to enter the color of each band 1 - 4.\n");
    printf("The program will then give you the resistance in ohms of the resistor.\n\n");

    return 0;
}


