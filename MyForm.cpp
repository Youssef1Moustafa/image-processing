/*
This Tool Have been designed by

youssef moustafa youssef

*/

#include "MyForm.h"
#include <opencv2/opencv.hpp>


using namespace cv;
using namespace GUI2; 


[STAThreadAttribute]
int main()
{
	
	Application::Run(gcnew MyForm()); 
	return 0;
}
