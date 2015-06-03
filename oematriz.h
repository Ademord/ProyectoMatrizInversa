#pragma once
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

// n - 1 : si quiero de 2 x 2, pongo 3.
#define MAX 4
// struct Matriz;
using namespace std;



struct Matriz{	
	int tam;
	Matriz () { tam =0; }
	//DEFINICION DE FUNCIONES

	//ENTRADA
	void CargarMatriz(float M[MAX][MAX], float AUX_M[MAX][MAX], int n)
	{
		for ( int i = 1; i < n ; i ++ )
		{
			for ( int j = 1; j < n ; j++ )
			{
				int aux; cin>> aux;
				M[i][j]=aux;
				AUX_M[i][j]=aux;
			}
		}

	}
	//PROCESO
	void MatrizInversa()
	{
		int n = tam;
		float M[MAX][MAX],I[MAX][MAX];  bool correcto=true;
		float AUX_M[MAX][MAX];
		cout << "********************************************************"<< endl;
		cout << "Datos de la matriz" << endl;
		Identidad(I,correcto,"generar");
		CargarMatriz(M,AUX_M, n);


		puts("Matrices INICIALES");
		cout << "Matriz" << endl;
		MostrarMatriz(M);puts("");
		cout << "Matriz Identidad" << endl;
		MostrarMatriz(I);puts("");

		ProcesarMatrices(M,I);
		Identidad(M,correcto);
		if(correcto)
		{
			puts("Matrices PROCESADAS");
			cout << "Matriz original procesada a matriz IDENTIDAD" << endl;
			MostrarMatriz(M);puts("");
			cout << "Matriz identidad procesada a matriz INVERSA" << endl;
			MostrarMatriz(I);puts("");
			MultiplicarMatrices(I,AUX_M);
		}
		else printf("Esta operacion requiere una matriz NO-SINGULAR\n");



	}

	void MultiplicarMatrices(float A[MAX][MAX], float B[MAX][MAX])
	{
		float Aux[MAX][MAX];
		for ( int i = 1; i < tam; i++ )
		{
			for ( int j = 1 ; j < tam; j++ )
			{
				Aux[i][j]=0;
			}

		}

		for(int i = 1; i < tam; i++ )
		{

			for (int j = 1; j < tam ; j++ )
			{

				for (int k = 1; k < tam ; k++ )
				{
					Aux[i][j]+=A[i][k]*B[k][j];
				}
			}
		}
		cout << "Matriz Resultante de Multiplicar la M. Inversa con la  M. Inicial" << endl;
		MostrarMatriz(Aux);
	}
	void Identidad(float M[MAX][MAX],bool &correcto,string proceso="")
	{
		int i,j;
		if(proceso=="generar")
		{
			for(i=1;i< tam;i++)
			{
				for(j=1;j< tam;j++)
				{
					if(i==j)M[i][j]=1;
					else M[i][j]=0;
				}
			}
		}
		else //VERIFICAR
		{
			for(i=1;i< tam;i++)
			{
				for(j=1;j< tam;j++)
				{
					if(i==j)
					{
						if(M[i][j]!=1) correcto=false;
					}
					else if(M[i][j]!=0) correcto=false;
				}
			}
		}
	}

	void ProcesarMatrices(float M[MAX][MAX],float I[MAX][MAX])
	{
		int i=1;
		for(i=1;i< tam;i++)
		{
			//cout << "procesando... " << endl;
			//int aux; cin >> aux; 
			ReducirFila(M[i],I[i]);
			//MostrarMatriz(M);
		
			CerarColumna(M,I,i);
		}
	}

	int EncontrarPosElemFila(float M[MAX])
	{
		int i=1;
		while(M[i]==0)i++;
		//printf("Elemento encontrado en la columna %d es %f\n",i,M[i]);
		return i;
	}
	void ReducirFila(float M[MAX], float I[MAX])
	{
		int i,j;
		i=0;
		float divisor;
		divisor=M[EncontrarPosElemFila(M)];
		for(i=1;i< tam;i++)
		{
			if(M[i]!=0)
			{
				M[i]/=divisor;
			
			}
			I[i]/=divisor;
		}
	}
	bool FilasIguales(float Anterior[MAX],float Siguiente[MAX])
	{
		int i = 1;
		while ( i < tam ) 
		{
			if ( Anterior[i] != Siguiente[i] ) return false;
			i++;
		}
		return true;

		int cont=0;
		for(int i=1;i< tam;i++)
		{
			if(Anterior[i]==Siguiente[i])cont++;
		}
		if(cont==MAX-1)return true;
		return false;
	}
	bool IgualdadPresente(float M[MAX][MAX])
	{
		int i,j,k;
		i=j=k=1;
		for(i=1;i< tam;i++)
		{
			for(k=1;k< tam;k++)
			{
				if ( i!=k && FilasIguales( M[i],M[k] ) ) return true;
			}
		}
		return false;
	}
	void CerarColumna(float M[MAX][MAX],float I[MAX][MAX],int i)
	{
		int posicion;
		int j,k;
		k=1;j=1;
		while(k< tam)
		{
			float operador;
			posicion=EncontrarPosElemFila(M[k]);
			operador=-(M[k][i]);
			//cout << "fila pivote " << i << endl;
			//cout << "operador " << operador << " encontrado en... " << k << " " << posicion << endl;
			j=1;
			if(k != i)
			{
				while(j< tam)
				{
					//printf("F%d =  F%d %f * k %f + original %f \n",k,i,M[i][j],operador,M[k][j]);
					M[k][j]+=operador*M[i][j];
					I[k][j]+=operador*I[i][j];
					j++;
				}
			}
			if(IgualdadPresente(M))break;
			//cout << "k es_ " << k << endl;
			k++;
			//cout << "k cambiado :" << k << endl;
		
		}
	}

	//SALIDA
	void MostrarMatriz(float M[MAX][MAX])
	{
		 int i,j;

		for(i=1;i< tam;i++)
		{
			for(j=1;j< tam;j++)
			{
				printf("%5.2f",M[i][j]);
				if(j!=MAX)printf(" ");
			}
			puts("");
		}
	}

};


