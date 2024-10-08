//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <fstream>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
 sniffer.ParametrerLeServeurCirpark("172.20.21.157", 10001);
 sniffer.EnregistrerSous("Capteurs.txt");
 sniffer.DetecterLesCapteurs(0x1C0D,0x1C0E);
 sniffer.NombreCapteursTrouves();

ifstream f;
f.open("Capteurs.txt");
char adresseC[5];
for(int i=0;i<sniffer.NombreCapteursTrouves();i++)
{ 	f>>adresseC;
	ComboBox1->AddItem(adresseC,this);
}
ComboBox1->Text=adresseC;
f.close();
}

//void __fastcall TForm1::Button2Click(TObject *Sender)
//{
	//if (sniffer.Etat()==0) {
		//Shape1->Brush->Color = clRed;
	//} else if (sniffer.Etat() == 1) {
			   //Shape1->Brush->Color = clGreen;
		   //}
//}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
sniffer.ParametrerLeServeurCirpark("172.20.21.157",10001);
sniffer.LireConfigurationCapteur(ChaineHexaVersInt(AnsiString(ComboBox1->Text).c_str(),4));
Label1->Caption=sniffer.TxtEtat().c_str();
if(sniffer.Etat()==1) Shape1->Brush->Color=0x0000ff;
else Shape1->Brush->Color=0x00ff00;
}
//---------------------------------------------------------------------------

