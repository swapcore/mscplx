/*
	Implementación del formato ID3v2.3.0
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

#include "id3v230.h"

// abrir etiqueta
ID3V230TAG * ID3V230Open(wchar_t * filename)
{
	ID3V230TAG *tag;
	uint32_t tagsize=0;
	size_t filesize;
	uint8_t buf[10];
	FILE *song;

	if(!(song=_wfopen(filename,L"rb"))) {
		return 0;
	}

	// cargar cabecera
	fread(buf,10,1,song);

	// verificar identificador
	if(memcmp(buf,"ID3",3)) {
		// identificador no valido
		fclose(song);
		return NULL;
	}

	// verificar propiedades de etiqueta
	if(buf[3]>4||buf[4]>0||buf[5]>7) {
		fclose(song);
		return NULL;
	}

	// verificar tamaño de etiqueta
	if(*((uint32_t*)(&buf[6]))&0x80808080) {
		fclose(song);
		return NULL;
	}

	// copiar tamaño de etiqueta
	tagsize |= (buf[6]&0x7F)<<21;
	tagsize |= (buf[7]&0x7F)<<14;
	tagsize |= (buf[8]&0x7F)<<7;
	tagsize |= (buf[9]&0x7F)<<0;

	fseek(song,0,SEEK_END);
	filesize = ftell(song);
	rewind(song);

	if(!(tag=malloc(sizeof(ID3V230TAG)+filesize))) {
		fclose(song);
		return NULL;
	}
	
	// recopilar encabezado de etiqueta
	tag->id[0]    = buf[0];
	tag->id[1]    = buf[1];
	tag->id[2]    = buf[2];
	tag->ver      = buf[3];
	tag->rev      = buf[4];
	tag->flags    = buf[5];
	tag->tagsize  = tagsize;
	tag->filesize = filesize;

	// copiar datos del archivo
	fread(tag->filebuf,1,tag->filesize,song);

	fclose(song);

	return tag;
}

// cerrar etiqueta
int ID3V230Close(ID3V230TAG *tag)
{
	if(!tag) return 0;
	free(tag);
	
	return ID3V230_OK;
}