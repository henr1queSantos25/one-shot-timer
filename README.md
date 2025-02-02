# 🔘 Atividade 2: Temporizador de Um Disparo (One Shot)  

Este repositório contém um exemplo de código para a implementação de **um sistema de temporização acionado por um botão**, utilizando **temporizadores de um disparo (`add_alarm_in_ms()`)** no **Raspberry Pi Pico W**.  

## 🎯 Objetivo  

- Demonstrar o uso de **temporizadores de um disparo (One Shot)** para controle de LEDs.  
- Implementar um **sistema de acionamento progressivo de LEDs** com temporização.  
- Impedir múltiplos acionamentos simultâneos utilizando uma **variável de controle (`emProgresso`)**.  
- Simular o funcionamento no **Wokwi**.  

## 📹 Vídeo do Projeto  

- **[Ver Vídeo](#)** _(adicione o link do vídeo aqui)_  

## 🛠️ Tecnologias Utilizadas  

- **Linguagem de Programação**: C.  
- **Placa Microcontroladora**: Raspberry Pi Pico W.  
- **Bibliotecas**:  
  - **Pico SDK** para manipulação de GPIO e temporizadores.  
- **Ferramentas**:  
  - **Wokwi** (Simulação).  
  - **VS Code** (Ambiente de Desenvolvimento).  

## 🗂️ Estrutura do Repositório  

- `main.c`: Código-fonte principal contendo a implementação do sistema de temporização.  
- `README.md`: Documentação detalhada do projeto.  
- `diagram.json`: Configuração do circuito para simulação no **Wokwi**.  

## 🚀 Como Funciona  

O sistema é ativado **ao pressionar o botão**, e os LEDs **ligam e desligam progressivamente** a cada **3 segundos**:  

1. **Pressionar o botão (GP5) inicia a sequência de LEDs**.  
2. **Todos os LEDs acendem** (GP11, GP12, GP13).  
3. **Após 3 segundos, apenas dois LEDs permanecem ligados**.  
4. **Após mais 3 segundos, apenas um LED permanece ligado**.  
5. **Após mais 3 segundos, todos os LEDs são desligados**.  
6. **O botão pode ser pressionado novamente para reiniciar o ciclo**.  

✅ **O botão só pode ser pressionado novamente após a sequência ser concluída**.  
✅ **Os temporizadores são configurados com `add_alarm_in_ms()` para cada etapa**.  

## 🔌 Configuração do Hardware  

| Componente  | Pino do Pico W |  
|------------|---------------|  
| LED Verde  | GP11          |  
| LED Azul   | GP12          |  
| LED Vermelho | GP13         |  
| Botão (Pushbutton) | GP5   |  

## 💡 Desenvolvido por
Henrique Oliveira
📎 LinkedIn: **(https://www.linkedin.com/in/dev-henriqueo-santos/)**