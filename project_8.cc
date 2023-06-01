///////////////////////////////////////////////////////////////
// STUDENT NAME: ESTEBAN CUELLAR-AGUILAR
// PROJECT NUMBER: project 8
///////////////////////////////////////////////////////////////

include <iostream>
include <fstream>
include <cstring>
include <cstdlib>
include <cmath>
include <ctype.h>

using namespace std;

ofstream o_f_8("output_8.txt", ios::out);

class EZ_DIFF_INTEGRATE
{
   public:
	EZ_DIFF_INTEGRATE(char *); // constructor; 
		// example: s.EZ_DIFF_INTEGRATE("in.txt");
		// input data file is given;

	void EZ_DIFF_BY_ME(float, float, int);
		// example: s.EZ_DIFF_BY_ME(a, b, n);
		// differentiate the function defined in input file;
		
	void EZ_INTEG_BY_ME(float, float, int);
		// example: s.EZ_INTEG_BY_ME(a, b, n);
		// integrate the function defined in input file;
		
   private:
	int np; // number of data pairs
	char func_type[10]; // sin, cos, or poly
	int exp; // exponent of sin or cos 
	int arg; // argument to include in function
};

EZ_DIFF_INTEGRATE::EZ_DIFF_INTEGRATE(char * in_fn)
{
	char TYPE[10];
	char char_tempo[10]; // temp var to hold a string;
	int i_tempo; // temp var to hold an integer;
	int input_error;

	o_f_8 << "CONSTRUCTOR WITH INPUT FILE: " << in_fn << endl;
	//cout << "CONSTRUCTOR WITH INPUT FILE: " << in_fn << endl;
	// start parsing the input:
	ifstream i_f_8(in_fn, ios::in);
	exp = 1;

	i_f_8 >> TYPE;
	
	if (strcmp(TYPE, "sin") == 0 || strcmp(TYPE, "cos") == 0)
	{
		strcpy(func_type, TYPE);
		i_f_8 >> char_tempo;
	
		if (!strcmp(char_tempo, "(") == 0 && !strcmp(char_tempo, "**") == 0)
		{
			input_error = 1;
			return;
		}

		if (strcmp(char_tempo, "**") == 0)
		{
			if (!(i_f_8 >> i_tempo))
			{
				input_error = 1;
				return;
			}
			
			exp = i_tempo;

			i_f_8 >> char_tempo;

			if (!strcmp(char_tempo,"(") == 0)
			{
				input_error = 1;
				return;
			}
		}
		
		if (!(i_f_8 >> i_tempo))
		{
			input_error = 1;
			return;
		}
		
		arg = i_tempo;
		i_f_8 >> char_tempo;
		
		if (!strcmp(char_tempo, "*") == 0)
		{
			input_error = 1;
			return;
		}
		
		i_f_8 >> char_tempo;
		if (!strcmp(char_tempo, "x") == 0)
		{
			input_error = 1;
			return;
		}

		i_f_8 >> char_tempo;
		if (!strcmp(char_tempo, ")") == 0)
		{
			input_error = 1;
			 return;
		}

		i_f_8 >> char_tempo;
		if (!strcmp(char_tempo, ";") == 0)
		{
			input_error = 1;;
			 return;
		}
		

		o_f_8 << "FUNCTION IS PARSED AS: " << func_type << "**" << exp << " " << arg << "x" << endl; 

	}

	else
	{
		o_f_8 << "INPUT ERROR: NOT SIN OR COS" << endl;
		input_error = 1;
	}
}

