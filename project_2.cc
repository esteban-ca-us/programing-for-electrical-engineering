///////////////////////////////////////////////////////////////
// STUDENT NAME: ESTEBAN CUELLAR-AGUILAR
// PROJECT NUMBER: project 2
///////////////////////////////////////////////////////////////

include "project_1.cc"

using namespace std;

  class P2_GRADES: public P1_GRADES{
   public:      // public methods for this class

        P2_GRADES(int, int); // constructor;
		// example usage: P2_GRADES B(x, y);
		// create object B with x students each with y grades;

	void P2_SORT(int); // a method;
		// example usage: B.P2_SORT(x);
		// if x is 0, list students using inheritance from P1_LIST(1);
		// if x is 1, sort students based on IDs in ascending order;
		// returns no values;

	int P2_REPORT(int, int, int);  //another method;
		// example usage: B.P2_REPORT(x, y, z);
		// for student id x and pin y, report grade in exam z;
		// use P1_FIND(x, y); when it returns index, print the grade for exam z;
		// passing grade is 75 or higher;
		// P2_REPORT returns index of student;
		// if no such student, P2_REPORT returns -1;
		// if input error, P2_REPORT returns -2;
   };

// implementation of constructor:
P2_GRADES::P2_GRADES(int x, int y)
	: P1_GRADES(x, y) // call base class constructor;
{
	o_f << "P2_P2_P2: P2_GRADES CONSTRUCTOR." << endl;
}

void 
P2_GRADES::P2_SORT(int x)
{
	// your code goes below:
	int k, i, j, min, min_pos;
	int temp;

	o_f << "P2_P2_P2: START P2_SORT" << endl;
	if(x == 0)
	{
		P1_LIST(1);
	}
	else if(x == 1)
	{
		for(i = 0; i < n; i++)
		{
			min = id[i]; // take the contents of id[i] and replace contents of min with it;
			min_pos = i;
			for(j = i; j < n; j++)
			{
				if (min > id[j])
				{
					min = id[j];
					min_pos = j;
				}
				else{}
			}
			// swap contents of element in position min_pos w/ contents of element in position i:
			temp = id[min_pos];
			id[min_pos] = id[i];
			id[i] = temp;
	
			// swap pins:
			temp = pin[min_pos];
			pin[min_pos] = pin[i];
			pin[i] = temp;
	
			// swap grades:
			for(k = 0; k < e; k++)
			{
				temp = grades[min_pos][k];
				grades[min_pos][k] = grades[i][k];
				grades[i][k] = temp;
			}
		}
		o_f << "P2_P2_P2: STUDENTS ARE SORTED BASED ON IDS:" << endl;
		P0_LIST(1);
	}
	else
	{
		o_f << "P2_P2_P2: INPUT ERROR" << endl;
	}
	o_f << "P2_P2_P2: END P2_SORT" << endl;
	/*
	// swap contents of x and y: 
	// for example: before swap x= 10 and y = 20; after swap: x = 20 and y = 10;
	x = y; // x = 20; y = 20;
	y = x; // x = 20; y = 20;
	// DOES NOT WORK!
	
	// use a third variable called temp:
	temp = x; // temp = 10; x = 10; y = 20;
	x = y;	  // temp = 10; x = 20; y = 20;
	y = temp; // temp = 10; x = 10; y = 20; WORKS!
	*/
}

int
P2_GRADES::P2_REPORT(int x, int y, int z)
{
	// your code goes below:
	int GRADE, return_value;
	o_f << "P2_P2_P2: START P2_REPORT" << endl;
	return_value = P1_FIND(x, y); // check if there is such a student;	
//debug statement:
//cout << "x " << x << " y " << y << " z " << z << " return_value = " << return_value << endl;
	if (return_value == -2 || x <0 || x > 9999 || y < 0 || y > 999  || z < 0 || z >= e)
	{
		o_f << "P2_P2_P2: INPUT ERROR." << endl;
		o_f << "P2_P2_P2: END P2_REPORT" << endl;
		return -2;
	}
	else if (return_value == -1)
	{
		o_f << "P2_P2_P2: NO SUCH STUDENT WITH ID " << x << "." << endl;
		o_f << "P2_P2_P2: END P2_REPORT" << endl;
		return -1;
	}
	else
	{
		GRADE = grades[return_value][z];
		o_f << "P2_P2_P2: STUDENT " << x << " GRADE FOR EXAM " << z << " IS " << GRADE << "." << endl;
		o_f << "P2_P2_P2: END P2_REPORT" << endl;
		return return_value;
	}
}
