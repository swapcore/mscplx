/*
	Tratamiento del titulo de la canción
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

#include "title.h"

// crear titulo
wchar_t * CreateTitle(wchar_t *num, wchar_t *str)
{
	wchar_t *c;
	size_t len1,len2;

	len1 = wcslen(num);
	len2 = wcslen(str);

	if(!(c=calloc(len1+len2+1,sizeof(wchar_t)))) {
		return NULL;
	}

	memcpy(c,num,len1*sizeof(wchar_t));
	memcpy(c+len1,str,len2*sizeof(wchar_t));

	return c;
}