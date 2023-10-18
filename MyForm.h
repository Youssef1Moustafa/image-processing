/*
This Tool Have been designed by 

youssef moustafa youssef

*/


#pragma once
#include "MyForm.h"
#include <opencv2/opencv.hpp>
#include <msclr/marshal.h>






using namespace msclr::interop;
using namespace cv;
using namespace std;


// define some constants
Mat  src , temp , grayImg , grayOrg, original , backblind ,frontblind , blinded , bitplnImg;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace GUI2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;



	void getContours(Mat imgDil, Mat src) {

		vector<vector<cv::Point>> contours;
		vector<Vec4i> hierarchy;

		findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
		

		vector<vector<cv::Point>> conPoly(contours.size());
		vector<Rect> boundRect(contours.size());

		for (int i = 0; i < contours.size(); i++)
		{
			int area = contourArea(contours[i]);
			cout << area << endl;
			string objectType;

			if (area > 1000)
			{
				float peri = arcLength(contours[i], true);
				approxPolyDP(contours[i], conPoly[i], 0.01 * peri, true);
				cout << conPoly[i].size() << endl;
				boundRect[i] = boundingRect(conPoly[i]);

				int objCor = (int)conPoly[i].size();

				if (objCor == 3) { objectType = "Triangle"; }

				else if (objCor == 4)
				{
					float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height;
					cout << aspRatio << endl;
					if (aspRatio > 0.95 && aspRatio < 1.05)
					{
						objectType = "Square";
					}
					else { objectType = "Rectangle"; }
				}

				else if (objCor >= 4 && objCor <= 12)
				{ 

					if (objCor == 5)
					{
						objectType = "pentagon";
					}
					else if  (objCor == 6) 
					{

						objectType = "HEXA";
					}
					else if (objCor == 10)
					{

						objectType = "star";
					}
					else if (objCor == 12)
					{

						objectType = "star";
					}

				}
				else
				{
					// Detect and label circles
					double area = cv::contourArea(contours[i]);
					cv::Rect r = cv::boundingRect(contours[i]);
					int radius = r.width / 2;

					if (std::abs(1 - ((double)r.width / r.height)) <= 0.4 &&
						std::abs(1 - (area / (CV_PI * std::pow(radius, 2)))) <= 0.4)
						objectType = "circle";
				}
				

				drawContours(src, conPoly, i, Scalar(255, 0, 255), 2);
				rectangle(src, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
				putText(src, objectType, { boundRect[i].x,boundRect[i].y - 5 }, FONT_HERSHEY_PLAIN, 1, Scalar(0, 69, 255), 2);
			}
		}
	}


	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			
		}

	protected:
		
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;


	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::TrackBar^ trackBar1;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::GroupBox^ groupBox3;

	private: System::Windows::Forms::Button^ button13;

	private: System::Windows::Forms::Button^ button16;




	private: System::Windows::Forms::GroupBox^ groupBox5;
	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::TrackBar^ trackBar3;

	private: System::Windows::Forms::Button^ button19;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TrackBar^ trackBar4;
	private: System::Windows::Forms::GroupBox^ groupBox6;

	private: System::Windows::Forms::Button^ button20;






	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ button14;
	private: System::Windows::Forms::Button^ button15;



	private: System::Windows::Forms::Button^ button23;
	private: System::Windows::Forms::GroupBox^ groupBox8;
	private: System::Windows::Forms::Button^ button24;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::GroupBox^ groupBox9;
	private: System::Windows::Forms::Button^ button25;
	private: System::Windows::Forms::GroupBox^ groupBox10;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TrackBar^ trackBar6;
	private: System::Windows::Forms::GroupBox^ groupBox11;
	private: System::Windows::Forms::Button^ button30;
	private: System::Windows::Forms::Button^ button28;
	private: System::Windows::Forms::Button^ button29;
	private: System::Windows::Forms::Button^ button31;
	private: System::Windows::Forms::Button^ button27;
	private: System::Windows::Forms::Button^ button26;
	private: System::Windows::Forms::GroupBox^ groupBox12;
	private: System::Windows::Forms::GroupBox^ groupBox13;
	private: System::Windows::Forms::GroupBox^ groupBox14;


	private: System::Windows::Forms::Button^ button34;
	private: System::Windows::Forms::Button^ button35;
	private: System::Windows::Forms::Button^ button36;
	private: System::Windows::Forms::ToolTip^ toolTip1;
private: System::Windows::Forms::ToolTip^ toolTip2;
private: System::Windows::Forms::ToolTip^ toolTip4;
private: System::Windows::Forms::ToolTip^ toolTip3;
private: System::Windows::Forms::ToolTip^ toolTip5;
private: System::Windows::Forms::ToolTip^ toolTip6;

private: System::Windows::Forms::ToolTip^ toolTip8;
private: System::Windows::Forms::ToolTip^ toolTip7;
private: System::Windows::Forms::ToolTip^ toolTip9;
private: System::Windows::Forms::ToolTip^ toolTip11;
private: System::Windows::Forms::ToolTip^ toolTip10;
private: System::Windows::Forms::TrackBar^ trackBar7;
private: System::Windows::Forms::Label^ label12;
private: System::Windows::Forms::Label^ label11;
private: System::Windows::Forms::Button^ button8;
private: System::Windows::Forms::ToolTip^ toolTip12;
private: System::Windows::Forms::GroupBox^ groupBox4;
private: System::Windows::Forms::Button^ button9;

private: System::Windows::Forms::TextBox^ textBox2;
private: System::Windows::Forms::ToolTip^ toolTip13;
private: System::Windows::Forms::ToolTip^ toolTip14;
private: System::Windows::Forms::ToolTip^ toolTip15;
private: System::Windows::Forms::ToolTip^ toolTip16;
private: System::Windows::Forms::ToolTip^ toolTip17;
private: System::Windows::Forms::ToolTip^ toolTip18;
private: System::Windows::Forms::ToolTip^ toolTip19;
private: System::Windows::Forms::ToolTip^ toolTip22;
private: System::Windows::Forms::ToolTip^ toolTip21;
private: System::Windows::Forms::ToolTip^ toolTip20;
private: System::Windows::Forms::ToolTip^ toolTip23;
private: System::Windows::Forms::ToolTip^ toolTip25;
private: System::Windows::Forms::ToolTip^ toolTip24;
private: System::Windows::Forms::ToolTip^ toolTip26;
private: System::Windows::Forms::ToolTip^ toolTip27;
private: System::Windows::Forms::ToolTip^ toolTip28;
private: System::Windows::Forms::ToolTip^ toolTip29;
private: System::Windows::Forms::ToolTip^ toolTip30;
private: System::Windows::Forms::ToolTip^ toolTip32;
private: System::Windows::Forms::ToolTip^ toolTip31;
private: System::Windows::Forms::ToolTip^ toolTip33;
private: System::Windows::Forms::ToolTip^ toolTip34;
private: System::Windows::Forms::ToolTip^ toolTip35;
private: System::Windows::Forms::ToolTip^ toolTip36;
private: System::Windows::Forms::ToolTip^ toolTip37;
private: System::Windows::Forms::ToolTip^ toolTip38;
private: System::Windows::Forms::Button^ button11;
private: System::Windows::Forms::Button^ button17;
private: System::Windows::Forms::Button^ button22;
private: System::Windows::Forms::ToolTip^ toolTip39;
private: System::Windows::Forms::Button^ histogram_button32;
private: System::Windows::Forms::Button^ sobel_xy_button32;





private: System::Windows::Forms::Button^ gaussian_button32;
private: System::Windows::Forms::Button^ button32;
private: System::Windows::Forms::GroupBox^ groupBox15;
private: System::Windows::Forms::GroupBox^ groupBox17;
private: System::Windows::Forms::GroupBox^ histogram;
private: System::Windows::Forms::GroupBox^ groupBox16;
private: System::Windows::Forms::Button^ button12;
private: System::Windows::Forms::Button^ button18;
private: System::Windows::Forms::Button^ button21;
private: System::Windows::Forms::GroupBox^ groupBox7;
private: System::Windows::Forms::Button^ button33;
private: System::Windows::Forms::TextBox^ textBox4;
private: System::Windows::Forms::Button^ button37;
private: System::Windows::Forms::TextBox^ textBox5;
private: System::Windows::Forms::GroupBox^ groupBox18;
private: System::Windows::Forms::Button^ button38;

private: System::Windows::Forms::Button^ button39;
private: System::Windows::Forms::TextBox^ textBox6;
private: System::Windows::Forms::TextBox^ textBox7;
private: System::Windows::Forms::GroupBox^ groupBox21;
private: System::Windows::Forms::GroupBox^ groupBox20;
private: System::Windows::Forms::Button^ button40;
private: System::Windows::Forms::TextBox^ textBox8;
private: System::Windows::Forms::TextBox^ textBox9;
private: System::Windows::Forms::Button^ button41;
private: System::Windows::Forms::GroupBox^ groupBox22;
private: System::Windows::Forms::Label^ label14;
private: System::Windows::Forms::Label^ label13;
private: System::Windows::Forms::Label^ label8;
private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::GroupBox^ groupBox23;
private: System::Windows::Forms::Button^ button42;
private: System::Windows::Forms::Button^ button43;
private: System::Windows::Forms::Button^ button44;
private: System::Windows::Forms::GroupBox^ groupBox19;
private: System::Windows::Forms::TextBox^ cmpression_scale;

