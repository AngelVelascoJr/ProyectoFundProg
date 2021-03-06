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
		printf("Dame un nombre de usuario: ");
		fflush(stdin);
		gets(VarUsName);
		printf("Dame una contrasena: ");
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
	system("pause");
	fclose(DataFile);
	system("cls");
}

void Play()
{		
	if(UserIndex != -1)
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
	                               {"Natalie Rushman","Natalia Romanof","Nicole Rohan", "Naya rabe"},//1-10
	                               {"Un trozo de tarta","Una pinta de cerveza","Una pila de panqueques", "Una taza de cafe"},//4-11
	                               {"El Cotton Club","El Stork Club","El marruecos", "El copacabana"},//2-12
	                               {"Budapest","Praga","Estanbul", "Sokovia"},//1-13
	                               {"Nebulosa","Fauces de ebano","Obsidiana de sacrificio", "Gamora"},//4-14
	                               {"Harry","Enrique","Harley", "Holden"},//3-15
	                               {"En vomir","En una boveda em Asgard","Dentro de la espada de Sif", "Al coleccionista"},//4-16
	                               {"Quien diablos es Bucky","Te conozco","El se fue", "Que dijiste"},//1-17
	                               {"Una tarjeta de seguridad, un tenedor y un monitor de tobillo.","Una banda de seguridad, una bateria y una pierna protesica.","Un par de binoculares, un detonador y una protesis de pierna.", "Un cuchillo, cables y la cinta de mezcla de Peter."},//2-18
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
	      int i,j,k,pregun,pexiste,rexiste,bien,respondio,puntaje = 0;
	      int pregunta[10];
	      int respuesta[4];
	      srand(time(NULL));//para que los numeros sean al azar siempre
	      for(i=0;i<10;i++) //para 10 preguntas
	      {
	           do{
	               pexiste=0;
	               pregunta[i]=rand()%25;//selecciona lazar una pregunta
	               {
	                       for(j=i;j>(-1);j--)							
	                       {
	                             if(pregunta[i]==pregunta[j-1])			
	                             {										
	                                 pexiste=1;							
	                             }
	                       }
	               }
	           }while(pexiste==1);
	          printf("\n%s\n",preguntas[pregunta[i]]/*,pregunta[i]*/);//se imprime el enunciado de la pregunta
	 
	          for(k=0;k<4;k++)//se imprimen sus 4 posibles respuestas alazar
	          {
	                do{
	                   rexiste=0;
	                   respuesta[k]=(rand()%4);//selecciona lazar una posible respuesta
	                   if(k!=0)
	                   {
	                           for(j=k;j>(0);j--)
	                           {
	                                 if(respuesta[k]==respuesta[j-1])//cuando ya se uso ya no se usa
	                                 {
	                                     rexiste=1;
	                                 }
	                                 else
									 {
									 }	
	                           }
	                   }
	               }while(rexiste==1);
	               printf("%d.- %s\n",k+1,respuestas[pregunta[i]][respuesta[k]]);//impprime la posibles respuesta "\t" en vez de  "\n"
	          }
	          printf("Respuesta: ");
	               scanf("%d",&respondio);
	               if(respuesta[respondio-1]==buenas[pregunta[i]])
	               {
	                    printf("Correcto ");
	                    puntaje++;
	               }
	               else
	               {
	                   printf("Incorrecto ");
	               }
	      }
	      Users[UserIndex].JuegosJugados++;
	      printf("\nTu puntaje es %d\n", puntaje);
	      if (puntaje<=5) 
	      { printf("De verdad eres fan de marvel?\n");
	      Users[UserIndex].CalifPorJuego[0]++;
		  } else if (puntaje==6)
		  {printf("Seguro eres fan de marvel por moda\n");
		  Users[UserIndex].CalifPorJuego[1]++;
		  } else if (puntaje==7)
		  {printf("Bueno al menos sabes algo\n");
		  Users[UserIndex].CalifPorJuego[2]++;
		  } else if (puntaje==8)
		  {printf("Perfecto, ni tan geek ,ni tan poser\n");
		  Users[UserIndex].CalifPorJuego[3]++;
		  } else if (puntaje==9)
		  {printf("Eres muy bueno\n");
		  Users[UserIndex].CalifPorJuego[4]++;
		  }
		  else{printf("Estas bien?\n");
		  Users[UserIndex].CalifPorJuego[5]++;
		  }
	}
	else
	printf("para jugar, por favor inicie sesion\n");
	system("pause");//pausa
	system("cls");
}

