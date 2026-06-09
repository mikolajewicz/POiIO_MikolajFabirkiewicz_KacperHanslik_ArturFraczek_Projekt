#pragma once

#include <string>
#include <vector>

#include "TCoffee.h"
#include "CoffeeManager.h"
#include "SensorsModule.h" 

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

		
			sensors_backend = new SensorsModule(300, 150);

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

			
			AktualizujStanSerwisu();
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

			if (sensors_backend != nullptr)
			{
				delete sensors_backend;
				sensors_backend = nullptr;
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

		// Deklaracja kontrolek GUI dla modułu serwisowego
		System::Windows::Forms::GroupBox^ grp_PanelSerwisowy;
		System::Windows::Forms::Label^ lbl_StatusCzujnikow;
		System::Windows::Forms::Button^ btn_SerwisWoda;
		System::Windows::Forms::Button^ btn_SerwisZiarna;
		System::Windows::Forms::Button^ btn_SerwisFusy;
		System::Windows::Forms::Button^ btn_PokazSerwis;

	private:
		System::ComponentModel::Container^ components;

	private:
		std::vector<TCoffee>* default_coffees_vector;
		std::vector<TCoffee>* favourite_coffees_vector;

		// Deklaracja wskaźnika do oryginalnej klasy monitorującej
		SensorsModule* sensors_backend;

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

			// Inicjalizacja kontrolek serwisowych
			this->grp_PanelSerwisowy = (gcnew System::Windows::Forms::GroupBox());
			this->lbl_StatusCzujnikow = (gcnew System::Windows::Forms::Label());
			this->btn_SerwisWoda = (gcnew System::Windows::Forms::Button());
			this->btn_SerwisZiarna = (gcnew System::Windows::Forms::Button());
			this->btn_SerwisFusy = (gcnew System::Windows::Forms::Button());

			this->SuspendLayout();

			// PanelPodstaw
			this->PanelPodstaw->AutoScroll = true;
			this->PanelPodstaw->Location = System::Drawing::Point(4, 92);
			this->PanelPodstaw->Margin = System::Windows::Forms::Padding(2);
			this->PanelPodstaw->Name = L"PanelPodstaw";
			this->PanelPodstaw->Size = System::Drawing::Size(280, 240);
			this->PanelPodstaw->TabIndex = 0;

			// btn_Podstawowe
			this->btn_Podstawowe->Location = System::Drawing::Point(10, 10);
			this->btn_Podstawowe->Margin = System::Windows::Forms::Padding(2);
			this->btn_Podstawowe->Name = L"btn_Podstawowe";
			this->btn_Podstawowe->Size = System::Drawing::Size(130, 65);
			this->btn_Podstawowe->TabIndex = 1;
			this->btn_Podstawowe->Text = L"Podstawowe";
			this->btn_Podstawowe->Click += gcnew System::EventHandler(this, &MainWin::btn_Podstawowe_Click);

			// btn_Ulubione
			this->btn_Ulubione->Location = System::Drawing::Point(150, 10);
			this->btn_Ulubione->Margin = System::Windows::Forms::Padding(2);
			this->btn_Ulubione->Name = L"btn_Ulubione";
			this->btn_Ulubione->Size = System::Drawing::Size(130, 65);
			this->btn_Ulubione->TabIndex = 2;
			this->btn_Ulubione->Text = L"Ulubione";
			this->btn_Ulubione->Click += gcnew System::EventHandler(this, &MainWin::btn_Ulubione_Click);

			// PanelEdycji
			this->PanelEdycji->Location = System::Drawing::Point(300, 92);
			this->PanelEdycji->Size = System::Drawing::Size(240, 240);
			this->PanelEdycji->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;

			// lbl_TytulEdycji do num_Mleko (Struktura bez zmian konstrukcyjnych wymiarów)
			this->lbl_TytulEdycji->Text = L"Personalizacja kawy";
			this->lbl_TytulEdycji->Location = System::Drawing::Point(15, 10);
			this->txt_Nazwa->Location = System::Drawing::Point(100, 40);
			this->num_Woda->Location = System::Drawing::Point(100, 70);
			this->num_Kawa->Location = System::Drawing::Point(100, 100);
			this->num_Mleko->Location = System::Drawing::Point(100, 130);
			this->num_Woda->Maximum = 1000;
			this->num_Kawa->Maximum = 100;
			this->num_Mleko->Maximum = 1000;

			this->btn_ZapiszEdycje->Text = L"Zapisz";
			this->btn_ZapiszEdycje->Location = System::Drawing::Point(15, 165);
			this->btn_ZapiszEdycje->Size = System::Drawing::Size(65, 30);
			this->btn_ZapiszEdycje->Click += gcnew System::EventHandler(this, &MainWin::btn_ZapiszEdycje_Click);

			this->btn_AnulujEdycje->Text = L"Anuluj";
			this->btn_AnulujEdycje->Location = System::Drawing::Point(85, 165);
			this->btn_AnulujEdycje->Size = System::Drawing::Size(65, 30);
			this->btn_AnulujEdycje->Click += gcnew System::EventHandler(this, &MainWin::btn_AnulujEdycje_Click);

			this->btn_ZaparzEdycje->Text = L"Zaparz";
			this->btn_ZaparzEdycje->Location = System::Drawing::Point(155, 165);
			this->btn_ZaparzEdycje->Size = System::Drawing::Size(65, 30);
			this->btn_ZaparzEdycje->Click += gcnew System::EventHandler(this, &MainWin::btn_ZaparzEdycje_Click);

			this->PanelEdycji->Controls->Add(this->lbl_TytulEdycji);
			this->PanelEdycji->Controls->Add(this->txt_Nazwa);
			this->PanelEdycji->Controls->Add(this->num_Woda);
			this->PanelEdycji->Controls->Add(this->num_Kawa);
			this->PanelEdycji->Controls->Add(this->num_Mleko);
			this->PanelEdycji->Controls->Add(this->btn_ZapiszEdycje);
			this->PanelEdycji->Controls->Add(this->btn_AnulujEdycje);
			this->PanelEdycji->Controls->Add(this->btn_ZaparzEdycje);

			// Projekt graficzny i pozycjonowanie Panelu Serwisowego na dole okna
			this->grp_PanelSerwisowy->Text = L"Panel Serwisowy / Stan Ekspresu";
			this->grp_PanelSerwisowy->Location = System::Drawing::Point(4, 340);
			this->grp_PanelSerwisowy->Size = System::Drawing::Size(536, 110);

			this->lbl_StatusCzujnikow->Location = System::Drawing::Point(15, 25);
			this->lbl_StatusCzujnikow->Size = System::Drawing::Size(500, 35);
			this->lbl_StatusCzujnikow->Font = gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold);
			this->lbl_StatusCzujnikow->Text = L"Pobieranie danych z SensorsModule...";

			this->btn_SerwisWoda->Text = L"Dolej Wodę";
			this->btn_SerwisWoda->Location = System::Drawing::Point(15, 70);
			this->btn_SerwisWoda->Size = System::Drawing::Size(110, 30);
			this->btn_SerwisWoda->Click += gcnew System::EventHandler(this, &MainWin::btn_SerwisWoda_Click);

			this->btn_SerwisZiarna->Text = L"Dosyp Kawy";
			this->btn_SerwisZiarna->Location = System::Drawing::Point(135, 70);
			this->btn_SerwisZiarna->Size = System::Drawing::Size(110, 30);
			this->btn_SerwisZiarna->Click += gcnew System::EventHandler(this, &MainWin::btn_SerwisZiarna_Click);

			this->btn_SerwisFusy->Text = L"Opróżnij Fusy";
			this->btn_SerwisFusy->Location = System::Drawing::Point(255, 70);
			this->btn_SerwisFusy->Size = System::Drawing::Size(110, 30);
			this->btn_SerwisFusy->Click += gcnew System::EventHandler(this, &MainWin::btn_SerwisFusy_Click);

			this->grp_PanelSerwisowy->Controls->Add(this->lbl_StatusCzujnikow);
			this->grp_PanelSerwisowy->Controls->Add(this->btn_SerwisWoda);
			this->grp_PanelSerwisowy->Controls->Add(this->btn_SerwisZiarna);
			this->grp_PanelSerwisowy->Controls->Add(this->btn_SerwisFusy);

			this->btn_PokazSerwis = (gcnew System::Windows::Forms::Button());
			this->btn_PokazSerwis->Text = L"Diagnostyka";
			this->btn_PokazSerwis->Location = System::Drawing::Point(375, 70);
			this->btn_PokazSerwis->Size = System::Drawing::Size(110, 30);     
			this->btn_PokazSerwis->Click += gcnew System::EventHandler(this, &MainWin::btn_PokazSerwis_Click);

			this->grp_PanelSerwisowy->Controls->Add(this->lbl_StatusCzujnikow);
			this->grp_PanelSerwisowy->Controls->Add(this->btn_SerwisWoda);
			this->grp_PanelSerwisowy->Controls->Add(this->btn_SerwisZiarna);
			this->grp_PanelSerwisowy->Controls->Add(this->btn_SerwisFusy);
			this->grp_PanelSerwisowy->Controls->Add(this->btn_PokazSerwis); 

			// Główne Okno
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(560, 463);
			this->Controls->Add(this->grp_PanelSerwisowy);
			this->Controls->Add(this->PanelEdycji);
			this->Controls->Add(this->btn_Ulubione);
			this->Controls->Add(this->btn_Podstawowe);
			this->Controls->Add(this->PanelPodstaw);
			this->Name = L"MainWin";
			this->Text = L"Ekspres do kawy z systemem monitorowania";
			this->ResumeLayout(false);
		}

