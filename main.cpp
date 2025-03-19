#include <iostream>
#include <fstream>
#include <iomanip>

double map(double x)
{ 
return 3/4*x-7/4;
}

int main()
{ 
    std::ifstream file("data.txt"); 
	
	if(file.fail())
	{
		std::cerr << "File not found" << std::endl;
		return 1;
	}
	
	double val;
	double m;
	int n = 0;
	double sum = 0;
	std::ofstream writeout("result.txt");
	writeout << "#N Mean" << std::endl;
	writeout << std::scientific << std::setprecision(16);
	while(file >> val)
	{
		n +=1;
		sum += map(val);
		m = sum/n;
		writeout << n << " " << m << std::endl;
		
	}
	
	file.close();
	writeout.close();
	
    return 0;
}
