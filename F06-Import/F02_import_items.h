#ifndef F02_IMPORT_ITEMS_H
#define F02_IMPORT_ITEMS_H

#include "../Sources/outools.h"
#include "../Sources/struct.h"
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

/**
 * @brief Convierte una cadena de caracteres a un entero.
 *
 * @param pepe Cadena de caracteres a convertir.
 *
 * @return int El valor entero convertido. Devuelve -1 si la conversión falla.
 */

int sTOi(const string &pepe)
{
    // Eliminar espacios en blanco al principio y al final
    string trimmed_pepe = pepe;
    trimmed_pepe.erase(trimmed_pepe.begin(), find_if(trimmed_pepe.begin(), trimmed_pepe.end(), [](unsigned char ch)
                                                     { return !isspace(ch); }));
    trimmed_pepe.erase(find_if(trimmed_pepe.rbegin(), trimmed_pepe.rend(), [](unsigned char ch)
                               { return !isspace(ch); })
                           .base(),
                       trimmed_pepe.end());

    // Verificar si la cadena resultante está vacía
    if (trimmed_pepe.empty())
    {
        return -1;
    }

    // Verificar si todos los caracteres son dígitos
    for (char c : trimmed_pepe)
    {
        if (!isdigit(c))
        {
            return -1;
        }
    }
    return stoi(trimmed_pepe);
};

/**
 * @brief Lee ítems desde un archivo y los añade a un vector de punteros a ítems.
 *
 * @param items Vector de punteros a ítems donde se añadirán los ítems leídos.
 *
 * @return La función no retorna nada.
 */

void import_Items(vector<item *> &items)
{
    string root = "C:/Accesorio.zmb";
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

    getline(file, line); // Saltar la primera línea con el número de ítems del archivo

    while (getline(file, line))
    {
        if (line.empty())
            continue; // Si la línea está vacía, pasar a la siguiente

        item *new_Item = new item;

        // 1. Saltar la línea del ID
        if (!getline(file, line))
            break;
        line = "";

        // 2. Leer y almacenar el nombre del ítem
        if (!getline(file, line))
            break;
        new_Item->name = line;
        line = "";

        // 3. Leer y almacenar el tipo del ítem
        if (!getline(file, line))
            break;
        new_Item->type_item = line;
        line = "";

        // 4. Leer y almacenar el valor de efecto del ítem
        if (!getline(file, line))
            break;
        try
        {
            new_Item->effect_value = sTOi(line);
        }
        catch (const invalid_argument &e)
        {
            cerr << "Error de conversión en effect_value: " << e.what() << endl;
            new_Item->effect_value = 0; // Valor por defecto en caso de error
        }
        catch (const out_of_range &e)
        {
            cerr << "Error de rango en effect_value: " << e.what() << endl;
            new_Item->effect_value = 0; // Valor por defecto en caso de error
        }
        line = "";

        // 5. Leer y almacenar el valor de usos del ítem
        if (!getline(file, line))
            break;
        try
        {
            new_Item->usages = sTOi(line);
        }
        catch (const invalid_argument &e)
        {
            cerr << "Error de conversión en usages: " << e.what() << endl;
            new_Item->usages = 0; // Valor por defecto en caso de error
        }
        catch (const out_of_range &e)
        {
            cerr << "Error de rango en usages: " << e.what() << endl;
            new_Item->usages = 0; // Valor por defecto en caso de error
        }
        line = "";

        // 6. Inicializar el puntero siguiente en nulo
        new_Item->next = nullptr;

        // Añadir el nuevo ítem al vector
        items.push_back(new_Item);
    }
    file.close();
    return;
};

#endif // F02_IMPORT_ITEMS_H