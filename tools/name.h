/*
	Nobmre de archivo
	Copyright (c) 2024 Oscar Elías
	
	This file is part of mscplx.
	
	mscplx is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published
	by the Free Software Foundation, either version 3 of the License,
	or (at your option) any later version.
	
	mscplx is distributed in the hope that it will be useful, but
	WITHOUT ANY WARRANTY; without even the implied warranty of 
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
	General Public License for more details.
	
	You should have received a copy of the GNU General Public License
	along with mscplx. If not, see 
	<https://www.gnu.org/licenses/>.
*/

#ifndef _NAME_H_
#define _NAME_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

wchar_t * DecodeName(wchar_t *filename);
wchar_t * EncodeName(wchar_t *filename, wchar_t *ext);

#endif