#pragma endregion

	private:
		System::Void MainWin_Load(System::Object^ sender, System::EventArgs^ e) {}

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
				przyciskKawy->Click += gcnew System::EventHandler(this, &MainWin::KliknietoKawa_Click);
				PanelPodstaw->Controls->Add(przyciskKawy);

				Button^ przyciskEdycji = gcnew Button();
				przyciskEdycji->Text = L"⚙";
				przyciskEdycji->Font = gcnew System::Drawing::Font(L"Segoe UI Symbol", 18, System::Drawing::FontStyle::Regular);
				przyciskEdycji->TextAlign = ContentAlignment::MiddleCenter;
				przyciskEdycji->Size = System::Drawing::Size(70, 50);
				przyciskEdycji->Location = System::Drawing::Point(145, pozycjaY);
				przyciskEdycji->Tag = (int)i;
				przyciskEdycji->Click += gcnew System::EventHandler(this, &MainWin::KliknietoEdytujKawe_Click);
				PanelPodstaw->Controls->Add(przyciskEdycji);

				pozycjaY += odstep;
			}
		}

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
				przyciskKawy->Click += gcnew System::EventHandler(this, &MainWin::KliknietoUlubionaKawa_Click);
				PanelPodstaw->Controls->Add(przyciskKawy);

				Button^ przyciskEdycji = gcnew Button();
				przyciskEdycji->Text = L"⚙";
				przyciskEdycji->Font = gcnew System::Drawing::Font(L"Segoe UI Symbol", 18, System::Drawing::FontStyle::Regular);
				przyciskEdycji->TextAlign = ContentAlignment::MiddleCenter;
				przyciskEdycji->Size = System::Drawing::Size(45, 50);
				przyciskEdycji->Location = System::Drawing::Point(130, pozycjaY);
				przyciskEdycji->Tag = (int)i;
				przyciskEdycji->Click += gcnew System::EventHandler(this, &MainWin::KliknietoEdytujKawe_Click);
				PanelPodstaw->Controls->Add(przyciskEdycji);

				Button^ przyciskUsun = gcnew Button();
				przyciskUsun->Text = L"X";
				przyciskUsun->Font = gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold);
				przyciskUsun->TextAlign = ContentAlignment::MiddleCenter;
				przyciskUsun->Size = System::Drawing::Size(45, 50);
				przyciskUsun->Location = System::Drawing::Point(180, pozycjaY);
				przyciskUsun->Tag = (int)i;
				przyciskUsun->Click += gcnew System::EventHandler(this, &MainWin::KliknietoUsunUlubionaKawe_Click);
				PanelPodstaw->Controls->Add(przyciskUsun);

				pozycjaY += odstep;
			}
		}

		// Wspólna logika sprawdzania i parzenia kawy z integracją czujników backendowych
		void SprawdzISparz(TCoffee& wybranaKawa)
		{
			std::string error_msg;

			// Wywołanie backendowej funkcji sprawdzającej czy można zaparzyć
			if (!sensors_backend->canBrew(error_msg, wybranaKawa))
			{
				String^ system_msg = L"Błąd krytyczny urządzenia!\nPowód: ";
				if (error_msg == "WODA") system_msg += L"Zbyt niski poziom wody. Uzupełnij zbiornik.";
				else if (error_msg == "ZIARNA") system_msg += L"Brak ziaren kawy w zbiorniku młyńskim.";
				else if (error_msg == "FUSY") system_msg += L"Przepełniony pojemnik na odpady poekstrakcyjne.";
				else system_msg += gcnew String(error_msg.c_str());

				MessageBox::Show(system_msg, L"Blokada Serwisowa", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				AktualizujStanSerwisu();
				return;
			}

			// Jeśli test przeszedł pomyślnie - wywołaj proces dekrementacji zasobów
			sensors_backend->processBrewing(wybranaKawa);

			std::string info = "Parzenie zakonczone sukcesem:\n" + wybranaKawa.getName() +
				"\nPobrano: " + std::to_string(wybranaKawa.getWaterAmount()) + " ml wody, " +
				std::to_string(wybranaKawa.getCoffeeAmount()) + " g kawy.";

			MessageBox::Show(gcnew String(info.c_str()), L"Ekspres do kawy", MessageBoxButtons::OK, MessageBoxIcon::Information);

			// Odświeżenie diagnostyki na interfejsie
			AktualizujStanSerwisu();
		}

		System::Void KliknietoKawa_Click(System::Object^ sender, System::EventArgs^ e)
		{
			Button^ kliknietyPrzycisk = safe_cast<Button^>(sender);
			int indeksKawy = Convert::ToInt32(kliknietyPrzycisk->Tag);

			if (default_coffees_vector != nullptr && indeksKawy >= 0 && indeksKawy < static_cast<int>(default_coffees_vector->size()))
			{
				TCoffee wybranaKawa = (*default_coffees_vector)[indeksKawy];
				SprawdzISparz(wybranaKawa);
			}
		}

		System::Void KliknietoUlubionaKawa_Click(System::Object^ sender, System::EventArgs^ e)
		{
			Button^ kliknietyPrzycisk = safe_cast<Button^>(sender);
			int indeksKawy = Convert::ToInt32(kliknietyPrzycisk->Tag);

			if (favourite_coffees_vector != nullptr && indeksKawy >= 0 && indeksKawy < static_cast<int>(favourite_coffees_vector->size()))
			{
				TCoffee wybranaKawa = (*favourite_coffees_vector)[indeksKawy];
				SprawdzISparz(wybranaKawa);
			}
		}

		System::Void KliknietoEdytujKawe_Click(System::Object^ sender, System::EventArgs^ e)
		{
			Button^ kliknietyPrzycisk = safe_cast<Button^>(sender);
			int indeksKawy = Convert::ToInt32(kliknietyPrzycisk->Tag);
			std::vector<TCoffee>* aktualnyWektor = pokazujeUlubione ? favourite_coffees_vector : default_coffees_vector;

			if (aktualnyWektor != nullptr && indeksKawy >= 0 && indeksKawy < static_cast<int>(aktualnyWektor->size()))
			{
				edytowanyIndeks = indeksKawy;
				TCoffee wybranaKawa = (*aktualnyWektor)[indeksKawy];

				txt_Nazwa->Text = gcnew String(wybranaKawa.getName().c_str());
				num_Woda->Value = wybranaKawa.getWaterAmount();
				num_Kawa->Value = wybranaKawa.getCoffeeAmount();
				num_Mleko->Value = wybranaKawa.getMilkAmount();

				PanelEdycji->Visible = true;
			}
		}

		System::Void btn_ZapiszEdycje_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (edytowanyIndeks < 0) return;

			std::string nowaNazwa = msclr::interop::marshal_as<std::string>(txt_Nazwa->Text);
			int nowaWoda = Decimal::ToInt32(num_Woda->Value);
			int nowaKawa = Decimal::ToInt32(num_Kawa->Value);
			int noweMleko = Decimal::ToInt32(num_Mleko->Value);

			TCoffee nowaKawaObiekt(nowaNazwa, nowaWoda, nowaKawa, noweMleko);
			favourite_coffees_vector->push_back(nowaKawaObiekt);
			CoffeeManager::saveVector("favourite_coffees.txt", *favourite_coffees_vector);

			btn_Ulubione_Click(nullptr, nullptr);
		}

		System::Void btn_AnulujEdycje_Click(System::Object^ sender, System::EventArgs^ e)
		{
			PanelEdycji->Visible = false;
			edytowanyIndeks = -1;
		}

		System::Void btn_ZaparzEdycje_Click(System::Object^ sender, System::EventArgs^ e)
		{
			std::string nazwa = msclr::interop::marshal_as<std::string>(txt_Nazwa->Text);
			int woda = Decimal::ToInt32(num_Woda->Value);
			int kawa = Decimal::ToInt32(num_Kawa->Value);
			int mleko = Decimal::ToInt32(num_Mleko->Value);

			TCoffee kawaDoZaparzenia(nazwa, woda, kawa, mleko);
			SprawdzISparz(kawaDoZaparzenia);
		}

		System::Void KliknietoUsunUlubionaKawe_Click(System::Object^ sender, System::EventArgs^ e)
		{
			Button^ kliknietyPrzycisk = safe_cast<Button^>(sender);
			int indeksKawy = Convert::ToInt32(kliknietyPrzycisk->Tag);
			TCoffee usuwanaKawa = (*favourite_coffees_vector)[indeksKawy];

			CoffeeManager::removeCoffeeByName("favourite_coffees.txt", *favourite_coffees_vector, usuwanaKawa.getName());
			PanelEdycji->Visible = false;
			edytowanyIndeks = -1;
			GenerujPrzyciskiUlubionychKaw();
		}

		// Metoda pobierająca dane diagnostyczne i aktualizująca interfejs UI
		void AktualizujStanSerwisu()
		{
			std::string krytyczny_blad;
			bool blokada = !sensors_backend->canBrew(krytyczny_blad);

			if (blokada)
			{
				lbl_StatusCzujnikow->ForeColor = System::Drawing::Color::Red;
				if (krytyczny_blad == "WODA")
					lbl_StatusCzujnikow->Text = L"STATUS: BLOKADA - KRYTYCZNIE NISKI POZIOM WODY (<50ml)";
				else if (krytyczny_blad == "ZIARNA")
					lbl_StatusCzujnikow->Text = L"STATUS: BLOKADA - BRAK ZIAREN KAWY (<10g)";
				else if (krytyczny_blad == "FUSY")
					lbl_StatusCzujnikow->Text = L"STATUS: BLOKADA - POJEMNIK NA FUSY PRZEPEŁNIONY (>=10)";
			}
			else
			{
				lbl_StatusCzujnikow->ForeColor = System::Drawing::Color::DarkGreen;
				lbl_StatusCzujnikow->Text = L"STATUS: Urządzenie gotowe do eksploatacji. Stan serwisowy optymalny.";
			}
		}

		// Eventy obsługi przycisków serwisowych w GUI
		System::Void btn_SerwisWoda_Click(System::Object^ sender, System::EventArgs^ e)
		{
			sensors_backend->refillWater(500); // Dolej 500 ml
			AktualizujStanSerwisu();
			MessageBox::Show(L"Uzupełniono poziom wody o 500ml.", L"Serwis");
		}

		System::Void btn_SerwisZiarna_Click(System::Object^ sender, System::EventArgs^ e)
		{
			sensors_backend->refillBeans(100); // Dosyp 100 g
			AktualizujStanSerwisu();
			MessageBox::Show(L"Uzupełniono zbiornik ziaren o 100g.", L"Serwis");
		}

		System::Void btn_SerwisFusy_Click(System::Object^ sender, System::EventArgs^ e)
		{
			sensors_backend->emptyGrounds(); // Wyzeruj licznik
			AktualizujStanSerwisu();
			MessageBox::Show(L"Pojemnik na fusy został opróżniony.", L"Serwis");
		}

		private:
			System::Void btn_PokazSerwis_Click(System::Object^ sender, System::EventArgs^ e)
			{
				// Wywołanie canBrew w celu pobrania ewentualnego kodu błędu krytycznego
				std::string krytyczny_blad;
				bool maszyna_zablokowana = !sensors_backend->canBrew(krytyczny_blad);

				// Przygotowanie tekstu diagnostycznego
				String^ raport = L"--- STAN EKSPRESU ---\n\n";

				if (maszyna_zablokowana)
				{
					raport += L"STATUS OGÓLNY: ZABLOKOWANY\n";
					raport += L"Powód blokady: ";
					if (krytyczny_blad == "WODA") raport += L"Krytyczny brak wody w systemie (<50ml).\n";
					else if (krytyczny_blad == "ZIARNA") raport += L"Krytyczny brak ziaren w młynku (<10g).\n";
					else if (krytyczny_blad == "FUSY") raport += L"Przepełnienie szuflady na odpady (>=10 kaw).\n";
					else raport += gcnew String(krytyczny_blad.c_str()) + L"\n";
				}
				else
				{
					raport += L"STATUS OGÓLNY: GOTOWY DO PRACY\n";
					raport += L"Wszystkie czujniki mieszczą się w normach.\n";
				}

				raport += L"\nAktualne wartosci:\n";
				raport += L"- Poziom wody: " + sensors_backend->getWaterLevel() + L" ml\n";
				raport += L"- Stan ziaren: " + sensors_backend->getBeansAmount() + L" g\n";
				raport += L"- Licznik odpadów: " + sensors_backend->getGroundsCount() + L" / 10\n";

				// Wyświetlenie okna modalnego z raportem stanu
				MessageBox::Show(
					raport,
					L"Panel Diagnostyczny Serwisu",
					MessageBoxButtons::OK,
					maszyna_zablokowana ? MessageBoxIcon::Error : MessageBoxIcon::Information

				);
			}
	};
}