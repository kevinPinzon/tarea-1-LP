#include <iostream>
#include <cstring>
#include <cstdlib>
#include <time.h>
#include <fstream>
#define length(x)
#include <stdio.h>
#include <string.h>

using namespace std;

int main(int argc,char**argv){

	cout<<endl<<"	BIENVENIDO AL AHORCADO"<<endl;

	char palabra[10];
	char letra;
	char jugador[10];
	char tipoIntento;
	char completa[10];
	char desconocida[10];
	char* diccionario[10];
	int correcto=0;
	int chances=15,fallas=15;
	FILE *lectura;
	char continuar;
	int contadorL,contadorP;
	char letras[15];
	char* completas[3];

	do{

		contadorL=0,contadorP=0;


		srand(time(0));
		int dic=rand()%2;

		switch(dic){
			case 0:{
				lectura = fopen ( "diccionario1.txt", "r" );
				cout<<"PISTA: paises latinoamericanos"<<endl;
				break;
			}
			case 1:{
				lectura = fopen ( "diccionario2.txt", "r" );
				cout<<"PISTA: animales"<<endl;
				break;
			}
			case 2:{
				lectura = fopen ( "diccionario3.txt", "r" );
				cout<<"PISTA: mejores equipos del mundo"<<endl;
				break;
			}
		}

		for(int i=0; i<10; i++){
			fgets(desconocida,10,lectura);
			diccionario[i]= new char [strlen(desconocida)+1];
			strcpy(diccionario[i],desconocida);
		}
		char** tablero=new char*[16];
		for(int i=0; i<17; i++)
			tablero[i]=new char[27];

		for(int fila=0; fila<17; fila++){
			for(int columna=0; columna<27; columna++)
				tablero[fila][columna]=' ';
		}

		srand(time(0));
		int a=rand()%10;
		strcpy(desconocida,diccionario[a]);

		for(int i=0; i<sizeof(desconocida); i++){
			if (isalpha(desconocida[i]))
				desconocida[i]=desconocida[i];
			else{
				desconocida[i]='\0';
				break;
			}
		}

		int x=0;
		for(int i=0; i<sizeof(desconocida); i++){
			if (isalpha(desconocida[i]))
				palabra[i]='_';
			else{
				palabra[i]='\0';
				break;
			}
		}

		do{
//			cout<<endl<<"ahora desconocida es: "<<desconocida<<endl;

			cout<<"		";
			for(int i=0; i<sizeof(palabra); i++){//imprime actualizacion de array palabra.
				if(palabra[i]=='\0')
					break;
				cout<<palabra[i]<<" ";
			}
			cout<<endl;
			cout<<"tiene "<<chances<<" oportunidades para adivinar "<<endl;

			cout<<"desea probrar con:"<<endl<<"1.Una palabra"<<endl<<"2.Un letra"<<endl<<"9.Rendirse"<<endl;
			cin>>tipoIntento;
			switch(tipoIntento){

				case '1':{//PALABRA-----------------------------------------------------------
   					cout<<"palabra: ";
					cin>>completa;

					if(strcmp(completa,desconocida)==0){
						cout<<"	**********HAS GANADO**********"<<endl;
						chances=-1;
						break;
					}
						else{
							fallas=fallas-5;
							completas[contadorP]=new char[strlen(completa)];
							strcpy(completas[contadorP],completa);
							contadorP++;
					}
					chances=chances-5;
					break;
				}
				case '2':{//LETRA-------------------------------------------------------------
					cout<<"letra: ";
					cin>>letra;
					correcto=0;

					for(int i=0; i<	sizeof(desconocida); i++){//compara letra con array desconocida.
						if(desconocida[i]==letra){
							palabra[i]=letra;
							correcto=1;
						}
					}
					if(correcto==0){
						fallas=fallas-1;
						letras[contadorL]=letra;
						contadorL++;
					}
					chances--;

					break;
				}
				case '9':{//RENDIRCE-----------------------------------------------------------
					cout<<"	juego terminado"<<endl;


					cout<<"la palabra era(sin espacios): ";
					for(int i=0; i<sizeof(desconocida); i++)//imprime la palabra desconocida.
						cout<<desconocida[i]<<" ";
					cout<<endl<<endl;
					chances=0;
					fallas=0;
					break;
				}
				default:{
					cout<<"opcion incorrecta"<<endl;

					break;
				}

			}//fin switch-------------------------------------------------------------------------------------

			if(fallas<15){
				tablero[16][0]='*';
				tablero[16][1]='*';
				tablero[16][2]='*';
				tablero[16][3]='*';
				tablero[16][4]='*';
				tablero[16][5]='*';
				tablero[16][6]='*';
				tablero[16][7]='*';
				tablero[16][8]='*';
				tablero[16][9]='*';
				tablero[16][10]='*';
				tablero[16][11]='*';
				tablero[16][12]='*';
				tablero[16][13]='*';
				tablero[16][14]='*';
				tablero[16][15]='*';
				tablero[16][16]='*';
				tablero[16][17]='*';
				tablero[16][18]='*';
				tablero[16][19]='*';
				tablero[16][20]='*';
				tablero[16][21]='*';
				tablero[16][22]='*';
				tablero[16][23]='*';
				tablero[16][24]='*';
				tablero[16][25]='*';
				tablero[16][26]='*';
			}

			if(fallas<14){
				tablero[15][0]='*';
				tablero[15][1]='*';
				tablero[15][2]='*';
				tablero[15][3]='*';
				tablero[15][4]='*';
				tablero[15][5]='*';
				tablero[15][6]='*';
				tablero[15][7]='*';
				tablero[15][8]='*';
				tablero[15][9]='*';
				tablero[15][10]='*';
				tablero[15][11]='*';
				tablero[15][12]='*';
				tablero[15][13]='*';
				tablero[15][14]='*';
				tablero[15][15]='*';
				tablero[15][16]='*';
				tablero[15][17]='*';
				tablero[15][18]='*';
				tablero[15][19]='*';
				tablero[15][20]='*';
				tablero[15][21]='*';
				tablero[15][22]='*';
				tablero[15][23]='*';
				tablero[15][24]='*';
				tablero[15][25]='*';
				tablero[15][26]='*';
			}
			if(fallas<13){

				tablero[6][19]='|';
				tablero[7][19]='|';
				tablero[8][19]='|';
				tablero[9][19]='|';
				tablero[10][19]='|';
				tablero[11][19]='|';
				tablero[12][19]='|';
				tablero[13][19]='|';
				tablero[14][19]='|';
				tablero[6][17]='|';
				tablero[7][17]='|';
				tablero[8][17]='|';
				tablero[9][17]='|';
				tablero[10][17]='|';
				tablero[11][17]='|';
				tablero[12][17]='|';
				tablero[13][17]='|';
				tablero[14][17]='|';
			}
			if(fallas<12){
				tablero[5][22]=')';
				tablero[5][14]='(';
				tablero[4][13]='(';
				tablero[4][24]=')';
				tablero[1][12]='(';
				tablero[2][12]='(';
				tablero[3][12]='(';
				tablero[1][25]=')';
				tablero[2][25]=')';
				tablero[3][25]=')';
				tablero[0][13]='(';
				tablero[0][24]=')';
			}
			if(fallas<11){
				tablero[13][3]='n';
				tablero[12][3]='/';
				tablero[12][5]='.';
				tablero[12][7]='\\';
				tablero[13][8]='n';

			}
			if(fallas<10){
				tablero[11][5]='.';
				tablero[11][4]='|';
				tablero[11][6]='|';

			}
			if(fallas<9){
				tablero[11][9]='\\';
				tablero[10][8]='\\';

			}
			if(fallas<9){
				tablero[11][1]='/';
				tablero[10][2]='/';
			}
			if(fallas<8){
				tablero[9][5]='0';
			}
			if(fallas<8){
				tablero[8][7]=')';
				tablero[8][3]='(';

			}
			if(fallas<7){
				tablero[8][4]='^';
				tablero[8][5]='.';
				tablero[8][6]='^';

			}
			if(fallas<6)
				tablero[4][13]='/';

			if(fallas<5)
				tablero[5][12]='/';

			if(fallas<4)
				tablero[6][11]='/';

			if(fallas<3)
				tablero[7][10]='/';

			if(fallas<2)
				tablero[8][9]='/';

			if(fallas<1||chances==0){
	//			tablero[9][8]='/';
				tablero[8][4]='x';
				tablero[8][5]='.';
				tablero[8][6]='x';
				tablero[9][5]='#';
			}

			for(int fila=0; fila<17; fila++){
				cout<<" ";
				for(int columna=0; columna<27; columna++){
					cout<<tablero[fila][columna]<<"";
				}
				cout<<endl;
			}

			if(strcmp(palabra,desconocida)==0){
				cout<<"	**********HAS GANADO**********"<<endl;
				chances=-1;
				break;
			}

		}while(chances>0);

	cout<<"letras errones: "<<endl;
	for(int i=0; i<contadorL; i++){
		if (isalpha(letras[i]))
		cout<<letras[i]<<"	";
	}
	cout<<endl;

	cout<<"palabras errones: "<<endl;
	for(int i=0; i<contadorP; i++){
		if(!(completas[i]=='\0'))
		cout<<completas[i]<<"	";
	}

	cout<<endl<<"Desea volver a jugar(s/n): ";
	cin>>continuar;
	chances=15;
	fallas=15;

	}while(continuar=='s');

	for(int i=0; i<3; i++)
		delete[] diccionario[i];

	for(int i=0; i<10; i++)
		delete[] diccionario[i];




return 0;}


