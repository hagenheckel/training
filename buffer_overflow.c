/* [Kommentar] Das folgende Programm übernimmt ein Argument aus der Kommandozeile. Es werden zwei char Puffer der Länge 10 deklariert und mit den Werten 'eins' und 'zwei' belegt. Danach kopiert man des Kommandozeilen-Argument in den Puffer zwei und betrachtet das Ergebnis */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
	int wert = 10;
	char puffer_eins[10], puffer_zwei[10];
	
	strcpy(puffer_eins, "eins");
	strcpy(puffer_zwei, "zwei");
	
	printf("*VORHER* puffer_zwei liegt bei %p und enthaelt \'%s\'\n", puffer_zwei, puffer_zwei);		
	printf("*VORHER* puffer_eins liegt bei %p und enthaelt \'%s\'\n", puffer_eins, puffer_eins);
	printf("*VORHER* wert liegt bei %p und enthaelt %d (0x%08x)\n", &wert, wert, wert);
	
	printf("\n*KOPIEREN* Kopieren von %d bytes in puffer_zwei\n\n", strlen(argv[1]));
	strcpy(puffer_zwei, argv[1]);
	
	printf("*NACHHER* puffer_zwei liegt bei %p und enthaelt \'%s\'\n", puffer_zwei, puffer_zwei);
	printf("*NACHHER* puffer_eins liegt bei %p und enthaelt \'%s\'\n", puffer_eins, puffer_eins);
	printf("*NACHHER* wert liegt bei %p und enthaelt %d (0x%08x)\n", &wert, wert, wert);
}

/* 
[Compiler] hagen@Pluto:~/C$ gcc -g -o bo buffer_overflow.c
[Aufruf] hagen@Pluto:~/C$ ./bo 123456
   
*VORHER* puffer_zwei liegt bei 0x7ffdbfa5d6fe und enthaelt 'zwei'
*VORHER* puffer_eins liegt bei 0x7ffdbfa5d6f4 und enthaelt 'eins'
*VORHER* wert liegt bei 0x7ffdbfa5d6f0 und enthaelt 10 (0x0000000a)

*KOPIEREN* Kopieren von 6 bytes in puffer_zwei

*NACHHER* puffer_zwei liegt bei 0x7ffdbfa5d6fe und enthaelt '123456'
*NACHHER* puffer_eins liegt bei 0x7ffdbfa5d6f4 und enthaelt 'eins'
*NACHHER* wert liegt bei 0x7ffdbfa5d6f0 und enthaelt 10 (0x0000000a)

[Kommentar] Das Programm wird mit dem Argument 123456 aufgerufen und funktioniert wie gedacht: Das Argument wird in puffer_zwei abgelegt. puffer_eins und wert bleiben unverändert. Man beachte, dass puffer_eins bei .....f4 beginnt, 10 char enthält und deshalb bis .....fd reicht. Direkt im Anschluss beginnt puffer_zwei bei .....fe.

[Aufruf] hagen@Pluto:~/C$ ./bo 123456789ABCD

*VORHER* puffer_zwei liegt bei 0x7ffdd9ae296e und enthaelt 'zwei'
*VORHER* puffer_eins liegt bei 0x7ffdd9ae2964 und enthaelt 'eins'
*VORHER* wert liegt bei 0x7ffdd9ae2960 und enthaelt 10 (0x0000000a)

*KOPIEREN* Kopieren von 13 bytes in puffer_zwei

*NACHHER* puffer_zwei liegt bei 0x7ffdd9ae296e und enthaelt '123456789ABCD'
*NACHHER* puffer_eins liegt bei 0x7ffdd9ae2964 und enthaelt 'eins'
*NACHHER* wert liegt bei 0x7ffdd9ae2960 und enthaelt 10 (0x0000000a)
*** stack smashing detected ***: terminated
Abgebrochen (Speicherabzug geschrieben)

[Kommentar] Ruft man das Programm mit einem Argument auf, das für den Puffer zu gross ist '123456789ABCD', schreibt man über das Ende von puffer_zwei hinaus und provoziert einen Programmabbruch. Trotzdem wird puffer_eins erhalten, obwohl man in dessen Speicherbereich hineinschreibt.
*/ 	

	
