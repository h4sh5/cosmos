/**
 * 
 * base uwu encoding
 * 
 * 0 - u
 * 1 - U
 * 2 - w
 * 3 - W
 * 
 * ignore - . ?
 *  
 **/

/**
 * takes a char and uwu encode it
 * 
 **/
void uwu_encode(char c, char* outbuf) {
	outbuf[0] = (c & 0b11000000) >> 6 ;
	outbuf[1] = (c & 0b00110000) >> 4;
	outbuf[2] = (c & 0b00001100) >> 2;
	outbuf[3] = c & 0b00000011;

	for (int i = 0; i < 4; ++i)
	{
		// printf("%d\n", outbuf[i]);
		if (outbuf[i] == 0) {
			outbuf[i] = 'u';
		} else if (outbuf[i] == 1) {
			outbuf[i] = 'U';
		} else if (outbuf[i] == 2) {
			outbuf[i] = 'w';
		} else if (outbuf[i] == 3) {
			outbuf[i] = 'W';
		}
	}

}

char uwu_decode(char *inbuf) { //inbuf must be len 4

	char out = 0;

	for (int i = 0; i < 4; ++i)
	{
		if (inbuf[i] == 'u') {
			inbuf[i] = 0;
		} else if (inbuf[i] == 'U') {
			inbuf[i] = 1;
		} else if (inbuf[i] == 'w') {
			inbuf[i] = 2;
		} else if (inbuf[i] == 'W') {
			inbuf[i] = 3;
		}
		// else if (inbuf[i] == '=') {
		// 	inbuf[i] = 0
		// }
	}
	// printf("%x %x %x %x\n", inbuf[0], inbuf[1], inbuf[2], inbuf[3]);
	out = (inbuf[0] << 6) | (inbuf[1] << 4) | (inbuf[2] << 2) | inbuf[3];

	return out;

		
}

int main(int argc, char** argv) {
	int decode = 0; // decode
	int c;
 	while ((c = getopt (argc, argv, "d")) != -1) {
	  	if (c == 'd') {
	  		decode = 1;
	  	}
  	}

  	

  	if (!decode) {
  		// read and write loop, one char at a time, until EOF
	  	char inbuf[1] = {0,};
	  	char outbuf[4] = {0,}; // each char would be four out chars

  		while (1) {
	  		if (!read(0, inbuf, 1)) {
	  			break; // when read returns 0, its EOF so bye
	  		}
	  		uwu_encode(*inbuf, outbuf);
	  		write(1, outbuf, 4);
  		}
	  	write(1, "\n", 1);
   } else {
	  	char inbuf[4] = {0,};
	  	char outbuf[1] = {0,};
	  	int retn = 0;
    	while(1) {

    		retn = read(0, inbuf, 4);

    		if (retn == 0 || retn < 4) {
	  			break; // when read returns 0, its EOF so bye
    		}
	  		
	  		// printf("decode inbuf:%s\n", inbuf);
	  		outbuf[0] = uwu_decode(inbuf);
	  		write(1, outbuf, 1);
  		}
  		// write(1, "\n", 1);
    }
}
  	