private: System::Windows::Forms::Button^ button45;
private: System::Windows::Forms::GroupBox^ groupBox24;












































	private: System::ComponentModel::IContainer^ components;







	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button36 = (gcnew System::Windows::Forms::Button());
			this->button35 = (gcnew System::Windows::Forms::Button());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox24 = (gcnew System::Windows::Forms::GroupBox());
			this->button43 = (gcnew System::Windows::Forms::Button());
			this->groupBox21 = (gcnew System::Windows::Forms::GroupBox());
			this->button23 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->groupBox15 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox17 = (gcnew System::Windows::Forms::GroupBox());
			this->histogram = (gcnew System::Windows::Forms::GroupBox());
			this->histogram_button32 = (gcnew System::Windows::Forms::Button());
			this->groupBox16 = (gcnew System::Windows::Forms::GroupBox());
			this->button32 = (gcnew System::Windows::Forms::Button());
			this->groupBox10 = (gcnew System::Windows::Forms::GroupBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->trackBar6 = (gcnew System::Windows::Forms::TrackBar());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->trackBar4 = (gcnew System::Windows::Forms::TrackBar());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->trackBar3 = (gcnew System::Windows::Forms::TrackBar());
			this->groupBox14 = (gcnew System::Windows::Forms::GroupBox());
			this->gaussian_button32 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->trackBar7 = (gcnew System::Windows::Forms::TrackBar());
			this->groupBox11 = (gcnew System::Windows::Forms::GroupBox());
			this->button44 = (gcnew System::Windows::Forms::Button());
			this->groupBox20 = (gcnew System::Windows::Forms::GroupBox());
			this->button38 = (gcnew System::Windows::Forms::Button());
			this->button31 = (gcnew System::Windows::Forms::Button());
			this->sobel_xy_button32 = (gcnew System::Windows::Forms::Button());
			this->button22 = (gcnew System::Windows::Forms::Button());
			this->groupBox18 = (gcnew System::Windows::Forms::GroupBox());
			this->button33 = (gcnew System::Windows::Forms::Button());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button37 = (gcnew System::Windows::Forms::Button());
			this->groupBox13 = (gcnew System::Windows::Forms::GroupBox());
			this->button29 = (gcnew System::Windows::Forms::Button());
			this->groupBox12 = (gcnew System::Windows::Forms::GroupBox());
			this->button30 = (gcnew System::Windows::Forms::Button());
			this->button26 = (gcnew System::Windows::Forms::Button());
			this->button28 = (gcnew System::Windows::Forms::Button());
			this->button27 = (gcnew System::Windows::Forms::Button());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button24 = (gcnew System::Windows::Forms::Button());
			this->groupBox9 = (gcnew System::Windows::Forms::GroupBox());
			this->button34 = (gcnew System::Windows::Forms::Button());
			this->button25 = (gcnew System::Windows::Forms::Button());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip2 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip3 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip4 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip5 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip6 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip8 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip7 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip9 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip10 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip11 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip12 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip13 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip14 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip15 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip16 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip17 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip18 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip19 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip20 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip21 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip22 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip23 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip24 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip25 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip26 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip27 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip28 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip29 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip30 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip31 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip32 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip33 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip34 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip35 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip36 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip37 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip38 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip39 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->button21 = (gcnew System::Windows::Forms::Button());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->button39 = (gcnew System::Windows::Forms::Button());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->button40 = (gcnew System::Windows::Forms::Button());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->button41 = (gcnew System::Windows::Forms::Button());
			this->groupBox22 = (gcnew System::Windows::Forms::GroupBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox23 = (gcnew System::Windows::Forms::GroupBox());
			this->button42 = (gcnew System::Windows::Forms::Button());
			this->groupBox19 = (gcnew System::Windows::Forms::GroupBox());
			this->cmpression_scale = (gcnew System::Windows::Forms::TextBox());
			this->button45 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox24->SuspendLayout();
			this->groupBox21->SuspendLayout();
			this->groupBox15->SuspendLayout();
			this->groupBox17->SuspendLayout();
			this->histogram->SuspendLayout();
			this->groupBox16->SuspendLayout();
			this->groupBox10->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar6))->BeginInit();
			this->groupBox4->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->groupBox5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->BeginInit();
			this->groupBox14->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar7))->BeginInit();
			this->groupBox11->SuspendLayout();
			this->groupBox20->SuspendLayout();
			this->groupBox18->SuspendLayout();
			this->groupBox13->SuspendLayout();
			this->groupBox12->SuspendLayout();
			this->groupBox8->SuspendLayout();
			this->groupBox9->SuspendLayout();
			this->groupBox7->SuspendLayout();
			this->groupBox22->SuspendLayout();
			this->groupBox23->SuspendLayout();
			this->groupBox19->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::Control;
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(16, 64);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(477, 537);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->toolTip6->SetToolTip(this->pictureBox1, L"The selected image (original image)");
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// button1
			// 
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(16, 20);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(86, 27);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Open";
			this->toolTip1->SetToolTip(this->button1, L"Open an image to make a processing on it");
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button2->Location = System::Drawing::Point(19, 112);
			this->button2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(156, 80);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Flip Around XY-axis";
			this->toolTip18->SetToolTip(this->button2, L"Flip the image with flip code = -1");
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(109, 21);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(384, 22);
			this->textBox1->TabIndex = 4;
			this->toolTip2->SetToolTip(this->textBox1, L"The directory of the selected image");
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// button3
			// 
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button3->Location = System::Drawing::Point(100, 21);
			this->button3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 80);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Flip Around   Y-axis";
			this->toolTip17->SetToolTip(this->button3, L"Flip the image with flip code = 1\r\n");
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button4->Location = System::Drawing::Point(19, 21);
			this->button4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 80);
			this->button4->TabIndex = 6;
			this->button4->Text = L"Flip Around   X-axis";
			this->toolTip16->SetToolTip(this->button4, L"Flip the image with flip code = 0");
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button5->Location = System::Drawing::Point(17, 70);
			this->button5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(167, 37);
			this->button5->TabIndex = 7;
			this->button5->Text = L"Histogram Equalization";
			this->toolTip25->SetToolTip(this->button5, L"It Is a method which increases the dynamic range of the gray levels in a low\r\ncon"
				L"trast image to cover the full range of gray levels in order to improve\r\nimage co"
				L"ntrast.");
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button6->Location = System::Drawing::Point(13, 209);
			this->button6->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(234, 40);
			this->button6->TabIndex = 8;
			this->button6->Text = L"Negative";
			this->toolTip9->SetToolTip(this->button6, L"Convert the image to Negative.\r\nUsed for enhancing white or grey detail embedded "
				L"in\r\ndark regions of an image.");
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button7
			// 
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button7->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button7->Location = System::Drawing::Point(234, 15);
			this->button7->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(161, 26);
			this->button7->TabIndex = 9;
			this->button7->Text = L"reset";
			this->toolTip5->SetToolTip(this->button7, L"reset all performed processing");
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button10
			// 
			this->button10->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button10->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button10->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button10->Location = System::Drawing::Point(13, 158);
			this->button10->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(234, 38);
			this->button10->TabIndex = 12;
			this->button10->Text = L"Log Transformation";
			this->toolTip27->SetToolTip(this->button10, L"Used to expand values of dark pixels, while compressing\r\nhigher-level values.");
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(7, 45);
			this->trackBar1->Maximum = 50;
			this->trackBar1->Minimum = 1;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(219, 56);
			this->trackBar1->TabIndex = 13;
			this->trackBar1->Value = 1;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar1_Scroll);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Tahoma", 8));
			this->label1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label1->Location = System::Drawing::Point(46, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(73, 17);
			this->label1->TabIndex = 16;
			this->label1->Text = L" Value: 0.1";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"groupBox1.BackgroundImage")));
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->trackBar1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Tahoma", 8, System::Drawing::FontStyle::Bold));
			this->groupBox1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->groupBox1->Location = System::Drawing::Point(13, 35);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(239, 106);
			this->groupBox1->TabIndex = 17;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Gamma Transformation";
			this->toolTip19->SetToolTip(this->groupBox1, resources->GetString(L"groupBox1.ToolTip"));
			this->groupBox1->Enter += gcnew System::EventHandler(this, &MyForm::groupBox1_Enter);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->radioButton1->Location = System::Drawing::Point(16, 18);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(74, 20);
			this->radioButton1->TabIndex = 18;
			this->radioButton1->Text = L"Original";
			this->toolTip14->SetToolTip(this->radioButton1, L"When checked all process will be performed\r\non the original (opend) image.");
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton1_CheckedChanged);
			// 
			// groupBox2
			// 
			this->groupBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"groupBox2.BackgroundImage")));
			this->groupBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->groupBox2->Controls->Add(this->button36);
			this->groupBox2->Controls->Add(this->button35);
			this->groupBox2->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->groupBox2->Location = System::Drawing::Point(22, 420);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(179, 107);
			this->groupBox2->TabIndex = 19;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Zooming";
			this->groupBox2->Enter += gcnew System::EventHandler(this, &MyForm::groupBox2_Enter);
			// 
			// button36
			// 
			this->button36->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button36->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button36->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button36->Location = System::Drawing::Point(6, 70);
			this->button36->Name = L"button36";
			this->button36->Size = System::Drawing::Size(167, 28);
			this->button36->TabIndex = 34;
			this->button36->Text = L"Zoom In  the centre";
			this->toolTip25->SetToolTip(this->button36, L"Zoom In from the centre (scaling concept).");
			this->button36->UseVisualStyleBackColor = true;
			this->button36->Click += gcnew System::EventHandler(this, &MyForm::button36_Click);
			// 
			// button35
			// 
			this->button35->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button35->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button35->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button35->Location = System::Drawing::Point(6, 26);
			this->button35->Name = L"button35";
			this->button35->Size = System::Drawing::Size(167, 28);
			this->button35->TabIndex = 33;
			this->button35->Text = L"Zoom In with crop";
			this->toolTip24->SetToolTip(this->button35, L"Zoom In (crop concept).");
			this->button35->UseVisualStyleBackColor = true;
			this->button35->Click += gcnew System::EventHandler(this, &MyForm::button35_Click);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Checked = true;
			this->radioButton2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->radioButton2->Location = System::Drawing::Point(115, 18);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(94, 20);
			this->radioButton2->TabIndex = 20;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Processed";
			this->toolTip15->SetToolTip(this->radioButton2, L"When checked all process will be performed\r\non the processed image.\r\n");
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton2_CheckedChanged);
			// 
			// groupBox3
			// 
			this->groupBox3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"groupBox3.BackgroundImage")));
			this->groupBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->groupBox3->Controls->Add(this->groupBox24);
			this->groupBox3->Controls->Add(this->groupBox21);
			this->groupBox3->Controls->Add(this->groupBox15);
			this->groupBox3->Controls->Add(this->groupBox17);
			this->groupBox3->Controls->Add(this->histogram);
			this->groupBox3->Controls->Add(this->groupBox16);
			this->groupBox3->Controls->Add(this->groupBox4);
			this->groupBox3->Controls->Add(this->groupBox6);
			this->groupBox3->Controls->Add(this->groupBox5);
			this->groupBox3->Controls->Add(this->groupBox2);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox3->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->groupBox3->Location = System::Drawing::Point(510, 64);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(933, 537);
			this->groupBox3->TabIndex = 21;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Point Processing";
			// 
			// groupBox24
			// 
			this->groupBox24->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"groupBox24.BackgroundImage")));
			this->groupBox24->Controls->Add(this->button43);
			this->groupBox24->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox24->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->groupBox24->Location = System::Drawing::Point(16, 40);
			this->groupBox24->Name = L"groupBox24";
			this->groupBox24->Size = System::Drawing::Size(172, 79);
			this->groupBox24->TabIndex = 43;
			this->groupBox24->TabStop = false;
			this->groupBox24->Text = L"convert RGB to gray";
			// 
			// button43
			// 
			this->button43->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button43->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button43->Location = System::Drawing::Point(6, 29);
			this->button43->Name = L"button43";
			this->button43->Size = System::Drawing::Size(141, 33);
			this->button43->TabIndex = 42;
			this->button43->Text = L"gray image";
			this->button43->UseVisualStyleBackColor = true;
			this->button43->Click += gcnew System::EventHandler(this, &MyForm::button43_Click);
			// 
			// groupBox21
			// 
			this->groupBox21->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"groupBox21.BackgroundImage")));
			this->groupBox21->Controls->Add(this->button23);
			this->groupBox21->Controls->Add(this->comboBox1);
			this->groupBox21->Controls->Add(this->button13);
			this->groupBox21->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->groupBox21->Location = System::Drawing::Point(649, 358);
			this->groupBox21->Name = L"groupBox21";
			this->groupBox21->Size = System::Drawing::Size(265, 159);
			this->groupBox21->TabIndex = 41;
			this->groupBox21->TabStop = false;
			this->groupBox21->Text = L"slicing";
			// 
			// button23
			// 
			this->button23->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button23->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button23->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button23->Location = System::Drawing::Point(8, 97);
			this->button23->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button23->Name = L"button23";
			this->button23->Size = System::Drawing::Size(244, 40);
			this->button23->TabIndex = 28;
			this->button23->Text = L"Gray Level Slicing";
			this->toolTip30->SetToolTip(this->button23, L"Used to highlight gray range of interest to a viewer.\r\nUsed when we need to make "
				L"an object more clear.");
			this->button23->UseVisualStyleBackColor = true;
			this->button23->Click += gcnew System::EventHandler(this, &MyForm::button23_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(139, 48);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(113, 24);
			this->comboBox1->TabIndex = 25;
			this->comboBox1->Text = L"Select Plan no.";
			this->toolTip7->SetToolTip(this->comboBox1, L"Select plan number");
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// button13
			// 
			this->button13->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button13->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button13->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button13->Location = System::Drawing::Point(8, 39);
			this->button13->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(125, 40);
			this->button13->TabIndex = 21;
			this->button13->Text = L"Bit Plan Slicing";
			this->toolTip28->SetToolTip(this->button13, L"Bit plane slicing is a method of representing an image with\r\none or more bits of "
				L"the byte used for eachpixel.\r\nWhere M.S.B usually contain most of the significan"
				L"t visual information.");
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &MyForm::button13_Click);
			// 
			// groupBox15
			// 
			this->groupBox15->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"groupBox15.BackgroundImage")));
			this->groupBox15->Controls->Add(this->button6);
			this->groupBox15->Controls->Add(this->groupBox1);
			this->groupBox15->Controls->Add(this->button10);
			this->groupBox15->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->groupBox15->Location = System::Drawing::Point(649, 22);
			this->groupBox15->Name = L"groupBox15";
			this->groupBox15->Size = System::Drawing::Size(265, 260);
			this->groupBox15->TabIndex = 40;
			this->groupBox15->TabStop = false;
			this->groupBox15->Text = L"transformation";
			// 
			// groupBox17
			// 
			this->groupBox17->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"groupBox17.BackgroundImage")));
			this->groupBox17->Controls->Add(this->button4);
			this->groupBox17->Controls->Add(this->button3);
			this->groupBox17->Controls->Add(this->button2);
			this->groupBox17->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->groupBox17->Location = System::Drawing::Point(429, 28);
			this->groupBox17->Name = L"groupBox17";
			this->groupBox17->Size = System::Drawing::Size(189, 206);
			this->groupBox17->TabIndex = 39;
			this->groupBox17->TabStop = false;
			this->groupBox17->Text = L"flipping";
			// 
			// histogram
			// 
			this->histogram->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"histogram.BackgroundImage")));
			this->histogram->Controls->Add(this->histogram_button32);
			this->histogram->Controls->Add(this->button5);
			this->histogram->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->histogram->Location = System::Drawing::Point(429, 240);
			this->histogram->Name = L"histogram";
			this->histogram->Size = System::Drawing::Size(203, 112);
			this->histogram->TabIndex = 38;
			this->histogram->TabStop = false;
			this->histogram->Text = L"histogram";
			// 
			// histogram_button32
			// 
			this->histogram_button32->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->histogram_button32->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->histogram_button32->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->histogram_button32->Location = System::Drawing::Point(17, 32);
			this->histogram_button32->Name = L"histogram_button32";
			this->histogram_button32->Size = System::Drawing::Size(167, 32);
			this->histogram_button32->TabIndex = 31;
			this->histogram_button32->Text = L"histogram";
			this->histogram_button32->UseVisualStyleBackColor = true;
			this->histogram_button32->Click += gcnew System::EventHandler(this, &MyForm::histogram_button32_Click);
			// 
			// groupBox16
			// 
			this->groupBox16->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"groupBox16.BackgroundImage")));
			this->groupBox16->Controls->Add(this->button32);
			this->groupBox16->Controls->Add(this->groupBox10);
			this->groupBox16->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->groupBox16->Location = System::Drawing::Point(234, 358);
			this->groupBox16->Name = L"groupBox16";
			this->groupBox16->Size = System::Drawing::Size(379, 169);
			this->groupBox16->TabIndex = 37;
			this->groupBox16->TabStop = false;
			this->groupBox16->Text = L"gray level transformation";
			// 
			// button32
			// 
			this->button32->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->button32->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button32->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button32->Location = System::Drawing::Point(17, 17);
			this->button32->Name = L"button32";
			this->button32->Size = System::Drawing::Size(336, 30);
			this->button32->TabIndex = 36;
			this->button32->Text = L"increase pixel";
			this->button32->UseVisualStyleBackColor = false;
			this->button32->Click += gcnew System::EventHandler(this, &MyForm::button32_Click);
			// 
			// groupBox10
			// 
			this->groupBox10->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"groupBox10.BackgroundImage")));
			this->groupBox10->Controls->Add(this->label10);
			this->groupBox10->Controls->Add(this->trackBar6);
			this->groupBox10->Controls->Add(this->button16);
			this->groupBox10->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->groupBox10->Location = System::Drawing::Point(17, 53);
			this->groupBox10->Name = L"groupBox10";
			this->groupBox10->Size = System::Drawing::Size(336, 110);
			this->groupBox10->TabIndex = 30;
			this->groupBox10->TabStop = false;
			this->groupBox10->Text = L"Blinding";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label10->Location = System::Drawing::Point(138, 18);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(101, 16);
			this->label10->TabIndex = 21;
			this->label10->Text = L"Trancparency: 0";
			this->label10->Click += gcnew System::EventHandler(this, &MyForm::label10_Click);
			// 
			// trackBar6
			// 
			this->trackBar6->Location = System::Drawing::Point(98, 38);
			this->trackBar6->Name = L"trackBar6";
			this->trackBar6->Size = System::Drawing::Size(227, 56);
			this->trackBar6->TabIndex = 23;
			this->trackBar6->Value = 1;
			this->trackBar6->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar6_Scroll);
			// 
			// button16
			// 
			this->button16->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button16->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button16->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button16->Location = System::Drawing::Point(7, 21);
			this->button16->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(75, 76);
			this->button16->TabIndex = 22;
			this->button16->Text = L"Open Front Image";
			this->button16->UseVisualStyleBackColor = true;
			this->button16->Click += gcnew System::EventHandler(this, &MyForm::button16_Click);
			// 
			// groupBox4
			// 
			this->groupBox4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"groupBox4.BackgroundImage")));
			this->groupBox4->Controls->Add(this->button9);
			this->groupBox4->Controls->Add(this->textBox2);
			this->groupBox4->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox4->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->groupBox4->Location = System::Drawing::Point(6, 240);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(190, 165);
			this->groupBox4->TabIndex = 34;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Rotation (specific values)";
			// 
			// button9
			// 
			this->button9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button9->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button9->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button9->Location = System::Drawing::Point(7, 45);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(86, 98);
			this->button9->TabIndex = 2;
			this->button9->Text = L"Rotate";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click_1);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(110, 66);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(58, 23);
			this->textBox2->TabIndex = 0;
			this->textBox2->Text = L"angle ";
			this->textBox2->Click += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// groupBox6
			// 
			this->groupBox6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"groupBox6.BackgroundImage")));
			this->groupBox6->Controls->Add(this->button15);
			this->groupBox6->Controls->Add(this->button14);
			this->groupBox6->Controls->Add(this->button20);
			this->groupBox6->Controls->Add(this->button19);
			this->groupBox6->Font = (gcnew System::Drawing::Font(L"Tahoma", 8, System::Drawing::FontStyle::Bold));
			this->groupBox6->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->groupBox6->Location = System::Drawing::Point(8, 133);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(187, 101);
			this->groupBox6->TabIndex = 18;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Translation";
			// 
			// button15
			// 
			this->button15->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button15->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button15->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button15->Location = System::Drawing::Point(99, 58);
			this->button15->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(82, 32);
			this->button15->TabIndex = 25;
			this->button15->Text = L"-Y";
			this->toolTip22->SetToolTip(this->button15, L"Move the image down.\r\nmoving by 10 points.");
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Click += gcnew System::EventHandler(this, &MyForm::button15_Click);
			// 
			// button14
			// 
			this->button14->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button14->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button14->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button14->Location = System::Drawing::Point(99, 22);
			this->button14->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(82, 32);
			this->button14->TabIndex = 24;
			this->button14->Text = L"-X";
			this->toolTip21->SetToolTip(this->button14, L"Move the image to the left.\r\nmoving by 10 points.");
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &MyForm::button14_Click);
			// 
			// button20
			// 
			this->button20->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button20->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button20->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button20->Location = System::Drawing::Point(7, 57);
			this->button20->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(84, 32);
			this->button20->TabIndex = 23;
			this->button20->Text = L" Y";
			this->toolTip22->SetToolTip(this->button20, L"Move the image up.\r\nmoving by 10 points.");
			this->button20->UseVisualStyleBackColor = true;
			this->button20->Click += gcnew System::EventHandler(this, &MyForm::button20_Click);
			// 
			// button19
			// 
			this->button19->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button19->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button19->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button19->Location = System::Drawing::Point(7, 22);
			this->button19->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(84, 32);
			this->button19->TabIndex = 23;
			this->button19->Text = L" X";
			this->toolTip20->SetToolTip(this->button19, L"Move the image to the right.\r\nmoving by 10 points.");
			this->button19->UseVisualStyleBackColor = true;
			this->button19->Click += gcnew System::EventHandler(this, &MyForm::button19_Click);
			// 
			// groupBox5
			// 
			this->groupBox5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"groupBox5.BackgroundImage")));
			this->groupBox5->Controls->Add(this->button11);
			this->groupBox5->Controls->Add(this->label4);
			this->groupBox5->Controls->Add(this->trackBar4);
			this->groupBox5->Controls->Add(this->label3);
			this->groupBox5->Controls->Add(this->trackBar3);
			this->groupBox5->Font = (gcnew System::Drawing::Font(L"Tahoma", 8, System::Drawing::FontStyle::Bold));
			this->groupBox5->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->groupBox5->Location = System::Drawing::Point(202, 33);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(221, 312);
			this->groupBox5->TabIndex = 18;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"D_Skewing";
			this->toolTip26->SetToolTip(this->groupBox5, L"All parallel lines in the original image will still be parallel in\r\nthe output im"
				L"age. This transform is obtained from the\r\nrelation between three points.");
			// 
			// button11
			// 
			this->button11->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button11->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button11->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button11->Location = System::Drawing::Point(6, 263);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(210, 33);
			this->button11->TabIndex = 28;
			this->button11->Text = L"Adjust";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Tahoma", 8));
			this->label4->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label4->Location = System::Drawing::Point(82, 154);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(49, 17);
			this->label4->TabIndex = 27;
			this->label4->Text = L"-X-axis";
			this->label4->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			// 
			// trackBar4
			// 
			this->trackBar4->Location = System::Drawing::Point(6, 186);
			this->trackBar4->Maximum = 500;
			this->trackBar4->Minimum = 1;
			this->trackBar4->Name = L"trackBar4";
			this->trackBar4->Size = System::Drawing::Size(210, 56);
			this->trackBar4->SmallChange = 10;
			this->trackBar4->TabIndex = 26;
			this->toolTip11->SetToolTip(this->trackBar4, L"Slide the track bar to skew the image to the left");
			this->trackBar4->Value = 1;
			this->trackBar4->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar4_Scroll);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Tahoma", 8));
			this->label3->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label3->Location = System::Drawing::Point(77, 44);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(54, 17);
			this->label3->TabIndex = 16;
			this->label3->Text = L"+X-axis";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// trackBar3
			// 
			this->trackBar3->Location = System::Drawing::Point(5, 74);
			this->trackBar3->Maximum = 500;
			this->trackBar3->Minimum = 1;
			this->trackBar3->Name = L"trackBar3";
			this->trackBar3->Size = System::Drawing::Size(210, 56);
			this->trackBar3->SmallChange = 50;
			this->trackBar3->TabIndex = 13;
			this->toolTip10->SetToolTip(this->trackBar3, L"Slide the track bar to skew the image to the right");
			this->trackBar3->Value = 1;
			this->trackBar3->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar3_Scroll);
			// 
			// groupBox14
			// 
			this->groupBox14->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"groupBox14.BackgroundImage")));
			this->groupBox14->Controls->Add(this->gaussian_button32);
			this->groupBox14->Controls->Add(this->button17);
			this->groupBox14->Controls->Add(this->button8);
			this->groupBox14->Controls->Add(this->label12);
			this->groupBox14->Controls->Add(this->label11);
			this->groupBox14->Controls->Add(this->trackBar7);
			this->groupBox14->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox14->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->groupBox14->Location = System::Drawing::Point(510, 633);
			this->groupBox14->Name = L"groupBox14";
			this->groupBox14->Size = System::Drawing::Size(523, 158);
			this->groupBox14->TabIndex = 33;
			this->groupBox14->TabStop = false;
			this->groupBox14->Text = L"Segmentation";
			// 
			// gaussian_button32
			// 
			this->gaussian_button32->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->gaussian_button32->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->gaussian_button32->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->gaussian_button32->Location = System::Drawing::Point(251, 91);
			this->gaussian_button32->Name = L"gaussian_button32";
			this->gaussian_button32->Size = System::Drawing::Size(201, 36);
			this->gaussian_button32->TabIndex = 0;
			this->gaussian_button32->Text = L"gaussian";
			this->gaussian_button32->UseVisualStyleBackColor = true;
			this->gaussian_button32->Click += gcnew System::EventHandler(this, &MyForm::gaussian_button32_Click);
			// 
			// button17
			// 
			this->button17->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button17->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button17->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button17->Location = System::Drawing::Point(147, 22);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(88, 33);
			this->button17->TabIndex = 29;
			this->button17->Text = L"Adjust";
			this->button17->UseVisualStyleBackColor = true;
			this->button17->Click += gcnew System::EventHandler(this, &MyForm::button17_Click);
			// 
			// button8
			// 
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button8->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button8->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button8->Location = System::Drawing::Point(251, 28);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(201, 42);
			this->button8->TabIndex = 3;
			this->button8->Text = L"Edge Based Method";
			this->toolTip34->SetToolTip(this->button8, resources->GetString(L"button8.ToolTip"));
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click_1);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label12->Location = System::Drawing::Point(19, 54);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(68, 16);
			this->label12->TabIndex = 2;
			this->label12->Text = L"TH Value: ";
			this->label12->Click += gcnew System::EventHandler(this, &MyForm::label12_Click);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label11->Location = System::Drawing::Point(9, 27);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(110, 16);
			this->label11->TabIndex = 1;
			this->label11->Text = L"Threshold Method";
			this->toolTip36->SetToolTip(this->label11, resources->GetString(L"label11.ToolTip"));
			// 
			// trackBar7
			// 
			this->trackBar7->Location = System::Drawing::Point(8, 79);
			this->trackBar7->Maximum = 255;
			this->trackBar7->Minimum = 10;
			this->trackBar7->Name = L"trackBar7";
			this->trackBar7->Size = System::Drawing::Size(232, 56);
			this->trackBar7->TabIndex = 0;
			this->toolTip38->SetToolTip(this->trackBar7, L"Move the slider to adjust the TH value,\r\nthen click adjust to save it.");
			this->trackBar7->Value = 10;
			this->trackBar7->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar7_Scroll);
			// 
			// groupBox11
			// 
			this->groupBox11->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->groupBox11->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"groupBox11.BackgroundImage")));
			this->groupBox11->Controls->Add(this->button44);
			this->groupBox11->Controls->Add(this->groupBox20);
			this->groupBox11->Controls->Add(this->groupBox18);
			this->groupBox11->Controls->Add(this->groupBox13);
			this->groupBox11->Controls->Add(this->groupBox12);
			this->groupBox11->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox11->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->groupBox11->Location = System::Drawing::Point(1451, 64);
			this->groupBox11->Name = L"groupBox11";
			this->groupBox11->Size = System::Drawing::Size(340, 537);
			this->groupBox11->TabIndex = 31;
			this->groupBox11->TabStop = false;
			this->groupBox11->Text = L"Filters";
			// 
			// button44
			// 
			this->button44->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button44->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button44->Location = System::Drawing::Point(38, 356);
			this->button44->Name = L"button44";
			this->button44->Size = System::Drawing::Size(260, 23);
			this->button44->TabIndex = 52;
			this->button44->Text = L"laplacian filter";
			this->button44->UseVisualStyleBackColor = true;
			this->button44->Click += gcnew System::EventHandler(this, &MyForm::button44_Click_1);
			// 
			// groupBox20
			// 
			this->groupBox20->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"groupBox20.BackgroundImage")));
			this->groupBox20->Controls->Add(this->button38);
			this->groupBox20->Controls->Add(this->button31);
			this->groupBox20->Controls->Add(this->sobel_xy_button32);
			this->groupBox20->Controls->Add(this->button22);
			this->groupBox20->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->groupBox20->Location = System::Drawing::Point(30, 217);
			this->groupBox20->Name = L"groupBox20";
			this->groupBox20->Size = System::Drawing::Size(289, 135);
			this->groupBox20->TabIndex = 47;
			this->groupBox20->TabStop = false;
			this->groupBox20->Text = L"linear high pass (filter)";
			// 
			// button38
			// 
			this->button38->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button38->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button38->Location = System::Drawing::Point(8, 99);
			this->button38->Name = L"button38";
			this->button38->Size = System::Drawing::Size(262, 29);
			this->button38->TabIndex = 47;
			this->button38->Text = L"sobel";
			this->button38->UseVisualStyleBackColor = true;
			this->button38->Click += gcnew System::EventHandler(this, &MyForm::button38_Click);
			// 
			// button31
			// 
			this->button31->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button31->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button31->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button31->Location = System::Drawing::Point(7, 25);
			this->button31->Name = L"button31";
			this->button31->Size = System::Drawing::Size(128, 33);
			this->button31->TabIndex = 0;
			this->button31->Text = L"sobel in X\r\n";
			this->toolTip33->SetToolTip(this->button31, resources->GetString(L"button31.ToolTip"));
			this->button31->UseVisualStyleBackColor = true;
			this->button31->Click += gcnew System::EventHandler(this, &MyForm::button31_Click);
			// 
			// sobel_xy_button32
			// 
			this->sobel_xy_button32->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->sobel_xy_button32->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sobel_xy_button32->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->sobel_xy_button32->Location = System::Drawing::Point(8, 62);
			this->sobel_xy_button32->Name = L"sobel_xy_button32";
			this->sobel_xy_button32->Size = System::Drawing::Size(261, 33);
			this->sobel_xy_button32->TabIndex = 2;
			this->sobel_xy_button32->Text = L"sobel xy (diagonal)";
			this->sobel_xy_button32->UseVisualStyleBackColor = true;
			this->sobel_xy_button32->Click += gcnew System::EventHandler(this, &MyForm::sobel_xy_button32_Click);
			// 
			// button22
			// 
			this->button22->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button22->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button22->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button22->Location = System::Drawing::Point(147, 27);
			this->button22->Name = L"button22";
			this->button22->Size = System::Drawing::Size(128, 31);
			this->button22->TabIndex = 1;
			this->button22->Text = L"sobel  in Y";
			this->toolTip39->SetToolTip(this->button22, resources->GetString(L"button22.ToolTip"));
			this->button22->UseVisualStyleBackColor = true;
			this->button22->Click += gcnew System::EventHandler(this, &MyForm::button22_Click);
			// 
			// groupBox18
			// 
			this->groupBox18->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"groupBox18.BackgroundImage")));
			this->groupBox18->Controls->Add(this->button33);
			this->groupBox18->Controls->Add(this->textBox5);
			this->groupBox18->Controls->Add(this->textBox4);
			this->groupBox18->Controls->Add(this->button37);
			this->groupBox18->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->groupBox18->Location = System::Drawing::Point(30, 385);
			this->groupBox18->Name = L"groupBox18";
			this->groupBox18->Size = System::Drawing::Size(289, 132);
			this->groupBox18->TabIndex = 46;
			this->groupBox18->TabStop = false;
			this->groupBox18->Text = L"fourier";
			// 
			// button33
			// 
			this->button33->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button33->Location = System::Drawing::Point(6, 21);
			this->button33->Name = L"button33";
			this->button33->Size = System::Drawing::Size(191, 35);
			this->button33->TabIndex = 42;
			this->button33->Text = L"High frequency";
			this->button33->UseVisualStyleBackColor = true;
			this->button33->Click += gcnew System::EventHandler(this, &MyForm::button33_Click);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(204, 85);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(65, 23);
			this->textBox5->TabIndex = 45;
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox5_TextChanged);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(203, 25);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(65, 23);
			this->textBox4->TabIndex = 43;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox4_TextChanged);
			// 
			// button37
			// 
			this->button37->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button37->Location = System::Drawing::Point(6, 76);
			this->button37->Name = L"button37";
			this->button37->Size = System::Drawing::Size(191, 40);
			this->button37->TabIndex = 44;
			this->button37->Text = L"Low frequency";
			this->button37->UseVisualStyleBackColor = true;
			this->button37->Click += gcnew System::EventHandler(this, &MyForm::button37_Click);
			// 
			// groupBox13
			// 
			this->groupBox13->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"groupBox13.BackgroundImage")));
			this->groupBox13->Controls->Add(this->button29);
			this->groupBox13->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox13->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->groupBox13->Location = System::Drawing::Point(30, 139);
			this->groupBox13->Name = L"groupBox13";
			this->groupBox13->Size = System::Drawing::Size(289, 65);
			this->groupBox13->TabIndex = 32;
			this->groupBox13->TabStop = false;
			this->groupBox13->Text = L"Order Statistical (Filters)";
			this->toolTip31->SetToolTip(this->groupBox13, L"Remove salt and pepper noise while preserved the Edges.");
			// 
			// button29
			// 
			this->button29->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button29->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button29->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button29->Location = System::Drawing::Point(7, 22);
			this->button29->Name = L"button29";
			this->button29->Size = System::Drawing::Size(262, 33);
			this->button29->TabIndex = 0;
			this->button29->Text = L"Median Blur";
			this->toolTip32->SetToolTip(this->button29, L"Used to enhance the spark noise,\r\nwith preserving the sharp edges.\r\nHint: Kernel "
				L"adjusted to size = 9");
			this->button29->UseVisualStyleBackColor = true;
			this->button29->Click += gcnew System::EventHandler(this, &MyForm::button29_Click);
			// 
			// groupBox12
			// 
			this->groupBox12->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"groupBox12.BackgroundImage")));
			this->groupBox12->Controls->Add(this->button30);
			this->groupBox12->Controls->Add(this->button26);
			this->groupBox12->Controls->Add(this->button28);
			this->groupBox12->Controls->Add(this->button27);
			this->groupBox12->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox12->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->groupBox12->Location = System::Drawing::Point(30, 13);
			this->groupBox12->Name = L"groupBox12";
			this->groupBox12->Size = System::Drawing::Size(289, 116);
			this->groupBox12->TabIndex = 32;
			this->groupBox12->TabStop = false;
			this->groupBox12->Text = L"Linear Filters (smoothing)";
			this->toolTip35->SetToolTip(this->groupBox12, L"Remove spark noise (reduce irrelevant detail in image),\r\nbut make blluring edges."
				L"");
			// 
			// button30
			// 
			this->button30->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button30->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button30->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button30->Location = System::Drawing::Point(153, 78);
			this->button30->Name = L"button30";
			this->button30->Size = System::Drawing::Size(122, 29);
			this->button30->TabIndex = 0;
			this->button30->Text = L"circular filter";
			this->button30->UseVisualStyleBackColor = true;
			this->button30->Click += gcnew System::EventHandler(this, &MyForm::button30_Click);
			// 
			// button26
			// 
			this->button26->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button26->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button26->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button26->Location = System::Drawing::Point(7, 28);
			this->button26->Name = L"button26";
			this->button26->Size = System::Drawing::Size(134, 32);
			this->button26->TabIndex = 0;
			this->button26->Text = L"traditional";
			this->button26->UseVisualStyleBackColor = true;
			this->button26->Click += gcnew System::EventHandler(this, &MyForm::button26_Click);
			// 
			// button28
			// 
			this->button28->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button28->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button28->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button28->Location = System::Drawing::Point(7, 78);
			this->button28->Name = L"button28";
			this->button28->Size = System::Drawing::Size(134, 29);
			this->button28->TabIndex = 0;
			this->button28->Text = L"cone  filter";
			this->button28->UseVisualStyleBackColor = true;
			this->button28->Click += gcnew System::EventHandler(this, &MyForm::button28_Click);
			// 
			// button27
			// 
			this->button27->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button27->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button27->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button27->Location = System::Drawing::Point(153, 27);
			this->button27->Name = L"button27";
			this->button27->Size = System::Drawing::Size(123, 33);
			this->button27->TabIndex = 0;
			this->button27->Text = L"pyramidal filter";
			this->button27->UseVisualStyleBackColor = true;
			this->button27->Click += gcnew System::EventHandler(this, &MyForm::button27_Click);
			// 
			// groupBox8
			// 
			this->groupBox8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"groupBox8.BackgroundImage")));
			this->groupBox8->Controls->Add(this->label9);
			this->groupBox8->Controls->Add(this->label7);
			this->groupBox8->Controls->Add(this->label6);
			this->groupBox8->Controls->Add(this->label5);
			this->groupBox8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->groupBox8->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox8->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->groupBox8->Location = System::Drawing::Point(16, 628);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Size = System::Drawing::Size(227, 163);
			this->groupBox8->TabIndex = 29;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"Image Details";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label9->Location = System::Drawing::Point(15, 116);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(81, 16);
			this->label9->TabIndex = 2;
			this->label9->Text = L"Dimensions: ";
			this->label9->Click += gcnew System::EventHandler(this, &MyForm::label9_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label7->Location = System::Drawing::Point(16, 84);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(63, 16);
			this->label7->TabIndex = 1;
			this->label7->Text = L"Average: ";
			this->label7->Click += gcnew System::EventHandler(this, &MyForm::label7_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label6->Location = System::Drawing::Point(16, 59);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(36, 16);
			this->label6->TabIndex = 1;
			this->label6->Text = L"Min: ";
			this->label6->Click += gcnew System::EventHandler(this, &MyForm::label6_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label5->Location = System::Drawing::Point(16, 32);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(39, 16);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Max: ";
			this->label5->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			// 
			// button24
			// 
			this->button24->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button24->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button24->Location = System::Drawing::Point(673, 21);
			this->button24->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button24->Name = L"button24";
			this->button24->Size = System::Drawing::Size(133, 29);
			this->button24->TabIndex = 22;
			this->button24->Text = L"save";
			this->toolTip4->SetToolTip(this->button24, L"Save the processed image.");
			this->button24->UseVisualStyleBackColor = true;
			this->button24->Click += gcnew System::EventHandler(this, &MyForm::button24_Click);
			// 
			// groupBox9
			// 
			this->groupBox9->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"groupBox9.BackgroundImage")));
			this->groupBox9->Controls->Add(this->button34);
			this->groupBox9->Controls->Add(this->radioButton1);
			this->groupBox9->Controls->Add(this->radioButton2);
			this->groupBox9->Controls->Add(this->button7);
			this->groupBox9->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->groupBox9->Location = System::Drawing::Point(833, 12);
			this->groupBox9->Name = L"groupBox9";
			this->groupBox9->Size = System::Drawing::Size(610, 46);
			this->groupBox9->TabIndex = 30;
			this->groupBox9->TabStop = false;
			this->groupBox9->Text = L"Select to be process image";
			// 
			// button34
			// 
			this->button34->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button34->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button34->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button34->Location = System::Drawing::Point(420, 15);
			this->button34->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button34->Name = L"button34";
			this->button34->Size = System::Drawing::Size(180, 26);
			this->button34->TabIndex = 21;
			this->button34->Text = L"close all windows";
			this->toolTip8->SetToolTip(this->button34, L"Close All Opened Windows");
			this->button34->UseVisualStyleBackColor = true;
			this->button34->Click += gcnew System::EventHandler(this, &MyForm::button34_Click);
			// 
			// button25
			// 
			this->button25->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button25->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button25->Location = System::Drawing::Point(508, 21);
			this->button25->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button25->Name = L"button25";
			this->button25->Size = System::Drawing::Size(133, 29);
			this->button25->TabIndex = 31;
			this->button25->Text = L"restart";
			this->toolTip3->SetToolTip(this->button25, L"To restart the tool");
			this->button25->UseVisualStyleBackColor = true;
			this->button25->Click += gcnew System::EventHandler(this, &MyForm::button25_Click);
			// 
			// toolTip1
			// 
			this->toolTip1->AutoPopDelay = 15000;
			this->toolTip1->InitialDelay = 500;
			this->toolTip1->ReshowDelay = 100;
			// 
			// toolTip2
			// 
			this->toolTip2->AutoPopDelay = 15000;
			this->toolTip2->InitialDelay = 500;
			this->toolTip2->ReshowDelay = 100;
			// 
			// toolTip3
			// 
			this->toolTip3->AutoPopDelay = 15000;
			this->toolTip3->InitialDelay = 500;
			this->toolTip3->ReshowDelay = 100;
			// 
			// toolTip4
			// 
			this->toolTip4->AutoPopDelay = 15000;
			this->toolTip4->InitialDelay = 500;
			this->toolTip4->ReshowDelay = 100;
			// 
			// toolTip5
			// 
			this->toolTip5->AutoPopDelay = 15000;
			this->toolTip5->InitialDelay = 500;
			this->toolTip5->ReshowDelay = 100;
			// 
			// toolTip6
			// 
			this->toolTip6->AutoPopDelay = 15000;
			this->toolTip6->InitialDelay = 500;
			this->toolTip6->ReshowDelay = 100;
			// 
			// toolTip8
			// 
			this->toolTip8->AutoPopDelay = 15000;
			this->toolTip8->InitialDelay = 500;
			this->toolTip8->ReshowDelay = 100;
			// 
			// toolTip7
			// 
			this->toolTip7->AutoPopDelay = 15000;
			this->toolTip7->InitialDelay = 500;
			this->toolTip7->ReshowDelay = 100;
			// 
			// toolTip9
			// 
			this->toolTip9->AutoPopDelay = 15000;
			this->toolTip9->InitialDelay = 500;
			this->toolTip9->ReshowDelay = 100;
			// 
			// toolTip10
			// 
			this->toolTip10->AutoPopDelay = 15000;
			this->toolTip10->InitialDelay = 500;
			this->toolTip10->ReshowDelay = 100;
			// 
			// toolTip11
			// 
			this->toolTip11->AutoPopDelay = 15000;
			this->toolTip11->InitialDelay = 500;
			this->toolTip11->ReshowDelay = 100;
			// 
			// toolTip12
			// 
			this->toolTip12->AutoPopDelay = 15000;
			this->toolTip12->InitialDelay = 500;
			this->toolTip12->ReshowDelay = 100;
			// 
			// toolTip13
			// 
			this->toolTip13->AutoPopDelay = 15000;
			this->toolTip13->InitialDelay = 500;
			this->toolTip13->ReshowDelay = 100;
			// 
			// toolTip14
			// 
			this->toolTip14->AutoPopDelay = 15000;
			this->toolTip14->InitialDelay = 500;
			this->toolTip14->ReshowDelay = 100;
			// 
			// toolTip15
			// 
			this->toolTip15->AutoPopDelay = 15000;
			this->toolTip15->InitialDelay = 500;
			this->toolTip15->ReshowDelay = 100;
			// 
			// toolTip16
			// 
			this->toolTip16->AutoPopDelay = 15000;
			this->toolTip16->InitialDelay = 500;
			this->toolTip16->ReshowDelay = 100;
			// 
			// toolTip17
			// 
			this->toolTip17->AutoPopDelay = 15000;
			this->toolTip17->InitialDelay = 500;
			this->toolTip17->ReshowDelay = 100;
			// 
			// toolTip18
			// 
			this->toolTip18->AutoPopDelay = 15000;
			this->toolTip18->InitialDelay = 500;
			this->toolTip18->ReshowDelay = 100;
			// 
			// toolTip19
			// 
			this->toolTip19->AutoPopDelay = 15000;
			this->toolTip19->InitialDelay = 500;
			this->toolTip19->ReshowDelay = 100;
			// 
			// toolTip20
			// 
			this->toolTip20->AutoPopDelay = 15000;
			this->toolTip20->InitialDelay = 500;
			this->toolTip20->ReshowDelay = 100;
			// 
			// toolTip21
			// 
			this->toolTip21->AutoPopDelay = 15000;
			this->toolTip21->InitialDelay = 500;
			this->toolTip21->ReshowDelay = 100;
			// 
			// toolTip22
			// 
			this->toolTip22->AutoPopDelay = 15000;
			this->toolTip22->InitialDelay = 500;
			this->toolTip22->ReshowDelay = 100;
			// 
			// toolTip23
			// 
			this->toolTip23->AutoPopDelay = 15000;
			this->toolTip23->InitialDelay = 500;
			this->toolTip23->ReshowDelay = 100;
			// 
			// toolTip24
			// 
			this->toolTip24->AutoPopDelay = 15000;
			this->toolTip24->InitialDelay = 500;
			this->toolTip24->ReshowDelay = 100;
			// 
			// toolTip25
			// 
			this->toolTip25->AutoPopDelay = 15000;
			this->toolTip25->InitialDelay = 500;
			this->toolTip25->ReshowDelay = 100;
			// 
			// toolTip26
			// 
			this->toolTip26->AutoPopDelay = 15000;
			this->toolTip26->InitialDelay = 500;
			this->toolTip26->ReshowDelay = 100;
			// 
			// toolTip27
			// 
			this->toolTip27->AutoPopDelay = 15000;
			this->toolTip27->InitialDelay = 500;
			this->toolTip27->ReshowDelay = 100;
			// 
			// toolTip28
			// 
			this->toolTip28->AutoPopDelay = 15000;
			this->toolTip28->InitialDelay = 500;
			this->toolTip28->ReshowDelay = 100;
			// 
			// toolTip29
			// 
			this->toolTip29->AutoPopDelay = 15000;
			this->toolTip29->InitialDelay = 500;
			this->toolTip29->ReshowDelay = 100;
			// 
			// toolTip30
			// 
			this->toolTip30->AutoPopDelay = 15000;
			this->toolTip30->InitialDelay = 500;
			this->toolTip30->ReshowDelay = 100;
			// 
			// toolTip31
			// 
			this->toolTip31->AutoPopDelay = 15000;
			this->toolTip31->InitialDelay = 500;
			this->toolTip31->ReshowDelay = 100;
			// 
			// toolTip32
			// 
			this->toolTip32->AutoPopDelay = 15000;
			this->toolTip32->InitialDelay = 500;
			this->toolTip32->ReshowDelay = 100;
			// 
			// toolTip33
			// 
			this->toolTip33->AutoPopDelay = 15000;
			this->toolTip33->InitialDelay = 500;
			this->toolTip33->ReshowDelay = 100;
			// 
			// toolTip34
			// 
			this->toolTip34->AutoPopDelay = 15000;
			this->toolTip34->InitialDelay = 500;
			this->toolTip34->ReshowDelay = 100;
			// 
			// toolTip35
			// 
			this->toolTip35->AutoPopDelay = 15000;
			this->toolTip35->InitialDelay = 500;
			this->toolTip35->ReshowDelay = 100;
			// 
			// toolTip36
			// 
			this->toolTip36->AutoPopDelay = 15000;
			this->toolTip36->InitialDelay = 500;
			this->toolTip36->ReshowDelay = 100;
			// 
			// toolTip37
			// 
			this->toolTip37->AutoPopDelay = 15000;
			this->toolTip37->InitialDelay = 500;
			this->toolTip37->ReshowDelay = 100;
			// 
			// toolTip38
			// 
			this->toolTip38->AutoPopDelay = 15000;
			this->toolTip38->InitialDelay = 500;
			this->toolTip38->ReshowDelay = 100;
			// 
			// button12
			// 
			this->button12->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button12->Location = System::Drawing::Point(6, 28);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(158, 31);
			this->button12->TabIndex = 34;
			this->button12->Text = L"edge detection";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
			// 
			// button18
			// 
			this->button18->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button18->Location = System::Drawing::Point(6, 70);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(158, 30);
			this->button18->TabIndex = 35;
			this->button18->Text = L"prewit horizontal";
			this->button18->UseVisualStyleBackColor = true;
			this->button18->Click += gcnew System::EventHandler(this, &MyForm::button18_Click);
			// 
			// button21
			// 
			this->button21->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button21->Location = System::Drawing::Point(6, 114);
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(158, 29);
			this->button21->TabIndex = 36;
			this->button21->Text = L"prewit vertical";
			this->button21->UseVisualStyleBackColor = true;
			this->button21->Click += gcnew System::EventHandler(this, &MyForm::button21_Click);
			// 
			// groupBox7
			// 
			this->groupBox7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"groupBox7.BackgroundImage")));
			this->groupBox7->Controls->Add(this->button12);
			this->groupBox7->Controls->Add(this->button21);
			this->groupBox7->Controls->Add(this->button18);
			this->groupBox7->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->groupBox7->Location = System::Drawing::Point(1613, 633);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(178, 158);
			this->groupBox7->TabIndex = 41;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"prewit";
			// 
			// button39
			// 
			this->button39->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button39->Location = System::Drawing::Point(13, 35);
			this->button39->Name = L"button39";
			this->button39->Size = System::Drawing::Size(190, 30);
			this->button39->TabIndex = 43;
			this->button39->Text = L"add noise gaussian";
			this->button39->UseVisualStyleBackColor = true;
			this->button39->Click += gcnew System::EventHandler(this, &MyForm::button39_Click);
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(220, 42);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(38, 22);
			this->textBox6->TabIndex = 44;
			this->textBox6->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox6_TextChanged);
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(283, 44);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(42, 22);
			this->textBox7->TabIndex = 45;
			this->textBox7->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox7_TextChanged);
			// 
			// button40
			// 
			this->button40->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button40->Location = System::Drawing::Point(13, 85);
			this->button40->Name = L"button40";
			this->button40->Size = System::Drawing::Size(190, 29);
			this->button40->TabIndex = 46;
			this->button40->Text = L"add salt pepper ";
			this->button40->UseVisualStyleBackColor = true;
			this->button40->Click += gcnew System::EventHandler(this, &MyForm::button40_Click);
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(220, 92);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(43, 22);
			this->textBox8->TabIndex = 47;
			this->textBox8->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox8_TextChanged);
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(283, 92);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(42, 22);
			this->textBox9->TabIndex = 48;
			this->textBox9->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox9_TextChanged);
			// 
			// button41
			// 
			this->button41->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button41->Location = System::Drawing::Point(13, 130);
			this->button41->Name = L"button41";
			this->button41->Size = System::Drawing::Size(312, 23);
			this->button41->TabIndex = 49;
			this->button41->Text = L"add impulse noise";
			this->button41->UseVisualStyleBackColor = true;
			this->button41->Click += gcnew System::EventHandler(this, &MyForm::button41_Click);
			// 
			// groupBox22
			// 
			this->groupBox22->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"groupBox22.BackgroundImage")));
			this->groupBox22->Controls->Add(this->label14);
			this->groupBox22->Controls->Add(this->label13);
			this->groupBox22->Controls->Add(this->label8);
			this->groupBox22->Controls->Add(this->label2);
			this->groupBox22->Controls->Add(this->button39);
			this->groupBox22->Controls->Add(this->textBox7);
			this->groupBox22->Controls->Add(this->button41);
			this->groupBox22->Controls->Add(this->textBox6);
			this->groupBox22->Controls->Add(this->textBox8);
			this->groupBox22->Controls->Add(this->button40);
			this->groupBox22->Controls->Add(this->textBox9);
			this->groupBox22->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->groupBox22->Location = System::Drawing::Point(1253, 633);
			this->groupBox22->Name = L"groupBox22";
			this->groupBox22->Size = System::Drawing::Size(341, 163);
			this->groupBox22->TabIndex = 50;
			this->groupBox22->TabStop = false;
			this->groupBox22->Text = L"add noise";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label14->Location = System::Drawing::Point(283, 73);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(23, 16);
			this->label14->TabIndex = 53;
			this->label14->Text = L"pb";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label13->Location = System::Drawing::Point(234, 73);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(23, 16);
			this->label13->TabIndex = 52;
			this->label13->Text = L"pa";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label8->Location = System::Drawing::Point(281, 18);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(44, 16);
			this->label8->TabIndex = 51;
			this->label8->Text = L"sigma";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label2->Location = System::Drawing::Point(216, 18);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(41, 16);
			this->label2->TabIndex = 50;
			this->label2->Text = L"mean";
			// 
			// groupBox23
			// 
			this->groupBox23->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"groupBox23.BackgroundImage")));
			this->groupBox23->Controls->Add(this->button42);
			this->groupBox23->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->groupBox23->Location = System::Drawing::Point(254, 635);
			this->groupBox23->Name = L"groupBox23";
			this->groupBox23->Size = System::Drawing::Size(239, 156);
			this->groupBox23->TabIndex = 51;
			this->groupBox23->TabStop = false;
			this->groupBox23->Text = L"recognition";
			// 
			// button42
			// 
			this->button42->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button42->Location = System::Drawing::Point(18, 52);
			this->button42->Name = L"button42";
			this->button42->Size = System::Drawing::Size(200, 49);
			this->button42->TabIndex = 0;
			this->button42->Text = L"object recognition";
			this->button42->UseVisualStyleBackColor = true;
			this->button42->Click += gcnew System::EventHandler(this, &MyForm::button42_Click);
			// 
			// groupBox19
			// 
			this->groupBox19->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"groupBox19.BackgroundImage")));
			this->groupBox19->Controls->Add(this->cmpression_scale);
			this->groupBox19->Controls->Add(this->button45);
			this->groupBox19->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->groupBox19->Location = System::Drawing::Point(1055, 645);
			this->groupBox19->Name = L"groupBox19";
			this->groupBox19->Size = System::Drawing::Size(173, 141);
			this->groupBox19->TabIndex = 52;
			this->groupBox19->TabStop = false;
			this->groupBox19->Text = L"compression huffman";
			// 
			// cmpression_scale
			// 
			this->cmpression_scale->Location = System::Drawing::Point(34, 42);
			this->cmpression_scale->Name = L"cmpression_scale";
			this->cmpression_scale->Size = System::Drawing::Size(73, 22);
			this->cmpression_scale->TabIndex = 1;
			this->cmpression_scale->TextChanged += gcnew System::EventHandler(this, &MyForm::cmpression_scale_TextChanged);
			// 
			// button45
			// 
			this->button45->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button45->Location = System::Drawing::Point(6, 76);
			this->button45->Name = L"button45";
			this->button45->Size = System::Drawing::Size(155, 39);
			this->button45->TabIndex = 0;
			this->button45->Text = L"compression";
			this->button45->UseVisualStyleBackColor = true;
			this->button45->Click += gcnew System::EventHandler(this, &MyForm::button45_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1924, 818);
			this->Controls->Add(this->groupBox19);
			this->Controls->Add(this->groupBox23);
			this->Controls->Add(this->groupBox22);
			this->Controls->Add(this->groupBox7);
			this->Controls->Add(this->groupBox14);
			this->Controls->Add(this->groupBox8);
			this->Controls->Add(this->button25);
			this->Controls->Add(this->groupBox11);
			this->Controls->Add(this->groupBox9);
			this->Controls->Add(this->button24);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->HelpButton = true;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"youssef moustafa (tool box)";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox24->ResumeLayout(false);
			this->groupBox21->ResumeLayout(false);
			this->groupBox15->ResumeLayout(false);
			this->groupBox17->ResumeLayout(false);
			this->histogram->ResumeLayout(false);
			this->groupBox16->ResumeLayout(false);
			this->groupBox10->ResumeLayout(false);
			this->groupBox10->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar6))->EndInit();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox6->ResumeLayout(false);
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->EndInit();
			this->groupBox14->ResumeLayout(false);
			this->groupBox14->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar7))->EndInit();
			this->groupBox11->ResumeLayout(false);
			this->groupBox20->ResumeLayout(false);
			this->groupBox18->ResumeLayout(false);
			this->groupBox18->PerformLayout();
			this->groupBox13->ResumeLayout(false);
			this->groupBox12->ResumeLayout(false);
			this->groupBox8->ResumeLayout(false);
			this->groupBox8->PerformLayout();
			this->groupBox9->ResumeLayout(false);
			this->groupBox9->PerformLayout();
			this->groupBox7->ResumeLayout(false);
			this->groupBox22->ResumeLayout(false);
			this->groupBox22->PerformLayout();
			this->groupBox23->ResumeLayout(false);
			this->groupBox19->ResumeLayout(false);
			this->groupBox19->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

