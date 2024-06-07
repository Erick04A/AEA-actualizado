#include <stdio.h>
#include "lectura.h"

int leerEnteroPositivo(char* mensaje){
  int valor;
  do{
    printf("%s", mensaje);
    scanf("%d",&valor);
  }while(valor <= 0);
  return valor;
}

int leerEntero(char* mensaje){
  int num1;
  printf("%s",mensaje);
  scanf("%d",&num1);
  return num1;
}

int leerEnteroEntre(char*mensaje, int numMay, int numMen){
  int num3;
  do{
    printf("%s", mensaje);
    scanf("%d",&num3);
  }while( num3 < numMen || num3 > numMay );
  return num3;

}

float leerFlotantePositivo(char* mensaje){
  float valor;
  do{
    printf("%s", mensaje);
    scanf("%f",&valor);
  }while(valor <= 0);
  return valor;
}

float leerFlotante(char*mensaje){
  float num2;
  printf("%s",mensaje);
  scanf("%f", &num2);
  return num2;
}

float leerFlotanteEntre(char*mensaje, float numMay, float numMen){
  float num4;
  do{
    printf("%s",mensaje);
    scanf("%f",&num4);
  }while( num4 < numMen || num4 > numMay);
  return num4;

}

char leerCaracter(char* mensaje){
  char caracter;
  printf("%s",mensaje);
  scanf("%c", &caracter);
  return caracter;
}