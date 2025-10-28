# 🟢 Classe Rele para Arduino

Uma classe C++ simples para controle de relés com suporte a **temporização automática**, ideal para projetos com Arduino.

---

## 🚀 Funcionalidades

- Controle direto de relé (`On()` / `Off()`)
- Temporizador interno (`Timer(minutos)`) com desligamento automático
- Função `Update()` para gerenciamento não bloqueante (sem `delay()`)
- Proteção contra múltiplas ativações simultâneas
- Limite de segurança de **180 minutos** por temporização

---

🧰 Exemplo:
'''cpp

    #include "Rele.hpp"
    
    Rele rele(8); // Relé conectado ao pino 8
    
    void setup() {
        Serial.begin(9600);
        Serial.println("Iniciando teste do relé...");
        
        // Liga o relé por 2 minutos
        rele.Timer(2);
    }
    
    void loop() {
        // Atualiza o estado do relé
        rele.Update();
    
        // Apenas para feedback visual via Serial
        static unsigned long lastPrint = 0;
        if (millis() - lastPrint > 1000) {
            lastPrint = millis();
            Serial.println("Rele ativo...");
        }
    }


## 🧩 Estrutura da Classe

```cpp
class Rele {
private:
    uint8_t _pin_rele;
    bool _estado_rele;
    bool _temporizador;
    unsigned long _tempo_inicio;
    unsigned long _tempo_duracao;

public:
    Rele(uint8_t pin);
    void On();
    void Off();
    void Timer(uint8_t tempo_m);
    void Update();
};
