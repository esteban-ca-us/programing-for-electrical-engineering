#############################################################
## STUDENT NAME: ESTEBAN CUELLAR-AGUILAR
## PROJECT NUMBER: project 1
#############################################################
# using project_0 import *, we already imported the output file
# we do not have to open the file again, since running this line will
# open the file. We can just use the file object now:
from project_0 import * 

# in P1_GRADES we inherit from P0_GRADES. Syntax is as follows:
# class DerivedClassName(BaseClassName):

class P1_GRADES(P0_GRADES): 
	def __init__(self, w, z):
		super().__init__(w, z) # calling the base class constructor

		output_file.write("P1_P1: P1_GRADES CONSTRUCTOR CREATED A NEW OBJECT.\n")
        
	def P1_LIST(self, q):
		''' a method
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
		'''
		output_file.write("P1_P1: START P1_LIST\n")
		if (q == 0):
			output_file.write ("P1_P1: INHERITING FROM P0_LIST:\n") 
			self.P0_LIST(1) # call from base class
		elif (q == 1):
			output_file.write ("P1_P1: LISTING IDS AND GRADES:\n")
			for i in range(self.n):
				output_file.write(f"P1_P1: ID[{i}]: {self.id[i]}\t")
				for j in range(self.e):
					output_file.write(f"EXAM[{j}]: {self.grades[i][j]}\t")
				output_file.write("\n") 
		else:
			output_file.write ("P1_P1: INPUT ERROR\n")
		output_file.write("P1_P1: END P1_LIST\n")

	def P1_FIND(self, r, s):
		output_file.write("P1_P1: START P1_FIND\n")
		if r > 0 and r < 10000 and s > 0 and s < 1000:
			found = 0
			for i in range (self.n):
				if self.id[i] == r and self.pin[i] == s:
					found = 1
					found_pos = i
				else:
					pass
			if found == 1:
				output_file.write(f"P1_P1: FOUND STUDENT WITH ID {r}\n")
				output_file.write("P1_P1: GRADES:\n")
				output_file.write("P1_P1: ")
				for j in range(self.e):
					output_file.write(f"EXAM[{j}]: {self.grades[found_pos][j]}\t")
				output_file.write("\n") 
				output_file.write("P1_P1: END P1_FIND\n")
				return found_pos
			else:
				output_file.write(f"P1_P1: NO SUCH STUDENT WITH ID {r}\n")
				output_file.write("P1_P1: ALL STUDENT IDS ARE:\n")
				self.P0_LIST(1)
				output_file.write("P1_P1: END P1_FIND\n")
				return  -1
		else:
			output_file.write("P1_P1: INPUT ERROR\n")
			output_file.write("P1_P1: END P1_FIND\n")
			return -2

