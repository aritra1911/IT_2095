/*
 * 4. Write appropriate number of programs to implement the 3 types of access specifiers in multilevel inheritance while inheriting from base class.
 */

#include <iostream>

/* ---- Private Multilevel Inheritance ---- */
class APrivate {
    protected:
    int x;
};

class BPrivate : APrivate {
    protected:
    int y;
};

class CPrivate : BPrivate {
    protected:
    int z;

    public:
    CPrivate(int a, int b, int c) {
        //x = a;  // <-- error
        y = b;
        z = c;
    }

    void display(void) {
        //std::cout << "x : " << x << std::endl;  // <-- error
        std::cout << "y : " << y << std::endl;
        std::cout << "z : " << z << std::endl;
    }
};
/* ---------------------------------------- */

/* --- Protected Multilevel Inheritance --- */
class AProtected {
    protected:
    int x;
};

class BProtected : protected AProtected {
    protected:
    int y;
};

class CProtected : protected BProtected {
    protected:
    int z;

    public:
    CProtected(int a, int b, int c) {
        x = a;
        y = b;
        z = c;
    }

    void display(void) {
        std::cout << "x : " << x << std::endl;
        std::cout << "y : " << y << std::endl;
        std::cout << "z : " << z << std::endl;
    }
};
/* ---------------------------------------- */

/* ---- Public Multilevel Inheritance ----- */
class APublic {
    protected:
    int x;
};

class BPublic : public APublic {
    protected:
    int y;
};

class CPublic : public BPublic {
    protected:
    int z;

    public:
    CPublic(int a, int b, int c) {
        x = a;
        y = b;
        z = c;
    }

    void display(void) {
        std::cout << "x : " << x << std::endl;
        std::cout << "y : " << y << std::endl;
        std::cout << "z : " << z << std::endl;
    }
};
/* ---------------------------------------- */

int main(void) {
    std::cout << "Private Multilevel Inheritance:\n";
    CPrivate cprv(1, 2, 3);
    cprv.display();

    std::cout << "\nProtected Multilevel Inheritance:\n";
    CProtected cpro(1, 2, 3);
    cpro.display();

    std::cout << "\nPublic Multilevel Inheritance:\n";
    CPublic cpub(1, 2, 3);
    cpub.display();

    return 0;
}
