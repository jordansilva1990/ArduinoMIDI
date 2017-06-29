#include <MIDI.h>
#include <midi_Defs.h>
#include <midi_Message.h>
#include <midi_Namespace.h>
#include <midi_Settings.h>



const int numBotones=4;
int valorLeido[numBotones];    // Array con los valores leidos de cada boton
int valorAnterior[numBotones]; // Array con el valor anterior leido
MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {
  //Serial.begin(31250);   // set MIDI baud rate
  MIDI.begin();                // Inicializamos la comunicacion midi (realmente es serial)
  for(int i=0; i<numBotones; i++){
    pinMode(i+2, INPUT_PULLUP);// Recorremos cada pin y lo ponemos como entrada
    valorAnterior[i]=1;        // Inicializamos el valor anterior a 1 (no pulsado)
  }
}

void loop(){
  for(int i=0; i<numBotones; i++){
    valorLeido[i]=digitalRead(i+2); // Leer valor
    // Solo enviamos cuando ha existido un cambio, para no sobrecargar el puerto serial
    if((valorLeido[i]==0) && (valorLeido[i]!=valorAnterior[i])){
      MIDI.sendNoteOn(48+i, 127, 1); //48 corresponde a C es decir DO.
    }
    else if ((valorLeido[i]==1) && (valorLeido[i]!=valorAnterior[i])){
      MIDI.sendNoteOff(48+i, 0, 1);
    }
    valorAnterior[i]=valorLeido[i]; // El valor anterior es el nuevo valor para la siguiente iteracion
  }

}






