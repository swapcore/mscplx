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
	size_t filesize;
	FILE *fp;

	if(!(fp=_wfopen(filename,L"rb"))) {
		return NULL;
	}

	fseek(fp,0,SEEK_END);
	filesize = ftell(fp);
	rewind(fp);

	if(!(tag=calloc(1,sizeof(ID3V230TAG)+filesize))) {
		fclose(fp);
		return NULL;
	}

	// copiar datos del archivo
	fread(tag->filebuf,1,filesize,fp);

	fclose(fp);

	// copiar datos de cabecera
	tag->id[0]     = tag->filebuf[0];
	tag->id[1]     = tag->filebuf[1];
	tag->id[2]     = tag->filebuf[2];
	tag->ver       = tag->filebuf[3];
	tag->rev       = tag->filebuf[4];
	tag->flags     = tag->filebuf[5];
	tag->tagsize  |= (tag->filebuf[6]&0x7F)<<21;
	tag->tagsize  |= (tag->filebuf[7]&0x7F)<<14;
	tag->tagsize  |= (tag->filebuf[8]&0x7F)<<7;
	tag->tagsize  |= (tag->filebuf[9]&0x7F)<<0;
	tag->filesize  = filesize;

	// verificar identificador
	if(memcmp(tag->id,"ID3",3)) {
		// identificador no valido
		free(tag);
		return NULL;
	}

	// verificar propiedades de etiqueta
	if(tag->ver>4||tag->rev>0||tag->flags>7) {
		free(tag);
		return NULL;
	}

	// verificar tamaño de etiqueta
	if(tag->tagsize&0x80808080) {
		free(tag);
		return NULL;
	}

	tag->filename = wcsdup(filename);

	return tag;
}

// cerrar etiqueta
int ID3V230Close(ID3V230TAG *tag)
{
	if(!tag) return 0;
	free(tag->filename);
	free(tag);
	
	return ID3V230_OK;
}