void
EZ_DIFF_INTEGRATE::EZ_DIFF_BY_ME(float a , float b, int n)
{
	int i, k;
	int noof_min = 0;
	int noof_max = 0;
	float x_new, x_old;
	float x[30]; // x coordinate;
	float df[30]; // first derivative;

	
	if (strcmp(func_type,"sin") == 0)
	{
		// your code to compute differentiation for sin:
		
		x_old = a;
		x_new = a + (b - a) / n;
		
		for (i = 0; i < n; i++)
		{

			float new_term = 1.0;
			float old_term = 1.0;
			for (k = 0; k < exp; k++)
			{
				new_term *= sin(arg * x_new);
				old_term *= sin(arg * x_old);
			}

			df[i] = (new_term - old_term) / (x_new - x_old);
			x_old += (b - a) / n;
			x_new += (b - a) / n;
		}
	}

	else if (strcmp(func_type,"cos") == 0)
	{
		// your code to compute differentiation for cos:
		
		x_old = a;
		x_new = a + (b - a) / n;

		for (i = 0; i < n; i++)
		{
			df[i] = (cos(arg * x_new) - cos(arg * x_old)) / (x_new - x_old);
			x_old += (b - a) / n;
			x_new += (b - a) / n;
		}
	}

	// report extreme points:
	else if (strcmp(func_type, "x") == 0)
	{
		x_old = a;
                x_new = a + (b - a) / n;

                for (i = 0; i < n; i++)
		{
			df[i] = (x_new * x_new - 2 * x_new + 1) -
				(x_old * x_old - 2 * x_old + 1) / (x_new - x_old);
			
			x_old += (b - a) / n;
            x_new += (b - a) / n;

		}
	}
	// report extreme points:
	
	for (i = 0; i < n-1; i++)
	{
		if (df[i] > 0 && df[i + 1] < 0)
		{
			o_f_8 << "*** THERE IS AN EXTREME POINT"
				<< "*** df[" << i << "]: " << df[i]
				<< "\tdf[" << i+1 << "]: " << df[i+1] << endl;
			noof_max++;
		}

		else if (df[i] < 0 && df[i +1] > 0)
		{
			o_f_8 << "*** THERE IS AN EXTREME POINT"
				<< "*** df[" << i << "]: " << df[i]
				<< "\tdf[" << i+1 << "]: " << df[i+1] << endl;
			noof_min++;
		}
		
		else if (df[i] == 0)
		{
			o_f_8 << "*** THERE IS AN EXTREME POINT"
				<< "*** df[" << i << "]: " << df[i] << endl;
			noof_min++;
		}
	}

	o_f_8 << "THERE ARE " << noof_min << " MINIMUMS AND " << noof_max
		<< " MAXIMUMS FOR THIS " << func_type << " FUNCTION " << endl;
	o_f_8 << "IN THE INTERVAL OF " << a << " AND " << b << " WITH " << n << " POINTS. " << endl;
}

void
EZ_DIFF_INTEGRATE::EZ_INTEG_BY_ME(float a , float b, int n)
{
	int i, k;
	float x_new, x_old;
	float x[30]; // x coordinate;
	float df[30]; // first derivative;
	float ddf[30]; // second derivative;
	float integral = 0.0;
	float coeff = 0.0;
	float new_term = 1.0;
	
	if (strcmp(func_type,"sin") == 0)
	{
		// your code to compute integration for sin:
		
		x_new = a;
		coeff = (b - a) / (2 * n);
		
		for (i = 0; i <= n; i++)
		{
			new_term = 1.0;
			for (k = 0; k < exp; k++)
			{
				new_term *= sin(arg * x_new);
			}
			
			if (i == 0 || i == n)
			{
				integral += fabs(new_term);
			}

			else
			{
				integral += (2 * fabs(new_term));
			}

			x_new += (b - a) / n;
		}

		integral *= coeff;
	}

	else if (strcmp(func_type, "cos") == 0)
	{
		// your code to compute integration for cos:

		x_new = a;
		coeff = (b - a) / (2 * n);
		for (i = 0; i <= n; i++)
		{
			new_term = 1.0;
			for (k = 0; k < exp; k++)
			{
				new_term *= cos(arg * x_new); 
			}
		
			if (i == 0 || i == n)
			{
				integral += fabs(new_term);
			}

			else
			{
				integral += (2 * fabs(new_term));
			}

			x_new += (b - a) / n;
		}

		integral *= coeff;
	}

	else
	{

	}
	
	o_f_8 << "THE INTEGRATION OF THIS " << func_type << " FUNCTION " << endl;
	o_f_8 << "IN THE INTERVAL OF " << a << " AND " << b << " WITH " << n
		<< " POINTS IS " << integral << endl;

}
