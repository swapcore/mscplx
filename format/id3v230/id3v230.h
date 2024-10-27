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

#ifndef _ID3V230_H_
#define _ID3V230_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

// codigos de error

#define ID3V230_OK        0
#define ID3V230_NOVALID   1     // Etiqueta no valida
#define ID3V230_ERRFILE   2     // Error al abrir el archivo
#define ID3V230_ERRMEMORY 3     // Error al reservar memoria

typedef struct TagID3V230 {
	uint8_t id[3];         // Identificador
	uint8_t ver;           // Version
	uint8_t rev;           // Revisión
	uint8_t flags;         // Banderas
	uint32_t tagsize;      // Tamaño de etiqueta
	size_t filesize;       // Tamaño del archivo
	wchar_t * filename;    // Nombre del archivo
	uint8_t filebuf[1];    // Datos del archivo
}ID3V230TAG;

ID3V230TAG * ID3V230Open(wchar_t * filename);
int ID3V230Close(ID3V230TAG *tag);

#endif