#ifndef DIALOGUES_H
#define DIALOGUES_H
#include <iostream>
#include "outools.h"
using namespace std;

void coutStory()
{
    string intro = "Londres, 2024.\n\n"
                   "Lo que comenzó como una serie de extraños síntomas en pequeñas comunidades a lo largo y ancho del país, pronto se reveló como una pesadilla global. "
                   "Investigaciones preliminares apuntan a un incidente aéreo en el Canal de la Mancha, donde un cargamento altamente confidencial de patógenos modificados a partir del COVID-19 se habría dispersado en la atmósfera. "
                   "La comunidad internacional se encuentra al borde del pánico, mientras expertos en salud pública y gobiernos intentan contener lo que parece ser una guerra biológica desatada accidentalmente.\n\n"
                   "La Dra. Emily Carter se encontraba en su laboratorio cuando recibió la llamada. Un nuevo virus, mucho más agresivo que cualquier otro conocido, estaba diezmando poblaciones enteras. "
                   "Como viróloga experta, sabía que solo había una explicación: una fuga en uno de los laboratorios secretos que habían estado desarrollando armas biológicas. "
                   "Sin embargo, cuando comenzó a investigar, se encontró con una conspiración mucho más profunda de lo que jamás había imaginado. "
                   "Las grandes potencias habían estado jugando con fuego, y ahora el mundo entero estaba pagando las consecuencias.";

    couttw(RED, intro, 3);
}

#endif // DIALOGUES_H