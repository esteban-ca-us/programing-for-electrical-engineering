///////////////////////////////////////////////////////////////
// STUDENT NAME: ESTEBAN CUELLAR-AGUILAR
// PROJECT NUMBER: project 7
///////////////////////////////////////////////////////////////

include <iostream>
include <fstream>
include <cstring>
include <cstdlib>
include "project_6.cc"

using namespace std;

ofstream o_f_7("output_7.txt", ios::out);

class EZ_CURVE_FIT: public LINEAR_SOLVER
{
   public:
	EZ_CURVE_FIT(int); // constructor; 
		// example: s.EZ_CURVE_FIT(5);
		// there are 5 pairs of data points;

	void LS_FIT_BY_ME(char *); 
		// example: s.LS_FIT_BY_ME("data_file");
		// perform least squares fit using inheritance 
		// data is in "data_file";
		
	void LS_FIT_BY_MATLAB (char *); 
		// example: s.LS_FIT_BY_MATLAB("data_file);
		// perform least squares fit using MATLAB; 
		
	void LS_FIT_BY_PYTHON (char *); 
		// example: s.LS_FIT_BY_PYTHON("data_file);
		// perform least squares fit using Python; 
   private:
	int np; // number of data pairs
};
 
// constructor code 
EZ_CURVE_FIT::EZ_CURVE_FIT(int x)
	:LINEAR_SOLVER(2) // call base class constructor, (we need to solve 
	   // a linear equation system of AX=B; dimension of A is 2x2) ;
{
        np = x;
        o_f_7 << "++++++++ P7 BEGIN ++++++" << endl;
        o_f_7 << "++++++++ P7 INSTANTIATED AN OBJECT WITH " << np << " DATA POINTS" << endl;
        o_f_7 << "++++++++ P7 END ++++++" << endl;
}

void EZ_CURVE_FIT::LS_FIT_BY_ME(char * data_file)
{
	int i, j;
	float S1, S2, S3, S4, S5, S6, error;
	float X[15], Y[15];
	float m, b;		

	// initialize vars:
	error = S1 = S2 = S3 = S4 = S5 = S6 = 0.0;
	m = b = 0.0;

	// read X and Y values:
	ifstream input_data_file(data_file, ios::in);   
	
	for(i = 0; i < np; i++)
        {
        	input_data_file >> X[i]>> Y[i];
        }

    // calculate the S1-S6 values:

    for (i = 0; i < np; i++)
    {
    	S1 += (X[i]*X[i]);

    	S2 += X[i];
    	
    	S3 += (X[i]*Y[i]);
    	
    	S4 += X[i];
    	
    	S5 += 1;
    	
    	S6 += Y[i];
    } 

	// write them into S_values.txt file in the format that 
	// is sutaible for sample_p6.h to read:
	ofstream out_s_values("S_values.txt", ios::out);

	out_s_values << S1 << " " << S2 << endl;

	out_s_values << S4 << " " << S5 << endl;

	out_s_values << S3 << endl;

	out_s_values << S6 << endl;
	
	
	// instantiate a LINEAR_SOLVER object:
	LINEAR_SOLVER L("S_values.txt", 2);

	// access SOLVE_LINEAR_EQUATION (results are in output.txt file):
	L.SOLVE_LINEAR_EQUATION("UNSORTED");

	string tempo;
	ifstream o_from_p6("output.txt", ios::in);

	for (i = 0; i < 12 ; i++)
	{
		getline (o_from_p6, tempo);

		cout << tempo << endl;
	}

	// read the results from output.txt file and populate output_7.txt file:

	o_from_p6 >> tempo;

	cout << "after loop tempo " << tempo << endl;
			o_from_p6 >> m;

	cout << "m is " << m << endl;
			o_from_p6 >> tempo;

	cout << "after loop tempo " << tempo << endl;
			o_from_p6 >> b;

	cout << "b is " << b << endl;

			o_f_7 << "LEAST_SQUARE_FIT RESULT:" << endl;
			o_f_7 << "USING INHERITANCE:" << endl;
			o_f_7 << "MATCHING FUNCTION IS Y = "
					<< setprecision (2) << setiosflags(ios::fixed | ios::showpoint)
					<< m << " * X + " << b << endl;

			error = 0;

			for (i = 0; i < np; i++)
			{
				error += pow((Y[i] - (m*X[i]) -b), 2);
			}

			o_f_7 << "THE ERROR FROM LS_FIT_BY_ME METHOD IS "
					<< setprecision (3) << setiosflags(ios::fixed | ios::showpoint)
					<< error << endl;
}

