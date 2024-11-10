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

// crear prefijo de pista
wchar_t * CreateTrackPrefix(int num)
{
	wchar_t *c;
	wchar_t temp[6];

	if(num>LIMIT_TRACKS) {
		return NULL;
	}

	if(c=calloc(6,sizeof(wchar_t))) {
		_itow(num,temp,10);

		if(num<=9) {
			c[0] = L'0';
			c[1] = L'0';
			c[2] = temp[0];
			c[3] = L'.';
			c[4] = L' ';
		}
		else if(num<=99) {
			c[0] = L'0';
			c[1] = temp[0];
			c[2] = temp[1];
			c[3] = L'.';
			c[4] = L' ';
		}
		else {
			c[0] = temp[0];
			c[1] = temp[1];
			c[2] = temp[2];
			c[3] = L'.';
			c[4] = L' ';
		}
	}

	return c;
}

// Actualizar prefijo de pista
int UpdateTrackPrefix(wchar_t *str, int num)
{
	wchar_t *prefix;

	prefix=CreateTrackPrefix(num);

	// cambiando pista
	str[0] = prefix[0];
	str[1] = prefix[1];
	str[2] = prefix[2];
	str[3] = prefix[3];

	free(prefix);

	return 1;
}