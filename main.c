#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisci le costanti
#define N 3
#define MAX_STRLEN 30

// Definisci il tipo di dato struct s_studente
struct s_studente{
    char nome[MAX_STRLEN];
    char cognome[MAX_STRLEN];
    unsigned int eta;
    unsigned int classe;
    char sezione[MAX_STRLEN];
};

// Definisci studente come struct s_studente
typedef struct s_studente studente;

// Dichiara il prototipo della funzione di ordinamento
void Cognomi(studente vet[],int n);


int main(int argc, char** argv) {
    // Dichiara le variabili locali
    int i;
    studente ciao[N];
    
    // Codice per l'inserimento, da parte dell'utente, dei dati
    for(i=0;i<N;i++)
    {
        printf("inserisci il nome: ");
        scanf("%s", &ciao[i].nome);
        printf("inserisci il cognome: ");
        scanf("%s", &ciao[i].cognome);
        printf("inserisci l'eta': ");
        scanf("%d", &ciao[i].eta);
        printf("inserisci la classe: ");
        scanf("%d", &ciao[i].classe);
        printf("inserisci la sezione: ");
        scanf("%s", &ciao[i].sezione);
    }
    
    // Ordina l'elenco (con funzione)
    Cognomi(ciao,N);
    
    // Codice per la stampa dei dati (uno studente per riga)
    for(i=0;i<N;i++)
    {
      printf("%s; %s; %d; %d; %s\n",ciao[i].nome,ciao[i].cognome,ciao[i].eta,ciao[i].classe,ciao[i].sezione);
    }
    return (EXIT_SUCCESS);
}

// Definisci la funzione di ordinamento
void Cognomi(studente vet[],int n){
    int i,min,k;
    studente scambio;
    
    for(i=0;i<n-1;i++){
        min=i;
        
        for(k=i+1;k<n;k++){
            if(strcmp(vet[k].cognome, vet[min].cognome)<0){
                min=k;
            }
        }
        
        scambio=vet[i];
        vet[i]=vet[min];
        vet[min]=scambio;
    }
}