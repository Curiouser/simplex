#include "stdafx.h"
#include "SimplexProblem.h"

using namespace std;

SimplexProblem::SimplexProblem()
{
	nbInequations = 0;
	nbVariables = 0;
	systemIneq = new double * [nbInequations]; //each systemIneq[nbIneq] is of size nbVariables + 2, for relational sign and result // we have deleted the +2
	z = new double[nbVariables + 1]; //expression to maximize; //WHYYYYYYYYYYYYYYYY +1 ?????????
	signs = new int[nbInequations];
	results = new double[nbInequations];
}

SimplexProblem::SimplexProblem(int nbIneq, int nbVar)
{
	nbInequations = nbIneq;
	nbVariables = nbVar;
	systemIneq = new double *[nbInequations];
	z = new double[nbVariables + 1];
	signs = new int[nbInequations];
	results = new double[nbInequations];
}


SimplexProblem::~SimplexProblem()
{
}

int SimplexProblem::getNbIneq()
{
	return nbInequations;
}

void SimplexProblem::setNbIneq(int nbIneq)
{
	nbInequations = nbIneq;
	systemIneq = new double *[nbInequations];
	signs = new int[nbInequations];
	results = new double[nbInequations];
}

int SimplexProblem::getNbVar()
{
	return nbVariables;
}

void SimplexProblem::setNbVar(int nbVar)
{
	nbVariables = nbVar;
	for (int i = 0; i < nbInequations; i++)
		systemIneq[i] = new double[nbVariables + 2];
	z = new double[nbVariables + 1];
}
		
double ** SimplexProblem::getSystIneq()
{
	return systemIneq;
}

void SimplexProblem::setSystIneq(double ** array)
{
	if (array == NULL) 
	{
		cout << "Issue in SimplexProblem::setSystIneq array is null" << endl;
		return;
	}
	
	int i, j;
	int sizeA, sizeB;
	sizeA = sizeof(array) / sizeof(array[0][0]);

	systemIneq = new double*[sizeA];

	for (i = 0; i < sizeA; i++)
	{
		sizeB = sizeof(array[i]) / sizeof(array[0][0]);

		systemIneq[i] = new double[sizeB];

		for (j = 0; i < sizeB; j++)
		{
			systemIneq[i][j] = array[i][j];
		}
	}
}

double * SimplexProblem::getZ()
{
	return z;
}

void SimplexProblem::setZ(double * array)
{
	if (array == NULL)
		cout << "Issue in SimplexProblem::setSystIneq array is null" << endl;

	else
	{
		int i, size;
		size = sizeof(array) / sizeof(array[0]);
		z = new double[size];
		for (i = 0; i < size; i++)
			z[i] = array[i];
	}
}

void SimplexProblem::setCoefficient(int ineq, int var, double coeff)
{
	if (ineq >= 0 && ineq <= nbInequations && var >= 0 && var <= nbVariables)
		systemIneq[ineq][var] = coeff;
	else
		cout << "Problem in SimplexProblem::setCoefficient for inequation number " + ineq << "var number " + var << " not correct" << endl;
}

double SimplexProblem::getCoefficient(int ineq, int var)
{
	if (ineq >= 0 && ineq <= nbInequations && var >= 0 && var <= nbVariables)
		return systemIneq[ineq][var];
	else
	{
		cout << "Problem in SimplexProblem::getCoefficient for inequation number " + ineq << "var number " + var << " not correct" << endl;
		return -1;
	}		
}

void SimplexProblem::setSign(int ineq, int sign)
{
	if (ineq >= 0 && ineq <= nbInequations)
	{
		systemIneq[ineq][nbVariables + 1] = sign;
		signs[ineq] = sign;

	}
	else
		cout << "Problem in SimplexProblem::setSign for inequation number " + ineq << endl;
}

int SimplexProblem::getSign(int ineq)
{
	if (ineq >= 0 && ineq <= nbInequations)
		return signs[ineq];
	else
	{
		cout << "Problem in SimplexProblem::getSign for inequation number " + ineq << endl;
		return -1;
	}
		
}

void SimplexProblem::setResult(int ineq, double result)
{
	if (ineq >= 0 && ineq <= nbInequations)
	{
		systemIneq[ineq][nbVariables + 2] = result;
		results[ineq] = result;
	}
	else
		cout << "Problem in SimplexProblem::setResult for inequation number " + ineq << endl;
}

double SimplexProblem::getResult(int ineq)
{
	if (ineq >= 0 && ineq <= nbInequations)
		return results[ineq];
	else
	{
		cout << "Problem in SimplexProblem::getResult for inequation number " + ineq << endl;
		return -1;
	}	
}


