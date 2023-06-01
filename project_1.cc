///////////////////////////////////////////////////////////////
// STUDENT NAME: ESTEBAN CUELLAR-AGUILAR
// PROJECT NUMBER: project 1
///////////////////////////////////////////////////////////////

#include "project_0.cc"

using namespace std;

  class P1_GRADES: public P0_GRADES{
   public:      // public methods for this class
        P1_GRADES(int, int); // constructor;
		// example usage: B.P1_GRADES(w, z);
		// create an object called B with w students each with z exams;

	void P1_LIST(int); // a method;
		// example usage: B.P1_LIST(q);
		// list the grades for a given exam;
		// if q is 0, list the ids (use inheritance);
		// if q is 1, list the ids and grades for all exams;
		// returns no values;

	int P1_FIND(int, int); // another method;
		// example usage: B.P1_FIND(r, s);
		// list the grades of student with id r and pin s;
		// if student exists, return its index;
		// if no such student, give list of all students; return -1;
		// if r and/or s are illegal, return -2;
		// rules: 0 < r < 10000 and 0 < s < 1000
   };

P1_GRADES::P1_GRADES(int w, int z)
	: P0_GRADES(w, z) // you must call base class constructor;
{
	// base class P0_GRADES reads students grades and populates
	// protected data members; so, no need to read them again;

	o_f << "P1_P1: P1_GRADES CONSTRUCTOR CREATED A NEW OBJECT." << endl;
}

void
P1_GRADES::P1_LIST(int q)
{
	// your code goes below:

	int i, j;
	o_f << "P1_P1: START P1_LIST" << endl;
	if (q == 0)
	{
		o_f << "P1_P1: INHERITING FROM P0_LIST:" << endl;
		P0_LIST(1); // inherit from from base class;
	}
	else if(q == 1) 
	{
		o_f << "P1_P1: LISTING IDS AND GRADES:" << endl;
		for(i = 0; i < n; i++)
		{
			o_f << "P1_P1: ID[" << i << "]: " << id[i] << "\t";
			for(j = 0; j < e; j++)
			{
				o_f << "EXAM[" << j << "]: " << grades[i][j] << "\t"; 
			}
			o_f << endl;
		}
	}
	else 
	{
		o_f << "P1_P1: INPUT ERROR" << endl;
	}
	o_f << "P1_P1: END P1_LIST" << endl;
}

int
P1_GRADES::P1_FIND(int r, int s)
{
	// your code goes below:
	int i, j, FOUND, FOUND_POS;

//cout << "\nin P1_FIND method: r: " << r << " s: " << s << endl;
//cout << "in P1_FIND method: rules: 0 < r < 10000 and 0 < s < 1000" << endl;

	o_f << "P1_P1: START P1_FIND" << endl;
	if(r > 0 && r < 10000 && s > 0 && s < 1000)
	{
		FOUND = 0;
		for(i = 0; i < n && FOUND == 0; i++)
		{
// debugging printout:
//cout << "id[" << i << "]: " << id[i] << " r: " << r << endl; 
			if (id[i] == r && pin[i] == s)
			{
				FOUND = 1;
				FOUND_POS = i;
			}
			else{}
		}
// debugging printout:
//cout << "in P1_FIND method: FOUND: " << FOUND << endl << endl;
		if (FOUND == 1)
		{
			o_f << "P1_P1: FOUND STUDENT WITH ID " << r 
				<< endl;
			o_f << "P1_P1: GRADES: " << endl;
			o_f << "P1_P1: ";
			for(j = 0; j < e; j++)
			{
				o_f << "EXAM[" << j << "]: " << grades[FOUND_POS][j] << "\t"; 
			}
			o_f << endl;
			o_f << "P1_P1: END P1_FIND" << endl;
			return FOUND_POS;
		}
		else
		{
			o_f << "P1_P1: NO SUCH STUDENT WITH ID " << r << endl;
			o_f << "P1_P1: ALL STUDENT IDS ARE:" << endl;
			P0_LIST(1);
			o_f << "P1_P1: END P1_FIND" << endl;
			return -1;
		}
	}
	else
	{
//cout << "in P1_FIND method: input error since r and/or s is illegal\n" << endl;
//cout << "in P1_FIND method: rules: 0 < r < 10000 and 0 < s < 1000" << endl;
		o_f << "P1_P1: INPUT ERROR" << endl;
		o_f << "P1_P1: END P1_FIND" << endl;
		return -2;
	}
}
