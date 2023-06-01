///////////////////////////////////////////////////////////////
// STUDENT NAME: ESTEBAN CUELLAR-AGUILAR
// PROJECT NUMBER: project 3
///////////////////////////////////////////////////////////////

include "project_2.cc"

using namespace std;

ifstream i_f_2; // declare a pointer to pin input file;

  class P3_GRADES: public P2_GRADES{
   public:      // public methods for this class

        P3_GRADES(int, int); // constructor;
		// example usage: B.P3_GRADES(x, y);
		// create an object B with x students each with y grades;
		// read the names from studentNames.txt file

	void P3_LIST(int); // a method;
		// example usage: B.LIST(x);
		// if x is 0, use inheritance P0_LIST(1);
		// if x is 1, list grades and names;
		// otherwise, input error;

	void P3_SORT(int); // a method;
		// example usage: B.P3_SORT(x);
		// if x == 0, sort based on ids;
		// if x == 1, alphabetize based on last names;
		// returns no values;

	int P3_VERIFY(string, string); // a method;
		// example usage: B.P3_VERIFY("KATE", "OGGEN");
		// if there is such a student and return index;
		// if there is no such a student and return -1;
		// if first/last name > 14 characters, error and return -2;

	int P3_REPORT(int, int, int, int);  //another method;
		// example usage: B.P3_REPORT(w, x, y, z);
		// if w == 0, use inheritance P2_REPORT(x, y, z); return index;
		// if w == 1, id x, pin y, and exam z, and names; return index;
		// if input error: return -2;
		// returns no values;

	protected:
		string firstNames[20]; // first names for students;
		string lastNames[20]; // last names for students;
   };

P3_GRADES::P3_GRADES(int x, int y)
	: P2_GRADES(x, y) // call base class constructor (it is the rule);
{
	int i;
	i_f_2.open("studentNames.txt", ios::in); // open input file;

	for(i =0; i < n; i++)
	{
		i_f_2 >> firstNames[i];
		i_f_2 >> lastNames[i];
	}
	i_f_2.close(); // close input file;
	i_f_2.clear(); // rewind file pointer to the top of the file;

	o_f << "P3_P3_P3_P3: P3_GRADES CREATES OBJECT WITH NAMES." << endl;
}

void 
P3_GRADES::P3_LIST(int x)
{
	int i, j;
	o_f << "P3_P3_P3_P3: START P3_LIST" << endl;
	if (x == 0)
	{
		o_f << "P3_P3_P3_P3: INHERIT FROM P1_LIST(1):" << endl;
		P1_LIST(1);
	}
	else if (x == 1)
	{
		o_f << "P3_P3_P3_P3: LISTING  NAMES AND GRADES:" 
			<< endl;
		for(i = 0; i < n; i++)
		{
			o_f << "P3_P3_P3_P3: " << firstNames[i] << "\t"
				<< lastNames[i] << "\t" << id[i]; 
				for(j = 0; j < e; j++)
				{
					o_f << "\t" << grades[i][j];
				}
				o_f << endl;
		}
	}
	else
	{
		o_f << "P3_P3_P3_P3: INPUT ERROR." << endl;
	}
	o_f << "P3_P3_P3_P3: END P3_LIST" << endl;
}