//////////////////////////////////(Basic Form Plans)///////////////////////////////////////////
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e)
	{
	//combobox filling for bit plan 
	comboBox1->Items->Add(0);
	comboBox1->Items->Add(1);
	comboBox1->Items->Add(2);
	comboBox1->Items->Add(3);
	comboBox1->Items->Add(4);
	comboBox1->Items->Add(5);
	comboBox1->Items->Add(6);
	comboBox1->Items->Add(7);
	}
//textbox showing the directory 
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void groupBox2_Enter(System::Object^ sender, System::EventArgs^ e) {
}
//picture Box // to Show the image in Box 
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e)
	{

	}
#pragma region // details label 
	   // maximum label
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {

}
	   // minimum label
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}
	   // average label
private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
}
	   // dimension label
private: System::Void label9_Click(System::Object^ sender, System::EventArgs^ e) {
}
# pragma endregion
//Open button // to load the image
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		IO::Stream^ myStream; // to open file stream	//to hold the image file
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

		openFileDialog1->InitialDirectory = "Desktop";
		openFileDialog1->Filter = "Image files (*.png)|*.png|All files|*.*|Image files (*.jpg)|*.jpg";
		openFileDialog1->FilterIndex = 2;
		openFileDialog1->RestoreDirectory = true;

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			if ((myStream = openFileDialog1->OpenFile()) != nullptr)
			{
				// Insert code to read the stream here. (image file)
				GUI2::String^ selectedFile = openFileDialog1->FileName; // create file stream
				this->pictureBox1->ImageLocation = selectedFile; // Display The Selected Image in PicBox
				textBox1->Text = openFileDialog1->FileName; // Show the Dir of the selected Image
				marshal_context converter;
				const char* str2 = converter.marshal_as<const char*>(openFileDialog1->FileName);
				src = imread(str2, 1); // read the image as Mat type to be processed in colored operation
				original = src; //to save orginal image and retreive it when needed
				grayImg = imread(str2, 0); // read the image in grayscale as Mat type to be processed in point porcessing
				bitplnImg = grayImg; //to be processed in bitplan
				grayOrg = grayImg; //to save gray image and retreive it when needed for point porcessing
				imwrite("temp.png", src); // keep original image for resestting
				myStream->Close();
			}
		}
		int max, min;
		float avg;
		max = maxMeasure(src);
		min = minMeasure(src);
		avg = StatMeasure(src);
		//call max function in Max variable
		this->label5->Text = "Max: " + max;
		//call min function in Min variable
		this->label6->Text = "Min: " + min;
		//call avg function in avg variable
		this->label7->Text = "Average: " + avg;
		//Dimensions
		this->label9->Text = "Dimensions: " + src.rows + " x " + src.cols;

	}
