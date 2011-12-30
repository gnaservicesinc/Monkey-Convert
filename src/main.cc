/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * Monkey Convert - main.cc
 * 
 * Copyright (C) 2011 GNA SERVICES INC.
 * Copyright (C) 2011 Andrew Smith (GNA SERVICES INC) <Andrew@GNAServicesInc.com>
 * 
 * Author: Andrew Joseph Smith <andrew@gnaservicesinc.com>
 * 
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


using namespace std;

int cnf(char *arg);

int main(int argc, char *argv[])
{
	using namespace std;
	int status=5;
	bool sout = true;
	char *pFilename, *pOFilename;
	#define VERSION 1.0
	#define CMDMAX 3

	
	if (argc <= 1 || argc > CMDMAX)
    {
		cnf(argv[0]);
        return(1);
	}

	else
	{
		switch (argc)
		{
			case 2:
				sout=true;
				pFilename = argv[1];
				pOFilename = 0;
				status=fileio(pFilename, sout, pOFilename);
				break;
			case 3:
				sout=false;
				pFilename = argv[1];
				pOFilename = argv[2];
				status=fileio(pFilename, sout, pOFilename);
				break;
			default:
				cnf(argv[0]);
				break;
		}
	}
	
	switch (status)
	{
		case 1: 
			cout << endl << endl << "By file name I meant a FILE name..." << endl << "You know..." << endl << "Like a FILE that is actually ON your computer :)" << endl << "That would be great, until then I am just going to go ahead and exit." << endl << endl;
			return(1);
			break;
		case 2:
			
		case 99:
			cout  << endl;
		break;
		default:
			cout << "Uh oh, someting unexpected has happened.";
			break;
	}
return 0;
}

int cnf(char *arg)
{
	using namespace std;
cout << endl << "Monkey-Converter Version " << VERSION << endl << endl << "	 Usage: " << arg << " <Filename (REQUIRED)>  <Output (Optional)> " << endl << endl;
}
	