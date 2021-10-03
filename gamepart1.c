#include<stdio.h>

int main(){


    int si; 

    printf("Estas listo para empezar a jugar? \n si quieres jugar Triqui marca 1, Si quieres jugar... marca 0 \n");
    scanf("%d", &si);

    if(si == 1 ){

       printf("Bienvenido a jugar Triqui \n");

        void loop (char [3][3]); 
        void Intro_Primera (char c[3][3]); 
        void tablero (char c[3][3]); 
        void Intro_yo  (char c[3][3]); 

                                              
            char c [3][3]; 
            loop (c); 

            system ("pause"); 
                        

            void loop (char [3][3]);{
            char c [3][3];
            loop (c);                 

                Intro_Primera (c); 
                tablero (c);         
                }         

                void Intro_Primera (char c[3][3]); 
                char c [3][3];
                loop (c); 

                    int i, j; 
                    char aux; 
                    aux = '1'; 

                    for (i=0; i<3; i++){
                    
                         for (j=0; j<3; j++){
                            c[i][j] = aux++; 


                    }
                    
                }       
            
                void tablero (char c[3][3]){                       
                                          
                int i, j ;  

                for (i=0; i<3; i++){    
                    
                    for(j=0, j<3; j++){
                        
                    if (j<2){
                        printf (" %c |", c[i][j]); 
                        }    
                    else {
                        printf (" %c ", c[i][j]);    
                        }   

                    }   
                }
                }


                if (i<2); {
                    printf("\n-----------\n");
                    }
                      
                }
                
                 

                void Intro_yo (char [3][3]){
                char aux;                 
                    do{
                        do{
                            printf ("Escoge una casilla:"); 
                            fflush (stdin); 
                            scanf ("%c", &aux); 

                        } while (aux<1 || aux>9);    
                     }



                }  

            
    


    else {

        printf("Bienvenido a jugar .... \n");
        
    }    


   return 0;
}
