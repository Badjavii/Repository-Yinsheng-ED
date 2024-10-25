#ifndef DIALOGUES_H
#define DIALOGUES_H
#include <iostream>
#include "outools.h"
using namespace std;

void coutStory()
{
    string *intro = new string;
    
    *intro = ("Londres, 2024.\n\n"
                   "Lo que comenzó como una serie de extraños síntomas en pequeñas comunidades a lo largo y ancho del país, pronto se reveló como una pesadilla global. "
                   "Investigaciones preliminares apuntan a un incidente aéreo en el Canal de la Mancha, donde un cargamento altamente confidencial de patógenos modificados a partir del COVID-19 se habría dispersado en la atmósfera. "
                   "La comunidad internacional se encuentra al borde del pánico, mientras expertos en salud pública y gobiernos intentan contener lo que parece ser una guerra biológica desatada accidentalmente.\n\n"
                   "La Dra. Emily Carter se encontraba en su laboratorio cuando recibió la llamada. Un nuevo virus, mucho más agresivo que cualquier otro conocido, estaba diezmando poblaciones enteras. "
                   "Como viróloga experta, sabía que solo había una explicación: una fuga en uno de los laboratorios secretos que habían estado desarrollando armas biológicas. "
                   "Sin embargo, cuando comenzó a investigar, se encontró con una conspiración mucho más profunda de lo que jamás había imaginado. "
                   "Las grandes potencias habían estado jugando con fuego, y ahora el mundo entero estaba pagando las consecuencias.");

    couttw(RED, *intro, 3);
    delete intro;
}

void printAsciiArt() {
    string *art = new string(R"(
 ____                                __                               
/\  _`\                             /\ \                              
\ \,\L\_\     __   __  __    __     \_\ \    ____      __  __   ____  
 \/_\__ \   /'__`\/\ \/\ \ /'__`\   /'_` \  /',__\    /\ \/\ \ /',__\ 
   /\ \L\ \/\ \L\ \ \ \_\ /\ \L\.\_/\ \L\ \/\__, `\   \ \ \_/ /\__, `\
   \ `\____\ \___, \ \____\ \__/.\_\ \___,_\/\____/    \ \___/\/\____/
    \/_____/\/___/\ \/___/ \/__/\/_/\/__,_ /\/___/      \/__/  \/___/ 
 ________        \ \_\        __                                      
/\_____  \        \/_/       /\ \      __                             
\/____//'/'    ___    ___ ___\ \ \____/\_\     __    ____             
     //'/'    / __`\/' __` __`\ \ '__`\/\ \  /'__`\ /',__\            
    //'/'___ /\ \L\ /\ \/\ \/\ \ \ \L\ \ \ \/\  __//\__, `\           
    /\_______\ \____\ \_\ \_\ \_\ \_,__/\ \_\ \____\/\____/           
    \/_______/\/___/ \/_/\/_/\/_/\/___/  \/_/\/____/\/___/            
                                                                      
                                                                      
)");
    couttw(YELLOW, "Welcome to ...", 25);
    this_thread::sleep_for(chrono::seconds(1));
    coutf(YELLOW, *art);
    delete art;
}

#endif // DIALOGUES_H