#include <iostream>
#include<cmath> 
#define max 4
 //float n=3;

using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
  float Determinante(float matriz[][max], float a);
  float Cofactor(float matriz[][max], float a, float fila, float columna);
  float AdjuntaTranspuesta(float matriz[][max], float a ,float det);
  float ResultadoF(float matrizT[][max],float Det,float a );
int main()
 {
	 float matriz [max][max];
	float Det,a=4;
	 cout  << "\n ingrese los valores para la matriz :\n\n";
	 for (int f=0; f<a; f++) {
	 	for (int c=0; c<a; c++){
	 		cout<<"("<<f<<","<<c<<")"<<endl;
		  cin>>matriz[f][c];
		 }
	 }
	
	cout<<"Mostrando la matriz : ";
	cout<<"\a";
		for(int f=0; f<a; f++){
			
 		for (int c=0; c<a; c++){
 			cout <<"\t"<<matriz[f][c]; 
		 }
		 cout<<"\a"<<endl;
	 }
	 
	 Det=Determinante(  matriz, a);
	 cout<< "La Determinante es :"<<Det<<endl;
	 AdjuntaTranspuesta(matriz,a,Det);
	return 0;
}
  
  float Determinante(float matriz[][max], float a)
  {
  	float Det=0.0;
  	int f=0,i=0;
  	if (a==1)
	  {
  		Det=matriz[0][0];
	  } 
	  else
	  {
	
		  	for(int c=0; c<a; c++)
	  		{
	  			Det=Det+matriz[0][c]*Cofactor(matriz,a,f,c);
	  		}
	  }
	  return Det;
  }
  
  //procedimento de cofactores y productos cruz
 float Cofactor(float matriz[][max], float a, float fila, float columna)
  {
  	float matriz2[max][max];
  	float nw=a-1;
  	int i=0,nueva;
  	int e=0;
  	int s=0;
  	for (int f=0; f<a; f++)
  	{
		for(int c=0; c<a; c++)
  		{
  			if(f!= fila && c!=columna)
			  {
			  	matriz2[e][s]=matriz[f][c];
			  	//	cout<<"\t:"<<matriz2[e][s];
			  	s++;
			  	if (s>=nw)
			  	{
			  		e++;
			  		s=0;
				  }
			  }
		  }	
		}
	  return pow(-1.0,fila+columna)* Determinante(matriz2, nw);
  }
  
  //matriz adjunta y tanspuesta
  float AdjuntaTranspuesta(float matriz[][max], float a,float Det){
  	float matrizC[max][max];
  	float matrizT[max][max];
  	int f=0,i=0;
  	if (a==1)
	  {
		Det=matriz[0][0];
	  } 
	  else
	  {
	  	// matriz adjunta
	  	cout<<endl<<"La matriz adjuanta es : "<<endl;
		for(int f=0;f<a;f++){

		  	for(int c=0; c<a; c++)
	  		{
			 matrizC[f][c]=Cofactor(matriz,a,f,c);
			 // cout<<"f: "<<f<<" c :"<<c<<endl;
			  cout<<"\t:"<<matrizC[f][c];
			  matrizT[c][f]=matrizC[f][c];
	  		}
	  		cout<<"\a"<<endl;
	  		i+=1;
	  		if(i<a){
	  		i=0;	
			  }
			  else{
			  f-=1;
			}
	  	}
	  }
	  // matriz transpuesta 
	  cout<<endl<<"La Matriz Transpuesta "<<endl;
	   for (int f=0; f<a; f++) {
	 	for (int c=0; c<a; c++){
	 		cout<<"\t:"<<matrizT[f][c];
		 }
		 cout<<"\n"<<endl;
	 }
	 ResultadoF(matrizT,Det,a);
	  return 0 ;
  }
  
  //resultado fial 
  float ResultadoF(float matrizT[max][max], float Det, float a){
  	float matrizb[max][max];
	int ent;
  	float dec,veri;
	 if(Det!=0){
		cout<<"El resultado de la multiplicacion de la matriz ingresada dividida entre la determinante  es : "<<endl;
	 	for (int f=0; f<a; f++) {
	 		for (int c=0; c<a; c++){
		  		matrizb[f][c]=matrizT[f][c]/Det;
		  		dec=matrizb[f][c];
		  		ent=dec;
		  		veri=dec-ent;
		  		if(veri!=0){
		  		cout<<"\t"<<matrizT[f][c]<<"/"<<Det;
				  }else{
				cout<<"\t:"<<matrizb[f][c];	
				}
			}
				cout<<"\n"<<endl;
		 	}
	 	}
	 	else{
	 		cout<<"Error no es posible una division por 0";
		 }
		return 0;
}
