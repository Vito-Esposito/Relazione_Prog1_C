#include "lib.h"
#include <stdio.h>

// Stampa indice, stampa il campo .lettera di ogni elemento di dizionario indice[26], quindi indice[i].lettera.
//    Parametri in INPUT: dizionario indice[] (array di 26 elementi di tipo struct dizionario).
//    Parametri in OUTPUT: nessuno.

void stampa_indice(dizionario indice[]){
	int i; 
	
	printf("Indice del dizionario:\n");
	for(i=0; i<26; i++){
		printf("-%c ", indice[i].lettera);
	}
}

// Inizializzazione dell'indice, assegna una lettera dell'alfabeto ad ogni elemento di dizionario indice[26], nel suo campo lettera.
//    Parametri in INPUT: dizionario indice[] (array di 26 elementi di tipo struct dizionario).
//    Parametri in OUTPUT: nessuno.

void iniz_indice(dizionario indice[]){
	int i, j; 
	
	for(i=0; i<26; i++)
		indice[i].lettera= 'A'+i;	
}

// Scelta dell'operazione da effettuare, se verrà immessa una scelta non disponibile, la funzione chiederà con un ciclo while
// di riprovare finchè non riceverà 1, 2 o 3. 
//    Parametri in INPUT: nessuno.
//    Parametri in OUTPUT: int op (ovvero l'operazione scelta dall'utente e inserita tramite tastiera).

int scelta(){
	int op;
	
	printf("\n\nChe operazione vuoi effettuare:\n1) Inserire una parola\n2) Cercare una parola\n3) Spegni\n\n");
	scanf("%d", &op);
	
	while(op != 1 && op != 2 && op != 3){
		printf("RIPROVARE: ");
		scanf("%d", &op);
	}
	
	return op;
}

// Operazione, se op sarà 1, richiamerà la funzione ins_parola(indice), se sarà op sarà 2 richiamerà la funzione cerca_parola(indice), 
// se op nè 1 nè 2 (if non chiede esplicitamente che sia 3, perchè op= 3 sarà forzato dalla funzione scelta() nel caso non si immetta 1 o 2) 
// il programma non richiamerà nessuna funzione e terminerà.
//    Parametri in INPUT: dizionario indice[] (array di 26 elementi di tipo struct dizionario).
//                        int op (ovvero l'output di scelta(), e indicherà l'operazione scelta e immessa dall'utente da tastiera.  
//    Parametri in OUTPUT: nessuno.

void operazione(int op, dizionario indice[]){
	
	if(op == 1)
		ins_parola(indice);
	else if(op == 2)
		cerca_parola(indice);
	else
		return;
}

// Inserimento parola nel dizionario con eventuali sinonimi e significato.
// La funzione chiede all'utente se desidera inserire una parola, e chiederà di riprovare con un ciclo while finchè non viene inserito "si" o "no" dall'utente. 
// Se l'utente dice "si", chiede di inserire la parola, eventuali sinonimi (fino a un massimo di 5, interrompendo con "STOP"), e il significato della parola, dopo aver cercato
// spazio disponibile in indice[26].parole[30] (perchè c'è il massimo di 30 parole esclusi sinonimi per lettera), la parola poi viene posizionata nel primo spazio disponibile della lettera 
// corrispondente nel dizionario, se non c'è spazio disponibile per la lettera, informa l'utente e annulla l'inserimento, in caso è anche possibile non inserire sinonimi non rispondendo con "si".
// Se l'utente dice "no", l'inserimento viene annullato.
// Al termine, richiama la funzione operazione(scelta(), indice) per continuare con un'altra scelta.
//    Parametri in INPUT: dizionario indice[] (array di 26 elementi di tipo struct dizionario).
//    Parametri in OUTPUT: nessuno.

