class Complex
{
    private:
        double re, im;

    public:
        /* construtor sem parâmetros. Cria um complexo nulo */
        Complex();
        /* Cria um complexo com o coeficiente imaginário nulo */
        Complex(double r);
        /* Cria um complexo com coeficientes real e imaginário */
        Complex(double r, double i);

        /* devolve a parte real do complexo */
        double real();
        /* devolve a parte imaginária do complexo */
        double imag();

        /* complexo introduzido pelo utilizador na forma a + ib*/
        void read();

        /* escreve no ecrá o complexo na forma (a + ib) */
        void print();

        /* devolve o conjugado do complexo */
        Complex conjugate();
        /* devolve o módulo do complexo */
        double modulus();
        /* devolve o argumento do complexo, em radianos */
        double arg_rad();
        /* devolve o argumento do complexo, em graus */
        double arg_deg();
        
        /* devolve a soma de 2 complexox */
        Complex operator + (Complex& c);
        /* devolve a diferença de 2 complexos*/
        Complex operator - (Complex& c);
        /* devolve o simétrico do complexo */
        Complex operator-();
        /* devolve o produto de 2 complexos */
        Complex operator * (Complex& c);
        /* devolve o produto de um complexo por um escalar */
        Complex operator* (double k);
        /* devolve a divisão do 2 complexos */
        Complex operator / (Complex& c);
        /* devolve a divisão do complexo por um escalar*/
        Complex operator / (double k);


        /* adiciona ao complexo um outro complexo, devolvendo o resultado */
        Complex operator += (Complex& c);
        /* multiplicação do complexo por outro complexo, devolvendo o resultado */
        Complex operator *= (Complex& c);
};