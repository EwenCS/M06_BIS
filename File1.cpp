#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "IRSnifferCirpark.h"
using namespace std;
std::string IntVersChaineHexa(unsigned int nombre, int nbCar)//(65535,4)->"FFFF"   (10,4)->"000A"   (10,2)->"0A"
{	char chaineHexa[9];
	for(int i=0; i<nbCar; i++)
	{	int quartet=(nombre>>(4*((7-(8-nbCar))-i)))&0xf;
		if(quartet>=10)
		{	chaineHexa[i]='A'-10+quartet;
		}
		else
		{	chaineHexa[i]='0'+quartet;
		}
	}
	chaineHexa[nbCar]=0;
	return chaineHexa;
}
unsigned int ChaineHexaVersInt(char *chaineHexa, int nbCar)   //("FFFF",4)->65535   ("ffff",4)->65535
{	int nombre=0,j;
	char caractere;
	for(j=0;j<nbCar;j++)
	{ 	caractere=chaineHexa[j];
		if(caractere>='0' && caractere<='9')
		{ 	 nombre=nombre+((caractere-'0')<<(4*(nbCar-j-1)));
		}
		else
		{   char a;
			if(caractere>='a') a='a';
			else a='A';
			nombre=nombre+((caractere-a+10)<<(4*(nbCar-j-1)));
		}
	}
	return nombre;
}
int _tmain(int argc, _TCHAR* argv[])
{   IRSnifferCirpark sniffer;
	if(sniffer.ParametrerLeServeurCirpark("172.20.21.157",10102))
		cout<<"Creation socket OK"<<endl;
	else cout<<"Creation socket ERREUR"<<endl;
	sniffer.DetecterLesCapteurs(0x0B0,0x1CFF);
	cout<<sniffer.NombreCapteursTrouves()<<" capteurs"<<endl;
	sniffer.EnregistrerSous("ListeCapteur.txt");
	cin.get();
	return 0;
}
