#ifndef PONTO_HPP
#define PONTO_HPP

class Ponto {

    protected:

        int x;
        int y;

    public:

        Ponto();
        Ponto(int, int);

        int getX();
        int getY();

        void setX(int);
        void setY(int);
};

#endif