void Stadistics()
{
	if(UserIndex != -1)
	{
		int columna, columna2, columna3, columna4, q, k;
		int x = 6, y, z[100], mayor=0, menor=0;
		for (y=1; y<=x; y++){
			z[y] = Users[UserIndex].CalifPorJuego[y-1];
			if (mayor < z[y]){
				mayor = z[y];
			}
			if (menor > z[y]){
				menor = z[y];	
			}
		}
		columna = mayor;
		columna2 = mayor;
		columna3 = mayor;
		columna4 = mayor;
		printf("aqui estan tus estadisticas, las filas representan la cantidad de veces que has sacado esa puntuacion\nlas columnas representan las puntuaciones\n");
		printf("has jugado %i veces\n\n", Users[UserIndex].JuegosJugados);
		for (q=1; q <= columna; q++){
			printf ("%i\t",columna2);
			columna2=columna2-1;
			for (k=1; k<=x; k++){
				if (z[k]>=columna3){
					printf ("*  ");
				}
				else{
					printf ("   ");
				}
			}
			columna3 = columna3 -1;
			printf  ("\n");
		}
		printf  ("\t");
		for (columna4=1; columna4<=x;columna4++){
			if(columna4==1){
				printf(">%i ", columna4+4);
			}
			else{
				printf("%i  ", columna4+4);
			}
		}
		printf ("\n");
		printf ("\n");
	}
	else
	printf("para ver sus estadisticas, por favor inicie sesion\n");
	system("pause");//pausa
	system("cls");
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
		char Var[80], JJ[3], JG[3], m5[3], v6[3], v7[3], v8[3], v9[3], v10[3];
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
		sscanf(Var,"%s %s %s %s %s %s %s %s %s", &Users[i].Username, &Users[i].Password, &JJ, &m5, &v6, &v7, &v8, &v9, &v10/*&JJ, &JG*/);
		Users[i].JuegosJugados = strtol(JJ,NULL,10);
		Users[i].CalifPorJuego[0] = strtol(m5,NULL,10);
		Users[i].CalifPorJuego[1] = strtol(v6,NULL,10);
		Users[i].CalifPorJuego[2] = strtol(v7,NULL,10);
		Users[i].CalifPorJuego[3] = strtol(v8,NULL,10);
		Users[i].CalifPorJuego[4] = strtol(v9,NULL,10);
		Users[i].CalifPorJuego[5] = strtol(v10,NULL,10);
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
			fprintf(DataFile, "%s %s %i %i %i %i %i %i %i", &Users[i].Username, &Users[i].Password, Users[i].JuegosJugados, Users[i].CalifPorJuego[0], Users[i].CalifPorJuego[1], Users[i].CalifPorJuego[2], Users[i].CalifPorJuego[3], Users[i].CalifPorJuego[4], Users[i].CalifPorJuego[5]);
		else
			fprintf(DataFile, "%s %s %i %i %i %i %i %i %i\n", &Users[i].Username, &Users[i].Password, Users[i].JuegosJugados, Users[i].CalifPorJuego[0], Users[i].CalifPorJuego[1], Users[i].CalifPorJuego[2], Users[i].CalifPorJuego[3], Users[i].CalifPorJuego[4], Users[i].CalifPorJuego[5]);
		i++;
	}
	fclose(DataFile);
}
