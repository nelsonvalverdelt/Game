#pragma once

#include "UIGame.h"
namespace GameViews {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de User
	/// </summary>
	public ref class User : public System::Windows::Forms::Form
	{
	public:
		User(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~User()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  lblTitle;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Panel^  panelLogin;
	private: System::Windows::Forms::TextBox^  txtContrasena;
	private: System::Windows::Forms::TextBox^  txtUser;
	private: System::Windows::Forms::Button^  btnLogin;
	private: System::Windows::Forms::Button^  btnSalir;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panelLogin = (gcnew System::Windows::Forms::Panel());
			this->txtUser = (gcnew System::Windows::Forms::TextBox());
			this->txtContrasena = (gcnew System::Windows::Forms::TextBox());
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->panelLogin->SuspendLayout();
			this->SuspendLayout();
			// 
			// lblTitle
			// 
			this->lblTitle->AutoSize = true;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Bauhaus 93", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTitle->ForeColor = System::Drawing::Color::White;
			this->lblTitle->Location = System::Drawing::Point(137, 26);
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->Size = System::Drawing::Size(281, 50);
			this->lblTitle->TabIndex = 0;
			this->lblTitle->Text = L"DAN C GAME";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(64, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(125, 38);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Usuario:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(26, 92);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(172, 38);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Contraseña:";
			// 
			// panelLogin
			// 
			this->panelLogin->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panelLogin->Controls->Add(this->txtContrasena);
			this->panelLogin->Controls->Add(this->txtUser);
			this->panelLogin->Controls->Add(this->label1);
			this->panelLogin->Controls->Add(this->label2);
			this->panelLogin->Location = System::Drawing::Point(57, 94);
			this->panelLogin->Name = L"panelLogin";
			this->panelLogin->Size = System::Drawing::Size(439, 157);
			this->panelLogin->TabIndex = 3;
			// 
			// txtUser
			// 
			this->txtUser->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtUser->Location = System::Drawing::Point(214, 23);
			this->txtUser->Name = L"txtUser";
			this->txtUser->Size = System::Drawing::Size(194, 38);
			this->txtUser->TabIndex = 3;
			// 
			// txtContrasena
			// 
			this->txtContrasena->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtContrasena->Location = System::Drawing::Point(214, 92);
			this->txtContrasena->Name = L"txtContrasena";
			this->txtContrasena->PasswordChar = '*';
			this->txtContrasena->Size = System::Drawing::Size(194, 38);
			this->txtContrasena->TabIndex = 4;
			// 
			// btnLogin
			// 
			this->btnLogin->BackColor = System::Drawing::Color::White;
			this->btnLogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnLogin->Location = System::Drawing::Point(90, 277);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(137, 45);
			this->btnLogin->TabIndex = 4;
			this->btnLogin->Text = L"Ingresar";
			this->btnLogin->UseVisualStyleBackColor = false;
			this->btnLogin->Click += gcnew System::EventHandler(this, &User::btnLogin_Click);
			// 
			// btnSalir
			// 
			this->btnSalir->BackColor = System::Drawing::Color::White;
			this->btnSalir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSalir->Location = System::Drawing::Point(315, 277);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(137, 45);
			this->btnSalir->TabIndex = 5;
			this->btnSalir->Text = L"Salir";
			this->btnSalir->UseVisualStyleBackColor = false;
			// 
			// User
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(571, 345);
			this->Controls->Add(this->btnSalir);
			this->Controls->Add(this->btnLogin);
			this->Controls->Add(this->panelLogin);
			this->Controls->Add(this->lblTitle);
			this->MaximizeBox = false;
			this->Name = L"User";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"User";
			this->panelLogin->ResumeLayout(false);
			this->panelLogin->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnLogin_Click(System::Object^  sender, System::EventArgs^  e) {

		//if (txtUser->Text == "" && txtContrasena->Text == "") {
			UIGame^ game = gcnew UIGame();
			User^ user = gcnew User();
			game->Show();
			this->Hide();


			
		//}


	}
};
}
