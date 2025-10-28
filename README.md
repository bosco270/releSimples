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