void 
P3_GRADES::P3_SORT(int x)
{
	// your code goes below:
	int k, i, j, min, min_pos;
	int temp;
	string min_name, temp_name;
	o_f << "P3_P3_P3_P3: START P3_SORT" << endl;

	if (x == 0)
	{
		o_f << "P3_P3_P3_P3: SORTING STUDENTS IN ASCENDING ORDER "
			<< " BASED ON IDS" << endl;
		for(i = 0; i < n; i++)
		{
			min = id[i]; // make ith one minimum first;
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
			temp_name = lastNames[min_pos];
			lastNames[min_pos] = lastNames[i];
			lastNames[i] = temp_name;
	
			// swap contents of element in position min_pos w/ contents of element in position i:
			temp_name = firstNames[min_pos];
			firstNames[min_pos] = firstNames[i];
			firstNames[i] = temp_name;
	
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
	}
	else if (x == 1)
	{
		o_f << "P3_P3_P3_P3: SORTING STUDENTS IN ALPHABETICAL ORDER "
			<< " BASED ON LAST NAMES" << endl;
		for(i = 0; i < n; i++)
		{
			min_name = lastNames[i]; // make ith one minimum first;
			min_pos = i;
			for(j = i; j < n; j++)
			{
				if (min_name > lastNames[j])
				{
					min_name = lastNames[j];
					min_pos = j;
				}
				else{}
			}
			// swap contents of element in position min_pos w/ contents of element in position i:
			temp_name = lastNames[min_pos];
			lastNames[min_pos] = lastNames[i];
			lastNames[i] = temp_name;
	
			// swap contents of element in position min_pos w/ contents of element in position i:
			temp_name = firstNames[min_pos];
			firstNames[min_pos] = firstNames[i];
			firstNames[i] = temp_name;
	
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
	}
	else
	{
		o_f << "P3_P3_P3_P3: INPUT ERROR." << endl;
	}
	o_f << "P3_P3_P3_P3: END P3_SORT" << endl;
}

int 
P3_GRADES::P3_VERIFY(string F, string L)
{
	int i, FOUND, FOUND_POS;

	o_f << "P3_P3_P3_P3: START P3_VERIFY" << endl;
	if (F.length() <= 14 && L.length() <=14 )
	{
		FOUND = 0;
		FOUND_POS = -1;
		for(i = 0; i <n && FOUND == 0; i++)
		{
			if(F == firstNames[i] && L == lastNames[i])
			{
				FOUND = 1;
				FOUND_POS = i;
			}
			else{}
		}
		if (FOUND == 1)
		{
			o_f << "P3_P3_P3_P3: THERE IS A STUDENT AS "
				<< F << " " << L << "." << endl;
			o_f << "P3_P3_P3_P3: END P3_VERIFY" << endl;
			return FOUND_POS;
		}
		else
		{
			o_f << "P3_P3_P3_P3: THERE IS NO STUDENT AS "
				<< F << " " << L << "." << endl;
			o_f << "P3_P3_P3_P3: END P3_VERIFY" << endl;
			return -1;
		}
	}
	else
	{
		o_f << "P3_P3_P3_P3: INPUT ERROR" << endl;
		o_f << "P3_P3_P3_P3: END P3_VERIFY" << endl;
		return -2;
	}
}

// if w == 0, use inheritance P2_REPOrt(x, y, z); return -1;
// if w == 1, id x, pin y, and exam z, and names; return index;
int
P3_GRADES::P3_REPORT(int w, int x, int y, int z)
{
	int ret_value;

	o_f << "P3_P3_P3_P3: START P3_REPORT" << endl;
	if (w == 0)
	{
		o_f << "P3_P3_P3_P3: INHERIT FROM P2_REPORT:" << endl;
		P2_REPORT(x, y, z);
		o_f << "P3_P3_P3_P3: END P3_REPORT" << endl;
		return -1;
	}
	else if (w == 1)
	{
		o_f << "P3_P3_P3_P3: FIRST INHERIT FROM P2_REPORT:" << endl;
		ret_value = P2_REPORT(x, y, z);
		if (ret_value != -1 && ret_value != -2)
		{
			o_f << "P3_P3_P3_P3: STUDENT NAME IS: " << firstNames[ret_value]
				<< " " << lastNames[ret_value] << endl;
			o_f << "P3_P3_P3_P3: END P3_REPORT" << endl;
			return ret_value;
		}
		else
		{
			o_f << "P3_P3_P3_P3: INPUT ERROR RETURNED BY P2_REPORT" << endl;
			o_f << "P3_P3_P3_P3: END P3_REPORT" << endl;
			return -2;
		}
	}
	else
	{
		o_f << "P3_P3_P3_P3: INPUT ERROR" << endl;
		o_f << "P3_P3_P3_P3: END P3_REPORT" << endl;
		return -2;
	}
}
