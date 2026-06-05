#pragma once

#include <string>
#include <vector>

#include "TCoffee.h"
#include "CoffeeManager.h"

namespace Ekspresdokawy {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MainWin : public System::Windows::Forms::Form
	{
	public:
		MainWin(void)
		{
			InitializeComponent();

			default_coffees_vector = new std::vector<TCoffee>();
			favourite_coffees_vector = new std::vector<TCoffee>();

			CoffeeManager::ensureDefaultCoffeeFileExists("default_coffees.txt");
			CoffeeManager::readFile("default_coffees.txt", *default_coffees_vector);

			CoffeeManager::ensureFavouriteCoffeeFileExists("favourite_coffees.txt");
			CoffeeManager::readFile("favourite_coffees.txt", *favourite_coffees_vector);

			GenerujPrzyciskiKaw();
			GenerujPrzyciskiUlubionychKaw();
		}

	protected:
		~MainWin()
		{
			if (components)
			{
				delete components;
			}

			if (default_coffees_vector != nullptr)
			{
				delete default_coffees_vector;
				default_coffees_vector = nullptr;
			}

			if (favourite_coffees_vector != nullptr)
			{
				delete favourite_coffees_vector;
				favourite_coffees_vector = nullptr;
			}
		}

	private:
		System::Windows::Forms::Panel^ PanelPodstaw;
		System::Windows::Forms::Button^ btn_Podstawowe;
		System::Windows::Forms::Button^ btn_Ulubione;
		System::Windows::Forms::Panel^ PanelUlub;

	private:
		System::ComponentModel::Container^ components;

	private:
		std::vector<TCoffee>* default_coffees_vector;
		std::vector<TCoffee>* favourite_coffees_vector;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources =
				(gcnew System::ComponentModel::ComponentResourceManager(MainWin::typeid));

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
			this->btn_Podstawowe->Click +=
				gcnew System::EventHandler(this, &MainWin::btn_Podstawowe_Click);

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
			this->btn_Ulubione->Click +=
				gcnew System::EventHandler(this, &MainWin::btn_Ulubione_Click);

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

			this->Icon =
				(cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));

			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MainWin";
			this->Text = L"Ekspres do kawy";
			this->Load += gcnew System::EventHandler(this, &MainWin::MainWin_Load);

			this->ResumeLayout(false);
		}

#pragma endregion

	private:
		System::Void MainWin_Load(System::Object^ sender, System::EventArgs^ e)
		{
		}

	private:
		System::Void btn_Podstawowe_Click(System::Object^ sender, System::EventArgs^ e)
		{
			PanelPodstaw->Visible = true;
			PanelUlub->Visible = false;
		}

	private:
		System::Void btn_Ulubione_Click(System::Object^ sender, System::EventArgs^ e)
		{
			PanelPodstaw->Visible = false;
			PanelUlub->Visible = true;
		}

	private:
		void GenerujPrzyciskiKaw()
		{
			PanelPodstaw->Controls->Clear();

			int pozycjaY = 10;
			int odstep = 55;

			for (size_t i = 0; i < default_coffees_vector->size(); i++)
			{
				Button^ nowyPrzycisk = gcnew Button();

				std::string nazwaKawy = (*default_coffees_vector)[i].getName();

				nowyPrzycisk->Text = gcnew String(nazwaKawy.c_str());
				nowyPrzycisk->Size = System::Drawing::Size(150, 50);
				nowyPrzycisk->Location = System::Drawing::Point(10, pozycjaY);
				nowyPrzycisk->Tag = (int)i;

				nowyPrzycisk->Click +=
					gcnew System::EventHandler(this, &MainWin::KliknietoKawa_Click);

				PanelPodstaw->Controls->Add(nowyPrzycisk);

				pozycjaY += odstep;
			}
		}

	private:
		void GenerujPrzyciskiUlubionychKaw()
		{
			PanelUlub->Controls->Clear();

			int pozycjaY = 10;
			int odstep = 55;

			for (size_t i = 0; i < favourite_coffees_vector->size(); i++)
			{
				Button^ nowyPrzycisk = gcnew Button();

				std::string nazwaKawy = (*favourite_coffees_vector)[i].getName();

				nowyPrzycisk->Text = gcnew String(nazwaKawy.c_str());
				nowyPrzycisk->Size = System::Drawing::Size(150, 50);
				nowyPrzycisk->Location = System::Drawing::Point(10, pozycjaY);
				nowyPrzycisk->Tag = (int)i;

				nowyPrzycisk->Click +=
					gcnew System::EventHandler(this, &MainWin::KliknietoUlubionaKawa_Click);

				PanelUlub->Controls->Add(nowyPrzycisk);

				pozycjaY += odstep;
			}
		}

	private:
		System::Void KliknietoKawa_Click(System::Object^ sender, System::EventArgs^ e)
		{
			Button^ kliknietyPrzycisk = safe_cast<Button^>(sender);

			int indeksKawy = Convert::ToInt32(kliknietyPrzycisk->Tag);

			if (default_coffees_vector != nullptr &&
				indeksKawy >= 0 &&
				indeksKawy < static_cast<int>(default_coffees_vector->size()))
			{
				TCoffee wybranaKawa = (*default_coffees_vector)[indeksKawy];

				PokazInformacjeOKawie(wybranaKawa, false);
			}
			else
			{
				MessageBox::Show(
					"B³¹d: Nie znaleziono danych dla tej kawy!",
					"B³¹d",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error
				);
			}
		}

	private:
		System::Void KliknietoUlubionaKawa_Click(System::Object^ sender, System::EventArgs^ e)
		{
			Button^ kliknietyPrzycisk = safe_cast<Button^>(sender);

			int indeksKawy = Convert::ToInt32(kliknietyPrzycisk->Tag);

			if (favourite_coffees_vector != nullptr &&
				indeksKawy >= 0 &&
				indeksKawy < static_cast<int>(favourite_coffees_vector->size()))
			{
				TCoffee wybranaKawa = (*favourite_coffees_vector)[indeksKawy];

				PokazInformacjeOKawie(wybranaKawa, true);
			}
			else
			{
				MessageBox::Show(
					"B³¹d: Nie znaleziono danych dla tej kawy!",
					"B³¹d",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error
				);
			}
		}

	private:
		void PokazInformacjeOKawie(const TCoffee& wybranaKawa, bool czyUlubiona)
		{
			std::string info;

			if (czyUlubiona)
			{
				info = "Parzê ulubion¹ kawê: ";
			}
			else
			{
				info = "Parzê: ";
			}

			info += wybranaKawa.getName() +
				"\nWoda: " + std::to_string(wybranaKawa.getWaterAmount()) + " ml" +
				"\nKawa: " + std::to_string(wybranaKawa.getCoffeeAmount()) + " g" +
				"\nMleko: " + std::to_string(wybranaKawa.getMilkAmount()) + " ml";

			String^ komunikat = gcnew String(info.c_str());

			MessageBox::Show(komunikat, "Ekspres do kawy");
		}
	};
}