/***************************************************************************
 * Monkey Convert -  fileio.cxx
 *
 * Thu December 29 17:18:50 2011
 * Copyright (C) 2011 GNA SERVICES INC.
 * Copyright (C) 2011 Andrew Smith (GNA SERVICES INC) <Andrew@GNAServicesInc.com>
 * 
 * Author: Andrew Joseph Smith <andrew@gnaservicesinc.com>
 ****************************************************************************/
/*
 * Monkey-Convert is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Monkey-Convert is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <fstream>
#include <iostream>

#include "fileio.h"

inline int convert(char chC);

int fileio(char *file, bool sout, char *ofile)
{
	 using namespace std;
fstream iofile(file, ios::in);
		
 if (!iofile)
    {
		return 1;
	}
else{
	char chChar;
	int size=0;
	long double dec=0;
	ifstream inf(file);
	inf.seekg(0, ios::end); 
	size=inf.tellg();
	if (!size)
	{
		return 2;
	}

	if (sout == false)
	{
	ofstream outf(ofile, ios::app);		
	outf << endl << "char monkey[" << size << "] = {";
	long double cnt=0;
  while (iofile.get(chChar))
    {
		if (cnt > 0)
			{
				outf << ",";
			}
		outf << convert(chChar);
		cnt++;
		iofile.seekg(iofile.tellg(), ios::beg);		
	}
	outf << "};" << endl;
	outf.close();
	iofile.close();
	}
else {
cout << endl << "char monkey[" << size << "] = {";
	long double cnt=0;
  while (iofile.get(chChar))
    {
		if (cnt > 0)
			{
				cout << ",";
			}
		cout << convert(chChar);
		cnt++;
		iofile.seekg(iofile.tellg(), ios::beg);		
	}
	iofile.close();
	cout << "};" << endl;	
}
		
	return 99;
 }
}

inline int convert(char chC)
{
	using namespace std;
	int  asciiVal = 0;	
	asciiVal = (char)chC;
	return asciiVal;
}