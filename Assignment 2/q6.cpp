//#include"app.h";
//int main()
//{
//	Appointment*app = new Appointment[totalApp];
//	app[0] = Onetime("See the Dentist", 12, 2, 2023);
//	app[1] = Daily("Study", 10, 1, 2023);
//	app[2] = Monthly("Pay Bills", 2, 3, 2023);
//	app[3] = Monthly("Do Assignment", 2, 3, 2023);
//	//-----------------------------------//
//	while (true)
//	{
//		menu();
//		cin >> choice;
//		if (choice == 1)
//		{
//			searchAppointment(app);
//		}
//		else if (choice == 2)
//		{
//			AddNew(app);
//		}
//		else
//		{
//			break;
//		}
//	}
//	system("CLS");
//	cout << "Bye-Bye" << endl;
//	delete[]app;
//	app = nullptr;
//}