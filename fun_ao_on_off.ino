/* Função para acender o led quando o botão for pressionado e apagá-lo quando o botão for pressionado novamente */

void on_off(int *est,int *estAnt,int *saidas,int leds,int botoes, int *turno){
  
  /* foram utilizados ponteiros para chamar pelo endereço das variáveis e não o valor delas */
  // est -> lê o estado do botão, no caso est=0 significa botão apertado, pois o botão é PULL-UP
  // estAnt -> armazena o estado anterior do botão
  // saidas -> indica se o led acenderá ou apagará
  // leds -> pino do led associado ao botão
  // botoes -> pino do botão
  // turno -> contagem de turno
  
  *est=digitalRead(botoes); //lê o botão

  if ( *est==0 && *estAnt==0)   // só mudará o estado do led na transição do botão de não apertado para apertado 

  { *turno=1-*turno; //troca o turno
    *saidas=1-*saidas; //inverte o estado do led
    delay(20);  //de-bouncing
  }

  *estAnt=1-*est; //armazena o estado anterior do botão

  if( *saidas==1)

  {
    digitalWrite(leds, HIGH); // led on

  }

  else{
    digitalWrite(leds,LOW); // led off


  }}