//save button
private: System::Void button24_Click(System::Object^ sender, System::EventArgs^ e) {
	// Displays a SaveFileDialog so the user can save the Image // assigned to Button2.
	SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog;
	saveFileDialog1->Filter = "JPeg Image|*.jpg|Bitmap Image|*.bmp|Gif Image|*.gif";
	saveFileDialog1->Title = "Save an Image File";
	saveFileDialog1->ShowDialog();
	// If the file name is not an empty string open it for saving.
	if (saveFileDialog1->FileName != "")
	{
		marshal_context converter;
		const char* str2 = converter.marshal_as<const char*>(saveFileDialog1->FileName);
		//imwrite(str2, src);
		imwrite(str2, grayImg);
	}
}
//restart button
private: System::Void button25_Click(System::Object^ sender, System::EventArgs^ e) {
	destroyAllWindows();
	Application::Restart();
}
//reseting button
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	if (src.data) 
	{
	src = imread("temp.png",1);
	grayImg = imread("temp.png", 0);
	showImg(src);
	}
}
//close all windows button
private: System::Void button34_Click(System::Object^ sender, System::EventArgs^ e) {
	pictureBox1->ImageLocation = "" ;
	
}
// radio buttons for select to be processed image

//original checked
private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
//processed checked
private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
/*////////////////////////////////////(Buttons)\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
#pragma region // flipping buttons
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	grayImg = flipping(grayImg, -1);
	showImg(grayImg);
}
//flip around X button
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	grayImg = flipping(grayImg, 0);
	showImg(grayImg);
}
//flip around Y button
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	grayImg = flipping(grayImg, 1);
	showImg(grayImg);
}
//flipping function
private: Mat flipping(Mat src, int fcode) {	// flip the image 
	flip(src, src, fcode);
	return src;	// after process return destination image.
}
#pragma endregion
#pragma region // point processing
//Histogram equalization button
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	equalizeHist(grayImg, grayImg);
	showImg(grayImg);
}
//Negative button // 
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	for (int i = 0; i < grayImg.rows; i++)
		for (int j = 0; j < grayImg.cols; j++)
			grayImg.at<uchar>(i, j) = 255 - grayImg.at<uchar>(i, j);
	showImg(grayImg);
}
// Log Transformation button 
private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
	grayImg.convertTo(grayImg, CV_32F);
	grayImg = grayImg + 1;
	log(grayImg, grayImg);
	normalize(grayImg, grayImg, 0, 255, NORM_MINMAX);
	convertScaleAbs(grayImg, grayImg);
	showImg(grayImg);
}
//gamma transformation button
private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) {
	this->label1->Text = "Gamma Value: " + (trackBar1->Value) * 0.1;
	float gammaVal = trackBar1->Value;
	temp = grayImg;
	grayImg.convertTo(grayImg, CV_32F);
	for (int r = 0; r < grayImg.rows; r++)
		for (int c = 0; c < grayImg.cols; c++)
			grayImg.at<float>(r, c) = powf(grayImg.at<float>(r, c), gammaVal * 0.1);

	normalize(grayImg, grayImg, 0, 255, NORM_MINMAX);
	convertScaleAbs(grayImg, grayImg);
	showImg(grayImg);
	grayImg = temp;
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
// gray level slicing button
private: System::Void button23_Click(System::Object^ sender, System::EventArgs^ e) {
	for (int i = 0; i < grayImg.rows; i++)
		for (int j = 0; j < grayImg.cols; j++)
			if (grayImg.at<uchar>(i, j) > 130 && grayImg.at<uchar>(i, j) < 200)
				grayImg.at<uchar>(i, j) = 255;
			else
				grayImg.at<uchar>(i, j) = grayImg.at<uchar>(i, j);
	showImg(grayImg);
}
#pragma endregion
#pragma region //  Zooming 
//Zoom In + button with crop
private: System::Void button35_Click(System::Object^ sender, System::EventArgs^ e) {
	grayImg = grayImg(Rect(180, 50, grayImg.rows / 2, grayImg.cols / 2));
	resize(grayImg, grayImg, cv::Size(), 2, 2, 0);
	showImg(grayImg);
}
//Zoom In  button from the centre
private: System::Void button36_Click(System::Object^ sender, System::EventArgs^ e) {
	Mat R = getRotationMatrix2D(Point2f(grayImg.rows / 2, grayImg.cols / 2), 0, 1.3); // scaling without rotation
	warpAffine(grayImg, grayImg, R, grayImg.size());
	showImg(grayImg);
}
#pragma endregion
#pragma region // Statistics Measure fnctions 
private: int maxMeasure(Mat& image) {
	int max = 0;
	if (!image.data) // handle error while open and does not select an image 
		return 0;
	for (int i = 0; i < src.rows; i++)
	{
		for (int j = 0; j < src.cols; j++)
		{
			if (src.at<uchar>(i, j) > max)
			{
				max = src.at<uchar>(i, j);
			}
		}
	}
	return  max;
}
	   private: int minMeasure(Mat& image) {
		   int min = 255;
		   if (!image.data) // handle error while open and does not select an image 
			   return 0;
		   for (int i = 0; i < src.rows; i++)
		   {
			   for (int j = 0; j < src.cols; j++)
			   {
				   if (src.at<uchar>(i, j) < min)
				   {
					   min = src.at<uchar>(i, j);
				   }
			   }
		   }
		   return  min;
	   }

	private: int StatMeasure(Mat& image)
	{
		int sum = 0, max = 0, min = 255; float avg;
		if (!image.data) // handle error while open and does not select an image 
			return 0;
		else
		{
			for (int i = 0; i < image.rows; i++)
			{
				for (int j = 0; j < image.cols; j++)
				{
					sum += image.at<uchar>(i, j);

					if (image.at<uchar>(i, j) > max)
						max = image.at<uchar>(i, j);

					if (min > image.at<uchar>(i, j))
						min = image.at<uchar>(i, j);
				}
			}
			avg = sum / image.total();
			return  avg;
		}
	}
#pragma endregion
#pragma region //translation buttons
 /*/////// buttons of translation \\\\\\\\\\\\\\\\\\\\*/
