#include <iostream>
#include <string>
#include <fstream>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

// a partir del caracter 56 está el nombre en las líneas
// que inician con "        <span dir=\"ltr\"><span aria-hidden=\"true\"><!---->" 
// y hay 10 por página

main(){
    setlocale(LC_ALL, "spanish");
    ifstream htmlDatos;
    int n = 0, charNamePos = 56, charPuestoPos = 15, charUbiPos = 17, charLinkPos = 57;
    string documento = "(3) Search _ LinkedIn.txt", Nombre = "", htmlLinea, Puesto = "", Ubi = "", Link = "";
    char charName = ' ', charPuesto = ' ', charUbi = ' ', charLink = ' ';

    htmlDatos.open(documento);
    cout << "Nombres: " << endl;
    while(getline(htmlDatos, htmlLinea)){
        if(htmlLinea.substr(0,56) == "        <span dir=\"ltr\"><span aria-hidden=\"true\"><!---->"){
            while(htmlLinea[charNamePos] != '<'){
                charName = htmlLinea[charNamePos];
                Nombre+=charName;
                charNamePos++;
            }
            printf("%s \n", Nombre.c_str());
            Nombre = "";
            charNamePos = 56;
            }
    }
    htmlDatos.close();




    htmlDatos.open(documento);
    cout << endl << endl << "Puestos: " << endl;
    while(getline(htmlDatos, htmlLinea)){
        if(htmlLinea == "      <div class=\"entity-result__primary-subtitle t-14 t-black t-normal\">"){
                getline(htmlDatos, htmlLinea);
                while(htmlLinea[charPuestoPos] != '<'){
                    charPuesto = htmlLinea[charPuestoPos];
                    Puesto+=charPuesto;
                    charPuestoPos++;
                }
                cout << Puesto << endl;
                Puesto = "";
                charPuestoPos = 15;
            }
    }
    htmlDatos.close();




    htmlDatos.open(documento);
    cout << endl << endl << "Ubicación: " << endl;
    while(getline(htmlDatos, htmlLinea)){
        if(htmlLinea == "        <div class=\"entity-result__secondary-subtitle t-14 t-normal\">"){
                getline(htmlDatos, htmlLinea);
                while(htmlLinea[charUbiPos] != '<'){
                    charUbi = htmlLinea[charUbiPos];
                    Ubi+=charUbi;
                    charUbiPos++;
                }
                cout << Ubi << endl;
                Ubi = "";
                charUbiPos = 17;
            }
    }
    htmlDatos.close();



    htmlDatos.open(documento);
    cout << endl << endl << "Link: " << endl;
    while(getline(htmlDatos, htmlLinea)){
        if(htmlLinea.substr(0,56) == "      <a class=\"app-aware-link\" aria-hidden=\"true\" href="){
                while(htmlLinea[charLinkPos] != '"'){
                    charLink = htmlLinea[charLinkPos];
                    Link+=charLink;
                    charLinkPos++;
                }
                cout << Link << endl;
                Link = "";
                charLinkPos = 57;
            }
    }
    htmlDatos.close();
}