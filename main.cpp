/*
28 de agosto de 2024
Vanessa Reteguín - 375533

Actividad 5 - Práctica de Estados y Transiciones: Ejercicio 1

Universidad Aútonoma de Aguascalientes
Ingeniería en Computación Inteligente (ICI)
Semestre V

Grupo 5 - A
Autómatas I
Ángel Eduardo Villegas Ortíz

Instrucciones:

Ejercicio 1:

En una productora Aguacatera se establece que:

Existen dos calidades de aguacate, Premium y Estándar.
El aguacate premium puede tener un peso alto y un peso bajo, los Aguacates
estándar con peso bajo se clasifican en la misma categoría que los Premium. Por
último, los Aguacates estándar que no obtienen el peso bajo se descartan.

Requerimientos:
-Genere un mecanismo para contener la expresión en el lenguaje de programación
seleccionado para que el usuario ingrese el estado y la transición: . -Ofrezca
en consola su nomenclatura de Estados y Transiciones:

Por ejemplo:
Estado Inicial: q0
Posibles señales de Entrada:
X: Premium, Y: Estándar,
a=Peso Alto
b=Peso Bajo,c=Descartes.
Estados Posibles: q0, q1, q2, q3, q4, q5

-Implemente una función Transicion que reciba como parámetro del usuario el
Estado Actual (qn) y un valor de entrada (a) y retorne el estado que se adecúa a
la lógica del ejercicio. -Implemente una función ReporteEstado que reciba como
parámetro un Estado (qn) obtenido de la función Transicion. Indique en consola
la clasificación del tomate como Premium o Estándar y Peso Alto, Peso Bajo o
Descarte en función del estado recibido. -En la función main muestre la
transición solicitada por el usuario en la notación más parecida posible y
despliegue el estado resultado, así como su clasificación.
*/

/* ------------ Resources / Documentation involved ------------- */

/* ------------------------- Libraries ------------------------- */
#include <iostream> /* cin/cout */

using namespace std;

/* ------------------------- Functions ------------------------- */
void displayAguacate() {
    cout
        << endl
        << "\n      ⡀        ⠤       "
           "\n     ⠈⠁⢀⡠⠒⠈⠉⠐⠢⣄⡀      "
           "\n      ⢠⠋      ⠈⢿⢆      "
           "\n   ⠄ ⢀⠃        ⠘⡈⢇        ___                          __        "
           "       ____ ___  ___  ___ "
           "\n     ⡌          ⡇⡌⡄ ⠈⠁   / _ |___ ___ _____ ________ _/ /____ "
           "_______  |_  // _ \\/ _ \\/ _ \\"
           "\n    ⡐    ⡀ ⡀    ⢿⣥⡇     / __ / _ `/ // / _ `/ __/ _ `/ __/ -_) "
           "__/ _ \\_/_ </ // / // / // /"
           "\n⣀⡀ ⡰   ⡰⠊  ⢈⠢⡀  ⠘⣏⣿⡀   /_/ |_\\_, "
           "/\\_,_/\\_,_/\\__/\\_,_/\\__/\\__/_/  \\___/____/\\___/\\___/\\___/"
           "\n⠈⠁⡠⠅⡄ ⡜⠸⠶⣶⠆⠾ ⢰⡀ ⡠⢸⣿⡇ ⢠⡀     /___/                                "
           "                     "
           "\n ⢌⠠⡖⠁ ⡇      ⣬⠇ ⠱⢀⠙⡇   "
           "\n   ⠱⡀ ⠱⣗⢲⠤⠶⣶⣘⠟  ⢀⣾⣿⠇  "
           "\n ⢀⣤ ⠈⠢⣀ ⠉⠉⠉⠉⠁ ⢀⣠⣾⡿⠋   "
           "\n  ⠁   ⠸⡉⡒⠂ ⠴⡖⢸⠛⠋⠁ ⠠⠦  "
           "\n       ⠉⠁   ⠘⠊         ";
}

void diplayMenu() {
    cout << endl
         << "\n.---------------------."
            "\n||    -{ MENU }-     ||"
            "\n.---------------------."
            "\n| [1] Clasificación   |"
            "\n|     de aguacates 🥑 |"
            "\n|           [2] Salir |"
            "\n.---------------------.\n";
}

void endTitle() {
    cout << "\n  ^~^  , * ------------- *"
            "\n ('Y') ) |  Hasta luego! | "
            "\n /   \\/  * ------------- *"
            "\n(\\|||/)        FIN      \n";
}

void diplayState() {
    cout << endl
         << "\n.------------------."
            "\n||  -[ Estado ]-  ||"
            "\n.------------------."
            "\n|      [0] q0      |"
            "\n|      [1] q1      |"
            "\n|      [2] q2      |"
            "\n|      [3] q3      |"
            "\n|      [4] q4      |"
            "\n|      [5] q5      |"
            "\n.------------------.\n";
}

void diplayClassification() {
    cout << endl
         << "\n.-------------------------."
            "\n||  -[ Clasificación ]-  ||"
            "\n.-------------------------."
            "\n|   [1] ★★★★★ Premium    |"
            "\n|   [2] ★★★☆☆ Estándar   |"
            "\n.------------------------.\n";
}

