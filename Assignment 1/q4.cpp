//#include"pgmEditor.h"
//using namespace std;
//int main()
//{
//	grayImage GM;
//	string outputFile;
//	string image1;
//
//	while (true)
//	{
//		cout << "Enter name of image 1: " << endl;
//		getline(cin, image1);
//		if (GM.loadImage(image1))
//		{
//			break;
//		}
//		else
//			cout << "Invalid entry " << endl;
//	}
//	//system("CLS");
//
//
//	int option = 0;
//
//	while (option != -1)
//	{
//		cout << "Choose an option:\n" << endl;
//		cout << " 1. Combine Two images side by side " << endl;
//		cout << " 2. Change Brightness of Image" << endl;
//		cout << " 3. Find Negative of an Image " << endl;
//		cout << " 4. Flip an image Vertically" << endl;
//		cout << " 5. Flip an image Horizontally" << endl;
//		cout << " 6. Apply Median Filter (Remove Noise)" << endl;
//		cout << " 7. Apply your own Filter (Bonus)" << endl;
//		cout << "ENTER -1 TO EXIT" << endl;
//		cin >> option;
//		cout << endl;
//	    if (option == 4) { 
//			GM.flipImageV();
//			cout << "Enter the output file name: ";
//			cin >> outputFile;
//			GM.saveImageV(outputFile);
//			cout << endl;
//			cout << "Files Saved successfully in the output folder" << endl;
//		}
//		else if (option == 5)
//		{
//			GM.flipImageH();
//			cout << "Enter the output file name: ";
//			cin >> outputFile;
//			GM.saveImageH(outputFile);
//			cout << endl;
//			cout << "Files Saved successfully in the output folder" << endl;
//		}
//		else if (option == 2)
//		{
//			GM.changeBrightness();
//			GM.saveImageBright();
//		}
//		else if (option == 3)
//		{
//			GM.imageNeg();
//			GM.imageNegSave();
//		}
//		else if (option == 1)
//		{
//		
//			GM.placeImage();
//		}
//	}
//
//	 
//
//}