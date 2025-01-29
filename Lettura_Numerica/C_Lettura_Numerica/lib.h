// Dichiarazione struct 
typedef struct{
	char carattere;
	int valore;
	int colore;          // 1 se giallo, 0 se bianco
}lettera_singola;

// Dichiarazione delle funzioni
int check_num_tab_ing(char[]);
void scandisci_lettere(char[], lettera_singola[][4]);
void stampa_tab(lettera_singola[][4]);
void trova_tab(char, lettera_singola[][4]);
int segno_lett(lettera_singola);
