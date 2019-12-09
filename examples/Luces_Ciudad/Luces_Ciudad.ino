#include <LibLucesCiudad.h>

void setup() {
  //Función de inicialización del sistema.
  inicializar_sistema();
}

void loop() 
{
  luz1.encender();
  luz2.encender();
  luz3.encender();
  luz4.encender();
  luz5.encender();
  
  luz6.apagar();
  luz7.apagar();
  luz8.apagar();
  luz9.apagar();
  luz10.apagar();

  delay(1000);

  luz1.apagar();
  luz2.apagar();
  luz3.apagar();
  luz4.apagar();
  luz5.apagar();
  
  luz6.encender();
  luz7.encender();
  luz8.encender();
  luz9.encender();
  luz10.encender();
  
  delay(1000);

}

