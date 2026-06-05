#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "TCoffee.h"


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
			default_coffees_vector = new std::vector<TCoffee>();
			readFile("default_coffees.txt", *default_coffees_vector);

			// Generujemy przyciski dynamicznie na podstawie zawartoœci pliku
			GenerujPrzyciskiKaw();
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
			this->SuspendLayout();
			// 
			// PanelPodstaw
			// 
			this->PanelPodstaw->AutoScroll = true;
			this->PanelPodstaw->Location = System::Drawing::Point(4, 92);
			this->PanelPodstaw->Margin = System::Windows::Forms::Padding(2);
			this->PanelPodstaw->Name = L"PanelPodstaw";
			this->PanelPodstaw->Size = System::Drawing::Size(225, 366);
			this->PanelPodstaw->TabIndex = 0;
			this->PanelPodstaw->Visible = false;
			// 
			// btn_Podstawowe
			// 
			this->btn_Podstawowe->Location = System::Drawing::Point(140, 10);
			this->btn_Podstawowe->Margin = System::Windows::Forms::Padding(2);
			this->btn_Podstawowe->Name = L"btn_Podstawowe";
			this->btn_Podstawowe->Size = System::Drawing::Size(90, 65);
			this->btn_Podstawowe->TabIndex = 1;
			this->btn_Podstawowe->Text = L"Podstawowe";
			this->btn_Podstawowe->UseVisualStyleBackColor = true;
			this->btn_Podstawowe->Click += gcnew System::EventHandler(this, &MainWin::btn_Podstawowe_Click);
			// 
			// btn_Ulubione
			// 
			this->btn_Ulubione->Location = System::Drawing::Point(234, 10);
			this->btn_Ulubione->Margin = System::Windows::Forms::Padding(2);
			this->btn_Ulubione->Name = L"btn_Ulubione";
			this->btn_Ulubione->Size = System::Drawing::Size(90, 65);
			this->btn_Ulubione->TabIndex = 2;
			this->btn_Ulubione->Text = L"Ulubione";
			this->btn_Ulubione->UseVisualStyleBackColor = true;
			this->btn_Ulubione->Click += gcnew System::EventHandler(this, &MainWin::btn_Ulubione_Click);
			// 
			// PanelUlub
			// 
			this->PanelUlub->AutoScroll = true;
			this->PanelUlub->Location = System::Drawing::Point(234, 92);
			this->PanelUlub->Margin = System::Windows::Forms::Padding(2);
			this->PanelUlub->Name = L"PanelUlub";
			this->PanelUlub->Size = System::Drawing::Size(225, 366);
			this->PanelUlub->TabIndex = 3;
			this->PanelUlub->Visible = false;
			// 
			// MainWin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(467, 463);
			this->Controls->Add(this->PanelUlub);
			this->Controls->Add(this->btn_Ulubione);
			this->Controls->Add(this->btn_Podstawowe);
			this->Controls->Add(this->PanelPodstaw);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MainWin";
			this->Text = L"Ekspres do kawy";
			this->Load += gcnew System::EventHandler(this, &MainWin::MainWin_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MainWin_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	

	private: System::Void btn_Podstawowe_Click(System::Object^ sender, System::EventArgs^ e) {
		PanelPodstaw->Visible = true;
		PanelUlub->Visible = false;
	}

	private: System::Void btn_Ulubione_Click(System::Object^ sender, System::EventArgs^ e) {
		PanelPodstaw->Visible = false;
		PanelUlub->Visible = true;
	}
		   
		   private: 
			   void readFile(std::string filename, std::vector<TCoffee>& coffe_vector) {
				   std::ifstream plik(filename);

				   std::string linia;

				   while (std::getline(plik, linia)) {
					   std::stringstream ss(linia);

					   std::string name;
					   std::string water_text;
					   std::string coffe_text;
					   std::string milk_text;

					   std::getline(ss, name, ';');
					   std::getline(ss, water_text, ';');
					   std::getline(ss, coffe_text, ';');
					   std::getline(ss, milk_text, ';');

					   int water_amount = std::stoi(water_text);
					   int coffe_amount = std::stoi(coffe_text);
					   int milk_amount = std::stoi(milk_text);

					   TCoffee kawa(name, water_amount, coffe_amount, milk_amount);

					   coffe_vector.push_back(kawa);
				   }
			   }
			   private:
				   std::vector<TCoffee>* default_coffees_vector;
				   std::vector<TCoffee>* favourite_coffees_vector;

				   private:
					   void GenerujPrzyciskiKaw() {
						   PanelPodstaw->Controls->Clear();

						   int pozycjaY = 10; 
						   int odstep = 55;   

						   for (size_t i = 0; i < default_coffees_vector->size(); i++) {
							
							   Button^ nowyPrzycisk = gcnew Button();

							   std::string nazwaKawy = (*default_coffees_vector)[i].getName();
							   nowyPrzycisk->Text = gcnew String(nazwaKawy.c_str());
							   nowyPrzycisk->Size = System::Drawing::Size(150, 50);
							   nowyPrzycisk->Location = System::Drawing::Point(10, pozycjaY);
							   nowyPrzycisk->Tag = i;
							   nowyPrzycisk->Click += gcnew System::EventHandler(this, &MainWin::KliknietoKawa_Click);

							   PanelPodstaw->Controls->Add(nowyPrzycisk);

							
							   pozycjaY += odstep;
						   }
					   }

					private: System::Void KliknietoKawa_Click(System::Object^ sender, System::EventArgs^ e) {
					
						Button^ kliknietyPrzycisk = safe_cast<Button^>(sender);

					
						int indeksKawy = Convert::ToInt32(kliknietyPrzycisk->Tag);

		
						if (default_coffees_vector != nullptr && indeksKawy < (int)default_coffees_vector->size()) {

							TCoffee wybranaKawa = (*default_coffees_vector)[indeksKawy];

							std::string info = "Parzê: " + wybranaKawa.getName() +
								"\nWoda: " + std::to_string(wybranaKawa.getWaterAmount()) + "ml" +
								"\nKawa: " + std::to_string(wybranaKawa.getCoffeeAmount()) + "g" +
								"\nMleko: " + std::to_string(wybranaKawa.getMilkAmount()) + "ml";
							String^ komunikat = gcnew String(info.c_str());
							MessageBox::Show(komunikat, "Ekspres do kawy");
						}
						else {
							MessageBox::Show("B³¹d: Nie znaleziono danych dla tej kawy!", "B³¹d", MessageBoxButtons::OK, MessageBoxIcon::Error);
						}
					}
};
}
