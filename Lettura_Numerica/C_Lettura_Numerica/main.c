#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lib.h"

/*
Lettura numerica
Il programma implementerà una simulazione del gioco della lettura numerica. 
Scelto un qualsiasi numero nella Tabella (disponibile nella cartella "Contenuti_multimediali"), 
il programma scandirà il nome in inglese lettera dopo lettera prendendo i numeri corrispondenti alle lettere, 
sottraendo quelli nelle caselle gialle e sommando quelli nelle caselle bianche. 
Il risultato sarà il numero scelto, con il segno negativo o positivo. 

Il programma, dato un numero in lettere e in inglese, permetterà di attraversare la tabella visualizzando/stampando 
le posizioni lettera per lettera e il risultato finale.

Ad esempio, TWENTYTWO risulta: 20-25-4-2+20+11+20-25+7= 22.
*/

// Dichiarazione Tabella 
lettera_singola tab[4][4]={
				    	      {{'E', 4, 1},  {'I', 17, 0}, {'N', 2, 1},  {'S', 16, 0}},
                              {{'L', 24, 0}, {'F', 9, 1},  {'T', 20, 0}, {'R', 6, 1}},
			        	      {{'W', 25, 1}, {'U', 12, 0}, {'G', 22, 1}, {'O', 7, 0}},
	        	         	  {{'V', 1, 0},  {'X', 27, 1}, {'Y', 11, 0}, {'M', 3, 1}}
       					  };

int main(){
	char nome_num[20];
	
	stampa_tab(tab);

    printf("Immettere il nome del numero (presente in tabella e in inglese) che vuoi leggere: ");
    scanf("%s", nome_num);
    strupr(nome_num);

    while(check_num_tab_ing(nome_num) != 1){
        printf("Immettere correttamente il nome del numero, assicurandosi che sia in tabella e sia scritto in inglese: ");
        scanf("%s", nome_num);
        strupr(nome_num);
    }
    
    scandisci_lettere(nome_num, tab);

    return 0;
}
























