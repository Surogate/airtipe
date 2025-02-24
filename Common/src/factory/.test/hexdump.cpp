/*!
 * \file	hexdump.cpp
 * \brief	
 * \author	Alexis Lucazeau - lucaze_b@epitech.eu
 * \version	0.1
 * \date	07/08/2010 10:42:56 AM
 *
 * more description...
 */


#include <cstdio>
#include <cstring>
#include <ctype.h>

void hex_dump(void *data, int size)
{
	/*  dumps size bytes of *data to stdout. Looks like:
	 *       [0000] 75 6E 6B 6E 6F 77 6E 20
	 *              30 FF 00 00 00 00 39 00 unknown 0.....9.
	 *       (in a single line of course)
	 */

	unsigned char *p = (unsigned char *) data;
	unsigned char c;
	int n;
	char bytestr[4] = {0};
	char addrstr[10] = {0};
	char hexstr[ 16*3 + 5] = {0};
	char charstr[16*1 + 5] = {0};
	for(n=1;n<=size;n++) {
		if (n%16 == 1) {
			/*  store address for this line */
			snprintf(addrstr, sizeof(addrstr), "%.4x",
					((unsigned int)p-(unsigned int)data) );
		}

		c = *p;
		if (isalnum(c) == 0) {
			c = '.';
		}

		/*  store hex str (for left side) */
		snprintf(bytestr, sizeof(bytestr), "%02X ", *p);
		strncat(hexstr, bytestr, sizeof(hexstr)-strlen(hexstr)-1);

		/*  store char str (for right side) */
		snprintf(bytestr, sizeof(bytestr), "%c", c);
		strncat(charstr, bytestr, sizeof(charstr)-strlen(charstr)-1);

		if(n%16 == 0) { 
			/*  line completed */
			printf("[%4.4s]   %-50.50s  %s\n", addrstr, hexstr, charstr);
			hexstr[0] = 0;
			charstr[0] = 0;
		} else if(n%8 == 0) {
			/*  half line: add whitespaces */
			strncat(hexstr, "  ", sizeof(hexstr)-strlen(hexstr)-1);
			strncat(charstr, " ", sizeof(charstr)-strlen(charstr)-1);
		}
		p++; /*  next byte */
	}

	if (strlen(hexstr) > 0) {
		/*  print rest of buffer if not empty */
		printf("[%4.4s]   %-50.50s  %s\n", addrstr, hexstr, charstr);
	}
}

