///////////////////////////////////////////////////////////////
// STUDENT NAME: ESTEBAN CUELLAR-AGUILAR
// PROJECT NUMBER: project 4
///////////////////////////////////////////////////////////////

include "project_3.cc"

using namespace std;

  class P4_GRADES: public P3_GRADES{
   public:      // public methods for this class

        P4_GRADES(char *, int, int); // constructor;
		// example usage: G.P4_GRADES("G1", x, y);
		// create an object G with x students each with y grades;

	void P4_LIST(string); // a method;
		// example usage: G.P4_LIST("P1");
		// if x == "P1", use inheritance from P1_LIST(1);
		// if x == "P3", use inheritance from P3_LIST(1);
		// otherwise input error;
		// returns no values;

	int operator == (int); // an overloaded operator;
		// example usage: if (G == 4)
		// if n is 4, return 1;
		// otherwise return 0;

	int operator == (P4_GRADES); // an overloaded operator;
		// example usage: if (G1 == G2)
		// return 1 if n in G1 is equal to n in G2;
		// return 0 otherwise;

        int operator -= (int); // an overloaded operator;
		// example usage: G -= 1234;
		// remove student id 1234 from class if exists;
		// returns 1 if successful;
		// returns -1 if no such student;
		// returns -2 if input error;

        void operator = (P4_GRADES); // an overloaded operator;
		// example usage: G1 = G2;
		// assign elements of G2 to G1;
		// G2 remains unchanged;
		// returns nothing;

        P4_GRADES operator + (P4_GRADES); // an overloaded operator;
		// example usage: G1+G2;
		// step 1: create a temporary P4_GRADES object (call it P4_TEMP);
		// step 2: copy elements of G1 into P4_TEMP; don't forget to update n and e;
		// step 3: append elements of G2 into P4_TEMP; don't forget to update n and e;
		// step 4: return P4_TEMP object;
   private:
	char objName[15]; // name for the object; max length 14;
   };

P4_GRADES:: P4_GRADES(char * O_N, int x, int y)
	: P3_GRADES(x, y)
{
	strcpy (objName, O_N);
	o_f << "P4_P4_P4_P4_P4: P4_GRADES CREATES OBJECT " << objName 
		<<  "." << endl;
	o_f << "=============================================" << endl;
}

void
P4_GRADES::P4_LIST(string x)
{
	o_f << "P4_P4_P4_P4_P4: START P4_LIST FOR " << objName << endl;
	if(x == "P1")
	{
		o_f << "P4_P4_P4_P4_P4: SINCE CALLED WITH \"P1\", INHERITING FROM P1_LIST(1):" << endl;
		P1_LIST(1);
	}
	else if(x == "P3")
	{
		o_f << "P4_P4_P4_P4_P4: SINCE CALLED WITH \"P3\", INHERITING FROM P3_LIST(1):" << endl;
		P3_LIST(1);
	}
	else
	{
		o_f << "P4_P4_P4_P4_P4: SINCE NOT CALLED WITH \"P1\" OR \"P3\", INPUT ERROR" << endl;
	}
	o_f << "P4_P4_P4_P4_P4: END P4_LIST FOR " << objName << endl;
	o_f << "=============================================" << endl;
}

int
P4_GRADES::operator == (int x)  
{
	o_f << "P4_P4_P4_P4_P4: START " << objName << ".operator==(" << x << ")" << endl;
	o_f << "P4_P4_P4_P4_P4: COMPARING n: " << n << " AND x: " << x << endl;
	if(n == x)
	{
		o_f << "P4_P4_P4_P4_P4: RETURNING TRUE " << endl;
		o_f << "P4_P4_P4_P4_P4: END " << objName << ".operator==(" << x << ")" << endl;
		o_f << "=============================================" << endl;
		return 1;
	}
	else
	{
		o_f << "P4_P4_P4_P4_P4: RETURNING FALSE " <<endl;
		o_f << "P4_P4_P4_P4_P4: END " << objName << ".operator==(" << x << ")" << endl;
		o_f << "=============================================" << endl;
		return 0;
	}
}

int
P4_GRADES::operator == (P4_GRADES obj2)  
{
	o_f << "P4_P4_P4_P4_P4: START " << objName << ".operator==(" << obj2.objName << ")" << endl;
	o_f << "P4_P4_P4_P4_P4: COMPARING n IN " << objName << ": " << n << " AND n IN " << obj2.objName << ": " 
		<< obj2.n << endl;
	if(n ==  obj2.n)
	{
		o_f << "P4_P4_P4_P4_P4: RETURNING TRUE" << endl;
		o_f << "P4_P4_P4_P4_P4: END " << objName << ".operator==(" << obj2.objName << ")" << endl;
		o_f << "=============================================" << endl;
		return 1;
	}
	else
	{
		o_f << "P4_P4_P4_P4_P4: RETURNING FALSE" <<endl;
		o_f << "P4_P4_P4_P4_P4: END " << objName << ".operator==(" << obj2.objName << ")" << endl;
		o_f << "=============================================" << endl;
		return 0;
	}
}

