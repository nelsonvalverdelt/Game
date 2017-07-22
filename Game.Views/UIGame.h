#pragma once
#include "../Game.Views/ArrowsController.h";
#include <Windows.h>
#include <mmsystem.h>
#include <msclr\marshal_cppstd.h>
#include <stdlib.h>
#include <string>

//using namespace GameViews;
namespace GameViews {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Resumen de UIGame
	/// </summary>
	public ref class UIGame : public System::Windows::Forms::Form
	{

	public:
	
		UIGame(void)
		{
			
			InitializeComponent();
			timerGame->Enabled = false;
			timerArrows->Enabled = false;
			//Instanciamos para reproducir objetos multimedia
			player = gcnew SoundPlayer();
			player->SoundLocation = "Music/Faded-Alan_Walker.wav";
			player->Load();
			
			
			background = gcnew Bitmap("backgroundGame.png");
			arrows = gcnew Bitmap("FlechasSprite.png");
			successArrows = gcnew Bitmap("FlechasExitoSprite.png");

			//arrowController = new ArrowsController();
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
		SoundPlayer^ player;
		Bitmap^ background;
		Bitmap ^ arrows;
		Bitmap ^ successArrows;
		Graphics ^ graphic;
		BufferedGraphicsContext^ bufferedGraphicContext;
		BufferedGraphics ^ bufferedGraphics;
		ArrowsController* arrowController;
		int time=0,speed;
		int outputArrowsCol1 = 0, outputArrowsCol2 = 0, outputArrowsCol3 = 0, outputArrowsCol4 = 0;
	protected:
	private: System::Windows::Forms::Label^  lblTiempo;
	private: System::Windows::Forms::Timer^  timerGame;
	private: System::Windows::Forms::Label^  lblUser;
	private: System::Windows::Forms::Timer^  timerArrows;
	private: System::Windows::Forms::Label^  lblIzquierda;
	private: System::Windows::Forms::Label^  lblArriba;
	private: System::Windows::Forms::Label^  lblAbajo;
	private: System::Windows::Forms::Label^  lblDerecha;
	private: System::Windows::Forms::Button^  btnJugar;
	private: System::Windows::Forms::TextBox^  txtUser;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  lblFinalizar;
	private: System::Windows::Forms::GroupBox^  gbAciertos;
	private: System::Windows::Forms::GroupBox^  gbSalida;
	private: System::Windows::Forms::Label^  lblTotalDerecha;
	private: System::Windows::Forms::Label^  lblTotalAbajo;
	private: System::Windows::Forms::Label^  lblTotalArriba;
	private: System::Windows::Forms::Label^  lblTotalIzquierda;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  lblTotalAciertoDerecha;
	private: System::Windows::Forms::Label^  lblTotalAciertoAbajo;
	private: System::Windows::Forms::Label^  lblTotalAciertoArriba;
	private: System::Windows::Forms::Label^  lblTotalAciertoIzquierda;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  lblPausa;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  lblPoints;
	private: System::Windows::Forms::Label^  label10;
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
			this->lblUser = (gcnew System::Windows::Forms::Label());
			this->timerArrows = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblIzquierda = (gcnew System::Windows::Forms::Label());
			this->lblArriba = (gcnew System::Windows::Forms::Label());
			this->lblAbajo = (gcnew System::Windows::Forms::Label());
			this->lblDerecha = (gcnew System::Windows::Forms::Label());
			this->btnJugar = (gcnew System::Windows::Forms::Button());
			this->txtUser = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->gbAciertos = (gcnew System::Windows::Forms::GroupBox());
			this->lblTotalAciertoDerecha = (gcnew System::Windows::Forms::Label());
			this->lblTotalAciertoAbajo = (gcnew System::Windows::Forms::Label());
			this->lblTotalAciertoArriba = (gcnew System::Windows::Forms::Label());
			this->lblTotalAciertoIzquierda = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->gbSalida = (gcnew System::Windows::Forms::GroupBox());
			this->lblTotalDerecha = (gcnew System::Windows::Forms::Label());
			this->lblTotalAbajo = (gcnew System::Windows::Forms::Label());
			this->lblTotalArriba = (gcnew System::Windows::Forms::Label());
			this->lblTotalIzquierda = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblFinalizar = (gcnew System::Windows::Forms::Label());
			this->lblPausa = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->lblPoints = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->gbAciertos->SuspendLayout();
			this->gbSalida->SuspendLayout();
			this->SuspendLayout();
			// 
			// lblTiempo
			// 
			this->lblTiempo->AutoSize = true;
			this->lblTiempo->Font = (gcnew System::Drawing::Font(L"Kristen ITC", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTiempo->ForeColor = System::Drawing::Color::White;
			this->lblTiempo->Location = System::Drawing::Point(473, 9);
			this->lblTiempo->Name = L"lblTiempo";
			this->lblTiempo->Size = System::Drawing::Size(36, 42);
			this->lblTiempo->TabIndex = 2;
			this->lblTiempo->Text = L"0";
			// 
			// timerGame
			// 
			this->timerGame->Enabled = true;
			this->timerGame->Interval = 1000;
			this->timerGame->Tick += gcnew System::EventHandler(this, &UIGame::timerGame_Tick);
			// 
			// lblUser
			// 
			this->lblUser->AutoSize = true;
			this->lblUser->BackColor = System::Drawing::Color::Transparent;
			this->lblUser->Font = (gcnew System::Drawing::Font(L"Kristen ITC", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblUser->ForeColor = System::Drawing::Color::Lime;
			this->lblUser->Location = System::Drawing::Point(21, 61);
			this->lblUser->Name = L"lblUser";
			this->lblUser->Size = System::Drawing::Size(95, 28);
			this->lblUser->TabIndex = 6;
			this->lblUser->Text = L"Usuario:";
			// 
			// timerArrows
			// 
			this->timerArrows->Enabled = true;
			this->timerArrows->Interval = 1;
			this->timerArrows->Tick += gcnew System::EventHandler(this, &UIGame::timerArrows_Tick);
			// 
			// lblIzquierda
			// 
			this->lblIzquierda->AutoSize = true;
			this->lblIzquierda->BackColor = System::Drawing::Color::Black;
			this->lblIzquierda->ForeColor = System::Drawing::Color::White;
			this->lblIzquierda->Location = System::Drawing::Point(80, 703);
			this->lblIzquierda->Name = L"lblIzquierda";
			this->lblIzquierda->Size = System::Drawing::Size(66, 17);
			this->lblIzquierda->TabIndex = 11;
			this->lblIzquierda->Text = L"izquierda";
			// 
			// lblArriba
			// 
			this->lblArriba->AutoSize = true;
			this->lblArriba->ForeColor = System::Drawing::Color::White;
			this->lblArriba->Location = System::Drawing::Point(216, 703);
			this->lblArriba->Name = L"lblArriba";
			this->lblArriba->Size = System::Drawing::Size(45, 17);
			this->lblArriba->TabIndex = 12;
			this->lblArriba->Text = L"arriba";
			// 
			// lblAbajo
			// 
			this->lblAbajo->AutoSize = true;
			this->lblAbajo->ForeColor = System::Drawing::Color::White;
			this->lblAbajo->Location = System::Drawing::Point(335, 703);
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
			this->lblDerecha->Location = System::Drawing::Point(449, 703);
			this->lblDerecha->Name = L"lblDerecha";
			this->lblDerecha->Size = System::Drawing::Size(60, 17);
			this->lblDerecha->TabIndex = 14;
			this->lblDerecha->Text = L"derecha";
			// 
			// btnJugar
			// 
			this->btnJugar->BackColor = System::Drawing::Color::WhiteSmoke;
			this->btnJugar->Font = (gcnew System::Drawing::Font(L"Kristen ITC", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnJugar->Location = System::Drawing::Point(18, 144);
			this->btnJugar->Name = L"btnJugar";
			this->btnJugar->Size = System::Drawing::Size(105, 35);
			this->btnJugar->TabIndex = 15;
			this->btnJugar->Text = L"JUGAR";
			this->btnJugar->UseVisualStyleBackColor = false;
			this->btnJugar->Click += gcnew System::EventHandler(this, &UIGame::btnJugar_Click);
			// 
			// txtUser
			// 
			this->txtUser->Font = (gcnew System::Drawing::Font(L"Kristen ITC", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtUser->Location = System::Drawing::Point(15, 95);
			this->txtUser->Name = L"txtUser";
			this->txtUser->Size = System::Drawing::Size(105, 31);
			this->txtUser->TabIndex = 16;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->gbAciertos);
			this->panel1->Controls->Add(this->gbSalida);
			this->panel1->Controls->Add(this->lblUser);
			this->panel1->Controls->Add(this->btnJugar);
			this->panel1->Controls->Add(this->txtUser);
			this->panel1->Location = System::Drawing::Point(552, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(163, 749);
			this->panel1->TabIndex = 17;
			// 
			// gbAciertos
			// 
			this->gbAciertos->Controls->Add(this->lblTotalAciertoDerecha);
			this->gbAciertos->Controls->Add(this->lblTotalAciertoAbajo);
			this->gbAciertos->Controls->Add(this->lblTotalAciertoArriba);
			this->gbAciertos->Controls->Add(this->lblTotalAciertoIzquierda);
			this->gbAciertos->Controls->Add(this->label9);
			this->gbAciertos->Controls->Add(this->label6);
			this->gbAciertos->Controls->Add(this->label8);
			this->gbAciertos->Controls->Add(this->label7);
			this->gbAciertos->ForeColor = System::Drawing::Color::White;
			this->gbAciertos->Location = System::Drawing::Point(18, 377);
			this->gbAciertos->Name = L"gbAciertos";
			this->gbAciertos->Size = System::Drawing::Size(128, 148);
			this->gbAciertos->TabIndex = 18;
			this->gbAciertos->TabStop = false;
			this->gbAciertos->Text = L"Aciertos";
			// 
			// lblTotalAciertoDerecha
			// 
			this->lblTotalAciertoDerecha->AutoSize = true;
			this->lblTotalAciertoDerecha->Location = System::Drawing::Point(93, 109);
			this->lblTotalAciertoDerecha->Name = L"lblTotalAciertoDerecha";
			this->lblTotalAciertoDerecha->Size = System::Drawing::Size(16, 17);
			this->lblTotalAciertoDerecha->TabIndex = 8;
			this->lblTotalAciertoDerecha->Text = L"0";
			// 
			// lblTotalAciertoAbajo
			// 
			this->lblTotalAciertoAbajo->AutoSize = true;
			this->lblTotalAciertoAbajo->Location = System::Drawing::Point(94, 85);
			this->lblTotalAciertoAbajo->Name = L"lblTotalAciertoAbajo";
			this->lblTotalAciertoAbajo->Size = System::Drawing::Size(16, 17);
			this->lblTotalAciertoAbajo->TabIndex = 8;
			this->lblTotalAciertoAbajo->Text = L"0";
			// 
			// lblTotalAciertoArriba
			// 
			this->lblTotalAciertoArriba->AutoSize = true;
			this->lblTotalAciertoArriba->Location = System::Drawing::Point(94, 62);
			this->lblTotalAciertoArriba->Name = L"lblTotalAciertoArriba";
			this->lblTotalAciertoArriba->Size = System::Drawing::Size(16, 17);
			this->lblTotalAciertoArriba->TabIndex = 13;
			this->lblTotalAciertoArriba->Text = L"0";
			// 
			// lblTotalAciertoIzquierda
			// 
			this->lblTotalAciertoIzquierda->AutoSize = true;
			this->lblTotalAciertoIzquierda->Location = System::Drawing::Point(94, 36);
			this->lblTotalAciertoIzquierda->Name = L"lblTotalAciertoIzquierda";
			this->lblTotalAciertoIzquierda->Size = System::Drawing::Size(16, 17);
			this->lblTotalAciertoIzquierda->TabIndex = 12;
			this->lblTotalAciertoIzquierda->Text = L"0";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(14, 36);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(66, 17);
			this->label9->TabIndex = 8;
			this->label9->Text = L"Izquierda";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(17, 109);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(62, 17);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Derecha";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(15, 61);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(46, 17);
			this->label8->TabIndex = 9;
			this->label8->Text = L"Arriba";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(16, 85);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(44, 17);
			this->label7->TabIndex = 10;
			this->label7->Text = L"Abajo";
			// 
			// gbSalida
			// 
			this->gbSalida->Controls->Add(this->lblTotalDerecha);
			this->gbSalida->Controls->Add(this->lblTotalAbajo);
			this->gbSalida->Controls->Add(this->lblTotalArriba);
			this->gbSalida->Controls->Add(this->lblTotalIzquierda);
			this->gbSalida->Controls->Add(this->label4);
			this->gbSalida->Controls->Add(this->label3);
			this->gbSalida->Controls->Add(this->label2);
			this->gbSalida->Controls->Add(this->label1);
			this->gbSalida->ForeColor = System::Drawing::Color::White;
			this->gbSalida->Location = System::Drawing::Point(18, 210);
			this->gbSalida->Name = L"gbSalida";
			this->gbSalida->Size = System::Drawing::Size(128, 152);
			this->gbSalida->TabIndex = 17;
			this->gbSalida->TabStop = false;
			this->gbSalida->Text = L"Salida";
			// 
			// lblTotalDerecha
			// 
			this->lblTotalDerecha->AutoSize = true;
			this->lblTotalDerecha->Location = System::Drawing::Point(90, 114);
			this->lblTotalDerecha->Name = L"lblTotalDerecha";
			this->lblTotalDerecha->Size = System::Drawing::Size(16, 17);
			this->lblTotalDerecha->TabIndex = 7;
			this->lblTotalDerecha->Text = L"0";
			// 
			// lblTotalAbajo
			// 
			this->lblTotalAbajo->AutoSize = true;
			this->lblTotalAbajo->Location = System::Drawing::Point(90, 87);
			this->lblTotalAbajo->Name = L"lblTotalAbajo";
			this->lblTotalAbajo->Size = System::Drawing::Size(16, 17);
			this->lblTotalAbajo->TabIndex = 6;
			this->lblTotalAbajo->Text = L"0";
			// 
			// lblTotalArriba
			// 
			this->lblTotalArriba->AutoSize = true;
			this->lblTotalArriba->Location = System::Drawing::Point(90, 59);
			this->lblTotalArriba->Name = L"lblTotalArriba";
			this->lblTotalArriba->Size = System::Drawing::Size(16, 17);
			this->lblTotalArriba->TabIndex = 5;
			this->lblTotalArriba->Text = L"0";
			// 
			// lblTotalIzquierda
			// 
			this->lblTotalIzquierda->AutoSize = true;
			this->lblTotalIzquierda->Location = System::Drawing::Point(90, 31);
			this->lblTotalIzquierda->Name = L"lblTotalIzquierda";
			this->lblTotalIzquierda->Size = System::Drawing::Size(16, 17);
			this->lblTotalIzquierda->TabIndex = 4;
			this->lblTotalIzquierda->Text = L"0";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(18, 114);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(62, 17);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Derecha";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(18, 87);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(44, 17);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Abajo";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(18, 59);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 17);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Arriba";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(18, 31);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(66, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Izquierda";
			// 
			// lblFinalizar
			// 
			this->lblFinalizar->AutoSize = true;
			this->lblFinalizar->Font = (gcnew System::Drawing::Font(L"Kristen ITC", 22.2F));
			this->lblFinalizar->ForeColor = System::Drawing::Color::Yellow;
			this->lblFinalizar->Location = System::Drawing::Point(142, 307);
			this->lblFinalizar->Name = L"lblFinalizar";
			this->lblFinalizar->Size = System::Drawing::Size(332, 52);
			this->lblFinalizar->TabIndex = 18;
			this->lblFinalizar->Text = L"Juego Finalizado";
			this->lblFinalizar->Visible = false;
			// 
			// lblPausa
			// 
			this->lblPausa->AutoSize = true;
			this->lblPausa->Font = (gcnew System::Drawing::Font(L"Kristen ITC", 22.2F));
			this->lblPausa->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->lblPausa->Location = System::Drawing::Point(233, 379);
			this->lblPausa->Name = L"lblPausa";
			this->lblPausa->Size = System::Drawing::Size(134, 52);
			this->lblPausa->TabIndex = 19;
			this->lblPausa->Text = L"Pausa";
			this->lblPausa->Visible = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Kristen ITC", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Lime;
			this->label5->Location = System::Drawing::Point(25, 9);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(131, 42);
			this->label5->TabIndex = 20;
			this->label5->Text = L"Puntos:";
			// 
			// lblPoints
			// 
			this->lblPoints->AutoSize = true;
			this->lblPoints->Font = (gcnew System::Drawing::Font(L"Kristen ITC", 18));
			this->lblPoints->ForeColor = System::Drawing::Color::White;
			this->lblPoints->Location = System::Drawing::Point(162, 9);
			this->lblPoints->Name = L"lblPoints";
			this->lblPoints->Size = System::Drawing::Size(36, 42);
			this->lblPoints->TabIndex = 21;
			this->lblPoints->Text = L"0";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Transparent;
			this->label10->Font = (gcnew System::Drawing::Font(L"Kristen ITC", 18));
			this->label10->ForeColor = System::Drawing::Color::Lime;
			this->label10->Location = System::Drawing::Point(331, 9);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(134, 42);
			this->label10->TabIndex = 22;
			this->label10->Text = L"Tiempo:";
			// 
			// UIGame
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(712, 744);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->lblPoints);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->lblPausa);
			this->Controls->Add(this->lblFinalizar);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->lblDerecha);
			this->Controls->Add(this->lblAbajo);
			this->Controls->Add(this->lblArriba);
			this->Controls->Add(this->lblIzquierda);
			this->Controls->Add(this->lblTiempo);
			this->MaximizeBox = false;
			this->Name = L"UIGame";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L".:: JUEGO DE FLECHAS ::. NELSON VALVERDE LA TORRE";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &UIGame::UIGame_KeyDown);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->gbAciertos->ResumeLayout(false);
			this->gbAciertos->PerformLayout();
			this->gbSalida->ResumeLayout(false);
			this->gbSalida->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void timerGame_Tick(System::Object^  sender, System::EventArgs^  e) {
		// Tiempo

		time = time + 1;
	
		if (time == 60) {
			arrowController->guardarJuego();
			time = 0;
			timerGame->Enabled = false;
			timerArrows->Enabled = false;
			this->btnJugar->Enabled = true;
			this->txtUser->Text = "";
			this->txtUser->Enabled = true;
			//Eliminamos los datos
			this->lblFinalizar->Visible = true;
			player->Stop();
			
		}
		if (time == 0) {
			arrowController->deleteElementtVector();
	
		}

		this->lblTiempo->Text = time + "";
}

	private: System::Void timerArrows_Tick(System::Object^  sender, System::EventArgs^  e) {

		speed = speed + 5;
		//this->lblSpeed->Text = speed + "";

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

			
			//Total Salidas de Flechas en GroupBox Salida
			this->lblTotalIzquierda->Text = arrowController->getCountArrowsColumn(1) + "";
			this->lblTotalArriba->Text = arrowController->getCountArrowsColumn(2) + "";
			this->lblTotalAbajo->Text = arrowController->getCountArrowsColumn(3) + "";
			this->lblTotalDerecha->Text = arrowController->getCountArrowsColumn(4) + "";

			this->lblPoints->Text = arrowController->countPoints() + "";

		}
		
	
}

private: System::Void UIGame_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {


	switch (e->KeyCode) {
		case Keys::Left: this->lblTotalAciertoIzquierda->Text = this->arrowController->SuccessArrowsLeft(time) + ""; break;
		case Keys::Up: this->lblTotalAciertoArriba->Text = this->arrowController->SuccessArrowsUp(time) + ""; break;
		case Keys::Down: this->lblTotalAciertoAbajo->Text = this->arrowController->SuccessArrowsDown(time) + "";break;
		case Keys::Right: this->lblTotalAciertoDerecha->Text =  this->arrowController->SuccessArrowsRight(time) + ""; break;
		case Keys::P: 
			player->Stop();
			this->lblPausa->Visible = true;
			timerArrows->Enabled = false;
			timerGame->Enabled = false; break;;
		case Keys::S: 
			player->Play();
			this->lblPausa->Visible = false;
			timerArrows->Enabled = true;
			timerGame->Enabled = true;break;
	}

}
private: System::Void btnJugar_Click(System::Object^  sender, System::EventArgs^  e) {



	
	player->Play();

	// Creamos la instancia de nuestro constrolador
	arrowController = new ArrowsController();
	
	
	if (txtUser->Text == "") {
		MessageBox::Show("Agregar un usuario");
		
	}
	else {
		msclr::interop::marshal_context context;
		string c_user = context.marshal_as<string>(txtUser->Text);

		this->arrowController->addUser(c_user);
		this->txtUser->Enabled = false;
		this->btnJugar->Enabled = false;
		timerGame->Enabled = true;
		timerArrows->Enabled = true;

		//Escondemos Mensaje Finalizado
		this->lblFinalizar->Visible = false;

		//Reiniciamos el juego en caso que los resultados esten con  datos
		restartGame();
	}

}


		 void restartGame() {
			 this->lblTotalIzquierda->Text = "0";
			 this->lblTotalArriba->Text = "0";
			 this->lblTotalAbajo->Text = "0";
			 this->lblTotalDerecha->Text = "0";

			 this->lblTotalAciertoIzquierda->Text = "0";
			 this->lblTotalAciertoArriba->Text = "0";
			 this->lblTotalAciertoAbajo->Text = "0";
			 this->lblTotalAciertoDerecha->Text = "0";
		 }
};
		 
}
