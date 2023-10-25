#ifndef BIEN_H
#define BIEN_H


class Bien
{
protected:
    char tipo;
    int cod;
    double valor;
public:
    float virtual calcularAmortizacion()=0;
    Bien(int,char,double);
    Bien();
    double getValor() const;
    void setValor(double newValor);
    int getCod() const;
    void setCod(int newCod);
    char getTipo() const;
    void setTipo(char newTipo);
};

#endif // BIEN_H
