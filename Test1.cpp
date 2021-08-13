#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

struct Jugador
{
	char *Username;
	char *Password;
	int JuegosJugados;
	int JuegosGanados;
	int CalifPorJuego[6];
};
int n = 1, Op, UserIndex = -1, ArraySize;	//User index se puede usar como variable para checar si se ha 
											//iniciado sesion, se mantendra como -1 si no, se cambiara a 0->n si si
char Nombre[20], Contra[20];
Jugador *Users;
FILE *DataFile;

void Play();
void LogIn();
void Stadistics();
void CreateProfile();
void DataFromFile();
void DataToFile();
main()
{	
	do
	{
		printf("Menu de juego, selecciona la opcion que deseas hacer\n1.-Iniciar sesion\n2.-Crear perfil\n3.-Estadisticas\n4.-Jugar\n5.-Salir\n");
		scanf("%i",&Op);
		switch(Op)
		{
			case 1: //Iniciar sesion
				LogIn();
				break;
			case 2:	//Crear perfil
				CreateProfile();
				break;
			case 3:	//Estadisticas
				Stadistics();
				break;
			case 4:	//Jugar
				Play();
				break;
			default:
			case 5:	//Salir
				if(UserIndex != -1)
				{
					DataToFile();
					free(Users);
				}
				break;
		}
	}while(Op != 5);
}

void LogIn()
{
	DataFromFile();
	char VarUsName[20], VarPassW[20];
	
	bool IsValid = false;
	do
	{
		fflush(stdin);
		printf("Dame tu usuario: ");
		fflush(stdin);
		gets(VarUsName);
		printf("Dame tu contrasena: ");
		gets(VarPassW);
		for(int i = 0; i < ArraySize; i++)
		{
			if(IsValid == false)
			{
				if(strcmp((char*)&Users[i].Username, VarUsName) == 0 && strcmp((char*)&Users[i].Password, VarPassW) == 0)
				{
					system("cls");
					printf("Bienvenido %s\n", &Users[i].Username);
					IsValid = true;
					UserIndex = i;
				}
			}
		}
		if(IsValid == false)	printf("Usuario o contrasena incorrectos\n");
	}while(IsValid == false);
}

void CreateProfile()
{
	if(UserIndex = -1)
		DataFromFile();
	DataFile = fopen("file.txt" , "a");
	char VarUsName[20], VarPassW[20];
	bool IsValid;
	do
	{
		printf("Dame tu usuario: ");
		fflush(stdin);
		gets(VarUsName);
		printf("Dame tu contrasena: ");
		gets(VarPassW);
		IsValid = true;
		for(int i = 0; i < ArraySize; i++)
		{
			if(IsValid == true)
			{
				if(strcmp((char*)&Users[i].Username, VarUsName) == 0)
				{
					printf("Ya hay un Usuario con ese nombre, elija otro por favor\n");
					IsValid = false;
				}
			}
		}
	}while(IsValid == false);
	fprintf(DataFile, "\n%s %s %i %i %i %i %i %i %i", VarUsName, VarPassW, 0, 0, 0, 0, 0, 0, 0);//nombre, contrasena, juegos jugados, cant de veces que obtuvo menosque5, 6, 7, 8, 9, 10
	printf("Se ha guardado su perfil\n");
	Sleep(3000);
	system("cls");
	fclose(DataFile);
}