void SimplexProblem::setCoeffInZ(int var, double coeff)
{
	if (var >= 0 && var <= nbVariables)
		z[var] = coeff;
	else
		cout << "Problem in SimplexProblem::setCoeffInZ for variable " + var << endl;
}

double SimplexProblem::getCoeffInZ(int var)
{
	if (var >= 0 && var <= nbVariables)
		return z[var];
	else
	{
		cout << "Problem in SimplexProblem::getCoeffInZ for variable " + var << endl;
		return -1;
	}		
}

void SimplexProblem::ReadFile(ifstream *file) //BOF NE FONCTIONNE PAS TROP // A REVOIR, PAS CORRIGEE
{
	int nbLines = 0; //nbInequations
	int nbCol = 0; //nbVariables

	if (file) {

		*file >> nbLines >> nbCol;
		cout << endl << "nb of lines : " << nbLines << endl;
		cout << "nb of columns : " << nbCol << endl << endl;

		double **tab = new double*[nbLines];
		setNbIneq(nbLines);
		setNbVar(nbCol);

		for (int i = 0; i <= nbLines; i++) {
			tab[i] = new double[nbCol + 2]; // +2 corresponds to the relational sign and result
		}

		for (int i = 0; i <= nbLines; i++) {
			for (int j = 0; j <= nbCol + 1; j++) {
				*file >> tab[i][j];
			}
		}

		for (int i = 0; i <= nbLines; i++) {
			for (int j = 0; j <= nbCol + 1; j++) {
				cout << tab[i][j] << " ";
			}
			cout << endl;
		}

		cout << endl;

		double *z = new double[nbCol + 1];

		for (int i = 0; i <= nbCol + 1; i++) {
			z[i] = tab[nbLines][i];
		}

		cout << " Z = " << endl;
		for (int i = 0; i <= nbCol + 1; i++) {
			cout << z[i] << " ";
		}
		
		setSystIneq(tab);
		setZ(z);
	}

	else cout << "Erreur : Impossible d ouvrir le fichier " << endl;
}


void SimplexProblem::ReadFileBinaryValue(ifstream *file)
{
	// TO DO
}


void SimplexProblem::createProblemFromIO()
{
	int nbVar, nbIneq, sign = 0;
	double result, coeff = 0;

	do {
		cout << "Please write the number of linear inequations : " << endl;
		cin >> nbIneq;
	} while (nbIneq < 1);
	setNbIneq(nbIneq);
	cout << "\n" << endl;

	do {
		cout << "Please write the number of variables : " << endl;
		cin >> nbVar;
	} while (nbVar < 1);
	setNbVar(nbVar);
	cout << "\n" << endl;

	for (int i = 0; i < nbIneq; i++)
	{
		cout << "Now you are going to be asked the coefficient for each variable in inequation number " + i << endl;
		cout << "Please write 0 when the variable does not appear in the inequation " << endl;
		for (int j = 0; j < nbVar; j++)
		{
			cout << "coefficient for variable " + j << endl;
			cin >> coeff;
			setCoefficient(i, j, coeff);
		}
		cout << "\n" << endl;

		cout << "Please write the relational sign for inequation number" + i << endl;
		cout << "1 - Inferior or equal" << endl;
		cout << "2 - Superior or equal " << endl;
		cout << "3 - Equal " << endl << endl;
		do {
			cin >> sign;
		} while (sign != 1 && sign != 2 && sign != 3);
		setSign(i, sign);
		cout << "\n" << endl;

		cout << "Please write the result of inequation number " + i << endl;
		cin >> result;
		setResult(i, result);
		cout << "\n" << endl;

	}
	cout << endl << endl;

	cout << "You are now going to be asked about the coefficients in the function Z to maximize" << endl;
	cout << "Please write 0 when the variable does not appear in the inequation " << endl;
	for (int i = 0; i < nbVar; i++)
	{
		cout << "coefficient in Z for variable " + i << endl;
		cin >> coeff;
		setCoeffInZ(i, coeff);
		cout << "\n" << endl;
	}

	cout << endl << "The system of inequations is as follows : " << endl;

	for (int i = 0; i < nbIneq; i++)
	{
		cout << getCoefficient(i, 0) << "X1 ";
		for (int j = 1; j < nbVar; j++)
			cout << " + " << getCoefficient(i, j) << "X" << j + 1;

		switch (getSign(i))
		{
		case 1:
			cout << " <= ";
		case 2:
			cout << " >= ";
		case 3:
			cout << " = ";
		}

		cout << getResult(i) << endl;
	}

	cout << "The function to maximize is " << endl;
	cout << " Z = ";

	cout << getCoeffInZ(0) << "X" << "1";

	for (int i = 0; i < nbVar; i++)
		cout << " + " << getCoeffInZ(i) << "X" << i + 1;

	cout << endl << endl;
}