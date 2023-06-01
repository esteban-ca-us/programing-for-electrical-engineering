output_file = open("python_Output.txt",'w')

class P0_GRADES:

	# start implementation of constructor:
	def __init__(self, x, y):
		''' 
        	this is the constructor
            	Example usage: B = P0_GRADES(x,y)
		B is an object with x students and y exams;
		it populates the data members using values read
		from an input file called studentGrades.txt
		returns no values 
        	'''
		self.n = x # number of students
		self.e = y # number of exam
		self.id = []
		self.pin = []
		self.grades = []
        
		# In Python, this is the conventional way to read in a text file; 
		# the "with" statement closes the file at the end of the with clause;
		# typically the file is read line by line and parsed; 
		with open('studentGrades.txt','r') as i_f:
			for line in i_f: 
				self.id.append(int(line.split()[0])) # first element of each line is the id
				self.pin.append(int(line.split()[1])) # second element of each line is pin
				self.grades.append([int(x) for x in line.split()[2:]]) # the rest of the line is grades 
		# end with
		output_file.write(f"P0: OBJECT HAS {self.n} STUDENTS, EACH WITH {self.e} EXAMS.\n")
	# end implementation of constructor

	# start implementation of method P0_LIST:
	def P0_LIST(self, x):
		output_file.write("P0: START P0_LIST\n")
		if x == 1:
			output_file.write("P0: STUDENT IDS:\n")
			'''
			for(i = 0; i < n; i++)
			{
				o_f << id[i] << endl;
			}
			'''
			for i in range(self.n):
				output_file.write(f"{self.id[i]}\n")
		elif x == 2:
			output_file.write("P0: STUDENT IDS AND EXAM GRADES:\n")
			'''
			for(i = 0; i < n; i++)
			{
				o_f << id[i] << endl;
				for(j = 0; j < e; j++)
				{
					o_f << grades[i][j];
				}
				o_f << endl;
			}
			'''
			for i in range(self.n):
				output_file.write(f"{self.id[i]}\t")
				for j in range(self.e):
					output_file.write(f"{self.grades[i][j]}\t")
				output_file.write("\n")
		else:
			output_file.write("P0: INPUT ERROR\n") 

		output_file.write("P0: END P0_LIST\n")
	# end implementation of method P0_LIST

	# start implementation of method P0_MIN:
	def P0_MIN(self, x):
		''' A method
		
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
		'''
		output_file.write("P0: START P0_MIN\n")
		if (x >= 0) and (x < self.e):
			min = self.grades[0][x]
			for i in range(self.n):
				if min > self.grades[i][x]:
					min = self.grades[i][x]

			output_file.write(f"P0: MINIMUM FOR {self.n} STUDENTS IN EXAM {x} IS {min}.\n")
		else:
			output_file.write("P0: INPUT ERROR\n")

		output_file.write("P0: END P0_MIN\n")
	# end implementation of method P0_MIN

	# start implementation of method P0_MAX:
	def P0_MAX(self, x):
		''' A method
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
		'''
		output_file.write("P0: START P0_MAX\n")
		if (x >= 0) and (x < self.e):
			max = self.grades[0][x]
			for i in range(self.n):
				if max < self.grades[i][x]:
					max = self.grades[i][x]

			output_file.write(f"P0: MAXIMUM FOR {self.n} STUDENTS IN EXAM {x} IS {max}.\n")
		else:
			output_file.write("P0: INPUT ERROR\n")

		output_file.write("P0: END P0_MAX\n")
	# end implementation of method P0_MAX
# end of class definition

if __name__ == '__main__':
    output_file.close()
