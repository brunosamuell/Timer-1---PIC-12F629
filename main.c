//===========================================================================//
//             Timer 1 - PIC 12F629                                          //
// Autor: Eng.Bruno Samuel Luiz de Oliveira                                  //
// Compilador: PCWHD v5.080   INÍCIO: 10/01/2017    TÉRMINO: 10/01/2017      //
// Descrição: Demostração da estrutura minima para utilização do timer 1 no  //
// pic 12f629 com clock interno.                                             //
//===========================================================================//
//          DEFINIÇÕES GERAIS  DO  PROGRAMA                                  //
//===========================================================================//
#include <12F629.h>                                  // Define uC            //
#fuses INTRC_IO,WDT,NOPROTECT, NOMCLR ,BROWNOUT, PUT // Define Fusíveis      //
#use delay(internal=4000000)                         // Clock para 4 mhz     //
#use fast_io(A)                                      // Sentido das portas   //
                                                     // de acesso rapido     //
//===========================================================================//
//                       TIMER 1                                             //
//===========================================================================//
#int_timer1                                                                  //
void trata_t1()                                                              //
   {                                                                         //                            
   set_timer1(57344-get_timer1());                                           //                                        
                                                                             //                                                                                                                      //
}                                                                            //
//===========================================================================//
//                    ROTINA PRINCIPAL                                       //
//===========================================================================//
void main(){                                                                 //                                                  
   setup_timer_1(T1_INTERNAL|T1_DIV_BY_1);      // config. clock timer       //
   set_timer1(57344);                           // 57344 s overflow          //                                            
   enable_interrupts(int_timer1);               // Habilita timer 1          // 
   setup_comparator(nc_nc_nc_nc);               // Desliga comparadores      //
   enable_interrupts(GLOBAL);                  //  Liga interrupção geral    //
//===========================================================================//
//   LOOP  PRINCIPAL DE REPETIÇÃO                                            //
//===========================================================================//
   while (TRUE)                                                              //
   {                                                                         //
   }                                                                         //
}                                                                            //
//===========================================================================//
//  Fim do algoritmo                                                         //
//===========================================================================//
