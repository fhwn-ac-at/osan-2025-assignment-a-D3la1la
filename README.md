[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/H1vNwaly)
# Protokoll 
*Hello_World!



Protokoll von B&NW von 10.04.2025
Protokoll 3
Thema: Systemprogrammierung
Name: Delaila Dedic - 211014

#Gelernte Befehle/Anwendungen im Unterricht:
Das es das man(manual) in Ubuntu gibt und wie man es öffnet bzw. bedient. 
Befehle wie pid_t, mq_[jegliche Unterbefehle], mq_t, EXIT_SUCCESSFUL, getopt ect. erstes Mal gesehen und kennengelernt. 
bool Befehle erstes Mal auch in Anwendungen gesehen, kannte man vom Namen her bei anderen LVs aber schon etwas
Viele neue Header kennengelernt (unistd.h, fcntl.h, mqueue.h, sys/wait.h, sys/types.h,...)

Generell etwas mehr zur Visual Studio Codierung (Shortcuts, ect.) gelernt. 
Und vieles weiteres das in der Coding Geschwindigkeit im Unterricht_Code_Parts.c File zum Teil vorhanden ist.



#Aufgabe Ventilator und Worker Dateien
ventilator.c ist die C File die als Hauptcode mit der int main() Funktion sich jene Befehle von worker.c holt und bearbeitet.
	worker.c währendessen behandelt wie der Name schon sagt das Aufteilen der "Arbeiter" an Aufgaben 
	bzw. die genauen Auführungen werden dann in der Command Line mit 
	zum Beispiel (wenn alles am Ende wirklich funktioniert) mit "$ ./ventilator -w 4 -t 10 -s 2" ausgeführt. 
																	w=Arbeiter, t=Aufgabenanzahl, s=Bearbeitungsdauer/Aufwand/...

Generell hat man den Code am Anfang unabhängig bzw. in 1 C File gehabt um überhaupt zu compilen
ohne out und executable zu erstellen um beide gleichzeitig auszuführen.


Sonst lässt sich noch kurz sagen das man einiges an neuen Befehlen/Headern/Arbeitsweisen/... anwenden/probieren/versuchen konnte.
Die Aufgabe auch im Vergleich zu vorherigen Aufgaben eine viel komplexere/verschachtelte/aufwändigere war.		

#Zusätzlich genutzte Informationen um Aufgabenstellung zu bewältigen:

Vorher noch nie mit Makefile gearbeitet in irgendeiner Hinsicht. Alles was mit Makefile zu tun hatte war neu. Daher 
kann es nach vielen Versuchen und dem zusätzlichen Einschalten von ChatGPT für den Code 
trotzdem noch sein das es nicht richtig compiliert bzw. bei Files miteinander vollständig arbeiten.
 
Generell auch KI für genauere Erläuterungen und bessere Code Struktur/Header file Aufteillung aber auch bei den 
mq, ect. Befehlen/Korrekturen/Umschreiben gefragt. Sowie die Header files generell auch mit man und/oder mit KI versucht zu verstehen und zu unterscheiden. 








 





















