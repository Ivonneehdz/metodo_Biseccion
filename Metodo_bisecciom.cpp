#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <windows.h>  
#define E 2.71818182845905
 void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }
 void margen (int x1, int y1, int x2, int y2);
float funcion ( float x);
int main (){
	float Xl,Xr,Xu,FXl,FXu,FXr,producto, Error = 100 ,Es, Errora , almacena [100];
	int iteracion, i=0;
	gotoxy (5,2); printf ("*-*-*-*-*-*-Programa de metodo de bisección.-*-*-*-*-*-*");
	gotoxy (6,4); printf ("Ingrese el error: ");
	scanf ("%f",&Es);
	gotoxy (6,5); printf ("Ingrese el valor de Xl: ");
	scanf  ("%f",& Xl);
	gotoxy (6,6); printf ("Ingrese el valor de Xu: ");
	scanf  ("%f",& Xu);
	gotoxy (6,7); printf ("Ingrese el número de iteraciones: ");
	scanf  ("%d",& iteracion);
	printf ("\n\n");
	almacena[i]=0;
	gotoxy (1,10);printf ("Iteraciones:");
    gotoxy (8,10);printf ("XL:");
    gotoxy (23,10);printf ("Xu:");
    gotoxy (38,10);printf ("Xr:");
	gotoxy (53,10);printf ("F(Xl):");
	gotoxy (68,10);printf ("F(Xu):");
	gotoxy (82,10);printf ("F(Xr):");
	gotoxy (92,10);printf ("FXr*FXl");
	gotoxy (98,10);printf ("Error:");
	
	do{
		//metodo biseccion
    	Xr = (Xl + Xu) / 2 ;
		FXl = funcion (Xl);
		FXu = funcion (Xu);
		FXr = funcion (Xr);
		producto = FXl * FXr;
		// falsa posicion
		//Xr = (Xu)- ((FXu)*(Xl-Xu)/(FXl-FXu));
		if (i!=0) {
			Error = (((Xr-Errora)/Xr)*100);
			if (Error < 0){
				Error = Error * (-1);
			 } 
		} 
		gotoxy (1,12+i); printf ("%d",i);
		gotoxy (8,12+i);printf ("%.3f",Xl);
		gotoxy (23,12+i); printf ("%.3f",Xu);
		gotoxy (38,12+i);printf ("%.3f",Xr);
		gotoxy (53,12+i);printf ("%.3f",FXl);
		gotoxy (68,12+i);printf ("%.3f",FXu);
		gotoxy (80,12+i);printf ("%.3f",FXr);
		gotoxy (95,12+i);printf ("%.3f",producto);
		gotoxy (110,12+i);printf ("%.3f",Error);
		producto = FXl * FXr;
			if (producto > 0 ){
				printf ("\n\nSe termina el programa: Hay raíz o múltiples raíces.");
				return 0;		
			}else if (producto < 0){
				Xu = Xr ;
				FXu = FXr;
			}else{
				Xl = Xr ;
				FXu = FXr;
			}
		Errora = Xr;
		i++; 
		almacena[i]=Error;
		
			
		
		
	} while ( (i <= iteracion+1) && Error>=Es );
	printf ("\n\nLa solución es %.f3 de %d iteraciones  con el error de %.3f.", Xr, i, almacena[i]);
		
	/*Termina cuando el producto es  igual a cero termina rl programa
	raiz= Xr
	sino if el producto es mayor cero*/
	//error con valor absoluto = valor actual - valor anterior / valor actual *100
	
	//system ("pause");
	printf ("\n\n");
	printf ("\nPulse cualquier tecla para terminar [  ]\b");
	getch ();
}
float funcion ( float x){
	//La ecuación ingresada difería.
	//Se pueden agregar para logaritmo natural log
	//Se puede agregar la exponencial a través de e
    //return    /*(9.8*x)/15*(1-pow(E,(-15*9/x)))-35*/ pow(x,10)-1;
    return 3924/x*(1-E(-x/20))-15;
    //	return (3.141592654*pow(x,2)) * ((9-x)/3);
}
void margen (int x1, int y1, int x2, int y2){
  int x,y;
  for (x=x1;x<=x2;x++){
    gotoxy (x,y1); printf ("%c",176);
    gotoxy (x,y2); printf ("%c",176);
  }
  for (y=y1;y<=y2;y++){
    gotoxy (x1,y); printf ("%c",186);
    gotoxy (x2,y); printf ("%c",186);
  }
}