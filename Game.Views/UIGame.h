#pragma once

#include <stdlib.h>
#include <time.h>
#include "../Game.Controllers/ArrowsController.h";

namespace GameViews {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de UIGame
	/// </summary>
	public ref class UIGame : public System::Windows::Forms::Form
	{

	public:
		UIGame(void)
		{

			InitializeComponent();

			background = gcnew Bitmap("background.png");
			arrows = gcnew Bitmap("FlechasSprite.png");
			arrowController = new ArrowsController();
			graphic = this->CreateGraphics();
			//
			//TODO: agregar código de constructor aquí
			//
			yCol1 = 0;
			yCol2 = 0;
			yCol3 = 0;
			yCol4 = 0;
			
			// Inicializamos con random e inicializar con cualquier flecha dentro del rectangulo	
			// Random de Sprits X y Y

			speed = 0;

			sCol1 = false;
			sCol2 = false;
			sCol3 = false;
			sCol4 = false;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~UIGame()
		{
			if (components)
			{
				delete components;
			}
		}
		// Variables de la aplicación
	private: 
		int idSpriteXCol1, idSpriteYCol1, xCol1, yCol1;
		Bitmap^ background;
		Bitmap ^ arrows;
		Graphics ^ graphic;
		BufferedGraphicsContext^ bufferedGraphicContext;
		BufferedGraphics ^ bufferedGraphics;
		ArrowsController* arrowController;

		int idSpriteXCol2, idSpriteYCol2, xCol2, yCol2;
		int idSpriteXCol3, idSpriteYCol3, xCol3, yCol3;
		int idSpriteXCol4, idSpriteYCol4, xCol4, yCol4;
		bool sCol1,sCol2,sCol3,sCol4;

		int time=0,increaseSpeed=0,speed;

	protected:




	private: System::Windows::Forms::Label^  lblTiempo;



	private: System::Windows::Forms::Timer^  timerGame;
	private: System::Windows::Forms::Label^  lblSpeed;
	private: System::Windows::Forms::Label^  lblTimeText;
	private: System::Windows::Forms::Label^  lblSpeedText;

	private: System::Windows::Forms::Label^  lblResultado;

	private: System::Windows::Forms::Timer^  timerArrows;




	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->lblTiempo = (gcnew System::Windows::Forms::Label());
			this->timerGame = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblSpeed = (gcnew System::Windows::Forms::Label());
			this->lblTimeText = (gcnew System::Windows::Forms::Label());
			this->lblSpeedText = (gcnew System::Windows::Forms::Label());
			this->lblResultado = (gcnew System::Windows::Forms::Label());
			this->timerArrows = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// lblTiempo
			// 
			this->lblTiempo->AutoSize = true;
			this->lblTiempo->ForeColor = System::Drawing::Color::White;
			this->lblTiempo->Location = System::Drawing::Point(99, 13);
			this->lblTiempo->Name = L"lblTiempo";
			this->lblTiempo->Size = System::Drawing::Size(16, 17);
			this->lblTiempo->TabIndex = 2;
			this->lblTiempo->Text = L"0";
			// 
			// timerGame
			// 
			this->timerGame->Enabled = true;
			this->timerGame->Interval = 1000;
			this->timerGame->Tick += gcnew System::EventHandler(this, &UIGame::timerGame_Tick);
			// 
			// lblSpeed
			// 
			this->lblSpeed->AutoSize = true;
			this->lblSpeed->ForeColor = System::Drawing::Color::White;
			this->lblSpeed->Location = System::Drawing::Point(208, 13);
			this->lblSpeed->Name = L"lblSpeed";
			this->lblSpeed->Size = System::Drawing::Size(16, 17);
			this->lblSpeed->TabIndex = 3;
			this->lblSpeed->Text = L"0";
			// 
			// lblTimeText
			// 
			this->lblTimeText->AutoSize = true;
			this->lblTimeText->ForeColor = System::Drawing::Color::White;
			this->lblTimeText->Location = System::Drawing::Point(34, 13);
			this->lblTimeText->Name = L"lblTimeText";
			this->lblTimeText->Size = System::Drawing::Size(59, 17);
			this->lblTimeText->TabIndex = 4;
			this->lblTimeText->Text = L"Tiempo:";
			// 
			// lblSpeedText
			// 
			this->lblSpeedText->AutoSize = true;
			this->lblSpeedText->ForeColor = System::Drawing::Color::White;
			this->lblSpeedText->Location = System::Drawing::Point(128, 13);
			this->lblSpeedText->Name = L"lblSpeedText";
			this->lblSpeedText->Size = System::Drawing::Size(74, 17);
			this->lblSpeedText->TabIndex = 5;
			this->lblSpeedText->Text = L"Velocidad:";
			// 
			// lblResultado
			// 
			this->lblResultado->AutoSize = true;
			this->lblResultado->BackColor = System::Drawing::Color::BlanchedAlmond;
			this->lblResultado->Location = System::Drawing::Point(248, 13);
			this->lblResultado->Name = L"lblResultado";
			this->lblResultado->Size = System::Drawing::Size(72, 17);
			this->lblResultado->TabIndex = 6;
			this->lblResultado->Text = L"Resultado";
			// 
			// timerArrows
			// 
			this->timerArrows->Enabled = true;
			this->timerArrows->Tick += gcnew System::EventHandler(this, &UIGame::timerArrows_Tick);
			// 
			// UIGame
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(597, 744);
			this->Controls->Add(this->lblResultado);
			this->Controls->Add(this->lblSpeedText);
			this->Controls->Add(this->lblTimeText);
			this->Controls->Add(this->lblSpeed);
			this->Controls->Add(this->lblTiempo);
			this->MaximizeBox = false;
			this->Name = L"UIGame";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"UIGame";
			this->Load += gcnew System::EventHandler(this, &UIGame::UIGame_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void UIGame_Load(System::Object^  sender, System::EventArgs^  e) {
		

	}
			 



private: System::Void timerGame_Tick(System::Object^  sender, System::EventArgs^  e) {
	
	// Tiempo
	time++;
	this->lblTiempo->Text = time + "";

	//time = 1, porque no permite tomar desde 0 para el movimiento de flechas
	if (time % 15 == 0 || time <= 1) {
		// Aumentamos +4 Pixeles por cada 15 segundos
		increaseSpeed +=4;
		//Enviamos o steamos el incremento acumulado a nuestro controlador con el metodo setIncreaseSpeed(nueva velocidad por pixel)
		arrowController->setIncreaseSpeed(increaseSpeed);
	}
	

}


private: System::Void timerArrows_Tick(System::Object^  sender, System::EventArgs^  e) {

	// Velocidad
	speed++;


	bufferedGraphicContext = BufferedGraphicsManager::Current;
	bufferedGraphics = bufferedGraphicContext->Allocate(graphic, this->ClientRectangle);
	bufferedGraphics->Graphics->DrawImage(background, 0, 0);

	arrowController->alignArrowsPositionX(bufferedGraphics->Graphics, arrows);
	int dato = arrowController->moveArrows(bufferedGraphics->Graphics, arrows);
	lblSpeed->Text = dato + "";
	bufferedGraphics->Render(graphic);

	/*

	Graphics^ graphic = this->CreateGraphics();

	int ancho = pbArrows->Width / 4;
	int alto = pbArrows->Height / 4;

	//Selecciomos un bloque de una flecha utilizando rectangulo

	Rectangle sectionVisibleCol1 = Rectangle(ancho * idSpriteXCol1, alto * idSpriteYCol2, ancho, alto);

	//Columna 1

	graphic->DrawImage(pbArrows->Image, 45, yCol1, sectionVisibleCol1, GraphicsUnit::Pixel);

	if (yCol1 == 550) {
		yCol1 = 0;
		sCol1 = false;

		// Random de Sprits X y Y
		idSpriteXRandomCol1 = rand() % 3;
		idSpriteYRandomCol1 = rand() % 3;

		//Cambiar Sprits

		idSpriteXCol1 = idSpriteXRandomCol1;
		idSpriteYCol1 = idSpriteYRandomCol1;

		//Aumentar la velocidad
		//timerCol1->Interval = timerCol1->Interval - 5;
	}

	if (yCol1 == 0) {
		randomOrder1 = rand() % 250;
		speed = 0;
		//lblResultado->Text = "";
	}
	if (randomOrder1 == speed) {
		sCol1 = true;
	}

	if (sCol1 == true) {
		yCol1++;
	}

	

	//Columna 2

	Rectangle sectionVisibleCol2 = Rectangle(ancho * idSpriteXCol2, alto * idSpriteYCol2, ancho, alto);

	graphic->DrawImage(pbArrows->Image, 170, yCol2, sectionVisibleCol2, GraphicsUnit::Pixel);

	if (yCol2 == 550) {
	yCol2 = 0;
	sCol2 = false;
	// Random de Sprits X y Y
	idSpriteXRandomCol2 = rand() % 3;
	idSpriteYRandomCol2 = rand() % 3;

	//Cambiar Sprits

	idSpriteXCol2 = idSpriteXRandomCol2;
	idSpriteYCol2 = idSpriteYRandomCol2;

	//Aumentar la velocidad
	//timerCol2->Interval = timerCol2->Interval - 5;
	}


	if (yCol2 == 0) {
	randomOrder2 = rand() % 250;
	speed = 0;
	//lblResultado->Text = "";
	}
	if (randomOrder2 == speed) {
	sCol2 = true;
	}

	if (sCol2 == true) {
	yCol2++;
	}


	//Columna 3

	Rectangle sectionVisibleCol3 = Rectangle(ancho * idSpriteXCol3, alto * idSpriteYCol3, ancho, alto);

	graphic->DrawImage(pbArrows->Image, 300, yCol3, sectionVisibleCol3, GraphicsUnit::Pixel);

	if (yCol3 == 550) {
	yCol3 = 0;
	sCol3 = false;

	// Random de Sprits X y Y
	idSpriteXRandomCol3 = rand() % 3;
	idSpriteYRandomCol3 = rand() % 3;

	//Cambiar Sprits

	idSpriteXCol3 = idSpriteXRandomCol3;
	idSpriteYCol3 = idSpriteYRandomCol3;

	//Aumentar la velocidad
	//timerCol3->Interval = timerCol3->Interval - 5;
	}

	if (yCol3 == 0) {
	randomOrder3 = rand() % 250;
	speed = 0;
	//lblResultado->Text = "";
	}
	if (randomOrder3 == speed) {
	sCol3 = true;
	}

	if (sCol3 == true) {
	yCol3++;
	}



	//Columna 4

	Rectangle sectionVisibleCol4 = Rectangle(ancho * idSpriteXCol4, alto * idSpriteYCol4, ancho, alto);

	graphic->DrawImage(pbArrows->Image, 425, yCol4, sectionVisibleCol4, GraphicsUnit::Pixel);

	if (yCol4 == 550) {
	yCol4 = 0;
	sCol4 = false;
	// Random de Sprits X y Y
	idSpriteXRandomCol4 = rand() % 3;
	idSpriteYRandomCol4 = rand() % 3;

	//Cambiar Sprits

	idSpriteXCol4 = idSpriteXRandomCol4;
	idSpriteYCol4 = idSpriteYRandomCol4;

	//Aumentar la Velocidad
	//timerCol4->Interval = timerCol4->Interval - 5;
	}

	if (yCol4 == 0) {
	randomOrder4 = rand() % 250;
	speed = 0;
	//lblResultado->Text = "";
	}
	if (randomOrder4 == speed) {
	sCol4 = true;
	}

	if (sCol4 == true) {
	yCol4++;
	}
	
	*/
}
private: System::Void pbArrows_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
//	this->pbArrows->Visible = false;
}
};
		 
}
