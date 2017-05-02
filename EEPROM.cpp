///////////////////////////////////////////////////////////////////////////////
//
//  EEPROM.cpp// update a float (32 bits) - EEPROM Library for Arduino
//  Copyright (c) 2012, 2017 Roger A. Krupski <rakrupski@verizon.net>
//
//  Last update: 02 May 2017
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program. If not, see <http://www.gnu.org/licenses/>.
//
///////////////////////////////////////////////////////////////////////////////

#include "EEPROM.h"

// eeprom read a byte
uint8_t EEPROMClass::read (uint16_t addr)
{
	return eeRead ((uint8_t *)(addr));
}

// eeprom read a byte
uint8_t EEPROMClass::readByte (uint16_t addr)
{
	return eeRead ((uint8_t *)(addr));
}

// eeprom read a word (16 bits)
uint16_t EEPROMClass::readWord (uint16_t addr)
{
	return eeRead ((uint16_t *)(addr));
}

// eeprom read a dword (32 bits)
uint32_t EEPROMClass::readDWord (uint16_t addr)
{
	return eeRead ((uint32_t *)(addr));
}

// eeprom read a quad word (64 bits)
uint64_t EEPROMClass::readQWord (uint16_t addr)
{
	return eeRead ((uint64_t *)(addr));
}

// eeprom read a float (32 bits)
float EEPROMClass::readFloat (uint16_t addr)
{
	return eeRead ((float *)(addr));
}

// eeprom read a double (32 bits)
double EEPROMClass::readDouble (uint16_t addr)
{
	return eeRead ((double *)(addr));
}

// eeprom write a byte
void EEPROMClass::write (uint16_t addr, uint8_t value)
{
	eeWrite ((void *)(addr), value);
}

// eeprom write a byte
void EEPROMClass::writeByte (uint16_t addr, uint8_t value)
{
	eeWrite ((void *)(addr), value);
}

// eeprom write a word (16 bits)
void EEPROMClass::writeWord (uint16_t addr, uint16_t value)
{
	eeWrite ((void *)(addr), value);
}

// eeprom write a dword (32 bits)
void EEPROMClass::writeDWord (uint16_t addr, uint32_t value)
{
	eeWrite ((void *)(addr), value);
}

// eeprom write a quad word (64 bits)
void EEPROMClass::writeQWord (uint16_t addr, uint64_t value)
{
	eeWrite ((void *)(addr), value);
}

// eeprom write a float (32 bits)
void EEPROMClass::writeFloat (uint16_t addr, float value)
{
	eeWrite ((void *)(addr), value);
}

// eeprom write a double (32 bits)
void EEPROMClass::writeDouble (uint16_t addr, double value)
{
	eeWrite ((void *)(addr), value);
}

// update a byte
void EEPROMClass::update (uint16_t addr, uint8_t value)
{
	eeUpdate ((void *)(addr), value);
}

// update a byte
void EEPROMClass::updateByte (uint16_t addr, uint8_t value)
{
	eeUpdate ((void *)(addr), value);
}

// update a word (16 bits)
void EEPROMClass::updateWord (uint16_t addr, uint16_t value)
{
	eeUpdate ((void *)(addr), value);
}

// update a dword (32 bits)
void EEPROMClass::updateDWord (uint16_t addr, uint32_t value)
{
	eeUpdate ((void *)(addr), value);
}

// update a quad word (64 bits)
void EEPROMClass::updateQWord (uint16_t addr, uint64_t value)
{
	eeUpdate ((void *)(addr), value);
}

// update a float (32 bits)
void EEPROMClass::updateFloat (uint16_t addr, float value)
{
	eeUpdate ((void *)(addr), value);
}

// update a double (32 bits)
void EEPROMClass::updateDouble (uint16_t addr, double value)
{
	eeUpdate ((void *)(addr), value);
}

// return size of eeprom in bytes
uint32_t EEPROMClass::size (void)
{
	uint32_t ee_size;
	ee_size = (E2END + 1);
	return ee_size;
}

// universal eeprom READ
template <typename T> T EEPROMClass::eeRead (T *__address)
{
	T __value;
	uint8_t x = sizeof (__value);
	uint8_t *ptr = (uint8_t *)(&__value);

	while (x--) {
		*(ptr + x) = (eeprom_read_byte ((uint8_t *)(__address) + x));
	}

	return __value;
}

// universal eeprom WRITE
template <typename T> void EEPROMClass::eeWrite (void *__address, T __value)
{
	uint8_t x = sizeof (__value);
	uint8_t *ptr = (uint8_t *)(&__value);

	while (x--) {
		if (eeprom_read_byte ((const uint8_t *)(__address) + x) != *(ptr + x)) {
			eeprom_write_byte (((uint8_t *)(__address) + x), *(ptr + x));
		}
	}
}

// universal eeprom UPDATE
template <typename T> void EEPROMClass::eeUpdate (void *__address, T __value)
{
	uint8_t x = sizeof (__value);
	uint8_t *ptr = (uint8_t *)(&__value);

	while (x--) {
		eeprom_update_byte (((uint8_t *)(__address) + x), *(ptr + x));
	}
}

EEPROMClass EEPROM; // Preinstantiate EEPROM object

// end of EEPROM.cpp
