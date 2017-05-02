///////////////////////////////////////////////////////////////////////////////
//
//  EEPROM.h - EEPROM Library for Arduino
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

#ifndef _EEPROM_H_
#define _EEPROM_H_

#include <avr/eeprom.h>

class EEPROMClass
{
	public:
		uint8_t read (uint16_t);
		uint8_t readByte (uint16_t);
		uint16_t readWord (uint16_t);
		uint32_t readDWord (uint16_t);
		uint64_t readQWord (uint16_t);
		float readFloat (uint16_t);
		double readDouble (uint16_t);
		void write (uint16_t, uint8_t);
		void writeByte (uint16_t, uint8_t);
		void writeWord (uint16_t, uint16_t);
		void writeDWord (uint16_t, uint32_t);
		void writeQWord (uint16_t, uint64_t);
		void writeFloat (uint16_t, float);
		void writeDouble (uint16_t, double);
		void update (uint16_t, uint8_t);
		void updateByte (uint16_t, uint8_t);
		void updateWord (uint16_t, uint16_t);
		void updateDWord (uint16_t, uint32_t);
		void updateQWord (uint16_t, uint64_t);
		void updateFloat (uint16_t, float);
		void updateDouble (uint16_t, double);
		uint32_t size (void);
		template <typename T> T eeRead (T *);
		template <typename T> void eeWrite (void *, T);
		template <typename T> void eeUpdate (void *, T);
};

extern EEPROMClass EEPROM; // Preinstantiate EEPROM object

#endif // #ifndef _EEPROM_H_

