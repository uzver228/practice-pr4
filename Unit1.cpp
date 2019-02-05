//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
AnsiString MyFName = "";
String S, S1;
bool TextMode = false;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
 MyFName =  "" ;
 Memo1->Lines->Clear();
 Form1->Caption="̳� �������� "+MyFName;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N6Click(TObject *Sender)
{
 MyFName =  "" ;
 Memo1->Lines->Clear();
 Form1->Caption="̳� �������� "+MyFName;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N8Click(TObject *Sender)
{
 if (MyFName !=  "")
Memo1->Lines->SaveToFile(MyFName);
else if(SaveDialog1->Execute())
{
MyFName = SaveDialog1->FileName;
Memo1->Lines->SaveToFile(SaveDialog1->FileName);
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N9Click(TObject *Sender)
{
SaveDialog1->FileName = MyFName;
if (SaveDialog1->Execute())
{
MyFName = SaveDialog1->FileName;
Memo1->Lines->SaveToFile(SaveDialog1->FileName);
}
Form1->Caption="̳� ��������: "+MyFName;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N7Click(TObject *Sender)
{
if (OpenDialog1->Execute())
{
MyFName = OpenDialog1->FileName;
Memo1->Lines->LoadFromFile(OpenDialog1->FileName);
}
Form1->Caption="̳� ��������: "+MyFName;
}
//---------------------------------------------------------------------------}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton3Click(TObject *Sender)
{
 if (OpenDialog1->Execute())
{
MyFName = OpenDialog1->FileName;
Memo1->Lines->LoadFromFile(OpenDialog1->FileName);
}
Form1->Caption="̳� ��������: "+ MyFName;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{
 if (MyFName !=  "")
Memo1->Lines->SaveToFile(MyFName);
else if(SaveDialog1->Execute())
{
MyFName = SaveDialog1->FileName;
Memo1->Lines->SaveToFile(SaveDialog1->FileName);
}
Form1->Caption="̳� ��������: "+ MyFName;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton4Click(TObject *Sender)
{
 Memo1->CutToClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N18Click(TObject *Sender)
{
 Memo1->SelectAll();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton6Click(TObject *Sender)
{
 Memo1->PasteFromClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N19Click(TObject *Sender)
{
  Memo1->CutToClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N20Click(TObject *Sender)
{
 Memo1->CopyToClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N21Click(TObject *Sender)
{
 Memo1->PasteFromClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N11Click(TObject *Sender)
{
  Memo1->CopyToClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N12Click(TObject *Sender)
{
  Memo1->PasteFromClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N10Click(TObject *Sender)
{
  Memo1->CutToClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N13Click(TObject *Sender)
{
Form1->WindowState=wsMaximized;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N14Click(TObject *Sender)
{
  Form1->WindowState=wsMinimized;
}
//---------------------------------------------------------------------------

 void __fastcall TForm1::N15Click(TObject *Sender)
{
 Form1->WindowState=wsNormal;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TForm1::RichEdit1Change(TObject *Sender)
{
StatusBar1->SimpleText="������ �����: " + IntToStr(Memo1->Lines->Count) +
"       ������ �������: "  + IntToStr(Memo1->Text.Length()) ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N16Click(TObject *Sender)
{
 if(ColorDialog1->Execute())
   Memo1->Color =ColorDialog1->Color;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::N17Click(TObject *Sender)
{
 if(FontDialog1->Execute())
Memo1->Font=FontDialog1->Font;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N22Click(TObject *Sender)
{
  if(PrintDialog1->Execute())
 { TPrinter* Printer  =  Printers::Printer();
   Printer->Canvas->Font=Memo1->Font;
   int height=Printer->Canvas->TextHeight(Memo1->Lines->Strings[0]);
   int top=10;
   Printer->BeginDoc();
   for(int i=0;i<Memo1->Lines->Count;i++)
   {
   Printer->Canvas->TextOutA(10,top,Memo1->Lines->Strings[i]);
   top+=height;
   if(top>=Printer->PageHeight) {top=10; Printer->NewPage();}
   }
   Printer->EndDoc();
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N24Click(TObject *Sender)
{
if (N24->Checked==true)N24->Checked=false;
 else N24->Checked=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N5Click(TObject *Sender)
{
Form2->ShowModal();
}
//---------------------------------------------------------------------------


int errors = 0;
int it = 0;
int in_time;

void __fastcall TForm1::Memo1KeyPress(TObject *Sender, char &Key)
{
  if (N24->Checked==true) {
     S=Memo1->Lines->Text;
     S1=S.SubString(S.Length()-1,2);
     AnsiString str( &Key, 1 );
     if (S.Length()==0) {
        Key=0;
        Memo1->Lines->Text=Memo1->Lines->Text+AnsiUpperCase(str);
     }
     if (S1==". " && Key!=8) {
        Key=0;
        Memo1->Lines->Text=Memo1->Lines->Text+AnsiUpperCase(str);
     }
     Memo1->SelStart=Memo1->Text.Length();
  }

  if(TextMode) {
     Timer1->Enabled = true;
     Label3->Visible = true;
     if(Key != 8 && Key != Memo2->Lines->Text.c_str()[it++])
        Label1->Caption = "�������: " + IntToStr(++errors);
     if(Key == 8)
        (it > 0) ? it-- : 0;
  }
}

//---------------------------------------------------------------------------

void __fastcall TForm1::N25Click(TObject *Sender)
{
    if(TextMode) {
    //exit
        errors = 0;
        it = 0;
        in_time = 0;

        N25->Checked = false;
        TextMode = false;
        Label1->Visible = false;
        Label2->Visible = false;
        Label3->Visible = false;
        Button1->Visible = false;
        Memo2->Visible = false;
        Memo1->Align = alClient;
        Memo1->Lines->Clear();
    }
    else {
        N25->Checked = true;
        Memo2->Lines->LoadFromFile("text.txt");
        TextMode = true;
        N24->Checked = false;
        Label1->Visible = true;
        //Label3->Visible = true;
        Button1->Visible = true;
        Memo2->Visible = true;
        Memo1->Align = alNone;
        Memo1->Width = 393;
    }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
    Timer1->Enabled = false;
    Label2->Caption = "�������� �����: " +
                      FloatToStrF(it/(float)in_time*60, ffGeneral, 6, 2) + " �������/��";
    Label2->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    in_time++;
    Label3->Caption = "���: " + IntToStr(in_time) + " c��.";
}
//---------------------------------------------------------------------------

