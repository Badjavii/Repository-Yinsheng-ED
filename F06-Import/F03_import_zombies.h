#ifndef F03_IMPORT_ZOMBIES_H
#define F03_IMPORT_ZOMBIES_H
#include "../Sources/outools.h"
#include "../Sources/struct.h"

#include <fstream>
#include <vector>
#include <string>
#include <sstream>

/**
 * @brief Lee zombies desde un archivo y los añade a un vector de punteros a zombies.
 *
 * @param types_Zombies Vector de punteros a zombies donde se añadirán los zombies leídos.
 *
 * @return La función no retorna nada.
 */

void import_Zombies(vector<zombie *> &types_Zombies)
{
    string root = "C:/Zombie.zmb";
    ifstream file;
    file.open(root, ios::in);
    string line;

    if (!file.is_open())
    {
        cerr << "Error al abrir el archivo: " << root << endl;
        return;
    }
    else
    {
        cout << "Archivo abierto correctamente: " << root << endl;
    }

    getline(file, line); // Leer la cantidad de tipos de zombies

    int zombie_count = sTOi(line);
    if (zombie_count <= 0)
    {
        cerr << "Cantidad de tipos de zombies no válida: " << zombie_count << endl;
        file.close();
        return;
    }

    while (getline(file, line))
    {
        if (line.empty() || line == "---")
            continue; // Si la línea está vacía o es un separador, pasar a la siguiente

        zombie *new_Zombie = new zombie;

        // Leer y almacenar el tipo del zombie
        new_Zombie->type = line;
        line = "";

        // Leer y almacenar el daño del zombie
        if (!getline(file, line))
            break;
        new_Zombie->damage = sTOi(line);
        line = "";

        // Leer y almacenar la salud del zombie
        if (!getline(file, line))
            break;
        new_Zombie->health = sTOi(line);
        line = "";

        // Inicializar el ID, oponente y puntero siguiente en nulo
        new_Zombie->id = 0;
        new_Zombie->opponent = nullptr;
        new_Zombie->next = nullptr;

        // Añadir el nuevo zombie al vector
        types_Zombies.push_back(new_Zombie);
    }

    file.close();
    return;
}

#endif // F03_IMPORT_ZOMBIES_H