void Play()
{					
	fflush(stdin);	
	char preguntas[25][500]={"En que anio se estreno la primera pelicula de Iron Man, que lanzo el Marvel Cinematic Universe?", //Pregunta 1
	                         "Como se llama el martillo de Thor?", //Pregunta 2
	                         "En The Incredible Hulk, que le dice Tony a Thaddeus Ross al final de la pelicula?", //Pregunta 3
	                         "De que esta hecho el escudo del Capitan America?", //Pregunta 4
	                         "Los Flerkens son una raza de alienigenas extremadamente peligrosos que se parece a que.", //Pregunta 5
	                         "Antes de convertirse en Vision, como se llama el mayordomo de inteligencia artificial de Iron Man?", //Pregunta 6
	                         "Cual es el verdadero nombre de la Pantera Negra?", //Pregunta 7
	                         "Cual es la raza alienigena que Loki envia para invadir la Tierra en The Avengers?", //Pregunta 8
	                         "Quien fue el ultimo titular de la Piedra espacial antes de que Thanos lo reclame por su Infinity Gauntlet?", //Pregunta 9
	                         "Que nombre falso usa Natasha cuando conoce a Tony por primera vez?", //Pregunta 10
	                         "De que quiere Thor otro cuando esta en el restaurante?", //Pregunta 11
	                         "Donde le dice Peggy a Steve que quiere encontrarse con el para bailar, antes de que el se hunda en el hielo?", //Pregunta 12
	                         "Sobre que ciudad recuerdan a menudo Hawkeye y Black Widow?", //Pregunta 13
	                         "A quien sacrifica el Thanos para adquirir la Piedra del Alma?", //Pregunta 14
	                         "Cual es el nombre del ninio que Tony se hace amigo mientras esta varado en Iron Man 3?", //Pregunta 15
	                         "Donde guardan Lady Sif y Volstagg la Piedra de la Realidad despues de que los Elfos Oscuros intentaron robarla?", //pregunta 16
	                         "Que dice el Soldado de Invierno despues de que Steve lo reconoce por primera vez?", //Pregunta 17
	                         "Cuales fueron los tres elementos que Rocket afirma que necesita para escapar de la prision?", //Pregunta 18
	                         "Que palabra pronuncia Tony que hace que Steve diga Lenguaje?", //Pregunta 19
	                         "Que animal encoge Darren Cross sin exito en Ant Man?", //Pregunta 20
	                         "Quien es asesinado por Loki en los Vengadores?", //Pregunta 21
	                         "Quien es la hermana de Black Panther?", //PRegunta 22
	                         "De que hito rescata Peter Parker a sus companeros de clase en SpiderMan: Homecoming?", //Pregunta 23
	                         "Que cancion baila Baby Groot al final del primer Guardian of the Galaxy?", //Pregunta 24
	                         "Que tipo de medico es Stephen Strange", //PRegunta 25
	                         };
    char respuestas[25][4][100]={
                               {"2005","2008","2010", "2012"},//2-1
                               {"Vanir","Mjolnir","Aesir", "Norn"},//2-2
                               {"Que quiere estudiar The Hulk","Que el sabe sobre SHIELD","Que estan formando un equipo", "Que Thaddeus le debe dinero"},//3-3
                               {"Adamantium","Vibranio","Prometeo", "Carbonadio"},//2-4
                               {"Gatos","Patos","Reptiles", "Mapaches"},//1-5
                               {"HOMERO","JARVIS","ALFREDO", "MARVIN"},//2-6
                               {"TChalla","MBaku","Njadaka", "Njobu"},//1-7
                               {"El chitauri","Los skrulls","el kree", "Los flerkens"},//1-8
                               {"Thor","Loki","El coleccionista", "Tony Stark"},//2-9
                               {"Natalie Rushman ","Natalia Romanof","Nicole Rohan", "Naya rabe"},//1-10
                               {"Un trozo de tarta","Una pinta de cerveza","Una pila de panqueques", "Una taza de cafe"},//4-11
                               {"El Cotton Club","El Stork Club","El marruecos", "El copacabana"},//2-12
                               {"Budapest","Praga","Estanbul", "Sokovia"},//1-13
                               {"Nebulosa","Fauces de ebano","Obsidiana de sacrificio", "Gamora"},//4-14
                               {"Harry","Enrique","Harley", "Holden"},//3-15
                               {"En vomir","En una boveda em Asgard","Dentro de la espada de Sif", "Al coleccionista"},//4-16
                               {"Quien diablos es Bucky","Te conozco","El se fue", "Que dijiste"},//1-17
                               {"Una tarjeta de seguridad, un tenedor y un monitor de tobillo.","Una banda de seguridad, una baterÃ­a y una pierna protesica.","Un par de binoculares, un detonador y una protesis de pierna.", "Un cuchillo, cables y la cinta de mezcla de Peter."},//2-18
                               {"Culo","Estupido","Mierda", "Idiota"},//3-19
                               {"Raton","Oveja","Pato", "Hamster"},//2-20
                               {"Maria Hill","Nick Fury","Agente Coulson", "Doctor Erik Selving"},//3-21
                               {"Shuri","Nakia","Ramonda", "Okoye"},//1-22
                               {"Monumento de Washington","Estatua de la libertad","Mount Rushmore", "Puente Golden Gate"},//1-23
                               {"Cherry Bomb  The Runaways","Ain t No Mountain High Enough  Marvin Gaye y Tammi Terrell","Te quiero de vuelta  The Jackson 5", "Enganchado a un sentimiento  Voidoid"},//3-24
                               {"Neurocirujano","Cirujano cardiotoracico","Cirujano de trauma", "Cirujano Plastico"}//1-25
                               
 
                               };
      int buenas[25]={1,1,2,1,0,1,0,0,1,0,3,1,0,3,2,3,0,1,2,1,
                      2,0,0,2,0};//#respuesta-1
      int i,j,k,pregun,pexiste,rexiste,bien,respondio,puntaje ;
      int pregunta[10];
      int respuesta[4];
      srand(time(NULL));//para que los numeros sean al azar siempre
      for(i=0;i<10;i++) //para 10 preguntas
      {
           do{
               pexiste=0;
               pregunta[i]=rand()%25;//selecciona lazar una pregunta
               //if(i!=1)
               {
                       //j=i;
                       for(j=i;j>(-1);j--)							
                       {
                       	//printf("entro");
                             if(pregunta[i]==pregunta[j-1])			
                             {										
                                 pexiste=1;							
                             }
                       }
               }
           }while(pexiste==1);
		//printf("la pregunta que se guardo es: %s\n", preguntas[pregunta[i]]);
		//printf("\tLas respuestas guardadas son: %s, %s, %s, %s\n", respuestas[pregunta[i]][0], respuestas[pregunta[i]][1], respuestas[pregunta[i]][2], respuestas[pregunta[i]][3]);

          printf("\n%s %d\n",preguntas[pregunta[i]],pregunta[i]);//se imprime el enunciado de la pregunta
 
          for(k=0;k<4;k++)//se imprimen sus 4 posibles respuestas alazar
          {
                do{
                   rexiste=0;
                   respuesta[k]=(rand()%4);//selecciona lazar una posible respuesta
            		//printf("\tvalor aleatorio de respuesta es: %i\n", respuesta[k]);
            		//printf("\tse busca dentro de respuestas[pregunta[%i]][respuesta[%i]]\n", i, k);
            		//printf("\tes decir dentro de respuestas[%i][%i]\n", pregunta[i], respuesta[k]);
            		//printf("\trespuesta referida al valor aleatorio: %s\n", respuestas[pregunta[i]][respuesta[k]]);
                   //if(i!=1)
                   {
                           //j=k;
                           for(j=k;j>(-1);j--)
                           {
                           	    //printf("\t\tvalor de i: %i, valor de j: %i, valor de k: %i\n", i, j, k);

                                 if(respuesta[k]==respuesta[j-1])//cuando ya se uso ya no se usa
                                 {
                                     rexiste=1;
                                 }
                           }
                   }
               }while(rexiste==1);
                //printf("\timprimiendo la respuesta en respuestas[pregunta[%i]][respuesta[%i]] = %s\n", i, k, respuestas[pregunta[i]][respuesta[k]]);
               printf("%d.- %s\n ",k+1,respuestas[pregunta[i]][respuesta[k]]);//impprime la posibles respuesta "\t" en vez de  "\n"
               if(k==buenas[pregunta[i]]) //calcula cual es numero de la respuesta buena
               {
               	//printf("valor de bien: %i", k);
                  bien=k;
               }
 
          }
          printf("Respuesta: ");
               scanf("%d",&respondio);
               if((respondio-1)==bien)//evalua si la respuesta fue la correcta
               {
                    printf("Correcto ");
                    puntaje++;
               }
               else
               {
                   printf("Incorrecto ");
               }
 
      }
      
      printf("Tu puntaje es %d\n", puntaje);
      if (puntaje<=5) 
      { printf("De verdad eres fan de marvel?\n");
	  } else if (puntaje==6)
	  {printf("Seguro eres fan de marvel por moda\n");
	  } else if (puntaje==7)
	  {printf("Bueno al menos sabes algo\n");
	  } else if (puntaje==8)
	  {printf("Perfecto, ni tan geek ,ni tan poser\n");
	  } else if (puntaje==9)
	  {printf("Eres muy bueno\n");
	  }
	  else{printf("Estas bien?\n");
	  }
 
            system("pause");//pausa
		system("cls");
}

