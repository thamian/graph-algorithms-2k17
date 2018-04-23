//
// Created by thamian on 10.05.17.
//

#include "Message.h"

const std::string Message::CONSOLE_prompt = ":> ";
const std::string Message::MENU_information =
        "Struktury danych i złożoność obliczeniowa - projekt 2\n"
        "by Damian Korzekwa";
const std::string Message::MENU_description =
        "0 | Lista dostępnych opcji\n"
        "1 | Wczytanie grafu z pliku\n"
        "2 | Wyświetlenie grafu\n"
        "3 | Algorytm Kruskala\n"
        "4 | Algorytm Prima\n"
        "5 | Algorytm Dijkstry\n"
        "6 | Algorytm Bellmana-Forda\n"
        "7 | Wyjście z programu";
const std::string Message::MENU_wrongInput = "ERR: Polecenie nie zostało rozpoznane";
const std::string Message::FILE_getFilename = "Proszę podać nazwę pliku: ";
const std::string Message::FILE_loadSuccess = "Plik został wczytany poprawnie!";
const std::string Message::FILE_loadFailure = "ERR: Plik nie został wczytany";
const std::string Message::GRAPH_created = "Graf został utworzony!";
const std::string Message::GRAPH_notExist = "Graf jest pusty!";
const std::string Message::MATRIX_GRAPH_display = "Graf w postaci macierzy wag:";
const std::string Message::LIST_GRAPH_display = "Graf w postaci list sąsiedztwa:";
