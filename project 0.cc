///////////////////////////////////////////////////////////////
// STUDENT NAME: ESTEBAN CUELLAR-AGUILAR
// PROJECT NUMBER: p0
///////////////////////////////////////////////////////////////

include <iostream>
include <fstream>
include <iomanip>

using namespace std;

ifstream i_f; // declare a pointer to an input file;
ofstream o_f("output.txt", ios::out); 

  class P0_GRADES{
   public:      // public methods for this class
        P0_GRADES(int, int); // constructor;
		// example usage: g.P0_GRADES(x, y);
		// create an object called g with x students each with y exams;

	void P0_LIST(int); // a method;
		// example usage: g.P0_LIST(x);
		// if x is 1, list the student ids;
		// if x is 2, list the student ids and exam grades;
                // returns no values;

	void P0_MIN(int); // another method;
		// example usage: e.P0_MIN(x);
		// find the minimum grade for exam x;
                // returns no values;

	void P0_MAX(int); // another method;
		// example usage: e.P0_MAX(x);
		// find the maximum grade for exam x;
                // returns no values;

   protected:	// protected var to be used by this class and its derivative
   		// classes only (not from main)
        int n;  // no of students;
        int e;  // no of exams;
	int id[20]; // an integer array to hold the ids;
	int pin[20]; // an integer array to hold the pins;
        int grades[20][10]; // 2-dim array to hold exam grades; 
   };
  
P0_GRADES::P0_GRADES(int x, int y)
{
	// your goes code below:
	int i, j;
	n = x;
	e = y;

	i_f.open("studentGrades.txt", ios::in); // open input file;

	for(i =0; i < n; i++)
	{
		i_f >> id[i] >> pin[i];
		for(j = 0; j < e; j++)
		{
			i_f >> grades[i][j];
		}
	}
	i_f.close(); // close input file;
	i_f.clear(); // rewind file pointer to the top of the file;

	o_f << "P0: OBJECT HAS " << x << " STUDENTS, EACH WITH " << y << " EXAMS." << endl;
}

void
P0_GRADES::P0_LIST(int x)
{
	int i, j;
	o_f << "P0: START P0_LIST" << endl;
	// your code goes below:
	if(x == 1)
	{
		o_f << "P0: STUDENT IDS:"<< endl;
		for(i = 0; i < n; i++)
		{
			o_f << id[i] << endl;
		}

	}
	else if(x == 2)
	{
		o_f << "P0: STUDENT IDS AND EXAM GRADES:" << endl;
		for(i = 0; i < n; i++)
		{
			o_f << id[i] << "\t"; 
			for(j = 0; j < e; j++)
			{
				o_f << grades[i][j] << "\t";
			}
			o_f << endl;
		}
	}
	else 
	{
		o_f << "P0: INPUT ERROR" << endl;
	}
	o_f << "P0: END P0_LIST" << endl;
}

void
P0_GRADES::P0_MIN(int x)
{
	// your code goes below:
	int i;
	int min;

	o_f << "P0: START P0_MIN" << endl;
	if (x >=0 && x <e)
	{
		min = grades[0][x];
		for(i = 0; i <n; i++)
		{
			if (min > grades[i][x])
			{
				min = grades[i][x];
			}
			else {}
		}
		o_f << "P0: MINIMUM FOR " << n << " STUDENTS IN EXAM "
			<< x << " IS " << min << "." << endl;
	}
	else
	{
		o_f << "P0: INPUT ERROR" << endl;
	}
	o_f << "P0: END P0_MIN" << endl;
}

void
P0_GRADES::P0_MAX(int x)
{
	// your code goes below:
	int i;
	int max;

	o_f << "P0: START P0_MAX" << endl;
	if (x >=0 && x <e)
	{
		max = grades[0][x];
		for(i = 0; i <n; i++)
		{
			if (max < grades[i][x])
			{
				max = grades[i][x];
			}
			else {}
		}
		o_f << "P0: MAXIMUM FOR " << n << " STUDENTS IN EXAM "
			<< x << " IS " << max << "." << endl;
	}
	else
	{
		o_f << "P0: INPUT ERROR" << endl;
	}
	o_f << "P0: END P0_MAX" << endl;
}
