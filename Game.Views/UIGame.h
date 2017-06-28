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
			successArrows = gcnew Bitmap("FlechasExitoSprite.png");

			arrowController = new ArrowsController();
			graphic = this->CreateGraphics();
			//
			//TODO: agregar código de constructor aquí

			speed = 0;

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
		Bitmap^ background;
		Bitmap ^ arrows;
		Bitmap ^ successArrows;
		Graphics ^ graphic;
		BufferedGraphicsContext^ bufferedGraphicContext;
		BufferedGraphics ^ bufferedGraphics;
		ArrowsController* arrowController;

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
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



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

	//LLuvia de flechas
	arrowController->alignArrowsPositionX(arrows);
	int dato = arrowController->moveArrows(bufferedGraphics->Graphics, arrows);
	lblSpeed->Text = dato + "";

	//Flechas inferior estática de exito
	arrowController->alignSuccessArrow(successArrows);
	arrowController->drawSuccessArrow(bufferedGraphics->Graphics, successArrows);

	bufferedGraphics->Render(graphic);

}

};
		 
}
