#pragma once

namespace Ekspresdokawy {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o MainWin
	/// </summary>
	public ref class MainWin : public System::Windows::Forms::Form
	{
	public:
		MainWin(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~MainWin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ PanelPodstaw;
	private: System::Windows::Forms::Button^ btn_Podstawowe;

	private: System::Windows::Forms::Button^ btn_Ulubione;
	private: System::Windows::Forms::Panel^ PanelUlub;
	private: System::Windows::Forms::Button^ Kawa1;
	private: System::Windows::Forms::Button^ Kawa8;


	private: System::Windows::Forms::Button^ Kawa7;

	private: System::Windows::Forms::Button^ Kawa6;

	private: System::Windows::Forms::Button^ Kawa5;

	private: System::Windows::Forms::Button^ Kawa4;

	private: System::Windows::Forms::Button^ Kawa3;

	private: System::Windows::Forms::Button^ Kawa2;
	private: System::Windows::Forms::Button^ Ulub4;

	private: System::Windows::Forms::Button^ Ulub3;

	private: System::Windows::Forms::Button^ Ulub2;

	private: System::Windows::Forms::Button^ Ulub1;






	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainWin::typeid));
			this->PanelPodstaw = (gcnew System::Windows::Forms::Panel());
			this->btn_Podstawowe = (gcnew System::Windows::Forms::Button());
			this->btn_Ulubione = (gcnew System::Windows::Forms::Button());
			this->PanelUlub = (gcnew System::Windows::Forms::Panel());
			this->Kawa1 = (gcnew System::Windows::Forms::Button());
			this->Kawa2 = (gcnew System::Windows::Forms::Button());
			this->Kawa4 = (gcnew System::Windows::Forms::Button());
			this->Kawa3 = (gcnew System::Windows::Forms::Button());
			this->Kawa8 = (gcnew System::Windows::Forms::Button());
			this->Kawa7 = (gcnew System::Windows::Forms::Button());
			this->Kawa6 = (gcnew System::Windows::Forms::Button());
			this->Kawa5 = (gcnew System::Windows::Forms::Button());
			this->Ulub4 = (gcnew System::Windows::Forms::Button());
			this->Ulub3 = (gcnew System::Windows::Forms::Button());
			this->Ulub2 = (gcnew System::Windows::Forms::Button());
			this->Ulub1 = (gcnew System::Windows::Forms::Button());
			this->PanelPodstaw->SuspendLayout();
			this->PanelUlub->SuspendLayout();
			this->SuspendLayout();
			// 
			// PanelPodstaw
			// 
			this->PanelPodstaw->Controls->Add(this->Kawa8);
			this->PanelPodstaw->Controls->Add(this->Kawa7);
			this->PanelPodstaw->Controls->Add(this->Kawa6);
			this->PanelPodstaw->Controls->Add(this->Kawa5);
			this->PanelPodstaw->Controls->Add(this->Kawa4);
			this->PanelPodstaw->Controls->Add(this->Kawa3);
			this->PanelPodstaw->Controls->Add(this->Kawa2);
			this->PanelPodstaw->Controls->Add(this->Kawa1);
			this->PanelPodstaw->Location = System::Drawing::Point(6, 113);
			this->PanelPodstaw->Name = L"PanelPodstaw";
			this->PanelPodstaw->Size = System::Drawing::Size(300, 450);
			this->PanelPodstaw->TabIndex = 0;
			this->PanelPodstaw->Visible = false;
			// 
			// btn_Podstawowe
			// 
			this->btn_Podstawowe->Location = System::Drawing::Point(186, 12);
			this->btn_Podstawowe->Name = L"btn_Podstawowe";
			this->btn_Podstawowe->Size = System::Drawing::Size(120, 80);
			this->btn_Podstawowe->TabIndex = 1;
			this->btn_Podstawowe->Text = L"Podstawowe";
			this->btn_Podstawowe->UseVisualStyleBackColor = true;
			this->btn_Podstawowe->Click += gcnew System::EventHandler(this, &MainWin::btn_Podstawowe_Click);
			// 
			// btn_Ulubione
			// 
			this->btn_Ulubione->Location = System::Drawing::Point(312, 12);
			this->btn_Ulubione->Name = L"btn_Ulubione";
			this->btn_Ulubione->Size = System::Drawing::Size(120, 80);
			this->btn_Ulubione->TabIndex = 2;
			this->btn_Ulubione->Text = L"Ulubione";
			this->btn_Ulubione->UseVisualStyleBackColor = true;
			this->btn_Ulubione->Click += gcnew System::EventHandler(this, &MainWin::btn_Ulubione_Click);
			// 
			// PanelUlub
			// 
			this->PanelUlub->Controls->Add(this->Ulub4);
			this->PanelUlub->Controls->Add(this->Ulub3);
			this->PanelUlub->Controls->Add(this->Ulub2);
			this->PanelUlub->Controls->Add(this->Ulub1);
			this->PanelUlub->Location = System::Drawing::Point(312, 113);
			this->PanelUlub->Name = L"PanelUlub";
			this->PanelUlub->Size = System::Drawing::Size(300, 450);
			this->PanelUlub->TabIndex = 3;
			this->PanelUlub->Visible = false;
			// 
			// Kawa1
			// 
			this->Kawa1->Location = System::Drawing::Point(3, 3);
			this->Kawa1->Name = L"Kawa1";
			this->Kawa1->Size = System::Drawing::Size(150, 50);
			this->Kawa1->TabIndex = 0;
			this->Kawa1->Text = L"Kawa 1";
			this->Kawa1->UseVisualStyleBackColor = true;
			// 
			// Kawa2
			// 
			this->Kawa2->Location = System::Drawing::Point(3, 59);
			this->Kawa2->Name = L"Kawa2";
			this->Kawa2->Size = System::Drawing::Size(150, 50);
			this->Kawa2->TabIndex = 1;
			this->Kawa2->Text = L"Kawa 2";
			this->Kawa2->UseVisualStyleBackColor = true;
			// 
			// Kawa4
			// 
			this->Kawa4->Location = System::Drawing::Point(6, 171);
			this->Kawa4->Name = L"Kawa4";
			this->Kawa4->Size = System::Drawing::Size(150, 50);
			this->Kawa4->TabIndex = 3;
			this->Kawa4->Text = L"Kawa 4";
			this->Kawa4->UseVisualStyleBackColor = true;
			// 
			// Kawa3
			// 
			this->Kawa3->Location = System::Drawing::Point(6, 115);
			this->Kawa3->Name = L"Kawa3";
			this->Kawa3->Size = System::Drawing::Size(150, 50);
			this->Kawa3->TabIndex = 2;
			this->Kawa3->Text = L"Kawa 3";
			this->Kawa3->UseVisualStyleBackColor = true;
			// 
			// Kawa8
			// 
			this->Kawa8->Location = System::Drawing::Point(9, 395);
			this->Kawa8->Name = L"Kawa8";
			this->Kawa8->Size = System::Drawing::Size(150, 50);
			this->Kawa8->TabIndex = 7;
			this->Kawa8->Text = L"Kawa 8";
			this->Kawa8->UseVisualStyleBackColor = true;
			// 
			// Kawa7
			// 
			this->Kawa7->Location = System::Drawing::Point(9, 339);
			this->Kawa7->Name = L"Kawa7";
			this->Kawa7->Size = System::Drawing::Size(150, 50);
			this->Kawa7->TabIndex = 6;
			this->Kawa7->Text = L"Kawa 7";
			this->Kawa7->UseVisualStyleBackColor = true;
			// 
			// Kawa6
			// 
			this->Kawa6->Location = System::Drawing::Point(6, 283);
			this->Kawa6->Name = L"Kawa6";
			this->Kawa6->Size = System::Drawing::Size(150, 50);
			this->Kawa6->TabIndex = 5;
			this->Kawa6->Text = L"Kawa 6";
			this->Kawa6->UseVisualStyleBackColor = true;
			// 
			// Kawa5
			// 
			this->Kawa5->Location = System::Drawing::Point(6, 227);
			this->Kawa5->Name = L"Kawa5";
			this->Kawa5->Size = System::Drawing::Size(150, 50);
			this->Kawa5->TabIndex = 4;
			this->Kawa5->Text = L"Kawa 5";
			this->Kawa5->UseVisualStyleBackColor = true;
			// 
			// Ulub4
			// 
			this->Ulub4->Location = System::Drawing::Point(6, 171);
			this->Ulub4->Name = L"Ulub4";
			this->Ulub4->Size = System::Drawing::Size(150, 50);
			this->Ulub4->TabIndex = 7;
			this->Ulub4->Text = L"Ulub4";
			this->Ulub4->UseVisualStyleBackColor = true;
			// 
			// Ulub3
			// 
			this->Ulub3->Location = System::Drawing::Point(6, 115);
			this->Ulub3->Name = L"Ulub3";
			this->Ulub3->Size = System::Drawing::Size(150, 50);
			this->Ulub3->TabIndex = 6;
			this->Ulub3->Text = L"Ulub3";
			this->Ulub3->UseVisualStyleBackColor = true;
			// 
			// Ulub2
			// 
			this->Ulub2->Location = System::Drawing::Point(3, 59);
			this->Ulub2->Name = L"Ulub2";
			this->Ulub2->Size = System::Drawing::Size(150, 50);
			this->Ulub2->TabIndex = 5;
			this->Ulub2->Text = L"Ulub1";
			this->Ulub2->UseVisualStyleBackColor = true;
			// 
			// Ulub1
			// 
			this->Ulub1->Location = System::Drawing::Point(3, 3);
			this->Ulub1->Name = L"Ulub1";
			this->Ulub1->Size = System::Drawing::Size(150, 50);
			this->Ulub1->TabIndex = 4;
			this->Ulub1->Text = L"Ulub1";
			this->Ulub1->UseVisualStyleBackColor = true;
			// 
			// MainWin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(623, 570);
			this->Controls->Add(this->PanelUlub);
			this->Controls->Add(this->btn_Ulubione);
			this->Controls->Add(this->btn_Podstawowe);
			this->Controls->Add(this->PanelPodstaw);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MainWin";
			this->Text = L"Ekspres do kawy";
			this->Load += gcnew System::EventHandler(this, &MainWin::MainWin_Load);
			this->PanelPodstaw->ResumeLayout(false);
			this->PanelUlub->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MainWin_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	

	private: System::Void btn_Podstawowe_Click(System::Object^ sender, System::EventArgs^ e) {

	}

	private: System::Void btn_Ulubione_Click(System::Object^ sender, System::EventArgs^ e) {

	}

};
}
