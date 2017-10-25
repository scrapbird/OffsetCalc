#pragma once

#include <iostream>
#include <sstream>
#include <iomanip>
#include <msclr\marshal_cppstd.h>

namespace OffsetCalc {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class OffsetCalc : public System::Windows::Forms::Form
	{
	public:
		OffsetCalc(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~OffsetCalc()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  TxtFromBaseAddr;

	private: System::Windows::Forms::TextBox^  TxtTgtAddr;
	private: System::Windows::Forms::TextBox^  TxtToBaseAddr;

	private: System::Windows::Forms::Button^  CopyButton;
	private: System::Windows::Forms::Button^  SwapButton;



	private: System::Windows::Forms::TextBox^  TxtResult;


	private:
		UINT64 GetFromHextString(String ^ src) {
			if (src->StartsWith("0x")) {
				// Strip 0x from the start
				src = src->Substring(2);
			}
			std::string HexString = msclr::interop::marshal_as<std::string>(src);
			std::stringstream converter(HexString);
			UINT64 value;
			converter >> std::hex >> value;
			return value;
		}

		void CalculateOffsets() {
			// Calculate the offets
			UINT64 FromBaseAddr = GetFromHextString(TxtFromBaseAddr->Text->ToString());
			System::Diagnostics::Debug::Write("From base addr: " + FromBaseAddr + "\n");

			UINT64 TargetAddr = GetFromHextString(TxtTgtAddr->Text->ToString());
			System::Diagnostics::Debug::Write("Target addr: " + TargetAddr + "\n");

			UINT64 ToBaseAddr = GetFromHextString(TxtToBaseAddr->Text->ToString());
			System::Diagnostics::Debug::Write("To base addr: " + ToBaseAddr + "\n");

			// Get offset
			UINT64 offset = TargetAddr - FromBaseAddr;
			System::Diagnostics::Debug::Write("Offset: " + offset + "\n");

			// Calculate DisassBaseAddr + offset
			UINT64 result = ToBaseAddr + offset;
			System::Diagnostics::Debug::Write("Result: " + result + "\n");

			std::stringstream stream;
			stream << "0x" << std::hex << result;
			std::string resultString(stream.str());

			TxtResult->Text = gcnew String(resultString.c_str());
			TxtResult->Refresh();
		}

		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(OffsetCalc::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->TxtFromBaseAddr = (gcnew System::Windows::Forms::TextBox());
			this->TxtTgtAddr = (gcnew System::Windows::Forms::TextBox());
			this->TxtToBaseAddr = (gcnew System::Windows::Forms::TextBox());
			this->TxtResult = (gcnew System::Windows::Forms::TextBox());
			this->CopyButton = (gcnew System::Windows::Forms::Button());
			this->SwapButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(96, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"From base address";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 104);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(78, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Target address";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 73);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(86, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"To base address";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 135);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(37, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Result";
			// 
			// TxtFromBaseAddr
			// 
			this->TxtFromBaseAddr->Font = (gcnew System::Drawing::Font(L"Consolas", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TxtFromBaseAddr->Location = System::Drawing::Point(114, 7);
			this->TxtFromBaseAddr->Name = L"TxtFromBaseAddr";
			this->TxtFromBaseAddr->Size = System::Drawing::Size(181, 25);
			this->TxtFromBaseAddr->TabIndex = 5;
			this->TxtFromBaseAddr->TextChanged += gcnew System::EventHandler(this, &OffsetCalc::TxtFromBaseAddr_TextChanged);
			// 
			// TxtTgtAddr
			// 
			this->TxtTgtAddr->Font = (gcnew System::Drawing::Font(L"Consolas", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TxtTgtAddr->Location = System::Drawing::Point(114, 98);
			this->TxtTgtAddr->Name = L"TxtTgtAddr";
			this->TxtTgtAddr->Size = System::Drawing::Size(181, 25);
			this->TxtTgtAddr->TabIndex = 6;
			this->TxtTgtAddr->TextChanged += gcnew System::EventHandler(this, &OffsetCalc::TxtTgtAddr_TextChanged);
			// 
			// TxtToBaseAddr
			// 
			this->TxtToBaseAddr->Font = (gcnew System::Drawing::Font(L"Consolas", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TxtToBaseAddr->Location = System::Drawing::Point(114, 67);
			this->TxtToBaseAddr->Name = L"TxtToBaseAddr";
			this->TxtToBaseAddr->Size = System::Drawing::Size(181, 25);
			this->TxtToBaseAddr->TabIndex = 7;
			this->TxtToBaseAddr->Text = L"0x140000000";
			this->TxtToBaseAddr->TextChanged += gcnew System::EventHandler(this, &OffsetCalc::TxtToBaseAddr_TextChanged);
			// 
			// TxtResult
			// 
			this->TxtResult->Font = (gcnew System::Drawing::Font(L"Consolas", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TxtResult->Location = System::Drawing::Point(114, 129);
			this->TxtResult->Name = L"TxtResult";
			this->TxtResult->ReadOnly = true;
			this->TxtResult->Size = System::Drawing::Size(126, 25);
			this->TxtResult->TabIndex = 8;
			// 
			// CopyButton
			// 
			this->CopyButton->Location = System::Drawing::Point(246, 130);
			this->CopyButton->Name = L"CopyButton";
			this->CopyButton->Size = System::Drawing::Size(49, 23);
			this->CopyButton->TabIndex = 9;
			this->CopyButton->Text = L"Copy";
			this->CopyButton->UseVisualStyleBackColor = true;
			this->CopyButton->Click += gcnew System::EventHandler(this, &OffsetCalc::CopyButton_Click);
			// 
			// SwapButton
			// 
			this->SwapButton->Location = System::Drawing::Point(165, 38);
			this->SwapButton->Name = L"SwapButton";
			this->SwapButton->Size = System::Drawing::Size(75, 23);
			this->SwapButton->TabIndex = 10;
			this->SwapButton->Text = L"Swap";
			this->SwapButton->UseVisualStyleBackColor = true;
			this->SwapButton->Click += gcnew System::EventHandler(this, &OffsetCalc::SwapButton_Click);
			// 
			// OffsetCalc
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(309, 162);
			this->Controls->Add(this->SwapButton);
			this->Controls->Add(this->CopyButton);
			this->Controls->Add(this->TxtResult);
			this->Controls->Add(this->TxtToBaseAddr);
			this->Controls->Add(this->TxtTgtAddr);
			this->Controls->Add(this->TxtFromBaseAddr);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"OffsetCalc";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Offset Calculator";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void TxtFromBaseAddr_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		this->CalculateOffsets();
	}

	private: System::Void TxtTgtAddr_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		this->CalculateOffsets();
	}

	private: System::Void TxtToBaseAddr_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		this->CalculateOffsets();
	}

	private: System::Void CopyButton_Click(System::Object^  sender, System::EventArgs^  e) {
		Clipboard::SetDataObject(this->TxtResult->Text, true);
	}

	private: System::Void SwapButton_Click(System::Object^  sender, System::EventArgs^  e) {
		System::String ^from = this->TxtFromBaseAddr->Text;
		System::String ^to = this->TxtToBaseAddr->Text;
		this->TxtFromBaseAddr->Text = to;
		this->TxtToBaseAddr->Text = from;
	}
};
}