void Stadistics()
{
	
}

void DataFromFile()	//carga el archivo de perfiles
{
	DataFile = fopen("file.txt" , "r");
	if(DataFile == NULL) 
	{
		perror("Error opening file");
	}
	int i = 1;
	for (char c = getc(DataFile); c != EOF; c = getc(DataFile))
	{
		if (c == '\n')
		{
			i++;
		}
	}
	Users = (Jugador*)malloc(i*sizeof(Jugador));
	ArraySize = (i);
	i = 0;
	fclose(DataFile);
	DataFile = fopen("file.txt" , "r");
	while(i < ArraySize)
	{
		char Var[40], JJ[3], JG[3];
		int j = 0;
		for (char c = getc(DataFile); c != '\n'; c = getc(DataFile))
		{
			if (c != '\n' || c != EOF)
			{
				Var[j] = c;
				j++;
			}
			if(c == EOF)	break;
		}
		sscanf(Var,"%s %s %s %s", &Users[i].Username, &Users[i].Password, &JJ, &JG);
		Users[i].JuegosJugados = strtol(JJ,NULL,10);
		Users[i].JuegosGanados = strtol(JG,NULL,10);
		i++;
	}
	fclose(DataFile);
}

void DataToFile()	//salva el struct de perfiles en el archivo
{
	DataFile = fopen("file.txt" , "w");
	int i = 0;
	while(i < ArraySize)
	{
		if(i == ArraySize - 1)
			fprintf(DataFile, "%s %s %i %i", &Users[i].Username, &Users[i].Password, Users[i].JuegosJugados, Users[i].JuegosGanados);
		else
			fprintf(DataFile, "%s %s %i %i\n", &Users[i].Username, &Users[i].Password, Users[i].JuegosJugados, Users[i].JuegosGanados);
		i++;
	}
	fclose(DataFile);
}
