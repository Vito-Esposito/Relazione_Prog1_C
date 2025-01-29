#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

/*
DIZIONARIO
Il programma simulerà la gestione di un dizionario della lingua italiana. 
Con un array indice di 26 elementi di tipo struct dizionario, ogni elemento avrà un campo lettera 
(carattere che rappresenterà la lettera dell'indice) ed un campo parole[30] di tipo struct parola, tale che ogni elemento di indice con una 
lettera specifica avrà la possibilità di immagazzinare 30 parole diverse nell'array parole[30] di tipo struct parola.
Ogni elemento dell'array parole di quella lettera (quindi ogni parola indicizzata) potrà accedere al campo char parola_sinonimi[6][20] 
(un'array bidimensionale dove inserirò la parola principale e 5 sinonimi, di lunghezza massima 20 caratteri) e un campo 
char significato[50] (stringa dove inserirò la spiegazione della parola di lunghezza massima 50 caratteri). 
Sarà possibile tramite due funzioni di inserimento e di ricerca di: -inserire una parola indicizzandola.
																	-ricercare una parola nel dizionario e visualizzare il significato.
E la scelta dell'operazione sarà proposta all'utente e in loop finchè non inserirà "3".
*/


int main() {

	// Indice del dizionario
	dizionario indice[26];
	
	iniz_indice(indice);
	stampa_indice(indice);
	
	operazione(scelta(), indice);
	
	return 0;
}
