#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

void tamano(int tablero[][15], int gg_easy);
void NukeDrop(int minas[][15], int a)
{
     int i, horizontal, vertical;

     for(i = 1; i <= a; i++)
     {
           horizontal = 0 + rand() % 14;
           vertical = 0 + rand() % 14;

           minas[horizontal][vertical] = 3;
     }
}
void comentarios(int buscar)
{
     switch(buscar)
     {
         case 1: printf("JAJAJAJAJA ahora hazlo sin suerte\n");
                 break;

         case 2: printf("No pero hay que ver vaina\n");
                 break;

         case 3: printf("Chepa perez\n");
                 break;

         case 4: printf("Dichoso\n");
                 break;
     }
}
void mas_comentarios(int numero)
{
     switch(numero)
     {
         case 1: printf("Quien lo diria...\n");
                 break;

         case 2: printf("Ootra vez? \n");
                 break;

         case 3: printf("Si lo hace de nuevo tiene 2 empanada en pensum\n");
                 break;

         case 4: printf("OMEGALUL\n");
                 break;

     }
}


#define HORIZONTAL 15
#define VERTICAL 15

int main()
{
  int NukeSeeker[HORIZONTAL][VERTICAL] = {0}, i, j;
  int entrada, dificultad;
  int condicion_actual, cantidad = 0, suerte;
  int intentos, chistes;
  float chepas;
  char pa_fuera;

  do{
       system("cls");

       printf("Decida su suerte:\n%d.-Facil\n", 1);
       printf("%d.-Normal\n%d.-Dificil\n%d.-Dios Mio\n%d.-Mas que juego, un tormento\n", 2, 3, 4, 5);

       scanf("%d", &entrada);

       switch(entrada){

           case 1: dificultad = 10;
                   break;

           case 2: dificultad = 15;
                   break;

           case 3: dificultad = 20;
                   break;

           case 4: dificultad = 25;
                   break;

           case 5: dificultad = 30;
                   break;

           default: printf("Error profe, eso no existe.\n\n");
                    break;

       }

       srand(time(NULL));

       NukeDrop(NukeSeeker, dificultad);

       intentos = 0;

       do{
           system("cls");

           tamano(NukeSeeker, condicion_actual);

           printf("\n");
           printf("*Ingrese las coordenadas como en math101[i, j]: ");
           scanf("%d%d",&i, &j);

           if(NukeSeeker[i][j] == 3){
               condicion_actual = -1;
               intentos++;

               system("cls");
               tamano(NukeSeeker, condicion_actual);

               printf("\t\t\t\t\t  Psss, pasa tu matricula pa quemarte (Voz del profe)");

               getch();
           }
           else
           {
               NukeSeeker[i][j] = 1;
               cantidad++;
               intentos++;
           }
           if(cantidad == (225 - dificultad) )
           {
               suerte = 1;
               system("cls");
               tamano(NukeSeeker, condicion_actual);

               printf("\t\t\t\t\t  Eres la prueba viviente de que la suerte y la chepa existen\n");

               getch();
           }


       }while(condicion_actual != -1 || suerte == 1);

       system("cls");

       chepas = ((float)cantidad * 100) / 225;

       printf("\n-NukeSeeker 1.0- Estadisticas.\n\n");
       printf("Tus chepas  de juego es %.2f %.2f%\n", chepas);
       printf("*No. de intentos %d.\n\n", intentos);

       chistes = 1 + rand() % 4;

       if(condicion_actual == -1)
         mas_comentarios(chistes);
       else if(suerte == 1)
         comentarios(chistes);

       printf("\n\n");

       printf("Lo quieres volver a intentar?(s/n)?: ");

       pa_fuera = getch();
       pa_fuera = tolower(pa_fuera);

       for(i = 0; i <= HORIZONTAL - 1; i++)
         for(j = 0; j <= VERTICAL - 1; j++)
           NukeSeeker[i][j] = 0;

       cantidad = 0;


  }while(pa_fuera == 's');

  system("cls");
  getch();

  return 0;
}

void tamano(int tablero[][15], int te_fuite)
{
     int i, j;

     for(i = 0; i <= HORIZONTAL -1; i++)
       printf("%d ", i);

     printf("\n");

     for(i = 0; i <= VERTICAL - 1; i++)
       printf("--");

     printf("\n");

     for(i = 0; i <= HORIZONTAL -1; i++)
     {
           for(j = 0; j <= VERTICAL - 1; j++){

             if(tablero[i][j] == 1)
               printf("%d ", tablero[i][j]);
             else if((tablero[i][j] == 3) && (te_fuite == -1))
               printf("%c ", '*');
             else
               printf("%c ", '#');
           }

           printf("| %d", i);


     }
}