// translation +X button
private: System::Void button19_Click(System::Object^ sender, System::EventArgs^ e) {
	int tx = 10, ty = 0; // move by 10 points
	Mat TM = (Mat_<float>(2, 3) << 1, 0, tx, 0, 1, ty);
	warpAffine(grayImg, grayImg, TM, grayImg.size());
	showImg(grayImg);
}
// translation +Y button
private: System::Void button20_Click(System::Object^ sender, System::EventArgs^ e) {
	int tx = 0, ty = 10;
	Mat TM = (Mat_<float>(2, 3) << 1, 0, tx, 0, 1, ty);
	warpAffine(grayImg, grayImg, TM, grayImg.size());
	showImg(grayImg);
}
// translation -X button
private: System::Void button14_Click(System::Object^ sender, System::EventArgs^ e) {
	int tx = -10, ty = 0;
	Mat TM = (Mat_<float>(2, 3) << 1, 0, tx, 0, 1, ty);
	warpAffine(grayImg, grayImg, TM, grayImg.size());
	showImg(grayImg);
}
// translation -Y button
private: System::Void button15_Click(System::Object^ sender, System::EventArgs^ e) {
	int tx = 0, ty = -10;
	Mat TM = (Mat_<float>(2, 3) << 1, 0, tx, 0, 1, ty);
	warpAffine(grayImg, grayImg, TM, grayImg.size());
	showImg(grayImg);
} /////////////// end of translation buttons ///////////////////////////
#pragma endregion
#pragma region //Rotation buttons