void ins_parola(dizionario indice[]){
	char risposta[2];
	char new_parola[20];
	char spiegazione[50];
	int i, j, k;
	
	printf("Desideri inserire una parola nel dizionario? (si/no): ");
	scanf("%s", risposta);
	strupr(risposta);
	
	while(strcmp(risposta, "SI") != 0 && strcmp(risposta, "NO") != 0){
		printf("RIPROVARE: ");
		scanf("%s", risposta);
		strupr(risposta);
	}
	
	if(strcmp(risposta, "SI") == 0){
		printf("INSERISCI PAROLA:\n");
		scanf("%s", new_parola);
		
		new_parola[0] = toupper(new_parola[0]);
		
		for(i=0; i<26; i++){
			if(new_parola[0] == indice[i].lettera)
				break;
		}
		
		// Cerco un posto disponibile per la parola
        for (j = 0; j < 30; j++) {
            if (indice[i].parole[j].parola_sinonimi[0][0] == '\0') {
                strcpy(indice[i].parole[j].parola_sinonimi[0], new_parola);
                break;
            }
        }

        if (j == 30) {
            printf("Non c'è spazio per inserire altre parole per questa lettera.\n");
            return;
        }
				
		printf("Vuoi inserire sinonimi? ");
		char risp[2];
		scanf("%s", risp);
		strupr(risp);
		
		if(strcmp(risp, "SI") == 0){
			for(k=1; k<6; k++){
				char new_sinonimo[20];
				printf("Sinonimo %d/5 (scrivere STOP per terminare): ",k);
				scanf("%s", new_sinonimo);
				
				if(strcmp(new_sinonimo, "STOP") == 0)
					break;
				else
					strcpy(indice[i].parole[j].parola_sinonimi[k], new_sinonimo);	
			}
			
		}
		else
			printf("Sinonimi non inseriti.\n");
			
		printf("Inserisci significato: ");
		while(getchar() != '\n');
		fgets(spiegazione, sizeof(spiegazione), stdin);
		
		strcpy(indice[i].parole[j].significato, spiegazione);
		
		printf("Inserimento parola concluso.");
	}
	else
		printf("Inserimento parola annullato.");
	
	operazione(scelta(), indice);
}

// Ricerca di una parola nel dizionario con eventuali sinonimi e significato.
// La funzione chiede all'utente se desidera cercare una parola e utilizza un ciclo while per richiedere "si" o "no" finché l'input non è valido.
// Se l'utente dice "si", chiede di inserire la parola da cercare. La parola viene confrontata con le parole presenti in indice[26].parole[30] (dove si possono inserire al massimo 30 parole per lettera).
// Se la parola viene trovata, la funzione stampa la parola, i suoi sinonimi (se presenti, fino a un massimo di 5) e il significato. 
// Se la parola non viene trovata, informa l'utente che non è presente nel dizionario. 
// Se l'utente dice "no", la ricerca viene annullata. 
// Al termine, richiama la funzione operazione(scelta(), indice) per continuare con un'altra scelta.
//    Parametri in INPUT: dizionario indice[] (array di 26 elementi di tipo struct dizionario).
//    Parametri in OUTPUT: nessuno.

void cerca_parola(dizionario indice[]) {
    char risposta[2];
    char parola_da_cercare[20];
    int i, j, k, trovato = 0;

    printf("Desideri cercare una parola nel dizionario? (si/no): ");
    scanf("%s", risposta);
    strupr(risposta);

    while(strcmp(risposta, "SI") != 0 && strcmp(risposta, "NO") != 0){
        printf("RIPROVARE: ");
        scanf("%s", risposta);
        strupr(risposta);
    }

    if(strcmp(risposta, "SI") == 0){
        printf("INSERISCI PAROLA DA CERCARE: ");
        scanf("%s", parola_da_cercare);
        parola_da_cercare[0]= toupper(parola_da_cercare[0]);

        for(i= 0; i < 26; i++){
            if(parola_da_cercare[0] == indice[i].lettera){
                for(j= 0; j < 30; j++) {
                    if(strcmp(parola_da_cercare, indice[i].parole[j].parola_sinonimi[0]) == 0){
                        trovato = 1;
                        printf("Parola trovata: %s\n", parola_da_cercare);

                        printf("Sinonimi:\n");
                        for(k= 1; k<6; k++) {
                            if(indice[i].parole[j].parola_sinonimi[k][0] != '\0'){
                                printf("%s\n", indice[i].parole[j].parola_sinonimi[k]);
                            }
                        }
                        
                        printf("Significato: %s\n", indice[i].parole[j].significato);
                        break;
                    }
                }
                if(trovato) 
					break; 
            }
        }
        if(!trovato) {
            printf("La parola %s non e' presente nel dizionario.\n", parola_da_cercare);
        }

    } else
        printf("Ricerca parola annullata.\n");

    operazione(scelta(), indice);
}

