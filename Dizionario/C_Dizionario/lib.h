// Dichiarazione struct 
typedef struct{
		char parola_sinonimi[6][20];
		char significato[50];
	}parola;
	
typedef struct{
		char lettera;
		parola parole[30];
	}dizionario;
	
// Dichiarazione delle funzioni
void stampa_indice(dizionario[]);
void iniz_indice(dizionario[]);
int scelta();
void operazione(int, dizionario[]);
void ins_parola(dizionario[]);
void cerca_parola(dizionario[]);