// Rotation new
private: System::Void button9_Click_1(System::Object^ sender, System::EventArgs^ e) {
	Mat dst;
	int rotation = Convert::ToInt32(textBox2->Text);
	Mat R = getRotationMatrix2D(Point2f(grayImg.cols / 2, grayImg.rows / 2), rotation, .7);
	warpAffine(grayImg, dst, R, grayImg.size());
	showImg(dst);
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	//textBox2->Text = ""; // to clear the default text while clicked ( attached with click event)
}
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	//textBox3->Text = ""; // to clear the default text while clicked ( attached with click event)
}

#pragma endregion
#pragma region // skewing buttons
//trackbar x-axis
private: System::Void trackBar3_Scroll(System::Object^ sender, System::EventArgs^ e) {
	this->label3->Text = "X-axis: " + (trackBar3->Value);
	int xtrans = trackBar3->Value;
	Point2f src_p[3];
	src_p[0] = Point2f(0, 0);
	src_p[1] = Point2f(src.cols - 1, 0); 
	src_p[2] = Point2f(0, src.rows - 1);
	Point2f dst_p[3];
	dst_p[0] = Point2f(0, 0);
	dst_p[1] = Point2f(src.cols - 1, 0);
	dst_p[2] = Point2f(xtrans, src.rows - 1);
	Mat SM = getAffineTransform(src_p, dst_p);
	warpAffine(grayImg, temp, SM, src.size());
	showImg(temp);
}
//trackbar -X-axis
private: System::Void trackBar4_Scroll(System::Object^ sender, System::EventArgs^ e) {
	this->label4->Text = "-X-axis: " + (trackBar4->Value);
	int ytrans = trackBar4->Value;
	Point2f src_p[3];
	src_p[0] = Point2f(0, 0);
	src_p[1] = Point2f(src.cols - 1, 0);
	src_p[2] = Point2f(0, src.rows - 1);
	Point2f dst_p[3];
	dst_p[0] = Point2f(0, 0);
	dst_p[1] = Point2f(src.cols - 1, 0);
	dst_p[2] = Point2f(-ytrans, src.rows - 1);
	Mat SM = getAffineTransform(src_p, dst_p);
	warpAffine(grayImg, temp, SM, src.size());
	showImg(temp);
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
// adjust button
private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
	grayImg = temp;
}

