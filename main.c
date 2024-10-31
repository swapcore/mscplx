/*
	Enumerador de canciones
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

#include <stdio.h>
#include "format/id3v230/id3v230.h"
#include "tools/track.h"
#include "tools/title.h"

int main(int arv, char ** argc)
{
	int a=0;
	int * buf;
	wchar_t *c,*d;

	buf=GenerateTrackList(143);

	for(a=0; a<143; a++) {
		c=EncodeTrack(buf[a]);
		d=CreateTitle(c,L"Hola");
		wprintf(L"track: %s\n",d);
		free(c);
		free(d);
	}

	free(buf);

	return 0;
}