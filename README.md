PT-BR
=

Esse código busca ler os pulsos emitidos por um encoder óptico do motor a cada tempo, que pode ser modificado no código.

Além disso, você poderá emitir um sinal PWM para controlar a velocidade do motor e acompanhar a mudança dos pulsos contados.

Aplicações:

Verificar se a quantidade de pulsos estimada confere com os valores reais.

Lembrando que cada encoder/motor possui medidas diferentes, justamente por conta disso, não foi aplicado o cálculo da velocidade.

Testado no Arduino UNO.

OBS: Caso não seja desejado a mudança da frequência de operação, e a mesma está gerando problemas de compilação, essa seção deverá ser removida.

EN
=

This code read the pulses emitted by an optical encoder of the engine every time, which can be modified in the code. 

In addition, you will be able to emit a PWM signal to control the speed of the engine and track the change of the counted pulses. 

Applications: 

Check if the estimated number of pulses matches the real values. 

Remembering that each encoder/engine has different measures, precisely because of this, the speed calculation was not applied.

Tested on Arduino UNO.

PS: If changing the operating frequency is generating compilation errors and you do not wish to use, you might remove the section. 