#pragma endregion
#pragma region //blinding buttons & label
private: System::Void button16_Click(System::Object^ sender, System::EventArgs^ e) {
	IO::Stream^ myStream; // to hold the image file
	OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

	openFileDialog1->InitialDirectory = "Desktop";
	openFileDialog1->Filter = "Image files (*.png)|*.png|All files|*.*|Image files (*.jpg)|*.jpg";
	openFileDialog1->FilterIndex = 2;
	openFileDialog1->RestoreDirectory = true;

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		if ((myStream = openFileDialog1->OpenFile()) != nullptr)
		{
			// Insert code to read the stream here. (image file)
			GUI2::String^ selectedFile = openFileDialog1->FileName;
			marshal_context converter;
			const char* str2 = converter.marshal_as<const char*>(openFileDialog1->FileName);
			frontblind = imread(str2, 0); // read the front image 
			showImg(grayImg);
			//show message to the user
			MessageBox::Show("Use the slider to change the trancparency and blind the images...", "Hint", MessageBoxButtons::OK, MessageBoxIcon::Information);
			myStream->Close();
		}
	}
}
	   //blinding image
private: System::Void trackBar6_Scroll(System::Object^ sender, System::EventArgs^ e) {
	backblind = grayImg; // assign back image
	Mat blinded(backblind.rows, backblind.cols, CV_8UC1); // make blinded image size as front image 
	cv::resize(frontblind, frontblind, cv::Size(backblind.cols, backblind.rows), CV_8UC1); // make back blind image size as front image
	float transVal = trackBar6->Value * 0.1;
	this->label10->Text = "Trancparency: " + transVal;

	for (int r = 0; r < frontblind.rows; r++)
		for (int c = 0; c < frontblind.cols; c++)
			blinded.at<uchar>(r, c) = frontblind.at<uchar>(r, c) * transVal + backblind.at<uchar>(r, c) * (1 - transVal);
	showImg(blinded);
}
private: System::Void label10_Click(System::Object^ sender, System::EventArgs^ e) {
}
#pragma endregion
#pragma region //bit plan slicing
// bit plan slicing button
int bitNo; //initialize bit number
private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) {
	//to prevent empty or no selection comboBox error
	if (comboBox1->Text=="Select Plan no." || comboBox1->Text=="")
		MessageBox::Show("Please select Plan no. from the list !", "Warnning...!",
		MessageBoxButtons::OK, MessageBoxIcon::Information);

	else
	{
		bitNo = System::Convert::ToInt16(comboBox1->Text);
		int plancode = pow(2, bitNo);
		bitplnImg = imread("temp.png", 0); 
		for (int r = 0; r < bitplnImg.rows; r++)
			for (int c = 0; c < bitplnImg.cols; c++)
				if (bitplnImg.at<uchar>(r, c)& uchar(plancode))
					bitplnImg.at<uchar>(r, c) = 255;
				else
					bitplnImg.at<uchar>(r, c) = 0;
		showPlan(bitplnImg);
		bitplnImg = grayImg; 
	}
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: void showPlan(Mat src) {
	imwrite("plan.png", src);
	ostringstream oss;
	oss << "Plan: " << bitNo;
	string windowName = oss.str();
	namedWindow(windowName, 0);
	imshow(windowName, src);
}
#pragma endregion
#pragma region // filters
private: Mat filtering(Mat src, Mat kernel) {	
	filter2D(src, src, CV_8UC1, kernel);
	showImg(src);
	return src;	
}
// traditional filter 3x3 button 3*3
private: System::Void button26_Click(System::Object^ sender, System::EventArgs^ e) {
	Mat kernel_T = (Mat_<float>(3, 3) << 1, 1, 1, 1, 1, 1, 1, 1, 1);
	kernel_T = kernel_T / 9;
	filter2D(grayImg, grayImg, CV_8UC1, kernel_T);
	//filtering(src, kernel_T);
	showImg(grayImg);
}
// pyramidal filter button 5*5
private: System::Void button27_Click(System::Object^ sender, System::EventArgs^ e) {
	Mat kernel_p = (Mat_<float>(5, 5) << 1, 2, 3, 2, 1, 2, 4, 6, 4, 2, 3, 6, 9, 6, 3, 2, 4, 6, 4, 2, 1, 2, 3, 2, 1);
	kernel_p = kernel_p / 81;
	filter2D(grayImg, grayImg, CV_8UC1, kernel_p);
	showImg(grayImg);
}
// cone filter button 5*5
private: System::Void button28_Click(System::Object^ sender, System::EventArgs^ e) {
	Mat kernel_co = (Mat_<float>(5, 5) << 0, 0, 1, 0, 0, 0, 2, 2, 2, 0, 1, 2, 5, 2, 1, 0, 2, 2, 2, 0, 0, 0, 1, 0, 0);
	kernel_co = kernel_co / 25;
	filter2D(grayImg, grayImg, CV_8UC1, kernel_co);
	showImg(grayImg);
}
// circular filter 5*5 button
private: System::Void button30_Click(System::Object^ sender, System::EventArgs^ e) {
	Mat kernel_c = (Mat_<float>(5, 5) << 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0);
	kernel_c = kernel_c / 21;
	filter2D(grayImg, grayImg, CV_8UC1, kernel_c);
	showImg(grayImg);
}
// Median Blur filter  button 9
private: System::Void button29_Click(System::Object^ sender, System::EventArgs^ e) {
	medianBlur(grayImg, grayImg, 9);
	showImg(grayImg);
}
// Sobel filter in X dir button
private: System::Void button31_Click(System::Object^ sender, System::EventArgs^ e) {
	Sobel(grayImg, grayImg, CV_8UC1, 1, 0, 3);
	showImg(grayImg);
}
// Sobel filter in Y dir button
private: System::Void button22_Click(System::Object^ sender, System::EventArgs^ e) {
	Sobel(grayImg, grayImg, CV_8UC1, 0, 1, 3);
	showImg(grayImg);
}

#pragma endregion
#pragma region // segmentation
	   //thresholding method
private: System::Void trackBar7_Scroll(System::Object^ sender, System::EventArgs^ e) {
	int TH = trackBar7->Value; //TH Value: 
	this->label12->Text = "TH Value: " + (trackBar7->Value);
	threshold(grayImg, temp, TH, 255, THRESH_BINARY);
	showImg(temp);
}
private: System::Void label12_Click(System::Object^ sender, System::EventArgs^ e) {
}
	   //Edge Based Method button
private: System::Void button8_Click_1(System::Object^ sender, System::EventArgs^ e) {
	GaussianBlur(grayImg, grayImg, cv::Size(3, 3), 0);
	Laplacian(grayImg, grayImg, CV_8UC1);
	showImg(grayImg);
}
// adjust button
private: System::Void button17_Click(System::Object^ sender, System::EventArgs^ e) {
	grayImg = temp;
}


#pragma endregion
//showing function
private: void showImg(Mat pimg) {
	imwrite("processed.png", pimg);
	this->pictureBox1->ImageLocation = "processed.png"; // Display The Selected Image in PicBox
	//to update image details box
	int max, min;
	float avg;
	max = maxMeasure(pimg);
	min = minMeasure(pimg);
	avg = StatMeasure(pimg);
	
	//call max function in Max variable
	this->label5->Text = "Max: " + max;
	//call min function in Min variable
	this->label6->Text = "Min: " + min;
	//call avg function in avg variable
	this->label7->Text = "Avg: " + avg;
}
	   //histogram 
private: System::Void histogram_button32_Click(System::Object^ sender, System::EventArgs^ e) {
	int histSize = 256;
	float range[] = { 0, 256 }; 
	const float* histRange[] = { range };
	bool uniform = true, accumulate = false;

	Mat b_hist;
	calcHist(&grayImg, 1, 0, Mat(), b_hist, 1, &histSize, histRange, uniform, accumulate);

	int hist_w = 512, hist_h = 400;
	int bin_w = cvRound((double)hist_w / histSize);

	Mat histImage(hist_h, hist_w, CV_8UC1, Scalar(0, 0, 0));
	normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	for (int i = 1; i < histSize; i++)
	{
		line(histImage, cvPoint(bin_w * (i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))),
			cvPoint(bin_w * (i), hist_h - cvRound(b_hist.at<float>(i))),
			Scalar(255, 255, 255), 2, 8, 0);
	}
	imshow("histogram of image", histImage);
	//showImg(histImage);
}
	   //sobel diagonal