void diplayQualityDiscard() {
    cout << endl
         << "\n.-------------------."
            "\n||  -[ Calidad ]-  ||"
            "\n.-------------------."
            "\n| [2] Peso Bajo     |"
            "\n| [3] Descarte      |"
            "\n.-------------------.\n";
}

void diplayQualityWeights() {
    cout << endl
         << "\n.-------------------."
            "\n||  -[ Calidad ]-  ||"
            "\n.-------------------."
            "\n| [1] Peso Alto     |"
            "\n| [2] Peso Bajo     |"
            "\n.-------------------.\n";
}

void getAvocado() {
    int classification, quality, state, initialState;

    cout << endl << "Ingrese estado inicial: ";
    diplayState();
    while (!((cin >> state) && (state >= 0 && state <= 5))) {
        cin.clear();
        cin.ignore();
    }

    initialState = state;

    switch (state) {
        case 0: {
            cout << endl << "Ingrese la clasificación del aguacate: ";
            diplayClassification();
            while (!((cin >> classification) &&
                     (classification >= 1 && classification <= 3))) {
                cin.clear();
                cin.ignore();
            }

            switch (classification) {
                case 1:
                    state = 1;
                    break;

                case 2:
                    state = 2;
                    break;

                default:
                    cout << endl
                         << "[!] Error: calidad inválida para trancisión"
                         << endl;
                    break;
            }
        } break;

        case 1: {
            cout << endl << "Ingrese la calidad del aguacate: ";
            diplayQualityWeights();
            while (!((cin >> quality) && (quality >= 1 && quality <= 2))) {
                cin.clear();
                cin.ignore();
            }

            switch (quality) {
                case 1:
                    state = 3;
                    break;

                case 2:
                    state = 4;
                    break;

                default:
                    break;
            }
        } break;

        case 2: {
            cout << endl << "Ingrese la calidad del aguacate: ";
            diplayQualityDiscard();
            while (!((cin >> quality) && (quality >= 2 && quality <= 3))) {
                cin.clear();
                cin.ignore();
            }

            switch (quality) {
                case 2:
                    state = 4;
                    break;

                case 3:
                    state = 5;
                    break;

                default:
                    break;
            }
            break;
        }

        case 3: {
            cout << endl << "Ingrese la calidad del aguacate: ";
            diplayQualityWeights();
            while (!((cin >> quality) && (quality >= 2 && quality <= 2))) {
                cin.clear();
                cin.ignore();
            }

            switch (quality) {
                case 2:
                    state = 4;
                    break;

                default:
                    cout << endl
                         << "[!] Error: calidad inválida para trancisión"
                         << endl;
                    break;
            }
        } break;

        case 4: {
            cout << endl << "Ingrese la calidad del aguacate: ";
            diplayQualityDiscard();
            while (!((cin >> quality) && (quality >= 3 && quality <= 3))) {
                cin.clear();
                cin.ignore();
            }

            switch (quality) {
                case 3:
                    state = 5;
                    break;

                default:
                    cout << endl
                         << "[!] Error: calidad inválida para trancisión"
                         << endl;
                    break;
            }
        } break;

        case 5: {
            cout << endl << "Ingrese la calidad del aguacate: ";
            diplayQualityWeights();
            while (!((cin >> quality) && (quality >= 2 && quality <= 2))) {
                cin.clear();
                cin.ignore();
            }

            switch (quality) {
                case 2:
                    state = 4;
                    break;

                default:
                    cout << endl
                         << "[!] Error: calidad inválida para trancisión"
                         << endl;
                    break;
            }
        } break;

        default:
            cout << endl
                 << "[!] Error: uno o más estados ingresados son inválidos"
                 << endl;
            break;
    }

    cout << endl << "Estado Resultado: q" << state;
    cout << endl << "Reporte Estado: ";

    if (state == 5) {
        cout << "): Descarte" << endl;
    } else if (classification == 1) {
        cout << "★★★★★ Premium" << endl;
    } else if (classification == 2) {
        cout << "★★★☆☆ Estándar" << endl;
    }

    cout << "δ(q" << initialState << ", " << classification << ") = q" << state
         << ": Aguacate ";

    if (state == 5) {
        cout << "): Descarte" << endl;
    } else if (classification == 1) {
        cout << "Premium" << endl;
    } else if (classification == 2) {
        cout << "Estándar" << endl;
    }
}

int main() {
    /* ------------------------- Variables ------------------------- */
    /* - Menu - */
    int userChoice;
    bool run = true;

    /* --------------------------- Code ---------------------------- */
    while (run == true) {
        displayAguacate();
        diplayMenu();
        while (!((cin >> userChoice) && (userChoice >= 1 && userChoice <= 2))) {
            cin.clear();
            cin.ignore();
        }

        switch (userChoice) {
            case 1:
                getAvocado();
                break;

            case 2:
                endTitle();
                run = false;
                break;
        }
    }

    return 0;
}