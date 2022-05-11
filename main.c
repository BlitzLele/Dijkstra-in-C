//Samuele Sorrentino
//4°INA

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "primo_punto.h"
#include "secondo_punto.h"
#include "terzo_punto.h"

void intestazione();                                                //Funzione che genera una tabella di caratteri ASCII per l'intestazione
void base_5_nodi();                                                     //Funzione per la soluzione default del primo punto del programma
void base_10_nodi();                                                //Funzione per la soluzione default del secondo punto del programma
void base_finale();                                                     //Funzione per la soluzione default del terzo punto del programma
void avanzata_5_nodi();                                             //Funzione per la soluzione avanzata del primo punto del programma
void avanzata_10_nodi();                                                //Funzione per la soluzione avanzata del secondo punto del programma
void dijkstra_finale();                                             //Funzione per la soluzione avanzata del terzo punto del programma    
int dijkstra_5_nodi(int grafo[][N], int partenza, int arrivo);          //Algoritmo Dijkstra per la soluzione del primo punto del programma
int dijkstra_10_nodi(int grafo[][P], int partenza, int arrivo);             //Algoritmo Dijkstra per la soluzione del secondo punto del programma
int dijkstra_base(int grafo[][G], int partenza, int arrivo);            //Algoritmo Dijkstra per la soluzione del terzo punto del programma

int main()
{
    intestazione();                                                 //Richiamo la funzione per l'intestazione
    
    int i;                                                  //Variabile per il ciclo for 
    int fine;                                               //Variabile per la scelta della soluzione
    int scelta;                                                 //Variabile per la scelta della soluzione
    int soluzione;                                          //Variabile per la scelta della soluzione

    //MENU DI SCELTA PER L'UTENTE
    do
    {
        printf("\n");
        printf("\n");
        printf ("Scegli una tra queste operazioni:\n\n");
        printf("1)Algoritmo Dijkstra con Grafo di 5 Nodi Orientato in un solo Verso\n");
        printf("2)Algoritmo Dijkstra con Grafo di 10 Nodi Orientato in un solo Verso\n");
        printf("3)Algoritmo Dijkstra Finale Applicato ad un Grafo Qualsiasi\n");
        printf("4)Istruzioni sul Funzionamento del Programma\n");
        printf("5)Pulizia della schermata di Esecuzione\n");
        printf("0)Fine\n");
        printf("\n");
        printf("\n");
        printf("La tua scelta: \t");
        scanf ("%d",&scelta);
            switch (scelta)
            {
                default:
                        printf("\n--Il Carattere Inserito non e' Accettabile--\n\n");       //In caso l'utente inserisca caratteri non presenti nel menu' il programma stampa un messaggio di errore
                        sleep(3);
                        exit(0);
            case 1:

                printf("\n");
                printf("Scegli il Tipo di Soluzione:\n\n");
                printf(" 1)Soluzione Default Con Nodi gia' Impostati\n 2)Soluzione con Nodi inseriti dall'Utente\n");
                printf("\n");
                printf("\n");
                printf("La tua scelta: \t");
                scanf ("%d",& soluzione);
                switch(soluzione)
                {
                    case 1:

                        printf("\n");
                        base_5_nodi();                          
                        break;

                    case 2:

                        printf("\n");
                        avanzata_5_nodi();
                        break;
                }
                break;

            case 2:

                printf("\n");
                printf("\n");
                printf("Scegli il Tipo di Soluzione:\n\n");
                printf(" 1)Soluzione Default Con Nodi gia' Impostati\n 2)Soluzione con Nodi inseriti dall'Utente\n");
                printf("\n");
                printf("\n");
                printf("La tua scelta: \t");
                scanf ("%d",& soluzione);
                switch(soluzione)
                {
                    case 1:

                        printf("\n");
                        base_10_nodi();
                        break;

                    case 2:

                        printf("\n");
                        avanzata_10_nodi();
                        break;
                }
                break;

            case 3:

                printf("\n");
                printf("\n");
                printf("Scegli il Tipo di Soluzione:\n\n");
                printf(" 1)Soluzione Default Con Nodi gia' Impostati\n 2)Soluzione con Nodi inseriti dall'Utente\n");
                printf("\n");
                printf("\n");
                printf("La tua scelta: \t");
                scanf ("%d",& soluzione);
                switch(soluzione)
                {
                    case 1:

                        printf("\n");
                        base_finale();
                        break;

                    case 2:

                        printf("\n");
                        avanzata_finale();
                        break;
                }
                break;

            case 4:

                    printf("\n");
                    printf("Istruzioni sul Funzionamento Richieste\n");
                    sleep(2);
                    system("spiegazione.txt");
                    break;

            case 5:

                    printf("\n");
                    printf("Pulizia della Schermata di Esecuzione in Corso\n");
                    sleep(2);
                    system("cls");
                    break;

            case 0:

                    printf("\n");
                    printf("Uscita dal Programma in Corso\n");
                    sleep(2);
                    exit(0);
            }
    }
    while(scelta!=0);
}

void intestazione()
{
    printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n" , 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
    printf(" %c                                        %c\n", 179, 179);
    printf(" %c                                        %c\n", 179, 179);
    printf(" %c                                        %c\n", 179, 179);
    printf(" %c\tSORRENTINO SAMUELE 4 INA\t  %c \n", 179, 179);
    printf(" %c    PROGRAMMA APP. DIJKSTRA 2021/2022   %c\n", 179, 179);
    printf(" %c                                        %c\n", 179, 179);
    printf(" %c                                        %c\n", 179, 179);
    printf(" %c                                        %c\n", 179, 179);
    printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n" , 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
}
