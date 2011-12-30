/***************************************************************************
 * Monkey Convert -  convert.cxx
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

 int convert(char chC)
{
	 using namespace std;
	int  asciiVal = 0;	
	asciiVal = (char)chC;
	return asciiVal;
}