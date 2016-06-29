/*
Il programma dovrà leggere i caratteri contenuti in un file di testo ed invertire ogni parola letta (es: casa → asac).
I caratteri di punteggiatura non dovranno essere spostati. Tutte le parole cosi invertite dovranno essere scritte su
un altro file di testo.
Il programma dovrà prendere da tastiera il nome del file di input (max 15 caratteri), il nome del file di output
(max 15 caratteri), nel caso in cui i nomi dei file (compreso il “.txt”) superino tale lunghezza dovranno essere
sostituiti con nomi non più lunghi di 15 caratteri.
Dopo aver effettuato l'inversione di tutte le parole del testo, dovrà stampare a video sia il contenuto del file di
input che quello del file di output ottenuto dalla conversione.
Il programma dovrà ciclare fino a quando si inserisce i caratteri s o S ed uscire dal ciclo esclusivamente inserendo
i caratteri n o N. Altri caratteri genereranno un messaggio di errore.
*/
#include <iostream>
#include <fstream>
using namespace std;

int conta_caratteri(char b[]){
int i=0;
while(b[i]!='\0'){
    i++;
}
return i;
}

void leggi_nome_file(char a[]){
    int i=0;
do{
    cin>>a;
    i=conta_caratteri(a);
    if(i>15){
        cout<<"lunghezza del file troppo lunga"<<endl;
        }
}while(i>15);
}

void inverti(char in[], char out[]){
char c;//è il carattere che andrai a leggere dal file di ingresso
char nome[50];//serve per copiarci dentro il carattere senza la punteggiatura
int i=0;//altro contatore
fstream input,output;
input.open(in,ios::in);
output.open(out,ios::out);
while(input.get(c)){//prende dal file di ingresso carattere per carattere
    while(i<50&&(c!='.'&&c!='\n'&&c!=','&&c!=';'&&c!='!'&&c!='?'&&c!='\\'&&c!=':'&&c!='*'&&c!='%'&&c!=' ')){
        nome[i]=c;//il while sopra prende i caratteri solo se non sono punteggiatura o se la i è maggiore di 50
        i++;//il c viene salvato nel vettore nome[i] con l istruzione precedente e viene incrementato il contatore
        input.get(c);//per far uscire dal while serve che avviva a fine parola
    }
    while(i!=0){//scorre il vettore fino che i non è uguale a 0
        i--;//decrementa il contatore
        output<<nome[i];//scrive la parola al contrario nel file
    }
    output<<c;//inserisce nel file il carattere di punteggiatura
    i=0;//azzera il contatore
}
input.close();
output.close();
}

void stampa_file(char nome[]){
char c;
fstream input;
input.open(nome,ios::in);
    while(input.get(c)){
        cout<<c;//stampa il carattere a video
    }
}
int main(){
    char s;
    do{
        char nomefilein[15];
        char nomefileout[15];
        cout<<"inserisci il nome del file di input"<<endl;
        leggi_nome_file(nomefilein);//avvi la funzione passandogli come argomento il vettore del file input
        cout<<"inserisci in nome del file di output"<<endl;
        leggi_nome_file(nomefileout);//identica cosa di sopra
        inverti(nomefilein,nomefileout);
        stampa_file(nomefilein);
        cout<<endl<<endl;
        stampa_file(nomefileout);
        cout<<endl<<endl;
        do{
        cout<<"vuoi continuare [SI/NO]"<<endl;
        cin>>s;
        if(s!='s'&&s!='n'&&s!='S'&&s!='N'){
            cout<<"lettera non consentita"<<endl;
        }
        }while(s!='s'&&s!='n'&&s!='S'&&s!='N');
    }while(s!='n'||s!='N');
    return 0;
}

//Coded by DarkCerfa
