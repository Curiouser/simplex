// Projet_Optim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "SimplexProblem.h"

using namespace std;


int main()
{
	SimplexProblem simplexProblem;

	cout << "Initialisation of the program \n" << endl;
	cout << "1. Create a new problem" << endl;
	cout << "2. Import a problem from a file \n" << endl;

	int choice;
	do {
		cout << "Enter either 1 or 2" << endl;
		cin >> choice;
	} while (choice != 1 && choice != 2);
	cout << "\n" << endl;

	if (choice == 1)
	{
		cout << "Create a new problem \n" << endl;
		simplexProblem.createProblemFromIO();
	}

	else
	{
		cout << "Import a problem from a file" << endl << endl << "Problems to choose from : " << endl;
		cout << endl << "1 : Simplex 1 phase" << endl;
		cout << endl << "2 : Simplex 2 phases" << endl;
		cout << endl << "3 : Binary Value" << endl;
		cout << endl << "Write the number of a problem (between 1 and 3) : " << endl;

		int nbProblem = 0;
		cin >> nbProblem;

		switch (nbProblem)
		{
		case 1: {
			ifstream file("../Pb1.txt", ios::in);
			cin.get();
			simplexProblem.ReadFile(&file);
			break;
		}
		case 2: {
			ifstream file("../Pb2.txt", ios::in);
			simplexProblem.ReadFile(&file);
			break;
		}
		case 3: {
			ifstream file("../Pb3.txt", ios::in);
			simplexProblem.ReadFileBinaryValue(&file);
			break;
		}
		default:
			break;
		}
	}//end of else : read problem from a file
	
	cout << "Choose a way to solve the problem : " << endl;
	cout << " 1 - Simplex resolution" << endl;
	cout << " 2 - Binary tree resolution" << endl;
	cout << " 3 - Split/Cut resolution" << endl;

	int resolution = 0;
	do {
		cout << "Write the number associated to the resolution you want : " << endl;
		cin >> resolution;
	} while (resolution != 1 && resolution != 2 && resolution != 3);
	cout << "\n" << endl;

	switch (resolution)
	{
	case 1: {
		cout << "Simplex resolution" << endl;
		//SimplexDetectionPhase(tab, z, nbInequations, nbInconnues);
		break;
	}
	case 2: {
		cout << "Binary tree resolution" << endl;
		//InitTree(tab, z, nbInequations, nbInconnues);
		break;
	}
	case 3: {
		cout << "Split/Cut resolution" << endl;
		// Split/Cut
		break;
	}
	case 4: {
		break;
	}

	default:
		break;
	}

	cin.get();
	return 0;
}

