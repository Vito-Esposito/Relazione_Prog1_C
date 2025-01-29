#include "lib.h"

// Funzione che verificherà se la stringa del numero in lettere è presente nella tabella e in inglese.
//    Parametri in INPUT: char numero[], stringa del numero in lettere.
//    Parametri in OUTPUT: ritorna 1 se la stringa rappresenta un numero presente nella tabella
//                         ritorna 0 altrimenti.

int check_num_tab_ing(char numero[]){

    if(strcmp(numero, "FOUR") == 0        || strcmp(numero, "SEVENTEEN") == 0   || strcmp(numero, "TWO") == 0       || strcmp(numero, "SIXTEEN") == 0 || 
	   strcmp(numero, "TWENTYFOUR") == 0  || strcmp(numero, "NINE") == 0        || strcmp(numero, "TWENTY") == 0    || strcmp(numero, "SIX") == 0     || 
	   strcmp(numero, "TWENTYFIVE") == 0  || strcmp(numero, "TWELVE") == 0      || strcmp(numero, "TWENTYTWO") == 0 || strcmp(numero, "SEVEN") == 0   || 
	   strcmp(numero, "ONE") == 0         || strcmp(numero, "TWENTYSEVEN") == 0 || strcmp(numero, "ELEVEN") == 0    || strcmp(numero, "THREE") == 0)
            return 1;

    return 0;
}

// Prendo numero come parola, prendo le singole lettere scorrendo z, confronto z-lettera con tab[i][j].carattere, scorrendo i e j, 
// finchè non trovo che tab[i][j].carattere coincide con la singola lettera, poi tramite la funzione trova_tab(numero[z], tab) cercherò e 
// stamperò la posizione in tabella dove la lettera numero[z] coincide con tab[i][j].carattere, e tramite segno_lett(tab[i][j]) ritornerò il valore della lettera in tabella
// (tab[i][j].valore) e il suo segno dipendentemente da tab[i][j].colore, e infine svolgerò la somma, tramite il ciclo while farò ciò per ogni lettera, e infine stamperò il risultato.
//    Parametri in INPUT: char numero[], stringa del numero in lettere.
//						  lettera_singola tab[][4], la tabella/array bidimensionale di tipo struct lettera_singola.
//    Parametri in OUTPUT: nessuno.

void scandisci_lettere(char numero[], lettera_singola tab[][4]){
	int z=0, i=0, j=0, somma= 0;
	
	while(numero[z] != '\0'){
		
		for(i=0; i<4; i++){
			for(j=0; j<4; j++){
				if(numero[z] == tab[i][j].carattere){
					trova_tab(numero[z], tab);
					somma= somma + segno_lett(tab[i][j]);
				}
			}
		}
		z++;
	}
	
	printf("Risultato finale: %d", somma);	
}
 
// Semplice funzione che stamperà a schermo la tabella (in input) con i rispettivi caratteri, valori e colori, con \033[33mtesto\033[0m che mi formatta il testo di giallo.
//    Parametri in INPUT: lettera_singola tab[][4], la tabella/array bidimensionale di tipo struct lettera_singola.
//    Parametri in OUTPUT: nessuno.

void stampa_tab(lettera_singola tab[][4]){
	int i, j;
	
	printf("Tabella stampata:\n");
	
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			if(tab[i][j].colore == 1)
				printf("[\033[33m%c %d\033[0m]", tab[i][j].carattere, tab[i][j].valore);
			else
				printf("[%c %d]", tab[i][j].carattere, tab[i][j].valore);
		}
		printf("\n");
	}
	printf("\n");
}

// Scorro e stampo la tabella (in input) indicando con "->" la posizione della singola lettera (in input). 
//    Parametri in INPUT: char lettera, un carattere (che sarà numero[z]).
//                        lettera_singola tab[][4], la tabella/array bidimensionale di tipo struct lettera_singola.
//    Parametri in OUTPUT: nessuno.

void trova_tab(char lettera, lettera_singola tab[][4]){
	int i, j, i_t= 0, j_t= 0;
	
	printf("\nLettera trovata:\n");
	
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			if(tab[i][j].colore == 1){
				if(lettera == tab[i][j].carattere){
					printf("[->\033[33m%c %d\033[0m]", tab[i][j].carattere, tab[i][j].valore);
					i_t= i;
					j_t= j;	
				}
				else
					printf("[\033[33m%c %d\033[0m]", tab[i][j].carattere, tab[i][j].valore);	
			}
			else{
				if(lettera == tab[i][j].carattere){
					printf("[->%c %d]", tab[i][j].carattere, tab[i][j].valore);
					i_t= i;
					j_t= j;
				}	
				else
					printf("[%c %d]", tab[i][j].carattere, tab[i][j].valore);
			}
		}
		printf("\n");
	}
	
	printf("\t\t\t\tin posizione riga %d e colonna %d.", i_t+1, j_t+1);
	
	printf("\n");
}

// Funzione che semplicemente associa il segno giusto al valore della lettera in tabella (elem_tab aka tab[i][j]), in base al suo colore.
//    Parametri in INPUT: lettera_singola elem_tab, (che sarà lettera_singola tab[i][j]).
//    Parametri in OUTPUT: -(elem_tab.valore) sse elem_tab.colore == 1
//							 elem_tab.valore sse elem_tab.colore != 1

int segno_lett(lettera_singola elem_tab){
	
	if(elem_tab.colore == 1)
		return -(elem_tab.valore);
	else
		return elem_tab.valore;
}


















