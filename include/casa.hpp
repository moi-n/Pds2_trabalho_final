#ifndef CASA_H
#define CASA_H

#include <iostream>
#include <string>

class Casa {

    private:

        int estado;
        std::string conteudo;

    public:

        Casa();
        //estado
        int getEstado();
        void setEstado(int);
        //conteudo
        std::string getConteudo();
        void setConteudo(std::string);

};

#endif