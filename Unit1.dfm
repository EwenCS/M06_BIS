object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 299
  ClientWidth = 635
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 264
    Top = 29
    Width = 31
    Height = 13
    Caption = 'Label1'
  end
  object Shape1: TShape
    Left = 232
    Top = 144
    Width = 121
    Height = 97
    Shape = stCircle
  end
  object Shape2: TShape
    Left = 272
    Top = 168
    Width = 41
    Height = 49
    Shape = stCircle
  end
  object Button1: TButton
    Left = 56
    Top = 24
    Width = 75
    Height = 25
    Caption = 'Rechercher'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 137
    Top = 26
    Width = 121
    Height = 21
    TabOrder = 1
    Text = '172.20.21.157'
  end
  object ComboBox1: TComboBox
    Left = 312
    Top = 26
    Width = 145
    Height = 21
    TabOrder = 2
    Text = 'ComboBox1'
  end
  object Button2: TButton
    Left = 56
    Top = 55
    Width = 75
    Height = 25
    Caption = 'Configuration'
    TabOrder = 3
    OnClick = Button2Click
  end
end
