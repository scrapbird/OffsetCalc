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
	private: System::Windows::Forms::TextBox^  TxtDbgBaseAddr;
	private: System::Windows::Forms::TextBox^  TxtTgtAddr;
	private: System::Windows::Forms::TextBox^  TxtDisassBaseAddr;
	private: System::Windows::Forms::Button^  CopyButton;

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
			UINT64 DbgBaseAddr = GetFromHextString(TxtDbgBaseAddr->Text->ToString());
			System::Diagnostics::Debug::Write("Dbg base addr: " + DbgBaseAddr + "\n");

			UINT64 TargetAddr = GetFromHextString(TxtTgtAddr->Text->ToString());
			System::Diagnostics::Debug::Write("Target addr: " + TargetAddr + "\n");

			UINT64 DisassBaseAddr = GetFromHextString(TxtDisassBaseAddr->Text->ToString());
			System::Diagnostics::Debug::Write("Disassembler base addr: " + DisassBaseAddr + "\n");

			// Get offset
			UINT64 offset = TargetAddr - DbgBaseAddr;
			System::Diagnostics::Debug::Write("Offset: " + offset + "\n");

			// Calculate DisassBaseAddr + offset
			UINT64 result = DisassBaseAddr + offset;
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
			this->TxtDbgBaseAddr = (gcnew System::Windows::Forms::TextBox());
			this->TxtTgtAddr = (gcnew System::Windows::Forms::TextBox());
			this->TxtDisassBaseAddr = (gcnew System::Windows::Forms::TextBox());
			this->TxtResult = (gcnew System::Windows::Forms::TextBox());
			this->CopyButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 10);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(120, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Debugger base address";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 36);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(78, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Target address";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 62);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(135, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Disassembler base address";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 88);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(37, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Result";
			// 
			// TxtDbgBaseAddr
			// 
			this->TxtDbgBaseAddr->Location = System::Drawing::Point(153, 7);
			this->TxtDbgBaseAddr->Name = L"TxtDbgBaseAddr";
			this->TxtDbgBaseAddr->Size = System::Drawing::Size(181, 20);
			this->TxtDbgBaseAddr->TabIndex = 5;
			this->TxtDbgBaseAddr->TextChanged += gcnew System::EventHandler(this, &OffsetCalc::DbgBaseAddr_TextChanged);
			// 
			// TxtTgtAddr
			// 
			this->TxtTgtAddr->Location = System::Drawing::Point(153, 33);
			this->TxtTgtAddr->Name = L"TxtTgtAddr";
			this->TxtTgtAddr->Size = System::Drawing::Size(181, 20);
			this->TxtTgtAddr->TabIndex = 6;
			this->TxtTgtAddr->TextChanged += gcnew System::EventHandler(this, &OffsetCalc::TxtTgtAddr_TextChanged);
			// 
			// TxtDisassBaseAddr
			// 
			this->TxtDisassBaseAddr->Location = System::Drawing::Point(153, 59);
			this->TxtDisassBaseAddr->Name = L"TxtDisassBaseAddr";
			this->TxtDisassBaseAddr->Size = System::Drawing::Size(181, 20);
			this->TxtDisassBaseAddr->TabIndex = 7;
			this->TxtDisassBaseAddr->Text = L"0x140000000";
			this->TxtDisassBaseAddr->TextChanged += gcnew System::EventHandler(this, &OffsetCalc::TxtDisassBaseAddr_TextChanged);
			// 
			// TxtResult
			// 
			this->TxtResult->Location = System::Drawing::Point(153, 85);
			this->TxtResult->Name = L"TxtResult";
			this->TxtResult->ReadOnly = true;
			this->TxtResult->Size = System::Drawing::Size(141, 20);
			this->TxtResult->TabIndex = 8;
			// 
			// CopyButton
			// 
			this->CopyButton->Location = System::Drawing::Point(297, 83);
			this->CopyButton->Name = L"CopyButton";
			this->CopyButton->Size = System::Drawing::Size(42, 23);
			this->CopyButton->TabIndex = 9;
			this->CopyButton->Text = L"Copy";
			this->CopyButton->UseVisualStyleBackColor = true;
			this->CopyButton->Click += gcnew System::EventHandler(this, &OffsetCalc::CopyButton_Click);
			// 
			// OffsetCalc
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(346, 114);
			this->Controls->Add(this->CopyButton);
			this->Controls->Add(this->TxtResult);
			this->Controls->Add(this->TxtDisassBaseAddr);
			this->Controls->Add(this->TxtTgtAddr);
			this->Controls->Add(this->TxtDbgBaseAddr);
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
	private: System::Void TxtDbgBaseAddr_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		this->CalculateOffsets();
	}
	private: System::Void DbgBaseAddr_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		this->CalculateOffsets();
	}
	private: System::Void TxtTgtAddr_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		this->CalculateOffsets();
	}
	private: System::Void TxtDisassBaseAddr_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		this->CalculateOffsets();
	}

	private: System::Void CopyButton_Click(System::Object^  sender, System::EventArgs^  e) {
		Clipboard::SetDataObject(this->TxtResult->Text, true);
	}
};
}