void EZ_CURVE_FIT::LS_FIT_BY_MATLAB(char * file_name)
{// your code goes below:
   float X[50],Y[50];
   int i,j;
   
   // read data from input file:
   //ifstream input_data_file(data_file, ios::in); 
   ifstream input_data_file(file_name, ios::in);

   for (i = 0; i < np; i++)
   {
   		input_data_file >> X[i] >> Y[i];
   }
   
    ofstream matlabout_file_2("mat_1.m", ios::out); 
   // populate mat_1.m file:

    matlabout_file_2 << "x = [";
    for (i = 0; i < np; i++)
    {
    	matlabout_file_2 << X[i];
    	if (i < np - 1)
    	{
    		matlabout_file_2 << ",";
    	}
    	else{};
    }
	
	matlabout_file_2 << "];" << endl;
	matlabout_file_2 << "y = [";
	for (i = 0; i < np; i++)
	{
		matlabout_file_2 << Y[i];
		if (i < np - 1)
		{
			matlabout_file_2 << ",";
		}
		else{};
	}

	matlabout_file_2 << "];" << endl;
	matlabout_file_2 << "coef = polyfit(x,y,1);" << endl;
	matlabout_file_2 << "m = coef(1);" << endl;
	matlabout_file_2 << "b = coef(2);" << endl;
	matlabout_file_2 << "Y = m * x + b;" << endl;
	matlabout_file_2 << "matlab_error = sum((y - Y).^2);" << endl;
	matlabout_file_2 << "fid = fopen('output_7.txt','a');" << endl;
	matlabout_file_2 << "fprintf(fid,'*** RESULT FROM MATLAB\\n');" << endl;
	matlabout_file_2 << "fprintf(fid,'*** THE MATCHING FUNCTION IS Y = (%.3f) * X + (%.3f) \\n', m, b);" << endl;
	matlabout_file_2 << "fprintf(fid,'*** THE ERROR FROM MATLAB IS %.3f \\n', matlab_error);" << endl;
  
   // run mat_1.m file:
   //system("/bin/csh/ee259/tools/pro_7/run_mat_1");
	system("matlab < mat_1.m");

/*
x=[0,1,2.1,3.1,4.2];
y=[1,3.1,5.2,6.9,9.1];
coef=polyfit(x,y,1);
m=coef(1);
b=coef(2);
Y=m*x+b;
matlab_error=sum((y - Y).^2);
fid=fopen('output_7.txt','a');
fprintf(fid,'*** RESULT FROM MATLAB\n');
fprintf(fid,'*** THE MATCHING FUNCTION IS Y=(%.3f) * X +(%.3f) \n',m,b);
fprintf(fid,'*** THE ERROR FROM MATLAB IS %.3f \n', matlab_error);
*/
}

void EZ_CURVE_FIT::LS_FIT_BY_PYTHON(char * file_name)
{// your code goes below:
	int i;

	double X[10], Y[10];

	ifstream i_f(file_name, ios::in);

	for (i = 0; i < np; i++)
	{
		i_f >> X[i] >> Y[i];
	}

	ofstream o_f_py("my_pyhton_7.py", ios::out);

	o_f_py << "import numpy as np" << endl;
	o_f_py << "x = np.array([";

	for (i = 0; i < np; i++)
	{
		o_f_py << X[i];
		if (i < np - 1)
		{
			o_f_py << ",";
		}
	}
	o_f_py << "])" << endl;
	o_f_py << "y = np.array([";

	for (i = 0; i < np; i++)
	{
		o_f_py << Y[i];
		if (i < np - 1)
		{
			o_f_py << ",";
		}
	}
	o_f_py << "])" << endl;
	o_f_py << "coef = np.polyfit(x,y,1)" << endl;
	o_f_py << "m = coef[0]" << endl;
	o_f_py << "b = coef[1]" << endl;
	o_f_py << "Y = m*x+b" << endl;
	o_f_py << "python_error = np.sum((y-Y) ** 2)" << endl;

	o_f_py << "fid = open('./output_7.txt','a')" << endl;
	o_f_py << "fid.write(\"*** RESULT FROM PYTHON\\n\")" << endl;
	o_f_py << "fid.write(f\"*** THE MATCHING FUNCTION IS Y=({m:.3f}) * X +({b:.3f}) \\n\")" << endl;
	o_f_py << "fid.write(f\"*** THE ERROR FROM PYTHON IS {python_error:.3f}\\n\")" << endl;
	o_f_py << "fid.close()" << endl;

	system ("python3 my_pyhton_7.py");
}
/*
import numpy as np 

x = np.array([0,1,2.1,3.1,4.2])
y = np.array([1,3.1,5.2,6.9,9.1])
coef = np.polyfit(x,y,1)
m = coef[0]
b = coef[1]
Y = m*x+b
python_error = np.sum((y-Y) ** 2)

fid = open('./output_7.txt','a')
fid.write("*** RESULT FROM PYTHON\n")
fid.write(f"*** THE MATCHING FUNCTION IS Y=({m:.3f}) * X +({b:.3f}) \n")
fid.write(f"*** THE ERROR FROM PYTHON IS {python_error:.3f}\n")
fid.close()
*/

