#ifndef SIMPLEXPROBLEM_H
#define SIMPLEXPROBLEM_H

#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class SimplexProblem
{
private:

	double **systemIneq;
	double *z;
	int nbInequations;
	int nbVariables;
	int *signs; // "1 - Inferior or equal"; "2 - Superior or equal "; "3 - Equal "
	double *results;

public:	

	SimplexProblem();
	SimplexProblem(int nbIneq, int nbVar);
	virtual ~SimplexProblem();

	int getNbIneq();

	void setNbIneq(int nbIneq);

	int getNbVar();

	void setNbVar(int nbVar);

	double ** getSystIneq();

	void setSystIneq(double ** array);

	double * getZ();

	void setZ(double * array);

	void setCoefficient(int ineq, int var, double coeff);

	double getCoefficient(int ineq, int var);

	void setSign(int ineq, int sign);

	int getSign(int ineq);

	void setResult(int ineq, double result);

	double getResult(int ineq);

	void setCoeffInZ(int var, double coeff);

	double getCoeffInZ(int var);

	void ReadFile(std::ifstream *file);

	void ReadFileBinaryValue(std::ifstream *file);
	
	void createProblemFromIO();
};

#endif //SIMPLEXPROBLEM_H