private: System::Void sobel_xy_button32_Click(System::Object^ sender, System::EventArgs^ e) {
	Mat sobelX = grayImg.clone();
	Mat sobelY = grayImg.clone();
	Sobel(sobelX, sobelX, CV_8UC1, 1, 0, 3);
	Sobel(sobelY, sobelY, CV_8UC1, 0, 1, 3);
	addWeighted(sobelX, 1, sobelY, 1, 0, grayImg);
	showImg(grayImg);
}
// gaussian
private: System::Void gaussian_button32_Click(System::Object^ sender, System::EventArgs^ e) {
	Mat kernel_G = (Mat_<float>(3, 3) << 1, 2, 1, 2, 4, 2, 1, 2, 1);
	kernel_G = kernel_G / 16;
	filter2D(grayImg, grayImg, CV_8UC1, kernel_G);
	showImg(grayImg);
}
// increase pixel
private: System::Void button32_Click(System::Object^ sender, System::EventArgs^ e) {
	for (int i = 0; i < grayImg.rows; i++)
		for (int j = 0; j < grayImg.cols; j++)
			grayImg.at<uchar>(i, j) = grayImg.at<uchar>(i, j) + 10;
	showImg(grayImg);

}
//prewit edge detection 
private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) {
	int pv, ph, p_mag;
	for (int i = 1; i < grayImg.rows - 1; i++)
		for (int j = 1; j < grayImg.cols - 1; j++)
		{
			ph = grayImg.at<uchar>(i, j);
			pv = grayImg.at<uchar>(i, j);
			p_mag = sqrt((pv * pv) + (ph * ph));
			if (p_mag > 100)

				grayImg.at<uchar>(i, j) = 255;
			else
				grayImg.at<uchar>(i, j) = 0;
		}
}
//prewit horizontal
private: System::Void button18_Click(System::Object^ sender, System::EventArgs^ e) {
	for (int i = 1; i < grayImg.rows - 1; i++)
		for (int j = 1; j < grayImg.cols - 1; j++)
		{
			grayImg.at<uchar>(i, j) = abs(grayImg.at<uchar>(i - 1,
				j - 1) * 1 +
				grayImg.at<uchar>(i - 1, j) * 1 +
				grayImg.at<uchar>(i - 1, j + 1) * 1 +
				grayImg.at<uchar>(i, j - 1) * 0 +
				grayImg.at<uchar>(i, j) * 0 +
				grayImg.at<uchar>(i, j + 1) * 0 +
				grayImg.at<uchar>(i + 1, j - 1) * -1 +
				grayImg.at<uchar>(i + 1, j) * -1 +
				grayImg.at<uchar>(i + 1, j + 1) * -1);

		}
}
	   //prewit vertical
private: System::Void button21_Click(System::Object^ sender, System::EventArgs^ e) {
	for (int i = 1; i < grayImg.rows - 1; i++)
		for (int j = 1; j < grayImg.cols - 1; j++)
		{

			grayImg.at<uchar>(i, j) = abs(grayImg.at<uchar>(i - 1,
				j - 1) * 1 +
				grayImg.at<uchar>(i - 1, j) * 0 +
				grayImg.at<uchar>(i - 1, j + 1) * -1 +
				grayImg.at<uchar>(i, j - 1) * 1 +
				grayImg.at<uchar>(i, j) * 0 +
				grayImg.at<uchar>(i, j + 1) * -1 +
				grayImg.at<uchar>(i + 1, j - 1) * 1 +
				grayImg.at<uchar>(i + 1, j) * 0 +
				grayImg.at<uchar>(i + 1, j + 1) * -1);

		}
}
// high pass fourier
private: System::Void button33_Click(System::Object^ sender, System::EventArgs^ e) {
	int m = getOptimalDFTSize(src.rows);
	int n = getOptimalDFTSize(src.cols);
	Mat padded;
	copyMakeBorder(grayImg, padded, 0, m - src.rows, 0, n - src.cols, 0);
	padded.convertTo(padded, CV_32FC1, 1.0 / 255.0);
	Mat planes[2] = { padded , Mat::zeros(padded.size(),CV_32FC1) };
	Mat complexI;
	merge(planes, 2, complexI);
	dft(complexI, complexI);
	split(complexI, planes);

	int cx = complexI.cols / 2;
	int cy = complexI.rows / 2;

	Mat p1(complexI, Rect(0, 0, cx, cy));
	Mat p2(complexI, Rect(cx, 0, cx, cy));
	Mat p3(complexI, Rect(0, cy, cx, cy));
	Mat p4(complexI, Rect(cx, cy, cx, cy));
	Mat temp;
	p1.copyTo(temp);
	p4.copyTo(p1);
	temp.copyTo(p4);
	p2.copyTo(temp);
	p3.copyTo(p2);
	temp.copyTo(p3);
	split(complexI, planes);

	int d0 = Convert::ToInt32(textBox4->Text);

	Mat Lfilter(complexI.size(), CV_32FC1);

	for (int i = 0; i < Lfilter.rows; i++)
		for (int j = 0; j < Lfilter.cols; j++)
		{
			double z1 = i - Lfilter.rows / 2;
			double z2 = j - Lfilter.cols / 2;
			if (sqrt(pow(z1, 2) + pow(z2, 2)) < d0)
				Lfilter.at<float>(i, j) = 1;
			else
				Lfilter.at<float>(i, j) = 0;
		}
	namedWindow("high freq filter", 0);
	imshow("high freq filter", Lfilter);

	Mat outR, outI;
	multiply(planes[0], Lfilter, outR);
	multiply(planes[1], Lfilter, outI);
	Mat out_planes[2] = { outR , outI };
	Mat out_complexI;
	merge(out_planes, 2, out_complexI);
	idft(out_complexI, out_complexI);
	///////////////////////////////////////////////
	split(out_complexI, planes);
	Mat out;
	magnitude(planes[0], planes[1], out);
	normalize(out, out, 1, 0, NORM_MINMAX);
	namedWindow("after idft", 0);
	imshow("after idft", out);
}
private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
	   // low pass fourier
private: System::Void button37_Click(System::Object^ sender, System::EventArgs^ e) {
	int m = getOptimalDFTSize(src.rows);
	int n = getOptimalDFTSize(src.cols);
	Mat padded;
	copyMakeBorder(grayImg, padded, 0, m - src.rows, 0, n - src.cols, 0);
	padded.convertTo(padded, CV_32FC1, 1.0 / 255.0);
	Mat planes[2] = { padded , Mat::zeros(padded.size(),CV_32FC1) };
	Mat complexI;
	merge(planes, 2, complexI);
	dft(complexI, complexI);
	split(complexI, planes);

	int cx = complexI.cols / 2;
	int cy = complexI.rows / 2;

	Mat p1(complexI, Rect(0, 0, cx, cy));
	Mat p2(complexI, Rect(cx, 0, cx, cy));
	Mat p3(complexI, Rect(0, cy, cx, cy));
	Mat p4(complexI, Rect(cx, cy, cx, cy));
	Mat temp;
	p1.copyTo(temp);
	p4.copyTo(p1);
	temp.copyTo(p4);
	p2.copyTo(temp);
	p3.copyTo(p2);
	temp.copyTo(p3);
	split(complexI, planes);

	int d0 = Convert::ToInt32(textBox5->Text);

	Mat Lfilter(complexI.size(), CV_32FC1);

	for (int i = 0; i < Lfilter.rows; i++)
		for (int j = 0; j < Lfilter.cols; j++)
		{
			double z1 = i - Lfilter.rows / 2;
			double z2 = j - Lfilter.cols / 2;
			if (sqrt(pow(z1, 2) + pow(z2, 2)) < d0)
				Lfilter.at<float>(i, j) = 0;
			else
				Lfilter.at<float>(i, j) = 1;
		}
	namedWindow("low freq filter", 0);
	imshow("low freq filter", Lfilter);

	Mat outR, outI;
	multiply(planes[0], Lfilter, outR);
	multiply(planes[1], Lfilter, outI);
	Mat out_planes[2] = { outR , outI };
	Mat out_complexI;
	merge(out_planes, 2, out_complexI);
	idft(out_complexI, out_complexI);
	///////////////////////////////////////////////
	split(out_complexI, planes);
	Mat out;
	magnitude(planes[0], planes[1], out);
	normalize(out, out, 1, 0, NORM_MINMAX);
	namedWindow("after idft", 0);
	imshow("after idft", out);
}
private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
// sobel
private: System::Void button38_Click(System::Object^ sender, System::EventArgs^ e) {
	Mat dst12_2, dst12_3, dst12_4, dst12_5, dst12_6;
	Mat kernel_TH = (Mat_<int>(3, 3) << -1, -2, -1, 0, 0, 0, 1, 2, 1);
	filter2D(grayImg, dst12_2, CV_8UC1, kernel_TH);
	Mat kernel_TV = (Mat_<int>(3, 3) << -1, 0, 1, -2, 0, 2, -1, 0, 1);
	filter2D(grayImg, dst12_3, CV_8UC1, kernel_TV);
	Mat kernel_Td = (Mat_<int>(3, 3) << 2, 1, 0, 1, 0, -1, 0, -1, -2);
	filter2D(grayImg, dst12_4, CV_8UC1, kernel_Td);
	addWeighted(dst12_2, 1, dst12_3, 1, 0, dst12_5);
	addWeighted(dst12_4, 1, dst12_5, 1, 0, dst12_6);
	showImg(dst12_6);
}
	   // add gaussian noise
private: System::Void button39_Click(System::Object^ sender, System::EventArgs^ e) {
	
	double mean = Convert::ToDouble(textBox6->Text),
		sigma = Convert::ToDouble(textBox7->Text);
	Mat gaussian_Noise = grayImg.clone();
	RNG rng;
	rng.fill(gaussian_Noise, RNG::NORMAL, mean, sigma);
	add(grayImg, gaussian_Noise, grayImg);
	showImg(grayImg);
}
private: System::Void textBox6_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox7_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
	   // add salt pepper
private: System::Void button40_Click(System::Object^ sender, System::EventArgs^ e) {
	RNG rng;
	double pa = Convert::ToDouble(textBox8->Text),
		pb = Convert::ToDouble(textBox9->Text);
	int amount1 = grayImg.total() * pa;
	int amount2 = grayImg.total() * pb;
	for (int counter = 0; counter < amount1; ++counter)
	{
		grayImg.at<uchar>(rng.uniform(0, src.rows), rng.uniform(0, src.cols)) = 0;
	}

	for (int counter = 0; counter < amount2; ++counter)
	{
		grayImg.at<uchar>(rng.uniform(0, src.rows), rng.uniform(0, src.cols)) = 255;
	}
	showImg(grayImg);
}
private: System::Void textBox8_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox9_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
// impulse noise
private: System::Void button41_Click(System::Object^ sender, System::EventArgs^ e) {
	Mat impulse_noise(grayImg.rows, grayImg.cols, CV_8UC1);
	RNG rng;
	rng.fill(impulse_noise, RNG::UNIFORM, 0, 255);
	threshold(impulse_noise, impulse_noise, 250, 255, THRESH_BINARY);
	add(grayImg, impulse_noise, grayImg);
	showImg(grayImg);
}
//object recognition
private: System::Void button42_Click(System::Object^ sender, System::EventArgs^ e) {

	Mat imgDil , imgBlur, imgCanny;
	GaussianBlur(src, imgBlur, cv::Size(3, 3), 3, 0);
	Canny(imgBlur, imgCanny, 25, 75);
	Mat kernel = getStructuringElement(MORPH_RECT, cv::Size(3, 3));
	dilate(imgCanny, imgDil, kernel);
	getContours(imgDil, src);
	imshow("object recognition", src);
}
//convert RGB to Gray
private: System::Void button43_Click(System::Object^ sender, System::EventArgs^ e) {
	showImg(grayImg);
}
//laplacian filter
private: System::Void button44_Click_1(System::Object^ sender, System::EventArgs^ e) {
	Mat dst12_L;
	Mat kernel_L = (Mat_<int>(3, 3) << 0, -1, 0, -1, 4, -1, 0, -1, 0);
	filter2D(grayImg, dst12_L, CV_8UC1, kernel_L);
	Laplacian(grayImg, dst12_L, CV_8UC1);
	showImg(dst12_L);
}
//compression
private: System::Void button45_Click(System::Object^ sender, System::EventArgs^ e) {
	if (src.empty()) {
		MessageBox::Show("No image ");
		return;
	}
	std::vector<int>params;
	params.push_back(IMWRITE_JPEG_QUALITY);
	params.push_back(Convert::ToInt32(cmpression_scale->Text));    
	imwrite("comprition.jpg", src, params);
	pictureBox1->ImageLocation = "comprition.jpg";
	imshow("original", src);
}
private: System::Void cmpression_scale_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};///////////////////////////////////////////////////////////////////////////////////////////////////////////////
}
