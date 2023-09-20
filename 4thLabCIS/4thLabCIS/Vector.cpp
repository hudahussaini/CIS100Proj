// Huda Hussaini
// 02/12/2022
// CISL 4th lab: 


#include "Vector.h"
using namespace std; 


int main()
{

        Vector a, b(3), c(3);

        a.print();
        c.set(3, 1);
        b.set(4, -1);
        b.set(2, 0);
        b.print();
        c.set(2, 2);      
        c.print(); 	

        Vector k(b);
        k.print(); 	 

        k.set(2, 1);
        k.set(1, 0);
        k.print();	
        b.print(); 	



        return 0;


}
