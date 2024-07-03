#ifndef CASA_H
#define CASA_H

#include <iostream>
#include <string>

class Casa {

    private:

        int estadoOcupado;
        std::string conteudo;

    public:

        Casa();
        void setConteudo(std::string);
        std::string getConteudo();

};

#endif