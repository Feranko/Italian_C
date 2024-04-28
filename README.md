Salve e benvenuti al primo linguaggio di programmazioni in italiano,

questo linguaggio è praticamente il linguaggio "C" però con le funzioni principale in italiano, per l'appunto bisogna installare il compilatore gcc.
Principalmente è indirizzato a tutti gli utenti Linux

per installare il compilatore è sufficente:

Ubuntu e Debian
sudo apt-get update -y
sudo apt-get install gcc -y
  
Fedora
sudo dnf update
sudo dnf install gcc

Arch
sudo pacman -Syu
sudo pacman -Sy gcc

Se non si dispone dispone di un sistema linux si può usufruire di 2 strumenti:
-WSL(Windows Subsystem for Linux) https://learn.microsoft.com/en-us/windows/wsl/install <- link per il setup oppure lo si cerca sul Microsoft Store
-Virtual Machine (suggerisco VirtualBOX)

I comandi tradotti sono i seguenti
#includi -> #include
int -> intero
float -> galleggiante
double -> doppia
char -> vocabolo
bool -> booleana
true -> vero
false -> falso
for -> per
while -> finche
do -> fai
return -> ritorna
printf -> stampa
main -> principale

Metto pure un paio di esempi:

  code:
    #includi<stdio.h>
    intero principale(){
      per(intero a = 0; a < 10; a++){
        stampa("%d", a);
      }
    }
    
  output:
    0123456789

L'estensione dei file è .italian
