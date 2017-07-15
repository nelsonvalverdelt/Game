#pragma once
#include "../Game.Views/ArrowsController.h";

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
			bufferedGraphicContext = BufferedGraphicsManager::Current;
			bufferedGraphics = bufferedGraphicContext->Allocate(graphic, this->ClientRectangle);
		

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
		int cont = 0;
		int outputArrowsCol1 = 0, outputArrowsCol2 = 0, outputArrowsCol3 = 0, outputArrowsCol4 = 0;
		int countHitCol1 = 0;
	protected:

	private: System::Windows::Forms::Label^  lblTiempo;
	private: System::Windows::Forms::Timer^  timerGame;
	private: System::Windows::Forms::Label^  lblSpeed;
	private: System::Windows::Forms::Label^  lblTimeText;
	private: System::Windows::Forms::Label^  lblSpeedText;
	private: System::Windows::Forms::Label^  lblResultado;
	private: System::Windows::Forms::Timer^  timerArrows;
	private: System::Windows::Forms::Label^  lblRojo;
	private: System::Windows::Forms::Label^  lblAzul;
	private: System::Windows::Forms::Label^  lblAmarilla;
	private: System::Windows::Forms::Label^  lblVerde;
	private: System::Windows::Forms::Label^  lblIzquierda;
	private: System::Windows::Forms::Label^  lblArriba;
	private: System::Windows::Forms::Label^  lblAbajo;
	private: System::Windows::Forms::Label^  lblDerecha;
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
			this->lblRojo = (gcnew System::Windows::Forms::Label());
			this->lblAzul = (gcnew System::Windows::Forms::Label());
			this->lblAmarilla = (gcnew System::Windows::Forms::Label());
			this->lblVerde = (gcnew System::Windows::Forms::Label());
			this->lblIzquierda = (gcnew System::Windows::Forms::Label());
			this->lblArriba = (gcnew System::Windows::Forms::Label());
			this->lblAbajo = (gcnew System::Windows::Forms::Label());
			this->lblDerecha = (gcnew System::Windows::Forms::Label());
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
			this->lblResultado->Location = System::Drawing::Point(428, 13);
			this->lblResultado->Name = L"lblResultado";
			this->lblResultado->Size = System::Drawing::Size(72, 17);
			this->lblResultado->TabIndex = 6;
			this->lblResultado->Text = L"Resultado";
			// 
			// timerArrows
			// 
			this->timerArrows->Enabled = true;
			this->timerArrows->Interval = 1;
			this->timerArrows->Tick += gcnew System::EventHandler(this, &UIGame::timerArrows_Tick);
			// 
			// lblRojo
			// 
			this->lblRojo->AutoSize = true;
			this->lblRojo->ForeColor = System::Drawing::Color::White;
			this->lblRojo->Location = System::Drawing::Point(504, 102);
			this->lblRojo->Name = L"lblRojo";
			this->lblRojo->Size = System::Drawing::Size(44, 17);
			this->lblRojo->TabIndex = 7;
			this->lblRojo->Text = L"Rojas";
			// 
			// lblAzul
			// 
			this->lblAzul->AutoSize = true;
			this->lblAzul->ForeColor = System::Drawing::Color::White;
			this->lblAzul->Location = System::Drawing::Point(507, 148);
			this->lblAzul->Name = L"lblAzul";
			this->lblAzul->Size = System::Drawing::Size(50, 17);
			this->lblAzul->TabIndex = 8;
			this->lblAzul->Text = L"Azules";
			// 
			// lblAmarilla
			// 
			this->lblAmarilla->AutoSize = true;
			this->lblAmarilla->ForeColor = System::Drawing::Color::White;
			this->lblAmarilla->Location = System::Drawing::Point(507, 196);
			this->lblAmarilla->Name = L"lblAmarilla";
			this->lblAmarilla->Size = System::Drawing::Size(65, 17);
			this->lblAmarilla->TabIndex = 9;
			this->lblAmarilla->Text = L"Amarillas";
			// 
			// lblVerde
			// 
			this->lblVerde->AutoSize = true;
			this->lblVerde->ForeColor = System::Drawing::Color::White;
			this->lblVerde->Location = System::Drawing::Point(510, 247);
			this->lblVerde->Name = L"lblVerde";
			this->lblVerde->Size = System::Drawing::Size(53, 17);
			this->lblVerde->TabIndex = 10;
			this->lblVerde->Text = L"Verdes";
			// 
			// lblIzquierda
			// 
			this->lblIzquierda->AutoSize = true;
			this->lblIzquierda->BackColor = System::Drawing::Color::Black;
			this->lblIzquierda->ForeColor = System::Drawing::Color::White;
			this->lblIzquierda->Location = System::Drawing::Point(74, 34);
			this->lblIzquierda->Name = L"lblIzquierda";
			this->lblIzquierda->Size = System::Drawing::Size(66, 17);
			this->lblIzquierda->TabIndex = 11;
			this->lblIzquierda->Text = L"izquierda";
			// 
			// lblArriba
			// 
			this->lblArriba->AutoSize = true;
			this->lblArriba->ForeColor = System::Drawing::Color::White;
			this->lblArriba->Location = System::Drawing::Point(208, 34);
			this->lblArriba->Name = L"lblArriba";
			this->lblArriba->Size = System::Drawing::Size(45, 17);
			this->lblArriba->TabIndex = 12;
			this->lblArriba->Text = L"arriba";
			// 
			// lblAbajo
			// 
			this->lblAbajo->AutoSize = true;
			this->lblAbajo->ForeColor = System::Drawing::Color::White;
			this->lblAbajo->Location = System::Drawing::Point(337, 34);
			this->lblAbajo->Name = L"lblAbajo";
			this->lblAbajo->Size = System::Drawing::Size(43, 17);
			this->lblAbajo->TabIndex = 13;
			this->lblAbajo->Text = L"abajo";
			// 
			// lblDerecha
			// 
			this->lblDerecha->AutoSize = true;
			this->lblDerecha->BackColor = System::Drawing::Color::Black;
			this->lblDerecha->ForeColor = System::Drawing::Color::White;
			this->lblDerecha->Location = System::Drawing::Point(440, 34);
			this->lblDerecha->Name = L"lblDerecha";
			this->lblDerecha->Size = System::Drawing::Size(60, 17);
			this->lblDerecha->TabIndex = 14;
			this->lblDerecha->Text = L"derecha";
			// 
			// UIGame
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(597, 744);
			this->Controls->Add(this->lblDerecha);
			this->Controls->Add(this->lblAbajo);
			this->Controls->Add(this->lblArriba);
			this->Controls->Add(this->lblIzquierda);
			this->Controls->Add(this->lblVerde);
			this->Controls->Add(this->lblAmarilla);
			this->Controls->Add(this->lblAzul);
			this->Controls->Add(this->lblRojo);
			this->Controls->Add(this->lblResultado);
			this->Controls->Add(this->lblSpeedText);
			this->Controls->Add(this->lblTimeText);
			this->Controls->Add(this->lblSpeed);
			this->Controls->Add(this->lblTiempo);
			this->MaximizeBox = false;
			this->Name = L"UIGame";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"UIGame";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &UIGame::UIGame_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



	private: System::Void timerGame_Tick(System::Object^  sender, System::EventArgs^  e) {
		// Tiempo
		time = time + 1;
		this->lblTiempo->Text = time + "";
		if (time == 60) {
			arrowController->guardarJuego();
		}
}

	private: System::Void timerArrows_Tick(System::Object^  sender, System::EventArgs^  e) {

		speed = speed + 5;
		this->lblSpeed->Text = speed + "";

		if (time <= 60) {
			bufferedGraphics->Graphics->DrawImage(background, 0, 0);

			if (speed % 120 == 0) {

				outputArrowsCol1 = rand() % 2;
				outputArrowsCol2 = rand() % 2;
				outputArrowsCol3 = rand() % 2;
				outputArrowsCol4 = rand() % 2;

				if (outputArrowsCol1 == 1 && outputArrowsCol2 == 0 && outputArrowsCol3 == 0 && outputArrowsCol4 == 0) {
					arrowController->alignArrowsPositionX(arrows, 1);
				}
				if (outputArrowsCol2 == 1 && outputArrowsCol1 == 0 && outputArrowsCol3 == 0 && outputArrowsCol4 == 0) {
					arrowController->alignArrowsPositionX(arrows, 2);
				}
				if (outputArrowsCol3 == 1 && outputArrowsCol1 == 0 && outputArrowsCol2 == 0 && outputArrowsCol4 == 0) {
					arrowController->alignArrowsPositionX(arrows, 3);
				}
				if (outputArrowsCol4 == 1 && outputArrowsCol3 == 0 && outputArrowsCol1 == 0 && outputArrowsCol2 == 0) {
					arrowController->alignArrowsPositionX(arrows, 4);
				}

			}
			
			arrowController->ArrowsRainColumn1(bufferedGraphics->Graphics, arrows);
			arrowController->ArrowsRainColumn2(bufferedGraphics->Graphics, arrows);
			arrowController->ArrowsRainColumn3(bufferedGraphics->Graphics, arrows);
			arrowController->ArrowsRainColumn4(bufferedGraphics->Graphics, arrows);

			//flechas inferiores
			arrowController->alignArrowsSuccess(bufferedGraphics->Graphics, successArrows);
			bufferedGraphics->Render(graphic);

		}
		
	
}

private: System::Void UIGame_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

	switch (e->KeyCode) {
	case Keys::Up: this->arrowController->SuceesArrowsUp(time); break;
	case Keys::Down: this->arrowController->SuceesArrowsDown(time);
					 break;
		case Keys::Left: this->arrowController->SuceesArrowsLeft(time); break;
		case Keys::Right: this->arrowController->SuceesArrowsRight(time); break;
	}
}
};
		 
}
