#include <iostream>

using namespace std;

string wordParser(char input) {
	switch (input) {
	case 'a': return "000";
	case 'b': return "001";
	case 'c': return "002";
	case 'd': return "003";
	case 'e': return "010";
	case 'f': return "011";
	case 'g': return "012";
	case 'h': return "013";
	case 'i': return "020";
	case 'j': return "021";
	case 'k': return "022";
	case 'l': return "023";
	case 'm': return "030";
	case 'n': return "031";
	case 'o': return "032";
	case 'p': return "033";
	case 'q': return "100";
	case 'r': return "101";
	case 's': return "102";
	case 't': return "103";
	case 'u': return "110";
	case 'v': return "111";
	case 'w': return "112";
	case 'x': return "113";
	case 'y': return "120";
	case 'z': return "121";

	case 'A': return "122";
	case 'B': return "123";
	case 'C': return "130";
	case 'D': return "131";
	case 'E': return "132";
	case 'F': return "133";
	case 'G': return "200";
	case 'H': return "201";
	case 'I': return "202";
	case 'J': return "203";
	case 'K': return "210";
	case 'L': return "211";
	case 'M': return "212";
	case 'N': return "213";
	case 'O': return "220";
	case 'P': return "221";
	case 'Q': return "222";
	case 'R': return "223";
	case 'S': return "230";
	case 'T': return "231";
	case 'U': return "232";
	case 'V': return "233";
	case 'W': return "300";
	case 'X': return "301";
	case 'Y': return "302";
	case 'Z': return "303";

	case '0': return "310";
	case '1': return "311";
	case '2': return "312";
	case '3': return "313";
	case '4': return "320";
	case '5': return "321";
	case '6': return "322";
	case '7': return "323";
	case '8': return "330";
	case '9': return "331";


	case ' ': return "332";
	case '!': return "333";

	default: return "999";
	}
}