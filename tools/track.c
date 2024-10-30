/*
	Generador de numeros de pista
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

#include "track.h"

// Generar numeros de pista
int * GenerateTrackList(int tracks)
{
	int * tracklist;
	int a=0,b=0;

	if(LIMIT_TRACKS<tracks) {
		return NULL;
	}

	if((tracklist=calloc(tracks,sizeof(int)))) {
		// gererar lista de pistas
		srand(time(NULL));
		while(++a<=tracks) {
			do {
				b = rand()%tracks;
			} while(tracklist[b]);
			tracklist[b] = a;
		}
	}

	return tracklist;
}

// codificar numero de pista
wchar_t * EncodeTrack(int num)
{
	wchar_t *c;
	wchar_t temp[4];
	int a=4;

	if(c=calloc(4,sizeof(wchar_t))) {
		_itow(num,temp,10);

		if(num<=9) {
			c[0] = L'0';
			c[1] = L'0';
			c[2] = temp[0];
		}
		else if(num<=99) {
			c[0] = L'0';
			c[1] = temp[0];
			c[2] = temp[1];
		}
		else {
			c[0] = temp[0];
			c[1] = temp[1];
			c[2] = temp[2];
		}
	}

	return c;
}