#include <CtrlLib/CtrlLib.h>
#include <iostream>
using namespace Upp;
using namespace std;

struct MyAppWindow : TopWindow {
	
    virtual void Paint(Draw& w) override {
        
		w.DrawRect(GetSize(), White());
	
	    int RightEnd = GetSize().cx; int BottomEnd = GetSize().cy;
	    
	    int LeftLineX = RightEnd - (RightEnd - 10);
	    int LeftMidLineX = RightEnd - (RightEnd - 455);
	    int RightMidLineX = RightEnd - (RightEnd - 910);
	    int RightLineX = RightEnd - 10;
	    
	    int LeftLineTopY = BottomEnd - (BottomEnd - 10);
	    int MidLineY = BottomEnd - (BottomEnd - 70);
	    int LeftLineBottomY = BottomEnd - 10;
	    
	    //Lineas Verticales
	    w.DrawLine(LeftLineX, LeftLineTopY, LeftLineX, LeftLineBottomY, 5, Black()); //Linea Uno
	    w.DrawLine(LeftMidLineX, LeftLineTopY, LeftMidLineX, LeftLineBottomY, 5, Black()); //Linea Dos
	    w.DrawLine(RightMidLineX, LeftLineTopY, RightMidLineX, LeftLineBottomY, 5, Black()); //Linea Tres
	    w.DrawLine(RightLineX, LeftLineTopY, RightLineX, LeftLineBottomY, 5, Black()); //Linea Cuatro
	    
	    //Lineas Horizontales
	    w.DrawLine(LeftLineX, LeftLineTopY, RightLineX, LeftLineTopY, 5, Black()); //Linea Uno
	    w.DrawLine(LeftLineX, MidLineY, RightLineX, MidLineY, 5, Black()); //Linea Dos
	    w.DrawLine(LeftLineX, LeftLineBottomY, RightLineX, LeftLineBottomY, 5, Black()); //Linea Tres
	    
	    //Encabezados
	    int FirstTextOnX = RightEnd - (RightEnd - 156);
	    int SecondTextOnX = RightEnd - (RightEnd - 626);
	    int ThirdTextOnX = RightEnd - (RightEnd - 1060);
	    int TextOnY = BottomEnd - (BottomEnd - 20);
	    w.DrawText(FirstTextOnX, TextOnY, "Nombre", Arial(40), Blue);
	    w.DrawText(SecondTextOnX, TextOnY, "Dibujo", Arial(40), Blue);
	    w.DrawText(ThirdTextOnX, TextOnY, "Volumen", Arial(40), Blue);
	    
	    //Titulo
	    int TituloTextOnX = RightEnd - (RightEnd - 20);
	    int TituloOnY = BottomEnd - (BottomEnd - 315);
	    w.DrawText(TituloTextOnX, TituloOnY, "Cilindros", Arial(60), Black);
	    
	    //Dimensiones
	    String s = AsString(GetSize().cx) + " x " + AsString(GetSize().cy);
	    w.DrawText(GetSize().cx - GetTextSize(s, Arial(20)).cx - 30, GetSize().cy - (10 * 5), s, Arial(20), Gray());
	    
	    //Formula
	    int FormulaOnX = RightEnd - 375;
	    int FormulaOnY = BottomEnd - (BottomEnd - 220);
	    
	    w.DrawText(RightMidLineX+100, FormulaOnY, "V = A  * H", Arial(60), Black);
	    
	    int LowerOnX = RightEnd - 220;
	    int LowerOnY = BottomEnd - (BottomEnd - 255);
	    w.DrawText(RightMidLineX+255, LowerOnY, "B", Arial(30), Black);
	    
	    //Base del Cilindro
	    int BaseX1 = RightEnd - (RightEnd - 490);
	    int BaseY1 = BottomEnd - (BottomEnd - 525);
	    int BaseX2 = RightEnd - (RightEnd - 280);
	    int BaseY2 = BottomEnd - (BottomEnd - 100);
	    int TopeY1 = BottomEnd - (BottomEnd - 125);
	    int TopeY2 = BottomEnd - (BottomEnd - 100);
	    Color Inside(236,157,109);
	    Color Border(80,37,92);
	    Color Base(215,74,53);
	    
	    //Inside
	    w.DrawRect(BaseX1, TopeY2+75, BaseX1-213, BaseY1-120, Inside);
	    //Base
		w.DrawEllipse(BaseX1, BaseY1, BaseX2, BaseY2, Inside, 5, Inside);
	    //Tope del Cilindro
	    w.DrawEllipse(BaseX1, TopeY1, BaseX2, TopeY2, Inside, 5, Border);
	    //Linea Base
		w.DrawLine(LeftLineX+625, MidLineY+505, LeftLineX+755, MidLineY+505, 8, Base);
	    //Bordes del Cilindro
	    w.DrawLine(BaseX1, BaseY1+50, BaseX1, TopeY2+75, 5, Border); //Left
	    w.DrawLine(BaseX1+279, BaseY1+50, BaseX1+279, TopeY2+75, 5, Border); //Right
		
		Rect rc4 = Rect(BaseX1+280, TopeY2+525, BaseX1, BaseY1);
		w.DrawArcOp(rc4, Point(BaseX1+900, BaseY1), Point(BaseX1-500, BaseY1), PEN_DASH, Border);
		w.DrawArc(rc4, Point(BaseX1-300, BaseY1+50), Point(BaseX1+900, BaseY1+50), 5, Border);
		
		
		//Calculos
		double RadioCil, HeightCil, VolCil, BaseCil;
		const Vector<String>& cmdline = CommandLine();
		
	    RadioCil = StrDbl(cmdline[0]); HeightCil = StrDbl(cmdline[1]);
	    
	    //Indicator Radio
		w.DrawText(LeftLineX+625, MidLineY+472, "R=" + AsString(RadioCil), Arial(30), Black());
		//Indicator Height
		w.DrawText(LeftLineX+765, MidLineY+275, "H=" + AsString(HeightCil), Arial(30), Black());
	    
	    BaseCil = (3.1416 * (RadioCil * RadioCil));
	    VolCil = BaseCil * HeightCil;
	    
	    int FormulaOnX2 = RightEnd - 375;
	    int FormulaOnY2 = BottomEnd - (BottomEnd - 260);
	
		w.DrawText(RightMidLineX+35, FormulaOnY2+70, "V = " + FormatDoubleFix(BaseCil, 2) +" * " + AsString(HeightCil), Arial(60), Black);
		w.DrawText(RightMidLineX+65, FormulaOnY2+170, "V = " + FormatDoubleFix(VolCil, 3), Arial(60). Bold(), Black);
    }
        
    MyAppWindow() {
        Title("Volúmenes de Cuerpos en el Espacio - Daniel Juárez © 2022").Sizeable().Zoomable();
    }
};

GUI_APP_MAIN {
	if (CommandLine().IsEmpty()) {
		PromptOK("Cilindros: Falta indicar los parámetros 'R' y 'H'!");
	} else if (CommandLine().GetCount() == 1) {
		PromptOK("Cilindros: Falta indicar el parámetro 'H'!");
	} else {
		MyAppWindow app;
		app.Sizeable().SetMinSize(Zsz(1366, 440));
    	app.SetRect(0, 0, 1366, 697);
    	app.MinimizeBox(false);
    	app.Sizeable().Run();
	}
}