#pragma once

#include <string>
#include <vector>

#include "TCoffee.h"
#include "CoffeeManager.h"

#include <msclr/marshal_cppstd.h>

using namespace System::IO;

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

			PanelPodstaw->Visible = true;
			PanelUlub->Visible = false;

			pokazujeUlubione = false;

			btn_Podstawowe->BackColor = System::Drawing::Color::SaddleBrown;
			btn_Podstawowe->ForeColor = System::Drawing::Color::White;

			btn_Ulubione->BackColor = System::Drawing::SystemColors::Control;
			btn_Ulubione->ForeColor = System::Drawing::Color::Black;

			GenerujPrzyciskiKaw();
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

		System::Windows::Forms::Panel^ PanelEdycji;

		System::Windows::Forms::Label^ lbl_TytulEdycji;
		System::Windows::Forms::Label^ lbl_Nazwa;
		System::Windows::Forms::Label^ lbl_Woda;
		System::Windows::Forms::Label^ lbl_Kawa;
		System::Windows::Forms::Label^ lbl_Mleko;

		System::Windows::Forms::TextBox^ txt_Nazwa;
		System::Windows::Forms::NumericUpDown^ num_Woda;
		System::Windows::Forms::NumericUpDown^ num_Kawa;
		System::Windows::Forms::NumericUpDown^ num_Mleko;

		System::Windows::Forms::Button^ btn_ZapiszEdycje;
		System::Windows::Forms::Button^ btn_AnulujEdycje;
		System::Windows::Forms::Button^ btn_ZaparzEdycje;

	private:
		System::ComponentModel::Container^ components;

	private:
		std::vector<TCoffee>* default_coffees_vector;
		std::vector<TCoffee>* favourite_coffees_vector;
		bool pokazujeUlubione;
		int edytowanyIndeks = -1;
		bool edytujeUlubiona = false;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources =
				(gcnew System::ComponentModel::ComponentResourceManager(MainWin::typeid));

			this->PanelPodstaw = (gcnew System::Windows::Forms::Panel());
			this->btn_Podstawowe = (gcnew System::Windows::Forms::Button());
			this->btn_Ulubione = (gcnew System::Windows::Forms::Button());
			this->PanelUlub = (gcnew System::Windows::Forms::Panel());

			this->PanelEdycji = (gcnew System::Windows::Forms::Panel());

			this->lbl_TytulEdycji = (gcnew System::Windows::Forms::Label());
			this->lbl_Nazwa = (gcnew System::Windows::Forms::Label());
			this->lbl_Woda = (gcnew System::Windows::Forms::Label());
			this->lbl_Kawa = (gcnew System::Windows::Forms::Label());
			this->lbl_Mleko = (gcnew System::Windows::Forms::Label());

			this->txt_Nazwa = (gcnew System::Windows::Forms::TextBox());
			this->num_Woda = (gcnew System::Windows::Forms::NumericUpDown());
			this->num_Kawa = (gcnew System::Windows::Forms::NumericUpDown());
			this->num_Mleko = (gcnew System::Windows::Forms::NumericUpDown());

			this->btn_ZapiszEdycje = (gcnew System::Windows::Forms::Button());
			this->btn_AnulujEdycje = (gcnew System::Windows::Forms::Button());
			this->btn_ZaparzEdycje = (gcnew System::Windows::Forms::Button());

			this->SuspendLayout();

			// 
			// PanelPodstaw
			// 
			this->PanelPodstaw->AutoScroll = true;
			this->PanelPodstaw->Location = System::Drawing::Point(4, 92);
			this->PanelPodstaw->Margin = System::Windows::Forms::Padding(2);
			this->PanelPodstaw->Name = L"PanelPodstaw";
			this->PanelPodstaw->Size = System::Drawing::Size(280, 366);
			this->PanelPodstaw->TabIndex = 0;
			this->PanelPodstaw->Visible = true;

			this->PanelPodstaw->Anchor =
				static_cast<System::Windows::Forms::AnchorStyles>(
					System::Windows::Forms::AnchorStyles::Top |
					System::Windows::Forms::AnchorStyles::Bottom |
					System::Windows::Forms::AnchorStyles::Left
					);

			// 
			// btn_Podstawowe
			// 
			this->btn_Podstawowe->Location = System::Drawing::Point(140, 10);
			this->btn_Podstawowe->Margin = System::Windows::Forms::Padding(2);
			this->btn_Podstawowe->Name = L"btn_Podstawowe";
			this->btn_Podstawowe->Size = System::Drawing::Size(90, 65);
			this->btn_Podstawowe->TabIndex = 1;
			this->btn_Podstawowe->Text = L"Podstawowe";
			this->btn_Podstawowe->UseVisualStyleBackColor = false;
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
			this->btn_Ulubione->UseVisualStyleBackColor = false;
			this->btn_Ulubione->Click +=
				gcnew System::EventHandler(this, &MainWin::btn_Ulubione_Click);

			// 
			// PanelUlub
			// Zostawiamy panel w projekcie, ale nie używamy go do wyświetlania kaw.
			// 
			this->PanelUlub->AutoScroll = true;
			this->PanelUlub->Location = System::Drawing::Point(4, 92);
			this->PanelUlub->Margin = System::Windows::Forms::Padding(2);
			this->PanelUlub->Name = L"PanelUlub";
			this->PanelPodstaw->Size = System::Drawing::Size(280, 366);
			this->PanelUlub->TabIndex = 3;
			this->PanelUlub->Visible = false;
			// 
