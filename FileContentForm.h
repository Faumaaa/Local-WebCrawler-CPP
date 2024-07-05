// FileContentForm.h
#pragma once
#include <msclr/marshal_cppstd.h>
#include <string>
#include <fstream>
#include <sstream>

namespace PROJECT_DS {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class FileContentForm : public System::Windows::Forms::Form {
    public:
        FileContentForm(String^ filePath) {
            InitializeComponent();
            LoadFileContent(filePath);
        }

    protected:
        ~FileContentForm() {
            if (components) {
                delete components;
            }
        }

    private: System::Windows::Forms::TextBox^ textBox;
    private: System::ComponentModel::IContainer^ components;

           void InitializeComponent(void) {
               this->textBox = (gcnew System::Windows::Forms::TextBox());
               this->SuspendLayout();
               // 
               // textBox
               // 
               this->textBox->Dock = System::Windows::Forms::DockStyle::Fill;
               this->textBox->Multiline = true;
               this->textBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
               this->textBox->Name = L"textBox";
               this->textBox->Size = System::Drawing::Size(800, 600);
               this->textBox->TabIndex = 0;
               this->textBox->Enabled = false;
               // 
               // FileContentForm
               // 
               this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->ClientSize = System::Drawing::Size(800, 600);
               this->Controls->Add(this->textBox);
               this->Name = L"FileContentForm";
               this->Text = L"File Content";
               this->ResumeLayout(false);
               this->PerformLayout();
           }

           void LoadFileContent(String^ filePath) {
               std::string filePathStr = msclr::interop::marshal_as<std::string>(filePath);
               std::ifstream file(filePathStr);
               if (file.is_open()) {
                   std::stringstream buffer;
                   buffer << file.rdbuf();
                   file.close();
                   String^ fileContent = msclr::interop::marshal_as<String^>(buffer.str());
                   textBox->Text = fileContent;
               }
               else {
                   textBox->Text = "Error: Unable to open file.";
               }
           }
    };
}
