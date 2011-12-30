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


#include "convert.h"
#include "fileio.h"

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
	int dec=0,cnt=0, size=0;
	ifstream inf(file);
	inf.seekg(0, ios::end); 
	size=inf.tellg();
	int decArray[size];
	int returnCheck=-1;
  while (iofile.get(chChar))
    {
		returnCheck=convert(chChar);
		if (returnCheck >= 0 && returnCheck <= 255)
		{
		decArray[cnt]=returnCheck;
		cnt++;
		}
		iofile.seekg(iofile.tellg(), ios::beg);		
	}

	if (sout == false)
	{
	ofstream outf(ofile, ios::app);		
	outf << endl << "char monkey[" << cnt << "] = {";
	for (int i=0; i < cnt; i++)
		{
			if (i > 0)
			{
				outf << ",";
			}
		outf << decArray[i];
		}
	outf << "};" << endl;
	outf.close();
	}
	else {
	cout << "char monkey[" << cnt << "] = {";
	for (int i=0; i < cnt; i++)
		{
			if (i > 0)
			{
				cout << ",";
			}
		cout << decArray[i];
		}
	cout << "};";
	}
	return 99;
 }
}