// PanelEdycji
// 
			this->PanelEdycji->Location = System::Drawing::Point(300, 92);
			this->PanelEdycji->Margin = System::Windows::Forms::Padding(2);
			this->PanelEdycji->Name = L"PanelEdycji";
			this->PanelEdycji->Size = System::Drawing::Size(240, 366);
			this->PanelEdycji->TabIndex = 4;
			this->PanelEdycji->Visible = false;
			this->PanelEdycji->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;

			// 
			// lbl_TytulEdycji
			// 
			this->lbl_TytulEdycji->Text = L"Personalizacja kawy";
			this->lbl_TytulEdycji->Location = System::Drawing::Point(15, 15);
			this->lbl_TytulEdycji->Size = System::Drawing::Size(200, 25);
			this->lbl_TytulEdycji->Font = gcnew System::Drawing::Font(
				this->lbl_TytulEdycji->Font,
				System::Drawing::FontStyle::Bold
			);

			// 
			// lbl_Nazwa
			// 
			this->lbl_Nazwa->Text = L"Nazwa:";
			this->lbl_Nazwa->Location = System::Drawing::Point(15, 55);
			this->lbl_Nazwa->Size = System::Drawing::Size(80, 20);

			// 
			// txt_Nazwa
			// 
			this->txt_Nazwa->Location = System::Drawing::Point(100, 55);
			this->txt_Nazwa->Size = System::Drawing::Size(120, 20);

			// 
			// lbl_Woda
			// 
			this->lbl_Woda->Text = L"Woda [ml]:";
			this->lbl_Woda->Location = System::Drawing::Point(15, 95);
			this->lbl_Woda->Size = System::Drawing::Size(80, 20);

			// 
			// num_Woda
			// 
			this->num_Woda->Location = System::Drawing::Point(100, 95);
			this->num_Woda->Size = System::Drawing::Size(120, 20);
			this->num_Woda->Minimum = 0;
			this->num_Woda->Maximum = 1000;

			// 
			// lbl_Kawa
			// 
			this->lbl_Kawa->Text = L"Kawa [g]:";
			this->lbl_Kawa->Location = System::Drawing::Point(15, 135);
			this->lbl_Kawa->Size = System::Drawing::Size(80, 20);

			// 
			// num_Kawa
			// 
			this->num_Kawa->Location = System::Drawing::Point(100, 135);
			this->num_Kawa->Size = System::Drawing::Size(120, 20);
			this->num_Kawa->Minimum = 0;
			this->num_Kawa->Maximum = 100;

			// 
			// lbl_Mleko
			// 
			this->lbl_Mleko->Text = L"Mleko [ml]:";
			this->lbl_Mleko->Location = System::Drawing::Point(15, 175);
			this->lbl_Mleko->Size = System::Drawing::Size(80, 20);

			// 
			// num_Mleko
			// 
			this->num_Mleko->Location = System::Drawing::Point(100, 175);
			this->num_Mleko->Size = System::Drawing::Size(120, 20);
			this->num_Mleko->Minimum = 0;
			this->num_Mleko->Maximum = 1000;

			// 
			// btn_ZapiszEdycje
			// 
			this->btn_ZapiszEdycje->Text = L"Zapisz";
			this->btn_ZapiszEdycje->Location = System::Drawing::Point(25, 230);
			this->btn_ZapiszEdycje->Size = System::Drawing::Size(85, 35);
			this->btn_ZapiszEdycje->Click +=
				gcnew System::EventHandler(this, &MainWin::btn_ZapiszEdycje_Click);

			this->AcceptButton = this->btn_ZapiszEdycje;
			// 
			// btn_AnulujEdycje
			// 
			this->btn_AnulujEdycje->Text = L"Anuluj";
			this->btn_AnulujEdycje->Location = System::Drawing::Point(125, 230);
			this->btn_AnulujEdycje->Size = System::Drawing::Size(85, 35);
			this->btn_AnulujEdycje->Click +=
				gcnew System::EventHandler(this, &MainWin::btn_AnulujEdycje_Click);

			this->PanelEdycji->Controls->Add(this->lbl_TytulEdycji);
			this->PanelEdycji->Controls->Add(this->lbl_Nazwa);
			this->PanelEdycji->Controls->Add(this->txt_Nazwa);
			this->PanelEdycji->Controls->Add(this->lbl_Woda);
			this->PanelEdycji->Controls->Add(this->num_Woda);
			this->PanelEdycji->Controls->Add(this->lbl_Kawa);
			this->PanelEdycji->Controls->Add(this->num_Kawa);
			this->PanelEdycji->Controls->Add(this->lbl_Mleko);
			this->PanelEdycji->Controls->Add(this->num_Mleko);
			
			// 
			// btn_ZaparzEdycje
			// 
			this->btn_ZaparzEdycje->Text = L"Zaparz";
			this->btn_ZaparzEdycje->Location = System::Drawing::Point(75, 280);
			this->btn_ZaparzEdycje->Size = System::Drawing::Size(85, 35);
			this->btn_ZaparzEdycje->Click +=
				gcnew System::EventHandler(this, &MainWin::btn_ZaparzEdycje_Click);
			this->PanelEdycji->Controls->Add(this->btn_ZapiszEdycje);
			this->PanelEdycji->Controls->Add(this->btn_AnulujEdycje);
			this->PanelEdycji->Controls->Add(this->btn_ZaparzEdycje);
				// 
				// MainWin
				// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(560, 463);

			this->Controls->Add(this->PanelEdycji);
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

			pokazujeUlubione = false;

			btn_Podstawowe->BackColor = System::Drawing::Color::SaddleBrown;
			btn_Podstawowe->ForeColor = System::Drawing::Color::White;

			btn_Ulubione->BackColor = System::Drawing::SystemColors::Control;
			btn_Ulubione->ForeColor = System::Drawing::Color::Black;

			GenerujPrzyciskiKaw();
			PanelEdycji->Visible = false;
			edytowanyIndeks = -1;
		}
	private:
		System::Void btn_Ulubione_Click(System::Object^ sender, System::EventArgs^ e)
		{
			PanelPodstaw->Visible = true;
			PanelUlub->Visible = false;

			pokazujeUlubione = true;

			btn_Ulubione->BackColor = System::Drawing::Color::SaddleBrown;
			btn_Ulubione->ForeColor = System::Drawing::Color::White;

			btn_Podstawowe->BackColor = System::Drawing::SystemColors::Control;
			btn_Podstawowe->ForeColor = System::Drawing::Color::Black;

			GenerujPrzyciskiUlubionychKaw();

			PanelEdycji->Visible = false;
			edytowanyIndeks = -1;
		}

	private:
		void GenerujPrzyciskiKaw()
		{
			PanelPodstaw->Controls->Clear();

			int pozycjaY = 10;
			int odstep = 55;

			for (size_t i = 0; i < default_coffees_vector->size(); i++)
			{
				Button^ przyciskKawy = gcnew Button();

				std::string nazwaKawy = (*default_coffees_vector)[i].getName();

				przyciskKawy->Text = gcnew String(nazwaKawy.c_str());
				przyciskKawy->Size = System::Drawing::Size(130, 50);
				przyciskKawy->Location = System::Drawing::Point(10, pozycjaY);
				przyciskKawy->Tag = (int)i;

				przyciskKawy->Click +=
					gcnew System::EventHandler(this, &MainWin::KliknietoKawa_Click);

				PanelPodstaw->Controls->Add(przyciskKawy);

				Button^ przyciskEdycji = gcnew Button();

				przyciskEdycji->Text = L"⚙";
				przyciskEdycji->Image = nullptr;
				przyciskEdycji->Font = gcnew System::Drawing::Font(
					L"Segoe UI Symbol",
					18,
					System::Drawing::FontStyle::Regular
				);
				przyciskEdycji->TextAlign = ContentAlignment::MiddleCenter;

				przyciskEdycji->Size = System::Drawing::Size(70, 50);
				przyciskEdycji->Location = System::Drawing::Point(145, pozycjaY);
				przyciskEdycji->Tag = (int)i;

				przyciskEdycji->Click +=
					gcnew System::EventHandler(this, &MainWin::KliknietoEdytujKawe_Click);

				PanelPodstaw->Controls->Add(przyciskEdycji);

				pozycjaY += odstep;
			}
		}

	private:
	private:
	private:
		void GenerujPrzyciskiUlubionychKaw()
		{
			PanelPodstaw->Controls->Clear();

			int pozycjaY = 10;
			int odstep = 55;

			for (size_t i = 0; i < favourite_coffees_vector->size(); i++)
			{
				Button^ przyciskKawy = gcnew Button();

				std::string nazwaKawy = (*favourite_coffees_vector)[i].getName();

				przyciskKawy->Text = gcnew String(nazwaKawy.c_str());
				przyciskKawy->Size = System::Drawing::Size(115, 50);
				przyciskKawy->Location = System::Drawing::Point(10, pozycjaY);
				przyciskKawy->Tag = (int)i;

				przyciskKawy->Click +=
					gcnew System::EventHandler(this, &MainWin::KliknietoUlubionaKawa_Click);

				PanelPodstaw->Controls->Add(przyciskKawy);


				Button^ przyciskEdycji = gcnew Button();

				przyciskEdycji->Text = L"⚙";
				przyciskEdycji->Image = nullptr;
				przyciskEdycji->Font = gcnew System::Drawing::Font(
					L"Segoe UI Symbol",
					18,
					System::Drawing::FontStyle::Regular
				);
				przyciskEdycji->TextAlign = ContentAlignment::MiddleCenter;

				przyciskEdycji->Size = System::Drawing::Size(45, 50);
				przyciskEdycji->Location = System::Drawing::Point(130, pozycjaY);
				przyciskEdycji->Tag = (int)i;

				przyciskEdycji->Click +=
					gcnew System::EventHandler(this, &MainWin::KliknietoEdytujKawe_Click);

				PanelPodstaw->Controls->Add(przyciskEdycji);


				Button^ przyciskUsun = gcnew Button();

				przyciskUsun->Text = L"X";
				przyciskUsun->Font = gcnew System::Drawing::Font(
					L"Segoe UI",
					14,
					System::Drawing::FontStyle::Bold
				);
				przyciskUsun->TextAlign = ContentAlignment::MiddleCenter;

				przyciskUsun->Size = System::Drawing::Size(45, 50);
				przyciskUsun->Location = System::Drawing::Point(180, pozycjaY);
				przyciskUsun->Tag = (int)i;

				przyciskUsun->Click +=
					gcnew System::EventHandler(this, &MainWin::KliknietoUsunUlubionaKawe_Click);

				PanelPodstaw->Controls->Add(przyciskUsun);

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
					"Błąd: Nie znaleziono danych dla tej kawy!",
					"Błąd",
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
					"Błąd: Nie znaleziono danych dla tej kawy!",
					"Błąd",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error
				);
			}
		}

	private:
		System::Void KliknietoEdytujKawe_Click(System::Object^ sender, System::EventArgs^ e)
		{
			Button^ kliknietyPrzycisk = safe_cast<Button^>(sender);

			int indeksKawy = Convert::ToInt32(kliknietyPrzycisk->Tag);

			std::vector<TCoffee>* aktualnyWektor = nullptr;

			if (pokazujeUlubione)
			{
				aktualnyWektor = favourite_coffees_vector;
				edytujeUlubiona = true;
			}
			else
			{
				aktualnyWektor = default_coffees_vector;
				edytujeUlubiona = false;
			}

			if (aktualnyWektor != nullptr &&
				indeksKawy >= 0 &&
				indeksKawy < static_cast<int>(aktualnyWektor->size()))
			{
				edytowanyIndeks = indeksKawy;

				TCoffee wybranaKawa = (*aktualnyWektor)[indeksKawy];

				txt_Nazwa->Text = gcnew String(wybranaKawa.getName().c_str());
				num_Woda->Value = wybranaKawa.getWaterAmount();
				num_Kawa->Value = wybranaKawa.getCoffeeAmount();
				num_Mleko->Value = wybranaKawa.getMilkAmount();

				PanelEdycji->Visible = true;
			}
			else
			{
				MessageBox::Show(
					"Błąd: Nie znaleziono danych dla tej kawy!",
					"Błąd",
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
				info = "Parzę ulubioną kawę: ";
			}
			else
			{
				info = "Parzę: ";
			}

			info += wybranaKawa.getName() +
				"\nWoda: " + std::to_string(wybranaKawa.getWaterAmount()) + " ml" +
				"\nKawa: " + std::to_string(wybranaKawa.getCoffeeAmount()) + " g" +
				"\nMleko: " + std::to_string(wybranaKawa.getMilkAmount()) + " ml";

			String^ komunikat = gcnew String(info.c_str());

			MessageBox::Show(komunikat, "Ekspres do kawy");
		}
	private:
		System::Void btn_ZapiszEdycje_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (edytowanyIndeks < 0)
			{
				MessageBox::Show(
					"Nie wybrano kawy do edycji.",
					"Błąd",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error
				);
				return;
			}

			std::string nowaNazwa =
				msclr::interop::marshal_as<std::string>(txt_Nazwa->Text);

			int nowaWoda = Decimal::ToInt32(num_Woda->Value);
			int nowaKawa = Decimal::ToInt32(num_Kawa->Value);
			int noweMleko = Decimal::ToInt32(num_Mleko->Value);

			for (size_t i = 0; i < favourite_coffees_vector->size(); i++)
			{
				if ((*favourite_coffees_vector)[i].getName() == nowaNazwa)
				{
					MessageBox::Show(
						"Kawa o takiej nazwie już istnieje w ulubionych.",
						"Błąd",
						MessageBoxButtons::OK,
						MessageBoxIcon::Warning
					);
					return;
				}
			}

			TCoffee nowaKawaObiekt(nowaNazwa, nowaWoda, nowaKawa, noweMleko);

			favourite_coffees_vector->push_back(nowaKawaObiekt);


			CoffeeManager::saveVector("favourite_coffees.txt", *favourite_coffees_vector);


			btn_Ulubione_Click(nullptr, nullptr);
		}
	private:
		System::Void btn_AnulujEdycje_Click(System::Object^ sender, System::EventArgs^ e)
		{
			PanelEdycji->Visible = false;
			edytowanyIndeks = -1;
		}
	private:
		System::Void KliknietoUsunUlubionaKawe_Click(System::Object^ sender, System::EventArgs^ e)
		{
			Button^ kliknietyPrzycisk = safe_cast<Button^>(sender);

			int indeksKawy = Convert::ToInt32(kliknietyPrzycisk->Tag);

			TCoffee usuwanaKawa = (*favourite_coffees_vector)[indeksKawy];

			String^ komunikat = gcnew String(
				("Czy na pewno chcesz usunąć kawę \"" + usuwanaKawa.getName() + "\" z ulubionych?").c_str()
			);

			bool usunieto = CoffeeManager::removeCoffeeByName(
				"favourite_coffees.txt",
				*favourite_coffees_vector,
				usuwanaKawa.getName()
			);

			if (!usunieto)
			{
				MessageBox::Show(
					"Nie udało się usunąć kawy.",
					"Błąd",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error
				);
				return;
			}

			PanelEdycji->Visible = false;
			edytowanyIndeks = -1;

			GenerujPrzyciskiUlubionychKaw();

		}
		private:
			System::Void btn_ZaparzEdycje_Click(System::Object^ sender, System::EventArgs^ e)
			{
				std::string nazwa =
					msclr::interop::marshal_as<std::string>(txt_Nazwa->Text);

				int woda = Decimal::ToInt32(num_Woda->Value);
				int kawa = Decimal::ToInt32(num_Kawa->Value);
				int mleko = Decimal::ToInt32(num_Mleko->Value);

				TCoffee kawaDoZaparzenia(nazwa, woda, kawa, mleko);

				PokazInformacjeOKawie(kawaDoZaparzenia, false);
			}
	};

}