int
P4_GRADES::operator -= (int x) 
{
	int i, j, ret_val, FOUND, FOUND_POS;

	o_f << "P4_P4_P4_P4_P4: START " << objName << ".operator-=(" << x << ")" << endl;
	if (x <= 0 || x >= 10000)
	{
		o_f << "P4_P4_P4_P4_P4: INPUT ERROR " << endl;
		o_f << "P4_P4_P4_P4_P4: END " << objName << ".operator-=(" << x << ")" << endl;
		o_f << "=============================================" << endl;
		return -2;
	}
	else
	{
		FOUND = 0;
		for(i = 0; i < n; i++)
		{
			if(id[i] == x)
			{
				FOUND = 1;
				FOUND_POS = i;
			}
			else{}
		}
		if (FOUND == 0)
		{
			o_f << "P4_P4_P4_P4_P4: NO SUCH STUDENT WITH ID " << x << endl;
			o_f << "P4_P4_P4_P4_P4: END " << objName << ".operator-=(" << x << ")" << endl;
			o_f << "=============================================" << endl;
			return -1;
		}
		else
		{
			for(i = FOUND_POS; i < n-1; i++)
			{
				id[i] = id[i+1];
				pin[i] = pin[i+1];
				for(j = 0; j < e; j++)
				{
					grades[i][j] = grades[i+1][j];
				}
				firstNames[i] = firstNames[i+1];
				lastNames[i] = lastNames[i+1];
			}
			n--; // decrement n;
			o_f << "P4_P4_P4_P4_P4: STUDENT WITH ID " << x << " IS DELETED FROM "
				<< objName << "." << endl;
			o_f << "P4_P4_P4_P4_P4: END " << objName << ".operator-=(" << x << ")" << endl;
			o_f << "=============================================" << endl;
			return 1;
		}
	}
}

void
P4_GRADES::operator = (P4_GRADES obj2) 
{
	int i, j;
	o_f << "P4_P4_P4_P4_P4: START " << objName << ".operator=(" << obj2.objName << ")" << endl;

	n = obj2.n; 
	e = obj2.e; 
	for(i = 0; i < n; i++)
	{
		id[i] = obj2.id[i];
		pin[i] = obj2.pin[i];
		
		for(j = 0; j < e; j++)
		{
			grades[i][j] = obj2.grades[i][j];
		}
		firstNames[i] = obj2.firstNames[i];
		lastNames[i] = obj2.lastNames[i];
	}
	o_f << "P4_P4_P4_P4_P4: ELEMENTS IN " << obj2.objName << " ARE ASSIGNED TO " << objName << endl;
	o_f << "P4_P4_P4_P4_P4: END " << objName << ".operator=(" << obj2.objName << ")" << endl;
	o_f << "=============================================" << endl;
}

P4_GRADES
P4_GRADES::operator + (P4_GRADES obj2)
{
	int i, j;
	P4_GRADES P4_TEMP("P4_TEMP", 0, 0);

	P4_TEMP.e = e;
	o_f << "P4_P4_P4_P4_P4: START " << objName << ".operator+(" << obj2.objName << ")" << endl;
	for(i = 0; i < n; i++)
	{
		P4_TEMP.id[i] = id[i];
		P4_TEMP.pin[i] = pin[i];
		for(j = 0; j < e; j++)
		{
			P4_TEMP.grades[i][j] = grades[i][j];
		}
		P4_TEMP.firstNames[i] = firstNames[i];
		P4_TEMP.lastNames[i] = lastNames[i];
	}
	P4_TEMP.n = n;

	for(i = 0; i < obj2.n; i++)
	{
		P4_TEMP.id[i+n] = obj2.id[i];
		P4_TEMP.pin[i+n] = obj2.pin[i];
		
		for(j = 0; j < obj2.e; j++)
		{
			P4_TEMP.grades[i+n][j] = obj2.grades[i][j];
		}
		P4_TEMP.firstNames[i+n] =  obj2.firstNames[i];
		P4_TEMP.lastNames[i+n] = obj2.lastNames[i];
	}
	P4_TEMP.n += obj2.n;
	P4_TEMP.e = e;
	o_f << "P4_P4_P4_P4_P4: " << n << " ELEMENTS IN " << objName 
		<< " AND " << obj2.n << " ELEMENTS IN " << obj2.objName
		<< " ARE ADDED TO " << P4_TEMP.objName << endl;
	o_f << "P4_P4_P4_P4_P4: RETURNING " << P4_TEMP.objName << endl;
	o_f << "P4_P4_P4_P4_P4: END " << objName 
		<< ".operator+(" << obj2.objName << ")" << endl;
	o_f << "=============================================" << endl;

	return P4_TEMP;
}
