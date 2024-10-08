//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <fstream>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "IRSnifferCirpark.h"
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// Composants gérés par l'EDI
	TButton *Button1;
	TEdit *Edit1;
	TLabel *Label1;
	TComboBox *ComboBox1;
	TShape *Shape1;
	TShape *Shape2;
	TButton *Button2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);



private:	// Déclarations utilisateur
public:		// Déclarations utilisateur
	IRSnifferCirpark sniffer;
	ofstream fichier;

	unsigned int TForm1::ChaineHexaVersInt(char *chaineHexa, int nbCar)
{ int nombre=0,j;
char caractere;
for(j=0;j<nbCar;j++)
{ caractere=chaineHexa[j];
if(caractere>='0' && caractere<='9')
{ nombre=nombre+((caractere-'0')<<(4*(nbCar-j-1)));
}
else nombre=nombre+((caractere-'A'+10)<<(4*(nbCar-j-1)));
}
return nombre;
}
	__fastcall TForm1(TComponent* Owner);
};


//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
